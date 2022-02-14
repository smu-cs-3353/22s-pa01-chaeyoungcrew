//
// Created by Daniel Ryan on 1/25/22.
//

#ifndef INC_22S_PA01_ALGORITHM_H
#define INC_22S_PA01_ALGORITHM_H

#include <iostream>
#include <cmath>
#include <float.h>
#include "Museum.h"

using namespace std;

class Algorithm {
private:
    // The museum
    Museum m;

    string fileName;

    /**
     * Helper method for bruteForce algorithm
     * @param int the number of art pieces to process
     * @return vector<Wall>
     */
    vector<Wall> bfGetSubsets();
public:
    /**
     * Default Constructor
     */
    Algorithm() = default;
    Algorithm(char*);
    Algorithm(char*, int);

    /**
     * Calculate all possible walls and return the value of the best wall given an input file
     * @param int the number of art pieces to process, default to size of the list
     * @return double
     */
    double bruteForce();

    /**
     * Create the wall in order from most expensive to least expensive paintings and
     * return the value given an input file
     * @return double
     */
    double mostExpensiveFirst();

    /**
     * Create the wall using a heuristic algorithm that orders
     * the paintings based on their total value, calculated with
     * price/width
     */
    double heuristicAlgo();

    /**
     * Creates the output file for the particular algorithm
     * @param wall the wall resulted from the algorithm
     * @param price the ending price of the art on the wall
     * @param algo the type of algorithm to be processed [b,e,h]
     */
     void outputFiles(const Wall&, int, char);

};


#endif //INC_22S_PA01_ALGORITHM_H
