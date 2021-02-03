include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/third-party/googletest/googletest/include)

add_executable(test-libfunctional-cpp
  main.cpp
  chapter-01-test.cpp
  chapter-02-test.cpp
  )

target_link_libraries(test-libfunctional-cpp
  PRIVATE
    functional-cpp
    gtest
  )