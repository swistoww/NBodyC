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

        force[0] = G * dataBank[i].mass * dataBank[index].mass / pow(distanceNorm,2) * distance[0]/distanceNorm;
        force[1] = G * dataBank[i].mass * dataBank[index].mass / pow(distanceNorm,2) * distance[1]/distanceNorm;
        force[2] = G * dataBank[i].mass * dataBank[index].mass / pow(distanceNorm,2) * distance[2]/distanceNorm;
    }
    acceleration[0] = force[0] / dataBank[index].mass;
    acceleration[1] = force[1] / dataBank[index].mass;
    acceleration[2] = force[2] / dataBank[index].mass;

    dataBank[index].velocityX += acceleration[0] * timeDiff;
    dataBank[index].velocityY += acceleration[1] * timeDiff;
    dataBank[index].velocityZ += acceleration[2] * timeDiff;

    dataBank[index].posX += dataBank[index].velocityX * timeDiff;
    dataBank[index].posY += dataBank[index].velocityY * timeDiff;
    dataBank[index].posZ += dataBank[index].velocityZ * timeDiff;
}

void calculateAllPositions(int size, long timeDiff){
    int i;
    for (i=0; i < size; i++){
        calculateNewPosition(i, timeDiff, size);
    }
}

void nBodySimulation(long timeDiff, long duration, char *outputPath){
    long actualTimeSec = 0;
    int iteration = 0;
    while (actualTimeSec < duration){
        if (actualTimeSec==0){
            printIterationToFile(outputPath, size, iteration);
        }
        calculateAllPositions(size, timeDiff);
        iteration++;
        printIterationToFile(outputPath, size, iteration);

        actualTimeSec += timeDiff;
    }
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