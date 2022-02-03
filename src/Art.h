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


    // Value
public:
    int price;
    int pictureID;
    /**
     * Default Constructor
     */
    Art();

    /**
     * Overloaded Constructor
     *
     * @param ID the id of the art piece
     * @param price the price of the art piece
     * @param width the width of the art piece
     * @param height the height of the art piece
     */
    Art(int, double, int, int);

    /**
     * Get the height of the art piece
     * @return int
     */
    int getHeight() const;

    /**
     * Get the width of the art piece
     * @return int
     */
     int getWidth() const;

     /**
      * Get the picture ID of the art piece
      * @return int
      */
     int getID() const;

     /**
      * Get the price of the art piece
      * @return double
      */
     double getPrice() const;

     /**
      * Set the height of the art piece
      * @param height the height of the art piece
      */
      void setHeight(int);

      /**
       * Set the width of the art piece
       * @param width the width of the art piece
       */
      void setWidth(int);

      /**
       * Set the picture ID of the art piece
       * @param ID the id of the art piece
       */
      void setID(int);

      /**
       * Set the price of the art piece
       * @param price the price of the art piece
       */
      void setPrice(double);

      /**
       * Comparators
       */
       bool operator==(const Art&) const;
       bool operator<(const Art&) const;
       bool operator>(const Art&) const;

       /**
        * Overloaded output operator
        * @return std::ostream
        */
       friend std::ostream &operator<<(std::ostream&, const Art&);
};

#endif //INC_22S_PA01_ART_H
