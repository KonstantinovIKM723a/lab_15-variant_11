#pragma once
#include <iostream>;
#include "windows.h";
using namespace std;

int strToNonNegativeInt(string str);
void switchElements(int* a, int from, int dest);
void arrayWithNegativesFirstZerosLast(int* a, int size);
void quickSort(int* a, int high, int low = 0);
bool isSorted(int* a, int count);