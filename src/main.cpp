/*
 * Project: Tiny 2048 Game for Windows System
 * File: main.cpp
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
#include<windows.h>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include "2048.h"

int main() {
	int board[4][4] = {0};
	srand(time(0));
	initBoard(board);
	
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prev_mode;
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
	
	printBoard(board);
	
	while(1) {
		INPUT_RECORD record;
        DWORD read;
        ReadConsoleInput(hInput, &record, 1, &read);
        if (record.EventType == KEY_EVENT && record.Event.KeyEvent.bKeyDown) {
        	bool flag;
        	switch (record.Event.KeyEvent.wVirtualKeyCode) {
                case VK_UP:
                    flag = updateBoard(board, UP);
                    break;
                case VK_DOWN:
                    flag = updateBoard(board, DOWN);
                    break;
                case VK_LEFT:
                    flag = updateBoard(board, LEFT);
                    break;
                case VK_RIGHT:
                    flag = updateBoard(board, RIGHT);
                    break;
                case VK_ESCAPE:
                    SetConsoleMode(hInput, prev_mode); // 恢复控制台模式
                    return 0;
            }
            printBoard(board);
            if(!flag){
            	printf("GAME OVER!");
            	return 0;
			}
        }
	}
	return 0;
}