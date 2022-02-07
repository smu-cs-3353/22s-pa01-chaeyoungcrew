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
        Museum m;
        /*m.readFile(argv[1]);
        m.getWall();
        m.getList();
        m.getArt(12);
        cout << m << std::endl;
        cout << m.getWall() << std::endl;
        cout << m.getArt(12) << std::endl;*/

        Algorithm a(argv[1]);
        cout << "Brute Force: $" << a.bruteForce() << endl;
        cout << "Most Expensive First: $" << a.mostExpensiveFirst() << endl;

    }
    return 0;
}