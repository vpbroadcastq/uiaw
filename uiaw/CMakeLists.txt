add_library(uiaw STATIC 
	builtin_typedefs.cpp
	enums.cpp
)

target_include_directories(uiaw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

