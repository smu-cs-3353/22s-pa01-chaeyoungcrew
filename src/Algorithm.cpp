//
// Created by Daniel Ryan on 1/25/22.
//
// Working Comments: The brute force algorithm is finished, but it currently
// only works if the IDs start at 0, and have every integer up to the size.
// Maybe change it so that accessing the Art can be by ID or by location in the vector?
//

#include "Algorithm.h"

double Algorithm::bruteForce(char* file) {
    // initialize the museum with the given file
    m.readFile(file);

    // vector of all subsets found through brute force
    vector<Wall> subsets = bfGetSubsets();

    // loop through list of subsets and find the one with the maximum value
    double max = -DBL_MAX;
    for (int i = 0; i < subsets.size(); i++) {
        if (subsets.at(i).getCurrentPrice() > max)
            max = subsets.at(i).getCurrentPrice();
    }
    return max;
}

vector<Wall> Algorithm::bfGetSubsets() {
    // trackers for the loops
    int size = m.getList().size();
    int big = pow(2, size);

    // create all possible subsets
    vector<Wall> subsets;
    for (int i = 0; i < big; i++) {
        // boolean variable to handle for invalid subsets
        bool add = true;
        for (int j = 0; j < size; j++) {
            if ((i & (1 << j)) != 0) {
                // handle for if the art cannot be added, if it can't, this is an invalid subset so throw it away
                try { m.addArt(j); }
                catch (exception e) { add = false; }
            }
        }
        // add the wall to the list of possible walls
        if (add) {
            Wall tempWall = m.getWall();
            subsets.push_back(tempWall);
        }
        // clear the working object for a new subset
        m.clearWall();
    }
    return subsets;
<<<<<<< Updated upstream
}
=======
}

double Algorithm::mostExpensiveFirst(char *file) {
    // initialize the museum with the given file
//    m.readFile(file);

    m.clearWall();


    bool add = true;
    for(auto it = m.getSortedArt().begin(); it != m.getSortedArt().end(); it++) {
        try {m.addArt(it->pictureID); }
        catch(exception& e) {continue;}
    }
    return m.getWall().getCurrentPrice();


}
>>>>>>> Stashed changes
