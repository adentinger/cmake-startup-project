# cmake-startup-project

An ultra-basic CMake project for when I want to quickly test something outside existing projects. For a (much) more capable CMake setup, see [another project of mine here](https://github.com/adentinger/CMakeBestPractices).

## Usage

Requirements:
- Assuming `CMAKE_DIR` contains a recent enough CMake installation (otherwise [get one here](https://cmake.org/download/)).
- Assuming a generator supported by CMake is installed. I recommend either [Ninja](https://github.com/ninja-build/ninja), which would need to be inside you shell's `PATH`, or one of the IDE generators, like `Visual Studio 17 2022`.

```bash
cd <this-dir>
${CMAKE_DIR}/bin/cmake -S . -B build -G "<generator>" -DCMAKE_INSTALL_PREFIX:STRING="<this-dir>/install" -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE
${CMAKE_DIR}/bin/cmake --build build -j10 --config Debug
${CMAKE_DIR}/bin/ctest --test-dir build --build-config Debug -j10
${CMAKE_DIR}/bin/cmake --install build --config Debug
```
