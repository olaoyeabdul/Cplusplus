//************************
//Name: Abdulsalam Olaoye*
//Date : 09-19-2016      *
//Lab : Lab 8            *
//Summary : Debug        *
//************************

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

int size[4];

string a[4];
string b[4];
string c[4];
string d[4];
string e[4];

//string a[4];
//string b[4];
//string d[4];
//string e[4];

//Global variables***

string no = "EoF Message";
string hard = "Billy Bob";
string labn = "Lab 8";
string header = "Debug";
string footer = "Printed input from console to output file stream - like a boss";


bool on;
int option;
string input;


string menuz1 = "please enter your first and last name";
string menuz2 = "please enter your course code";
string menuz3 = "please enter date of class, the time, and the room number";
string menuz4 = "Example 'Mon Tues Wed, 6:00-10:00PM 101";
string name = "Name:";
string course = "Course:";
string days = "Date:";
string timez = "Time:";
string room = "Room:";
string please = "Please choose from the following options:";
string one = "1. Input and print full name";
string two = "2. Input course codes";
string three = "3. Input date, time and room#";
string four = "4. Quit";

string how1 = "How many other pieces information?";
string how2 = "How many classes are you taking?";

int classes;
int Num;
int i;
ofstream ofs("Olaoye_Lab8.txt");


void hdr()
{ 
	ofs << labn <<  endl;
	ofs << setw(3) << left << header << endl;

	ofs << labn << endl;

}


void ftr()
{
	ofs << labn << endl;
	ofs << setw(3) << left << footer << endl;
	ofs << labn << endl;

}

void eof()
{
	ofs << labn << endl;
	ofs << setw(3) << left << no << endl;
	ofs << labn << endl;

}

void printArray(string z[], string y[], string x[], string w[], int size)

{
	ofs << labn << endl;
	ofs << setw(3) << left;
	ofs << setw(16) << left << name;
	ofs << setw(3) << left;
	ofs << setw(57) << left << input << name;
	ofs << endl;

	ofs << labn << endl;
	ofs << setw(3) << left;
	ofs << setw(16) << left << course;
	ofs << setw(3);
	ofs << setw(17) << days;
	ofs << setw(3) << left;
	ofs << setw(17) << left << timez;
	ofs << setw(3) << left;
	ofs << setw(17) << left << room;

	ofs << endl;
	ofs << labn << endl;

	for (i = 0; i < size; i++)

	{
		ofs << setw(3) << left;
		ofs << setw(16) << left << z[i];
		ofs << setw(3) << endl;
		ofs << setw(17) << left << y[i];
		ofs << setw(3) << left << endl;
		ofs << setw(17) << left << x[i];
		ofs << setw(3) << left << endl;
		ofs << setw(17) << left << w[i];

		ofs << endl;
		ofs << labn << endl;

	}
}
	
void output()
{

		on = true;
		while (on)
		{
			cin >> please;
			cout << endl;
			cout << endl;
			cout << one;
			cout << endl;
			cout << endl;
			cout << two;
			cout << endl;
			cout << endl;
			cout << three;
			cout << endl;
			cout << endl;
			cout << four;
			cout << endl;
			cout << endl;
			cin >> option;
			system("cls");

			switch (option)
			{
			case 1:
				cin.ignore();
				cout << menuz1;
				cout << endl;
				cin >> input >> name;
				system("cls");
				cout << how2 << endl;
				cin >> a[i];
				system("cls");

				break;


			case 2:
				for (i = 0; i < 4; i++)
				{
					cout << menuz2;
					cout << endl;
					cin >> a[i];
					system("cls");
				}

				break;

			case 3:
				for (i = 0; i < 4; i++)
				{
					cin.ignore();
					cout << menuz3;
					cout << endl;
					cout << menuz4;
					cout << endl;
					cin >> b[i];
					cin >> c[i];
					cin >> d[i];
					system("cls");
					break;
				}

	}


int main()
{
	hdr();
	output();
	ftr();
	eof();
	system("pause");
	ofs.close();
	return 0;

}