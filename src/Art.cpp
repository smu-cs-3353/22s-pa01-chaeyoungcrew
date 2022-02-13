//
// Created by Zachary on 1/24/2022.
//

#include "Art.h"
#include <iomanip>

Art::Art() {
    this->height = 1;
    this->width = 1;
    this->price = 1;
}

Art::Art(int ID, int price, int width, int height) {
    this->height = height;
    this->width = width;
    this->pictureID = ID;
    this->price = price;
    this->value = ((double)price)/width;
}

int Art::getHeight() const { return this->height; }
int Art::getWidth() const { return this->width; }
int Art::getID() const { return this->pictureID; }
int Art::getPrice() const { return this->price; }

void Art::setHeight(int h) { this->height = h; }
void Art::setWidth(int w) { this->width = w; }
void Art::setID(int ID) { this->pictureID = ID; }
void Art::setPrice(int p) { this->price = p; }

bool Art::operator==(const Art& other) const {
    return this->height == other.getHeight() && this->width == other.getWidth() && this->price == other.getPrice();
}

bool Art::operator<(const Art& other) const {
    return this->height*this->width < other.getHeight()*other.getWidth();
}

bool Art::operator>(const Art& other) const {
    return this->height*this->width > other.getHeight()*other.getWidth();
}

double Art::getValue() const {
    return value;
}

std::ostream& operator<<(std::ostream& fout, const Art& art) {
    fout<< art.pictureID << " " << art.price << " " << art.width << " " << art.height;
    return fout;
}

