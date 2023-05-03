//Quick program to spit out some maximum rent prices based on income.
//Throw it in a txt file to have around.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int income, maxRent, monthRent, counter;
	string outLine1, outLine2;
	ofstream rentIncomeFile;
	bool more = true;
	string input;

	rentIncomeFile.open("C://Users//1992p//Documents//Rent Income Comparisons.txt", ios::app);

	while (more) 
	{

		cout << "We're going to calculate the approximate rent you can afford based on";
		cout << " the mythical \"3x rent as income\". \n";
		cout << "\nSo, enter your estimated yearly income as an integer: ";

		cin >> income;
		maxRent = income / 3;
		monthRent = maxRent / 12;

		cout << "The maximum year rent price for you is approximately: $" << maxRent << endl;
		cout << "Per month: $" << monthRent << endl;

		rentIncomeFile << "\n \t" << '$' << income << "\t \t \t" << '$' << monthRent;

		cout << "Want to add another? y for yes, anything else for no: ";
		cin >> input;
		if (input == "y") {
			more = true;
		}
		else more = false;
	}
	rentIncomeFile.close();

	return 0;
}