//
// Created by Zachary on 1/24/2022.
// The wall on which the art will go.
//

#ifndef INC_22S_PA01_WALL_H
#define INC_22S_PA01_WALL_H

#include <iostream>
#include <map>
#include "Art.h"
#include "DSLinkedList.h"

using namespace std;

class Wall {
private:
    // dimensions of the wall
    int height, width;

    // current width of all paintings on the wall
    int currentWidth;

    // current price of all paintings on the wall
    double currentPrice;

    // vector of art pieces on the wall
    DSLinkedList<Art> pieces;
public:
    /**
     * Default Constructor
     */
    Wall();

    /**
     * Overloaded Constructor
     */
    Wall(int, int);

    /**
     * Add an art piece to the wall
     */
    void addArt(Art&);

    /**
     * Remove an art piece from the wall
     */
    void removeArt(Art&);

    /**
     * Get the width of the wall
     * @return int
     */
    int getWidth();

    /**
     * Set the width of the wall
     * @param w the width
     */
     void setWidth(int);

    /**
     * Get the height of the wall
     * @return int
     */
    int getHeight();

    /**
     * Set the width of the wall
     * @param h the width
     */
    void setHeight(int);

    /**
     * Get the current width of the art on the wall
     * @return int
     */
    int getCurrentWidth();

    /**
     * Get the current price of the art on the wall
     * @return double
     */
    double getCurrentPrice();

    /**
     * Overloaded output operator
     * @return
     */
    friend std::ostream& operator<<(std::ostream&, const Wall&);
};

#endif //INC_22S_PA01_WALL_H
