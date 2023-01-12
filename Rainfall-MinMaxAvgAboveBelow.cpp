//Progam By: John Daggs 11/19/20
//
//This program calls a function 'fillArray' to read an input file called "rainfall.txt" that contains 20 rainfall totals
//
//and reads them into an array.
//
//Then, the program calls a function 'MinMaxAverageAboveBelow' that calculates the average, the number of rainfalls that
//
//fall under three inches below the average, the number of rainfalls that fall above three inches below the average,
//
//the maximum of the rainfalls, the minimum of the rainalls, and prints them to the screen.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int SIZE = 20;

void fillArray(float rain[]); // this function reads the input file "rainfall.txt" and fills the array with the data.
void MinMaxAverageAboveBelow(float rain[]); // this function calculates the average of the rainfalls, the number of rainfalls that fall under three inches below the average, the number of rainfalls that fall above three inches below the average, the maximum of the rainfalls, and the minimum of the rainalls . . . printing them to the screen.

int main() {
	float rain[SIZE];
	
	fillArray(rain);
	MinMaxAverageAboveBelow(rain);
	
}

void fillArray(float rain[]) {

	ifstream in;
	in.open("rainfall.txt");
	if (in.fail()) {
		cout << "The input file 'rainfall.txt' has failed to open" << endl;
	}

	while (!(in.fail)()) {
		for (int i = 0; i < SIZE; ++i)
			in >> rain[i];
		cout << "The rainfall amounts are: " << endl;
		for (int i = 0; i < SIZE; ++i)
			cout << rain[i] << ' ';
		cout << endl;
		break;

	}

	in.close();
	
}

void MinMaxAverageAboveBelow(float rain[]) {

	float min = rain[0];
	float max = rain[0];

	for (int i = 0; i < SIZE; ++i) {
		if (min > rain[i]) {
			min = rain[i];
		}
		if (max < rain[i]) {
			max = rain[i];
		}
	}

	cout << endl << "The Lowest rainfall amount is: " << min;
	cout << endl << "The Highest rainfall amount is: " << max;


	float total = 0;
	float average = 0;

	for (int i = 0; i < SIZE; ++i) {
		total = total + rain[i];
	}

	average = total / SIZE;

	cout << endl << "The average is: " << average << endl;

	float below = average - 3;
	float above = average + 3;
	int countBelow = 0, countAbove = 0;

	for (int i = 0; i < SIZE; ++i) {
		if (rain[i] < below) {
			countBelow++;
		}
		if (rain[i] > above) {
			countAbove++;
		}
	}

	cout << "Number of rainfalls under " << below << " inches: " << countBelow << endl;
	cout << "Number of rainfalls above " << above << " inches: " << countAbove << endl;

}



