//
// Created by Zachary on 1/24/2022.
//

#ifndef INC_22S_PA01_ART_H
#define INC_22S_PA01_ART_H

class Art {
private:
    // Dimensions
    int height, width;

    // Value
    double price;
public:
    /**
     * Default Constructor
     */
    Art();

    /**
     * Overloaded Constructor
     */
    Art(int, int, double);

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
      * Get the price of the art
      * @return double
      */
     double getPrice();

     /**
      * Set the height of the art
      */
      void setHeight(int);

      /**
       * Set the width of the art
       */
      void setWidth(int);

      /**
       * Set the price of the art
       */
      void setPrice(double);
};

#endif //INC_22S_PA01_ART_H
