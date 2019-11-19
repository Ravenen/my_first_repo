#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	Vector A[n];
	matrixInput(A);
	cout << endl;

	cout << "Not sorted: " << endl;
	matrixOutput(A);
	cout << endl;

	matrixSort(A, DESCENDING);
	cout << "Sorted: " << endl;
	matrixOutput(A);
	cout << endl;

	double sum = 0;
	for (int i = 0; i < n; i++) {
		int row = 1;
		for (int j = 0; j < i; j++) {
			row *= A[j].getElement(i);
		}
		cout << "f(" << i << ") = " << (i == 0 ? 0 : pow(abs(row), 1./i)) << endl;
		sum += (i == 0 ? 0 : pow(abs(row), 1./i));
	}
	cout << endl;
	cout << "F = " << sum;
	cout << endl;
}