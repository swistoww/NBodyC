//
// Created by Wojtek on 2017-05-10.
//

#ifndef readData_h
#define readData_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globalVariables.h"

struct body *readData(char **filename, int nFiles);
int getDataFromFile(char *filename, int index);
int checkBodyAmount(char **filename, int nFiles);


#endif