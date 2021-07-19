#!/bin/bash

cd test
g++ -o testing main.cpp ../src/argumentparser.h ../src/argumentparser.cpp -L/usr/lib/ -lgtest -lgtest_main -pthread
./testing
rm ./testing