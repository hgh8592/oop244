#include "Marks.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
char mark[100] = { 0 };
char name[41] = { 0 };
int* arr;

void programTitle() {
	cout << "Mark Stats Program.\n" << endl;
}

void nameOfAssessment(char* name) {
	cout << "Please enter the assessment name: ";
	cin.getline(name, 40);
}
bool isInterger(char* mark) {
	for (int i = 0; i < (int)strlen(mark); i++) {
		if (isdigit(mark[i]) == false) {
			return false;
		}
	}
	return true;
}
int checkNumber(char* mark) {
	int number = 0;
	if (0 <= (int)mark[0] - 48 && 9 >= (int)mark[0] - 48) {
		number++;
	}return number;
	} 
int getRealNumber(char* mark) {
	int total = 0, i = 0;
	while (i < (int)strlen(mark)) {
		if (i == 0) {
			total += (int)mark[i] - 48;
		}
		else {
			total = total * 10 + (int)mark[i] - 48;
		}i++;
	}
	return total;

}

int getMark(char* mark) {
	int number = 0;
	int total = 0;
	cout << "Please enter the number of marks: ";
	cin >> mark;
	do {
		if (isInterger(mark)) {
			total = getRealNumber(mark);
			if (total > 50 || total < 5) {
				cout << "Invalid value (5<=value<=50), try again: ";
				cin >> mark;
			}
			else {
				continue;
			}
		}
		if (!isInterger(mark)) {
			number = checkNumber(mark);
			if (number == 0) {
				cout << "Invalid number, try again: ";
				cin >> mark;
			}
			else if (number == 1) {
				cout << "Invalid trailing characters, try again: ";
				cin >> mark;
			}
		}

	} while (!isInterger(mark) || total > 50 || total < 5);
	return total;
}
	
void display(int size){
	cout << "Please enter " << size << " marks (0<=value<=100): "<< endl;
}
bool checkValue(int arr) {
	if (arr > 100 || arr < 0) {
		cout << "Invalid calue (0<=value<=100), try again: ";
		return false;
	}
	return true;
}
void enterValue(int size){
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "> ";
		cin >> arr[i];
		while (!checkValue(arr[i])){
			cin >> arr[i];
		}
	}

}
void displayName(char* name) {
	for (int i = 0; name[i] != '\0'; i++) {
		cout << name[i];
	}
}
void sortMarks(int* arr, int size) {
		int temp;
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (arr[i] > arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}

		}
	}
 void displayMarks(int* arr, int size) {
	sortMarks(arr, size);
	for (int i = size - 1; i >= 0; i--) {
		if (i == 0) {
			cout << arr[i] << endl;
		}
		else {
			cout << arr[i] << ", ";
		}
	}
}

double calAverage(int* arr, int size) {
	double avg = 0;
	for (int i = 0; i < size; i++) {
		avg += (double)arr[i];
	}
	return avg /=(double)size;
}
int passMarks(int* arr, int size) {
	int number = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] >= 50) {
			number++;
		}
	}
	return number;
}
void displayResult(int size, char* name, int *arr){
	int markTotal = 0;
	double avg = 0;
	int number = passMarks(arr, size);

	cout << "Thank you. . ." << endl;
	cout << "Assessment Name: ";
	displayName(name);
	cout << endl << "----------------" << endl;
	displayMarks(arr, size);
	avg = calAverage(arr, size);
	cout.precision(1);
	cout << "Average: " <<fixed<< avg << endl;
	cout << "Number of Passing Marks: " << number << endl;
}
void markstat() {
	programTitle();
	nameOfAssessment(name);
	int size = getMark(mark);
	display(size);
	enterValue(size);
	displayResult(size, name, arr);


	delete[] arr;
}