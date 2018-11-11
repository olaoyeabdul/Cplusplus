//*****************************************
//name: Abdulsalam Olaoye			     **
//date: 10-24-2016					     **
//lab: Lab 17						     **
//summary: Using pointers for state data **
//*****************************************

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>


using namespace std;

//******************
//opening ofs file**
//******************

ofstream ofs("Olaoye_Lab17.txt");

//*****************
//Global Variables*
//*****************

string name = "Abdulsalam Olaoye";
string course = "CIS 2541 - 004";
string date = "10-24-2016";
string lab = "Lab 17";
string summary = "Creating Pointers which points to address of variable name";
string eofmsg = "EOF message: ";
string sp = " ";
string sp3 = "   ";
string lines = "-------------------------------------------------------------|";
string left_brace = "{";
string right_brace = "}";
string bar = "|";
string enter = "Enter Capital, State (Capital,state) :";
string sp10 = "          ";
string zero = "0";
string dot = ".";

//******************
//*header function**
//******************
void hdr()
{
	ofs << lines << endl;
	ofs << name << sp;
	ofs << course << sp;
	ofs << date << sp;
	ofs << lab << setw(12) << bar << endl;
	ofs << lines << endl;
}


//******************
//*footer function**
//******************
void ftr()
{

	ofs << summary << setw(4) << bar << endl;
}


//************************
//**end of file function**
//************************
void eof()
{
	hdr();
}



// This function extracts and return state name
char *getstate(char *p)
{
	while (*p != ',')
		p++;
	
	return(p + 1);
}

void getinput()
{
	char  *s;
	char info[50];

	for (int k = 1; k <= 20; k++)
	{
		cout << enter;
		cin >> info;
		s = getstate(info);  
		if (k < 10)
		{
			ofs << zero;
		}
		ofs << (k) << dot << sp3 << info << sp10 << s << endl;
		ofs << lines << endl;

	}

}

int main()
{
	//***************
	//*header output*
	//***************
	hdr();

	//**************
	// input output*
	//**************
	getinput();


	//***************
	//*footer output*
	//***************
	ftr();


	//********************
	//*end of file output*
	//********************
	eof();


	//********************
	//**closing ofs file**
	//********************
	ofs.close();




}


    