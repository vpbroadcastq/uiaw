#include "UIAutomationElement.h"
#include "uia_all.h"
#include "enums_private.h"

namespace Uiaw {

UIAutomationElement::UIAutomationElement(void* p) {
	p_ = p;
}

UIAutomationElement::UIAutomationElement(const UIAutomationElement& rhs) {
	p_ = rhs.p_;
	reinterpret_cast<IUIAutomationElement*>(p_)->AddRef();
}

UIAutomationElement& UIAutomationElement::operator=(const UIAutomationElement& rhs) {
	p_ = rhs.p_;
	reinterpret_cast<IUIAutomationElement*>(p_)->AddRef();
	return *this;
}
UIAutomationElement::UIAutomationElement(UIAutomationElement&& rhs) {
	p_ = rhs.p_;
	rhs.p_ = nullptr;
}

UIAutomationElement& UIAutomationElement::operator=(UIAutomationElement&& rhs) {
	p_ = rhs.p_;
	rhs.p_ = nullptr;
	return *this;
}

UIAutomationElement::~UIAutomationElement() {
	if (p_) {
		reinterpret_cast<IUIAutomationElement*>(p_)->Release();
	}
}

Uiaw::Result<Uiaw::UIAutomationElement> UIAutomationElement::FindFirst(Uiaw::TreeScope scope,
	Uiaw::UIAutomationCondition* condition) {
	::IUIAutomationElement* found {nullptr};
	HRESULT hr = reinterpret_cast<IUIAutomationElement*>(p_)->FindFirst(
		Uiaw::ToUia(scope),
		reinterpret_cast<IUIAutomationCondition*>(condition->p_),
		&found);

	if (FAILED(hr)) {
		return Uiaw::Result<Uiaw::UIAutomationElement>{.error = Uiaw::ErrorCode{ static_cast<int32_t>(hr) } };
	}
	return Uiaw::Result<Uiaw::UIAutomationElement>{.value = Uiaw::UIAutomationElement{ found } };
}











} // namespace Uiaw

