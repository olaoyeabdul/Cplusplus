/*
Name = Abdulsalam Olaoye
Zid = Z1836477
Prog title = Our friend the Atom 
Prog = Program to simulate chain reactions in Nuclear fission
Prog due date = 10/11/2017

*/



#pragma once
#ifndef prog5_h
#define prog5_h

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<ctime>
#include <cstdlib>



using namespace std;
const unsigned GRID_SIZE = 25;
const int MIN_CYCLES = 1;
const int MAX_CYCLES = 4;

//Routine to initialize the vectors used in simulation
void init_sim(vector < vector<bool> >& traps, vector<unsigned>& ballCycles);

//Routine to update the vector ballCycles
void update_cycles(vector<unsigned>& ballCycles);

//Routine used to compute balls to fall on trap and to manipulate traps
unsigned release_balls(vector < vector<bool> >& traps, vector<unsigned>& ballCycles);

//Routine used to print the traps grid
void print_grid(const vector < vector<bool> >&traps, const unsigned& clock, const unsigned& noBallsInAir);

//Routine to print final stats of program
void print_stat(const vector< vector < bool> >&traps, const unsigned& maxNoBallsInAir, const unsigned& clock);

#endif