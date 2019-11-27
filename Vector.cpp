#include "Vector.h"
#include <iostream>
#include <iomanip> 

using namespace std;

void mergeSort(int inputArray[], int arrayLength, sortType type);

int Matrix::getElementInColumnByIndex(int index) {
	return column[index];
}

void matrixInput(Matrix matrix[]) {
	for (int indexInColumn = 0; indexInColumn < dimention; indexInColumn++) {
		for (int indexInRow = 0; indexInRow < dimention; indexInRow++) {
			cin >> matrix[indexInRow].column[indexInColumn];
		}
	}
}

void matrixOutput(Matrix matrix[]) {
	for (int indexInColumn = 0; indexInColumn < dimention; indexInColumn++) {
		for (int indexInRow = 0; indexInRow < dimention; indexInRow++) {
			cout << setw(tabulation) << matrix[indexInRow].column[indexInColumn];
		}
		cout << endl;
	}
}

void matrixSortByColumnAscending(Matrix matrix[]) {
	matrixSortByColumn(matrix, ASCENDING);
}

void matrixSortByColumnDescending(Matrix matrix[]) {
	matrixSortByColumn(matrix, DESCENDING);
}

void matrixSortByColumn(Matrix matrix[], sortType type) {
	for (int columnIndex = 0; columnIndex < dimention; columnIndex++) {
		mergeSort(matrix[columnIndex].column, dimention, type);
	}
}

void splitArray(int inputArray[], int inputArrayLength, int leftPart[], int leftArrayLength, int rightPart[], int rightArrayLength) {
	for (int index = 0; index < leftArrayLength; index++) {
		leftPart[index] = inputArray[index];
	}
	for (int index = 0; index < rightArrayLength; index++) {
		rightPart[index] = inputArray[leftArrayLength + index];
	}
}

void mergeSort(int inputArray[], int arrayLength, sortType type) {
	if (arrayLength < 2) {
		return;
	}

	int leftPartLength = arrayLength / 2;
	int rightPartLength = arrayLength - leftPartLength;

	int* leftPart = new int[leftPartLength];
	int* rightPart = new int[rightPartLength];

	splitArray(inputArray, arrayLength, leftPart, leftPartLength, rightPart, rightPartLength);

	mergeSort(leftPart, leftPartLength, type);
	mergeSort(rightPart, rightPartLength, type);


	int indexInLeftPart = 0, indexInRightPart = 0;
	for (int index = 0; index < arrayLength; index++) {
		if (indexInLeftPart >= leftPartLength) {
			inputArray[index] = rightPart[indexInRightPart];
			indexInRightPart++;
			continue;
		}
		if (indexInRightPart >= rightPartLength) {
			inputArray[index] = leftPart[indexInLeftPart];
			indexInLeftPart++;
			continue;
		}
		if ((type == ASCENDING && leftPart[indexInLeftPart] < rightPart[indexInRightPart]) || (type == DESCENDING && leftPart[indexInLeftPart] > rightPart[indexInRightPart])) {
			inputArray[index] = leftPart[indexInLeftPart];
			indexInLeftPart++;
		}
		else {
			inputArray[index] = rightPart[indexInRightPart];
			indexInRightPart++;
		}
	}

	delete[] leftPart;
	delete[] rightPart;
}