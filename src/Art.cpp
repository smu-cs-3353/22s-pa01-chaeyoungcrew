//
// Created by Zachary on 1/24/2022.
//

#include "Art.h"

Art::Art() {
    this->height = 1;
    this->width = 1;
    this->price = 1;
}

Art::Art(int ID, double price, int width, int height) {
    this->height = height;
    this->width = width;
    this->pictureID = ID;
    this->price = price;
}

int Art::getHeight() const { return this->height; }
int Art::getWidth() const { return this->width; }
int Art::getID() const { return this->pictureID; }
double Art::getPrice() const { return this->price; }

void Art::setHeight(int height) { this->height = height; }
void Art::setWidth(int width) { this->width = width; }
void Art::setID(int ID) { this->pictureID = ID; }
void Art::setPrice(double price) { this->price = price; }

bool Art::operator==(const Art& other) const {
    return this->height == other.getHeight() && this->width == other.getWidth() && this->price == other.getPrice();
}

bool Art::operator<(const Art& other) const {
    return this->height*this->width < other.getHeight()*other.getWidth();
}

bool Art::operator>(const Art& other) const {
    return this->height*this->width > other.getHeight()*other.getWidth();
}

std::ostream& operator<<(std::ostream& fout, const Art& art) {
    fout<< "id: " << art.pictureID << ", $" << art.price << ", " << art.width << "x" << art.height;
    return fout;
}
