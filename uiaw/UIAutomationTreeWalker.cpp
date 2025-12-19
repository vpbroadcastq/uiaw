#include "UIAutomationTreeWalker.h"
#include "uia_all.h"



namespace Uiaw {

UIAutomationTreeWalker::UIAutomationTreeWalker(void* p) {
	p_ = p;
}

UIAutomationTreeWalker::UIAutomationTreeWalker(const UIAutomationTreeWalker& rhs) {
	p_ = rhs.p_;
	reinterpret_cast<::IUIAutomationTreeWalker*>(p_)->AddRef();
}

UIAutomationTreeWalker& UIAutomationTreeWalker::operator=(const UIAutomationTreeWalker& rhs) {
	p_ = rhs.p_;
	reinterpret_cast<::IUIAutomationTreeWalker*>(p_)->AddRef();
	return *this;
}

UIAutomationTreeWalker::UIAutomationTreeWalker(UIAutomationTreeWalker&& rhs) {
	p_ = rhs.p_;
	rhs.p_ = nullptr;
}

UIAutomationTreeWalker& UIAutomationTreeWalker::operator=(UIAutomationTreeWalker&& rhs) {
	p_ = rhs.p_;
	rhs.p_ = nullptr;
	return *this;
}

UIAutomationTreeWalker::~UIAutomationTreeWalker() {
	if (p_) {
		reinterpret_cast<::IUIAutomationTreeWalker*>(p_)->Release();
	}
}

Uiaw::Result<Uiaw::UIAutomationElement> UIAutomationTreeWalker::GetFirstChildElement(Uiaw::UIAutomationElement* element) {
	::IUIAutomationElement* child {nullptr};
	HRESULT hr = reinterpret_cast<IUIAutomationTreeWalker*>(p_)->GetFirstChildElement(
		reinterpret_cast<::IUIAutomationElement*>(element->p_),
		&child);
	if (FAILED(hr)) {
		return Uiaw::Result<Uiaw::UIAutomationElement>{ .error = Uiaw::ErrorCode{ static_cast<int32_t>(hr) } };
	}
	return Uiaw::Result<Uiaw::UIAutomationElement>{ .value = Uiaw::UIAutomationElement{ child } };
}

Uiaw::Result<Uiaw::UIAutomationElement> UIAutomationTreeWalker::GetNextSiblingElement(Uiaw::UIAutomationElement* element) {
	::IUIAutomationElement* sibling { nullptr };
	HRESULT hr = reinterpret_cast<IUIAutomationTreeWalker*>(p_)->GetNextSiblingElement(
		reinterpret_cast<::IUIAutomationElement*>(element->p_),
		&sibling);
	if (FAILED(hr)) {
		return Uiaw::Result<Uiaw::UIAutomationElement>{ .error = Uiaw::ErrorCode{ static_cast<int32_t>(hr) } };
	}
	return Uiaw::Result<Uiaw::UIAutomationElement>{ .value = Uiaw::UIAutomationElement{ sibling } };
}



} // namespace Uiaw
