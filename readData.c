//
// Created by Wojtek on 2017-05-10.
//

#include "readData.h"
//#include "globalVariables.h"

struct body *readData(char **filename, int nFiles) {

    size = checkBodyAmount(filename, nFiles);
    if (size < 2){
        printf("Mam zbyt malo danych. %d to zbyt malo zeby dalo sie przeprowadzic symulacje.", size);
        exit(1);
    }
    int j, index = 0;

    dataBank = malloc(size * sizeof(struct body));

    for (j = 0; j < nFiles; j++){
        index = getDataFromFile(filename[j], index);
    }

    return  dataBank;
}

int checkBodyAmount(char **filename, int nFiles) {

    int i, amount = 0;

    for (i = 0; i < nFiles; i++) {
        FILE *fp = fopen(filename[i], "r");
        if(fp == NULL){
            char ans[3];
            printf("Nie moge otworzyc pliku %s.\n", filename[i]);
            printf("Czy mimo to kontynuowac? (Tak/Nie)");
            scanf("%s", ans);
            if (strcmp(ans, "Nie") == 0){
                printf("W takim razie konczymy!");
                exit(1);
            } else {
                continue;
            }
        }
        char *line = NULL;
        size_t len = 0;
        char *token;
        while (getline(&line, &len, fp) != -1){
            token = strtok(line, " :\r\n");
            if(strcmp(token, "Nazwa") == 0){
                amount++;
            }
        }

    }

    return amount;
}

int getDataFromFile(char *filename, int index){

    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        return index;
    }
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
            }else if (strcmp(token, "Nazwa:") == 0) {
                dataBank[index].name = strdup(strtok(NULL, " \r\n"));
                //index++;
            }else if (strcmp(token, "Masa:") == 0){
                dataBank[index].mass = atof(strtok(NULL, " ,\r\n"));
            } else if (strcmp(token, "Pozycja:") == 0) {
                dataBank[index].posX = atof(strtok(NULL, " ,\r\n"));
                dataBank[index].posY = atof(strtok(NULL, " ,\r\n"));
                dataBank[index].posZ = atof(strtok(NULL, " ,\r\n"));
            } else if (strcmp(token, "Predkosc:") == 0) {
                dataBank[index].velocityX = atof(strtok(NULL, " ,\r\n"));
                dataBank[index].velocityY = atof(strtok(NULL, " ,\r\n"));
                dataBank[index].velocityZ = atof(strtok(NULL, " ,\r\n"));
            }
        }

    }

    return index;
}