/*
Author: Andre Colin Chavez
Date: 07/26/2023
Assignment: Object Oriented Math Library
Description: Method definitions for Math Library Class. Calculates the total, average, min, max, deviance, variance, and standard deviation of 6 grades.
			 Methods pass vector by reference to ensure vectors values are not copied into each function separately.
			 Utilizes pointer functions, function call within other functions, passing by value and by reference. 
*/

#include "MathLibrary.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

void MathLibrary::Prompt() {


	cout << "Please enter 6 grades:" << endl;

}

//Input: vector by reference to reduce copying data 
//Output: total of values within vector
double MathLibrary::Total(const vector<double> &grades)
{
	
	double sum = 0;
	for(auto &grade : grades)
	{
		sum += grade;
	}

	return sum;
}

//Returns average of values within vector
double MathLibrary::Average(const vector<double> &grades)
{
	return Total(grades) / grades.size();
}

/*********Pointer*********/
//Utilizes min_element pointer function template from the algorithm library to return an iterator that points to the smallest value in the vector
double MathLibrary::Min(const vector<double>& grades)
{
	return *min_element(grades.begin(), grades.end());
}

////Utilizes max_element pointer function template from the algorithm library to return an iterator that points to the largest value in the vector 
double MathLibrary::Max(const vector<double>& grades)
{
	return *max_element(grades.begin(), grades.end());
}
/*********Pointer********/


//Calculates the Deviance of grades vector and returns a new vector of deviance values
vector<double> MathLibrary::Deviance(const vector<double>& grades)
{
	double deviance = 0;
	vector<double> deviance_list;
	double size = grades.size();
	double avg = Average(grades);

	for(int i = 0; i < size; i++)
	{
		deviance = pow(grades[i] - avg, 2);
		deviance_list.push_back(deviance);
	}

	return deviance_list;
}

//Returns Variance: Total of Deviance vector divided by Deviance vector size
double MathLibrary::Variance(const vector<double> &deviance)
{
	return Total(deviance) / deviance.size();
}

//Returns Standard Deviation: Square Root of Variance
double MathLibrary::Standard_Deviation(double variance)
{
	return sqrt(variance);
}
