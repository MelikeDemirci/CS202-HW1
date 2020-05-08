#ifndef __AUX_ARRAY_FUNCTIONS
#define __AUX_ARRAY_FUNCTIONS

void displayArray(int *arr, int len);

/* It creates and returns three identical arrays with the given size N */
/* These arrays are in ascending order                                 */
void createAlreadySortedArrays(int *&arr1, int *&arr2, int *&arr3, int N);

/* It creates and returns three identical arrays with the given size N */
/* These arrays contain random integers                                */
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int N);

/* It creates and returns three identical arrays with the given size N */
/* These arrays are nearly sorted. That is, each item in these arrays  */
/* is at most K away from its target location.                         */
void createNearlySortedArrays(int *&arr1, int *&arr2, int *&arr3, int N, int K);

// These are auxiliary functions used to implement createNearlySortedArrays
void attemptOneSwap(int *arr, int N, int K, int currIndex);
double averageDistance(int *arr, int N);

#endif
