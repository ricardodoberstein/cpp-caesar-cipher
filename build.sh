#!/bin/bash

cd build
g++ -o CaesarCipher ../src/main.cpp ../src/cipher.cpp ../src/cipher.h ../src/ascii.cpp ../src/ascii.h ../src/filereader.h ../src/filereader.cpp ../src/filewriter.h ../src/filewriter.cpp ../src/argumentparser.h ../src/argumentparser.cpp