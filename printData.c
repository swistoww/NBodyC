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
        printf("Polozenie: %f, %f\n", dataBank[i].posX, dataBank[i].posY, dataBank[i].posZ);
        printf("Predkosc: %f, %f\n\n", dataBank[i].velocityX, dataBank[i].velocityY, dataBank[i].velocityZ);
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

    printf("Pliki z wynikami zostaly stworzone w lokalizacji:\n %s", filePath);
}

void printIterationToFile(char **fileNames, int size){
    int i;
    FILE *fp;
    for (i = 0; i < size; i++){
        fp = fopen(fileNames[i], "a");
        fprintf(fp, "\t%f\t%f\t%f\r\n", dataBank[i].posY, dataBank[i].posX, dataBank[i].posZ);
    }
}

void createScript(char **fileNames, int size, char *filePath, double range, int iterations){
    int i;
    FILE *fp;
    char scriptFile[100];
    strcpy(scriptFile, filePath);
    strcat(scriptFile, "gnuplotSkrypt.plt");
    fp = fopen(scriptFile, "w");
    fprintf(fp, "set xrange [-%f:%f]\n", range, range);
    fprintf(fp, "set yrange [-%f:%f]\n", range, range);
    fprintf(fp, "set zrange [-%f:%f]\n", range, range);
    fprintf(fp, "do for [ii=1:%d] {\n", iterations);
    fprintf(fp, "splot \t\"%s\" every ::ii::ii pt 7 ps 1 title \"%s\", \\\n", fileNames[0], dataBank[0].name);

    for (i = 1; i < size-1; ++i) {
        fprintf(fp, "\t\"%s\" every ::ii::ii pt 7 ps 1 title \"%s\", \\\n", fileNames[i], dataBank[i].name);
    }
    fprintf(fp, "\t\"%s\" every ::ii::ii pt 7 ps 1 title \"%s\"\n", fileNames[i], dataBank[i].name);
    fprintf(fp, "pause 0.01\n}");

}