#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	Matrix matrix[DIMENTION];
	matrixInput(matrix);
	cout << endl;

	cout << "Not sorted: " << endl;
	matrixOutput(matrix);
	cout << endl;

	matrixSortByColumnDescending(matrix);
	cout << "Sorted: " << endl;
	matrixOutput(matrix);
	cout << endl;

	double sum_of_avarages_geometric = 0;
	for (int index_in_column = 0; index_in_column < DIMENTION; index_in_column++) {
		int row_product = 1;
		for (int index_in_row = 0; index_in_row < index_in_column; index_in_row++) {
			row_product *= matrix[index_in_row].getElementInColumnByIndex(index_in_column);
		}
		double avarage_geometric = (index_in_column == 0 ? 0 : pow(abs(row_product), 1. / index_in_column));
		cout << "f(" << index_in_column << ") = " << avarage_geometric << endl;
		sum_of_avarages_geometric += avarage_geometric;
	}
	cout << endl;
	cout << "F = " << sum_of_avarages_geometric;
	cout << endl;
}