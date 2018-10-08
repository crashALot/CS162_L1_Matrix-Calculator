/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/01/2018
** Description: This program takes user input and computes the 
*               mathematical determinant of a 2x2 or 3x3 matrix. An
*               associated header file contains the needed function
*               prototypes.
*********************************************************************/
#include "determinant.hpp"
#include <iostream>

/********************************************************************* 
** Description: int determinant(int** matrixArray, int matrixType)
*               This function calculates the determinant of a user 
*               defined matrix.
*********************************************************************/
int determinant(int** matrixArray, int matrixType)
{

// Work cited: https://www.mathsisfun.com/algebra/matrix-determinant.html
if (matrixType==2)
{
    return(matrixArray[0][0]*matrixArray[1][1]-matrixArray[0][1]*matrixArray[1][0]);
}
else
{
    int col0=matrixArray[0][0]*(matrixArray[1][1]*matrixArray[2][2]-matrixArray[1][2]*matrixArray[2][1]);
    int col1=matrixArray[0][1]*(matrixArray[1][0]*matrixArray[2][2]-matrixArray[1][2]*matrixArray[2][0]);
    int col2=matrixArray[0][2]*(matrixArray[1][0]*matrixArray[2][1]-matrixArray[1][1]*matrixArray[2][0]);
    return(col0-col1+col2);
}

    return 0;
}

