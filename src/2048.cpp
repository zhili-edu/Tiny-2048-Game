/*
 * Project: Tiny 2048 Game for Windows System
 * File: 2048.cpp
 * Author: uncle-lu <uncle-lu@zhili-edu.com>
 * Date: 2024
 *
 * Copyright (c) 2024, uncle-lu
 * All rights reserved.
 *
 * This source code is licensed under the MIT License found in the
 * LICENSE file in the root directory of this source tree. 
 *
 * Description: Main core logic code.
 */
#include<windows.h>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#define INIT_COUNT 1
#define ADD_COUNT 1

enum Direction {
	UP=0, LEFT, DOWN, RIGHT
};

int x_turn[4] = {-1, 0, 1, 0};
int y_turn[4] = {0, -1, 0, 1};
int Score = 0;

void clearScreen() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void initBoard(int board[4][4]) { //初始化矩阵 
	int x, y;
	for(int i=1; i<=INIT_COUNT; i++) {
		do {
			x = rand() % 4;
			y = rand() % 4;
		}while(board[x][y]);
		board[x][y] = 2;
	}
	return ;
}

bool addOnePoint(int board[4][4]) {
	int cnt = 0;
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			if(board[i][j])
				cnt++;
	if(cnt == 4*4)
		return false;
	int x, y;
	for(int i=1; i<=ADD_COUNT; i++) {
		do {
			x = rand() % 4;
			y = rand() % 4;
		}while(board[x][y]);
		board[x][y] = 2;
	}
	return true;
}

void printBoard(int board[4][4]) {
	clearScreen();
	printf("     2048 Game!\n");
	for(int i=0; i<9; i++) {
		if(i%2) {
			printf("*");
			for(int j=0; j<4; j++) {
				if(board[i/2][j] == 0)
					printf("    ");
				else if(board[i/2][j] < 10)
					printf("  %d ", board[i/2][j]);
				else if(board[i/2][j] < 100)
					printf(" %d ", board[i/2][j]);
				else if(board[i/2][j] < 1000)
					printf(" %d", board[i/2][j]);
				else
					printf("%d", board[i/2][j]);
				printf("*");
			}
			printf("\n");
		}
		else {
			printf("*");
			for(int j=0; j<4; j++)
				printf("*****");
			printf("\n");
		}
	}
	printf("Use the arrow keys on the keyboard to navigate.\n");
	printf("Score: %d\n", Score);
	return ;
}

bool checkPointInBoard(int x, int y) {
	if(x >= 0 && x <= 3 && y >= 0 && y <= 3)
		return true;
	else
		return false;
}

void moveOnePoint(int board[4][4], int x, int y, Direction type) {
	while(checkPointInBoard(x, y) && checkPointInBoard(x + x_turn[type], y + y_turn[type]) && board[x][y] && !board[x + x_turn[type]][y + y_turn[type]]) {
		board[x + x_turn[type]][y + y_turn[type]] = board[x][y];
		board[x][y] = 0;
		x = x + x_turn[type]; y = y + y_turn[type];
	}
	return ;
}

void moveBoard(int board[4][4], Direction type) {
	switch (type) {
		case UP: 
			for(int j=0; j<4; j++)
				for(int i=1; i<4; i++)
					moveOnePoint(board, i, j, type);
			break;
		case LEFT:
			for(int i=0; i<4; i++)
				for(int j=1; j<4; j++)
					moveOnePoint(board, i, j, type);
			break;
		case DOWN:
			for(int j=0; j<4; j++)
				for(int i=2; i>=0; i--)
					moveOnePoint(board, i, j, type);
			break;
		case RIGHT:
			for(int i=0; i<4; i++)
				for(int j=2; j>=0; j--)
					moveOnePoint(board, i, j, type);
			break;
	}
	return ;
}

void mergeOnePoint(int board[4][4], int x, int y, Direction type) {
	if(board[x][y] && board[x][y] == board[x + x_turn[type]][y + y_turn[type]]) {
		Score += board[x][y];
		board[x + x_turn[type]][y + y_turn[type]] += board[x][y];
		board[x][y] = 0;
	}
	return ;
}

void mergeBoard(int board[4][4], Direction type) {
	switch (type) {
		case UP: 
			for(int j=0; j<4; j++)
				for(int i=1; i<4; i++)
					mergeOnePoint(board, i, j, type);
			break;
		case LEFT:
			for(int i=0; i<4; i++)
				for(int j=1; j<4; j++)
					mergeOnePoint(board, i, j, type);
			break;
		case DOWN:
			for(int j=0; j<4; j++)
				for(int i=2; i>=0; i--)
					mergeOnePoint(board, i, j, type);
			break;
		case RIGHT:
			for(int i=0; i<4; i++)
				for(int j=2; j>=0; j--)
					mergeOnePoint(board, i, j, type);
			break;
	}
	return ;
}

bool updateBoard(int board[4][4], Direction type) {
	moveBoard(board, type);
	mergeBoard(board, type);
	moveBoard(board, type);
	if(rand()%3) {
		return addOnePoint(board);
	}	
	return true;
}