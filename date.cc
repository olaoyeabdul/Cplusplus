/*
Name = Abdulsalam Olaoye
Zid = Z1836477
Prog title = Date class 2
Prog due date = 11/1/2017
*/

#include"Date.h"

/*Constructor implementation where default values are supplied to each member variable*/
Date::Date(const string& m , const int& d , const int& y )
{
	/*Variable to store well formatted Month entry*/
	string str;
	for (int i = 0; i < m.length(); i++) /*Loop to format the month variable in a more acceptable way*/
	{
		if (i == 0)
		{
			str += toupper(m[i]);
		}
		else if (i != 0)
		{
			str += tolower(m[i]);
		}
	}

	month = str;
	day = d;
	year = y;
}

///*Default constructor to initialize default values for each member variable*/
//Date::Date()
//{
//	month = "January";
//	day = 1;
//	year = 2000;
//}



/*Copy constructor used to copy data from object in argument*/
Date::Date(const Date& d): month(d.getMonth()),day(d.getDay()),year(d.getYear())
{}

/*Assignment operator overload to assign an object to the object on the left hand side of the operator*/
Date Date::operator=(const Date& d)
{
	month = d.getMonth();
	day = d.getDay();
	year = d.getYear();

	return *this;
}

/*Routine used to set the month variable*/
void Date::setMonth(const string& m)
{
	string str;
	for (int i = 0; i < m.length(); i++)/*Loop to format the month variable in a more acceptable way*/
	{
		if (i == 0)
		{
			str += toupper(m[i]);
		}
		else if (i != 0)
		{
			str += tolower(m[i]);
		}
	}
	month = str;
}

/*ROutine used to set the day variable*/
void Date::setDay(const int& d)
{ day = d; }

/*ROutine used to set Year variable*/
void Date::setYear(const int& y)
{	year = y;  }

/*Routine used to retrieve the month value*/
string Date::getMonth()const
{	return month;}

/*Routine to retrieve the Day value*/
int Date::getDay()const
{	return day;}

/*Routie to retrieve the Year value*/
int Date::getYear()const
{	return year;}

/*Routine to set the month value to a more uniform format*/
void Date::Month()
{
	string str;
	for (int i = 0; i < month.length(); i++)/*Loop to format the month variable in a more acceptable way*/
	{
		if (i == 0)
		{
			str+=toupper(month[i]); /*First element of value is set to uppercase*/
		}
		else if(i != 0)
		{
			str+=tolower(month[i]);/*The rest of the elements are set to lower case*/
		}
	}
	month = str;
	
}

/*Bool to confirm validity of entered month*/
bool Date::isValidDate()const
{
	/*If the day entered is greater than zero and its not more than the 
	number of days in that month, and the month is a valid one
	And the year entered is greater than zero retrun true */
	if( (getDay() > 0 && getDay() <= daysInMonth(getMonth())) &&
		(isValidMonth() == true)        &&    (getYear() > 0)
	  )
	{
		return true;
	}

	return false;
}

/*Bool to confirm if month is valid*/
bool Date::isValidMonth()const
{
	for (unsigned i = 0; i < months.size(); i++)
	{
		if (getMonth() == months[i])
		{
			return true;
		}
	}

	return false;
}

/*Function to return the MAX number of days in a month*/
int Date::daysInMonth(const string& m) const
{
	/*Months with 31 days*/
	int days = 1;
	if ((m == "January") || (m == "March") || (m == "May") || (m == "July") || (m == "August") || (m == "October") || (m == "December"))
	{
		days = 31;
	}

	/*Months with 30 Days*/
	if ((m == "September") || (m == "April") || (m == "June") || (m == "November"))
	{
		days = 30;
	}

	/*If it is february and if year is a leapYear*/
	if ((m == "February") && (isLeapYear() == true))
	{
		days = 29;
	}

	/*If it is february and year isn't a leap year*/
	if ((m == "February") && (isLeapYear() == false))
	{
		days = 28;
	}

	return days;	
}

/*Bool function to confirm if enetered year is a leap year*/
bool Date::isLeapYear()const
{
	/*Calculation to derive a leap year*/
	if ( (getYear() % 4 == 0) && (getYear() % 100 != 0) )
	{
		return true;
	}

	if ( (getYear() % 4 == 0) && (getYear() % 100 == 0) && (getYear() % 400 == 0) )
	{
		return true;
	}
	return false;
}

/*Overloading insertion operator in order to be able to enter values for variables in Date class*/
istream& operator >> (istream& is, Date& d)
{
	/*Temp variables used to store values*/
	string str ; int days, years;
	char c ;

	is >> str;
	d.setMonth(str);
	is >> days;
	d.setDay(days);

	is >> c;

	/*If the read character is a digit, it gets put back in fold*/
	if (isdigit(c))
	{
		is.unget();	
	}
	
	is >> years;
	d.setYear(years);
	


	return is;
	
	
}

/*Overloading extraction operator*/
ostream& operator<<(ostream& os, const Date& d)
{
	/*Operator is overloaded in a specific format*/
	os << d.getMonth() << " " << d.getDay() << ", " << d.getYear();
	return os;
}

/*Function used to return Date Values in a specific format*/
string Date::toString()const
{
	string s, value;
	for (int i = 0; i < 3; i++) /*Loop to get the first 3 characters of the month string*/
	{
		s += getMonth()[i];
	}

	string dayy = intToString(getDay());
	string c = "-";
	string yyear = intToString(getYear());

	/*All the variables are returned using value*/
	value = dayy + c + s + c + yyear;

	return value;

}

/*Function to convert int value to a string*/
string intToString(const int& n)
{
	ostringstream s;
	s << n;
	return s.str();
}

/*Returns the index value of the present month in the date object*/
int Date::monthIndex()
{
	for (unsigned i = 0; i < months.size(); i++)
	{
		if (getMonth() == months[i])
		{
			return i;
		}
	}
}

/*Increase year value by n*/
Date& Date::addYear(const int& n)
{ 
	if (n >= 0)
	{
		year += n;
	}
	if (n < 0)
	{
		year -= abs(n);
	}

	return *this;
}

/*Change the value of months by a number of days*/
Date& Date::addMonth(const int& n)
{
	if (n >= 0)
	{
		int addtoyears;		/*Variable used to add years to the year memeber variable*/
		int addtomonths;	 /*Variable used to add month to the month member variable*/


		for (unsigned i = 0; i < months.size(); i++)	/*Looop through the months member vector*/
		{
			if (getMonth() == months[i])	 /*If the month is in an index position*/
			{
				if ((i + n) > 11)				/*And if the position and the new addition is out of scope*/
				{
					addtoyears = ((i + n) / 12);	/*Calculate the number of years that can be derived from the addition of the month pos and no of months addition desired */
					addYear(addtoyears);			/*Add the number of years to the year member variable*/
					addtomonths = ((i + n) % 12);	/*Calculate the remaining months*/
					i = 0;
					addtomonths += i;				/*Add the remaining months to the position of current month*/
					setMonth(months[addtomonths]);	 /*Set new month value into month member variable*/
				}
				else if ((i + n) <= 11)				 /*Else if the position and additional month isn't beyod the no of months in a year*/
				{
					addtomonths = i + n;			 /*Make that the value of addtomonths*/
					setMonth(months[addtomonths]);	 /*SetMonth to that value*/
				}

				if (day > daysInMonth(getMonth()))		/*If the days in the date object is greater than the max number of valid days of that month */
				{
					int newmonth = addtomonths + 1;		/*New variable to hold the position of next month after the current one*/
					if ((newmonth) > 11);				/*If the position of the next month is beyond scope*/
					{
						addtoyears = ((newmonth) / 12);	 /*Calculate the number of years derived from that index value*/
						addYear(addtoyears);			/*Add the number to years*/
						addtomonths = ((newmonth) % 12);		/*Get the reminant as the new index position of month */

						setMonth(months[addtomonths]);		 /*Set the month to the new index position*/
						setDay(1);					/*Set the day value to the first day of that month*/
					}
					if ((newmonth) <= 11)		/*If the position of the next month isn't beyond our months vector scope*/
					{
						setMonth(months[newmonth]);			/*Set the index position as the new month index value*/
						setDay(1);						/*Set the day value to the first day of that month*/
					}
				}
				return *this;
			}
		}
	}

	if (n < 0)		/*If a negative value is passed as argument */
	{
		int addtoyears;		/*Variable used to add years to the year memeber variable*/
		int addtomonths = monthIndex() - abs(n) ;	 /*Variable used to add month to the month member variable*/

		if (addtomonths < 0)	/*If the new index value for month is less than 0*/
		{
			addtoyears = (addtomonths / 12);	 /*Calculation to find out number of years to deduct*/
			if (addtoyears == 0)		/*If years to add isn't more than zero then a year is added*/
			{
				addtoyears -=1;
			}
			addYear(addtoyears);	/*Else the number calculated is added*/

			addtomonths = (addtomonths % 12); /*Calculation to determine the new month index*/
			
			if (addtomonths < 0)  /*If there calculation us a negative value*/
			{
				int newmonth = addtomonths + 12;	/*Calculation is done to arrive at a positive value*/
				setMonth(months[newmonth]);		/*The new index is placed in the month variable*/
				
			}
			else if (addtomonths >= 0)			/*If the new index is not negative its used as the new month index*/
			{
				setMonth(months[addtomonths]);
			}
		}

		 if (addtomonths >= 0)			/* If the new month index isn't negative, set it as the new month index*/
		{
			setMonth(months[addtomonths]);
		}

		if (day > daysInMonth(getMonth()))		/*If the daye day is greater than the valid date*/
		{
			int newmonth = monthIndex() - 1;		/*The month goes down by one index position*/
			if (newmonth < 0)					/*If the new month index is out of scope*/
			{
				addYear(-1);					/*Deduct one year from the years*/
				addtomonths = (newmonth + 12);		/*Calculate new month index*/
				setMonth(months[addtomonths]);			/*Set the index value as the new position*/
				setDay(daysInMonth(getMonth()));			/*Set the day to the last day of the month*/

				
			}
			if ((newmonth) > 0)		/*If the position of the next month isn't beyond our months vector scope*/
			{
				setMonth(months[monthIndex() - 1]);		/*If the newmonth position isn't out of scope*/
				setDay(daysInMonth(getMonth()));			/*Make it the new index position*/
			}

		}

		return *this;
	}
	
}

/*Change the value of days by n number of days*/
Date& Date::addDay(const int& n)
{
	

	if (n > 0)
	{
		int days = getDay() + n;				 /*The day argument value is added to the days already in the date object*/
		int DaysMonth = daysInMonth(getMonth());		/*The number of dayss in a month are passed into newly created variable*/
		while (days > DaysMonth)						/*While the newly derived date is greater than the number of days in the present month of date object*/
		{
			days = days - DaysMonth;					/*The number of days in that month is deducted from the days variable*/
			addMonth(1);									/*A new month is added to the DAte object*/
			DaysMonth = daysInMonth(getMonth());				/*The days in the newly derived month in the date object is passed to the variable holding */
		}
		setDay(days);					/*Day member variable is set to the nwly calculated day*/
	}

	if (n < 0)
	{
		int days = getDay() - abs(n);					/*The day argument passed id deducted from the present day in the date object*/
		int DaysMonth = daysInMonth(getMonth());			/*The number of dayss in a month are passed into newly created variable*/
		if (days <= 0)										/* If the newl calculated value is less than or equal to zero*/
		{
			while (days <= 0)					
			{
				
				days = days + daysInMonth(getMonth());			/*The number of days in the month is added to the days variable*/
				addMonth(-1);									/*A month is deucted from date object*/
				DaysMonth = daysInMonth(getMonth());
			}
		}
		
			setDay(days);			/*New day value is passed in*/
		
	}

	return *this;
}

/*Function to calculayte the number of days passed since jan 1 1*/
int Date::dayIndex() const
{
	int value = 1, newyear = getYear(), newday = getDay(), newmonth ;		/*Variables to recieve the current date */	/*Value is the return variable*/

	for (unsigned i = 0; i < months.size(); i++)			/*USed to pass the present month index into variable holding month */
	{
		if (months[i] == getMonth())
		{
			newmonth = i;
		}
	}




	


	if (year > 1)					/*If present year is greater than 1*/
	{
		while (newyear != 1)			
		{
			
			if ((((newyear) % 4 == 0) && ((newyear) % 100 != 0)) ||
				(((newyear) % 4 == 0) && ((newyear) % 100 == 0) && ((newyear) % 400 == 0)))				/*If statement to determine a leap year*/
			{
				value += 366;					
			}

			else
			{
				value += 365;
			}
			newyear -= 1;		/*Reduce the year value*/
		}

		while (newmonth != 0)			/*While month isn't january*/
		{
			value += daysInMonth(months[newmonth]);		/*Number of days in the present month is added to the value variable*/
			newmonth -= 1;						
		}
		if (day > 1)				
		{
			value += day;
		}
	}



	else if (year < 0)				/*If present year is less than 0*/
	{
		while (newyear != -1)
		{
			
			if ( ((abs(newyear) % 4 == 0) && (abs(newyear) % 100 != 0)) ||
				((abs(newyear) % 4 == 0) && (abs(newyear) % 100 == 0) && (abs(newyear) % 400 == 0)) )				/*If year is a leap year*/
			{
				value -= 366;
			}

			else
			{
				value -= 365;
			}
			newyear += 1;
		}

		while ((newmonth != 0))
		{
			if ((newmonth != 11) || (day !=31))				/*If its not the last day of the year*/
			{
				value -= daysInMonth(months[newmonth]);			/*The days in the present month is deducted from value*/
			}
				newmonth += 1;
			
			if (newmonth == 12)			/*If new month index is out of scope assign the month to be january*/
			{
				newmonth = 0;
			}

		}

		if ((day > 1) && (newyear != -1))
		{
			value -= day;
		}

	}


	return value;
}

/*Function to find the difference between two date objects*/
unsigned dateDiff(const Date& d1, const Date& d2)
{
	unsigned value = 0;		/*Return variable*/

	value = d2.dayIndex() - d1.dayIndex();			/*Return value is the difference between the dayIndex value of d2 and d1*/

	return value;
}