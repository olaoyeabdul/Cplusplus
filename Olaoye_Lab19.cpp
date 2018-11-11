//****************************************************
//name: Abdulsalam Olaoye			                **
//date: 10-31-2016					                **
//lab: Lab 19						                **
//summary: Creating and writing from an output file **
//****************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

//******************
//opening  files  **
//******************
ifstream ifs("Olaoye_Lab18.txt");
ofstream ofs("Olaoye_Lab19.txt");

//*****************
//Global Variables*
//*****************

string name = "Abdulsalam Olaoye";
string course = "CIS 2541 - 004";
string date = "10-31-2016";
string lab = "Lab 19";
string summary = "Creating and writing test scores from an output file";
string eofmsg = "EOF message: ";
string sp = " ";
string sp3 = "   ";
string lines = "-------------------------------------------------------------|";
string left_brace = "{";
string right_brace = "}";
string bar = "|";
string maxi = "Maximum score: ";
string mini = "Minimum score: ";
string average = "Average score: ";
string total = "Total score: ";
string zero = "0";
string dot = "." ;

vector<int> marks(26);

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

	ofs << summary << setw(10) << bar << endl;
}


//************************
//**end of file function**
//************************
void eof()
{
	hdr();
}


//******************************
//**vector activities function**
//******************************
void labfunction()
{
	for (int c = 0; c < 26; c++)
	{
		ifs >> marks[c];

		if ((c + 1) < 10) 
		{
			ofs << zero;
		}
		ofs << (c + 1) << dot << setw(7) << marks[c] << setw(52) << bar << endl;
		ofs << lines << endl;
	}

	ofs << maxi << *max_element(marks.begin(), marks.end()) << setw(44) << bar << endl;
	ofs << lines << endl;

	ofs << mini << *min_element(marks.begin(), marks.end()) << setw(46) << bar << endl;
	ofs << lines << endl;

	ofs << average << accumulate(marks.begin(), marks.end(), 0.0) / marks.size() << setw(40) << bar << endl;
	ofs << lines << endl;

	ofs << total << setw (5) << accumulate(marks.begin(), marks.end(), 0.0) << setw(44) << bar << endl;
	ofs << lines << endl;
	


}


//*******************************
// Main function of the program**
//*******************************
int main()
{
	//***************
	//*header output*
	//***************
	hdr();

	//**************
	// input output*
	//**************
	labfunction();


	//***************
	//*footer output*
	//***************
	ftr();


	//********************
	//*end of file output*
	//********************
	eof();


	//********************
	//**closing ifs file**
	//********************
	ifs.close();


	//********************
	//**closing ofs file**
	//********************
	ofs.close();

	


}
