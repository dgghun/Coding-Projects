//**********************************************************************************************
//  FILENAME:       Fort-Assn4-Funcs.h
//  DESCRIPTION:    Contains all function prototypes implemented by Michael Fort
//  DESIGNER:       Michael Fort
//*********************************************************************************************

#include "FortGarcia-Assn4-Common.h"
#include "Garcia-Assn4-Funcs.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "time.h"
#include <string>
#include <ctime>

using namespace std;

bool verifySort(int sortedArray[]);

int* randomArray();
int* sortNums(int sortType[], int repeatTimes, int timeArray1[], int timeArray2[]);

string printType(int enumType);

void displayResults(int sortType[], int timeArray1[], int timeArray2[], int repeatTimes);
void displayTime(int type, int time);
void insertionSort(int timeArrayKey, int randomArray[], int sortedArray[], int timeArray[]);
void mergeAlgor(int leftIdx, int mid, int rightIdx, int lst[]);
void mergeSort(int timeArrayKey, int randomArray[], int sortedArray[], int timeArray[]);
void mergeSortAlgor(int leftIdx, int rightIdx, int lst[]);
void whichSort( int timeArrayKey, int sortType[], int randomArray[], int timeArray1[], int timeArray2[]);

typedef void (*funcPtrType) (int, int[], int[], int[]);

const int NUM_FUNCS = 4;

const funcPtrType funcPtrArray[NUM_FUNCS] = {&bubbleSort,&insertionSort, &mergeSort, &quickSort};
