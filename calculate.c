//
// Created by Wojtek on 2017-05-17.
//

#include "calculate.h"

void calculateNewPosition(int index, long timeDiff, int size){
    int i;
    double distance[3], force[3] = {0,0,0}, acceleration[3] = {0,0,0}, distanceNorm;
    for (i = 0; i < size; i++){
        if (i == index){
            continue;
        }
        distance[0] = dataBank[i].posX - dataBank[index].posX;
        distance[1] = dataBank[i].posY - dataBank[index].posY;
        distance[2] = dataBank[i].posZ - dataBank[index].posZ;

        distanceNorm = sqrt(pow(distance[0],2) + pow(distance[1],2) + pow(distance[2],2));

        force[0] = (G * dataBank[i].mass * dataBank[index].mass / pow(distanceNorm,2)) * distance[0]/distanceNorm;
        force[1] = (G * dataBank[i].mass * dataBank[index].mass / pow(distanceNorm,2)) * distance[1]/distanceNorm;
        force[2] = (G * dataBank[i].mass * dataBank[index].mass / pow(distanceNorm,2)) * distance[2]/distanceNorm;
    }
    acceleration[0] -= force[0] / dataBank[index].mass;
    acceleration[1] -= force[1] / dataBank[index].mass;
    acceleration[2] -= force[2] / dataBank[index].mass;

    dataBank[index].velocityX += acceleration[0] * timeDiff;
    dataBank[index].velocityY += acceleration[1] * timeDiff;
    dataBank[index].velocityZ += acceleration[2] * timeDiff;

    dataBank[index].posX += dataBank[index].velocityX * timeDiff;
    if (fabs(dataBank[index].posX) > range)
        range = fabs(dataBank[index].posX);
    dataBank[index].posY += dataBank[index].velocityY * timeDiff;
    if (fabs(dataBank[index].posY) > range)
        range = fabs(dataBank[index].posY);
    dataBank[index].posZ += dataBank[index].velocityZ * timeDiff;
    if (fabs(dataBank[index].posZ) > range)
        range = fabs(dataBank[index].posZ);
}

void calculateAllPositions(int size, long timeDiff){
    adaptPositions();

    int i;
    for (i=0; i < size; i++){
        calculateNewPosition(i, timeDiff, size);
    }

    /*double followed[3] = {dataBank[0].posX, dataBank[0].posY, dataBank[0].posZ};
    int j;
    for (j = 0; j < size; ++j) {
        dataBank[j].posX = dataBank[j].posX - followed[0];
        dataBank[j].posY = dataBank[j].posY - followed[1];
        dataBank[j].posZ = dataBank[j].posZ - followed[2];
    }*/
    adaptPositions();
}

void nBodySimulation(long timeDiff, long duration, char *outputPath){
    long actualTimeSec = 0;
    //int iteration = 0;

    createFiles(outputPath, size);
    printIterationToFile(fileNames, size);
    while (actualTimeSec < duration){
        calculateAllPositions(size, timeDiff);
        //iteration++;
        printIterationToFile(fileNames, size);

        actualTimeSec += timeDiff;
    }
    range = 1.1 * range;
}


long calculateTime(long value, char unit){
    long time;
    switch (unit){
        case 115: //sekundy
            time = value;
            break;
        case 109: //minuty
            time = value *60;
            break;
        case 104: //godziny
            time = value *60*60;
            break;
        case 100: //dni
            time = value *60*60*24;
            break;
        case 119: //tygodnie
            time = value *60*60*24*7;
            break;
        case 121: //lata
            time = value *60*60*24*365;
            break;
        default: //ma wyrzucic blad o przeczytaniu manuala bo zadna literka nie pasuje
            printf("Zadna ze znanych mi jednostek czasu nie pasuje do podanej! Przeczytaj proszę manuala!");
            exit(1);
    }

    return time;
}

void adaptPositions(){
    if (followedBody != -1){
        double followed[3] = {dataBank[followedBody].posX, dataBank[followedBody].posY, dataBank[followedBody].posZ};

        int j;
        for (j = 0; j < size; ++j) {
            dataBank[j].posX = dataBank[j].posX - followed[0];
            dataBank[j].posY = dataBank[j].posY - followed[1];
            dataBank[j].posZ = dataBank[j].posZ - followed[2];
        }
    }

}