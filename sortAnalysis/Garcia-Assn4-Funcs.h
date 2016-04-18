//**********************************************************************************************
//  FILENAME:       Garcia-Assn4-Funcs.h
//  DESCRIPTION:    Contains all function prototypes implemented by David Garcia
//  DESIGNER:       David Garcia
//*********************************************************************************************

#include "FortGarcia-Assn4-Common.h"

void GetUserInput(int *sortType, int& repeatTimes);
void DrawMenu();
void timeArray (int repeatTimes, int*& timeArray1, int*& timeArray2);
void bubbleSort(int timeArrayKey, int randomArray[], int sortedArray[], int timeArray[]);
void quickSort (int timeArrayKey, int randomArray[], int sortedArray[], int timeArray[]);
void quickSort(int sortedArray[], int lowIdx, int highIdx); // overLoaded function
int  getPartition(int sortedArray[], int first, int last);  // called by overloaded quick sort - part of quickSort
void Swap(int sortedArray[], int first, int second);        // called by getPartition - part of quickSort
void ProgDescription();
