//
// Created by Daniel Ryan on 1/25/22.
//

#include "Algorithm.h"

double Algorithm::bruteForce(char* file) {
    //list of art pieces (vector<Art>): m.getList();
    //access the wall and related methods (Wall): m.getWall();

    // initialize the museum with the given file
    m.readFile(file);
    bfGetSubsets();
}

void Algorithm::bfGetSubsets() {
    // for loop delineating the limit of art pieces in the subset
    for (int limit = 1; limit < m.getList().size(); limit++) {
        vector<Art> subset;
        bfGetSubsetsNest(subset, 0, limit);
    }
}

void Algorithm::bfGetSubsetsNest(vector<Art> subset, int start, int numLeft) {
    for (int i = start; i < m.getList().size()-numLeft; i++) {
        subset.push_back(m.getArt(i));
        if (numLeft > 1)
            bfGetSubsetsNest(subset, i+1, numLeft-1);
    }
}