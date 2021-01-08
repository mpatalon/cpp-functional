cmake_minimum_required(VERSION 3.13)
project(functional-cpp)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Werror
  )
endif()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(third-party/googletest EXCLUDE_FROM_ALL)
