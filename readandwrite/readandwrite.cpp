// readandwrite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// readandwrite.cpp : Defines the entry point for the console application.
//

#include <sstream> // stringstream
#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <istream>
#include "Baseimage.h"
#include "Matchimage.h"
#include"Largeimage.h"
#include <vector>
#include <conio.h>

using namespace std;

// Input data are provided in .txt format and can be converted to .pgm files for visualization
// Download (free) ImageJ for plotting images in .pgm format
// http://rsb.info.nih.gov/ij/download.html

// Reads .txt file representing an image of R rows and C Columns stored in filename
// and converts it to a 1D array of doubles of size R*C
// Memory allocation is performed inside readTXT
double* readTXT(char *fileName, int sizeR, int sizeC);

// Converts a 1D array of doubles of size R*C to .pgm image of R rows and C Columns
// and stores .pgm in filename
// Use Q = 255 for greyscale images and Q=1 for binary images.
void WritePGM(char *filename, double *data, int sizeR, int sizeC, int Q);


int main()
{
	// This part will show you how to use the two functions.

	//M and N represent the number of rows and columns in the image,
	//e.g. Cluttered_scene, M = 768, N = 1024
	//e.g. Wally_grey, M = 49, N =  36
	int M = 768; int N = 1024;
	int m = 49; int n = 36;
	int row =0; int column =0; 
	// input_data is a pointer to a 1D array of M*N doubles stored in heap. Memory allocation is performed
	// inside readTXT. readTXT will read an image (in .pgm format) of size MxN and will  store the result in input_data.
	// once you're done with data DO NOT forget to delete the memory as in the end of this main() function
	double* input_data = 0;
	double* input_data2 = 0;

	double locationWally = 0.0;

	cout << endl;
	cout << "Data from text file -------------------------------------------" << endl;

	// .pgm image is stored in inputFileName, change the path in your program appropriately
	char* inputFileName = "Cluttered_scene.txt";
	input_data = readTXT(inputFileName, M, N);
	/// this will get wally_grey image , this will allow me to get wally  image through its size
	char* inputFileName2 = "Wally_grey.txt";
	input_data2 = readTXT(inputFileName2, m, n);
	///  separate this codes
	std::vector<Matchimage*> ssd_Vector;

	Baseimage* maths = new Baseimage(m, n, input_data2);
	maths-> populateMatrix();
	Matchimage name;

	
	
	//maths.out();
	
	//maths.out();
	Largeimage *obj = new Largeimage(M,N,input_data);
	obj -> populateMatrix();
	//obj.out();
	int counter = 1;

	/// make a nested for loop using the point 
	//for (int i = 0; i < 420; i +=49)
	//{
	//	for (int j = 0; j < 420; j +36)
	//	{

	//		obj->ssd(i, j,  maths, obj, 49, 36);

	//	}
	//}
	
	obj ->ssd(row, column, maths, obj, row, column); /// it will calle the large image ssd 
	
	obj->bubbleSort(); /// it will use bubble sort to sort the score in ascending orders 
	
	cout << counter << "first loop"<< endl;
//	cout << name.returnScore()<< "main\n";
	for (int i = 0; i < 3; i++) ///  it will loop three times to find the top[ score 
	{
		Matchimage* top = obj->returnVar(i); /// it will the vecors values 
		std::cout<< "ssd score :" << top->returnScore() <<"\t \n" <<std::endl; /// it will return the top three scores 
		ssd_Vector.push_back(top);/// 

	}

	//name
		int Q = 250;
		char* nameWally = "Bestmatch1.pgm";
		WritePGM(nameWally, ssd_Vector[0]->getData(), m, n,Q); /// writes the score to a pgm file 
		/*char * nameWally1 = "Bestmatch2.pgm";
		WritePGM(nameWally1, ssd_Vector[1]->getData(), m, n, Q); /// writes th file to pgm file 
		char * nameWally2 = "Bestmatch3.pgm";
		WritePGM(nameWally2, ssd_Vector[2]->getData(), m, n, Q); /// writes the file to a pgm file*/ 


	


  
	






	/*


	CODE TO PROCESS input_data SHOULD BE WRITTEN HERE!! (after removing the comments:)

	*/

	// writes data back to .pgm file stored in outputFileName
	char* outputFileName = "Clutered_scene.pgm";
	char* outputFileName1 = "Wally_grey.pgm"; 
	// Use Q = 255 for greyscale images and 1 for binary images.
	
	WritePGM(outputFileName, input_data, M, N, Q);
	WritePGM(outputFileName1, input_data2, m, n, Q);

	delete[] input_data;
	//delete[] obj;
//	delete []maths;
	delete[] input_data2;
	_getch();
	return 0;
}


// Read .txt file with image of size RxC, and convert to an array of doubles
double* readTXT(char *fileName, int sizeR, int sizeC)
{
	double* data = new double[sizeR*sizeC];
	int i = 0;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{

		while (myfile.good())
		{
			if (i>sizeR*sizeC - 1) break;
			myfile >> *(data + i);
			//   cout << *(data+i) << ' '; // This line display the converted data on the screen, you may comment it out.
			i++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	//cout << i;

	return data;
}

// convert data from double to .pgm stored in filename
void WritePGM(char *filename, double *data, int sizeR, int sizeC, int Q)
{

	int i, j;
	unsigned char *image;
	ofstream myfile;

	image = (unsigned char *) new unsigned char[sizeR*sizeC];

	// convert the integer values to unsigned char

	for (i = 0; i<sizeR*sizeC; i++)
		image[i] = (unsigned char)data[i];

	myfile.open(filename, ios::out | ios::binary | ios::trunc);

	if (!myfile) {
		cout << "Can't open file: " << filename << endl;
		exit(1);
	}

	myfile << "P5" << endl;
	myfile << sizeC << " " << sizeR << endl;
	myfile << Q << endl;

	myfile.write(reinterpret_cast<char *>(image), (sizeR*sizeC) * sizeof(unsigned char));

	if (myfile.fail()) {
		cout << "Can't write image " << filename << endl;
		exit(0);
	}

	myfile.close();

	delete[] image;

}

