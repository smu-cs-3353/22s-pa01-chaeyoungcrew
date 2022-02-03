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

        Algorithm a;
        cout << a.bruteForce("../Resources/testBruteForce") << endl;

        cout << a.mostExpensiveFirst("../Resources/testBruteForce") << endl;

    }
    return 0;
}