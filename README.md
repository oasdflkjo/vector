
[![C/C++ CI](https://github.com/oasdflkjo/vector/actions/workflows/ci.yml/badge.svg)](https://github.com/oasdflkjo/vector/actions/workflows/ci.yml)

# Vector Project

A simple vector implementation in C, providing dynamic resizing and generic data storage using void pointers. The goal is to offer C users an easy-to-integrate vector library.

## Build

To build the project, ensure CMake and Ninja are installed:

```sh
mkdir build
cd build
cmake -G Ninja ..
ninja
```

## Integration

You can add the vector repository as a submodule and integrate it into your CMake pipeline:

```sh
git submodule add https://github.com/oasdflkjo/vector.git
```

Include the vector library in your CMake project:

```cmake
add_subdirectory(vector)
include_directories(${VECTOR_INCLUDE_DIRS})
```

## License

This project is open source and available under the MIT License.
