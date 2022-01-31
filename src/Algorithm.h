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
    Museum m;

    /**
     * Helper method for bruteForce algorithm
     * @return vector<Wall>
     */
    vector<Wall> bfGetSubsets();
public:
    Algorithm() = default;

    /**
     * Calculate all possible walls and return the value of the best wall given an input file
     * @return double
     */
    double bruteForce(char*);

    /**
     * Create the wall in order from most expensive to least expensive paintings and
     * return the value given an input file
     * @return double
     */
    double mostExpensiveFirst(char*);

};


#endif //INC_22S_PA01_ALGORITHM_H
