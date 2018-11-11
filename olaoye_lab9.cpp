//*******************************************
//name: Abdulsalam Olaoye			        *
//date: 9-25-2016					        *
//lab: Lab 9						        *
//summary: Array comparison             	*
//*******************************************

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//******************
//opening ofs file**
//******************

ofstream ofs("olaoye_lab9.txt");

//*****************
//Global Variables*
//*****************

string name = "Abdulsalam Olaoye";
string course = "CIS 2541 - 004";
string date = "09-25-2016";
string lab = "lab_9";
string summary = "Array Comparison";
string eofmsg = "EOF message: ";
string sp = " ";
string Unsortedtitle = "Array #1 unsorted: ";
string sortedtitle = "Array #1 sorted with each occurrence :  ";
string sectitle = "Array #2 unsorted: ";
string sectitlesorted = "Array #2 sorted with each occurrence : ";
string lines = "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
string left_brace = "{";
string right_brace = "}";
string colon = ":";
string Num_found = "Numbers found in both arrays:";
string comma = ",";

//**************************************
//**Declaring Array types and variables*
//**************************************
int A[100];
int B[200];
int element;
int index;
int temp;
bool sort;
int num;
int SIZE;



//******************
//*header function**
//******************

void hdr()
{
	ofs << lines << endl;
	ofs << name << sp;
	ofs << course << sp;
	ofs << date << sp;
	ofs << lab << sp << endl;
	ofs << lines << endl;
}

//******************
//*footer function**
//******************

void ftr()
{
	ofs << lines << endl;
	ofs << summary << endl;
	ofs << lines << endl;
}
//************************
//**end of file function**
//************************

void eof()
{
	ofs << lines << endl;
	ofs << eofmsg << sp;
	ofs << name << sp;
	ofs << course << sp;
	ofs << date << sp;
	ofs << lab << sp << endl;
	ofs << lines << endl;

}

//***************************
//*Unsorted Array#1 function*
//***************************

void Array()
{
	ofs << lines <<lines << endl;
	ofs << Unsortedtitle << left_brace;
	for (element = 0; element < 100; element++)
	{
		A[element] = (rand() % (1 - 999 + 1)) + 1;

		ofs << setw(5) << A[element] << comma;
	}
	ofs <<right_brace << endl;
	ofs << lines << lines << endl;
}

//*************************
//*sort Array#1 function  *
//*************************
void Arraysorted(int A[],int element)

{
	ofs << lines << endl;
	ofs << sortedtitle << endl;
	ofs << lines << endl;

	//************************************************
	//**do-while loop for sorting elements in Array#1*
	//************************************************

	do
	{
		sort = false;
		for (int count = 0; count < (element - 1); count++)
		{

			if (A[count] > A[count + 1])
			{
				temp = A[count];
				A[count] = A[count + 1];
				A[count + 1] = temp;

				ofs << left_brace;

				//********************************************************************
				//**For-loop used for printing elements in Array#1 as they are sorted*
				//********************************************************************

				for (element = 0; element < 100; element++)

					ofs << setw(5) << A[element];
				ofs << right_brace << endl;
				ofs << lines << endl;



				sort = true;

			}
		}



	} while (sort);

	ofs << endl;
}

//***************************
//*Unsorted Array#2 function*
//***************************

void Sec_Array()
{
	ofs << lines << endl;
	ofs << sectitle << left_brace;

	for (index = 0; index < 200; index++)
	{
		B[index] = (rand() % (1 - 999 + 1)) + 1;

		ofs << setw(5) << B[index];
	}
	ofs << right_brace << endl;
	ofs << lines << endl;
}

//*************************
//*sort Array#2 function  *
//*************************

void Sec_Arraysorted(int B[], int index)

{
	ofs << lines << endl;
	ofs << sectitlesorted << endl;
	ofs << lines << lines << endl;

	//************************************************
	//**do-while loop for sorting elements in Array#2*
	//************************************************


	do
	{
		sort = false;
		for (int count = 0; count < (index - 1); count++)
		{
		
			if (B[count] > B[count + 1])
			{
				temp = B[count];
				B[count] = B[count + 1];
				B[count + 1] = temp;

				ofs << left_brace;


				//********************************************************************
				//**For-loop used for printing elements in Array#2 as they are sorted*
				//********************************************************************

				for (index = 0; index < 200; index++)

					ofs << setw(5) << B[index];
						ofs << right_brace << endl;
						ofs << lines << lines << endl;



				sort = true;

			}
		}



	} while (sort);

	ofs << endl;
}

//***************************************
//*Compare Both Arrays elements function*
//***************************************

void ArraysCompare()
{	
	ofs << lines << endl;
	ofs << Num_found << left_brace;



	for (element = 0; element < 100; element++)
	{
		SIZE = 0;

		for (index = 0; index < 200; index++)
		{
			if (A[element] == B[index])
			{
				num = A[element];

				SIZE++;

				ofs << setw(3) << num << colon << SIZE << comma << sp;
				

			}

		} 
	}
	ofs << right_brace << endl;
	ofs	<< lines << endl;
}

//*************************
//*Main function          *
//*************************
int main()
{
	//***************
	//*header output*
	//***************

	hdr();
	ofs << endl;

	//**************************
	//**Array#1 unsorted output*
	//**************************

	Array();
	ofs << endl;


	//************************
	//**Array#1 sorted output*
	//************************
	Arraysorted(A, element);
	ofs << endl;

	//**************************
	//**Array#2 unsorted output*
	//**************************
	Sec_Array();
	ofs << endl;

	//************************
	//**Array#2 sorted output*
	//************************
	Sec_Arraysorted(B, index);
	ofs << endl;

	//***************************
	//**Arrays comparison output*
	//***************************
	ArraysCompare();
	ofs << endl;

	//***************
	//*footer output*
	//***************

	ftr();
	ofs << endl;

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
