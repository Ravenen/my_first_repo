#pragma once
#include "consts.h"

class Vector
{
private:
	int array[m];
public:
	friend void matrixInput(Vector A[]);
	friend void matrixOutput(Vector A[]);
	friend void matrixSort(Vector A[], sort_type type);
	int getElement(int index);
};

