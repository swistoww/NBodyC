//
// Created by Wojtek on 2017-05-10.
//

#include "printData.h"

void printData(struct body *dataBank, int size){
    int i;
    printf("DANE: \n\n");
    for (i=0; i < size; i++){
        printf("Ciało: %s \n", dataBank[i].name);
        printf("Masa: %li\n", dataBank[i].mass);
        printf("Polozenie: %d, %d\n", dataBank[i].posX, dataBank[i].posY);
        printf("Predkosc: %d, %d\n\n", dataBank[i].velocityX, dataBank[i].velocityY);
    }
}