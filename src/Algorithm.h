//
// Created by Daniel Ryan on 1/25/22.
//

#ifndef INC_22S_PA01_ALGORITHM_H
#define INC_22S_PA01_ALGORITHM_H

#include <iostream>
#include "Museum.h"


class Algorithm {
private:
    Museum m;

    void bfGetSubsets();
    void bfGetSubsetsNest(vector<Art>, int, int)
public:
    Algorithm() = default;

    double bruteForce(char*);
    double mostExpensiveFirst(char*);

};


#endif //INC_22S_PA01_ALGORITHM_H
