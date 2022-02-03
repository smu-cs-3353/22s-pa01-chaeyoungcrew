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
    // the current wall
    Wall* wall;

    // the list of available art pieces
    vector<std::pair<Art, bool>> artPieces;

public:
    /**
     * Default Constructor
     */
    Museum();

    /**
     * Overloaded Constructor
     * @param w the width of the wall
     * @param h the height of the wall
     */
    Museum(int, int);

    /**
     * Populate the list of art pieces given an input file
     * @param filename the name of the input file
     */
    void readFile(char* filename);

    /**
     * Get the wall
     * @return Wall
     */
    Wall& getWall();

    /**
     * Get the list of art pieces
     * @return vector<std::pair<Art, bool>>
     */
    vector<std::pair<Art, bool>>& getList();

    /**
     * Get a specific art piece
     * @param ID the id of the art piece
     * @return Art
     */
    Art& getArt(int);

    /**
     * Add an art piece to the wall
     * @param ID the id of the art piece
     */
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
     * @return std::ostream
     */
    friend std::ostream &operator<<(std::ostream&, const Museum&);

};


#endif //INC_22S_PA01_MUSEUM_H
