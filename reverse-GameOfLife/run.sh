#!/bin/bash
g++ main.cpp gol.h gol.cpp -o gol.exe && echo "run main.exe"
echo "Running test ./tests/in$1.txt"
./gol.exe < tests/in$1.txt
rm gol.exe
