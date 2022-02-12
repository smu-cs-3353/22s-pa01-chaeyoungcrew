//
// Created by Zachary on 1/24/2022.
//

#include "Wall.h"

Wall::Wall() {
    this->height = 1;
    this->width = 1;
    this->currentWidth = 0;
    this->currentPrice = 0;
}

Wall::Wall(int height, int width) {
    this->height = height;
    this->width = width;
    this->currentWidth = 0;
    this->currentPrice = 0;
}

void Wall::addArt(Art& art) {
    // error handling
    if (currentWidth + art.getWidth() > width)
        throw out_of_range("Art exceeds the width of the wall");

    // add the art piece to the unordered map and change the status variables
    pieces.push_back(art);
    currentWidth += art.getWidth();
    currentPrice += art.getPrice();
}

void Wall::removeArt(Art& art) {
    // error handling
    if (!pieces.contains(art))
        throw out_of_range("Art does not exist");

    // remove the art piece from the unordered map and change the status variables
    pieces.remove(art);
    currentWidth -= art.getWidth();
    currentPrice -= art.getPrice();
}

int Wall::getWidth() const { return this->width; }
void Wall::setWidth(int w) { this->width = w; }
int Wall::getHeight() const { return this->height; }
void Wall::setHeight(int h) { this->height = h; }
int Wall::getCurrentWidth() const { return this->currentWidth; }
void Wall::setCurrentWidth(int w) { this->currentWidth = w; }
int Wall::getCurrentPrice() const { return this->currentPrice; }
void Wall::setCurrentPrice(double p) { this->currentPrice = p; }

std::ostream &operator<<(ostream& fout, const Wall& wall) {
    fout << "WxH: " << wall.width << "x" << wall.height << ", current width: " << wall.currentWidth <<
        ", price: " << wall.currentPrice << ", pieces: " << wall.pieces;
    return fout;
}
