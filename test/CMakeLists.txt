include_directories(${PROJECT_SOURCE_DIR}/third-party/googletest/googletest/include)

add_executable(test-libmylib
  main.cpp
  fib_test.cpp
  )

target_link_libraries(test-libmylib
  PRIVATE
    mylib
    gtest
  )
