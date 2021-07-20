#!/bin/bash
cd test
g++ -o testing *.cpp ../src/*.h ../src/*.cpp -L/usr/lib/ -lgtest -lgtest_main -pthread
./testing
rm ./testing