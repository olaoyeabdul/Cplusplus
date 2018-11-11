//*************************************
//name: Abdulsalam Olaoye			 **
//date: 10-17-2016					 **
//lab: Mid-term						 **
//summary: Powerball lotto program   **
//*************************************

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;


//**********************************************************************
// Concepts used in this program include for-loops, do/while, functions*
//        Arrays, strings, ofs, case/switch, cin, cout etc			   *	
//**********************************************************************





//******************
// Opening ofs file*
//******************

ofstream ofs("Olaoye_Midterm.txt");

//*********************************************
// Global string Variables used in the program*
//*********************************************

string name = "Abdulsalam Olaoye";
string course = "CIS 2541 - 004";
string date = "10-17-2016";
string lab = "Mid-term";
string summary = "PowerBall Machine";
string eofmsg = "EOF message: ";
string sp = " ";
string bar = "|";
string show = "Error : Input  must be within 1 - 69 ";
string show2 = "Error : Input  must be within 1 - 26 ";
string noDups = "Error: No duplicates please";
string PB = "PB";
string zero = "0";
string QP = "Enter your number of Quick-Picks: ";
string powerball = "Enter powerball (powerball must be 1 through 26): ";
string notvalid = "Error!!! You've entered an invalid choice";
string choose = "Enter a valid menu option: ";
string sph = "                        ";
string firstline = "POWERBALL JACKPOT IS $25 MILLION";
string secondline = "IN THE WORDS OF : YOU ARE A WINNER ";
string inputmessage = "Enter 5 quickpicks(1 through 69  and no duplicates please) : ";
string lines_8 = "\n\n\n\n\n\n\n\n";
string lines_2 = "\n\n";

//*************************************************************************
// String menu[array] which contains Ascii characters for main menu output* 
//*************************************************************************
string menu[18] = {
	" _      ___                       _    _          _    _ ",
	"/ |    / _ L _ _  ___   __ _ _  _(_)__| |__  _ __(_)__| |__ ",
	"| |_  | (_) | ' L/ -_) / _` | || | / _| / / | '_ L / _| / / ",
	"|_(_)  L___/|_||_L___| L__, |L_,_|_L__|_L_L | .__/_L__|_L_L ",
	"|_  )   | __(_)_ _____   _|_| _  _(_)__| |__|_| __(_)__| |__ ___",
	" / / _  | _|| L V / -_) / _` | || | / _| / / | '_ L / _| / /(_-<",
	"/___(_) |_|_|_|L_/L___| L__, |L_,_|_L__|_L_L | .__/_L__|_L_L/__/             _    _        _    _        ",
	"|__ /     /_L  _ _ _  _   _|_|_  _ _ __ | |__|_|__ _ _   ___ / _|  __ _ _  _(_)__| |___ __(_)__| |__ ___ ",
	" |_ L_   / _ L| ' L || | | ' L || | '  L| '_ L/ -_) '_| / _ L  _| / _` | || | / _| / / '_ L / _| / /(_-< ",
	"|___(_) /_/ L_L_||_L_, | |_||_L_,_|_|_|_|_.__/L___|_|   L___/_|   L__, |L_,_|_L__|_L_L .__/_L__|_L_L/__/ ",
	" _ _     ___     _ |__/        ___                  _                |_|            _|_|       ___                    _          _ _ ",
	"| | |   | __|_ _| |_ ___ _ _  | __|  _ _ _  _ _ __ | |__  ___ _ _ ___  __ _ _ _  __| |  __ _  | _ L_____ __ _____ _ _| |__  __ _| | |",
	"|_  _|  | _|| ' L  _/ -_) '_| |__ L | ' L || | '  L| '_ L/ -_) '_(_-< / _` | ' L/ _` | / _` | |  _/ _ L V  V / -_) '_| '_ L/ _` | | |",
	" _|_(_) |___|_||_L__L___|_|   |___/ |_||_L_,_|_|_|_|_.__/L___|_| /__/ L__,_|_||_L__,_| L__,_| |_| L___/L_/L_/L___|_| |_.__/L__,_|_|_|",
	"| __|    / _ L _  _(_) |_ ",
	"|__ L_  | (_) | || | |  _|",
	"|___(_)  L__L_LL_,_|_|L__|",};


//************************************************************
// String firstprint[array] which contains Ascii characters  *
//				 used for ticket print out head				 *
//************************************************************
string firstprint[6] = {

	" .oPYo. .oPYo. o      o .oPYo.  .oPYo.  .oPYo.      .oo o     o ",
	" 8    8 8    8 8      8 8.      8   `8  8   `8     .P 8 8     8 ",
	"o8YooP' 8    8 8      8 `boo   o8YooP' o8YooP'    .P  8 8     8 ",
	" 8      8    8 8  db  8 .P      8   `b  8   `b   oPooo8 8     8 ",
	" 8      8    8 `b.PY.d' 8       8    8  8    8  .P    8 8     8 ",
	" 8      `YooP'  `8  8'  `YooP'  8    8  8oooP' .P     8 8oooo 8oooo", };


//***********************************************************
// string secondprint[array] which contains Ascii characters* 
//				used for ticket print out head				*
//***********************************************************
string secondprint[3] = {

	"  ^    ^    ^    ^    ^    ^    ^    ^    ^",
	" /P   /O   /W   /E   /R   /p   /l   /a   /y  ", 
	"<___><___><___><___><___><___><___><___><___>", };


//*******************************************************************************
// string lastlines[array] which contains characters for the end of ticket print*
//*******************************************************************************
string lastlines[11] = {

	"	                     	1 draw(s)	10/17/2016",
	"		                  TOTAL 		     $2.00",
	"					  ",
	"                   	   LOTO   10/18/2016	 $256 MILL",
	"	                   PWRB   10/19/2016	 $500 MILL",
	"	                   MEGA   10/21/2016	 $400 MILL",
	"					  ",
	"                   21012 201355 25631 024563 12546 256620 22562",
	"	                    	10/17/2016    19:30:29	",
	"                       	|||||| |||||| ||||| |||||| ||||||",
	"					 ", };


//********************************
// String for Bye message in menu*
//********************************
string bye[5] = {
	" _            _     ___                   ___          _ _ _ ",
	"| |   __ _ __| |_  | _ L__ _ __ _ ___    | _ )_  _ ___| | | |",
	"| |__/ _` (_-<  _| |  _/ _` / _` / -_)_  | _ L || / -_)_|_|_|",
	"|____L__,_/__/L__| |_| L__,_L__, L___( ) |___/L_, L___(_|_|_)",
	"                            |___/    |/       |__/           ",
};

//************************************
// Declaring variable for menu choice*
//************************************
int choice;

//****************************
// Constants for menu choices*
//****************************
const int   Option_1 = 1,
			Option_2 = 2,
			Option_3 = 3,
			Option_4 = 4,
			Quit = 5;

//******************************************************************
// Naming of arrays and declaration of count and boolean variables *
//******************************************************************

int element;
int index;
int Count;
int input;
int userinput = 5;
int line = 0;
bool dupe;
int temp;
bool sort;


//********************************************************************************
// Array[array] is used in the program to hold 5 quickpick values which initially*
//     contains zeros and will be assigned random values in the program			 *
//********************************************************************************
int Array[5];


//****************************************************
// ArrayPB[array] is used to hold one POWERBALL value*
//  which is to be assigned randomly later in program*
//****************************************************
int ArrayPB[1];


//********************************************************************
// Array2[array] will be used in the las option to store values input*
//				       by user of the program						 *
//********************************************************************
int Array2[5];


//****************************************************
//*header function which displays the header message**
//****************************************************
void hdr()
{
	ofs << name << sp;
	ofs << course << sp;
	ofs << date << sp;
	ofs << lab << endl;	
}


//************************************************************
//*footer function which displays the summary of the program**
//************************************************************
void ftr()
{
	ofs << sph << sp << sp << sp << sp << sp << sp << summary << endl;
}


//***********************************************************
//  End of file function which displays end of file message *
//***********************************************************
void eof()
{
	hdr();
}


//***********************************************************************************
// Showmenu function uses a loop to display Ascii characters stored in menu[array]  *
//				which holds Ascii characters for menu display						*
//***********************************************************************************
void showmenu()
{
	
	//*************************************************************************
	// The for-loop here uses index as a counter to display the  menu[array]  *
	//*************************************************************************
	for (index = 0; index < 18; index++)
	{
		cout << menu[index] << endl;	
	}

	
}


//******************************************************************************************
// Tickethead function which contains two for-loops used to display the firstprint[array]  *
// and secondprint[array] The two arrays contain Ascii characters used for ticket top print*
//******************************************************************************************
void Tickethead()
{
	ofs << lines_2 << name << lines_2;


	//****************************************************************************************
	// The for-loop here uses variable f as a counter to display the Ascii firstprint[array] *
	//****************************************************************************************
	for (int f = 0; f < 6; f++)
	{
		ofs << firstprint[f] << endl;
	}
	ofs << endl;

	
	//*****************************************************************************************
	// The for-loop here uses variable s as a counter to display the Ascii secondprint[array] *
	//*****************************************************************************************
	for (int s = 0; s < 3; s++)
	{
		ofs << sph << sph << secondprint[s] << endl;
	}

	ofs << endl << sph << firstline << endl;
	ofs << sph << secondline << endl;
	ofs << lines_2;

}


//******************************************************************************************
// Ticketend function which contains a for-loop used to display the lastlines[array]  which*
//					contains the lower part of ticket print								   *
//******************************************************************************************
void Ticketend()
{
	//******************************************************************************
	// The for-loop here uses variable c as a counter to display  lastlines[array] *
	//******************************************************************************
	for (int c = 0; c < 11; c++)
	{
		ofs << lastlines[c] << endl;
	}

}


//************************************************************************************************
// option1 function contains for-loops that assign values, check and replace duplicates and print*
//		values in Array[array] and the ArrayPB[array] It also contains a do/while loop which     *
//						bubble sorts numbers in the Array[array]								 *
//************************************************************************************************
void option1()
{
	system("cls");

	//**********************************************************************************************
	// Nested for-loops, do/while and if statement used to assign random numbers, check and replace*
	//			duplicate numbers in the Array[array] (which holds 5 quickpick values)			   *
	//**********************************************************************************************
	for (element = 0; element < 5; element++)
	{
		for (int l = 0; l < 5; l++)
		{
			Array[l] = (rand() % (69 - 1 + 1)) + 1;

			do
			{
				dupe = false;

				for (int d = 0; d < 5; d++)
				{
					if (Array[l] == Array[d] && l != d)
					{
						Array[l] = (rand() % (69 - 1 + 1)) + 1;
						dupe = true;
					}
				}
			} while (dupe == true);

		}

	}


	//**************************************************************************
	// A do/while statement used for bubble-sorting numbers in the Array[array]*
	//**************************************************************************
	do
	{
		sort = false;
		for (int count = 0; count < (5 - 1); count++)
		{

			if (Array[count] > Array[count + 1])
			{
				temp = Array[count];
				Array[count] = Array[count + 1];
				Array[count + 1] = temp;

				sort = true;
			}

		}


	} while (sort);

	//*********************************************************************************
	// For-loops used to print values in Array[array] and ArrayPB[array] into the text*
	//		file and Nestedif statements used to add zeros to single digits			  *
	//*********************************************************************************
		ofs << sph;
	for (int k = 0; k < 5; k++)
	{
		if (Array[k] < 10)
			ofs << zero;
		ofs << Array[k] << sp << sp;
	}

	ofs << sp << sp << sp << PB << sp << sp;

	for (int p = 0; p < 1; p++)
	{
		ArrayPB[p] = (rand() % (26 - 1 + 1)) + 1;

		if (ArrayPB[p] < 10)
			ofs << zero;
		ofs << ArrayPB[p] << endl;

	}
	ofs << lines_2;
}


//************************************************************************************
// option2 function performs tasks to print output for 2nd option in the program menu*
//************************************************************************************
void option2()
{
	//***********************************************************************
	// The for-loop which uses y as counter variable prints out 5 quickpicks*
	//			and a POWERBALL by looping option1 function 5 times			*
	//***********************************************************************
	for (int y = 0; y < 5; y++)
	{
		option1();
	}

}


//****************************************************************
// option3 function prompts user to pick a number of quickpicks	 * 
//				and prints out 5 quickpicks per ticket			 *
//****************************************************************
void option3()
{
	system("cls");

	cout << QP;
	cin >> input;
	line = 0;

	//*********************************************************************
	// for-loop used to loop option1 function for the number of quickpicks*
	//					user inputs in the program menu					  *
	//*********************************************************************
	for (index = 1; index <= input; index++)
	{
		option1();

		if (index % 5 == 0)
		{
			Ticketend();

		}
		
	}
	
	


	

	



}


//*************************************************************************************
// option4 function allows user to enter  his/her quickpick numbers without duplicates*
//	 and a POWERBALL number, sorts the quickpicks && prints sorted input on a ticket  * 
//*************************************************************************************
void option4()
{
	system("cls");
	
	cout << inputmessage;
	
	//**********************************************************************************************
	// Nested for-loops, do/while and if statement used to assign input numbers, check and prompts *
	// user to replace duplicate numbers in the Array2[array] (which holds 5 quickpick values)	   *
	//**********************************************************************************************
	for (int c = 0; c < userinput; c++)
	{
		cin >> Array2[c];
		if (Array2[c] < 1 || Array2[c] > 69)
		{
			cout << show << endl;
			cin >> Array2[c];
		}
			do
			{
				dupe = false;

				for (int d = 0; d < 5; d++)
				{
					if (Array2[c] == Array2[d] && c != d)
					{
						cout << noDups << endl;
						cin >> Array2[c];
						if (Array2[c] < 1 || Array2[c] > 69)
						{
							cout << show << endl;
							cin >> Array2[c];
						}
						dupe = true;
					}
				}
			} while (dupe == true);

			
		}

		cout << powerball;


		//*****************************************************************************
		// For-loop used to assign POWERBALL value entered by user into ArrayPB[array]*
		//*****************************************************************************
		for (int a = 0; a < 1; a++)
		{
			cin >> ArrayPB[a];

			while (ArrayPB[a] < 1 || ArrayPB[a] > 26)
			{
				cout << show2 << endl;
				cin >> ArrayPB[a];
			}



			//***************************************************************************
			// A do/while statement used for bubble-sorting numbers in the Array2[array]*
			//***************************************************************************
			int temp;
			bool sort;


			do
			{
				sort = false;
				for (int count = 0; count < (5 - 1); count++)
				{

					if (Array2[count] > Array2[count + 1])
					{
						temp = Array2[count];
						Array2[count] = Array2[count + 1];
						Array2[count + 1] = temp;

						sort = true;
					}

				}


			} while (sort);
			

			//**********************************************************************************
			// For-loops used to print values in Array2[array] and ArrayPB[array] into the text*
			//		   file and Nestedif statements used to add zeros to single digits		   *
			//**********************************************************************************
			ofs << sph ; 

			for (int k = 0; k < 5; k++)
			{
				if (Array2[k] < 10)
					ofs << zero;
				ofs << Array2[k] << sp << sp;
			}

			ofs << sp << sp << sp << PB << sp << sp;

			for (int p = 0; p < 1; p++)
			{
				if (ArrayPB[p] < 10)
					ofs << zero;
				ofs << ArrayPB[p] << endl << endl;

			}
		
	}
	




}


//*****************************************************************************
// quit function which prints footer and end of file message to the ticket and*
// also prints a bye message to the console when user chooses to quit program *
//*****************************************************************************
void quit()
{
	system("cls");

	//************************************************************************
	// The footer and end of file print functions are called here they both  *
	// get printed to the text file(ticket) everytime user quits the program *
	//************************************************************************
	ftr();
	eof();
	

	//********************************************************************
	// for-loop used to display Ascii characters stored in the bye[array]*
	//   which holds a bye message to user whenever user quits program   *
	//********************************************************************
	for (int y = 0; y < 5; y++)
	{
		cout << bye[y] << endl;
	}
}


//********************************************************************************
// MenuChoice function contains other functions which are called on whenever user*
// chooses to use any of them with each function assigned to a numerical choice  *
// options such as option1 is assigned option_1 choice and so on, it also has an *
// input validation while statement which allows user to stay within menu scope  *
//    and avoid program error when a choice outside of assigned one  is chosen   *
//********************************************************************************
void MenuChoice()
{

	//*****************************************************************************
	// A do/while statement that displays menu by calling on the showmenu function*
	//			and gets user choice input in the menu of the program			  * 
	//*****************************************************************************
	do
	{

		showmenu();
		
		cin >> choice;


		//*********************************************************************
		// While statement which prompts user to stay within menu choice scope*
		//*********************************************************************
		while (choice < Option_1 || choice > Quit)
		{
			
				cout << notvalid << endl;
				system("pause");
				cin.clear();
				cin.ignore(100, '\n');
				system("cls");
				break;
			
		}

		//***********************************************************************
		// switch command which switches between menu choices chosen by user and*
		// calls on different functions assigned to the choices until user quits*
		//***********************************************************************
			switch (choice)
			{

			case Option_1:
				Tickethead();
				ofs << lines_8;
				option1();
				ofs << lines_8;
				Ticketend();
				break;

			case Option_2:
				Tickethead();
				option2();
				Ticketend();
				break;

			case Option_3:
				Tickethead();
				option3();
				break;

			case Option_4:
				Tickethead();
				ofs << lines_8;
				option4();
				ofs << lines_8;
				Ticketend();
				break;

			case Quit:
				quit();
				break;

			}

		
	} while (choice != Quit);
}


//*********************************************************************
// Main function of the program, it is where the program begins to run*
// menuchoice and header functions are called here each time program  *
//								runs								  *
//*********************************************************************
int main()
{
	//****************************************************************
	// Time command used to change duplicate values each program runs*
	//****************************************************************
	srand(time(NULL));


	//********************************************
	// hdr funtion to display header to text file*
	//********************************************
	hdr();
	

	//*******************************************
	// Menuchoice function is called here		*
	//*******************************************
	MenuChoice();


	//********************
	//**closing ofs file**
	//********************
	ofs.close();

	
	return 0;

}
