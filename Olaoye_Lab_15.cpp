//*************************************
//name: Abdulsalam Olaoye			 **
//date: 10-3-2016					 **
//lab: Lab 15						 **
//summary: Menu-driven Vector program**
//*************************************

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

ofstream ofs("Olaoye_Lab15.txt");

//*****************
//Global Variables*
//*****************

string name = "Abdulsalam olaoye";
string course = "CIS 2541 - 004";
string date = "10-3-2016";
string lab = "Lab 15";
string summary = "Menu-driven Vector program";
string eofmsg = "EOF message: ";
string sp = " ";
string Unsortedtitle = "Vector unsorted : ";
string sortedtitle = "Vector sorted   : ";
string Unsortedinput = "Unsorted Input : ";
string Sortedinput = "Sorted Input   : ";
string lines = "-------------------------------------------------------------|";
string left_brace = "{";
string right_brace = "}";
string bar = "|";
string show = "Here are your inputs : ";

int choice;

//****************************
//*Constants for menu choices*
//****************************
const int  Input_1 = 1,
		   Printinput_2 = 2,
		   SortInput_3 = 3,
		   PrintSorted_4= 4,
		   Quit = 5;

//********************************************
//*Declaration of Vector and count variables *
//********************************************

vector<int> input(5);

int element;
int index;
int Count = 0;

//***********************************************
//*Initializing Arrays used for ASCII characters*
//***********************************************
 string menu[25] = {"  _     _____       _                         _                  ",
	                " / |_  | ____|_ __ | |_ ___ _ __  __   ____ _| |_   _  ___  ___  ",
	                " | (_) |  _| | '_ L| __/ _ L '__| L L / / _` | | | | |/ _ L/ __| ",
					" | |_  | |___| | | | ||  __/ |     L V / (_| | | |_| |  __/L__ L ",
					" |_(_) |_____|_| |_|L__L___|_|      L_/ L__,_|_|L__,_|L___||___/ ",
					"   ____      ____       _       _     _                                    _      ",
					" |___ L _  |  _ L _ __(_)_ __ | |_  | |_ ___     ___ ___  _ __  ___  ___ | | ___ ",
					"   __) (_) | |_) | '__| | '_ L| __| | __/ _ L   / __/ _ L| '_ L/ __|/ _ L| |/ _ L ",
					"  / __/ _  |  __/| |  | | | | | |_  | || (_) | | (_| (_) | | | L__ L (_) | |  __/",
					" |_____(_) |_|   |_|  |_|_| |_|L__|  L__L___/   L___L___/|_| |_|___/L___/|_|L___|",
					"  _____    ____             _   ",
					" |___ /_  / ___|  ___  _ __| |_ ",
					"   |_ (_) L___ L / _ L| '__| __|",
					"  ___) |   ___) | (_) | |  | |_ ",
					" |____(_) |____/ L___/|_|   L__|",
					"  _  _      ____       _       _     _          _            _      __ _ _      ",
					" | || | _  |  _ L _ __(_)_ __ | |_  | |_ ___   | |_ _____  _| |_   / _(_) | ___ ",
					" | || |(_) | |_) | '__| | '_ L| __| | __/ _ L  | __/ _ L L/ / __| | |_| | |/ _ L",
					" |__   _|  |  __/| |  | | | | | |_  | || (_) | | ||  __/>  <| |_  |  _| | |  __/",
					"    |_|(_) |_|   |_|  |_|_| |_|L__|  L__L___/   L__L___/_/L_LL__| |_| |_|_|L___|",
					"  ____      ___        _ _   ",
					" | ___|_   / _ L _   _(_) |_ ",
					" |___ (_) | | | | | | | | __|",
					"  ___) |  | |_| | |_| | | |_ ",
					" |____(_)  L__L_LL__,_|_|L__|",};

 string Inputmessage[4] = {

	 " ___     _             ___                  _                ",
	 "| __|_ _| |_ ___ _ _  | __|  _ _ _  _ _ __ | |__  ___ _ _ ___",
	 "| _|| ' L  _/ -_) '_| |__ L | ' L || | '  L| '_ LL -_) '_(_-<",
	 "|___|_||_L__L___|_|   |___/ |_||_L_,_|_|_|_|_.__/L___|_| L__/", };

 string Validate[4] = {

	 "  __     _            __   __    _ _    _    ___ _        _        ",
	 "| __|_ _| |_ ___ _ _  L L / /_ _| (_)__| |  / __| |_  ___(_)__ ___ ",
	 "| _|| ' L  _/ -_) '_|  L V / _` | | / _` | | (__| ' L/ _ L / _/ -_)",
	 "|___|_||_L__L___|_|     L_/L__,_|_|_L__,_|  L___|_||_L___/_L__L___|",
 };

 string show_2[5] = {
	 " _  _                              _   _          _                _        _ ",
	 "| || |___ _ _ ___   __ _ _ _ ___  | |_| |_  ___  (_)_ _  _ __ _  _| |_ ___ (_)",
	 "| __ / -_) '_/ -_) / _` | '_/ -_) |  _| ' L/ -_) | | ' L| '_ L || |  _(_-<  _ ",
	 "|_||_L___|_| L___| L__,_|_| L___|  L__|_||_L___| |_|_||_| .__/L_,_|L__/__/ (_)",
	 "                                                        |_|                   ",};

//******************
//*header function**
//******************
void hdr()
{
	ofs << lines << endl;
	ofs << name << sp;
	ofs << course << sp;
	ofs << date << sp;
	ofs << lab << setw(13) << bar << endl;
	ofs << lines << endl;
}


//******************
//*footer function**
//******************
void ftr()
{
	
	ofs << summary << setw (36) << bar << endl;
}


//************************
//**end of file function**
//************************
void eof()
{
	hdr();
}


//***********************
//*Input Number function*
//***********************
void Input()
{

	for (Count = 0; Count < 4; Count++)
	{
		cout << Inputmessage[Count] << endl;
	}


	for (index = 0; index < input.size(); index++)
	{
		cin >> input[index];
	}
		
}


//**********************
//*sort Input function**
//**********************
void SortInput()
{
	sort(input.begin(), input.end());
}


//******************************
//*Show input message function**
//*****************************
void Show()
{
	for (Count = 0; Count < 5; Count++)
	{
		cout << show_2[Count] << endl;
	}
}


//*********************************
//*Print Input to console function*
//*********************************
void Printinput(vector<int> input,int index)
{
	Show();

	for (index = 0; index < input.size(); index++)
	{
		cout << setw(7) << input[index];
		
	}
	cout << endl;
}


//******************************
//*Print Input to file function*
//******************************
void PrintSorted() 
{
	ofs << Sortedinput;

	SortInput();

	for (element = 0; element < input.size(); element++)
	{
		ofs << setw(8) << input[element] << bar;
	}
	
	ofs << endl << lines << endl;
}


//***********************
//*Menu content function*
//***********************
void showMenu()
{
	for (Count = 0; Count < 25; Count++)

		cout << menu[Count] << endl;


}


//***************************
//*Input validation function*
//***************************
void EnterValidChoice()
{

	for (Count = 0; Count < 4; Count++)
	{
		cout << Validate[Count] << endl;
	}


}


//**********************
//*Menu choice function*
//**********************
void MenuChoice()
{
	do
	{
		showMenu();
		cin >> choice;

		while (choice < Input_1 || choice > Quit)
		{
			EnterValidChoice();
			cin >> choice;
		}

		if (choice != Quit)
		{
			switch (choice)
			{
			
			case Input_1:
				Input();
				break;
			case Printinput_2:
				Printinput(input, index);
				break;
			case SortInput_3:
				SortInput();
				break;
			case PrintSorted_4:
				PrintSorted();
				break;

			}

		}
	} while (choice != Quit);
}


//***************
//*Main function*
//***************
int main()
{
	//***************
	//*header output*
	//***************
	hdr();


	//********************
	//*menu function call*
	//********************
	MenuChoice();


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


