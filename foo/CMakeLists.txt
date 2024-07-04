file(GLOB_RECURSE CXX_SOURCES CONFIGURE_DEPENDS
  src/*.cpp)
file(GLOB_RECURSE CXX_HEADERS_PRIVATE CONFIGURE_DEPENDS
  src/*.h
  src/*.hpp)

add_executable(foo
  # I like to keep main.cpp separate from other sources in case I want to
  # run tests on the other sources. The test executable needs its own main()
  # function.
  main.cpp
  ${CXX_SOURCES})
target_sources(foo
  PRIVATE
    FILE_SET public_headers
    TYPE HEADERS
    BASE_DIRS src
    FILES ${CXX_HEADERS_PUBLIC})
install(TARGETS foo)
