
/*
Name = Abdulsalam Olaoye
Zid = Z1836477
Prog title = Ceaser cipher
Prog = Program to receive text from file and cipher the text using a specific key and shift given from a text
*/
#pragma once
#ifndef prog3_h
#define prog3_h

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <sstream>

#define INFILE "ceaserKey1.d1"

#define Textfile "ceaserKey2.d2"

using namespace std;

ifstream ifs(INFILE);
ifstream ifs2(Textfile);



int new_position(const char& c, const int& shift, const string& key);

string encodeCeaserCipher(string str, const int& shift, const string& key);

void process_infile(const int& shift, const string& key);


const string Alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";	/*Variable used to store alphabets in Upper case*/
const string alpha = "abcdefghijklmnopqrstuvwxyz";	/*Variable used to store alphabets in lower case*/


#endif