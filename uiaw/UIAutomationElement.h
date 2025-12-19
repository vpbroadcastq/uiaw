#pragma once
#include "utility.h"
#include "enums.h"
#include "UIAutomationCondition.h"



namespace Uiaw {
//class InternalAccessor;

class UIAutomationElement {
	void* p_;
	explicit UIAutomationElement(void*);
	friend class InternalAccessor;

public:
	UIAutomationElement(const UIAutomationElement&);
	UIAutomationElement& operator=(const UIAutomationElement&);
	UIAutomationElement(UIAutomationElement&&);
	UIAutomationElement& operator=(UIAutomationElement&&);
	~UIAutomationElement();

	Uiaw::Result<Uiaw::UIAutomationElement> FindFirst(Uiaw::TreeScope,
		Uiaw::UIAutomationCondition* condition);
};





} // namespace Uiaw
