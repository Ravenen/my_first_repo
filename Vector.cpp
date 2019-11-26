#include "Vector.h"
#include <iostream>
#include <iomanip> 

using namespace std;

void mergeSort(int& r_arr, int len, sort_type type);

int Vector::getElement(int index) {
	return array[index];
}

void matrixInput(Vector A[]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[j].array[i];
		}
	}
}

void matrixOutput(Vector A[]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << A[j].array[i];
		}
		cout << endl;
	}
}

void  matrixSort(Vector A[], sort_type type) {
	for (int i = 0; i < n; i++) {
		int column[m] = { 0 };
		for (int h = 0; h < m; h++) {
			column[h] = A[i].array[h];
		} 
		mergeSort(*column, m, type);
		for (int h = 0; h < m; h++) {
			A[i].array[h] = column[h];
		}
	}
}

void mergeSort(int& r_arr, int len, sort_type type) {
	int* arr = &r_arr;
	if (len < 2) {
		return;
	}

	int* a = new int[len / 2];
	int* b = new int[len - len / 2];

	for (int k = 0; k < len / 2; k++) {
		a[k] = arr[k];
	}
	for (int h = 0; h < len - len / 2; h++) {
		b[h] = arr[len / 2 + h];
	}

	mergeSort(*a, len / 2, type);
	mergeSort(*b, len - len / 2, type);


	int left = 0, right = 0;
	for (int i = 0; i < len; i++) {
		if (left >= len / 2) {
			arr[i] = b[right];
			right++;
			continue;
		}
		if (right >= len - len / 2) {
			arr[i] = a[left];
			left++;
			continue;
		}
		if ((type == ASCENDING && a[left] < b[right]) || (type == DESCENDING && a[left] > b[right])) {
			arr[i] = a[left];
			left++;
		}
		else {
			arr[i] = b[right];
			right++;
		}
	}

	delete[] a;
	delete[] b;
}