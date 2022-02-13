//
// Created by Daniel Ryan on 1/25/22.
//

#include "Museum.h"

void Museum::readFile(char *filename) {
    ifstream artFile;
    artFile.open(filename);

    if(!artFile.is_open())
        throw runtime_error("ERROR: Could not open art file");

    // read width and height from file
    int temp = 0;
    artFile >> temp;
    wall->setWidth(temp);
    artFile >> temp;
    wall->setHeight(temp);

    string buffer;

    artFile >> temp;
    int* info = new int[4];
    for(int i = 0; i < temp; i++) {

        // read attributes and store in an array
        artFile >> info[0];
        artFile >> info[1];
        artFile >> info[2];
        artFile >> info[3];

        // insert to temp art variable and add to lists of art pieces
        Art art(info[0], info[1], info[2], info[3]);
        artPieces.emplace_back(art, false);
        sortedArt.insert(art);
        sortedValue.insert(art);
    }

    delete[] info;
}

Wall &Museum::getWall() {
    return *wall;
}

vector<std::pair<Art, bool>> &Museum::getList() {
    return artPieces;
}

Art &Museum::getArt(int ID) {

    for(auto & artPiece : artPieces) {
        if(artPiece.first.getID() == ID)
            return artPiece.first;
    }
    throw out_of_range(to_string(ID) + " not found in list");
}

void Museum::addArt(int ID) {

    // sort through art list and find art based on id
    for(auto & artPiece : artPieces) {
        if (artPiece.first.getID() == ID) {
            wall->addArt(artPiece.first);
            return;
        }
    }
    throw out_of_range(to_string(ID) + " not found in list");
}

void Museum::addArtIndex(int i) {
    // add art to list if its in range
    if(i > artPieces.size() || i < 0)
        throw out_of_range(to_string(i) + " is out of range");

    wall->addArt(artPieces[i].first);
}

void Museum::clearWall() {
    wall->clearWall();
}

std::ostream &operator<<(ostream& fout, const Museum& museum) {
    fout << "WxH: " << museum.wall->getWidth() << "x" << museum.wall->getHeight() << ", current width: "
    << museum.wall->getCurrentWidth() << ", price: " << museum.wall->getCurrentPrice() << ", Art Pieces: ";
    for(auto& a : museum.artPieces) {
        fout << "(" << a.first << ": " << a.second << "), ";
    }

    return fout;
}

multiset<Art, std::function<bool(Art, Art)>> &Museum::getSortedArt() {
    return sortedArt;
}

std::multiset<Art, std::function<bool(Art, Art)>> &Museum::getSortedValue() {
    return sortedValue;
}




