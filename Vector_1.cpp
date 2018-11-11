//*******************************************
//name: Abdulsalam Olaoye		    *
//date: 10-2-2016					        *
//lab: Lab 13						        *
//summary: Vectors          		    	*
//*******************************************

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//******************
//opening ofs file**
//******************

ofstream ofs("Olaoye_Lab13.txt");

//*****************
//Global Variables*
//*****************

string name = "Abdulsalam Olaoye";
string course = "CIS 2541 - 004";
string date = "10-02-2016";
string lab = "Lab_13";
string summary = "Demonstrate accumulate of vector elements";
string eofmsg = "EOF message: ";
string sp = " ";
string Unsortedtitle = "Vector unsorted: ";
string sortedtitle = "Vector sorted: ";
string Vector1 = "Vector #1: ";
string Vector2 = "Vector #2: ";
string Vector3 = "Vector #3: ";
string lines = "-----------------------------------------------------------|";
string left_brace = "{";
string right_brace = "}";
string accum = "The accumulate of the vector is: ";
string accum1 = "Vector #1 Accumulated: ";
string accum2 = "Vector #2 Accumulated: ";
string accum3 = "Vector #3 Accumulated: ";
string total = "Accumulate of vectors #1 & #2:";
string bar = "|";

//****************************
//**Create and name vectors  *
//****************************
vector<int> VectorRandm_1(20);
vector<int> VectorRandm_2(20);
vector<int> Vector_3(20);

//**************************************
//**Create and name counter variables  *
//**************************************

int c;
int index = 0;
int d;
int k;


//******************
//*header function**
//******************
void hdr()
{
	ofs << lines << endl;
	ofs << name << sp;
	ofs << course << sp;
	ofs << date << sp;
	ofs << lab << setw(10) << bar << endl;
	
}

//******************
//*footer function**
//******************

void ftr()
{
	ofs << lines << endl;
	ofs << summary << setw(19) << bar << endl;
	
}

//************************
//**end of file function**
//************************
void eof()
{
	ofs << lines << endl;
	ofs << name << sp;
	ofs << course << sp;
	ofs << date << sp;
	ofs << lab << setw(10) << bar << endl;
	ofs << lines << endl;

}

//*********************************************************
//**Create vectors #1, #2, #3 and assign numbers function *
//*********************************************************
void vectors()
{
	ofs << lines << endl;
	ofs << Vector1 << setw(49) << bar << endl;
	ofs << lines;

	//***************************************************
	//**Create vector#1 elements, assign random numbers**
	//***************************************************

	 index = 0;
	 
	for (c = 0; c < VectorRandm_1.size(); c++)
	{
		VectorRandm_1[c] = (rand() % (1 - 99 + 1)) + 1;

		if (index % 10 == 0)
			ofs << endl;
		index++;
		
		ofs << setw(5) << VectorRandm_1[c] << bar;
	}
	ofs << endl;


	ofs << lines << endl;
	ofs << Vector2 << setw(49) << bar << endl;
	ofs << lines;

	//***************************************************
	//**Create vector#2 elements, assign random numbers**
	//***************************************************

	index = 0;

	for(d = 0; d < VectorRandm_2.size(); d++)
	{
		VectorRandm_2[d] = (rand() % (1 - 99 + 1)) + 1;

		if (index % 10 == 0)
			ofs << endl;
		index++;

		ofs << setw(5) << VectorRandm_2[d] << bar;
	}
	ofs << endl;


	

	ofs << lines << endl;
	ofs << Vector3 << setw(49) << bar << endl;
	ofs << lines;

	//******************************************************
	//**Create vector#3 elements by adding vectors 1 and 2**
	//******************************************************

	index = 0;
	for (k = 0; k < Vector_3.size(); k++)
	{
		Vector_3[k] = VectorRandm_1[k] + VectorRandm_2[k];

		if (index % 10 == 0)
			ofs << endl;
		index++;

		ofs << setw(5) << Vector_3[k] << bar;
	}

	ofs << endl;

}

//****************************************************************
//**Accumulate vectors #1, #2, and #3,assigned numbers function  *
//****************************************************************
void Accum_vectors()
{
	ofs << lines << endl;
	ofs << accum1 << setw(9) << left_brace;

	ofs << accumulate(VectorRandm_1.begin(), VectorRandm_1.end(), 0.0) << right_brace << setw(24) << bar << endl;
	
	

	ofs << lines << endl;
	ofs << accum2 << setw(9) << left_brace;

	ofs << accumulate(VectorRandm_2.begin(), VectorRandm_2.end(), 0.0) << right_brace << setw(24) << bar << endl;
	
	

	ofs << lines << endl;
	ofs << accum3 << setw(8) << left_brace;

	ofs << accumulate(Vector_3.begin(), Vector_3.end(), 0.0) << right_brace << setw(24) << bar << endl;
	
	


	ofs << lines << endl;
	ofs << total << left_brace;

	ofs << accumulate(VectorRandm_1.begin(), VectorRandm_1.end(), 0.0) +
		accumulate(VectorRandm_2.begin(), VectorRandm_2.end(), 0.0) << right_brace << setw(24) << bar << endl;
	
	


}


int main()
{
	//***************
	//*header output*
	//***************

	hdr();
	

	//**********************
	//Vectors content output*
	//**********************

	vectors();
	


	//************************************
	//Accumulated Vectors content output *
	//************************************

	Accum_vectors();
	


	//***************
	//*footer output*
	//***************

	ftr();
	

	//********************
	//*end of file output*
	//********************

	eof();
	ofs << endl;

	//********************
	//**closing ofs file**
	//********************

	ofs.close();


	return 0;
}
