#pragma once
#include "uiaw.h"
#include "UIAutomationElement.h"

namespace Uiaw {


class UIAutomationTreeWalker {
    void* p_;
explicit UIAutomationTreeWalker(void*);
        
public:
	UIAutomationTreeWalker(const UIAutomationTreeWalker&);
	UIAutomationTreeWalker& operator=(const UIAutomationTreeWalker&);
	UIAutomationTreeWalker(UIAutomationTreeWalker&&);
	UIAutomationTreeWalker& operator=(UIAutomationTreeWalker&&);
	~UIAutomationTreeWalker();

    Uiaw::Result<Uiaw::UIAutomationElement> GetFirstChildElement(Uiaw::UIAutomationElement*);
    Uiaw::Result<Uiaw::UIAutomationElement> GetNextSiblingElement(Uiaw::UIAutomationElement*);
};


} // namespace Uiaw
