# ZSL (Zach's Statistical Library)
A complete re-work of my statistical library "CppEZML". Now being renamed to ZSL (Zach's Statistical Library)...yeah, clever name.
# Building From Source
This is a typical CMake project, so after cloning the repo, run the following commands in the root directory.

NOTE: For Windows builds, I use MinGW compiler and hence, other windows compilers HAVE NOT BEEN TESTED.
### Windows
* `mkdir build`
* `cd build`
* `cmake -G "MinGW Makefiles" ..` (tell CMake to use MinGW compiler)
* `cmake --build .`
### Mac/Linux
* `mkdir build`
* `cd build`
* `cmake ..`
* `make`
