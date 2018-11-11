//*******************************************
//name: Abdulsalam Olaoye			        *
//date: 9-19-2016					        *
//lab: Lab 10						        *
//summary: Array/Alignment area pararmeter	*
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

ofstream ofs("olaoye_lab10.txt");

//*****************
//Global Variables*
//*****************

string name = "Abdulsalam olaoye";
string course = "CIS 2541 - 004";
string date = "09-19-2016";
string lab = "lab10";
string summary = "Array/Alignment area Parameter";
string eofmsg = "EOF message: ";
string sp = " ";
string Unsortedtitle = "Array unsorted: ";
string sortedtitle = "Array sorted with each occurrence :  ";
string lines = "----------------------------------------------------------------------";

int A[10];
int B[10];
int amount = 10;

int element;
int index;
bool assign;
bool dupe;

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

//************************
//*UnsortedArray function*
//************************

void Array()
{
	ofs << lines << endl;
	ofs << Unsortedtitle;
	for (element = 0; element < 10; element++)
	{
		A[element] = (rand() % (1 - 10 + 1)) + 1;

		ofs << setw(5) << A[element];
	}
	ofs << endl;
	ofs << lines << endl;
}

//**********************
//*sortedArray function*
//**********************
void Arraysorted(int A[], int element)

{
	ofs << lines << endl;
	ofs << sortedtitle << endl;
	ofs << lines << endl;


	int temp;
	bool sort;

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
				for (element = 0; element < 10; element++)

					ofs << setw(5) << A[element];
				ofs << endl;
				ofs << lines << endl;

				

					sort = true;

			}
		}



	} while (sort);

		ofs << endl;
}

void No_Dup(int A[])
{	
	int c;


	ofs << "nodup" << endl;


		for (c = 0; c < 10; c++)
		{
		do
		{
			if (A[c] == A[c + 1])
			{
				A[c] = (rand() % (1 - 10 + 1)) + 1;
			} 
			
			
				ofs << A[c] << endl;
			
		} while (A[c] == A[c + 1]);
		} 

		
}

void remove_Dupe(int A[], int amount)
{
	ofs << "here:" << endl;

	int prev = 0;
	int c = 0;

	for (prev = 0; prev < 10; prev++ )
	{
		for (c = 0; c < 10; c++ )
		{
			while (prev < c)
			{
				if (A[prev] == A[c])
					prev++;
				else
				{
					A[prev] = A[c];
					prev++; c++;

				}
			}
		}

	}
	for (int i = 0; i < prev; i++)
		ofs << A[i] << endl;



	

	ofs << endl;
	ofs << lines << endl;
	ofs << endl;

	//print and sort

	int temp;
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < (element - 1); count++)
		{

			if (A[count] > A[count + 1])
			{
				ofs << "{";

				temp = A[count];
				A[count] = A[count + 1];
				for (int d = 0; d < 10; d++)
				{
					ofs << setw(3) << A[d] << sp;

				}
				ofs << "}";
				ofs << endl;
				A[count + 1] = temp;
				swap = true;


			}

		}

	} while (swap);

	for (int i = 0; i < 10; i++)
	{
		ofs << A[i] << sp;
	}
}


int main()
{
	//***************
	//*header output*
	//***************

	hdr();
	ofs << " ";
	ofs << endl;

	//*************************
	//**Array unsorted output**
	//*************************

	Array();
	ofs << endl;


	//***********************
	//**Array sorted output**
	//***********************
	//Arraysorted(A, element);
	//ofs << endl;


	No_Dup(A);
	ofs << endl;


	//remove_Dupe(A, element);
	//ofs << endl;


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