//
// Created by Zachary on 1/24/2022.
//

#include "Art.h"

Art::Art() {
    this->height = 1;
    this->width = 1;
    this->price = 1;
}

Art::Art(int height, int width, int ID, double price) {
    this->height = height;
    this->width = width;
    this->pictureID = ID;
    this->price = price;
}

int Art::getHeight() { return this->height; }
int Art::getWidth() { return this->width; }
int Art::getID() { return this->pictureID; }
int Art::getPrice() { return this->price; }

void Art::setHeight(int height) { this->height = height; }
void Art::setWidth(int width) { this->width = width; }
void Art::setID(int ID) { this->pictureID = ID; }
void Art::setPrice(int price) { this->price = price; }

bool Art::operator==(Art& other) {
    return this->height == other.getHeight() && this->width == other.getWidth() && this->price == other.getPrice();
}

bool Art::operator<(Art& other) {
    return this->height*this->width < other.getHeight()*other.getWidth();
}

bool Art::operator>(Art& other) {
    return this->height*this->width > other.getHeight()*other.getWidth();
}