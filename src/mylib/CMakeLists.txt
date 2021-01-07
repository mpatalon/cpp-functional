add_library(mylib mymath.cpp)
target_include_directories(mylib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mylib PRIVATE project_options project_warnings)
