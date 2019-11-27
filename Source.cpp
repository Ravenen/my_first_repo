#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	Matrix matrix[dimention];
	matrixInput(matrix);
	cout << endl;

	cout << "Not sorted: " << endl;
	matrixOutput(matrix);
	cout << endl;

	matrixSortByColumnDescending(matrix);
	cout << "Sorted: " << endl;
	matrixOutput(matrix);
	cout << endl;

	double sumOfAvaragesGeometric = 0;
	for (int indexInColumn = 0; indexInColumn < dimention; indexInColumn++) {
		int rowProduct = 1;
		for (int indexInRow = 0; indexInRow < indexInColumn; indexInRow++) {
			rowProduct *= matrix[indexInRow].getElementInColumnByIndex(indexInColumn);
		}
		double avarageGeometric = (indexInColumn == 0 ? 0 : pow(abs(rowProduct), 1. / indexInColumn));
		cout << "f(" << indexInColumn << ") = " << avarageGeometric << endl;
		sumOfAvaragesGeometric += avarageGeometric;
	}
	cout << endl;
	cout << "F = " << sumOfAvaragesGeometric;
	cout << endl;
}