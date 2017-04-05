/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Movement.h
 * Author: Nicolas
 *
 * Created on 5 avril 2017, 00:41
 */

#ifndef MOVEMENT_H
#define MOVEMENT_H
#define TRUE_DISTANCE 0
#define RELATIVE_DISTANCE 1

//Struct used to save coordinates(x,y)
typedef struct{
    int x;      //x coordinate
    int y;      //y coordinate
} Coordinates;

//Struct for array to know size to minimize creation of array with un-assigned
typedef struct{
    int size;               //Size of the array pointed by possibilities
    Coordinates* possibilities;    //Array's pointer of possible moves
}Possibilities;

void setCoord(int x, int y, Coordinates* pos);

Possibilities* movement(Problem state, Coordinates pos);

float true_Distance(Coordinates PointA, Coordinates PointB);

int relative_Distance(Coordinates PointA, Coordinates PointB);

void sort(Possibilities* moves, Coordinates pos_end, int flag);

int victoryCheck(Coordinates PointA, Coordinates PointB);

Possibilities* movementOpti(Problem state, Coordinates pos, int flag);


#endif /* MOVEMENT_H */

