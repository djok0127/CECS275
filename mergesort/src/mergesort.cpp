//============================================================================
// Name        : mergesort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdlib.h> 	// srand, rand
#include <time.h> 		// time
using namespace std;

void displayArray ( vector <int>, int );
void getRandomVector( vector<int> & ,int, int);

int main() {

	// variable initialization
	int quantityOfNumbers;
	int maxSizeNumber;
	int maxNumberOutput;

	vector <int> left;
	vector <int> right;

	// initialize the random seed for rand
	srand(time(NULL));

	// prompt the user for the number of random numbers to sort.
	cout << "Enter the number of random numbers to generate: " << endl;
	cin >> quantityOfNumbers;

	// prompt the user to pick the maximum size.
	cout << "Enter the maximum number to generate: " << endl;
	cin >> maxSizeNumber;

	// prompt the user to pick the maximum number of integers to write out on each line of output.
	cout << "Maximum number of integers to write out on each line of output: " << endl;
	cin >> maxNumberOutput;

	getRandomVector(left, quantityOfNumbers, maxSizeNumber);

	displayArray(left, maxNumberOutput);

	string a;
	cout << "completed satisfactorily." << endl;
	cin >> a;
	return 0;
}

/*
 * displayArray will display the printout the vector of integers is passed in
 * @ param vect the vector that is passed in to print out
 * @ param rowprint an integer to skip line on that rowprint iteration
 * @ return void
 */
void displayArray ( vector <int> vect , int rowprint) {

	for(unsigned int i = 0; i != vect.size(); ++i ){
		// display the contents of the vector
		cout << i;

		if(i != 0 && i != vect.size()) cout << ", ";

		// start the next row when rowprint is equal to current iteration
		if(i % (rowprint) == 0 && i != 0) cout << '\n';
	}

}

/*
 *
 */
void getRandomVector( vector<int> &vect, int quantity, int largest_number){

	for(int i = 0; i < quantity; ++i ){

		// add the random value to the vector
		vect.push_back(rand() % largest_number + 1);
	}
}
