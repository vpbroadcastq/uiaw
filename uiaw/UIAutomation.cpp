#include "UIAutomation.h"
#include "uia_all.h"


namespace Uiaw {

Uiaw::Result<Uiaw::UIAutomation> UIAutomation::Create() {
	::IUIAutomation* p {nullptr};
	HRESULT hr = CoCreateInstance(CLSID_CUIAutomation, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&p));
	if (FAILED(hr)) {
		return Uiaw::Result<Uiaw::UIAutomation>{.error = Uiaw::ErrorCode{ static_cast<int32_t>(hr) }};
	}
	return Uiaw::Result<Uiaw::UIAutomation>{.value = Uiaw::UIAutomation{ p }};
}

UIAutomation::UIAutomation(void* p) {
	p_ = p;
}

UIAutomation::UIAutomation() {
	::IUIAutomation* p {nullptr};
	HRESULT hr = CoCreateInstance(CLSID_CUIAutomation, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&p));
	if (FAILED(hr)) {
		std::terminate();
	}
	p_ = p;
}
UIAutomation::UIAutomation(const UIAutomation& rhs) {
	p_ = rhs.p_;
	reinterpret_cast<IUIAutomation*>(p_)->AddRef();
}
UIAutomation& UIAutomation::operator=(const UIAutomation& rhs) {
	p_ = rhs.p_;
	reinterpret_cast<IUIAutomation*>(p_)->AddRef();
	return *this;
}
UIAutomation::UIAutomation(UIAutomation&& rhs) {
	p_ = rhs.p_;
	rhs.p_ = nullptr;
}
UIAutomation& UIAutomation::operator=(UIAutomation&& rhs) {
	p_ = rhs.p_;
	rhs.p_ = nullptr;
	return *this;
}
UIAutomation::~UIAutomation() {
	if (p_) {
		reinterpret_cast<IUIAutomation*>(p_)->Release();
	}
}

Uiaw::Result<Uiaw::UIAutomationElement> UIAutomation::GetRootElement() {
	::IUIAutomationElement* elem {nullptr};
	HRESULT hr = reinterpret_cast<IUIAutomation*>(p_)->GetRootElement(&elem);
	if (FAILED(hr)) {
		return Uiaw::Result<Uiaw::UIAutomation>{.error = Uiaw::ErrorCode{ static_cast<int32_t>(hr) }};
	}
	return Uiaw::Result<Uiaw::UIAutomation>{.value = Uiaw::UIAutomationElement{ elem }};
}









} // namespace Uiaw
