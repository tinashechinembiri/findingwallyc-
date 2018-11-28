#pragma once
#include<iostream>
#include "Baseimage.h"
#include"Matchimage.h"
#include <vector>

class Largeimage : public Baseimage
{
public:
	Largeimage();
	Largeimage(int sizeX, int sizeY, double val); 
	Largeimage(int sizeX, int sizeY, double*value_Data);
	Largeimage(const Largeimage& copyMatrix);
	Matchimage *returnVar(int size); 
	void bubbleSort();
	
	double** getBlock(int sRow, int eRow, int sColumn, int eColumn);
	void ssd(int xcord, int ycords, Baseimage* base1, Largeimage* large1, int row, int column );
	~Largeimage();
protected:
	std::vector<Matchimage*>ssd_Vector;

	
	
	///24, 18
	
};

