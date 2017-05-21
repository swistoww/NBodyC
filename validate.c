//
// Created by Wojtek on 2017-05-21.
//

#include <ctype.h>
#include "validate.h"


void checkNumericArgument(char *argument){
    for (int n = 0; n < sizeof(argument)/ sizeof(char); n++){
        if (!isdigit(argument[n])){
            printf("'%s' nie jest liczba. Sprawdz jak wywolywac program", argument);
            exit(1);
        }
    }
}

void checkFileNumber(int fileNumber, int numberOfArguments){
    if (fileNumber < 1){
        printf("Minimalna liczba plikow wejsciowych to 1.");
        exit(1);
    } else if (fileNumber+5 > numberOfArguments){
        printf("Podana liczba plikow wejsciowych jest wieksza niz ilosc nazw.");
        exit(1);
    }
}

void checkForMissingData () {

    int i, counter = 0;
    char bodyName [20];
    for (i = 0; i < size; i++){
        if (dataBank[i].name == NULL) {
            strcpy(bodyName, "Cialo");
            sprintf(bodyName, "%d", i);
        } else {
            strcpy(bodyName, dataBank[i].name);
        }
        if (dataBank[i].mass == NULL)
            counter = missingData("masa", bodyName, counter);
        if (dataBank[i].velocityX == NULL)
            counter = missingData("predkosc X", bodyName, counter);
        if (dataBank[i].velocityY == NULL)
            counter = missingData("predkosc Y", bodyName, counter);
        if (dataBank[i].velocityZ == NULL)
            counter = missingData("predkosc Z", bodyName, counter);
        if (dataBank[i].posX == NULL)
            counter = missingData("polozenie X", bodyName, counter);
        if (dataBank[i].posY == NULL)
            counter = missingData("polozenie Y", bodyName, counter);
        if (dataBank[i].posZ == NULL)
            counter = missingData("polozenie Z", bodyName, counter);
    }
}

int missingData(char *data, char *body, int counter){
    printf("Brakuje danej %s dla %s", data, body);
    counter++;
    return counter;
}