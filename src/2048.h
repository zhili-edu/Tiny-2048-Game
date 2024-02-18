/*
 * Project: Tiny 2048 Game for Windows System
 * File: 2048.h
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
#ifndef SRC2048_H
#define SRC2048_H

enum Direction {
	UP=0, LEFT, DOWN, RIGHT
};

void clearScreen();
void initBoard(int board[4][4]);
bool addOnePoint(int board[4][4]);
void printBoard(int board[4][4]);
bool checkPointInBoard(int x, int y);
void moveOnePoint(int board[4][4], int x, int y, Direction type);
void moveBoard(int board[4][4], Direction type);
void mergeOnePoint(int board[4][4], int x, int y, Direction type);
void mergeBoard(int board[4][4], Direction type);
bool updateBoard(int board[4][4], Direction type);

#endif