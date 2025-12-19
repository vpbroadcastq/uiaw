// Write a program in C++ that uses UIAutomation to find a window given its ClassName, then prints
// out some basic information (class name, automation id, bounding rectangle coordinates, whatever)
// for each of its immediate children.
// 
// uiwalk_children.cpp
//
// Build (MSVC):
//   cl /std:c++20 /EHsc uiwalk_children.cpp ole32.lib uiautomationcore.lib
//
// Usage:
//   uiwalk_children.exe "Notepad"           // window class name to find
//   uiwalk_children.exe "CabinetWClass"     // Explorer
//
// Notes:
// - This finds the first top-level window with the given ClassName by scanning the desktop's
//   immediate children (top-level windows).
// - It then enumerates *immediate* children of that window (TreeScope_Children) and prints
//   basic properties for each child.
//

#include <windows.h>
#include <uiaw/uiaw.h>
#include <uiaw/uia_all.h>
#include <comdef.h>     // _com_error
#include <iostream>
#include <string>
#include <vector>

static std::string WideToUtf8(const wchar_t* w) {
    if (!w) return {};
    int len = WideCharToMultiByte(CP_UTF8, 0, w, -1, nullptr, 0, nullptr, nullptr);
    if (len <= 1) return {};
    std::string out(static_cast<size_t>(len - 1), '\0');
    WideCharToMultiByte(CP_UTF8, 0, w, -1, out.data(), len, nullptr, nullptr);
    return out;
}

static std::string BstrToUtf8(BSTR b) {
    if (!b) return {};
    return WideToUtf8(b);
}

static std::string RectToString(const RECT& r) {
    return "L=" + std::to_string(r.left) +
        " T=" + std::to_string(r.top) +
        " R=" + std::to_string(r.right) +
        " B=" + std::to_string(r.bottom) +
        " (W=" + std::to_string(r.right - r.left) +
        " H=" + std::to_string(r.bottom - r.top) + ")";
}

static void PrintElementInfo(IUIAutomationElement* e, int index) {
    if (!e) { return; }

    BSTR bClass = nullptr;
    BSTR bName = nullptr;
    BSTR bAutoId = nullptr;

    HRESULT hr = S_OK;

    hr = e->get_CurrentClassName(&bClass);
    if (FAILED(hr)) { bClass = nullptr; }

    hr = e->get_CurrentName(&bName);
    if (FAILED(hr)) { bName = nullptr; }

    hr = e->get_CurrentAutomationId(&bAutoId);
    if (FAILED(hr)) { bAutoId = nullptr; }

    RECT br{};
    hr = e->get_CurrentBoundingRectangle(&br);

    int pid = 0;
    e->get_CurrentProcessId(&pid);

    CONTROLTYPEID ct = 0;
    e->get_CurrentControlType(&ct);

    // RuntimeId is an int array; useful when Name/AutomationId are empty.
    SAFEARRAY* saRuntimeId = nullptr;
    hr = e->GetRuntimeId(&saRuntimeId);
    std::string runtimeIdStr;
    if (SUCCEEDED(hr) && saRuntimeId && saRuntimeId->cDims == 1) {
        LONG lb = 0, ub = -1;
        SafeArrayGetLBound(saRuntimeId, 1, &lb);
        SafeArrayGetUBound(saRuntimeId, 1, &ub);
        runtimeIdStr = "[";
        for (LONG i = lb; i <= ub; ++i)
        {
            LONG v = 0;
            SafeArrayGetElement(saRuntimeId, &i, &v);
            runtimeIdStr += std::to_string(v);
            if (i != ub) runtimeIdStr += ", ";
        }
        runtimeIdStr += "]";
    }
    if (saRuntimeId) { SafeArrayDestroy(saRuntimeId); }

    std::cout << "Child #" << index << "\n";
    std::cout << "  Name         : " << BstrToUtf8(bName) << "\n";
    std::cout << "  ClassName    : " << BstrToUtf8(bClass) << "\n";
    std::cout << "  AutomationId : " << BstrToUtf8(bAutoId) << "\n";
    std::cout << "  ControlType  : " << ct << "\n";
    std::cout << "  ProcessId    : " << pid << "\n";
    if (SUCCEEDED(hr)) {
        std::cout << "  Bounds       : " << RectToString(br) << "\n";
    }
    else {
        std::cout << "  Bounds       : <unavailable>\n";
    }
    std::cout << "  RuntimeId    : " << runtimeIdStr << "\n";

    if (bClass) SysFreeString(bClass);
    if (bName) SysFreeString(bName);
    if (bAutoId) SysFreeString(bAutoId);
}

static void FailIf(HRESULT hr, const char* what) {
    if (FAILED(hr)) {
        _com_error err(hr);
        std::cerr << what << " failed: 0x" << std::hex << hr << std::dec
            << " (" << err.ErrorMessage() << ")\n";
        std::exit(1);
    }
}

int wmain(int argc, wchar_t** argv) {
    if (argc < 2) {
        std::wcerr << L"Usage: " << argv[0] << L" <WindowClassName>\n";
        return 2;
    }
    const wchar_t* targetClass = argv[1];

    HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    FailIf(hr, "CoInitializeEx");

    IUIAutomation* uia = nullptr;
    hr = CoCreateInstance(CLSID_CUIAutomation, nullptr, CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(&uia));
    FailIf(hr, "CoCreateInstance(CUIAutomation)");

    IUIAutomationElement* desktop = nullptr;
    hr = uia->GetRootElement(&desktop);
    FailIf(hr, "GetRootElement");

    // Find the first top-level window with ClassName == targetClass.
    IUIAutomationCondition* condClass = nullptr;
    VARIANT vClass{};
    VariantInit(&vClass);
    vClass.vt = VT_BSTR;
    vClass.bstrVal = SysAllocString(targetClass);

    hr = uia->CreatePropertyCondition(UIA_ClassNamePropertyId, vClass, &condClass);
    VariantClear(&vClass);
    FailIf(hr, "CreatePropertyCondition(ClassName)");

    IUIAutomationElement* targetWindow = nullptr;
    hr = desktop->FindFirst(TreeScope_Children, condClass, &targetWindow);
    condClass->Release();
    FailIf(hr, "FindFirst(TreeScope_Children, ClassName)");

    if (!targetWindow) {
        std::cerr << "No top-level window found with ClassName = "
            << WideToUtf8(targetClass) << "\n";
        desktop->Release();
        uia->Release();
        CoUninitialize();
        return 1;
    }

    std::cout << "Found window (top-level) with ClassName=" << WideToUtf8(targetClass) << "\n";
    PrintElementInfo(targetWindow, 0);

    // Enumerate immediate children of the window.
    IUIAutomationTreeWalker* walker = nullptr;
    hr = uia->get_ControlViewWalker(&walker);
    FailIf(hr, "get_ControlViewWalker");

    IUIAutomationElement* child = nullptr;
    hr = walker->GetFirstChildElement(targetWindow, &child);
    FailIf(hr, "GetFirstChildElement");

    int idx = 1;
    while (child) {
        PrintElementInfo(child, idx);

        IUIAutomationElement* next = nullptr;
        hr = walker->GetNextSiblingElement(child, &next);
        FailIf(hr, "GetNextSiblingElement");

        child->Release();
        child = next;
        ++idx;
    }

    walker->Release();
    targetWindow->Release();
    desktop->Release();
    uia->Release();
    CoUninitialize();
    return 0;
}

