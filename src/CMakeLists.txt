add_library(functional-cpp
  chapter-01/count-lines-stdcount.cpp
  chapter-01/count-lines-transform.cpp
)

target_include_directories(functional-cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)