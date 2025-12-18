#pragma once
#include "enums.h"

#include "uia_all.h"

namespace Uiaw {
//-------------------------------------------------------------------------------------------------
// UIAutomationCore.h enums
//-------------------------------------------------------------------------------------------------

//
// Enum conversion declarations (scoped <-> unscoped).
// The unscoped types live in Windows headers
//
::AnnoScope ToUia(Uiaw::AnnoScope);
Uiaw::AnnoScope ToUiaw(::AnnoScope);

::NavigateDirection ToUia(Uiaw::NavigateDirection);
Uiaw::NavigateDirection ToUiaw(::NavigateDirection);

::ProviderOptions ToUia(Uiaw::ProviderOptions);
Uiaw::ProviderOptions ToUiaw(::ProviderOptions);

::StructureChangeType ToUia(Uiaw::StructureChangeType);
Uiaw::StructureChangeType ToUiaw(::StructureChangeType);

::TextEditChangeType ToUia(Uiaw::TextEditChangeType);
Uiaw::TextEditChangeType ToUiaw(::TextEditChangeType);

::OrientationType ToUia(Uiaw::OrientationType);
Uiaw::OrientationType ToUiaw(::OrientationType);

::DockPosition ToUia(Uiaw::DockPosition);
Uiaw::DockPosition ToUiaw(::DockPosition);

::ExpandCollapseState ToUia(Uiaw::ExpandCollapseState);
Uiaw::ExpandCollapseState ToUiaw(::ExpandCollapseState);

::ScrollAmount ToUia(Uiaw::ScrollAmount);
Uiaw::ScrollAmount ToUiaw(::ScrollAmount);

::RowOrColumnMajor ToUia(Uiaw::RowOrColumnMajor);
Uiaw::RowOrColumnMajor ToUiaw(::RowOrColumnMajor);

::ToggleState ToUia(Uiaw::ToggleState);
Uiaw::ToggleState ToUiaw(::ToggleState);

::WindowVisualState ToUia(Uiaw::WindowVisualState);
Uiaw::WindowVisualState ToUiaw(::WindowVisualState);

::SynchronizedInputType ToUia(Uiaw::SynchronizedInputType);
Uiaw::SynchronizedInputType ToUiaw(::SynchronizedInputType);

::WindowInteractionState ToUia(Uiaw::WindowInteractionState);
Uiaw::WindowInteractionState ToUiaw(::WindowInteractionState);

::SayAsInterpretAs ToUia(Uiaw::SayAsInterpretAs);
Uiaw::SayAsInterpretAs ToUiaw(::SayAsInterpretAs);

::TextUnit ToUia(Uiaw::TextUnit);
Uiaw::TextUnit ToUiaw(::TextUnit);

::TextPatternRangeEndpoint ToUia(Uiaw::TextPatternRangeEndpoint);
Uiaw::TextPatternRangeEndpoint ToUiaw(::TextPatternRangeEndpoint);

::SupportedTextSelection ToUia(Uiaw::SupportedTextSelection);
Uiaw::SupportedTextSelection ToUiaw(::SupportedTextSelection);

::LiveSetting ToUia(Uiaw::LiveSetting);
Uiaw::LiveSetting ToUiaw(::LiveSetting);

::ActiveEnd ToUia(Uiaw::ActiveEnd);
Uiaw::ActiveEnd ToUiaw(::ActiveEnd);

::CaretPosition ToUia(Uiaw::CaretPosition);
Uiaw::CaretPosition ToUiaw(::CaretPosition);

::CaretBidiMode ToUia(Uiaw::CaretBidiMode);
Uiaw::CaretBidiMode ToUiaw(::CaretBidiMode);

::ZoomUnit ToUia(Uiaw::ZoomUnit);
Uiaw::ZoomUnit ToUiaw(::ZoomUnit);

::AnimationStyle ToUia(Uiaw::AnimationStyle);
Uiaw::AnimationStyle ToUiaw(::AnimationStyle);

::BulletStyle ToUia(Uiaw::BulletStyle);
Uiaw::BulletStyle ToUiaw(::BulletStyle);

::CapStyle ToUia(Uiaw::CapStyle);
Uiaw::CapStyle ToUiaw(::CapStyle);

::FillType ToUia(Uiaw::FillType);
Uiaw::FillType ToUiaw(::FillType);

::FlowDirections ToUia(Uiaw::FlowDirections);
Uiaw::FlowDirections ToUiaw(::FlowDirections);

::HorizontalTextAlignment ToUia(Uiaw::HorizontalTextAlignment);
Uiaw::HorizontalTextAlignment ToUiaw(::HorizontalTextAlignment);

::OutlineStyles ToUia(Uiaw::OutlineStyles);
Uiaw::OutlineStyles ToUiaw(::OutlineStyles);

::TextDecorationLineStyle ToUia(Uiaw::TextDecorationLineStyle);
Uiaw::TextDecorationLineStyle ToUiaw(::TextDecorationLineStyle);

::VisualEffects ToUia(Uiaw::VisualEffects);
Uiaw::VisualEffects ToUiaw(::VisualEffects);

::NotificationProcessing ToUia(Uiaw::NotificationProcessing);
Uiaw::NotificationProcessing ToUiaw(::NotificationProcessing);

::NotificationKind ToUia(Uiaw::NotificationKind);
Uiaw::NotificationKind ToUiaw(::NotificationKind);

::UIAutomationType ToUia(Uiaw::UIAutomationType);
Uiaw::UIAutomationType ToUiaw(::UIAutomationType);


//-------------------------------------------------------------------------------------------------
// UIAutomationClient.h enums
//-------------------------------------------------------------------------------------------------
::TreeScope ToUia(Uiaw::TreeScope);
Uiaw::TreeScope ToUiaw(::TreeScope);

::PropertyConditionFlags ToUia(Uiaw::PropertyConditionFlags);
Uiaw::PropertyConditionFlags ToUiaw(::PropertyConditionFlags);

::AutomationElementMode ToUia(Uiaw::AutomationElementMode);
Uiaw::AutomationElementMode ToUiaw(::AutomationElementMode);

::TreeTraversalOptions ToUia(Uiaw::TreeTraversalOptions);
Uiaw::TreeTraversalOptions ToUiaw(::TreeTraversalOptions);

::ConnectionRecoveryBehaviorOptions ToUia(Uiaw::ConnectionRecoveryBehaviorOptions);
Uiaw::ConnectionRecoveryBehaviorOptions ToUiaw(::ConnectionRecoveryBehaviorOptions);

::CoalesceEventsOptions ToUia(Uiaw::CoalesceEventsOptions);
Uiaw::CoalesceEventsOptions ToUiaw(::CoalesceEventsOptions);


//-------------------------------------------------------------------------------------------------
// UIAutomationCoreApi.h enums
//-------------------------------------------------------------------------------------------------
::ConditionType ToUia(Uiaw::ConditionType);
Uiaw::ConditionType ToUiaw(::ConditionType);

::NormalizeState ToUia(Uiaw::NormalizeState);
Uiaw::NormalizeState ToUiaw(::NormalizeState);

::ProviderType ToUia(Uiaw::ProviderType);
Uiaw::ProviderType ToUiaw(::ProviderType);

::AutomationIdentifierType ToUia(Uiaw::AutomationIdentifierType);
Uiaw::AutomationIdentifierType ToUiaw(::AutomationIdentifierType);

::EventArgsType ToUia(Uiaw::EventArgsType);
Uiaw::EventArgsType ToUiaw(::EventArgsType);

::AsyncContentLoadedState ToUia(Uiaw::AsyncContentLoadedState);
Uiaw::AsyncContentLoadedState ToUiaw(::AsyncContentLoadedState);

} // namespace Uiaw


