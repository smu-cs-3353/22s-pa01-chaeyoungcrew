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
    int currentPrice;

    // linked list of art pieces on the wall
    DSLinkedList<Art> pieces;
public:
    /**
     * Default Constructor
     */
    Wall();

    /**
     * Overloaded Constructor
     * @param height the height of the wall
     * @param width the width of the wall
     */
    Wall(int, int);

    /**
     * Add an art piece to the wall
     * @param art the art piece to be added
     */
    void addArt(Art&);

    /**
     * Remove an art piece from the wall
     * @param art the art piece to be removed
     */
    void removeArt(Art&);

    /**
     * Get the width of the wall
     * @return int
     */
    int getWidth() const;

    /**
     * Set the width of the wall
     * @param w the width
     */
     void setWidth(int);

    /**
     * Get the height of the wall
     * @return int
     */
    int getHeight() const;

    /**
     * Set the height of the wall
     * @param h the height
     */
    void setHeight(int);

    /**
     * Get the current width of the art on the wall
     * @return int
     */
    int getCurrentWidth() const;

    /**
     * Set the current width of the art on the wall
     * @param w the width
     */
    void setCurrentWidth(int);

    /**
     * Get the current price of the art on the wall
     * @return double
     */
    int getCurrentPrice() const;

    /**
     * Set the current price of the art on the wall
     * @param p the price
     */
    void setCurrentPrice(double);

    /**
     * Overloaded output operator
     * @return std::ostream
     */
    friend std::ostream& operator<<(std::ostream&, const Wall&);
};

#endif //INC_22S_PA01_WALL_H
