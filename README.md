# 🖼Art is Fun!

Art is Fun! is a C++ project that calculates the most valuable collection of paintings that will fit along a centered position on a wall. This is achieved by use of 3 different algorithms: brute force (finding all possible subsets and selecting the most valuable one), most expensive first (sorting the art pieces by their price and putting them on the wall from highest to lowest), and a heuristic algorithm, which in this case orders art pieces by how valuable they are (price divided by width).

## Installation

This project can be run in the commandline via g++, or by compiling in CLion using the CMakeLists.txt file with your chosen compiler. Below I will show you how to install g++. 

First, check if g++ is installed. 
```bash
$ g++ --version
```
If it is not installed, install it. 
```bash
$ sudo apt-get install g++
```

## Usage

First, navigate to the project directory.
```bash
$ cd FullFilePathHere
```
Next, compile all of the relevant files using g++
```bash
$ g++ src/main.cpp src.Art.cpp src/Wall.cpp src/DSLinkedList.h src/Museum.cpp src.Algorithm.cpp
```
Run the program
```bash
$ ./a.out data/inputFileHere.txt
```

## Credits
This project was completed entirely by Zach Suzuki and Daniel Ryan for CS3353, Fundamentals of Algorithms taught by Dr. Fontenot.
