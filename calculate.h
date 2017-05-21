//
// Created by Wojtek on 2017-05-17.
//

#ifndef calculate_h
#define calculate_h

#define G 6.67408e-11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "globalVariables.h"
#include "printData.h"

void calculateNewPosition(int index, long timeDiff, int size);
void calculateAllPositions(int size, long timeDiff);
void nBodySimulation(long timeDiff, long duration, char *outputPath);
long calculateTime(long value, char unit);

#endif