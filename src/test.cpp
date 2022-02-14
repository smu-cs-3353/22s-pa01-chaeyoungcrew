//
// Created by Zachary on 1/23/2022.
//

#include "catch.hpp"

// INCLUDE CLASSES HERE
#include "Art.h"
#include "Wall.h"
#include "Museum.h"

/**
 * Create a new test case for every new class.
 */
TEST_CASE("Art Test", "[Art]") {
    SECTION("Art Constructors") {
        Art def;
        Art over(0,5,10,10);
    }
}