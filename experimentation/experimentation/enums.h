#pragma once
namespace Uiaw {

//-------------------------------------------------------------------------------------------------
// UIAutomationCore.h enums
//-------------------------------------------------------------------------------------------------
enum class AnnoScope {
	This = 0,
	Container = 1,
};

enum class NavigateDirection {
	Parent = 0,
	NextSibling = 1,
	PreviousSibling = 2,
	FirstChild = 3,
	LastChild = 4,
};

enum class ProviderOptions {
	ClientSideProvider = 0x1,
	ServerSideProvider = 0x2,
	NonClientAreaProvider = 0x4,
	OverrideProvider = 0x8,
	ProviderOwnsSetFocus = 0x10,
	UseComThreading = 0x20,
	RefuseNonClientSupport = 0x40,
	HasNativeIAccessible = 0x80,
	UseClientCoordinates = 0x100,
};

enum class StructureChangeType {
	ChildAdded = 0,
	ChildRemoved = 1,
	ChildrenInvalidated = 2,
	ChildrenBulkAdded = 3,
	ChildrenBulkRemoved = 4,
	ChildrenReordered = 5,
};

enum class TextEditChangeType {
	None = 0,
	AutoCorrect = 1,
	Composition = 2,
	CompositionFinalized = 3,
	AutoComplete = 4,
};

enum class OrientationType {
	None = 0,
	Horizontal = 1,
	Vertical = 2,
};

enum class DockPosition {
	Top = 0,
	Left = 1,
	Bottom = 2,
	Right = 3,
	Fill = 4,
	None = 5,
};

enum class ExpandCollapseState {
	Collapsed = 0,
	Expanded = 1,
	PartiallyExpanded = 2,
	LeafNode = 3,
};

enum class ScrollAmount {
	LargeDecrement = 0,
	SmallDecrement = 1,
	NoAmount = 2,
	LargeIncrement = 3,
	SmallIncrement = 4,
};

enum class RowOrColumnMajor {
	RowMajor = 0,
	ColumnMajor = 1,
	Indeterminate = 2,
};

enum class ToggleState {
	Off = 0,
	On = 1,
	Indeterminate = 2,
};

enum class WindowVisualState {
	Normal = 0,
	Maximized = 1,
	Minimized = 2,
};

enum class SynchronizedInputType {
	KeyUp = 0x1,
	KeyDown = 0x2,
	LeftMouseUp = 0x4,
	LeftMouseDown = 0x8,
	RightMouseUp = 0x10,
	RightMouseDown = 0x20,
};

enum class WindowInteractionState {
	Running = 0,
	Closing = 1,
	ReadyForUserInteraction = 2,
	BlockedByModalWindow = 3,
	NotResponding = 4,
};

enum class SayAsInterpretAs {
	None = 0,
	Spell = 1,
	Cardinal = 2,
	Ordinal = 3,
	Number = 4,
	Date = 5,
	Time = 6,
	Telephone = 7,
	Currency = 8,
	Net = 9,
	Url = 10,
	Address = 11,
	Alphanumeric = 12,
	Name = 13,
	Media = 14,
	Date_MonthDayYear = 15,
	Date_DayMonthYear = 16,
	Date_YearMonthDay = 17,
	Date_YearMonth = 18,
	Date_MonthYear = 19,
	Date_DayMonth = 20,
	Date_MonthDay = 21,
	Date_Year = 22,
	Time_HoursMinutesSeconds12 = 23,
	Time_HoursMinutes12 = 24,
	Time_HoursMinutesSeconds24 = 25,
	Time_HoursMinutes24 = 26,
};

enum class TextUnit {
	Character = 0,
	Format = 1,
	Word = 2,
	Line = 3,
	Paragraph = 4,
	Page = 5,
	Document = 6,
};

enum class TextPatternRangeEndpoint {
	Start = 0,
	End = 1,
};

enum class SupportedTextSelection {
	None = 0,
	Single = 1,
	Multiple = 2,
};

enum class LiveSetting {
	Off = 0,
	Polite = 1,
	Assertive = 2,
};

enum class ActiveEnd {
	None = 0,
	Start = 1,
	End = 2,
};

enum class CaretPosition {
	Unknown = 0,
	EndOfLine = 1,
	BeginningOfLine = 2,
};

enum class CaretBidiMode {
	LTR = 0,
	RTL = 1,
};

enum class ZoomUnit {
	NoAmount = 0,
	LargeDecrement = 1,
	SmallDecrement = 2,
	LargeIncrement = 3,
	SmallIncrement = 4,
};

enum class AnimationStyle {
	None = 0,
	LasVegasLights = 1,
	BlinkingBackground = 2,
	SparkleText = 3,
	MarchingBlackAnts = 4,
	MarchingRedAnts = 5,
	Shimmer = 6,
	Other = -1,
};

enum class BulletStyle {
	None = 0,
	HollowRoundBullet = 1,
	FilledRoundBullet = 2,
	HollowSquareBullet = 3,
	FilledSquareBullet = 4,
	DashBullet = 5,
	Other = -1,
};

enum class CapStyle {
	None = 0,
	SmallCap = 1,
	AllCap = 2,
	AllPetiteCaps = 3,
	PetiteCaps = 4,
	Unicase = 5,
	Titling = 6,
	Other = -1,
};

enum class FillType {
	None = 0,
	Color = 1,
	Gradient = 2,
	Picture = 3,
	Pattern = 4,
};

enum class FlowDirections {
	Default = 0,
	RightToLeft = 0x1,
	BottomToTop = 0x2,
	Vertical = 0x4,
};

enum class HorizontalTextAlignment {
	Left = 0,
	Centered = 1,
	Right = 2,
	Justified = 3,
};

enum class OutlineStyles {
	None = 0,
	Outline = 1,
	Shadow = 2,
	Engraved = 4,
	Embossed = 8,
};

enum class TextDecorationLineStyle {
	None = 0,
	Single = 1,
	WordsOnly = 2,
	Double = 3,
	Dot = 4,
	Dash = 5,
	DashDot = 6,
	DashDotDot = 7,
	Wavy = 8,
	ThickSingle = 9,
	DoubleWavy = 11,
	ThickWavy = 12,
	LongDash = 13,
	ThickDash = 14,
	ThickDashDot = 15,
	ThickDashDotDot = 16,
	ThickDot = 17,
	ThickLongDash = 18,
	Other = -1,
};

enum class VisualEffects {
	None = 0,
	Shadow = (1 << 0),
	Reflection = (1 << 1),
	Glow = (1 << 2),
	SoftEdges = (1 << 3),
	Bevel = (1 << 4),
};

enum class NotificationProcessing {
	ImportantAll = 0,
	ImportantMostRecent = 1,
	All = 2,
	MostRecent = 3,
	CurrentThenMostRecent = 4,
	ImportantCurrentThenMostRecent = 5,
};

enum class NotificationKind {
	ItemAdded = 0,
	ItemRemoved = 1,
	ActionCompleted = 2,
	ActionAborted = 3,
	Other = 4,
};

enum class UIAutomationType {
	Int = 0x1,
	Bool = 0x2,
	String = 0x3,
	Double = 0x4,
	Point = 0x5,
	Rect = 0x6,
	Element = 0x7,
	Array = 0x10000,
	Out = 0x20000,
	IntArray = (0x1 | 0x10000),
	BoolArray = (0x2 | 0x10000),
	StringArray = (0x3 | 0x10000),
	DoubleArray = (0x4 | 0x10000),
	PointArray = (0x5 | 0x10000),
	RectArray = (0x6 | 0x10000),
	ElementArray = (0x7 | 0x10000),
	OutInt = (0x1 | 0x20000),
	OutBool = (0x2 | 0x20000),
	OutString = (0x3 | 0x20000),
	OutDouble = (0x4 | 0x20000),
	OutPoint = (0x5 | 0x20000),
	OutRect = (0x6 | 0x20000),
	OutElement = (0x7 | 0x20000),
	OutIntArray = ((0x1 | 0x10000) | 0x20000),
	OutBoolArray = ((0x2 | 0x10000) | 0x20000),
	OutStringArray = ((0x3 | 0x10000) | 0x20000),
	OutDoubleArray = ((0x4 | 0x10000) | 0x20000),
	OutPointArray = ((0x5 | 0x10000) | 0x20000),
	OutRectArray = ((0x6 | 0x10000) | 0x20000),
	OutElementArray = ((0x7 | 0x10000) | 0x20000),
};

//-------------------------------------------------------------------------------------------------
// UIAutomationClient.h enums
//-------------------------------------------------------------------------------------------------
	
enum class TreeScope {
	None = 0,
	Element = 0x1,
	Children = 0x2,
	Descendants = 0x4,
	Parent = 0x8,
	Ancestors = 0x10,
	Subtree = ((0x1 | 0x2) | 0x4),
};

enum class PropertyConditionFlags {
	None = 0,
	IgnoreCase = 0x1,
	MatchSubstring = 0x2,
};

enum class AutomationElementMode {
	None = 0,
	Full = 1,
};

enum class TreeTraversalOptions {
	Default = 0,
	PostOrder = 0x1,
	LastToFirstOrder = 0x2,
};

enum class ConnectionRecoveryBehaviorOptions {
	Disabled = 0,
	Enabled = 0x1,
};

enum class CoalesceEventsOptions {
	Disabled = 0,
	Enabled = 0x1,
};

//-------------------------------------------------------------------------------------------------
// UIAutomationCoreApi.h enums
//-------------------------------------------------------------------------------------------------

enum class ConditionType {
	True = 0,
	False = 1,
	Property = 2,
	And = 3,
	Or = 4,
	Not = 5,
};

enum class NormalizeState {
	None = 0, // Don't normalize
	View = 1, // Normalize against condition in UiaCacheRequest
	Custom = 2, // Normalize against supplied condition
};

enum class ProviderType {
	BaseHwnd = 0,
	Proxy = 1,
	NonClientArea = 2,
};

enum class AutomationIdentifierType {
	Property = 0,
	Pattern = 1,
	Event = 2,
	ControlType = 3,
	TextAttribute = 4,
	LandmarkType = 5,
	Annotation = 6,
	Changes = 7,
	Style = 8,
};

enum class EventArgsType {
	Simple = 0,
	PropertyChanged = 1,
	StructureChanged = 2,
	AsyncContentLoaded = 3,
	WindowClosed = 4,
	TextEditTextChanged = 5,
	Changes = 6,
	Notification = 7,
	ActiveTextPositionChanged = 8,
	StructuredMarkup = 9,
};

enum class AsyncContentLoadedState {
	Beginning = 0,
	Progress = 1,
	Completed = 2,
};









} // namespace Uiaw

