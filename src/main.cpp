//
// Created by Zachary on 1/23/2022.
//

#include <iostream>
#include "Museum.h"
#include "Algorithm.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc == 1)
        cout << "No arguments provided." << endl;
    else {
        Algorithm a(argv[1]);
        cout << "Brute Force:          $" << a.bruteForce() << endl;
        cout << "Most Expensive First: $" << a.mostExpensiveFirst() << endl;
        cout << "Heuristic:            $" << a.heuristicAlgo() << endl;
    }
    return 0;
}