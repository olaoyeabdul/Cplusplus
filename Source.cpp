#include <iostream>
#include <string>
#include<set>
#include<map>
#include<vector>



using namespace std;


int main()
{
	map <string, int> populations;
	populations.insert(pair<string, int>("Chicago", 30));
	populations["St.Louis"] = 17;
	
	map<string, int>::iterator iter = populations.begin();

	for (; iter != populations.end(); ++iter)
	{
		/*iter->second = 99;*/ //another way to add new value to keys, can't change the key this way though


		cout << iter->first << " " << iter->second << endl;
	}

	for (; iter != populations.end(); ++iter)
	{
		if (iter->second == 30)					//used to delete the key that contains 30 populations
		{
			iter = populations.erase(iter);
		}
	}







	/*multiset<char> s;			// Sets and multisets
	s.insert('A');				//
	s.insert('Z');
	s.insert('M');
	s.insert('G');
	s.insert('Q');
	s.insert('G');

	for (char c : s)
	{
		cout << c << " ";
	}
	cout << endl;

	set<char>::iterator iter = s.begin();

	for (; iter != s.end(); ++iter)
	{
		cout << *iter << " ";
	}*/



	

	system("pause");
	return 0;
}