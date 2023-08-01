/*
Author: Andre Colin Chavez
Date: 07/26/2023
Assignment: Object Oriented Math Library
Description: Create instance of MathLibrary class, prompt user to initialize array, ensures only 6 values can be entered, prints calculations
*/

#include <iostream>
#include <cmath>
#include "MathLibrary.h"
using namespace std; 

int main()
{
	MathLibrary grade_book;
	int i = 0;
	double value = 0;
	grade_book.Prompt();

	//Initializes grades vector with user input
	//Explicitly define loop to break at 4 or 6 grades
	while (grade_book.grades.size() != 6) {

		cout << "Grade: " << i << ": ";
		cin >> value;
		grade_book.grades.push_back(value);
		i++;
	}

	//Range-based for loop through grades vector and prints values
	cout << "\nGrade List: ";
	for (const double grade : grade_book.grades)
		cout <<  grade << ",";
	cout << endl;

	//Stores deviance vector for use in main
	vector<double> dev = grade_book.Deviance(grade_book.grades);

	cout << "Total: " << grade_book.Total(grade_book.grades) << endl;
	cout << "Average: " << grade_book.Average(grade_book.grades) << endl;
	cout << "Min: " << grade_book.Min(grade_book.grades) << endl;
	cout << "Max: "<< grade_book.Max(grade_book.grades) << endl;

	//Range-based for loop iterates through deviance vector and prints values
	cout << "Deviance List: ";
	for (auto& d : dev)
		cout << d << ",";
	cout << endl;

	//Stores output for Variance and Standard_Deviation methods
	double variance = grade_book.Variance(dev);
	double standard_deviation = grade_book.Standard_Deviation(variance);

	//Formats output via IO Manipulator setprecision and Fixed flag to represent value rounded tenths decimal
	cout.precision(1);
	cout << "Variance: " << fixed << variance << endl;
	cout << "Standard Deviation: " << fixed << standard_deviation << endl;
}


