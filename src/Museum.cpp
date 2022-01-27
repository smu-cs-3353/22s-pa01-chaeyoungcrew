//
// Created by Daniel Ryan on 1/25/22.
//

#include "Museum.h"

Museum::Museum() {
    wall = new Wall();
}

Museum::Museum(int w, int h) {
    wall = new Wall(w, h);
}

void Museum::readFile(char *filename) {
    ifstream artFile;
    artFile.open(filename);

    if(!artFile.is_open())
        throw runtime_error("ERROR: Could not open art file");

    char* buffer = new char[1024];
    int temp = 0;
    artFile >> temp;
    wall->setWidth(temp);
    artFile >> temp;
    wall->setHeight(temp);
    std::cout << wall->getWidth() << ", " << wall->getHeight() << std::endl;

    artFile >> temp;
    int numArt = temp;
    for(int i = 0; i < numArt; i++) {
        artFile >> temp;
        int ID = temp;
        artFile >> temp;
        int price = temp;
        artFile >> temp;
        int width = temp;
        artFile >> temp;
        int height = temp;
        Art art(height, width, ID, price);
        artPieces.emplace_back(art, false);
    }
}

Wall &Museum::getWall() {
    return *wall;
}

