#include "Vector.h"
#include <iostream>
#include <iomanip> 

using namespace std;

void mergeSort(int input_array[], int array_length, sortType type);

int Matrix::getElementInColumnByIndex(int index) {
	return column[index];
}

void matrixInput(Matrix matrix[]) {
	for (int index_in_column = 0; index_in_column < DIMENTION; index_in_column++) {
		for (int index_in_row = 0; index_in_row < DIMENTION; index_in_row++) {
			cin >> matrix[index_in_row].column[index_in_column];
		}
	}
}

void matrixOutput(Matrix matrix[]) {
	for (int index_in_column = 0; index_in_column < DIMENTION; index_in_column++) {
		for (int index_in_row = 0; index_in_row < DIMENTION; index_in_row++) {
			cout << setw(TABULATION) << matrix[index_in_row].column[index_in_column];
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
	for (int column_index = 0; column_index < DIMENTION; column_index++) {
		mergeSort(matrix[column_index].column, DIMENTION, type);
	}
}

void splitArray(int input_array[], int input_array_length, int left_part[], int left_array_length, int right_part[], int right_array_length) {
	for (int index = 0; index < left_array_length; index++) {
		left_part[index] = input_array[index];
	}
	for (int index = 0; index < right_array_length; index++) {
		right_part[index] = input_array[left_array_length + index];
	}
}

void mergeSort(int input_array[], int array_length, sortType type) {
	if (array_length < 2) {
		return;
	}

	int left_part_length = array_length / 2;
	int right_part_length = array_length - left_part_length;

	int* left_part = new int[left_part_length];
	int* right_part = new int[right_part_length];

	splitArray(input_array, array_length, left_part, left_part_length, right_part, right_part_length);

	mergeSort(left_part, left_part_length, type);
	mergeSort(right_part, right_part_length, type);


	int index_in_left_part = 0, index_in_right_part = 0;
	for (int index = 0; index < array_length; index++) {
		if (index_in_left_part >= left_part_length) {
			input_array[index] = right_part[index_in_right_part];
			index_in_right_part++;
			continue;
		}
		if (index_in_right_part >= right_part_length) {
			input_array[index] = left_part[index_in_left_part];
			index_in_left_part++;
			continue;
		}
		if ((type == ASCENDING && left_part[index_in_left_part] < right_part[index_in_right_part]) || (type == DESCENDING && left_part[index_in_left_part] > right_part[index_in_right_part])) {
			input_array[index] = left_part[index_in_left_part];
			index_in_left_part++;
		}
		else {
			input_array[index] = right_part[index_in_right_part];
			index_in_right_part++;
		}
	}

	delete[] left_part;
	delete[] right_part;
}