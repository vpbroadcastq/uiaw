add_library(uiaw STATIC 
	builtin_typedefs.cpp
	enums.cpp
	UIAutomation.cpp
	UIAutomationElement.cpp 
	UIAutomationCondition.cpp 
	UIAutomationTreeWalker.cpp
	variant.cpp)


target_include_directories(uiaw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

