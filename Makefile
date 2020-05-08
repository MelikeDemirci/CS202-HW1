# Title : Homework 1
# Author : Melike Demirci
# ID: 21702346
# Section : 2
# Assignment : 1
# Description : makefile


hw: main.o sorting.o auxArrayFunctions.o
	g++ main.o sorting.o auxArrayFunctions.o -o hw

main.o: main.cpp
	g++ -c main.cpp

auxArrayFunctions.o: auxArrayFunctions.cpp auxArrayFunctions.h
	g++ -c auxArrayFunctions.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

clean:
	rm *o hw