/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Nicolas
 *
 * Created on 5 avril 2017, 00:26
 */

#include <stdio.h>
#include <stdlib.h>



typedef struct{
    int sizeMatrix;
    char** matrix;
    Coordinates* pos_start;
    Coordinates* pos_end;
    Path* solution;
} Problem;

//Model Chained list for Nodes
typedef struct {
    Coordinates coord;  //Coordinates of a the node
    Node* next;         //Next node's pointer
} Node;

typedef struct{
    int size;
    Node* Head;
    Node* Tail;
} Path;

/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

