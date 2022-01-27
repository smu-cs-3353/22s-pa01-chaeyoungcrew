//
// Created by Daniel Ryan on 1/25/22.
//

#ifndef INC_22S_PA01_ALGORITHM_H
#define INC_22S_PA01_ALGORITHM_H

#include <iostream>
#include "Museum.h"


class Algorithm {

public:
    Algorithm() = default;

    double bruteForce(Museum&);
    double mostExpensiveFirst(Museum&);

};


#endif //INC_22S_PA01_ALGORITHM_H
