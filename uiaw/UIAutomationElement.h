#pragma once
#include "utility.h"
#include "enums.h"




namespace Uiaw {
class UIAutomation;
class UIAutomationTreeWalker;
class UIAutomationCondition;

class UIAutomationElement {
	void* p_;
	explicit UIAutomationElement(void*);

	friend class Uiaw::UIAutomation;
	friend class Uiaw::UIAutomationTreeWalker;

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
