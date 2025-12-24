#include "UIAutomationCondition.h"
#include "uia_all.h"



namespace Uiaw {

UIAutomationCondition::UIAutomationCondition(void* p) {
	p_ = p;
}

UIAutomationCondition::UIAutomationCondition(const UIAutomationCondition& rhs) {
	p_ = rhs.p_;
	reinterpret_cast<::IUIAutomationCondition*>(p_)->AddRef();
}

UIAutomationCondition& UIAutomationCondition::operator=(const UIAutomationCondition& rhs) {
	p_ = rhs.p_;
	reinterpret_cast<::IUIAutomationCondition*>(p_)->AddRef();
	return *this;
}

UIAutomationCondition::UIAutomationCondition(UIAutomationCondition&& rhs) {
	p_ = rhs.p_;
	rhs.p_ = nullptr;
}

UIAutomationCondition& UIAutomationCondition::operator=(UIAutomationCondition&& rhs) {
	p_ = rhs.p_;
	rhs.p_ = nullptr;
	return *this;
}

UIAutomationCondition::~UIAutomationCondition() {
	if (p_) {
		reinterpret_cast<::IUIAutomationCondition*>(p_)->Release();
	}
}

void* UIAutomationCondition::GetInternalPointer() {
	return p_;
}


} // namespace Uiaw


