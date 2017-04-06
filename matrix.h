/**
 * @project : NONOFuzion
 * @license : Available on License.md
 * @file : matrix.h
 * @brief :
 *      Define matrix model, fillers and wrappers.
 *  
 * @date : 4 avril 2017, 23:16
 * @version : 
 * 
 * @author : J4BB3R
 * @contributor :
 * 
 * @description :
 *      This file implements matrix structures, who embedded functions to fill it get data from it, or deleting process.
 *      You can, for example, fill the matrix from an printable file. That what we would use for ours usages.
 * 
 **/

#include <stdio.h>
#include "tools.h"

#ifndef MATRIX_H
#define MATRIX_H

    //!< Error Codes for "fillMatrixWithPath()" >!//
    #define FILE_NOT_SQUARE -1 //!< If the file do not contain as many lines as columns( char ) >!//
    #define FILE_ITS_NOT_CONVERTIBLE -5 //!< Don't have same number of char per lines >!//
    #define FILE_NON_REACHABLE -2
    #define FILE_PATH_IS_NULL -3
    #define FILE_CONTAIN_NON_PRINTABLE -4

    //!< Separator config flag for "printMatrix()" >!//
    #define SPACE_SEPARATOR 1 //!< 0 1 >!//
    #define BRACKET_SEPARATOR 3 //!< [0][1] >!//
    #define PARENTHESE_SEPARATOR 7 //!< (0)(1) >!//
    #define MARKUP_SEPARATOR 15 //!< <0><1> >!//
    #define SEPARATOR_OFFSET 15 //!< Use to isolate separator config with an binary AND >!//
    #define SPACE_BTW_SEPARATORS 16 //!< [0] [1] >!//
    #define SPACE_BTW_SEPARATOR_AND_DATA 32 //!< [ 0 ][ 1 ] >!//

    typedef struct {

        char** matrix; //!< It's the array who store matrix data >!>//
        unsigned int size_x, size_y; //!< Represent width and height of the matrix >!//
        Bool printable;

    } Matrix;

    /**
     * 
     * @param matrix it's the matrix
     * @param coord it's the coordinate to point a case to look on.
     * @param possiblesValues this array contains all the possibles values, uses to compare. 
     * @return boolean: true if the coordinates contain one of the possibles values.
     * @troubles if a value is missing or wrong false is return.      
     */
    Bool isPossible(Matrix matrix, Coordinates coord, char* possiblesValues);

    /**
     * 
     * @param matrix it's the matrix
     * @param fullPath contain the read to inject into the matrix
     * @param onlyPrintable define if the function verify or not if the values are printable.
     * @return error code or 0 if theres nothing wrong.
     */
    int fillMatrixWithPath(Matrix matrix, char* fullPath, Bool onlyPrintable);
    
    /**
     * 
     * @param matrix
     * @param separatorCfgFlag
     */
    void printMatrix(Matrix matrix, int separatorCfgFlag);

#endif /* MATRIX_H */

