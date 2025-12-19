#pragma once




namespace Uiaw {

class UIAutomationCondition {
	void* p_;
	explicit UIAutomationCondition(void*);
public:
	UIAutomationCondition(const UIAutomationCondition&);
	UIAutomationCondition& operator=(const UIAutomationCondition&);
	UIAutomationCondition(UIAutomationCondition&&);
	UIAutomationCondition& operator=(UIAutomationCondition&&);
	~UIAutomationCondition();

};





} // namespace Uiaw
