//
// Created by Zachary on 1/23/2022.
//

#include <iostream>
#include <iomanip>
#include <chrono>
#include "Algorithm.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc == 1)
        cout << "No arguments provided." << endl;
    else {
        ofstream data("input/data.csv");
        data << fixed << setprecision(5) << "Num,Brute,Expensive,Heuristic" << endl;
        cout << fixed << setprecision(5);
        for (int i = 1; i < 100000; i++) {
            if (i > 25)
                i += 1000;
            chrono::high_resolution_clock::time_point s1 = chrono::high_resolution_clock::now();
            Algorithm a(argv[1], i);
            chrono::high_resolution_clock::time_point s2 = chrono::high_resolution_clock::now();
            data << i << ",";

            cout << "-----" << i << "-----" << endl;

            chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
            cout << "Brute Force:          $" << a.bruteForce() << endl;
            chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> bruteTime = t2 - t1 + s2 - s1;
            cout << "Time: " << bruteTime.count() << " seconds." << endl;
            data << bruteTime.count() << ",";

            cout << "Most Expensive First: $" << a.mostExpensiveFirst() << endl;
            t1 = chrono::high_resolution_clock::now();
            chrono::duration<double> expensiveTime = t1 - t2 + s2 - s1;
            cout << "Time: " << expensiveTime.count() << " seconds." << endl;
            data << expensiveTime.count() << ",";

            cout << "Heuristic:            $" << a.heuristicAlgo() << endl;
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> heuristicTime = t2 - t1 + s2 - s1;
            cout << "Time: " << heuristicTime.count() << " seconds." << endl;
            data << heuristicTime.count() << endl;
        }
        data.close();


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