//
// Created by Wojtek on 2017-05-10.
//

#ifndef printData_h
#define printData_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readData.h"

void printData(struct body *dataBank,int size);
void printIterationToFile(char **fileNames, int size);
void createFiles(char *filePath, int size);
void createScript(char **fileNames, int size, char *filePath, double range, int iterations);

#endif