cmake_minimum_required(VERSION 3.23)
project(foo
  VERSION 1.0.0.0
  DESCRIPTION "An ultra-basic CMake project for when I want to quickly test something outside existing projects."
  HOMEPAGE_URL "https://github.com/adentinger/cmake-startup-project"
  LANGUAGES CXX)

# So that CTest doesn't fail. If we have 0 tests and 0 tests pass, then all of
# them did!
enable_testing()

# The default C++ version to use in all libraries/executables.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(foo)
