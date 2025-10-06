# Raycasting

A simple 3D project using RayLib to render with raycasting.

## Requirements
This project uses C++ 23, so you need the packages `g++-14` or `clang-20` (on Ubuntu) to be able to build.

## Build
Debug build:
```bash
mkdir -p build-debug
cmake -B build-debug -D CMAKE_CXX_COMPILER=g++-14 -D CMAKE_BUILD_TYPE=Debug
cmake --build build-debug --config Debug -t raycasting
```
Release build:
```bash
mkdir -p build-release
cmake -B build-debug -D CMAKE_CXX_COMPILER=g++-14 -D CMAKE_BUILD_TYPE=Release
cmake --build build-release --config Release -t raycasting
```
