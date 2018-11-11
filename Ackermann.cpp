#include<iostream>

using namespace std;

int function(int m, int n)
{
	if(m == 0)
	{
		return (2*n);
	}
	else if((m >= 1) && (n == 0))
	{
		return 0;
	}
	else if ((m >= 1) && (n == 1))
	{
		return 2;
	}
	else if ((m >= 1) && (n >= 2))
	{
		return function((m - 1), function(m, n - 1));
	}

}

int main()
{
	cout << function(2, 3) << endl;



	system("pause");
	return 0;
}