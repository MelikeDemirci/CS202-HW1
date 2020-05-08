/*
* Title: Algorithm Efficiency and Sorting
* Author: Melike Demirci
* ID: 21702346
* Section: 2
* Assignment: 1
* Description: Sorting.cpp
*/
#include "sorting.h"
#include "auxArrayFunctions.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

//--------------------- Insertion Sort Algorithms -------------------------------
void sorting::insertionSort(int *arr, int size, int &compCount, int &moveCount){
    compCount = 0;
    moveCount = 0;

    for (int unsorted = 1; unsorted < size; ++unsorted) {

        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;

        for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc){
           arr[loc] = arr[loc-1];
           moveCount++;
           compCount++;
        }

        arr[loc] = nextItem;
        moveCount++;
  }

}
//--------------------- Quick Sort Algorithms -------------------------------
void sorting::quickSort(int *arr, int size, int &compCount, int &moveCount){
    compCount = 0;
    moveCount = 0;
    quickSort(arr, 0, size - 1, compCount, moveCount);
}

void sorting::quickSort(int *arr, int first, int last, int &compCount, int &moveCount){
    int pivotIndex;
    if (first < last) {
        // Create the partition: S1 | Pivot | S2
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        // Sort subarrays S1 and S2
        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

void sorting::partition( int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    int temp;
    // Choose pivot as first
    int pivot = arr[first];
    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown
    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
      // Locate first entry on left that is ≥ pivot
      if (arr[firstUnknown] < pivot) {
		  ++lastS1;
		  temp = arr[firstUnknown];
          arr[firstUnknown] = arr[lastS1];
          arr[lastS1] = temp;
    	  moveCount = moveCount + 3;
      }
      compCount++;
   }
   // Place pivot in proper position between S 1 and S 2 , and mark its new location
   temp = arr[first];
   arr[first] = arr[lastS1];
   arr[lastS1] = temp;
   moveCount = moveCount + 3;
   pivotIndex = lastS1;
}

//--------------------- Merge Sort Algorithms -------------------------------

void sorting::mergeSort(int *arr, int size, int &compCount, int &moveCount){
    compCount = 0;
    moveCount = 0;
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

void sorting::mergeSort(int *arr, int first, int last, int &compCount, int &moveCount){
    if (first < last){
        int mid = first + (last - first) / 2; //index of the midpoint
        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid + 1, last, compCount, moveCount);
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void sorting::merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount){
    int tempArray[30000]; // Temporary array
    // Initialize the local indices to indicate the subarrays
    int first1 = first; // Beginning of first subarray
    int last1 = mid; // End of first subarray
    int first2 = mid + 1; // Beginning of second subarray
    int last2 = last; // End of second subarray

    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1; // Next available location in tempArray

    while ((first1 <= last1) && (first2 <= last2)){
        compCount++;
        // At this point, tempArray[first..index-1] is in order
        if (arr[first1] <= arr[first2]){
            tempArray[index] = arr[first1];
            first1++;
            moveCount++;
        } else {
            tempArray[index] = arr[first2];
            first2++;
            moveCount++;
        }
        index++;
    }
    // Finish off the first subarray, if necessary
    while (first1 <= last1){
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = arr[first1];
        first1++;
        index++;
        moveCount++;
    }
    // Finish off the second subarray, if necessary
    while (first2 <= last2){
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = arr[first2];
        first2++;
        index++;
        moveCount++;
    }
    // Copy the result back into the original array
    for (index = first; index <= last; index++) {
        arr[index] = tempArray[index];
        moveCount++;
    }
}

void sorting::performanceAnalysis(int selection){
    int* arr1, *arr2, *arr3;
    int arrSize[5] = {5000, 10000, 15000, 20000, 25000};
    int insS[5][3];
    int mergeS[5][3];
    int quickS[5][3];
    for(int i = 0; i < 5; i++){
        //cleans the arrays
        if(arr1 != NULL){
            delete []arr1;
        }

        if(arr2 != NULL){
            delete []arr2;
        }

        if(arr3 != NULL){
            delete []arr3;
        }

        //creates the array depending on the selection
        if(selection == 0)
            createRandomArrays(arr1, arr2, arr3, arrSize[i]);
        else
            createAlreadySortedArrays(arr1, arr2, arr3,arrSize[i]);


        clock_t startTime = clock();
        //call for insertion sort
        insertionSort(arr1,arrSize[i],insS[i][1],insS[i][2]);
        insS[i][0] = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        startTime = clock();
        //call for merge sort
        mergeSort(arr2,arrSize[i],mergeS[i][1],mergeS[i][2]);
        mergeS[i][0] = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        startTime = clock();
        //call for quick sort
        quickSort(arr3,arrSize[i],quickS[i][1],quickS[i][2]);
        quickS[i][0] = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    }
    //prints the results
    performancePrinter("Insertion Sort", arrSize, insS);
    performancePrinter("Merge Sort", arrSize, mergeS);
    performancePrinter("Quick Sort", arrSize, quickS);

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
}

void sorting::performancePrinter(string sortType, int arrSize[], int data[][3]){
    cout<<"\n-----------------------------------------------------------"<<endl;
    cout<<"Part c - Time analysis of "<< sortType<<endl;
    cout<<"Array Size\t\tTime Elapsed\t\tCompCount\t\tMoveCount "<<endl;
    for(int k = 0; k <5; k++){
        cout<<arrSize[k]<<"\t\t\t"<<data[k][0]<<"\t\t\t"<< data[k][1]<<"\t\t\t"<< data[k][2]<<endl;
    }

}
void sorting::nearlySortedAnalyze(int size){
    int* arr1, *arr2, *arr3;
    int insS, mergeS, quickS;
    int n, m;

    cout<<"K\t\tInsertion Sort\t\tMerge Sort\t\tQuick Sort"<<endl;
    for(int i = 0; i < size; i = i + size/10){
        //cleans the arrays
        if(arr1 != NULL){
            delete []arr1;
        }

        if(arr2 != NULL){
            delete []arr2;
        }

        if(arr3 != NULL){
            delete []arr3;
        }
        createNearlySortedArrays(arr1, arr2, arr3, size, i);
        clock_t startTime = clock();
        //call for insertion sort
        insertionSort(arr1,size,n,m);
        insS = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        startTime = clock();
        //call for merge sort
        mergeSort(arr2,size, n ,m );
        mergeS = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        startTime = clock();
        //call for quick sort
        quickSort(arr3,size, n, m);
        quickS = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        cout<<i<<"\t\t\t"<<insS<<"\t\t\t"<<mergeS<<"\t\t\t"<<quickS<<endl;
    }
    delete []arr1;
    delete []arr2;
    delete []arr3;
}
