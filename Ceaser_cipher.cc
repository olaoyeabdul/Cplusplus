/*
Name = Abdulsalam Olaoye
Zid = Z1836477
Prog title = Ceaser cipher
Prog = Program to receive text from file and cipher the text using a specific key and shift given from a text
*/


#include "prog3.h"

string str;
string str2;

int main()
{

	string key;
	int shift;

	while (!ifs.eof())
	{
		ifs >> shift;
		ifs >> key;
		process_infile(shift, key);
		
	}
	

	
	
	system("pause");
	return 0;
}

int new_position(const char& c, const int& shift, const string& key)
{
	
	int pos = 0;		/* Return Variable used to hold the final position of 'c' after it has gone through cipher shift */

	char in_key =' ';		 /* char variable to hold the char in postion of (c) in the key string*/

	for (int j = 0; j < Alpha.length(); j++)	/*For loop used to check for the int position of 'c' the alphabetic strings */
	{
		if (c == Alpha[j])  /*This checks if c is Upper alphabetic character and adds the postion of 'c' to the "pos" variable*/
		{
			pos += j;
		}
		else if (c == alpha[j])  /*This checks if c is lower alphabetic character and adds the postion of 'c' to the "pos" variable*/
		{
			pos += j;
		}

	}
		for (int i = 0; i < key.length(); i++) /*Loops through KEY and checks for the alphabet in the index position of 'c' on the KEY string  */
		{
			if (pos == i)
			{
				in_key = key[i];			/*The alphabet in the desired position is assigned to in_key*/
			}

		}
	
		for (int k = 0; k < Alpha.length(); k++) /*The real index postion of the Alphabet stored in in_key is checked on the normal alphabet string*/
		{
			if (in_key == Alpha[k]) /* if the desired alphabet is found */
			{
				pos -= k;		/*It's index position is deducted from the index position of 'c' */
			}
		}
	
		pos += shift;	/* Shift is added to the result of the cipher calculation*/

	return pos;
}


string encodeCeaserCipher(string str, const int& shift, const string& key)
{
	string new_string;  /*New string that will hold ciphered string and return it*/
	int pos_hold = 0;
	
	for (int i = 0; i < str.length(); i++)	/*Loops through the string str to check contents*/
	{
		int pos = 0;				/*Variable used to return int position from routine (new_postion)*/
		if (!isalpha(str[i]))		/*If statement checks o see if str is an alphabet*/
		{
			new_string += str[i];		/*If string isn't an alphabet, character in string is returned the new_string variable*/
		}
		else
		{
			pos = new_position(str[i], shift, key);			/*Else the position of character in str is shifted and the new position assigned is passed to pos*/
			if (pos == 0)								/*If there is no position change, the character is passed to new_string*/
			{
				new_string += str[i];
			}
			else if (pos > 0)							/*If there is position shifts and the new shift value is greater than zero */
			{
				for (int j = 0; j < Alpha.length();  j++)  /*For loop to check for the position of the str character on the Alphabet table*/
				{
					if ((str[i] == Alpha[j]) || (str[i] == alpha[j]) )				/*If the str character  and it's position is found on the alpha table */
					{
						pos_hold = j + pos;					/*Add the new shift position to the position of original str character on the alpha table*/
						if (pos_hold > 25)					/*If the value of the newly derived position is greater than 25*/
						{
							pos_hold = (pos_hold % 26);		/*Calculation to prevent going outside of context i.e Alphabet table*/
						}
						for (int k = 0; k <= pos_hold; k++)  /* for loop to loop locate the new position for the final shift */
						{
							if ((k == pos_hold) && (isupper(str[i])) ) /* If the character in the position has been located and text is upper case */
							{
								new_string += Alpha[pos_hold];		/*add the upper case character to the return string*/
							}
							else if ((k == pos_hold) && (islower(str[i]))) /* If the character in the position has been located and text is lower case */
							{
								new_string += alpha[pos_hold];		/*add the lower case character to the return string*/
							}
						}
											
					}
				}
			
			}
			else if (pos < 0)		/*If there is position shifts and the new shift value is lower than zero */
			{
				for (int j = 0; j < Alpha.length(); j++)  /*For loop to check for the position of the str character on the Alphabet table*/
				{
					if ((str[i] == Alpha[j]) || (str[i] == alpha[j]))				/*If the str character  and it's position is found on the alpha table */
					{
						
						if ((abs(pos)) > 25) /*if the absolute negative value is greater than number of alphabets */
						{
							pos = (pos % 26)+26; /*Calculate the shift value and convert it to positive*/
						}
						else 
						{
							pos = (pos + 26);  /*If the negative shift value isn't greater than number of alphabets, add the value to 26 to vonvert it to positive*/
						}
						pos_hold = j;         /*Position of string character in text is passed to pos_hold*/

						int k = 0;
						while (k < pos)     /*While loop used to reset the position of newly formed string whenever it reaches end of alpha table*/
						{
							pos_hold++;		
							k++;
							if (pos_hold == alpha.length() ) /*If the current shift position reaches the end of alpha table, it resets back to the beginning of the table*/
							{
								pos_hold = 0; 
							}

						}
						for (int e = 0; e <= alpha.length(); e++)	/*For loop used to find the alphabet in the final position derived, checks if text is upper or lower case and assigns the correct case to return string*/
						{
							if ((Alpha[e] == Alpha[pos_hold]) && (isupper(str[i])))
							{
								new_string += Alpha[e];
							}
							else if ((alpha[e] == alpha[pos_hold]) && (islower(str[i])))
							{
								new_string += alpha[e];
							}
						}
						
					}
				}

			}
		}

		
	}
	return new_string;
}

void process_infile(const int& shift, const string& key)
{

	
	
	cout << "Shift = " << shift<< endl;
	cout << "Key = ";
	for (int i = 0; i < key.length(); i++)
	{
		cout << key[i];
	}cout << endl;
	
		while (!ifs2.eof()) /*This is used to get the characters in text and copy them into new string variable*/
		{

			getline(ifs2, str2); /*Characters from file are copied into str2*/
			str += str2;			/*characters copies into str2 are saved to str in order to have the full file*/

		}

		string newstring;			/*String returned from encodeCipher is returned here*/

		newstring += encodeCeaserCipher(str, shift, key);


		for (int i = 0; i < newstring.length(); i++)	/*Loop to print out ciphered string*/
		{
			cout << newstring[i];
		} cout << endl << endl;

		/*if (ifs2.fail());
		{
			cout << "File 2 couldn't Open" << endl;
			exit(EXIT_FAILURE);
		}*/
	
}