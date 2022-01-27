//
// Created by Zachary on 1/24/2022.
// The art that will go on the wall.
//

#ifndef INC_22S_PA01_ART_H
#define INC_22S_PA01_ART_H

#include <iostream>

class Art {
private:
    // Dimensions
    int height, width;

    //ID
    int pictureID;

    // Value
    int price;
public:
    /**
     * Default Constructor
     */
    Art();

    /**
     * Overloaded Constructor
     */
    Art(int, int, int, int);

    /**
     * Get the height of the art
     * @return int
     */
    int getHeight();

    /**
     * Get the width of the art
     * @return int
     */
     int getWidth();

     /**
      * Get the picture ID of the art
      * @return
      */
     int getID();

     /**
      * Get the price of the art
      * @return int
      */
     int getPrice();

     /**
      * Set the height of the art
      */
      void setHeight(int);

      /**
       * Set the width of the art
       */
      void setWidth(int);

      /**
       * Set the picture ID of the art
       */
      void setID(int);

      /**
       * Set the price of the art
       */
      void setPrice(int);

      /**
       * Comparators
       */
       bool operator==(Art&);
       bool operator<(Art&);
       bool operator>(Art&);

       /**
        * Overloaded output operator
        * @return
        */
       friend std::ostream &operator<<(std::ostream&, const Art&);
};

#endif //INC_22S_PA01_ART_H
