#pragma once
//#include "uiaw.h"
#include "UIAutomationElement.h"
#include "UIAutomationCondition.h"
#include "UIAutomationTreeWalker.h"

namespace Uiaw {

// Owns an ::IUIAutomation
class UIAutomation {
	void* p_;

	explicit UIAutomation(void*);
public:
	static Uiaw::Result<Uiaw::UIAutomation> Create();

	// Calls std::terminate on failure
	UIAutomation();
	UIAutomation(const UIAutomation&);
	UIAutomation& operator=(const UIAutomation&);
	UIAutomation(UIAutomation&&);
	UIAutomation& operator=(UIAutomation&&);
	~UIAutomation();

    Uiaw::Result<Uiaw::UIAutomationElement> GetRootElement();
	Uiaw::Result<Uiaw::UIAutomationCondition> CreatePropertyCondition(Uiaw::PropertyId, Uiaw::Variant);
	Uiaw::Result<Uiaw::UIAutomationTreeWalker> GetControlViewWalker();
};





} // namespace uiaw

