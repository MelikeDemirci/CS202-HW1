/*
* Title: Algorithm Efficiency and Sorting
* Author: Melike Demirci
* ID: 21702346
* Section: 2
* Assignment: 1
* Description: Main.cpp
*/
#include <iostream>
#include "sorting.h"
#include "auxArrayFunctions.h"
using namespace std;

int main() {
    sorting s;
    int arr1[] =  {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    int arr2[] =  {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    int arr3[] =  {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    int compCount = 0, moveCount = 0;

    // call insertionSort
    s.insertionSort(arr1, 16, compCount, moveCount);
    cout<<"Insertion Sort \t Comp Count: "<< compCount<<"\t Move Count: "<< moveCount<<endl;
    displayArray(arr1, 16);
    // reset counters and call mergeSort
    compCount = 0, moveCount = 0;
    s.mergeSort(arr2, 16, compCount, moveCount);
    cout<<"\nMerge Sort \t Comp Count: "<< compCount<<"\t Move Count: "<< moveCount<<endl;
    displayArray(arr2, 16);
    // reset counters and call quickSort
    compCount = 0, moveCount = 0;
    s.quickSort(arr3, 16, compCount, moveCount);
    cout<<"\nQuick Sort \t Comp Count: "<< compCount<<"\t Move Count: "<< moveCount<<endl;
    displayArray(arr3, 16);
    // call performanceAnalysis
    cout<<"\n-------------------------------------------------------------"<<endl;
    cout<<"---------------------Random Arrays---------------------------"<<endl;
    s.performanceAnalysis(0);

    cout<<"\n-------------------------------------------------------------"<<endl;
    cout<<"---------------------Already Sorted Arrays-------------------"<<endl;
    s.performanceAnalysis(1);

    //Question 3 Experiment
    cout<<"\n********************************************************************************"<<endl;
    cout<<"***************************************Question 3*********************************"<<endl;
    for(int i=5000; i <=25000; i = i + 5000){
        cout<<"Size: "<< i <<endl;
        s.nearlySortedAnalyze(i);
    }

    return 0;
}
