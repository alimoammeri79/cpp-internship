#!/bin/bash
g++ main.cpp GOL.h GOL.cpp -o gol.exe && echo "run main.exe"
echo "Running test ./tests/in$1.txt"
./gol.exe < tests/in$1.txt
rm gol.exe
