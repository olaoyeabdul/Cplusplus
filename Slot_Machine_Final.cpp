//*************************************
//name: Abdulsalam Olaoye	     **
//date: 12-12-2016					 **
//lab: Final				 **
//summary: Slot machine program      **
//*************************************

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>


using namespace std;


//******************
// Opening ofs file*
//******************

ofstream ofs("Olaoye_Final.txt");

//*********************************************
// Global string Variables used in the program*
//*********************************************

string name = "Abdulsalam Olaoye";
string course = "CIS 2541 - 004";
string date = "12-12-2016";
string lab = "Final";
string summary = " A standard Slot Machine program";
string eofmsg = "EOF message: ";
string sp = " ";
string bar = "|";
string notvalid = "Error!!! You've entered an invalid choice";
string choose = "Enter a valid menu option: ";
string sph = "                        ";
string walletbalance = "Your wallet balance is: $";
string howmuch = "How much would you like to add to balance? (max: $1000) ";
string wallet_full = "Your wallet is full, you can't add anymore cash";

//*************************************************************************
// String menu[array] which contains Ascii characters for main menu output* 
//*************************************************************************
string menu[16] =
{

	"  _     ___  _         _             ___      _         ",
	" / |   |   L(_)____ __| |__ _ _  _  | _ L_  _| |___ ___ ",
	" | |_  | |) | (_-< '_ L / _` | || | |   / || | / -_|_-< ",
	" |_(_) |___/|_/__/ .__/_L__,_|L_, | |_|_LL_,_|_L___/__/ ",
	"  ___    __      |_|   _ _    |__/                      ",
	" |_  )   L L    / /_ _| | |___| |_                      ",
	"  / / _   L L/L/ / _` | | / -_)  _|                     ",
	" /___(_)  _L_/L_/L__,_|_|_L___|L__|                     ",
	" |__ /   | _ L |__ _ _  _   / __|__ _ _ __  ___         ",
	"  |_ L_  |  _/ / _` | || | | (_ / _` | '  L/ -_)        ",
	" |___(_) |_| |_L__,_|L_, |  L___L__,_|_|_|_L___|        ",
	"  _ _      ___       |__/                               ",
	" | | |    / _ L _  _(_) |_                              ",
	" |_  _|  | (_) | || | |  _|                             ",
	"   |_(_)  L__L_LL_,_|_|L__|                             ",
	"                                                        ",

};


//***********************************
// String for welcome screen in menu*
//***********************************
string startup[15] =
{

	"    _   _        _      _          _               ___  _                    ",
	"   /_L | |__  __| |_  _| |___ __ _| |__ _ _ __    / _ L| |__ _ ___ _  _ ___  ",
	"  / _ L| '_ L/ _` | || | (_-</ _` | / _` | '  L  | (_) | / _` / _ L || / -_) ",
	" /_/ L_L_.__/L__,_|L_,_|_/__/L__,_|_L__,_|_|_|_|  L___/|_L__,_L___/L_, L___| ",
	"   ___ ___ ___   ___ ___ _ _  _          __   __  _ _              |__/      ",
	"  / __|_ _/ __| |_  ) __| | |/ |  ___   /  L /  L| | |                       ",
	" | (__ | |L__ L  / /|__ L_  _| | |___| | () | () |_  _|                      ",
	"  L___|___|___/ /___|___/ |_||_|_ __  _ L__/ L__/  |_|                       ",
	" / |_  )  ___  / |_  )  ___  |_  )  L/ |/ /                                  ",
	" | |/ /  |___| | |/ /  |___|  / / () | / _ L                                 ",
	" |_/___|       |_/___|       /___L__/|_L___/                                 ",
	" | __(_)_ _  __ _| |                                                         ",
	" | _|| | ' L/ _` | |                                                         ",
	" |_| |_|_||_L__,_|_|                                                         ",
	"                                                                             ",

};


//********************************
// String for Bye message in menu*
//********************************
string bye[5] = 
{
	" _            _     ___                   ___          _ _ _ ",
	"| |   __ _ __| |_  | _ L__ _ __ _ ___    | _ )_  _ ___| | | |",
	"| |__/ _` (_-<  _| |  _/ _` / _` / -_)_  | _ L || / -_)_|_|_|",
	"|____L__,_/__/L__| |_| L__,_L__, L___( ) |___/L_, L___(_|_|_)",
	"                            |___/    |/       |__/           ",
};

string rules[28] =
{

	"Rules of the game are as follows:					",
	"							 		",
	"1.	Money								",
	"	- Wallet range (min:$100 – max: $1000)				",
	"	- Range of amount to bet ($100 - $1000)				",
	"	- Buy-in minimum is $100 					",
	"	- Amount that can be added to wallet ($100, $200, $500 and $1000)",
	"									",
	"2.	Up to Five winning lines during game play 			",
	"									",
	"3.	Stats on playing screen include:				",
	"	- Number of lines chosen (1 line, 3 lines and  5 lines)		",
	"	- Bet amount and wallet balance					",
	"									",
	"4.	Winning rules: 							",
	"	- 1 line pays 1:1						",
	"	- 3 lines (pays double) 					",
	"	- 5 lines (pays triple)						",
	"									",
	"5.	Bet per line:							",
	"	- Minimum is $100						",
	"	- Maximum is $1000 						",
	"									",
	"6.	Symbols used during gameplay include:				",
	"	- Three 7s, three cherries, three $$$ 				",
	"	- Three diamonds, three lightning bolts				",
	"	- One shamrock (wild card)					",
	"									",

};


string cherries[] = 
{  
	"		    ",
	"1111111111111111111",
	"1111111111111111111",
	"1111111111111111111",
	"1111111111111111111",
	"1111111111111111111",
	"1111111111111111111",
	"1111111111111111111",
	"		    ",
	"		    ",
};
						
string sevens[10] =
{
	"                 ",
	" /$$$$$$$$|      ",
	" |_____ $$/      ",
	"      /$$/       ",
	"     /$$/        ",
	"    /$$/         ",
	"   /$$/          ",
	"  /$$/           ",
	" |__/            ",
	"                 ",


};

string money[10] =
{
	
	"    /$$        ",
	"   /$$$$$$     ",
	"  /$$__  $$    ",
	" | $$  \__/    ",
	" |  $$$$$$     ",
	"  \____  $$    ",
	"  /$$  \ $$    ",
	" |  $$$$$$/    ",
	"  \_  $$_/     ",
	"    \__/       ",
	

};

string diamond[10] = 
{
	"                 ",	
	"  .     '     .  ",
	"     _________	  ",
	"   _L_|_____|_L_ ",
	"    '. L   L .'  ",
	"      '.L L.'    ",
	"        '.'      ",
	"                 ",
	"	          ",
	"	          ",
							
};


string bolt[10] =
{
	"		  ",
	"	  ,'//    ",
	"       ,' //     ",
	"     ,'  //_____,",
	"   .'____     ,' ",
	"        //  ,'   ",
	"       // ,'     ",
	"      //,'       ",
	"     //'         ",
	"	          ",
	

};


string shamrock[10] =
{
	"	          ",
	"       .-.-.     ",
	"      (  :  )    ",
	"    .-.`. .'.-.  ",
	"   (_  '.Y.'  _) ",
	"   (   .'|'.   ) ",
	"     '-' |  '-'  ",
	"	          ",
	"		  ",
	"	          ",
	


};


//************************************
// Declaring variable for menu choice*
//************************************
int choice;
int balance = 0;
int index;
int assign, assign2, assign3;
char wallet;

//****************************
// Constants for menu choices*
//****************************
const int   Option_1 = 1,
			Option_2 = 2,
			Option_3 = 3,
			Quit = 4;



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



void option1()
{
	for (int i = 0; i < 28; i++)
	{
		cout << rules[i] << endl;
	}
	system("pause");
	system("cls");


}



void option2()
{
	while (wallet != 'E' || wallet != 'e')
	{
		
		cout << walletbalance << balance << endl;
		cout << sph << howmuch << endl;
		cin >> wallet;

		if (balance >= 1000)
		{
			cout << wallet_full << endl;
			system("pause");
			break;
		}
		

		if (wallet == 'a' || wallet == 'A')
		{
			balance += 100;
		}
		if (wallet == 'B' || wallet == 'b')
		{
			balance += 200;
		}
		if (wallet == 'C' || wallet == 'c')
		{
			balance += 500;
		}
		if (wallet == 'd' || wallet == 'D')
		{
			balance += 1000;
		}
		if (wallet == 'e' || wallet == 'E')
		{
			break;
		}
		
		system("cls");
		

	} 
}



void option3()
{
	

	for (int k = 0; k < 3; k++)
	{
		

		 assign = (rand() % (6 - 1 + 1)) + 1;
		assign2 = (rand() % (6 - 1 + 1)) + 1;
		assign3 = (rand() % (6 - 1 + 1)) + 1;


		for (int f = 0; f < 10; f++)
		{
			if (assign == 1)
			{
				cout << cherries[f];
			}
			if (assign == 2)
			{
				cout << sevens[f];
			}
			if (assign == 3)
			{
				cout << money[f];
			}
			if (assign == 4)
			{
				cout << diamond[f];
			}
			if (assign == 5)
			{
				cout << bolt[f];
			}
			if (assign == 6)
			{
				cout << shamrock[f];
			}
			//cout << setw(3) << bar;
			cout << sp << sp << sp << sp << sp;

			if (assign2 == 1)
			{
				cout << cherries[f];
			}
			if (assign2 == 2)
			{
				cout << sevens[f];
			}
			if (assign2 == 3)
			{
				cout << money[f];
			}
			if (assign2 == 4)
			{
				cout << diamond[f];
			}
			if (assign2 == 5)
			{
				cout << bolt[f];
			}
			if (assign2 == 6)
			{
				cout << shamrock[f];
			}
			//cout << setw(3) << bar;
			cout << sp << sp << sp << sp << sp;

			if (assign3 == 1)
			{
				cout << cherries[f] << endl;
			}
			if (assign3 == 2)
			{
				cout << sevens[f] << endl;
			}
			if (assign3 == 3)
			{
				cout << money[f] << endl;
			}
			if (assign3 == 4)
			{
				cout << diamond[f] << endl;
			}
			if (assign3 == 5)
			{
				cout << bolt[f] << endl;
			}
			if (assign3 == 6)
			{
				cout << shamrock[f] << endl;
			}
			//cout << setw(3) << bar;
			cout << sp << sp << sp << sp << sp;
		}
		cout << endl;
	}
	system("pause");
	system("cls");
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
	for (index = 0; index < 16; index++)
	{
		cout << menu[index] << endl;
	}


}



void showfirst()
{

	for (int k = 0; k < 15; k++)
	{
		cout << startup[k] << endl;
	}

	system("pause");
	system("cls");

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
			cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			system("cls");
			option1();
			break;

		case Option_2:
			system("cls");
			option2();
			break;

		case Option_3:
			system("cls");
			option3();
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

	system("color e");

	//****************************************************************
	// Time command used to change duplicate values each program runs*
	//****************************************************************
	srand(time(NULL));


	//********************************************
	// hdr funtion to display header to text file*
	//********************************************
	hdr();

	showfirst();
	

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
