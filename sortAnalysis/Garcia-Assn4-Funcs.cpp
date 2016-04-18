//**********************************************************************************************
//  FILENAME:       Garcia-Assn4-Funcs.cpp
//  DESCRIPTION:    Contains all function definitions implemented by David Garcia
//  DESIGNER:       David Garcia
//*********************************************************************************************

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Fort-Assn4-Funcs.h"
#include "Garcia-Assn4-Funcs.h"
#include "FortGarcia-Assn4-Common.h"

using namespace std;

//***********************************************************************************************
// FUNCTION:    getUserInput()
// DESCRIPTION: Request input from the user as to which sort functions
//			    they wish to run and how many times. Also validates
//              user input.
//  PARAMATERS: sortType    - Type of sorts to perform.
//              repeatTimes - Number of times to repeat sorts.
//  RETURNS:    sortType    - Enumerated SORT_TYPE
//              repeatTimes - Number of times to repeat sorts.
// 	CALLS:      NONE.
//  IMPLEMENTED BY: DAVID GARCIA
//***********************************************************************************************
void GetUserInput(int *sortType, int& repeatTimes)
{
    int ignoreSize = 1000;
    bool goodInput = false;
    string sortTypeInput;
    repeatTimes = 0;

    // get sort type from user
    while(!goodInput)
    {
        DrawMenu();
        cout << "\n Enter two letter choices (or EE to exit): ";
        cin  >> sortTypeInput;
        cin.clear();                 // clears error flags
        cin.ignore(ignoreSize,'\n'); // ignores "ignoreSize" of characters up to new line '\n'.

        // Check input for errors
        for(int i = 0; i <= 1; i++)
        {
            if(sortTypeInput == "ee" || sortTypeInput == "EE" || sortTypeInput == "eE" || sortTypeInput == "Ee")
            {
                goodInput = true;
                repeatTimes = -1; // set to -1 to exit program
                i += 2; // break loop
            }
            else if(sortTypeInput[i] == 'b' || sortTypeInput[i] == 'B')
            {
                sortType[i] = BUBBLE;
                goodInput = true;
            }
            else if(sortTypeInput[i] == 'i' || sortTypeInput[i] == 'I')
            {
                sortType[i] = INSERTION;
                goodInput = true;
            }
            else if(sortTypeInput[i] == 'm' || sortTypeInput[i] == 'M')
            {
                sortType[i] = MERGE;
                goodInput = true;
            }
            else if(sortTypeInput[i] == 'q' || sortTypeInput[i] == 'Q')
            {
                sortType[i] = QUICK;
                goodInput = true;
            }
            else
            {
                cout << " ERROR: Incorrect input. Try again." << endl << endl;
                repeatTimes = 0; // reset repeat times
                goodInput = false;
                i += 2; // break loop
            } // END of if else if
        } // END of for loop
    } // END of while loop

    // if repeat times is -1 exit program, else get repeat times from user
    if(repeatTimes == 0)
    {
        goodInput = false;
        while(!goodInput)
        {
            cout << "\n Enter the number of times to repeat each sort (1 or more):";
            cin  >> repeatTimes;

            if(repeatTimes < 1 || cin.fail())
                cout << " ERROR: Input must be greater than zero." << endl;
            else
                goodInput = true;
            cin.clear();                 // clears error flags
            cin.ignore(ignoreSize,'\n'); // ignores "ignoreSize" of characters up to new line '\n'.
        }
    }
}


//***********************************************************************************************
// FUNCTION:    drawMenu()
// DESCRIPTION: Utilizes "cout" to draw the user menu in the program.
// PARAMATERS:  NONE.
// RETURNS:     NONE.
// CALLS:       NONE.
// IMPLEMENTED BY: DAVID GARCIA
//***********************************************************************************************
void DrawMenu()
{
    cout << " Choose two sorts you wish to compare:" << endl;
    cout << "\t B = Bubble sort" << endl;
    cout << "\t I = Insertion sort" << endl;
    cout << "\t M = Merge sort" << endl;
    cout << "\t Q = Quick sort" << endl;
    cout << "\t E = Exit program" << endl;
}


//***********************************************************************************************
// FUNCTION:    timeArray()
// DESCRIPTION: Dynamically creates two arrays to store the amount of
//              time it takes to do each sort test.
// PARAMATERS:  repeatTimes - Number of times to repeat sorts.
//              timeArray1  - Array to hold sort time.
//              timeArray2  - Array to hold sort time.
// RETURNS:     timeArray1  - An initialized dynamic array.
//              timeArray2  - An initialized dynamic array.
// CALLS:       NONE.
// IMPLEMENTED BY: DAVID GARCIA
//***********************************************************************************************
void timeArray(int repeatTimes, int*& timeArray1, int*& timeArray2)
{
    // dynamically allocate memory for arrays
    timeArray1 = new (nothrow) int[repeatTimes];
    timeArray2 = new (nothrow) int[repeatTimes];

    // set each element to zero
    for(int i = 0; i < repeatTimes; i++)
    {
        timeArray1[i] = 0;
        timeArray2[i] = 0;
    }
}


//***********************************************************************************************
// FUNCTION:    bubbleSort()
// DESCRIPTION: Performs a "bubble" sort on a list of random integers and stores the time it took
//              to perform the sort.
// PARAMATERS:  timeArrayKey - Index location to store the sort time.
//              randomArray  - Array of random integers.
//              sortedArray  - Sorted array of integers.
//              timeArray    - Array that holds the sort times.
// RETURNS:     timeArray    - The time it took to perform a bubble sort.
// CALLS:       NONE.
// IMPLEMENTED BY: DAVID GARCIA
//***********************************************************************************************
void bubbleSort(int timeArrayKey, int randomArray[], int sortedArray[], int timeArray[])
{
    int startTime, endTime;
    int temp = 0;
    bool listSorted = false;
    int currentIndex, lastIndex = randListSize - 1;

    for(int i = 0; i < randListSize; i++) // copy random numbers in array to sort
        sortedArray[i] = randomArray[i];

    startTime = clock(); // get sort start time

    // Bubble sort
    while(!listSorted)
    {
        listSorted = true;
        currentIndex = 0;

        while(currentIndex < lastIndex)
        {
            if(sortedArray[currentIndex] > sortedArray[currentIndex + 1])
            {
                temp = sortedArray[currentIndex];
                sortedArray[currentIndex] = sortedArray[currentIndex + 1];
                sortedArray[currentIndex + 1] = temp;
                listSorted = false;
            }
            ++currentIndex;
        }
    }

    endTime = clock(); // get sort end time
    timeArray[timeArrayKey] = endTime - startTime; // save total sort time
}


//***********************************************************************************************
// FUNCTION:    quickSort(int, int[], int[], int[])
// DESCRIPTION: Performs a "quick" sort on a list of random integers and stores the time it took
//              to perform the sort.
// PARAMATERS:  timeArrayKey - Index location to store the sort time.
//              randomArray  - Array of random integers.
//              sortedArray  - Sorted array of integers.
//              timeArray    - Array that holds the sort times.
// RETURNS:     timeArray    - The time it took to perform a bubble sort.
// CALLS:       quickSort    - An OVER LOADED FUNCTION of quick sort. Recursively calls itself
//                             and handles all of the sorting.
// IMPLEMENTED BY: DAVID GARCIA
//***********************************************************************************************
void quickSort(int timeArrayKey, int randomArray[], int sortedArray[], int timeArray[])
{
    int startTime, endTime;

    for(int i = 0; i < randListSize; i++) // copy random numbers in array to sort
        sortedArray[i] = randomArray[i];

    startTime = clock(); // get sort start time

    quickSort(sortedArray, 0, randListSize - 1);

    endTime = clock(); // get sort end time
    timeArray[timeArrayKey] = endTime - startTime; // save total sort time
}


//***********************************************************************************************
// FUNCTION:    quickSort(int[], int, int) - OVERLOADED FUNCTION
// DESCRIPTION: Performs the majority of the sorting by recursively calling it self until the
//              the list is sorted.
// PARAMATERS:  sortedArray - An array of integers to sort.
//              first       - Index location that initially is the first element in list.
//              last        - Index location that initially is the last element in list.
// RETURNS:     sortedArray - An array of sorted integers.
// CALLS:       quickSort(int[], int, int) - Recursively calls itself to sort array.
//              getPartition()             - Returns location of pivot point used in quickSort.
// IMPLEMENTED BY: DAVID GARCIA
//***********************************************************************************************
void quickSort(int sortedArray[], int first, int last)
{
    int pivotLocation;

    if(first < last)
    {
        pivotLocation = getPartition(sortedArray, first, last);
        quickSort(sortedArray, first, pivotLocation - 1);
        quickSort(sortedArray, pivotLocation + 1, last);
    }
}


//***********************************************************************************************
// FUNCTION:    getPartition()
// DESCRIPTION: Gets pivot point index location for quickSort function.
// PARAMATERS:  sortedArray - An array of integers.
//              first       - Index location that initially is the first element in list.
//              last        - Index location that initially is the last element in list.
// RETURNS:     smallIdx    - The pivot location used to sort list.
// CALLS:       Swap()      - Swaps the values in index locations first & smallIdx.
// IMPLEMENTED BY: DAVID GARCIA
//***********************************************************************************************
int getPartition(int sortedArray[], int first, int last)
{
    int pivot, index, smallIdx;

    Swap(sortedArray, first, (first + last) / 2);

    pivot = sortedArray[first];
    smallIdx = first;

    for(index = first + 1; index <= last; index++)
        if(sortedArray[index] < pivot)
        {
            smallIdx++;
            Swap(sortedArray, smallIdx, index);
        }

    Swap(sortedArray, first, smallIdx);

    return smallIdx;
}

//***********************************************************************************************
// FUNCTION:    Swap()
// DESCRIPTION: Swaps 2 elements in an array
// PARAMATERS:  sortedArray - An array of integers.
//              first       - Index location of value to swap with "second".
//              last        - Index location of value to swap with "first".
// RETURNS:     sortedArray - Returns array with 2 elements swapped at index locations first and
//                            second.
// CALLS:       NONE.
// IMPLEMENTED BY: DAVID GARCIA
//***********************************************************************************************
void Swap(int sortedArray[], int first, int second)
{
    int temp;

    temp = sortedArray[first];
    sortedArray[first] = sortedArray[second];
    sortedArray[second] = temp;
}


//***********************************************************************************************
// FUNCTION:    ProgDescription()
// DESCRIP:     Displays a description of what the program does.
// PARAMATERS:  NONE.
// RETURNS:     NONE.
// CALLS:       NONE.
// IMPLEMENTED BY: DAVID GARCIA
//***********************************************************************************************
void ProgDescription()
{
    cout << " PROGRAM DESCRIPTION: This program creates an array of 100,000 random\n";
    cout << " integers that is sorted by an algorithm selected by the user. After\n";
    cout << " each sort the program displays the amount of time each sort took to\n";
    cout << " run. This program will continue to run until the user chooses to exit.\n\n\n";
}
