#pragma once
#include "consts.h"

class Matrix
{
private:
	int column[DIMENTION];
public:
	friend void matrixInput(Matrix matrix[]);
	friend void matrixOutput(Matrix matrix[]);
	friend void matrixSortByColumnAscending(Matrix matrix[]);
	friend void matrixSortByColumnDescending(Matrix matrix[]);
	friend void matrixSortByColumn(Matrix matrix[], sortType type);
	int getElementInColumnByIndex(int index);
};

