//
// Created by Wojtek on 2017-05-10.
//

#include "readData.h"

struct body *readData(char **filename, int nFiles) {

    int size = checkBodyAmount(filename, nFiles), j, index = 0;

    dataBank = malloc(size * sizeof(struct body));

    for (j = 0; j < nFiles; j++){
        getDataFromFile(filename[j], index);
    }

    return  dataBank;
}

int checkBodyAmount(char **filename, int nFiles) {

    int i, amount = 0;

    for (i = 0; i < nFiles; i++) {
        FILE *fp = fopen(filename[i], "r");
        char *line = NULL;
        size_t len = 0;
        if (fp == NULL) {
            printf("Error opening file!\n");
            exit(1);
        } else {
            getline(&line, &len, fp);
            char *token = strtok(line, " =\r\n");
            if(strcmp(token, "----") == 0){
                amount++;
            }
        }

    }

    return amount;
}

int getDataFromFile(char *filename, int index){

        FILE *fp = fopen(filename, "r");
        char *line = NULL;
        size_t len = 0;
        getline(&line, &len, fp);
        char *token;// = strtok(line, " \r\n");
        while (getline(&line, &len, fp) != -1) {
            if (strlen(line) > 2) {
                token = strtok(line, " \r\n");
                if (strcmp(token, "------") == 0){
                    index++;
                    continue;
                }
            } else continue;
            if (strcmp(token, "Name:") == 0) {
                dataBank[index].name = strdup(strtok(NULL, " \r\n"));
            }else if (strcmp(token, "Mass:") == 0){
                dataBank[index].mass = atoi(strtok(NULL, " ,\r\n"));
            } else if (strcmp(token, "Position:") == 0) {
                dataBank[index].posX = atoi(strtok(NULL, " ,\r\n"));
                dataBank[index].posY = atoi(strtok(NULL, " ,\r\n"));
            } else if (strcmp(token, "Velocity:") == 0) {
                dataBank[index].velocityX = atoi(strtok(NULL, " ,\r\n"));
                dataBank[index].velocityY = atoi(strtok(NULL, " ,\r\n"));
            }
        }
    return index;

}