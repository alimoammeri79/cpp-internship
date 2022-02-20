#!/bin/bash
g++ main.cpp -o gol.exe
echo "Running test ./tests/in$1.txt"
./gol.exe < tests/in$1.txt
rm gol.exe
