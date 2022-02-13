//
// Created by Daniel Ryan on 1/25/22.
//

#include "Algorithm.h"

Algorithm::Algorithm(char* file) {
    m.readFile(file);
    fileName = file;
}

double Algorithm::bruteForce(int size) {
    m.clearWall();

    // vector of all subsets found through brute force
    vector<Wall> subsets = bfGetSubsets(size);

    // loop through list of subsets and find the one with the maximum value
    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i < subsets.size(); i++) {
        if (subsets.at(i).getCurrentPrice() > max) {
            max = subsets.at(i).getCurrentPrice();
            maxIndex = i;
        }
    }

    if (subsets.size() > 0)
        outputFiles(subsets.at(maxIndex), max, 'b');
    return max;
}

vector<Wall> Algorithm::bfGetSubsets(int size) {
    // trackers for the loops
    if (size == -1)
        size = m.getList().size();
    else if (size > m.getList().size())
        size = m.getList().size();
    int big = pow(2, size);

    // create all possible subsets
    vector<Wall> subsets;

    // terminates if size is too large and im not patient enough to wait
    if(size > 13)
        return subsets;

    for (int i = 0; i < big; i++) {
        // boolean variable to handle for invalid subsets
        bool add = true;
        for (int j = 0; j < size; j++) {
            //for my ref: this operation is used to iterate through every permutation of the different art pieces
            //using binary and bits
            if ((i & (1 << j)) != 0) {
                // handle for if the art cannot be added, if it can't, this is an invalid subset so throw it away
                try { m.addArtIndex(j); }
                catch (exception &e) { add = false; }
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
}

double Algorithm::mostExpensiveFirst() {
    m.clearWall();

    // add the sorted to the wall until the wall runs out of space
    for(auto it = m.getSortedArt().begin(); it != m.getSortedArt().end(); it++) {
        try {m.addArt(it->pictureID); }
        catch(exception& e) {continue;}
    }

    // creates and writes to the output file
    outputFiles(m.getWall(), m.getWall().getCurrentPrice(), 'e');

    return m.getWall().getCurrentPrice();

}

double Algorithm::heuristicAlgo() {
    m.clearWall();

    // add the sorted to the wall until the wall runs out of space
    for(auto it = m.getSortedValue().begin(); it != m.getSortedValue().end(); it++) {
        try {m.addArt(it->pictureID); }
        catch(exception& e) {continue;}
    }

    // creates and writes to the output file
    outputFiles(m.getWall(), m.getWall().getCurrentPrice(), 'h');

    return m.getWall().getCurrentPrice();
}

void Algorithm::outputFiles(const Wall& wall, int price, char algo) {
    string ofileName;
    switch(algo) {
        // creates output file name in format "inputfile-algoType.txt"
        case 'b':
            ofileName = fileName.substr(0, fileName.size()-4) + "-bruteforce.txt";
            break;
        case 'e':
            ofileName = fileName.substr(0, fileName.size()-4) + "-highvalue.txt";
            break;
        case 'h':
            ofileName = fileName.substr(0, fileName.size()-4) + "-custom.txt";
            break;
        default:
            break;
    }

    // writes price and list of art onto the file
    ofstream of(ofileName.c_str());
    if(of.is_open()) {
        of << price << std::endl;
        of << wall << std::endl;
    }

    of.close();
}
