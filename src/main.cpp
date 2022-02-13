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


        //code for toggleable menu for data collection
        /*
        bool loop = true;
        while (loop) {
            cout << "Options:\n"
                    "[1] brute force\n"
                    "[2] most expensive first\n"
                    "[3] heuristic\n"
                    "[*] any key to quit\n"
                    "Make a choice: " << endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Brute Force:          $" << a.bruteForce() << endl;
                    break;
                case 2:
                    cout << "Most Expensive First: $" << a.mostExpensiveFirst() << endl;
                    break;
                case 3:
                    cout << "Heuristic:            $" << a.heuristicAlgo() << endl;
                    break;
                default:
                    loop = false;
            }

        }
         */
    }
    return 0;
}