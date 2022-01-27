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
    std::cout << wall->getWidth() << ", " << wall->getHeight() << std::endl;

    artFile >> temp;
    int* info = new int[4];
    for(int i = 0; i < temp; i++) {
        artFile >> info[0];
        artFile >> info[1];
        artFile >> info[2];
        artFile >> info[3];

        Art art(info[0], info[1], info[2], info[3]);
        artPieces.emplace_back(art, false);
        std::cout << "id: " << art.getID() << std::endl;
        std::cout << "price: " << art.getPrice() << std::endl;
        std::cout << "width: " << art.getWidth() << std::endl;
        std::cout << "height: " << art.getHeight() << std::endl << std::endl;
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
    throw out_of_range("ID not found in list");
}

std::ostream &operator<<(ostream& fout, const Museum& museum) {
    fout << "WxH: " << museum.wall->getWidth() << "x" << museum.wall->getHeight() << ", current width: "
    << museum.wall->getCurrentWidth() << ", price: " << museum.wall->getCurrentPrice() << ", Art Pieces: ";
    for(auto& a : museum.artPieces) {
        fout << "(" << a.first << ": " << a.second << "), ";
    }

    return fout;
}


