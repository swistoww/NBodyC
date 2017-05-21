
//
// Created by Wojtek on 2017-05-21.
//

#ifndef NBODY_VALIDATEDATA_H
#define NBODY_VALIDATEDATA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "globalVariables.h"

void checkNumericArgument(char *argument);
void checkForMissingData ();
int missingData(char *data, char* body, int counter);
void checkFileNumber(int fileNumber, int numberOfArguments);

#endif //NBODY_VALIDATEDATA_H
