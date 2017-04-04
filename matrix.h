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
 **/

#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    
    void* matrix[][];
    int size_x, size_y; //!<
    
} Matrix;




#endif /* MATRIX_H */

