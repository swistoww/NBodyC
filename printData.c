//
// Created by Wojtek on 2017-05-10.
//

#include "printData.h"

void printData(struct body *dataBank, int size){
    int i;
    printf("Dane Wejściowe: \n\n");
    for (i=0; i < size; i++){
        printf("Ciało: %s \n", dataBank[i].name);
        printf("Masa: %f\n", dataBank[i].mass);
        printf("Polozenie: %f, %f\n", dataBank[i].posX, dataBank[i].posY);
        printf("Predkosc: %f, %f\n\n", dataBank[i].velocityX, dataBank[i].velocityY);
    }
}

void createFiles(char *filePath, int size){

    int i,j;
    FILE *fp;
    fileNames = malloc(size * sizeof(char*));
    for (j = 0; j < size; ++j) {
        fileNames[j] = malloc(100 * sizeof(char));
    }

    for (i = 0; i < size; i++){
        strcpy(fileNames[i], filePath);
        strcat(fileNames[i], dataBank[i].name);
        strcat(fileNames[i], ".txt");
        fp = fopen(fileNames[i], "w");
        fprintf(fp, "#\tX\tY\tZ\r\n");
    }
}

void printIterationToFile(char **fileNames, int size){
    int i;
    FILE *fp;
    for (i = 0; i < size; i++){
        fp = fopen(fileNames[i], "a");
        fprintf(fp, "\t%f\t%f\t%f\r\n", dataBank[i].posY, dataBank[i].posX, dataBank[i].posZ);
    }
}

/*void printIterationToFile(char *filePath, int size, int iteration){
    int i;
    FILE *fp;
    char fileName[100];
    strcpy(fileName, filePath);
    strcat(fileName, "wynik");
    sprintf(fileName, "%s%d", fileName, iteration);
    strcat(fileName, ".txt");

    fp = fopen(fileName, "w");
    fprintf(fp, "#\tX\tY\tZ\r\n");
    for (i=0; i<size; i++){
        fprintf(fp, "\t%f\t%f\t%f\r\n", dataBank[i].posY, dataBank[i].posX, dataBank[i].posZ);
        fprintf(fp, "\r\n");
    }
}

void createScript(){

}*/