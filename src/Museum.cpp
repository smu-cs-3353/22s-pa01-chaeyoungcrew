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

    int temp = 0;
    artFile >> temp;
    wall->setWidth(temp);
    artFile >> temp;
    wall->setHeight(temp);

    string buffer;

    artFile >> temp;
    int* info = new int[4];
    for(int i = 0; i < temp; i++) {
        artFile >> info[0];
        artFile >> info[1];
        artFile >> info[2];
        artFile >> info[3];

        Art art(info[0], info[1], info[2], info[3]);
        artPieces.emplace_back(art, false);
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
    for(int i = 0; i < artPieces.size(); i++) {
        if(artPieces[i].first.getID() == ID)
            return artPieces[i].first;
    }
    throw out_of_range(to_string(ID) + " not found in list");
}

void Museum::addArt(int ID) {
    for(int i = 0; i < artPieces.size(); i++) {
        if (artPieces[i].first.getID() == ID) {
            wall->addArt(artPieces[i].first);
            return;
        }
    }
    throw out_of_range(to_string(ID) + " not found in list");
}

void Museum::addArtIndex(int i) {
    if(i > artPieces.size() || i < 0)
        throw out_of_range(to_string(i) + " is out of range");

    wall->addArt(artPieces[i].first);
}

void Museum::clearWall() {
    wall->setCurrentWidth(0);
    wall->setCurrentPrice(0.0);
}

std::ostream &operator<<(ostream& fout, const Museum& museum) {
    fout << "WxH: " << museum.wall->getWidth() << "x" << museum.wall->getHeight() << ", current width: "
    << museum.wall->getCurrentWidth() << ", price: " << museum.wall->getCurrentPrice() << ", Art Pieces: ";
    for(auto& a : museum.artPieces) {
        fout << "(" << a.first << ": " << a.second << "), ";
    }

    return fout;
}


