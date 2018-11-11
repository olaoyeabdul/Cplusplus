/*
	Name: Abdulsalam Olaoye	
	Zid: *******
	Assignment Number: 2
	Assignment Title: Perfect Numbers
	Due Date: 9/14/2017
*/

/*
	This program is used to compute the perfect numbers within a given range
*/
#include"prog2.h"

int main()
{
	/*
		This For-loop is used to loop isPerfect Fn N(9999) number of times, with
		the counter variable "i" serving as arguement for the isPerfect Fn
	*/
	for (int i = 1; i < N; i++)
	{
		cout << setw(4);   //Used to set width during console output
		isPerfect(i);
	}

	system("pause");
	return 0;
}

/*
	Each time an "int" arguement is thrown in this bool Fn it returns true if the arguement is a perfect number,
	And prints the arguement and its divisors. But returns False if the arguement is  not a perfect number.
*/
bool isPerfect(unsigned int N)
{
	vector<int> factor; // The vector is used to store divisors
	int sum = 0;		//Sum is used to add divisors values and used to compare arguement values

	for (int i = 1; i < N; i++)
	{
		if (N%i ==0)
		{
			factor.push_back(i);	// Each divisor that leaves no remainder is pushed back into the vector
			sum += i;				// Divisor gets added to sum
		}
	}
	if (sum == N)		// If Sum is equal to argument, i.e argument is a perfect number
	{
		
		cout << N << " = ";
		for (int k = 0; k < factor.size(); k++)		//FOr loop used to print out vector elements i.e divisors
		{
			cout << factor[k];
			if ((k + 1) < factor.size())
			{
				cout << " + ";
			}
		}
		cout << endl;
		return isPerfect(true);
	}
	return false;
}
