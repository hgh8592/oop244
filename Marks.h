#ifndef _244_Marks_H
#define _244_Marks_H
#include "Utils.h"
using namespace std;



void programTitle();
void nameOfAssessment(char* name);
bool isInterger(char* mark);
int checkNumber(char* mark);
int getRealNumber(char* mark);
int getMark(char* mark);
void display(int size);
bool checkValue(int arr);
void enterValue(int size);
void displayName(char* name);
void sortMarks(int* arr, int size);
void displayMarks(int* arr, int size);
double calAverage(int* arr, int size);
int passMarks(int* arr, int size);
void displayResult(int size, char* name, int* arr);
void markstat();

#endif // !_244_Utils_H
