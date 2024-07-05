# cmake-startup-project

An ultra-basic CMake project for when I want to quickly test something outside existing projects. For a (much) more capable CMake setup, see [another project of mine here](https://github.com/adentinger/CMakeBestPractices).

## Usage

Requirements:
- A compiler supporting at least C++17 is installed, such as MSVC (that comes with Visual Studio), GCC or Clang.
- Assuming `CMAKE_DIR` contains a recent enough CMake installation (otherwise [get one here](https://cmake.org/download/)).
- Assuming a generator supported by CMake is installed. I recommend either [Ninja](https://github.com/ninja-build/ninja), which would need to be inside your shell's `PATH`, or one of the IDE generators, like `Visual Studio 17 2022` or `Xcode`. For a list of generators, run `${CMAKE_DIR}/bin/cmake -G` or see [here](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html).

```bash
cd <this-dir> && \
${CMAKE_DIR}/bin/cmake -S . -B build -G "<generator>" -DCMAKE_INSTALL_PREFIX:STRING="<this-dir>/install" -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE && \
${CMAKE_DIR}/bin/cmake --build build --config Debug -j10 && \
${CMAKE_DIR}/bin/ctest --test-dir build --build-config Debug -j10 && \
${CMAKE_DIR}/bin/cmake --install build --config Debug
```

In the commands above, replace `<this-dir>` by the path to the directory containing this `README.md` file, replace `<generator>` by the chosen generator, and `${CMAKE_DIR}` by the directory where CMake is installed as explained above. If your shell is not bash (e.g., it is CMD/PowerShell), you should remove the `&& \` at the end of each command to run the commands separately.

Then, on Linux/MacOS, run `./install/bin/foo` to run the program. On Windows, run `install/bin/foo.exe` to run it.

## VSCode IDE support

This project supports IDE integration with VSCode, which allows e.g. to view compile errors and warnings directly inside VSCode, allows finding definitions, etc. To enable this support:

1. Downlaod an LLVM release [here](https://github.com/llvm/llvm-project/releases), then install/extract it to a global location (such as `C:\dev-data\llvm`, `~/dev-data/llvm`, or the like).
2. In VSCode, install the `C/C++` extension (by Microsoft). You may also install the `CMake Tools` extension, also by Microsoft, but that is less important.
3. Open the `.vscode/settings.json` file, and follow the instructions to tell VSCode where you've installed LLVM and CMake once and for all.
4. Finally, in VSCode, do `Open Folder...` and select this directory.

All these steps, apart from the last one of course, are a one-time configuration for your system; you don't need to do them again if you delete this directory and clone it again. Also note that the VSCode integration relies on the `build/compile_commands.json` file, which is generated by CMake, so until you've run the first CMake command, the VSCode integration won't work properly.
