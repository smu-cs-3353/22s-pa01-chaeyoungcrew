//
// Created by Daniel Ryan on 1/25/22.
//

#ifndef INC_22S_PA01_MUSEUM_H
#define INC_22S_PA01_MUSEUM_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Wall.h"
#include "Art.h"
#include <map>
#include <exception>


class Museum {
private:
    Wall* wall;
    vector<std::pair<Art, bool>> artPieces;

public:
    Museum();
    Museum(int, int);

    void readFile(char* filename);
    Wall& getWall();
    vector<std::pair<Art, bool>>& getList();
    Art& getArt(int);
    void addArt(int);

    /**
     * Add an art piece to the wall using it's index in the vector
     * @param i the index in the vector
     */
    void addArtIndex(int);

    /**
     * Clear the wall of all art pieces
     */
    void clearWall();

    /**
     * Overloaded output stream operator
     * @return
     */
    friend std::ostream &operator<<(std::ostream&, const Museum&);

};


#endif //INC_22S_PA01_MUSEUM_H
