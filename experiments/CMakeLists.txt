add_executable(experiments experiments.cpp)
target_link_libraries(experiments PRIVATE uiaw)

add_executable(uiwalk_children uiwalk_children.cpp)
target_link_libraries(uiwalk_children PRIVATE uiaw)

add_executable(uiawwalk_children uiawwalk_children.cpp)
target_link_libraries(uiawwalk_children PRIVATE uiaw)

