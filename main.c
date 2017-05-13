//
// Created by Wojtek on 2017-05-10.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readData.h"
//#include "forward.h"
#include "printData.h"
/*#include "backward.h"
#include "checkData.h"*/

int main(int argc, char **argv) {
    char **filename;
    //struct body *dataBank;
    int i, j;
    int nFiles = atoi(argv[1]);
    filename = malloc(nFiles*sizeof(char*));
    for (i=0; i < nFiles; i++){
        filename[i] = strdup(argv[i+2]);
    }

        dataBank = readData(filename, nFiles);
        printData(dataBank,2);

    return(0);
}