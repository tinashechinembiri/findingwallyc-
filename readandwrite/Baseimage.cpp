#include "stdafx.h"
#include "Baseimage.h"
#include <sstream> // stringstream
#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <istream>


Baseimage::Baseimage()
{
}
Baseimage::Baseimage(int sizeX, int sizeY, double val)
{
	M = sizeX;
	N = sizeY;
	data_ptr = new double[M*N];
	for (int i = 0; i < M*N; i++)
	{

		data_ptr[i] = val;

	}


}
Baseimage::Baseimage(int sizeX, int sizeY, double* value_Data)
{
	M = sizeX;
	N = sizeY;

	data_ptr = new double[M*N]; // it will make the space for the one d array
	for (int i = 0; i < M*N; i++)
	{
		data_ptr[i] = value_Data[i]; /// populates the 1 d array
	}

	matrix_Ptr = getPointermatrix(sizeX, sizeY);

}
double** Baseimage::getPointermatrix(int sizeX, int sizeY)
{
	double** temp = new double*[sizeX];
	for (int i = 0; i < sizeX; i++)
	{
		temp[i] = new double[sizeY];

	}
	return temp;
}
void Baseimage::populateMatrix() /// this function will allow me to populate the 2 d array
{
	int counter = 0;
	for (int i = 0; i < M; i++) /// it will loop through the rows
	{
		for (int j = 0; j < N; j++) /// this will loop through the columns
		{
			matrix_Ptr[i][j] = data_ptr[counter++];  /// it will populate the  matrix _Ptr from 1 d array to a 2 d array.

		}

	}
	//std::cout << "matrix has been populated" << std::endl;

}
/// this makes a copy of the matrix 
Baseimage::Baseimage(const Baseimage& copyMatrix)
{
	M = copyMatrix.getM(); /// the M will get the matrix original N size
	N = copyMatrix.getN();

	matrix_Ptr = new double*[M];
	for (int i = 0; i < M; ++i)
	{
		matrix_Ptr[i] = new double[N];    /// this will create space for the 2 d array 
	}
	for (int i = 0; i < M; i++)
	{

		for (int j = 0; j < N; j++)
		{
			/// this will use deep copy to copy the matrix 
			matrix_Ptr[i][j] = copyMatrix.get(i, j); /// this will get the copy data from the original matrix  and will make the new one
		}
	}
	std::cout << "check" << std::endl;
}
double Baseimage::get(int k, int j) const /// this value will be passed by constant value
{
	//std::cout << "its working" << std::endl;
	return matrix_Ptr[k][j];


}

//double** Baseimage::getBlock(int sRow, int eRow, int sColumn, int eColumn) // this will allow me to return a section of the matrix 
//{
//	int Row = eRow - sRow; /// this will take the endrow  and subtract the strat row so we can find the size of the no of the row
//	int Column = eColumn - sColumn; /// this will calculate the number of columns
//	double ** block = new double*[Row + 1]; /// we create a new pointer that will take the size of the rows and columns
//	for (int i = 0; i < Row; i++)
//	{
//		block[i] = new double[Column + 1]; /// 
//
//	}
//	for (int i = sRow; i < eRow; i++) // loops through the start row and end row
//	{
//		for (int j = sColumn; j< eColumn; j++) /// loops through the start colum and end column 
//		{
//
//
//			block[i - sRow][j - sColumn] = matrix_Ptr[i][j];
//
//		}
//	}
//	/// will return the blocks and row/ colums 
//
//	return block;
//}

int Baseimage::getM() const
{
	return M;
}
int Baseimage::getN()const
{
	return N;

}

double* Baseimage::getData()
{
	return data_ptr;
}
double Baseimage::getMatrix(int row , int column) /// this will allow me to access the pointer to pointer on inheritence
{
	return matrix_Ptr[row][column];
}
double** Baseimage::returnMatrix(int rows, int column)
{
	double** temp = new double*[rows];
	for (int i = 0; i < rows; i++) {
		temp[i] = new double[column];
		for (int j = 0; j < column; j++) { temp[i][j] = matrix_Ptr[i][j]; }  
	}
	return temp;
}
void Baseimage::set(int i, int j, double&val)  /// this value will  be passed by refrence
{
	matrix_Ptr[i][j] = val;

}
void Baseimage::out()
{

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cout << matrix_Ptr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
int Baseimage::sum()
{
	 int total = 0.0;
	for (int i = 0; i <M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			total = total + matrix_Ptr[i][j];
		}
	}
	return total;
}


 Baseimage::~Baseimage()
{
	for (int i = 0; i < M; i++)
	{


		delete[]  matrix_Ptr[i];
		
	}
	delete[] matrix_Ptr;
	delete[] data_ptr;
}
