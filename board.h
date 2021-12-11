#pragma once
#include "includes.h"
extern char grid[50][50];
extern std::string directionArray[100];

void FillPlayArea(short cells, short heroRow, short heroCol, short princessRow, short princessCol) {
	for (int row = 0; row <= cells; row++) {
		for (short col = 0; col <= cells; col++) {
			grid[row][col] = '-';			
		}
	}
	grid[heroRow][heroCol] = 'M';
	grid[princessRow][princessCol] = 'P';
}

void PrintPlayArea(short cells) {
	short arrayPointer = 0;
	for (int row = 0; row <= cells; row++) {
		for (short col = 0; col <= cells; col++) {
			printf("%c", grid[row][col]);
		}
		arrayPointer = row - 2;
		if (row == 0)
			printf(" MoveList%c", NULL);
		else if (row == 1)
			printf(" ========%c", NULL);
		else if (directionArray[arrayPointer] != "")
			std::cout << " " + directionArray[arrayPointer];
		printf("\n%c",NULL);
	}	

	if (directionArray[arrayPointer + 1] != "") {
		arrayPointer++;
		while (directionArray[arrayPointer] != "") {
			std::cout << directionArray[arrayPointer];
			arrayPointer++;
		}
	}
	// If the list of directions is longer than there are spots on the
	// game board, continue printing under the game board.
}