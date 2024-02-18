/*
 * Project: Tiny 2048 Game for Windows System
 * File: test_mergeBoard.cpp
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

TEST_CASE("mergeOnePoint UP", "[mergeOnePoint]") {
    int baseBoard[4][4] = {
        {0, 0, 0, 6},
        {1, 2, 3, 0},
        {0, 2, 0, 5},
        {2, 0, 4, 0},
    };
    mergeOnePoint(baseBoard, 2, 1, UP);
    INFO(arrayToString(baseBoard));
    REQUIRE(baseBoard[2][1] == 0);
    REQUIRE(baseBoard[1][1] == 4);
}

TEST_CASE("mergeBoard UP 1", "[mergeBoard]") {
    int baseBoard[4][4] = {
        {2, 2, 16, 16},
        {2, 2, 16, 16},
        {4, 4, 8, 8},
        {4, 4, 8, 8},
    };
    int targetBoard[4][4] = {
        {4, 4, 32, 32},
        {0, 0, 0, 0},
        {8, 8, 16, 16},
        {0, 0, 0, 0},
    };
    mergeBoard(baseBoard, UP);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++) 
        for(int j=0; j<4; j++)
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
}

TEST_CASE("mergeBoard UP 2", "[mergeBoard]") {
    int baseBoard[4][4] = {
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2},
    };
    int targetBoard[4][4] = {
        {4, 4, 4, 4},
        {0, 0, 0, 0},
        {4, 4, 4, 4},
        {0, 0, 0, 0},
    };
    mergeBoard(baseBoard, UP);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++) 
        for(int j=0; j<4; j++)
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
}

TEST_CASE("mergeBoard UP 3", "[mergeBoard]") {
    int baseBoard[4][4] = {
        {2, 2, 2, 2},
        {2, 1, 1, 2},
        {2, 1, 1, 2},
        {2, 2, 2, 2},
    };
    int targetBoard[4][4] = {
        {4, 2, 2, 4},
        {0, 2, 2, 0},
        {4, 0, 0, 4},
        {0, 2, 2, 0},
    };
    mergeBoard(baseBoard, UP);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++) 
        for(int j=0; j<4; j++)
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
}

TEST_CASE("mergeBoard LEFT 1", "[mergeBoard]") {
    int baseBoard[4][4] = {
        {2, 2, 16, 16},
        {2, 2, 16, 16},
        {4, 4, 8, 8},
        {4, 4, 8, 8},
    };
    int targetBoard[4][4] = {
        {4, 0, 32, 0},
        {4, 0, 32, 0},
        {8, 0, 16, 0},
        {8, 0, 16, 0},
    };
    mergeBoard(baseBoard, LEFT);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++) 
        for(int j=0; j<4; j++)
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
}

TEST_CASE("mergeBoard LEFT 2", "[mergeBoard]") {
    int baseBoard[4][4] = {
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2},
    };
    int targetBoard[4][4] = {
        {4, 0, 4, 0},
        {4, 0, 4, 0},
        {4, 0, 4, 0},
        {4, 0, 4, 0},
    };
    mergeBoard(baseBoard, LEFT);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++) 
        for(int j=0; j<4; j++)
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
}

TEST_CASE("mergeBoard LEFT 3", "[mergeBoard]") {
    int baseBoard[4][4] = {
        {4, 2, 2, 4},
        {4, 2, 2, 4},
        {4, 2, 2, 4},
        {4, 2, 2, 4},
    };
    int targetBoard[4][4] = {
        {4, 4, 0, 4},
        {4, 4, 0, 4},
        {4, 4, 0, 4},
        {4, 4, 0, 4},
    };
    mergeBoard(baseBoard, LEFT);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++) 
        for(int j=0; j<4; j++)
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
}

TEST_CASE("mergeBoard DOWN 1", "[mergeBoard]") {
    int baseBoard[4][4] = {
        {4, 2, 2, 4},
        {4, 2, 2, 4},
        {4, 2, 2, 4},
        {4, 2, 2, 4},
    };
    int targetBoard[4][4] = {
        {0, 0, 0, 0},
        {8, 4, 4, 8},
        {0, 0, 0, 0},
        {8, 4, 4, 8},
    };
    mergeBoard(baseBoard, DOWN);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++) 
        for(int j=0; j<4; j++)
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
}

TEST_CASE("mergeBoard DOWN 2", "[mergeBoard]") {
    int baseBoard[4][4] = {
        {4, 4, 4, 4},
        {4, 2, 2, 4},
        {4, 2, 2, 4},
        {4, 4, 4, 4},
    };
    int targetBoard[4][4] = {
        {0, 4, 4, 0},
        {8, 0, 0, 8},
        {0, 4, 4, 0},
        {8, 4, 4, 8},
    };
    mergeBoard(baseBoard, DOWN);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++) 
        for(int j=0; j<4; j++)
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
}

TEST_CASE("mergeBoard RIGHT 1", "[mergeBoard]") {
    int baseBoard[4][4] = {
        {4, 4, 4, 4},
        {4, 2, 2, 4},
        {4, 2, 2, 4},
        {4, 4, 4, 4},
    };
    int targetBoard[4][4] = {
        {0, 8, 0, 8},
        {4, 0, 4, 4},
        {4, 0, 4, 4},
        {0, 8, 0, 8},
    };
    mergeBoard(baseBoard, RIGHT);
    INFO(arrayToString(baseBoard));
    for(int i=0; i<4; i++) 
        for(int j=0; j<4; j++)
            REQUIRE(baseBoard[i][j] == targetBoard[i][j]);
}