//
// Created by Zachary on 1/24/2022.
//

#include "Art.h"

Art::Art() {
    this->height = 1;
    this->width = 1;
    this->price = 1;
}

Art::Art(int height, int width, double price) {
    this->height = height;
    this->width = width;
    this->price = price;
}

int Art::getHeight() { return this->height; }
int Art::getWidth() { return this->width; }
double Art::getPrice() { return this->price; }

void Art::setHeight(int height) { this->height = height; }
void Art::setWidth(int width) { this->width = width; }
void Art::setPrice(double price) { this->price = price; }