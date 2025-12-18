#include "enums_private.h"
#include "uia_all.h"
#include <type_traits>

namespace Uiaw {

//-------------------------------------------------------------------------------------------------
// UIAutomationCore.h enums
//-------------------------------------------------------------------------------------------------
    
//
// enum AnnoScope
//
namespace {
    using UiaUnder = std::underlying_type_t<::AnnoScope>;
    using UiawUnder = std::underlying_type_t<Uiaw::AnnoScope>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);
    static_assert(static_cast<UiawUnder>(::ANNO_THIS) == static_cast<UiawUnder>(Uiaw::AnnoScope::This));
    static_assert(static_cast<UiawUnder>(::ANNO_CONTAINER) == static_cast<UiawUnder>(Uiaw::AnnoScope::Container));
}
::AnnoScope ToUia(Uiaw::AnnoScope v) {
    return static_cast<::AnnoScope>(v);
}
Uiaw::AnnoScope ToUiaw(::AnnoScope v) {
    return static_cast<Uiaw::AnnoScope>(v);
}

//
// enum NavigateDirection
//
namespace {
    using UiaUnder = std::underlying_type_t<::NavigateDirection>;
    using UiawUnder = std::underlying_type_t<Uiaw::NavigateDirection>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);
    static_assert(static_cast<UiawUnder>(::NavigateDirection_Parent) == static_cast<UiawUnder>(Uiaw::NavigateDirection::Parent));
    static_assert(static_cast<UiawUnder>(::NavigateDirection_NextSibling) == static_cast<UiawUnder>(Uiaw::NavigateDirection::NextSibling));
    static_assert(static_cast<UiawUnder>(::NavigateDirection_PreviousSibling) == static_cast<UiawUnder>(Uiaw::NavigateDirection::PreviousSibling));
    static_assert(static_cast<UiawUnder>(::NavigateDirection_FirstChild) == static_cast<UiawUnder>(Uiaw::NavigateDirection::FirstChild));
    static_assert(static_cast<UiawUnder>(::NavigateDirection_LastChild) == static_cast<UiawUnder>(Uiaw::NavigateDirection::LastChild));
}
::NavigateDirection ToUia(Uiaw::NavigateDirection v) {
    return static_cast<::NavigateDirection>(v);
}
Uiaw::NavigateDirection ToUiaw(::NavigateDirection v) {
    return static_cast<Uiaw::NavigateDirection>(v);
}

//
// enum ProviderOptions
//
namespace {
    using UiaUnder = std::underlying_type_t<::ProviderOptions>;
    using UiawUnder = std::underlying_type_t<Uiaw::ProviderOptions>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);
    static_assert(static_cast<UiawUnder>(::ProviderOptions_ClientSideProvider) == static_cast<UiawUnder>(Uiaw::ProviderOptions::ClientSideProvider));
    static_assert(static_cast<UiawUnder>(::ProviderOptions_ServerSideProvider) == static_cast<UiawUnder>(Uiaw::ProviderOptions::ServerSideProvider));
    static_assert(static_cast<UiawUnder>(::ProviderOptions_NonClientAreaProvider) == static_cast<UiawUnder>(Uiaw::ProviderOptions::NonClientAreaProvider));
    static_assert(static_cast<UiawUnder>(::ProviderOptions_OverrideProvider) == static_cast<UiawUnder>(Uiaw::ProviderOptions::OverrideProvider));
    static_assert(static_cast<UiawUnder>(::ProviderOptions_ProviderOwnsSetFocus) == static_cast<UiawUnder>(Uiaw::ProviderOptions::ProviderOwnsSetFocus));
    static_assert(static_cast<UiawUnder>(::ProviderOptions_UseComThreading) == static_cast<UiawUnder>(Uiaw::ProviderOptions::UseComThreading));
    static_assert(static_cast<UiawUnder>(::ProviderOptions_RefuseNonClientSupport) == static_cast<UiawUnder>(Uiaw::ProviderOptions::RefuseNonClientSupport));
    static_assert(static_cast<UiawUnder>(::ProviderOptions_HasNativeIAccessible) == static_cast<UiawUnder>(Uiaw::ProviderOptions::HasNativeIAccessible));
    static_assert(static_cast<UiawUnder>(::ProviderOptions_UseClientCoordinates) == static_cast<UiawUnder>(Uiaw::ProviderOptions::UseClientCoordinates));
}
::ProviderOptions ToUia(Uiaw::ProviderOptions v) {
    return static_cast<::ProviderOptions>(v);
}
Uiaw::ProviderOptions ToUiaw(::ProviderOptions v) {
    return static_cast<Uiaw::ProviderOptions>(v);
}

//
// enum StructureChangeType
//
namespace {
    using UiaUnder_StructureChangeType = std::underlying_type_t<::StructureChangeType>;
    using UiawUnder_StructureChangeType = std::underlying_type_t<Uiaw::StructureChangeType>;
    static_assert(std::is_same_v<UiaUnder_StructureChangeType, UiawUnder_StructureChangeType>);

    static_assert(static_cast<UiawUnder_StructureChangeType>(::StructureChangeType_ChildAdded) == static_cast<UiawUnder_StructureChangeType>(Uiaw::StructureChangeType::ChildAdded));
    static_assert(static_cast<UiawUnder_StructureChangeType>(::StructureChangeType_ChildRemoved) == static_cast<UiawUnder_StructureChangeType>(Uiaw::StructureChangeType::ChildRemoved));
    static_assert(static_cast<UiawUnder_StructureChangeType>(::StructureChangeType_ChildrenInvalidated) == static_cast<UiawUnder_StructureChangeType>(Uiaw::StructureChangeType::ChildrenInvalidated));
    static_assert(static_cast<UiawUnder_StructureChangeType>(::StructureChangeType_ChildrenBulkAdded) == static_cast<UiawUnder_StructureChangeType>(Uiaw::StructureChangeType::ChildrenBulkAdded));
    static_assert(static_cast<UiawUnder_StructureChangeType>(::StructureChangeType_ChildrenBulkRemoved) == static_cast<UiawUnder_StructureChangeType>(Uiaw::StructureChangeType::ChildrenBulkRemoved));
    static_assert(static_cast<UiawUnder_StructureChangeType>(::StructureChangeType_ChildrenReordered) == static_cast<UiawUnder_StructureChangeType>(Uiaw::StructureChangeType::ChildrenReordered));
}
::StructureChangeType ToUia(Uiaw::StructureChangeType v) {
    return static_cast<::StructureChangeType>(v);
}
Uiaw::StructureChangeType ToUiaw(::StructureChangeType v) {
    return static_cast<Uiaw::StructureChangeType>(v);
}

//
// enum TextEditChangeType
//
namespace {
    using UiaUnder_TextEditChangeType = std::underlying_type_t<::TextEditChangeType>;
    using UiawUnder_TextEditChangeType = std::underlying_type_t<Uiaw::TextEditChangeType>;
    static_assert(std::is_same_v<UiaUnder_TextEditChangeType, UiawUnder_TextEditChangeType>);

    static_assert(static_cast<UiawUnder_TextEditChangeType>(::TextEditChangeType_None) == static_cast<UiawUnder_TextEditChangeType>(Uiaw::TextEditChangeType::None));
    static_assert(static_cast<UiawUnder_TextEditChangeType>(::TextEditChangeType_AutoCorrect) == static_cast<UiawUnder_TextEditChangeType>(Uiaw::TextEditChangeType::AutoCorrect));
    static_assert(static_cast<UiawUnder_TextEditChangeType>(::TextEditChangeType_Composition) == static_cast<UiawUnder_TextEditChangeType>(Uiaw::TextEditChangeType::Composition));
    static_assert(static_cast<UiawUnder_TextEditChangeType>(::TextEditChangeType_CompositionFinalized) == static_cast<UiawUnder_TextEditChangeType>(Uiaw::TextEditChangeType::CompositionFinalized));
    static_assert(static_cast<UiawUnder_TextEditChangeType>(::TextEditChangeType_AutoComplete) == static_cast<UiawUnder_TextEditChangeType>(Uiaw::TextEditChangeType::AutoComplete));
}
::TextEditChangeType ToUia(Uiaw::TextEditChangeType v) {
    return static_cast<::TextEditChangeType>(v);
}
Uiaw::TextEditChangeType ToUiaw(::TextEditChangeType v) {
    return static_cast<Uiaw::TextEditChangeType>(v);
}

//
// enum OrientationType
//
namespace {
    using UiaUnder_OrientationType = std::underlying_type_t<::OrientationType>;
    using UiawUnder_OrientationType = std::underlying_type_t<Uiaw::OrientationType>;
    static_assert(std::is_same_v<UiaUnder_OrientationType, UiawUnder_OrientationType>);

    static_assert(static_cast<UiawUnder_OrientationType>(::OrientationType_None) == static_cast<UiawUnder_OrientationType>(Uiaw::OrientationType::None));
    static_assert(static_cast<UiawUnder_OrientationType>(::OrientationType_Horizontal) == static_cast<UiawUnder_OrientationType>(Uiaw::OrientationType::Horizontal));
    static_assert(static_cast<UiawUnder_OrientationType>(::OrientationType_Vertical) == static_cast<UiawUnder_OrientationType>(Uiaw::OrientationType::Vertical));
}
::OrientationType ToUia(Uiaw::OrientationType v) {
    return static_cast<::OrientationType>(v);
}
Uiaw::OrientationType ToUiaw(::OrientationType v) {
    return static_cast<Uiaw::OrientationType>(v);
}

//
// enum DockPosition
//
namespace {
    using UiaUnder_DockPosition = std::underlying_type_t<::DockPosition>;
    using UiawUnder_DockPosition = std::underlying_type_t<Uiaw::DockPosition>;
    static_assert(std::is_same_v<UiaUnder_DockPosition, UiawUnder_DockPosition>);

    static_assert(static_cast<UiawUnder_DockPosition>(::DockPosition_Top) == static_cast<UiawUnder_DockPosition>(Uiaw::DockPosition::Top));
    static_assert(static_cast<UiawUnder_DockPosition>(::DockPosition_Left) == static_cast<UiawUnder_DockPosition>(Uiaw::DockPosition::Left));
    static_assert(static_cast<UiawUnder_DockPosition>(::DockPosition_Bottom) == static_cast<UiawUnder_DockPosition>(Uiaw::DockPosition::Bottom));
    static_assert(static_cast<UiawUnder_DockPosition>(::DockPosition_Right) == static_cast<UiawUnder_DockPosition>(Uiaw::DockPosition::Right));
    static_assert(static_cast<UiawUnder_DockPosition>(::DockPosition_Fill) == static_cast<UiawUnder_DockPosition>(Uiaw::DockPosition::Fill));
    static_assert(static_cast<UiawUnder_DockPosition>(::DockPosition_None) == static_cast<UiawUnder_DockPosition>(Uiaw::DockPosition::None));
}
::DockPosition ToUia(Uiaw::DockPosition v) {
    return static_cast<::DockPosition>(v);
}
Uiaw::DockPosition ToUiaw(::DockPosition v) {
    return static_cast<Uiaw::DockPosition>(v);
}

//
// enum ExpandCollapseState
//
namespace {
    using UiaUnder_ExpandCollapseState = std::underlying_type_t<::ExpandCollapseState>;
    using UiawUnder_ExpandCollapseState = std::underlying_type_t<Uiaw::ExpandCollapseState>;
    static_assert(std::is_same_v<UiaUnder_ExpandCollapseState, UiawUnder_ExpandCollapseState>);

    static_assert(static_cast<UiawUnder_ExpandCollapseState>(::ExpandCollapseState_Collapsed) == static_cast<UiawUnder_ExpandCollapseState>(Uiaw::ExpandCollapseState::Collapsed));
    static_assert(static_cast<UiawUnder_ExpandCollapseState>(::ExpandCollapseState_Expanded) == static_cast<UiawUnder_ExpandCollapseState>(Uiaw::ExpandCollapseState::Expanded));
    static_assert(static_cast<UiawUnder_ExpandCollapseState>(::ExpandCollapseState_PartiallyExpanded) == static_cast<UiawUnder_ExpandCollapseState>(Uiaw::ExpandCollapseState::PartiallyExpanded));
    static_assert(static_cast<UiawUnder_ExpandCollapseState>(::ExpandCollapseState_LeafNode) == static_cast<UiawUnder_ExpandCollapseState>(Uiaw::ExpandCollapseState::LeafNode));
}
::ExpandCollapseState ToUia(Uiaw::ExpandCollapseState v) {
    return static_cast<::ExpandCollapseState>(v);
}
Uiaw::ExpandCollapseState ToUiaw(::ExpandCollapseState v) {
    return static_cast<Uiaw::ExpandCollapseState>(v);
}

//
// enum ScrollAmount
//
namespace {
    using UiaUnder_ScrollAmount = std::underlying_type_t<::ScrollAmount>;
    using UiawUnder_ScrollAmount = std::underlying_type_t<Uiaw::ScrollAmount>;
    static_assert(std::is_same_v<UiaUnder_ScrollAmount, UiawUnder_ScrollAmount>);

    static_assert(static_cast<UiawUnder_ScrollAmount>(::ScrollAmount_LargeDecrement) == static_cast<UiawUnder_ScrollAmount>(Uiaw::ScrollAmount::LargeDecrement));
    static_assert(static_cast<UiawUnder_ScrollAmount>(::ScrollAmount_SmallDecrement) == static_cast<UiawUnder_ScrollAmount>(Uiaw::ScrollAmount::SmallDecrement));
    static_assert(static_cast<UiawUnder_ScrollAmount>(::ScrollAmount_NoAmount) == static_cast<UiawUnder_ScrollAmount>(Uiaw::ScrollAmount::NoAmount));
    static_assert(static_cast<UiawUnder_ScrollAmount>(::ScrollAmount_LargeIncrement) == static_cast<UiawUnder_ScrollAmount>(Uiaw::ScrollAmount::LargeIncrement));
    static_assert(static_cast<UiawUnder_ScrollAmount>(::ScrollAmount_SmallIncrement) == static_cast<UiawUnder_ScrollAmount>(Uiaw::ScrollAmount::SmallIncrement));
}
::ScrollAmount ToUia(Uiaw::ScrollAmount v) {
    return static_cast<::ScrollAmount>(v);
}
Uiaw::ScrollAmount ToUiaw(::ScrollAmount v) {
    return static_cast<Uiaw::ScrollAmount>(v);
}

//
// enum RowOrColumnMajor
//
namespace {
    using UiaUnder_RowOrColumnMajor = std::underlying_type_t<::RowOrColumnMajor>;
    using UiawUnder_RowOrColumnMajor = std::underlying_type_t<Uiaw::RowOrColumnMajor>;
    static_assert(std::is_same_v<UiaUnder_RowOrColumnMajor, UiawUnder_RowOrColumnMajor>);

    static_assert(static_cast<UiawUnder_RowOrColumnMajor>(::RowOrColumnMajor_RowMajor) == static_cast<UiawUnder_RowOrColumnMajor>(Uiaw::RowOrColumnMajor::RowMajor));
    static_assert(static_cast<UiawUnder_RowOrColumnMajor>(::RowOrColumnMajor_ColumnMajor) == static_cast<UiawUnder_RowOrColumnMajor>(Uiaw::RowOrColumnMajor::ColumnMajor));
    static_assert(static_cast<UiawUnder_RowOrColumnMajor>(::RowOrColumnMajor_Indeterminate) == static_cast<UiawUnder_RowOrColumnMajor>(Uiaw::RowOrColumnMajor::Indeterminate));
}
::RowOrColumnMajor ToUia(Uiaw::RowOrColumnMajor v) {
    return static_cast<::RowOrColumnMajor>(v);
}
Uiaw::RowOrColumnMajor ToUiaw(::RowOrColumnMajor v) {
    return static_cast<Uiaw::RowOrColumnMajor>(v);
}

//
// enum ToggleState
//
namespace {
    using UiaUnder_ToggleState = std::underlying_type_t<::ToggleState>;
    using UiawUnder_ToggleState = std::underlying_type_t<Uiaw::ToggleState>;
    static_assert(std::is_same_v<UiaUnder_ToggleState, UiawUnder_ToggleState>);

    static_assert(static_cast<UiawUnder_ToggleState>(::ToggleState_Off) == static_cast<UiawUnder_ToggleState>(Uiaw::ToggleState::Off));
    static_assert(static_cast<UiawUnder_ToggleState>(::ToggleState_On) == static_cast<UiawUnder_ToggleState>(Uiaw::ToggleState::On));
    static_assert(static_cast<UiawUnder_ToggleState>(::ToggleState_Indeterminate) == static_cast<UiawUnder_ToggleState>(Uiaw::ToggleState::Indeterminate));
}
::ToggleState ToUia(Uiaw::ToggleState v) {
    return static_cast<::ToggleState>(v);
}
Uiaw::ToggleState ToUiaw(::ToggleState v) {
    return static_cast<Uiaw::ToggleState>(v);
}

//
// enum WindowVisualState
//
namespace {
    using UiaUnder_WindowVisualState = std::underlying_type_t<::WindowVisualState>;
    using UiawUnder_WindowVisualState = std::underlying_type_t<Uiaw::WindowVisualState>;
    static_assert(std::is_same_v<UiaUnder_WindowVisualState, UiawUnder_WindowVisualState>);

    static_assert(static_cast<UiawUnder_WindowVisualState>(::WindowVisualState_Normal) == static_cast<UiawUnder_WindowVisualState>(Uiaw::WindowVisualState::Normal));
    static_assert(static_cast<UiawUnder_WindowVisualState>(::WindowVisualState_Maximized) == static_cast<UiawUnder_WindowVisualState>(Uiaw::WindowVisualState::Maximized));
    static_assert(static_cast<UiawUnder_WindowVisualState>(::WindowVisualState_Minimized) == static_cast<UiawUnder_WindowVisualState>(Uiaw::WindowVisualState::Minimized));
}
::WindowVisualState ToUia(Uiaw::WindowVisualState v) {
    return static_cast<::WindowVisualState>(v);
}
Uiaw::WindowVisualState ToUiaw(::WindowVisualState v) {
    return static_cast<Uiaw::WindowVisualState>(v);
}

//
// enum SynchronizedInputType
//
namespace
{
    using UiaUnder_SynchronizedInputType = std::underlying_type_t<::SynchronizedInputType>;
    using UiawUnder_SynchronizedInputType = std::underlying_type_t<Uiaw::SynchronizedInputType>;
    static_assert(std::is_same_v<UiaUnder_SynchronizedInputType, UiawUnder_SynchronizedInputType>);

    static_assert(static_cast<UiawUnder_SynchronizedInputType>(::SynchronizedInputType_KeyUp) == static_cast<UiawUnder_SynchronizedInputType>(Uiaw::SynchronizedInputType::KeyUp));
    static_assert(static_cast<UiawUnder_SynchronizedInputType>(::SynchronizedInputType_KeyDown) == static_cast<UiawUnder_SynchronizedInputType>(Uiaw::SynchronizedInputType::KeyDown));
    static_assert(static_cast<UiawUnder_SynchronizedInputType>(::SynchronizedInputType_LeftMouseUp) == static_cast<UiawUnder_SynchronizedInputType>(Uiaw::SynchronizedInputType::LeftMouseUp));
    static_assert(static_cast<UiawUnder_SynchronizedInputType>(::SynchronizedInputType_LeftMouseDown) == static_cast<UiawUnder_SynchronizedInputType>(Uiaw::SynchronizedInputType::LeftMouseDown));
    static_assert(static_cast<UiawUnder_SynchronizedInputType>(::SynchronizedInputType_RightMouseUp) == static_cast<UiawUnder_SynchronizedInputType>(Uiaw::SynchronizedInputType::RightMouseUp));
    static_assert(static_cast<UiawUnder_SynchronizedInputType>(::SynchronizedInputType_RightMouseDown) == static_cast<UiawUnder_SynchronizedInputType>(Uiaw::SynchronizedInputType::RightMouseDown));
}
::SynchronizedInputType ToUia(Uiaw::SynchronizedInputType v) {
    return static_cast<::SynchronizedInputType>(v);
}
Uiaw::SynchronizedInputType ToUiaw(::SynchronizedInputType v) {
    return static_cast<Uiaw::SynchronizedInputType>(v);
}

//
// enum WindowInteractionState
//
namespace {
    using UiaUnder_WindowInteractionState = std::underlying_type_t<::WindowInteractionState>;
    using UiawUnder_WindowInteractionState = std::underlying_type_t<Uiaw::WindowInteractionState>;
    static_assert(std::is_same_v<UiaUnder_WindowInteractionState, UiawUnder_WindowInteractionState>);

    static_assert(static_cast<UiawUnder_WindowInteractionState>(::WindowInteractionState_Running) == static_cast<UiawUnder_WindowInteractionState>(Uiaw::WindowInteractionState::Running));
    static_assert(static_cast<UiawUnder_WindowInteractionState>(::WindowInteractionState_Closing) == static_cast<UiawUnder_WindowInteractionState>(Uiaw::WindowInteractionState::Closing));
    static_assert(static_cast<UiawUnder_WindowInteractionState>(::WindowInteractionState_ReadyForUserInteraction) == static_cast<UiawUnder_WindowInteractionState>(Uiaw::WindowInteractionState::ReadyForUserInteraction));
    static_assert(static_cast<UiawUnder_WindowInteractionState>(::WindowInteractionState_BlockedByModalWindow) == static_cast<UiawUnder_WindowInteractionState>(Uiaw::WindowInteractionState::BlockedByModalWindow));
    static_assert(static_cast<UiawUnder_WindowInteractionState>(::WindowInteractionState_NotResponding) == static_cast<UiawUnder_WindowInteractionState>(Uiaw::WindowInteractionState::NotResponding));
}
::WindowInteractionState ToUia(Uiaw::WindowInteractionState v) {
    return static_cast<::WindowInteractionState>(v);
}
Uiaw::WindowInteractionState ToUiaw(::WindowInteractionState v) {
    return static_cast<Uiaw::WindowInteractionState>(v);
}

//
// enum SayAsInterpretAs
//
namespace {
    using UiaUnder_SayAsInterpretAs = std::underlying_type_t<::SayAsInterpretAs>;
    using UiawUnder_SayAsInterpretAs = std::underlying_type_t<Uiaw::SayAsInterpretAs>;
    static_assert(std::is_same_v<UiaUnder_SayAsInterpretAs, UiawUnder_SayAsInterpretAs>);

    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_None) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::None));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Spell) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Spell));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Cardinal) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Cardinal));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Ordinal) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Ordinal));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Number) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Number));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Date) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Date));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Time) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Time));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Telephone) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Telephone));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Currency) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Currency));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Net) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Net));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Url) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Url));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Address) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Address));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Alphanumeric) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Alphanumeric));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Name) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Name));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Media) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Media));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Date_MonthDayYear) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Date_MonthDayYear));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Date_DayMonthYear) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Date_DayMonthYear));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Date_YearMonthDay) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Date_YearMonthDay));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Date_YearMonth) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Date_YearMonth));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Date_MonthYear) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Date_MonthYear));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Date_DayMonth) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Date_DayMonth));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Date_MonthDay) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Date_MonthDay));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Date_Year) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Date_Year));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Time_HoursMinutesSeconds12) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Time_HoursMinutesSeconds12));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Time_HoursMinutes12) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Time_HoursMinutes12));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Time_HoursMinutesSeconds24) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Time_HoursMinutesSeconds24));
    static_assert(static_cast<UiawUnder_SayAsInterpretAs>(::SayAsInterpretAs_Time_HoursMinutes24) == static_cast<UiawUnder_SayAsInterpretAs>(Uiaw::SayAsInterpretAs::Time_HoursMinutes24));
}
::SayAsInterpretAs ToUia(Uiaw::SayAsInterpretAs v) {
    return static_cast<::SayAsInterpretAs>(v);
}
Uiaw::SayAsInterpretAs ToUiaw(::SayAsInterpretAs v) {
    return static_cast<Uiaw::SayAsInterpretAs>(v);
}

//
// enum TextUnit
//
namespace {
    using UiaUnder_TextUnit = std::underlying_type_t<::TextUnit>;
    using UiawUnder_TextUnit = std::underlying_type_t<Uiaw::TextUnit>;
    static_assert(std::is_same_v<UiaUnder_TextUnit, UiawUnder_TextUnit>);

    static_assert(static_cast<UiawUnder_TextUnit>(::TextUnit_Character) == static_cast<UiawUnder_TextUnit>(Uiaw::TextUnit::Character));
    static_assert(static_cast<UiawUnder_TextUnit>(::TextUnit_Format) == static_cast<UiawUnder_TextUnit>(Uiaw::TextUnit::Format));
    static_assert(static_cast<UiawUnder_TextUnit>(::TextUnit_Word) == static_cast<UiawUnder_TextUnit>(Uiaw::TextUnit::Word));
    static_assert(static_cast<UiawUnder_TextUnit>(::TextUnit_Line) == static_cast<UiawUnder_TextUnit>(Uiaw::TextUnit::Line));
    static_assert(static_cast<UiawUnder_TextUnit>(::TextUnit_Paragraph) == static_cast<UiawUnder_TextUnit>(Uiaw::TextUnit::Paragraph));
    static_assert(static_cast<UiawUnder_TextUnit>(::TextUnit_Page) == static_cast<UiawUnder_TextUnit>(Uiaw::TextUnit::Page));
    static_assert(static_cast<UiawUnder_TextUnit>(::TextUnit_Document) == static_cast<UiawUnder_TextUnit>(Uiaw::TextUnit::Document));
}
::TextUnit ToUia(Uiaw::TextUnit v) {
    return static_cast<::TextUnit>(v);
}
Uiaw::TextUnit ToUiaw(::TextUnit v) {
    return static_cast<Uiaw::TextUnit>(v);
}

//
// enum TextPatternRangeEndpoint
//
namespace {
    using UiaUnder_TextPatternRangeEndpoint = std::underlying_type_t<::TextPatternRangeEndpoint>;
    using UiawUnder_TextPatternRangeEndpoint = std::underlying_type_t<Uiaw::TextPatternRangeEndpoint>;
    static_assert(std::is_same_v<UiaUnder_TextPatternRangeEndpoint, UiawUnder_TextPatternRangeEndpoint>);

    static_assert(static_cast<UiawUnder_TextPatternRangeEndpoint>(::TextPatternRangeEndpoint_Start) == static_cast<UiawUnder_TextPatternRangeEndpoint>(Uiaw::TextPatternRangeEndpoint::Start));
    static_assert(static_cast<UiawUnder_TextPatternRangeEndpoint>(::TextPatternRangeEndpoint_End) == static_cast<UiawUnder_TextPatternRangeEndpoint>(Uiaw::TextPatternRangeEndpoint::End));
}
::TextPatternRangeEndpoint ToUia(Uiaw::TextPatternRangeEndpoint v) {
    return static_cast<::TextPatternRangeEndpoint>(v);
}
Uiaw::TextPatternRangeEndpoint ToUiaw(::TextPatternRangeEndpoint v) {
    return static_cast<Uiaw::TextPatternRangeEndpoint>(v);
}

//
// enum SupportedTextSelection
//
namespace {
    using UiaUnder_SupportedTextSelection = std::underlying_type_t<::SupportedTextSelection>;
    using UiawUnder_SupportedTextSelection = std::underlying_type_t<Uiaw::SupportedTextSelection>;
    static_assert(std::is_same_v<UiaUnder_SupportedTextSelection, UiawUnder_SupportedTextSelection>);

    static_assert(static_cast<UiawUnder_SupportedTextSelection>(::SupportedTextSelection_None) == static_cast<UiawUnder_SupportedTextSelection>(Uiaw::SupportedTextSelection::None));
    static_assert(static_cast<UiawUnder_SupportedTextSelection>(::SupportedTextSelection_Single) == static_cast<UiawUnder_SupportedTextSelection>(Uiaw::SupportedTextSelection::Single));
    static_assert(static_cast<UiawUnder_SupportedTextSelection>(::SupportedTextSelection_Multiple) == static_cast<UiawUnder_SupportedTextSelection>(Uiaw::SupportedTextSelection::Multiple));
}
::SupportedTextSelection ToUia(Uiaw::SupportedTextSelection v) {
    return static_cast<::SupportedTextSelection>(v);
}
Uiaw::SupportedTextSelection ToUiaw(::SupportedTextSelection v) {
    return static_cast<Uiaw::SupportedTextSelection>(v);
}

//
// enum LiveSetting
//
namespace {
    using UiaUnder_LiveSetting = std::underlying_type_t<::LiveSetting>;
    using UiawUnder_LiveSetting = std::underlying_type_t<Uiaw::LiveSetting>;
    static_assert(std::is_same_v<UiaUnder_LiveSetting, UiawUnder_LiveSetting>);

    static_assert(static_cast<UiawUnder_LiveSetting>(::Off) == static_cast<UiawUnder_LiveSetting>(Uiaw::LiveSetting::Off));
    static_assert(static_cast<UiawUnder_LiveSetting>(::Polite) == static_cast<UiawUnder_LiveSetting>(Uiaw::LiveSetting::Polite));
    static_assert(static_cast<UiawUnder_LiveSetting>(::Assertive) == static_cast<UiawUnder_LiveSetting>(Uiaw::LiveSetting::Assertive));
}
::LiveSetting ToUia(Uiaw::LiveSetting v) {
    return static_cast<::LiveSetting>(v);
}
Uiaw::LiveSetting ToUiaw(::LiveSetting v) {
    return static_cast<Uiaw::LiveSetting>(v);
}

//
// enum ActiveEnd
//
namespace {
    using UiaUnder_ActiveEnd = std::underlying_type_t<::ActiveEnd>;
    using UiawUnder_ActiveEnd = std::underlying_type_t<Uiaw::ActiveEnd>;
    static_assert(std::is_same_v<UiaUnder_ActiveEnd, UiawUnder_ActiveEnd>);

    static_assert(static_cast<UiawUnder_ActiveEnd>(::ActiveEnd_None) == static_cast<UiawUnder_ActiveEnd>(Uiaw::ActiveEnd::None));
    static_assert(static_cast<UiawUnder_ActiveEnd>(::ActiveEnd_Start) == static_cast<UiawUnder_ActiveEnd>(Uiaw::ActiveEnd::Start));
    static_assert(static_cast<UiawUnder_ActiveEnd>(::ActiveEnd_End) == static_cast<UiawUnder_ActiveEnd>(Uiaw::ActiveEnd::End));
}
::ActiveEnd ToUia(Uiaw::ActiveEnd v) {
    return static_cast<::ActiveEnd>(v);
}
Uiaw::ActiveEnd ToUiaw(::ActiveEnd v) {
    return static_cast<Uiaw::ActiveEnd>(v);
}

//
// enum CaretPosition
//
namespace {
    using UiaUnder_CaretPosition = std::underlying_type_t<::CaretPosition>;
    using UiawUnder_CaretPosition = std::underlying_type_t<Uiaw::CaretPosition>;
    static_assert(std::is_same_v<UiaUnder_CaretPosition, UiawUnder_CaretPosition>);

    static_assert(static_cast<UiawUnder_CaretPosition>(::CaretPosition_Unknown) == static_cast<UiawUnder_CaretPosition>(Uiaw::CaretPosition::Unknown));
    static_assert(static_cast<UiawUnder_CaretPosition>(::CaretPosition_EndOfLine) == static_cast<UiawUnder_CaretPosition>(Uiaw::CaretPosition::EndOfLine));
    static_assert(static_cast<UiawUnder_CaretPosition>(::CaretPosition_BeginningOfLine) == static_cast<UiawUnder_CaretPosition>(Uiaw::CaretPosition::BeginningOfLine));
}
::CaretPosition ToUia(Uiaw::CaretPosition v) {
    return static_cast<::CaretPosition>(v);
}
Uiaw::CaretPosition ToUiaw(::CaretPosition v) {
    return static_cast<Uiaw::CaretPosition>(v);
}

//
// enum CaretBidiMode
//
namespace {
    using UiaUnder_CaretBidiMode = std::underlying_type_t<::CaretBidiMode>;
    using UiawUnder_CaretBidiMode = std::underlying_type_t<Uiaw::CaretBidiMode>;
    static_assert(std::is_same_v<UiaUnder_CaretBidiMode, UiawUnder_CaretBidiMode>);

    static_assert(static_cast<UiawUnder_CaretBidiMode>(::CaretBidiMode_LTR) == static_cast<UiawUnder_CaretBidiMode>(Uiaw::CaretBidiMode::LTR));
    static_assert(static_cast<UiawUnder_CaretBidiMode>(::CaretBidiMode_RTL) == static_cast<UiawUnder_CaretBidiMode>(Uiaw::CaretBidiMode::RTL));
}
::CaretBidiMode ToUia(Uiaw::CaretBidiMode v) {
    return static_cast<::CaretBidiMode>(v);
}
Uiaw::CaretBidiMode ToUiaw(::CaretBidiMode v) {
    return static_cast<Uiaw::CaretBidiMode>(v);
}

//
// enum ZoomUnit
//
namespace {
    using UiaUnder_ZoomUnit = std::underlying_type_t<::ZoomUnit>;
    using UiawUnder_ZoomUnit = std::underlying_type_t<Uiaw::ZoomUnit>;
    static_assert(std::is_same_v<UiaUnder_ZoomUnit, UiawUnder_ZoomUnit>);

    static_assert(static_cast<UiawUnder_ZoomUnit>(::ZoomUnit_NoAmount) == static_cast<UiawUnder_ZoomUnit>(Uiaw::ZoomUnit::NoAmount));
    static_assert(static_cast<UiawUnder_ZoomUnit>(::ZoomUnit_LargeDecrement) == static_cast<UiawUnder_ZoomUnit>(Uiaw::ZoomUnit::LargeDecrement));
    static_assert(static_cast<UiawUnder_ZoomUnit>(::ZoomUnit_SmallDecrement) == static_cast<UiawUnder_ZoomUnit>(Uiaw::ZoomUnit::SmallDecrement));
    static_assert(static_cast<UiawUnder_ZoomUnit>(::ZoomUnit_LargeIncrement) == static_cast<UiawUnder_ZoomUnit>(Uiaw::ZoomUnit::LargeIncrement));
    static_assert(static_cast<UiawUnder_ZoomUnit>(::ZoomUnit_SmallIncrement) == static_cast<UiawUnder_ZoomUnit>(Uiaw::ZoomUnit::SmallIncrement));
}
::ZoomUnit ToUia(Uiaw::ZoomUnit v) {
    return static_cast<::ZoomUnit>(v);
}
Uiaw::ZoomUnit ToUiaw(::ZoomUnit v) {
    return static_cast<Uiaw::ZoomUnit>(v);
}

//
// enum AnimationStyle
//
namespace {
    using UiaUnder_AnimationStyle = std::underlying_type_t<::AnimationStyle>;
    using UiawUnder_AnimationStyle = std::underlying_type_t<Uiaw::AnimationStyle>;
    static_assert(std::is_same_v<UiaUnder_AnimationStyle, UiawUnder_AnimationStyle>);

    static_assert(static_cast<UiawUnder_AnimationStyle>(::AnimationStyle_None) == static_cast<UiawUnder_AnimationStyle>(Uiaw::AnimationStyle::None));
    static_assert(static_cast<UiawUnder_AnimationStyle>(::AnimationStyle_LasVegasLights) == static_cast<UiawUnder_AnimationStyle>(Uiaw::AnimationStyle::LasVegasLights));
    static_assert(static_cast<UiawUnder_AnimationStyle>(::AnimationStyle_BlinkingBackground) == static_cast<UiawUnder_AnimationStyle>(Uiaw::AnimationStyle::BlinkingBackground));
    static_assert(static_cast<UiawUnder_AnimationStyle>(::AnimationStyle_SparkleText) == static_cast<UiawUnder_AnimationStyle>(Uiaw::AnimationStyle::SparkleText));
    static_assert(static_cast<UiawUnder_AnimationStyle>(::AnimationStyle_MarchingBlackAnts) == static_cast<UiawUnder_AnimationStyle>(Uiaw::AnimationStyle::MarchingBlackAnts));
    static_assert(static_cast<UiawUnder_AnimationStyle>(::AnimationStyle_MarchingRedAnts) == static_cast<UiawUnder_AnimationStyle>(Uiaw::AnimationStyle::MarchingRedAnts));
    static_assert(static_cast<UiawUnder_AnimationStyle>(::AnimationStyle_Shimmer) == static_cast<UiawUnder_AnimationStyle>(Uiaw::AnimationStyle::Shimmer));
    static_assert(static_cast<UiawUnder_AnimationStyle>(::AnimationStyle_Other) == static_cast<UiawUnder_AnimationStyle>(Uiaw::AnimationStyle::Other));
}
::AnimationStyle ToUia(Uiaw::AnimationStyle v) {
    return static_cast<::AnimationStyle>(v);
}
Uiaw::AnimationStyle ToUiaw(::AnimationStyle v) {
    return static_cast<Uiaw::AnimationStyle>(v);
}

//
// enum BulletStyle
//
namespace {
    using UiaUnder_BulletStyle = std::underlying_type_t<::BulletStyle>;
    using UiawUnder_BulletStyle = std::underlying_type_t<Uiaw::BulletStyle>;
    static_assert(std::is_same_v<UiaUnder_BulletStyle, UiawUnder_BulletStyle>);

    static_assert(static_cast<UiawUnder_BulletStyle>(::BulletStyle_None) == static_cast<UiawUnder_BulletStyle>(Uiaw::BulletStyle::None));
    static_assert(static_cast<UiawUnder_BulletStyle>(::BulletStyle_HollowRoundBullet) == static_cast<UiawUnder_BulletStyle>(Uiaw::BulletStyle::HollowRoundBullet));
    static_assert(static_cast<UiawUnder_BulletStyle>(::BulletStyle_FilledRoundBullet) == static_cast<UiawUnder_BulletStyle>(Uiaw::BulletStyle::FilledRoundBullet));
    static_assert(static_cast<UiawUnder_BulletStyle>(::BulletStyle_HollowSquareBullet) == static_cast<UiawUnder_BulletStyle>(Uiaw::BulletStyle::HollowSquareBullet));
    static_assert(static_cast<UiawUnder_BulletStyle>(::BulletStyle_FilledSquareBullet) == static_cast<UiawUnder_BulletStyle>(Uiaw::BulletStyle::FilledSquareBullet));
    static_assert(static_cast<UiawUnder_BulletStyle>(::BulletStyle_DashBullet) == static_cast<UiawUnder_BulletStyle>(Uiaw::BulletStyle::DashBullet));
    static_assert(static_cast<UiawUnder_BulletStyle>(::BulletStyle_Other) == static_cast<UiawUnder_BulletStyle>(Uiaw::BulletStyle::Other));
}
::BulletStyle ToUia(Uiaw::BulletStyle v) {
    return static_cast<::BulletStyle>(v);
}
Uiaw::BulletStyle ToUiaw(::BulletStyle v) {
    return static_cast<Uiaw::BulletStyle>(v);
}

//
// enum CapStyle
//
namespace {
    using UiaUnder_CapStyle = std::underlying_type_t<::CapStyle>;
    using UiawUnder_CapStyle = std::underlying_type_t<Uiaw::CapStyle>;
    static_assert(std::is_same_v<UiaUnder_CapStyle, UiawUnder_CapStyle>);

    static_assert(static_cast<UiawUnder_CapStyle>(::CapStyle_None) == static_cast<UiawUnder_CapStyle>(Uiaw::CapStyle::None));
    static_assert(static_cast<UiawUnder_CapStyle>(::CapStyle_SmallCap) == static_cast<UiawUnder_CapStyle>(Uiaw::CapStyle::SmallCap));
    static_assert(static_cast<UiawUnder_CapStyle>(::CapStyle_AllCap) == static_cast<UiawUnder_CapStyle>(Uiaw::CapStyle::AllCap));
    static_assert(static_cast<UiawUnder_CapStyle>(::CapStyle_AllPetiteCaps) == static_cast<UiawUnder_CapStyle>(Uiaw::CapStyle::AllPetiteCaps));
    static_assert(static_cast<UiawUnder_CapStyle>(::CapStyle_PetiteCaps) == static_cast<UiawUnder_CapStyle>(Uiaw::CapStyle::PetiteCaps));
    static_assert(static_cast<UiawUnder_CapStyle>(::CapStyle_Unicase) == static_cast<UiawUnder_CapStyle>(Uiaw::CapStyle::Unicase));
    static_assert(static_cast<UiawUnder_CapStyle>(::CapStyle_Titling) == static_cast<UiawUnder_CapStyle>(Uiaw::CapStyle::Titling));
    static_assert(static_cast<UiawUnder_CapStyle>(::CapStyle_Other) == static_cast<UiawUnder_CapStyle>(Uiaw::CapStyle::Other));
}
::CapStyle ToUia(Uiaw::CapStyle v) {
    return static_cast<::CapStyle>(v);
}
Uiaw::CapStyle ToUiaw(::CapStyle v) {
    return static_cast<Uiaw::CapStyle>(v);
}

//
// enum FillType
//
namespace {
    using UiaUnder_FillType = std::underlying_type_t<::FillType>;
    using UiawUnder_FillType = std::underlying_type_t<Uiaw::FillType>;
    static_assert(std::is_same_v<UiaUnder_FillType, UiawUnder_FillType>);

    static_assert(static_cast<UiawUnder_FillType>(::FillType_None) == static_cast<UiawUnder_FillType>(Uiaw::FillType::None));
    static_assert(static_cast<UiawUnder_FillType>(::FillType_Color) == static_cast<UiawUnder_FillType>(Uiaw::FillType::Color));
    static_assert(static_cast<UiawUnder_FillType>(::FillType_Gradient) == static_cast<UiawUnder_FillType>(Uiaw::FillType::Gradient));
    static_assert(static_cast<UiawUnder_FillType>(::FillType_Picture) == static_cast<UiawUnder_FillType>(Uiaw::FillType::Picture));
    static_assert(static_cast<UiawUnder_FillType>(::FillType_Pattern) == static_cast<UiawUnder_FillType>(Uiaw::FillType::Pattern));
}
::FillType ToUia(Uiaw::FillType v) {
    return static_cast<::FillType>(v);
}
Uiaw::FillType ToUiaw(::FillType v) {
    return static_cast<Uiaw::FillType>(v);
}

//
// enum FlowDirections
//
namespace {
    using UiaUnder_FlowDirections = std::underlying_type_t<::FlowDirections>;
    using UiawUnder_FlowDirections = std::underlying_type_t<Uiaw::FlowDirections>;
    static_assert(std::is_same_v<UiaUnder_FlowDirections, UiawUnder_FlowDirections>);

    static_assert(static_cast<UiawUnder_FlowDirections>(::FlowDirections_Default) == static_cast<UiawUnder_FlowDirections>(Uiaw::FlowDirections::Default));
    static_assert(static_cast<UiawUnder_FlowDirections>(::FlowDirections_RightToLeft) == static_cast<UiawUnder_FlowDirections>(Uiaw::FlowDirections::RightToLeft));
    static_assert(static_cast<UiawUnder_FlowDirections>(::FlowDirections_BottomToTop) == static_cast<UiawUnder_FlowDirections>(Uiaw::FlowDirections::BottomToTop));
    static_assert(static_cast<UiawUnder_FlowDirections>(::FlowDirections_Vertical) == static_cast<UiawUnder_FlowDirections>(Uiaw::FlowDirections::Vertical));
}
::FlowDirections ToUia(Uiaw::FlowDirections v) {
    return static_cast<::FlowDirections>(v);
}
Uiaw::FlowDirections ToUiaw(::FlowDirections v) {
    return static_cast<Uiaw::FlowDirections>(v);
}

//
// enum HorizontalTextAlignment
//
namespace
{
    using UiaUnder_HorizontalTextAlignment = std::underlying_type_t<::HorizontalTextAlignment>;
    using UiawUnder_HorizontalTextAlignment = std::underlying_type_t<Uiaw::HorizontalTextAlignment>;
    static_assert(std::is_same_v<UiaUnder_HorizontalTextAlignment, UiawUnder_HorizontalTextAlignment>);

    static_assert(static_cast<UiawUnder_HorizontalTextAlignment>(::HorizontalTextAlignment_Left) == static_cast<UiawUnder_HorizontalTextAlignment>(Uiaw::HorizontalTextAlignment::Left));
    static_assert(static_cast<UiawUnder_HorizontalTextAlignment>(::HorizontalTextAlignment_Centered) == static_cast<UiawUnder_HorizontalTextAlignment>(Uiaw::HorizontalTextAlignment::Centered));
    static_assert(static_cast<UiawUnder_HorizontalTextAlignment>(::HorizontalTextAlignment_Right) == static_cast<UiawUnder_HorizontalTextAlignment>(Uiaw::HorizontalTextAlignment::Right));
    static_assert(static_cast<UiawUnder_HorizontalTextAlignment>(::HorizontalTextAlignment_Justified) == static_cast<UiawUnder_HorizontalTextAlignment>(Uiaw::HorizontalTextAlignment::Justified));
}
::HorizontalTextAlignment ToUia(Uiaw::HorizontalTextAlignment v) {
    return static_cast<::HorizontalTextAlignment>(v);
}
Uiaw::HorizontalTextAlignment ToUiaw(::HorizontalTextAlignment v) {
    return static_cast<Uiaw::HorizontalTextAlignment>(v);
}

//
// enum OutlineStyles
//
namespace
{
    using UiaUnder_OutlineStyles = std::underlying_type_t<::OutlineStyles>;
    using UiawUnder_OutlineStyles = std::underlying_type_t<Uiaw::OutlineStyles>;
    static_assert(std::is_same_v<UiaUnder_OutlineStyles, UiawUnder_OutlineStyles>);

    static_assert(static_cast<UiawUnder_OutlineStyles>(::OutlineStyles_None) == static_cast<UiawUnder_OutlineStyles>(Uiaw::OutlineStyles::None));
    static_assert(static_cast<UiawUnder_OutlineStyles>(::OutlineStyles_Outline) == static_cast<UiawUnder_OutlineStyles>(Uiaw::OutlineStyles::Outline));
    static_assert(static_cast<UiawUnder_OutlineStyles>(::OutlineStyles_Shadow) == static_cast<UiawUnder_OutlineStyles>(Uiaw::OutlineStyles::Shadow));
    static_assert(static_cast<UiawUnder_OutlineStyles>(::OutlineStyles_Engraved) == static_cast<UiawUnder_OutlineStyles>(Uiaw::OutlineStyles::Engraved));
    static_assert(static_cast<UiawUnder_OutlineStyles>(::OutlineStyles_Embossed) == static_cast<UiawUnder_OutlineStyles>(Uiaw::OutlineStyles::Embossed));
}
::OutlineStyles ToUia(Uiaw::OutlineStyles v) {
    return static_cast<::OutlineStyles>(v);
}
Uiaw::OutlineStyles ToUiaw(::OutlineStyles v) {
    return static_cast<Uiaw::OutlineStyles>(v);
}

//
// enum TextDecorationLineStyle
//
namespace {
    using UiaUnder_TextDecorationLineStyle = std::underlying_type_t<::TextDecorationLineStyle>;
    using UiawUnder_TextDecorationLineStyle = std::underlying_type_t<Uiaw::TextDecorationLineStyle>;
    static_assert(std::is_same_v<UiaUnder_TextDecorationLineStyle, UiawUnder_TextDecorationLineStyle>);

    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_None) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::None));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_Single) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::Single));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_WordsOnly) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::WordsOnly));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_Double) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::Double));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_Dot) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::Dot));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_Dash) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::Dash));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_DashDot) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::DashDot));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_DashDotDot) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::DashDotDot));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_Wavy) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::Wavy));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_ThickSingle) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::ThickSingle));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_DoubleWavy) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::DoubleWavy));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_ThickWavy) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::ThickWavy));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_LongDash) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::LongDash));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_ThickDash) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::ThickDash));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_ThickDashDot) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::ThickDashDot));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_ThickDashDotDot) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::ThickDashDotDot));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_ThickDot) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::ThickDot));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_ThickLongDash) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::ThickLongDash));
    static_assert(static_cast<UiawUnder_TextDecorationLineStyle>(::TextDecorationLineStyle_Other) == static_cast<UiawUnder_TextDecorationLineStyle>(Uiaw::TextDecorationLineStyle::Other));
}
::TextDecorationLineStyle ToUia(Uiaw::TextDecorationLineStyle v) {
    return static_cast<::TextDecorationLineStyle>(v);
}
Uiaw::TextDecorationLineStyle ToUiaw(::TextDecorationLineStyle v) {
    return static_cast<Uiaw::TextDecorationLineStyle>(v);
}

//
// enum VisualEffects
//
namespace {
    using UiaUnder_VisualEffects = std::underlying_type_t<::VisualEffects>;
    using UiawUnder_VisualEffects = std::underlying_type_t<Uiaw::VisualEffects>;
    static_assert(std::is_same_v<UiaUnder_VisualEffects, UiawUnder_VisualEffects>);

    static_assert(static_cast<UiawUnder_VisualEffects>(::VisualEffects_None) == static_cast<UiawUnder_VisualEffects>(Uiaw::VisualEffects::None));
    static_assert(static_cast<UiawUnder_VisualEffects>(::VisualEffects_Shadow) == static_cast<UiawUnder_VisualEffects>(Uiaw::VisualEffects::Shadow));
    static_assert(static_cast<UiawUnder_VisualEffects>(::VisualEffects_Reflection) == static_cast<UiawUnder_VisualEffects>(Uiaw::VisualEffects::Reflection));
    static_assert(static_cast<UiawUnder_VisualEffects>(::VisualEffects_Glow) == static_cast<UiawUnder_VisualEffects>(Uiaw::VisualEffects::Glow));
    static_assert(static_cast<UiawUnder_VisualEffects>(::VisualEffects_SoftEdges) == static_cast<UiawUnder_VisualEffects>(Uiaw::VisualEffects::SoftEdges));
    static_assert(static_cast<UiawUnder_VisualEffects>(::VisualEffects_Bevel) == static_cast<UiawUnder_VisualEffects>(Uiaw::VisualEffects::Bevel));
}
::VisualEffects ToUia(Uiaw::VisualEffects v) {
    return static_cast<::VisualEffects>(v);
}
Uiaw::VisualEffects ToUiaw(::VisualEffects v) {
    return static_cast<Uiaw::VisualEffects>(v);
}

//
// enum NotificationProcessing
//
namespace {
    using UiaUnder_NotificationProcessing = std::underlying_type_t<::NotificationProcessing>;
    using UiawUnder_NotificationProcessing = std::underlying_type_t<Uiaw::NotificationProcessing>;
    static_assert(std::is_same_v<UiaUnder_NotificationProcessing, UiawUnder_NotificationProcessing>);

    static_assert(static_cast<UiawUnder_NotificationProcessing>(::NotificationProcessing_ImportantAll) == static_cast<UiawUnder_NotificationProcessing>(Uiaw::NotificationProcessing::ImportantAll));
    static_assert(static_cast<UiawUnder_NotificationProcessing>(::NotificationProcessing_ImportantMostRecent) == static_cast<UiawUnder_NotificationProcessing>(Uiaw::NotificationProcessing::ImportantMostRecent));
    static_assert(static_cast<UiawUnder_NotificationProcessing>(::NotificationProcessing_All) == static_cast<UiawUnder_NotificationProcessing>(Uiaw::NotificationProcessing::All));
    static_assert(static_cast<UiawUnder_NotificationProcessing>(::NotificationProcessing_MostRecent) == static_cast<UiawUnder_NotificationProcessing>(Uiaw::NotificationProcessing::MostRecent));
    static_assert(static_cast<UiawUnder_NotificationProcessing>(::NotificationProcessing_CurrentThenMostRecent) == static_cast<UiawUnder_NotificationProcessing>(Uiaw::NotificationProcessing::CurrentThenMostRecent));
    static_assert(static_cast<UiawUnder_NotificationProcessing>(::NotificationProcessing_ImportantCurrentThenMostRecent) == static_cast<UiawUnder_NotificationProcessing>(Uiaw::NotificationProcessing::ImportantCurrentThenMostRecent));
}
::NotificationProcessing ToUia(Uiaw::NotificationProcessing v) {
    return static_cast<::NotificationProcessing>(v);
}
Uiaw::NotificationProcessing ToUiaw(::NotificationProcessing v) {
    return static_cast<Uiaw::NotificationProcessing>(v);
}

//
// enum NotificationKind
//
namespace {
    using UiaUnder_NotificationKind = std::underlying_type_t<::NotificationKind>;
    using UiawUnder_NotificationKind = std::underlying_type_t<Uiaw::NotificationKind>;
    static_assert(std::is_same_v<UiaUnder_NotificationKind, UiawUnder_NotificationKind>);

    static_assert(static_cast<UiawUnder_NotificationKind>(::NotificationKind_ItemAdded) == static_cast<UiawUnder_NotificationKind>(Uiaw::NotificationKind::ItemAdded));
    static_assert(static_cast<UiawUnder_NotificationKind>(::NotificationKind_ItemRemoved) == static_cast<UiawUnder_NotificationKind>(Uiaw::NotificationKind::ItemRemoved));
    static_assert(static_cast<UiawUnder_NotificationKind>(::NotificationKind_ActionCompleted) == static_cast<UiawUnder_NotificationKind>(Uiaw::NotificationKind::ActionCompleted));
    static_assert(static_cast<UiawUnder_NotificationKind>(::NotificationKind_ActionAborted) == static_cast<UiawUnder_NotificationKind>(Uiaw::NotificationKind::ActionAborted));
    static_assert(static_cast<UiawUnder_NotificationKind>(::NotificationKind_Other) == static_cast<UiawUnder_NotificationKind>(Uiaw::NotificationKind::Other));
}
::NotificationKind ToUia(Uiaw::NotificationKind v) {
    return static_cast<::NotificationKind>(v);
}
Uiaw::NotificationKind ToUiaw(::NotificationKind v) {
    return static_cast<Uiaw::NotificationKind>(v);
}

//
// enum UIAutomationType
//
namespace {
    using UiaUnder_UIAutomationType = std::underlying_type_t<::UIAutomationType>;
    using UiawUnder_UIAutomationType = std::underlying_type_t<Uiaw::UIAutomationType>;
    static_assert(std::is_same_v<UiaUnder_UIAutomationType, UiawUnder_UIAutomationType>);

    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_Int) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::Int));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_Bool) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::Bool));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_String) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::String));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_Double) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::Double));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_Point) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::Point));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_Rect) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::Rect));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_Element) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::Element));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_Array) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::Array));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_Out) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::Out));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_IntArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::IntArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_BoolArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::BoolArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_StringArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::StringArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_DoubleArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::DoubleArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_PointArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::PointArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_RectArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::RectArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_ElementArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::ElementArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutInt) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutInt));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutBool) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutBool));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutString) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutString));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutDouble) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutDouble));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutPoint) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutPoint));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutRect) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutRect));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutElement) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutElement));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutIntArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutIntArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutBoolArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutBoolArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutStringArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutStringArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutDoubleArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutDoubleArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutPointArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutPointArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutRectArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutRectArray));
    static_assert(static_cast<UiawUnder_UIAutomationType>(::UIAutomationType_OutElementArray) == static_cast<UiawUnder_UIAutomationType>(Uiaw::UIAutomationType::OutElementArray));
}
::UIAutomationType ToUia(Uiaw::UIAutomationType v) {
    return static_cast<::UIAutomationType>(v);
}
Uiaw::UIAutomationType ToUiaw(::UIAutomationType v) {
    return static_cast<Uiaw::UIAutomationType>(v);
}


//-------------------------------------------------------------------------------------------------
// UIAutomationClient.h enums
//-------------------------------------------------------------------------------------------------
namespace {
    using UiaUnder = std::underlying_type_t<::TreeScope>;
    using UiawUnder = std::underlying_type_t<Uiaw::TreeScope>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::TreeScope::TreeScope_None) == static_cast<UiawUnder>(Uiaw::TreeScope::None));
    static_assert(static_cast<UiawUnder>(::TreeScope::TreeScope_Element) == static_cast<UiawUnder>(Uiaw::TreeScope::Element));
    static_assert(static_cast<UiawUnder>(::TreeScope::TreeScope_Children) == static_cast<UiawUnder>(Uiaw::TreeScope::Children));
    static_assert(static_cast<UiawUnder>(::TreeScope::TreeScope_Descendants) == static_cast<UiawUnder>(Uiaw::TreeScope::Descendants));
    static_assert(static_cast<UiawUnder>(::TreeScope::TreeScope_Parent) == static_cast<UiawUnder>(Uiaw::TreeScope::Parent));
    static_assert(static_cast<UiawUnder>(::TreeScope::TreeScope_Ancestors) == static_cast<UiawUnder>(Uiaw::TreeScope::Ancestors));
    static_assert(static_cast<UiawUnder>(::TreeScope::TreeScope_Subtree) == static_cast<UiawUnder>(Uiaw::TreeScope::Subtree));
}

::TreeScope ToUia(Uiaw::TreeScope v) {
    return static_cast<::TreeScope>(v);
}
Uiaw::TreeScope ToUiaw(::TreeScope v) {
    return static_cast<Uiaw::TreeScope>(v);
}


//
// enum PropertyConditionFlags
//
namespace {
    using UiaUnder = std::underlying_type_t<::PropertyConditionFlags>;
    using UiawUnder = std::underlying_type_t<Uiaw::PropertyConditionFlags>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::PropertyConditionFlags::PropertyConditionFlags_None) == static_cast<UiawUnder>(Uiaw::PropertyConditionFlags::None));
    static_assert(static_cast<UiawUnder>(::PropertyConditionFlags::PropertyConditionFlags_IgnoreCase) == static_cast<UiawUnder>(Uiaw::PropertyConditionFlags::IgnoreCase));
    static_assert(static_cast<UiawUnder>(::PropertyConditionFlags::PropertyConditionFlags_MatchSubstring) == static_cast<UiawUnder>(Uiaw::PropertyConditionFlags::MatchSubstring));
}

::PropertyConditionFlags ToUia(Uiaw::PropertyConditionFlags v) {
    return static_cast<::PropertyConditionFlags>(v);
}
Uiaw::PropertyConditionFlags ToUiaw(::PropertyConditionFlags v) {
    return static_cast<Uiaw::PropertyConditionFlags>(v);
}


//
// enum AutomationElementMode
//
namespace {
    using UiaUnder = std::underlying_type_t<::AutomationElementMode>;
    using UiawUnder = std::underlying_type_t<Uiaw::AutomationElementMode>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::AutomationElementMode::AutomationElementMode_None) == static_cast<UiawUnder>(Uiaw::AutomationElementMode::None));
    static_assert(static_cast<UiawUnder>(::AutomationElementMode::AutomationElementMode_Full) == static_cast<UiawUnder>(Uiaw::AutomationElementMode::Full));
}

::AutomationElementMode ToUia(Uiaw::AutomationElementMode v) {
    return static_cast<::AutomationElementMode>(v);
}
Uiaw::AutomationElementMode ToUiaw(::AutomationElementMode v) {
    return static_cast<Uiaw::AutomationElementMode>(v);
}


//
// enum TreeTraversalOptions
//
namespace {
    using UiaUnder = std::underlying_type_t<::TreeTraversalOptions>;
    using UiawUnder = std::underlying_type_t<Uiaw::TreeTraversalOptions>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::TreeTraversalOptions::TreeTraversalOptions_Default) == static_cast<UiawUnder>(Uiaw::TreeTraversalOptions::Default));
    static_assert(static_cast<UiawUnder>(::TreeTraversalOptions::TreeTraversalOptions_PostOrder) == static_cast<UiawUnder>(Uiaw::TreeTraversalOptions::PostOrder));
    static_assert(static_cast<UiawUnder>(::TreeTraversalOptions::TreeTraversalOptions_LastToFirstOrder) == static_cast<UiawUnder>(Uiaw::TreeTraversalOptions::LastToFirstOrder));
}

::TreeTraversalOptions ToUia(Uiaw::TreeTraversalOptions v) {
    return static_cast<::TreeTraversalOptions>(v);
}
Uiaw::TreeTraversalOptions ToUiaw(::TreeTraversalOptions v) {
    return static_cast<Uiaw::TreeTraversalOptions>(v);
}


//
// enum ConnectionRecoveryBehaviorOptions
//
namespace {
    using UiaUnder = std::underlying_type_t<::ConnectionRecoveryBehaviorOptions>;
    using UiawUnder = std::underlying_type_t<Uiaw::ConnectionRecoveryBehaviorOptions>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::ConnectionRecoveryBehaviorOptions::ConnectionRecoveryBehaviorOptions_Disabled) == static_cast<UiawUnder>(Uiaw::ConnectionRecoveryBehaviorOptions::Disabled));
    static_assert(static_cast<UiawUnder>(::ConnectionRecoveryBehaviorOptions::ConnectionRecoveryBehaviorOptions_Enabled) == static_cast<UiawUnder>(Uiaw::ConnectionRecoveryBehaviorOptions::Enabled));
}

::ConnectionRecoveryBehaviorOptions ToUia(Uiaw::ConnectionRecoveryBehaviorOptions v) {
    return static_cast<::ConnectionRecoveryBehaviorOptions>(v);
}
Uiaw::ConnectionRecoveryBehaviorOptions ToUiaw(::ConnectionRecoveryBehaviorOptions v) {
    return static_cast<Uiaw::ConnectionRecoveryBehaviorOptions>(v);
}


//
// enum CoalesceEventsOptions
//
namespace {
    using UiaUnder = std::underlying_type_t<::CoalesceEventsOptions>;
    using UiawUnder = std::underlying_type_t<Uiaw::CoalesceEventsOptions>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::CoalesceEventsOptions::CoalesceEventsOptions_Disabled) == static_cast<UiawUnder>(Uiaw::CoalesceEventsOptions::Disabled));
    static_assert(static_cast<UiawUnder>(::CoalesceEventsOptions::CoalesceEventsOptions_Enabled) == static_cast<UiawUnder>(Uiaw::CoalesceEventsOptions::Enabled));
}

::CoalesceEventsOptions ToUia(Uiaw::CoalesceEventsOptions v){
    return static_cast<::CoalesceEventsOptions>(v);
}
Uiaw::CoalesceEventsOptions ToUiaw(::CoalesceEventsOptions v) {
    return static_cast<Uiaw::CoalesceEventsOptions>(v);
}


//-------------------------------------------------------------------------------------------------
// UIAutomationCoreApi.h enums
//-------------------------------------------------------------------------------------------------

//
// enum ConditionType
//
namespace {
    using UiaUnder = std::underlying_type_t<::ConditionType>;
    using UiawUnder = std::underlying_type_t<Uiaw::ConditionType>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::ConditionType::ConditionType_True) == static_cast<UiawUnder>(Uiaw::ConditionType::True));
    static_assert(static_cast<UiawUnder>(::ConditionType::ConditionType_False) == static_cast<UiawUnder>(Uiaw::ConditionType::False));
    static_assert(static_cast<UiawUnder>(::ConditionType::ConditionType_Property) == static_cast<UiawUnder>(Uiaw::ConditionType::Property));
    static_assert(static_cast<UiawUnder>(::ConditionType::ConditionType_And) == static_cast<UiawUnder>(Uiaw::ConditionType::And));
    static_assert(static_cast<UiawUnder>(::ConditionType::ConditionType_Or) == static_cast<UiawUnder>(Uiaw::ConditionType::Or));
    static_assert(static_cast<UiawUnder>(::ConditionType::ConditionType_Not) == static_cast<UiawUnder>(Uiaw::ConditionType::Not));
}

::ConditionType ToUia(Uiaw::ConditionType v) {
    return static_cast<::ConditionType>(v);
}
Uiaw::ConditionType ToUiaw(::ConditionType v) {
    return static_cast<Uiaw::ConditionType>(v);
}


//
// enum NormalizeState
//
namespace {
    using UiaUnder = std::underlying_type_t<::NormalizeState>;
    using UiawUnder = std::underlying_type_t<Uiaw::NormalizeState>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::NormalizeState::NormalizeState_None) == static_cast<UiawUnder>(Uiaw::NormalizeState::None));
    static_assert(static_cast<UiawUnder>(::NormalizeState::NormalizeState_View) == static_cast<UiawUnder>(Uiaw::NormalizeState::View));
    static_assert(static_cast<UiawUnder>(::NormalizeState::NormalizeState_Custom) == static_cast<UiawUnder>(Uiaw::NormalizeState::Custom));
}

::NormalizeState ToUia(Uiaw::NormalizeState v) {
    return static_cast<::NormalizeState>(v);
}
Uiaw::NormalizeState ToUiaw(::NormalizeState v) {
    return static_cast<Uiaw::NormalizeState>(v);
}


//
// enum ProviderType
//
namespace {
    using UiaUnder = std::underlying_type_t<::ProviderType>;
    using UiawUnder = std::underlying_type_t<Uiaw::ProviderType>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::ProviderType::ProviderType_BaseHwnd) == static_cast<UiawUnder>(Uiaw::ProviderType::BaseHwnd));
    static_assert(static_cast<UiawUnder>(::ProviderType::ProviderType_Proxy) == static_cast<UiawUnder>(Uiaw::ProviderType::Proxy));
    static_assert(static_cast<UiawUnder>(::ProviderType::ProviderType_NonClientArea) == static_cast<UiawUnder>(Uiaw::ProviderType::NonClientArea));
}

::ProviderType ToUia(Uiaw::ProviderType v) {
    return static_cast<::ProviderType>(v);
}
Uiaw::ProviderType ToUiaw(::ProviderType v) {
    return static_cast<Uiaw::ProviderType>(v);
}


//
// enum AutomationIdentifierType
//
namespace {
    using UiaUnder = std::underlying_type_t<::AutomationIdentifierType>;
    using UiawUnder = std::underlying_type_t<Uiaw::AutomationIdentifierType>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::AutomationIdentifierType::AutomationIdentifierType_Property) == static_cast<UiawUnder>(Uiaw::AutomationIdentifierType::Property));
    static_assert(static_cast<UiawUnder>(::AutomationIdentifierType::AutomationIdentifierType_Pattern) == static_cast<UiawUnder>(Uiaw::AutomationIdentifierType::Pattern));
    static_assert(static_cast<UiawUnder>(::AutomationIdentifierType::AutomationIdentifierType_Event) == static_cast<UiawUnder>(Uiaw::AutomationIdentifierType::Event));
    static_assert(static_cast<UiawUnder>(::AutomationIdentifierType::AutomationIdentifierType_ControlType) == static_cast<UiawUnder>(Uiaw::AutomationIdentifierType::ControlType));
    static_assert(static_cast<UiawUnder>(::AutomationIdentifierType::AutomationIdentifierType_TextAttribute) == static_cast<UiawUnder>(Uiaw::AutomationIdentifierType::TextAttribute));
    static_assert(static_cast<UiawUnder>(::AutomationIdentifierType::AutomationIdentifierType_LandmarkType) == static_cast<UiawUnder>(Uiaw::AutomationIdentifierType::LandmarkType));
    static_assert(static_cast<UiawUnder>(::AutomationIdentifierType::AutomationIdentifierType_Annotation) == static_cast<UiawUnder>(Uiaw::AutomationIdentifierType::Annotation));
    static_assert(static_cast<UiawUnder>(::AutomationIdentifierType::AutomationIdentifierType_Changes) == static_cast<UiawUnder>(Uiaw::AutomationIdentifierType::Changes));
    static_assert(static_cast<UiawUnder>(::AutomationIdentifierType::AutomationIdentifierType_Style) == static_cast<UiawUnder>(Uiaw::AutomationIdentifierType::Style));
}

::AutomationIdentifierType ToUia(Uiaw::AutomationIdentifierType v) {
    return static_cast<::AutomationIdentifierType>(v);
}
Uiaw::AutomationIdentifierType ToUiaw(::AutomationIdentifierType v) {
    return static_cast<Uiaw::AutomationIdentifierType>(v);
}


//
// enum EventArgsType
//
namespace {
    using UiaUnder = std::underlying_type_t<::EventArgsType>;
    using UiawUnder = std::underlying_type_t<Uiaw::EventArgsType>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::EventArgsType::EventArgsType_Simple) == static_cast<UiawUnder>(Uiaw::EventArgsType::Simple));
    static_assert(static_cast<UiawUnder>(::EventArgsType::EventArgsType_PropertyChanged) == static_cast<UiawUnder>(Uiaw::EventArgsType::PropertyChanged));
    static_assert(static_cast<UiawUnder>(::EventArgsType::EventArgsType_StructureChanged) == static_cast<UiawUnder>(Uiaw::EventArgsType::StructureChanged));
    static_assert(static_cast<UiawUnder>(::EventArgsType::EventArgsType_AsyncContentLoaded) == static_cast<UiawUnder>(Uiaw::EventArgsType::AsyncContentLoaded));
    static_assert(static_cast<UiawUnder>(::EventArgsType::EventArgsType_WindowClosed) == static_cast<UiawUnder>(Uiaw::EventArgsType::WindowClosed));
    static_assert(static_cast<UiawUnder>(::EventArgsType::EventArgsType_TextEditTextChanged) == static_cast<UiawUnder>(Uiaw::EventArgsType::TextEditTextChanged));
    static_assert(static_cast<UiawUnder>(::EventArgsType::EventArgsType_Changes) == static_cast<UiawUnder>(Uiaw::EventArgsType::Changes));
    static_assert(static_cast<UiawUnder>(::EventArgsType::EventArgsType_Notification) == static_cast<UiawUnder>(Uiaw::EventArgsType::Notification));
    static_assert(static_cast<UiawUnder>(::EventArgsType::EventArgsType_ActiveTextPositionChanged) == static_cast<UiawUnder>(Uiaw::EventArgsType::ActiveTextPositionChanged));
    static_assert(static_cast<UiawUnder>(::EventArgsType::EventArgsType_StructuredMarkup) == static_cast<UiawUnder>(Uiaw::EventArgsType::StructuredMarkup));
}

::EventArgsType ToUia(Uiaw::EventArgsType v) {
    return static_cast<::EventArgsType>(v);
}
Uiaw::EventArgsType ToUiaw(::EventArgsType v) {
    return static_cast<Uiaw::EventArgsType>(v);
}


//
// enum AsyncContentLoadedState
//
namespace
{
    using UiaUnder = std::underlying_type_t<::AsyncContentLoadedState>;
    using UiawUnder = std::underlying_type_t<Uiaw::AsyncContentLoadedState>;
    static_assert(std::is_same_v<UiaUnder, UiawUnder>);

    static_assert(static_cast<UiawUnder>(::AsyncContentLoadedState::AsyncContentLoadedState_Beginning) == static_cast<UiawUnder>(Uiaw::AsyncContentLoadedState::Beginning));
    static_assert(static_cast<UiawUnder>(::AsyncContentLoadedState::AsyncContentLoadedState_Progress) == static_cast<UiawUnder>(Uiaw::AsyncContentLoadedState::Progress));
    static_assert(static_cast<UiawUnder>(::AsyncContentLoadedState::AsyncContentLoadedState_Completed) == static_cast<UiawUnder>(Uiaw::AsyncContentLoadedState::Completed));
}

::AsyncContentLoadedState ToUia(Uiaw::AsyncContentLoadedState v) {
    return static_cast<::AsyncContentLoadedState>(v);
}
Uiaw::AsyncContentLoadedState ToUiaw(::AsyncContentLoadedState v) {
    return static_cast<Uiaw::AsyncContentLoadedState>(v);
}


} // namespace Uiaw





