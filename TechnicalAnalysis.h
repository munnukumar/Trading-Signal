#pragma once
#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>



class TechnicalAnalysis
{
public:
	double  calculateFiftyMA();
	double calculateTwentyMA();
	double calculateTwohundredMA();

	double calculateRSIOfDrReddy();
	double calculateRSIOfNifty();
	double calculateRSIOfRel();
	double calculateRSIOfLAndT();
	double calculateRSIOfMAndM();

	double calculateEMAOfDrReddy();
	double calculateEMAOfNifty();
	double calculateEMAOfRel();
	double calculateEMAOfLAndT();
	double calculateEMAOfMAndM();

	double calculateWMAOfDrReddy();
	double calculateWMAOfNifty();
	double calculateWMAOfRel();
	double calculateWMAOfLAndT();
	double calculateWMAOfMAndM();

	void signal();

};


