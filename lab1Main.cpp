/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/01/2018
** Description: This program asks the users to choose the size of a
*               matrix (2x2 or 3x3). Dynamically allocates the memory 
*               space for the matrix using readMatrix() to prompt the 
*               user to enter 4 or 9 integers to fill the matrix.
*               Calculates the determinant using determinant(). Displays
*               both the matrix and the determinant to the user and frees
*               the dynamically allocated memory.
*********************************************************************/
#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>
#include <string>

int main()
{
    int matrixType=0, length=0, go=1;
    std::string stringInput="";
    // https://www.youtube.com/watch?v=0BX5heUj0FI
    int** matrixArray;
    std::cout << "Please choose the size of the matrix (2x2 or 3x3) using a single integer (eg. 2 or 3): " << std::endl;

    // Work cited: https://stackoverflow.com/questions/2075898/good-input-validation-loop-using-cin-c
    //             http://www.cplusplus.com/reference/string/string/getline/
    // Input validation for initial matrix size
    while (go)
    {
        getline(std::cin, stringInput);
        length=stringInput.length();
        if ((stringInput[0]!='2' && stringInput[0]!='3') || length>1)
        {
            std::cout << "Please re-enter the size of the matrix using an integer value of 2 or 3 (without spaces): " << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            matrixType=(int)stringInput[0]-'0'; // Converts char to int via ASCII code math
            go=0; // Signal variable exits while loop
        }
    }
    
    matrixArray= new int* [matrixType]; // Allocate dynamic array
    
    // Allocate new dynamic array for each row of the original dynamic array
    for (int row=0; row<matrixType; row++)
        matrixArray[row]= new int[matrixType];
    
    // Fill up array with int values
    readMatrix(matrixArray, matrixType);

    // Call and output solved determinant 
    std::cout << "Determinant is: " << determinant(matrixArray, matrixType) << std::endl;
    
    // Output filled matrix to consol
    for (int row=0; row<matrixType; row++)
    {
        for (int col=0; col<matrixType; col++)
        {
            std::cout << matrixArray[row][col] << " " ;
        }
        std::cout << std::endl;
    }
    
    // Work cited: https://www.tutorialcup.com/cplusplus/dynamic-memory.htm
    // Deallocate dynamic arrays 
    for (int row=0; row<matrixType; row++) // Start with the columns of dynamic arrays
        delete [] matrixArray[row];
        
    delete [] matrixArray; // Finally delete base dyanmic array
    matrixArray=NULL; // Set pointer to NULL
    
	return 0;
}
