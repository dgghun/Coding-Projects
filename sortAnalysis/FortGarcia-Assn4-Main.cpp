//**********************************************************************************************
//  FILENAME:   FortGarcia-Assn4-Main.cpp
//  PROGRAM
//  DESCRIPTION:This program demonstrates 4 different sorting algorithms: bubble sort, insertion
//              sort, merge sort and quick sort. The program starts off by getting input from
//              the user on which two types of sorts to do and how many times to run them. An
//              array of 100,000 integers is then created to be sorted by the algorithms the user
//              has selected. After each sort type is run the program displays the amount of time
//              it took to run each sort type. The program will continue to go through this process
//              until the user selects to exit the program.
//  DESIGNERS:  MICAHEL FORT
//              DAVID GARCIA
//*********************************************************************************************
#include <iostream>
#include "FortGarcia-Assn4-Common.h"
#include "Fort-Assn4-Funcs.h"
#include "Garcia-Assn4-Funcs.h"

using namespace std;


//***********************************************************************************************
// FUNCTION:    main()
// DESCRIP:     Calls functions that get user input and perform sorts on array of integers. Keeps
//              looping until user chooses to exit.
// PARAMATERS:  NONE.
// RETURNS:     Returns 0 if successful run.
// CALLS:       GetUserInput() - Gets user input on how many which sorts to run and how many
//                               times to run them.
//              timeArray()    - Dynamically allocates 2 arrays that will hold the sort times
//                               for each sort.
//              sortNums()     - Creates random list to sort, handles all the sorting and displays
//                               the sort times.
// IMPLEMENTED BY: MICAHEL FORT
//                 DAVID GARCIA
//***********************************************************************************************
int main()
{
    int sortType[2] = {0, 0};                   // holds 2 sort types
    int repeatTimes = 0;                        // how many times to repeat sorts
    int* timeArray1 = NULL, *timeArray2 = NULL; // holds the sort times for each repeat

    ProgDescription(); // displays description of program

    // Keep looping program until user wants to exit
    while(repeatTimes > -1)
    {
        GetUserInput(sortType, repeatTimes);

        if(repeatTimes > 0) // if repeat times is -1 exit program, else continue
        {
            timeArray(repeatTimes, timeArray1, timeArray2);                // dynamically allocate time arrays
            sortNums(sortType, repeatTimes, timeArray1, timeArray2);       // create random numbers and sort them
            displayResults(sortType, timeArray1, timeArray2, repeatTimes); // display sort time results
            cout << endl;

            system("pause");
        }
        cout << endl;
    }
    return 0;
}
