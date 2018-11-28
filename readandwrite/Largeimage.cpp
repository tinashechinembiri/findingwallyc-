#include "stdafx.h"
#include "Largeimage.h"
#include"Matchimage.h"
#include <vector>
#include <iostream>


Largeimage::Largeimage()
{

}
Largeimage::Largeimage(int sizeX, int sizeY, double val) :Baseimage(sizeX, sizeY, val)
{
	
}
Largeimage::Largeimage(int sizeX, int sizeY, double*value_Data):Baseimage(sizeX, sizeY, value_Data)
{


}
Matchimage* Largeimage::returnVar(int size)
{
	return ssd_Vector[size];  /// it returns the  image of nns score 
}

void Largeimage::ssd(int xcord, int ycords,  Baseimage* base1, Largeimage* large1, int row, int column)
{

	Largeimage *clutterdScene = large1;
	//double* getVector;
	Matchimage* results = new Matchimage();/// this is a  matchimage object that will  the the sum
	//Matchimage* results = new Matchimage();
	long int total = 0 ; /// this is int to get the total of ssd 
	long int closest = 1;

	
	
	
	

	int i; 
	int j; 
	
	//wallyimage.getMatrix(row, column)
	/// the application allows me to call int by using block1.name(int)
	double* compareImage = clutterdScene->getData();
	
	for (i = 0; i < 420 ; i+=24)
	{
		for ( j = 0; j <420 ; j+=18)
		{
			Matchimage* name = new Matchimage(i, j, compareImage);
			Baseimage *wallyimage = base1;

			Matchimage block1(49, 36, wallyimage->returnMatrix(49, 36)); // this object will return the wally image 

				
				double** thing = clutterdScene->getBlock(i, (i + 49), j, (j + 36));/// this function allows me to get cluttered scene data from large image 
				Matchimage block2(49, 36, thing); ///  we created an object that will allow us to use object overloading 
				delete thing;

				Matchimage* diff = block2 - block1; /// we use object overloading to  subtract cluttered image with wally 
				Matchimage* results = new Matchimage(); /// we create an empty object to hold the result
				results = *diff * * diff;/// we square the results 
			//	results = *results + *diff; /// we sum the result
				total = results->sum();/// we sum the result and convert a object to a double 
			//	std::cout << total << "\t";
				
				name->score(total); /// we use the match image function to send the result to match image
				name->lookForcords(xcord, ycords);
				ssd_Vector.push_back(name); /// struct vector
		}
	}
	



			
	

	


}

double** Largeimage::getBlock(int sRow, int eRow, int sColumn, int eColumn) // this will allow me to return a section of the matrix 
{
	int Row = eRow - sRow; /// this will take the endrow  and subtract the strat row so we can find the size of the no of the row
	int Column = eColumn - sColumn; /// this will calculate the number of columns
	double ** block = new double*[Row+1]; /// we create a new pointer that will take the size of the rows and columns
	for (int i = 0; i < Row; i++)
	{
		block[i] = new double[Column+1]; /// 

	}
	for (int i = sRow; i < eRow; i++) // loops through the start row and end row
	{
		for (int j = sColumn; j< eColumn; j++) /// loops through the start colum and end column 
		{


			block[i - sRow][j - sColumn] = matrix_Ptr[i][j]; // the get block data will be sent to the block 

		}
	}
	
	/// will return the blocks and row/ colums 
	
	return block; // returns the block of cluttered scene 

}
void Largeimage::bubbleSort()
{
	for (int x = 0; x < ssd_Vector.size(); x++)
	{
		for (int j = 0; j < ssd_Vector.size() - 1; j++)
		{
			Matchimage* firstSwap = ssd_Vector[j];
			Matchimage* secondSwap = ssd_Vector[j + 1];
			if ( firstSwap->returnScore() > secondSwap->returnScore())
			{
				Matchimage* num = firstSwap ;
				firstSwap = secondSwap;
				secondSwap = num; 

			}
		}
	}
}
Largeimage::Largeimage(const Largeimage& copyMatrix)
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
			matrix_Ptr[i][j] = copyMatrix.get(i, j); /// this will get the copy data from the original matrix  and will make the new one
		}
	}
	std::cout << "check for the large image " << std::endl;
}



Largeimage::~Largeimage()
{
	
	
}
