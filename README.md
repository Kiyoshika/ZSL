# ZSL (Zach's Statistical Library)
A complete re-work of my statistical library "CppEZML". Now being renamed to ZSL (Zach's Statistical Library)...yeah, clever name.
# Building From Source
This is a typical CMake project, so after cloning the repo, run the below commands in the root folder directory.

### Dependencies
So far the only dependency is `googletest`, although I'm using CMake to fetch the library so you should have to just use `make install` at least once if you don't have gtest already.

### Mac/Linux
* `mkdir build`
* `cd build`
* `cmake ..`
* `make install` (only need to run this once to install dependencies into your /usr/local/include folder)
* `make` to compile all sources
* `ctest --output-on-failure` to run tests (--output-on-failure will give you verbose output if a test fails)
