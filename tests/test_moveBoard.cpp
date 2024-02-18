/*
 * Project: Tiny 2048 Game for Windows System
 * File: test_moveBoard.cpp
 * Author: uncle-lu <uncle-lu@zhili-edu.com>
 * Date: 2024
 *
 * Copyright (c) 2024, uncle-lu
 * All rights reserved.
 *
 * This source code is licensed under the MIT License found in the
 * LICENSE file in the root directory of this source tree. 
 *
 */
#include "../src/2048.h"
#include "../external/catch.hpp"
#include "../external/tools.hpp"

TEST_CASE("moveOnePoint UP", "[moveOnePoint]") {
    int baseBoard[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 2, 0, 1},
        {1, 0, 1, 0},
    };
    moveOnePoint(baseBoard, 2, 1, UP);
    REQUIRE(baseBoard[2][1] == 0);
    REQUIRE(baseBoard[1][1] == 2);
}

TEST_CASE("moveBoard UP", "[moveBoard]") {
    int baseBoard[4][4] = {
        {0, 3, 0, 7},
        {1, 0, 5, 0},
        {0, 4, 0, 8},
        {2, 0, 6, 0},
    };
    int targetBoard[4][4] = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    moveBoard(baseBoard, UP);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++) {
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
        }
}

TEST_CASE("moveBoard LEFT", "[moveBoard]") {
    int baseBoard[4][4] = {
        {0, 3, 0, 7},
        {1, 0, 5, 0},
        {0, 4, 0, 8},
        {2, 0, 6, 0},
    };
    int targetBoard[4][4] = {
        {3, 7, 0, 0},
        {1, 5, 0, 0},
        {4, 8, 0, 0},
        {2, 6, 0, 0},
    };
    moveBoard(baseBoard, LEFT);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++) {
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
        }
}

TEST_CASE("moveBoard DOWN", "[moveBoard]") {
    int baseBoard[4][4] = {
        {0, 3, 0, 7},
        {1, 0, 5, 0},
        {0, 4, 0, 8},
        {2, 0, 6, 0},
    };
    int targetBoard[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 3, 5, 7},
        {2, 4, 6, 8},

    };
    moveBoard(baseBoard, DOWN);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++) {
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
        }
}

TEST_CASE("moveBoard RIGHT", "[moveBoard]") {
    int baseBoard[4][4] = {
        {0, 3, 0, 7},
        {1, 0, 5, 0},
        {0, 4, 0, 8},
        {2, 0, 6, 0},
    };
    int targetBoard[4][4] = {
        {0, 0, 3, 7},
        {0, 0, 1, 5},
        {0, 0, 4, 8},
        {0, 0, 2, 6},
    };
    moveBoard(baseBoard, RIGHT);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++) {
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
        }
}