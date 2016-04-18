//**********************************************************************************************
//  FILENAME:       Fort-Assn4-Funcs.cpp
//  DESCRIPTION:    Contains all function definitions implemented by Michael Fort
//  DESIGNER:       Michael Fort
//*********************************************************************************************
#include "Fort-Assn4-Funcs.h"

using namespace std;


//*********************************************************************
// FUNCTION: sortNums()
// DESCRIPTION: initializes random array and calls whichSort the
//              correct number of times
// INPUT:
//	Parameters: int sortType – Enum defining which sorts to run
//    		    int repeatTimes – number of times to run sorts
// OUTPUT:
//	Return Val: int* - array of sort clock times
// CALLS TO: int* randomArray()
//		     void whichSort()
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
int* sortNums(int sortType[], int repeatTimes, int timeArray1[], int timeArray2[])
{
    for(int i = 0; i < repeatTimes; i++)
    {
        int* randArr = randomArray();
        whichSort(i,sortType, randArr, timeArray1, timeArray2);
    }

}
//*********************************************************************

//*********************************************************************
// FUNCTION: randomArray()
// DESCRIPTION: creates the array of random numbers to sort
// INPUT:
//	Parameters: int arraySize – size of array to initialize
// OUTPUT:
//	Return Val: int* - pointer to random array of numbers
// CALLS TO: N/A
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
int* randomArray()
{
    static int tmp[randListSize];

    srand(time(NULL));
    for(int i = 0; i < randListSize; i++)
    {
        tmp[i] = rand() % randArrayTopNum + 1 ;
    }
    return tmp;
}
//*********************************************************************

//*********************************************************************
// FUNCTION: whichSort()
// DESCRIPTION: runs the required sorts
// INPUT:
//	Parameters: int sortType – Enum defining which sorts to run
//			  int timeArrayKey – where to store the results
//			  int timeArray1[] – array pointer to store results
//			  int timeArray2[] – array pointer to store results
//			  int randomArray[] – numbers to sort
// OUTPUT:
//	Return Val: void
// CALLS TO: void insertionSort()
//		   void mergeSort()
//		   void bubbleSort()
//		   void quicksort()
//		   bool verifySort()
//         void displayTime()
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
void whichSort(int timeArrayKey, int sortType[], int randomArray[], int timeArray1[], int timeArray2[])
{
    //void (*typeSort) (int, int*, int*, int*) = NULL;
    int sortedArray[randListSize];
    for(int i = 0; i < randListSize; i++)
    {
        sortedArray[i] = 0;
    }

    cout << "Starting sort #" << timeArrayKey+1 << "..." << endl;

    (*funcPtrArray[sortType[0]]) (timeArrayKey, randomArray, sortedArray, timeArray1);
    displayTime(sortType[0], timeArray1[timeArrayKey]);
    if(verifySort(sortedArray))
    {
        (*funcPtrArray[sortType[1]]) (timeArrayKey, randomArray, sortedArray, timeArray2);
        displayTime(sortType[1], timeArray2[timeArrayKey]);
        if(verifySort(sortedArray))
        {
            cout << "\t" << "Sorts validated" << endl;
        }
        else
        {
            cout << "SORTING ERROR IN 2ND FUNCTION" << endl;
        }
    }
    else
    {
        cout << "SORTING ERROR IN 1ST FUNCTION" << endl;
    }
}
//*********************************************************************

//*********************************************************************
// FUNCTION: insertionSort()
// DESCRIPTION: performs an insertion sort on random ints
// INPUT:
//	Parameters: int timeArrayKey – where to store sort time results
//			  int randomArray[] – array of random numbers
//			  int sortedArray[] – array to store sorted numbers
//			  int timeArray[] – array to store results
// OUTPUT:
//	Return Val: void
// CALLS TO: N/A
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
void insertionSort(int timeArrayKey, int randomArray[], int sortedArray[], int timeArray[])
//void insertionSort(int timeArrayKey, int randomArray[], int sortedArray[], int timeArray[])
{
    int curIndex = 0;
    int remainTopIndex = 1;
    int lastIndex = randListSize;
    int insertVal = 0;
    int startTime = 0;
    int endTime = 0;
    //copy array
    for(int i = 0; i < randListSize; i++)
    {
        sortedArray[i] = randomArray[i];
    }
    startTime = clock();
    while(remainTopIndex != lastIndex)
    {
        insertVal = sortedArray[remainTopIndex];
        curIndex = remainTopIndex - 1;
        while(insertVal < sortedArray[curIndex] && curIndex >= 0)
        {
            sortedArray[curIndex+1] = sortedArray[curIndex];
            curIndex -= 1;
        }
        sortedArray[curIndex+1] = insertVal;
        remainTopIndex++;
    }
    endTime = clock();
    timeArray[timeArrayKey] = endTime-startTime;
}
//*********************************************************************

//*********************************************************************
// FUNCTION: mergeSort()
// DESCRIPTION: performs an merge sort on random ints
// INPUT:
//	Parameters: int timeArrayKey – where to store sort time results
//			  int randomArray[] – array of random numbers
//			  int sortedArray[] – array to store sorted numbers
//			  int timeArray[] – array to store results
// OUTPUT:
//	Return Val: void
// CALLS TO: mergeSortAlgor()
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
void mergeSort(int timeArrayKey, int randomArray[], int sortedArray[], int timeArray[])
{
    int startTime = 0;
    int endTime = 0;

    for(int i = 0; i < randListSize; i++)
    {
        sortedArray[i] = randomArray[i];
    }
    startTime = clock();
    mergeSortAlgor(0, randListSize-1, sortedArray);
    endTime = clock();
    timeArray[timeArrayKey] = endTime-startTime;
}
//*********************************************************************

//*********************************************************************
// FUNCTION: mergeAlgor()
// DESCRIPTION: performs the merge portion of the merge sort
// INPUT:
//	Parameters: int leftIdx - the left index
//              int mid - the mid point
//              int rightIdx - the right index
//			    int lst[] – the array to be sorted
// OUTPUT:
//	Return Val: N/A
// CALLS TO: N/A
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
void mergeAlgor(int leftIdx, int mid, int rightIdx, int lst[])
{
    int lstSize = (rightIdx - leftIdx)+1;
    int *temp = new int[lstSize];

	int left = leftIdx;
	int right = mid+1;
	int current = 0;

	while(left <= mid && right <= rightIdx) {
		if(lst[left] <= lst[right]) {
			temp[current] = lst[left];
			left++;
		}
		else {
			temp[current] = lst[right];
			right++;
		}
		current++;
	}

	if(left > mid) {
		for(int i=right; i <= rightIdx;i++) {
			temp[current] = lst[i];
			current++;
		}
	}
	else {
		for(int i=left; i <= mid; i++) {
			temp[current] = lst[i];
			current++;
		}
	}

    //put back
	for(int i=0; i<=rightIdx-leftIdx;i++) {
                lst[i+leftIdx] = temp[i];
	}
	delete[] temp;
}
//*********************************************************************

//*********************************************************************
// FUNCTION: mergeSortAlgor()
// DESCRIPTION: performs the split portion of the merge sort
// INPUT:
//	Parameters: int leftIdx - the left index
//              int rightIdx - the right index
//			    int lst[] - the array to be sorted
// OUTPUT:
//	Return Val:
// CALLS TO: void mergeSortAlgor()
//		     void mergeAlgor()
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
void mergeSortAlgor(int leftIdx, int rightIdx, int lst[])
{
    int mid;
    if(leftIdx >= rightIdx)
    {
        return;
    }
    mid = (leftIdx + rightIdx)/2;
    mergeSortAlgor(leftIdx, mid, lst);
    mergeSortAlgor(mid+1, rightIdx, lst);
    mergeAlgor(leftIdx, mid, rightIdx, lst);
}
//*********************************************************************

//*********************************************************************
// FUNCTION: verifySort()
// DESCRIPTION: verifies that the numbers are properly sorted
// INPUT:
//	Parameters: int sortedArray[] – array of numbers to verify
// OUTPUT:
//	Return Val: bool – successful sort or not
// CALLS TO: N/A
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
bool verifySort(int sortedArray[])
{
    bool retVal = true;
    for(int i = 0; i < randListSize-1; i++)
    {
        if(sortedArray[i] > sortedArray[i+1])
        {
            i = randListSize;
            retVal = false;
        }
    }
    return retVal;
}
//*********************************************************************

//*********************************************************************
// FUNCTION: displayResults()
// DESCRIPTION: prints the results of the sorts
// INPUT:
//	Parameters: int sortType[] - the array of sort types used
//              int timeArray1[] – array of sort times
//              int timeArray2[] – array of sort times
//              int repeatTimes – number of times sorted
// OUTPUT:
//	Return Val: void
// CALLS TO: N/A
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
void displayResults(int sortType[], int timeArray1[], int timeArray2[], int repeatTimes)
{
    int avg1 = 0;
    int avg2 = 0;
    for(int i = 0; i < repeatTimes; i++)
    {
        avg1 += timeArray1[i];
    }
    avg1 = avg1/repeatTimes;
    for(int i = 0; i < repeatTimes; i++)
    {
        avg2 += timeArray2[i];
    }
    avg2 = avg2/repeatTimes;

    cout << endl << "SORTING RESULTS" << endl
                 << "---------------" << endl;
    string type1 = printType(sortType[0]);
    string type2 = printType(sortType[1]);
    string avgStatement = " clock ticks on average";
    cout << setw(10) << type1 << " Sort" << "\t " << avg1 << avgStatement << endl;
    cout << setw(10) << type2 << " Sort" << "\t " << avg2 << avgStatement << endl;

}
//*********************************************************************

//*********************************************************************
// FUNCTION: printType()
// DESCRIPTION: prints the name of sorts performed
// INPUT:
//	Parameters: int enumType = the type of sort
// OUTPUT:
//	Return Val: string - name of the sort
// CALLS TO: N/A
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
string printType(int enumType)
{
    string type = "ERROR";
    switch(enumType)
    {
    case 0:
        type = "Bubble";
        break;
    case 1:
        type = "Insertion";
        break;
    case 2:
        type = "Merge";
        break;
    case 3:
        type = "Quick";
        break;
    }
    return type;
}
//*********************************************************************

//*********************************************************************
// FUNCTION: displayTime()
// DESCRIPTION: prints the time for the sorts
// INPUT:
//	Parameters: int enumType - name of sort performed
//              int time - the time for the sort
// OUTPUT:
//	Return Val: void
// CALLS TO: N/A
// IMPLEMENTED BY: Michael Fort
//*********************************************************************
void displayTime(int enumType, int time)
{
    string type = printType(enumType);
    cout << "\t" << type << " Sort time " << time << "..." << endl;
}
