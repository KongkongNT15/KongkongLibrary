#!/bin/bash

g++ -std=c++20 -c ../../../src/All.cpp -O3
ar rcs klib.Lib All.o
