#pragma once
#include "includes.h"
extern std::string directionArray[100];

void CompleteDirections(short yAxis, short xAxis) {
	std::string direction;
	short numToFill;
	short directionArrayPointer = 0;

	if (yAxis > 0) direction = "DOWN";
	else direction = "UP";
	numToFill = abs(yAxis);
	for (short fillArrayY = 1; fillArrayY <= numToFill; fillArrayY++) {
		directionArray[directionArrayPointer] = direction;
		directionArrayPointer++;
	}

	if (xAxis > 0) direction = "RIGHT";
	else direction = "LEFT";
	numToFill = abs(xAxis);
	for (short fillArrayX = 1; fillArrayX <= numToFill; fillArrayX++) {
		directionArray[directionArrayPointer] = direction;
		directionArrayPointer++;
	}

}