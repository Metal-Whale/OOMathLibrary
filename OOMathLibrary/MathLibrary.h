/*
Author: Andre Colin Chavez
Date: 07/26/2023
Assignment: Object Oriented Math Library
Description: Header file for MathLibrary Class
*/

#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MathLibrary
{

public:
	vector<double> grades;
	void Prompt();
	double Total(const vector<double>& grades);
	double Average(const vector<double> &grades);
	double Min(const vector<double>& grades);
	double Max(const vector<double>& grades);
	vector<double> Deviance(const vector<double> &grades);
	double Variance(const vector<double> &deviance);
	double Standard_Deviation(double variance);

};

