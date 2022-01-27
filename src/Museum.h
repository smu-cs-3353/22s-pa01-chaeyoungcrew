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

};


#endif //INC_22S_PA01_MUSEUM_H
