/*
Name = Abdulsalam Olaoye
Zid = Z1836477
Prog title = Date class 2
Prog due date = 11/1/2017
*/
#pragma once
#ifndef Date_h
#define Date_h

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cctype>
#include<sstream>
#include<fstream>


using namespace std;

class Date
{
private:
	/*Private member variables*/

	string month ;
	int day ;
	int year ;

	/*Vector used to compare months validity*/
	const vector <string> months{ "January", "February", "March", "April", "May", "June", "July", "August",
		"September", "October", "November", "December" };

	/*Private member functions*/

	/*Routine used to Calculate MAX number of days in a month*/
	int daysInMonth(const string& m) const;

	/*Boolean function to check if a year is a leap year*/
	bool isLeapYear() const;

	/*Bool function to confirm the validity of an entered month*/
	bool isValidMonth() const;


	/*Used t overload the insertion  operator for the date class*/
	friend istream& operator >> (istream& is, Date& d);

	/*Used to overload the extraction operator for the date class*/
	friend ostream& operator<< (ostream& os, const Date& d);

	/*Returns the index value of the present month in the date object*/
	int monthIndex();


public:
	/*Public member functions*/

	/*Constructors of date class*/
	Date(const string& m = "January" , const int& d = 1 , const int& y = 2000 );
	/*Date();*/
	Date(const Date&);
	Date operator=(const Date&);


	/*Mutator Functions*/

	/*SetMonth,Day&Year are used to set values for member variables*/
	void setMonth(const string& m);
	void setDay(const int& d);
	void setYear(const int& y);

	/*GetMonth,Day&Year are used to get values of member variables*/
	string getMonth() const;
	int getDay() const;
	int getYear() const;

	/*Routine used to change the format of entered month to a generally acceptable one*/
	void Month();

	/*Routine used to confirm if date entered by user is valid*/
	bool isValidDate() const;

	/*Routine used to print out full date in a specified format*/
	string toString() const;

	/*Adds a number of years to the year variable*/
	Date& addYear(const int&);

	/*Change the value of days by n number of days*/
	Date& addDay(const int&);

	/*Change the value of months by a number of days*/
	Date& addMonth(const int&);

	int dayIndex()const;

}; 

/*Non member fuction prototypes*/

/*This is used to convert an int value to string*/
string intToString(const int& );

/*Function to find the difference between two date objects*/
unsigned dateDiff(const Date& d1, const Date& d2);


#endif
