#pragma once
class Baseimage
{
public:
	Baseimage();
	~Baseimage();
	Baseimage(int sizeX, int sizeY,double val);
	Baseimage(int sizeX, int sizeY, double*value_Data); // constructor  for a pointer 
	double** getPointermatrix(int sizeX, int sizeY); /// this will allow me to generate the matrix for the 2d array
	void populateMatrix();
	int sum();
	int getM() const; /// allows me to get row
	int getN() const; /// allows me to get the column 
	double*getData();
	double getMatrix(int row , int column);/// returns the value of the pointer to pointer matrix 
	void set(int i, int j, double&val); /// 
	/*double** getBlock(int sRow, int eRow, int sColumn, int eColumn);*/
	Baseimage(const Baseimage& copyMatrix);
	double get(int k, int j) const;

	double** returnMatrix(int rows, int column); /// returns the pointer to pointer matrix 
	void out();
	
	
protected:
	
	int M; /// rows
	int N; /// column
	double* data_ptr; // holds in the 1 d array 
	double ** matrix_Ptr; /// holds in the 2 d array
private : 
	 

	

};

