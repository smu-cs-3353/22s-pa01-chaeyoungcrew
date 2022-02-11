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
#include <set>


class Museum {
private:
    // the current wall
    Wall* wall;

    // the list of available art pieces
    vector<std::pair<Art, bool>> artPieces;

    // the list of art pieces sorted by price and value
    std::multiset<Art, std::function<bool(Art, Art)>> sortedArt;
    std::multiset<Art, std::function<bool (Art, Art)>> sortedValue;


public:
    /**
     * Default Constructor
     */
    Museum() : sortedValue ([](Art lhs, Art rhs){return lhs.getValue() > rhs.getValue();})
             , sortedArt ([](Art lhs, Art rhs){return lhs.getPrice() > rhs.getPrice();})
    {
        wall = new Wall();
    }


    /**
     * Overloaded Constructor
     * @param w the width of the wall
     * @param h the height of the wall
     */
    Museum(int w, int h) : sortedValue([](Art lhs, Art rhs){return lhs.getValue() < rhs.getValue();})
                         , sortedArt ([](Art lhs, Art rhs){return lhs.getPrice() > rhs.getPrice();})
    {
        wall = new Wall(w, h);
    }

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
     * returns the list of art sorted by price from greatest to least
     * @return
     */
    std::multiset<Art, std::function<bool (Art, Art)>>& getSortedArt();

    /**
     * returns the lst of art sorted by value per unit of width
     * from greatest of least
     * @return
     */
     std::multiset<Art, std::function<bool (Art, Art)>>& getSortedValue();


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
