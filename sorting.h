/*
* Title: Algorithm Efficiency and Sorting
* Author: Melike Demirci
* ID: 21702346
* Section: 2
* Assignment: 1
* Description: Sorting Header
*/
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;

class sorting {
public:
    void insertionSort(int *arr, int size, int &compCount, int &moveCount);
    void quickSort(int *arr, int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, int size, int &compCount, int &moveCount);
    void performanceAnalysis(int selection);
    void nearlySortedAnalyze(int size);

private:
    void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void partition( int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
    void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
    void performancePrinter(string sortType, int arrSize[], int data[][3]);
};

#endif // SORTING_H
