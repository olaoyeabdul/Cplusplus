//Prog1 is used to compute pi by deducting/adding odd numbers reciprocal from 1
//The computation gives a value close to the value of pi
#include"prog1.h"

int main()
{
	double result;   //result is the variable used hold the return value of add_terms
	int N ;			//Variable to hold the number of terms
	cout << "Enter the number of terms : ";
	cin >> N;
	result = add_terms(N);
	cout << endl << "Pi is " << result << endl;

	return 0;
}

//add_terms is the function that calculates the terms computed in this program, it returns "sum", a double data type.
//the terms are calculated using a for loop and if statements, if statements are used to determine operators to be used in turns.
double add_terms(unsigned int N)
{
	double dr = 0.0;   //dr is the denominator, it is assigned an odd value during each loop
	double odd = 1.0;  //variable to hold odd number values, this is accomplished by adding 2 to odd after each loop
	double sum = 1.0;  //The return value variable and also the first "1" in the equation 

	for (int k = 0; k < N; k++)
	{
		odd += 2;

		dr = odd;

		if (k == 0)
		{
			sum -= nr / dr;
		}

		if (k == 1)
		{
			sum += nr / dr;
		}

		if ((k > 1) && (k % 2 == 0))
		{
			sum -= nr / dr;
		}

		if ((k > 1) && (k % 2 > 0))
		{
			sum += nr / dr;
		}

	}

	return sum*4;

}
