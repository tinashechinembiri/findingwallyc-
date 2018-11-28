#include "stdafx.h"
#include "Matchimage.h"
#include<vector>




Matchimage::Matchimage()
{
}
Matchimage::Matchimage(int sizeX, int sizeY, double val):Baseimage( sizeX,  sizeY, val)
{
	



}
Matchimage::Matchimage(const Matchimage& name)
{
	M = name.getM(); /// the M will get the matrix original N size
	N = name.getN();

	matrix_Ptr = new double*[M];
	for (int i = 0; i < M; ++i)
	{
		matrix_Ptr[i] = new double[N];    /// this will create space for the 2 d array 
	}
	for (int i = 0; i < M; i++)
	{

		for (int j = 0; j < N; j++)
		{
			matrix_Ptr[i][j] = name.get(i, j); /// this will get the copy data from the original matrix  and will make the new one
		}
	}
}
Matchimage*Matchimage::operator*(const Matchimage& other)/// operator overload used the example of lecture 6 about 
{
//	std::cout << "operator overload *" << std::endl;
	Matchimage* temp = new Matchimage;
	temp->M = other.getM();
	temp->N = other.getN();

	temp->matrix_Ptr = new double*[temp->M];

	for (int k = 0; k < temp->M; k++)
	{
		temp->matrix_Ptr[k] = new double[temp->N];
	}

	for (int x = 0; x< temp->M; x++)
	{
		for (int j = 0; j < temp->N; j++)
		{

			temp->matrix_Ptr[x][j] = this->matrix_Ptr[x][j] * other.matrix_Ptr[x][j];

		}


	}
	return temp;

}



//Matchimage *Matchimage::operator >(const Matchimage& other)
//{
//	std::cout << "operator overload = " << std::endl;
//	//reserve memory for new array
//	M = other.M;
//		N = other.N;
//	matrix_Ptr = new double*[M];
//	for (int i = 0; i < M; i++)
//	{
//		matrix_Ptr[i] = new double[N];
//
//	}
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			matrix_Ptr[i][j] > other.matrix_Ptr[i][j];
//		}
//	}
//	
//	return matrix_Ptr;
//}
Matchimage::operator double()
{
	return bestscore;
}

Matchimage *Matchimage::operator=(const Matchimage& other)
{
	//std::cout << "operator overload = " << std::endl;
	Matchimage* temp = new Matchimage;
	temp->M = other.getM();
	temp->N = other.getN();

	temp->matrix_Ptr = new double*[temp->M];
	for (int k = 0; k < temp->M; k++)
	{
		temp->matrix_Ptr[k] = new double[temp->N];
	}
	for (int x = 0; x < temp->M; x++)
	{
		for (int j = 0; j < temp->N; j++)
		{
		

			temp->matrix_Ptr[x][j] = other.matrix_Ptr[x][j];

		}
	}
	return temp;
}
Matchimage *Matchimage::operator+(const Matchimage& other)
{
	//std::cout << "operator + overload" << std::endl;
	Matchimage* temp = new Matchimage;
	temp->M = other.getM(); /// get the M  from base class
	temp->N = other.getN();/// gets the N from the base class

	temp->matrix_Ptr = new double*[temp->M];  /// it will make  space for the 2d array 

	for (int k = 0; k < temp->M; k++)
	{
		temp->matrix_Ptr[k] = new double[temp->N]; /// creates space for the columns 
	}

	for (int x = 0; x< temp->M; x++)
	{
		for (int j = 0; j < temp->N; j++)
		{

			temp->matrix_Ptr[x][j] = this->matrix_Ptr[x][j] + other.matrix_Ptr[x][j];

		}


	}
	return temp;
}
Matchimage *Matchimage:: operator-(const Matchimage& other ) /// this will allow me to to subtract object of the images 
{
	//std::cout<< "operator - overload"<<std::endl;
	Matchimage* temp = new Matchimage;
	temp->M = other.getM(); /// get the M  from base class
	temp->N = other.getN();/// gets the N from the base class

	temp->matrix_Ptr = new double*[temp->M];  /// it will make  space for the 2d array 

	for (int k = 0; k < temp->M; k++)
	{
		temp->matrix_Ptr[k] = new double[temp->N]; /// creates space for the columns 
	}

	for (int x =0; x< temp->M; x++ )
	{
		for (int j =0; j < temp->N; j++)
		{
			
			temp->matrix_Ptr[x][j] = this->matrix_Ptr[x][j] - other.matrix_Ptr[x][j];

		}


	}
	return temp;
}
void Matchimage::score(long int  ssd_)
{
	nearestScore = ssd_; 
}
int Matchimage::returnScore()
{
	return nearestScore;
}
Matchimage::Matchimage(int sizeX, int sizeY, double*value_Data):Baseimage(sizeX,sizeY,value_Data)
{
	
}
Matchimage::Matchimage(int sizeX, int sizeY, double** input_data)
{
	M = sizeX;
	N = sizeY;
	matrix_Ptr = new double*[sizeX];
	for (int i = 0; i < sizeX; i++)
	{
		matrix_Ptr[i] = new double[sizeY];

	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix_Ptr[i][j]= input_data[i][j];
		}
	}
}
void Matchimage::lookForcords(int xcord, int ycords)
{
	xcord = xcord;
	int rowcord = xcord + 49;
	ycords = ycords;
	int colcord = ycords + 36;
}

Matchimage::~Matchimage()
{
	
	
}
