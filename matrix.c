/**
 * @project : NONOFuzion
 * @license : Available on License.md
 * @file : matrix.c
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
 */

#include "matrix.h"
#include "Movement.h"

/**
 * 
 * @param matrix it's the matrix
 * @param coord it's the coordinate to point a case to look on.
 * @param possiblesValues this array contains all the possibles values, uses to compare. 
 * @return boolean: true if the coordinates contain one of the possibles values.
 * @troubles if a value is missing or wrong false is return.      
 */
Bool isPossible(Matrix matrix, Coordinates coord, char* possiblesValues){
    
    int size = strlen();
    for(int i = 0; i < size; i++){
        if(matrix.matrix[coord.y][coord.x] == possiblesValues[i]) return True;   
    }return False;
    
}

/**
 * 
 * @param matrix it's the matrix
 * @param fullPath contain the read to inject into the matrix
 * @param onlyPrintable define if the function verify or not if the values are printable.
 * @return error code or 0 if theres nothing wrong.
 */
int fillMatrixWithPath(Matrix* matrix, char* fullPath, Bool onlyPrintable){
    
    FILE* file;
    
    if(fullPath == NULL) return FILE_PATH_IS_NULL; //!< Verify integrity of data >!// 
    file = fopen(fullPath,"r"); //!< Get data from file >!// 
    if(file == NULL) return FILE_NON_REACHABLE; //!< NULL if the system have some troubles to get data from the path you've given >!//
    
    char* line;
    unsigned int count_x = 0, count_y, width = 0;
    
    for(count_y = 0 ; fscanf(file, "%s", line) > 0; count_y++){
        if(count_y == 0) width = strlen(line);
        else if(width != strlen(line)) return FILE_ITS_NOT_CONVERTIBLE;
    }

    if( count_y != width) return FILE_NOT_SQUARE;
    else {
        matrix->size_x = width;
        matrix->size_y = count_y;
    }

    rewind(file);  
        
    if(onlyPrintable == True) {
        
        matrix->printable = True;
        
        for(int y = 0 ; fscanf(file, "%s", line) > 0; y++){
            for(int x = 0; x < strlen(line); x++){
                char buff = line[x];
                if(buff >= MIN_PRINTABLE_ASCII && buff <= MAX_PRINTABLE_ASCII){
                    matrix->matrix[y][x] = buff;
                } else return FILE_CONTAIN_NON_PRINTABLE;
            }
        }       
        
    } else {
        
        matrix->printable = False;
        
        for(int y = 0 ; fscanf(file, "%s", line) > 0; y++){
            for(int x = 0; x < strlen(line); x++){
                matrix->matrix[y][x] = line[x];
            }
        }          
        
    }
        
}

/**
 * 
 * @param matrix
 * @param separatorCfgFlag
 */
void printMatrix(Matrix matrix, int separatorCfgFlag){
    
    if (matrix->printable == True){
        
        char betweenSeps, betweenSepAndData;
        char beforeData, afterData;

        separatorCfgFlag & SPACE_BTW_SEPARATORS == SPACE_BTW_SEPARATORS ? betweenSeps = ' ': betweenSeps = '';
        separatorCfgFlag & SPACE_BTW_SEPARATOR_AND_DATA == SPACE_BTW_SEPARATOR_AND_DATA ? betweenSepAndData = ' ': betweenSepAndData = '';

        switch(separatorCfgFlag & SEPARATOR_OFFSET){
            case SPACE_SEPARATOR :
                beforeData = ' ';
                afterData = ' ';
                break;
            case BRACKET_SEPARATOR :
                beforeData = '[';
                afterData = ']';            
                break;
            case PARENTHESE_SEPARATOR :
                beforeData = '(';
                afterData = ')';            
                break;
            case MARKUP_SEPARATOR :
                beforeData = '<';
                afterData = '>';            
                break;
            default :
                beforeData = '';
                afterData = '';            
                break;
        };

        printf("\n");
        for(int y = 0; y < matrix.size_y; y++){
            for(int x = 0; x < matrix.size_x; x++){
                if(x == 0) printf("%c%c%c%c%c", beforeData, betweenSepAndData, matrix.matrix[y][x], betweenSepAndData, afterData);
                else printf("%c%c%c%c%c%c", betweenSeps, beforeData, betweenSepAndData, matrix.matrix[y][x], betweenSepAndData, afterData);
            }
            printf("\n");
        }
                
    } else printf("\nThe matrix cannot be displayed, it contain non-printable values...\n");
    
}

