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

    /**
     * Helper method for bruteForce algorithm
     * @param int the number of art pieces to process
     * @return vector<Wall>
     */
    vector<Wall> bfGetSubsets(int);
public:
    /**
     * Default Constructor
     */
    Algorithm() = default;
    Algorithm(char*);

    /**
     * Calculate all possible walls and return the value of the best wall given an input file
     * @param int the number of art pieces to process, default to size of the list
     * @return double
     */
    double bruteForce(int);

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

};


#endif //INC_22S_PA01_ALGORITHM_H
