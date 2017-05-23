//
// Created by Wojtek on 2017-05-18.
//

#ifndef NBODY_GLOBALVARIABLES_H
#define NBODY_GLOBALVARIABLES_H

struct body {
    char *name;
    double mass;
    double posX;
    double posY;
    double posZ;
    double velocityX;
    double velocityY;
    double velocityZ;
};

struct body *dataBank;

int size;

char **fileNames;

#endif //NBODY_GLOBALVARIABLES_H
