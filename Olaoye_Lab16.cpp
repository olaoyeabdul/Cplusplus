//*************************************
//name: Abdulsalam Olaoye			 **
//date: 10-24-2016					 **
//lab: Lab 16						 **
//summary: Pointers					 **
//*************************************

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>


using namespace std;

//******************
//opening ofs file**
//******************

ofstream ofs("Olaoye_Lab16.txt");

//*****************
//Global Variables*
//*****************

string name = "Abdulsalam Olaoye";
string course = "CIS 2541 - 004";
string date = "10-24-2016";
string lab = "Lab 16";
string summary = "Creating Pointers which points to address of variable name";
string eofmsg = "EOF message: ";
string sp = " ";
string lines = "-------------------------------------------------------------|";
string left_brace = "{";
string right_brace = "}";
string bar = "|";
string Showname = "Name Address: ";
string Showcourse = "Course Address: ";
string Showdate = "Date Address: ";
string Showlab = "Lab Address: ";
string Showsummary = "Summary Address: ";
string sp2 = "  ";

string *h;




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
	
	ofs << lines << endl << summary << setw(4) << bar << endl;
}


//************************
//**end of file function**
//************************
void eof()
{
	hdr();
}


//********************************************************************
//**Variable address function which uses pointers to display address**
//********************************************************************
void addressPoint()
{
	h = &name;
	
	ofs << Showname << sp2 << sp << h << setw(37) << bar << endl;
	ofs << lines << endl;

	h = &course;
	
	ofs << Showcourse << sp << h << setw(37) << bar << endl;
	ofs << lines << endl;

	h = &date;
	
	ofs << Showdate << sp2 << sp << h << setw(37) << bar << endl;
	ofs << lines << endl;

	h = &lab;
	
	ofs << Showlab << sp2  << sp2 << h << setw(37) << bar << endl;
	ofs << lines << endl;

	h = &summary;
	
	ofs << Showsummary << h << setw(37) << bar << endl;
	



}



//**************************
// Main Function		  **
//**************************
int main()
{
	//***************
	//*header output*
	//***************
	hdr();


	//****************
	//*pointer output*
	//****************
	addressPoint();


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


	return 0;



}