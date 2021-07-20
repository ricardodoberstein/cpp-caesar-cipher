#!/bin/bash
cd test
cmake -S . -B build
cmake --build build
cd build && ctest
