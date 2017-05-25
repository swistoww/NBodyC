//
// Created by Wojtek on 2017-05-10.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readData.h"
#include "printData.h"
#include "calculate.h"
#include "validate.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
//#include <unistd.h>
#include <ctype.h>

int main(int argc, char **argv) {
    /*char *tmpString;
    if (argc < 6){
        printf("Zbyt malo argumentow wywolania. Sprawdz dokladnie w jaki sposob uruchamiac program");
        exit(1);
    }*/
    //checkNumericArgument(argv[1]);
    //checkNumericArgument(argv[2]);
    //checkNumericArgument(argv[4]);
    followedBody = -1;
    char **filename, *outputPath;
    int i, iterations = atoi(argv[1]);
    long timeDiff = atoi(argv[2]), timeDiffSec, timeEndSec;
    char timeUnit = *argv[3];
    int nFiles = atoi(argv[4]);
    //checkFileNumber(nFiles, argc);
    filename = malloc(nFiles*sizeof(char*));
    for (i=0; i < nFiles; i++){
        filename[i] = strdup(argv[i+5]);
    }

    if (argv[i+5] == NULL){
        char cwd[1024];
        outputPath = getcwd(cwd, sizeof(cwd));
        strcat(outputPath, "/results/");
    } else {
        outputPath = argv[i+5];
        struct stat st = {0};

        if (stat(outputPath, &st) == -1) {
            mkdir(outputPath, 0700);
        }
    }

    dataBank = readData(filename, nFiles);
   // checkForMissingData;
    printData(dataBank,size);
    timeDiffSec = calculateTime(timeDiff, timeUnit);
    timeEndSec = iterations * timeDiffSec;
    nBodySimulation(timeDiffSec, timeEndSec, outputPath);
    createScript(fileNames, size, outputPath, range, iterations);

    free(dataBank);
    free(fileNames);

    return(0);
}