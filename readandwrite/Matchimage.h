#pragma once
#include "Baseimage.h"

#include<vector>

class Matchimage: public Baseimage
{
public:
	Matchimage();
	Matchimage(int sizeX, int sizeY, double value_data);
	Matchimage(int, int, double*);
	Matchimage(int, int ,double**);

	Matchimage(const Matchimage& name);
	
	void score(long int ssd_);
	Matchimage* operator * (const Matchimage& other); /// this operation will allow the addition of the matrix  
	Matchimage* operator - (const Matchimage& other);/// this operation will allow the subtraction of the matrix
	Matchimage* operator = (const Matchimage& other);
	Matchimage* operator + (const Matchimage& other);
	int returnScore();
	void lookForcords(int cord1 ,int cord2); 
	//Matchimage* operator > (const Matchimage& other);
	operator double(); 
	~Matchimage();
protected:
	double bestscore;
	 

private:
 long int  nearestScore ;

	
};

