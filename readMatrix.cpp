/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/01/2018
** Description: This program is used to validate and input int values
*               into a 2D dynamic array. An associated header file 
*               contains the needed prototype functions.
*********************************************************************/
#include "readMatrix.hpp"
#include <iostream>
#include <string>
#include <cmath> // Used for pow function

/********************************************************************* 
** Description: void readMatrix(int** arrayPtr, int matrixType)
*               This function reads user input and saves int values 
*               into a dynamic 2D array. Additional input validation
*               is completed prior to saving any data.
*********************************************************************/
void readMatrix(int** arrayPtr, int matrixType)
{
    int totalElements=matrixType*matrixType, length=0, signal=0;
    std::string arrayInput;
    std::cout << "Please enter " << totalElements << " integers: "  << std::endl;
    // Nested for-loops iterate through entire 2D array
    for (int row=0; row<matrixType; row++)
    {
        for (int col=0; col<matrixType; col++)
        {
            // Input validation loop
            while (1) // Input validation loop will repeat until sentinel variable changes
            {
                int runTotal=0, negStatus=1;
                getline(std::cin, arrayInput); // Convert user input to string, and evaluate individual elements
                length=arrayInput.length();
                if (arrayInput[0]=='-' && length>1) // If user inputs negative number, shorten string length by 1 and evaluate
                {
                    length=length-1;
                    for (int i=0; i<length; i++)
                    {
                        arrayInput[i]=arrayInput[i+1];
                    }
                    negStatus=-1; // Sentinel variable used to reestablish negative value of integer
                }
                for (int i=0; i<length; i++)
                {
                    if (!(isdigit(arrayInput[i])) || ispunct(arrayInput[i]) || isspace(arrayInput[i]))
                    {
                        std::cout << "Please re-enter the integer value (without spaces, commas, or periods): " << std::endl;
                        signal=0;
                        break; // Mutes repeated iteration through string after encountering first non-legal input
                    }
                    else
                    {
                        // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-cs
                        runTotal+=pow(10,length-1-i)*(arrayInput[i]-'0'); // Converts char back to int
                        if ((i+1)==length)
                        {
                            arrayPtr[row][col]=runTotal*negStatus; // Stores computed int as positive or negative as needed
                            signal=1;
                        }
                    }
                }
            if (signal==1) // When a value is stored into the array, exit out of while-loop
            break;
            }
        }
    }
}