/**
 * @project : NONOFuzion
 * @license : Available on License.md
 * @file : Movement.c
 * @brief :
 *      Define matrix model, fillers and wrappers.
 *  
 * @date : 4 avril 2017, 23:16
 * @version : 
 * 
 * @author : Neoghost
 * @contributor :
 * 
 * @description :
 *      Nono's movement function
 *      Calculation of distance for optimization
 *      Check Victory
 **/

#include "Movement.h"
#include <stdio.h>
#include <math.h>

/**
 * @param x to set
 * @param y to set
 * @param pos coordinates to set
 */
void setCoord(int x, int y, Coordinates* pos){
    pos->x = x;
    pos->y = y;
}

/**
 * Movement possible for nono
 * @param state contains the matrix where nono is
 * @param pos position of nono
 * @return array possible moves of nono from pos
 */
Possibilities* movement(Problem state, Coordinates pos){
    
    Possibilities moves;
    Coordinates position[4];
    
    moves.size=0;                      //Init of moves's array size
    moves.possibilities = position;    //Pointer of array
    
    if(pos.x-1>=0){       //Move left
        setCoord(pos.x-1,pos.y,position[moves.size]);
        moves.size++;      //One more possibilities
    }
    if(pos.x+1<state.sizeMatrix){
        setCoord(pos.x+1,pos.y,position[moves.size]);
        moves.size++;      //One more possibilities
    }
    if(pos.y-1>=0){
        setCoord(pos.x,pos.y-1,position[moves.size]);
        moves.size++;      //One more possibilities
    }
    if(pos.y+1<state.sizeMatrix){
        setCoord(pos.x,pos.y+1,position[moves.size]);
        moves.size++;      //One more possibilities
    }
    return &moves;
}
/**
 * Calculation of distance between 2 coordinates
 * @param PointA
 * @param PointB
 * @return distance between A and B
 */
float true_Distance(Coordinates PointA, Coordinates PointB){
    float distance;     //Creation of the value we will return
    distance = pow((PointB.x - PointA.x),2)+pow((PointB.y-PointA.y),2);   //Calculation of the hypotenuse between the 2 points
    distance = sqrt(distance);                                          //Continuation
    return distance;    
}

/**
 * Calculation of distance between 2 coordinates
 * @param PointA
 * @param PointB
 * @return distance between A and B
 */
int relative_Distance(Coordinates PointA, Coordinates PointB){
    int distance;                                                   //Creation of the value we will return
    distance = fabs(PointB.x-PointA.x)+fabs(PointB.y-PointA.y);     //Calculation of the minimal moves between 2 points without obstable
    return distance;
}

/**
 * Sort the possibilities by distance with a position (pos_end)
 * The closer position to pos_end is the first of the array, The further is the last
 * @param moves Array of nono's possibilities
 * @param pos_end , Compare the distance between possibilities and this point : it's the comparator
 * @param flag determine if we use True (0) or Relative (1) Distance 
 */
void sort(Possibilities* moves, Coordinates pos_end, int flag){
    int taille = moves->size;
    Coordinates solution[moves->size];
    
    switch(flag){
        case TRUE_DISTANCE:                 //Comparison with true distance (hypotenuse)
            for(int i=0 ; i< moves->size ; i++){
                solution[i]= moves->possibilities[i];
                
                //Compare each solution with the current possibilities
                for(int j=0; j<i ; j++){
                        
                //If the solution[j] is closer to the end
                    if(true_Distance(solution[j],pos_end) > true_Distance(moves->possibilities[i],pos_end)){

                        for(int k=i ; k>j ; k--){
                            //Shift right the array from the longer distance
                            solution[k]=solution[k-1];
                        }   
                        solution[j]= moves->possibilities[i];   //Put the possibilities to its position
                        j=i;
                    }
                }
            }
            break;
            
        case RELATIVE_DISTANCE:             //Comparison with Relative distance
            for(int i=0 ; i< moves->size ; i++){
                solution[i]= moves->possibilities[i];
                
                //Compare each solution with the current possibilities
                for(int j=0; j<i ; j++){
                        
                //If the solution[j] is closer to the end
                    if(relative_Distance(solution[j],pos_end) > relative_Distance(moves->possibilities[i],pos_end)){

                        for(int k=i ; k>j ; k--){
                            //Shift right the array from the longer distance
                            solution[k]=solution[k-1];
                        }   
                        solution[j]= moves->possibilities[i];   //Put the possibilities to its position
                        j=i;
                    }
                }
            }
            break;
            
        default:
            break;
    }
    for(int i=0 ; i<moves->size; i++){
        moves->possibilities[i]=solution[i];    //Set solution in moves(struct Possibilities)
    }
}

/**
 * Check the victory "event"
 * @param PointA
 * @param PointB
 * @return 1 if victory, 0 if not
 */
int victoryCheck(Coordinates PointA, Coordinates PointB){
    if(PointA.x == PointB.x && PointA.y == PointB.y){
        return 1;   //Victory
    }
    else{
        return 0;   //TryAgain
    }
}


Possibilities* movementOpti(Problem state, Coordinates pos, int flag){
    Possibilities* moves = movement(state,pos);
    sort(moves,flag);
    return moves;
}