/*
Name = Abdulsalam Olaoye
Zid = Z1836477
Prog title = Our friend the Atom
Prog = Simulate chain reactions in Nuclear fission
Prog due date = 10/11/2017

*/

#include"prog5.h"

int main()
{
	
	vector<vector <bool> >traps;
	vector<unsigned> ballCycles;
	unsigned noBallsInAir = 1;
	unsigned clock = 0;
	unsigned maxNoBallsInAir = 0;

	init_sim(traps, ballCycles);
	while (noBallsInAir > 0)
	{
		noBallsInAir = release_balls(traps, ballCycles);
		if ((clock == 0) || (clock % 10 == 0)) 
		{
			print_grid(traps, clock, noBallsInAir);
		}
		clock++;
		
		if (noBallsInAir > maxNoBallsInAir)
		{
			maxNoBallsInAir = noBallsInAir;
		}
	}
	print_grid(traps, clock, noBallsInAir);	
	
	print_stat(traps, maxNoBallsInAir, clock);
	
	system("pause");
	return 0;
}

void init_sim(vector <vector<bool> >& traps, vector<unsigned>& ballCycles)
{
	for (unsigned i = 0; i < GRID_SIZE; i++) //For loop to initialize each element in traps to true
	{
		vector<bool> temp;						//temp is used to hold the value of each element on a row 
		for (unsigned j = 0; j < GRID_SIZE; j++)
		{
			temp.push_back(true);	
		}
		traps.push_back(temp);
	}

	ballCycles.push_back(1);			//The first ball is added to the ballcycles

	srand(time(NULL));
	

}

unsigned release_balls(vector <vector<bool> >& traps, vector<unsigned>& ballCycles)
{
	int balls_drop = 0;						//if there is any element that is equal 0 i.e element ready to fall on trap
	unsigned released_balls = 0;				//Return variable for the routine


	for (unsigned j = 0; j < ballCycles.size(); j++)			//Loop to erase elements that have fallen on traps out of the ballCycles
	{
		if (ballCycles[j] == 0)
		{
			ballCycles.erase(ballCycles.begin()+j);
		}
	}

	for (int i = 0; i<ballCycles.size(); i++)			//for loop to check if there's any balls about to drop on a trap
	{
		if (ballCycles[i] != 0)								//decrement values in element if it's not zero
		{
			ballCycles[i] = ballCycles[i] - 1;
		}
		 if (ballCycles[i] == 0)
		{
			balls_drop += 1;							//Increment numbers of element ready to fall on traps
		}
	}
	if (balls_drop == 0)					//If After loop no element is ready to fall on trap
	{
		while (balls_drop == 0)				//Loop through the vector elements and decrement them till theres an element ready to fall on trap
		{
			for (int j = 0; j <ballCycles.size(); j++)
			{
				ballCycles[j] = ballCycles[j] - 1;
				if (ballCycles[j] == 0)
				{
					balls_drop += 1;
					
				}
			}
		}
	}

	for (int i = 0; i < balls_drop; i++)		//For the each number of balls ready to fall on trap
	{
		int row = rand() % (24 - 0 + 1) + 0;			//assign them a row and column on traps grid to fall on
		int column= rand() % (24 - 0 + 1) + 0;

		if (traps[row][column] == true)		//if the assigned row and column has not been sprung 
		{
			traps[row][column] = false;		//Spring it
			released_balls += 2;			//Release its 2 balls into the air
			update_cycles(ballCycles);		//Update_cycles is called to add a new ball in the air, and assign it a random number
			update_cycles(ballCycles);
		}
		
	}
	return released_balls;
}

void print_grid(const vector < vector<bool> >&traps, const unsigned& clock, const unsigned& noBallsInAir)
{
		cout << "Clock = " << clock << "  :  " << "noBallsInAir = " << noBallsInAir << endl << endl << endl;

		for (unsigned i = 0; i < traps.size(); i++)
		{
			for (unsigned j = 0; j < traps[i].size(); j++)
			{
				if (traps[i][j] == true)
				{
					cout << 'X' << " ";
				}
				else
				{
					cout << '.'<< " ";
				}
			}
			cout << endl;
		}
		cout << endl << endl << endl;
}

void print_stat(const vector< vector < bool> >&traps, const unsigned& maxNoBallsInAir, const unsigned& clock)
{
	int sprung = 0; 
	double perSprung = 0.0;

	
	for (unsigned i = 0; i < traps.size(); i++)
	{
		for (unsigned j = 0; j < traps[i].size(); j++)
		{
			if (traps[i][j] == false)
			{
				sprung++;
			}

		}
	}
	
	perSprung = (sprung / 625.0 ) * 100;
	
	cout << setprecision(1) << fixed;
	cout << "Total Simulation time      " << "=" << setw(6) << clock << endl;
	cout << "Max no of Balls in Air     " << "=" << setw(6) << maxNoBallsInAir << endl;
	cout << "Percentage of sprung traps " << "=" << setw(6) << perSprung << endl;
	
}

void update_cycles(vector<unsigned>& ballCycles)
{
	int ball = rand() % (MAX_CYCLES - MIN_CYCLES + 1) + MIN_CYCLES;		//New ball is given a new random cycle number 
	int found = 0;														//It turns to 1 if any element containing zero is found while looping through ballCycles
	for (int i = 0; i < ballCycles.size(); i++)
	{
		if ((ballCycles[i] == 0) && (found==0))						//If a zero is found and we haven't found any zero previously
		{
			ballCycles[i] = ball;								//The zero gets replaced with the newly generated random number
			found = 1;									//Zero has been found
		}	
	}

	if (found == 0)				//If at the end of the cycle,  no zero has been found
	{
		ballCycles.push_back(ball);			//Push_back the newly generated random number into the ballCycles vector
	}
}
