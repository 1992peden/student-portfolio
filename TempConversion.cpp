//This program has menu options that take numeric input, do some math on it, and display appropriate output
// based on the menu selection. It also stores the entries in an array that can be displayed with some formatting.

#include <iostream>
#include <iomanip>
#include <array>


using namespace std;
float fckArray[3][10];//Farenheit, Celsius, Kelvin
int tempInstances;

void showMenu();
void showCelsius();
void showKelvin();

int main()
{
	int menuChoice;

	cout << "This program converts a temperature given in Farenheit to Celsius or Kelvin." << endl;
	cout << "A maximum of 10 temperatures can be entered." << endl; //Keep this outside of loops etc. so it only displays once

	showMenu();
	while (tempInstances < 10) {
			cin >> menuChoice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This line should clear the whole input stream.
			} //This checks for invalid inputs, such as if a user inputs a char by accident or because they're trying to break my nice things.

			switch (menuChoice) {
				case 1:
					showCelsius();
					showMenu();
					break;
				case 2:
					showKelvin();
					showMenu();
					break; //I think break is required to break out of the switch and go back to the while
				case 3:
					cout << "Data Entered:" << endl;
					for (int f = 0; f < tempInstances; f++) {
						if (f == 0) {
							cout << setw(12) << left << "\nFahrenheit: " << fckArray[0][f]; //Print Fahrenheit with extra space,
						}
						else cout << setw(8) << right << fckArray[0][f]; //then print the rest of this row with less space (since we don't want to reprint "Fahrenheit" every time).
					}
					for (int c = 0; c < tempInstances; c++) {
						if (c == 0) {
							cout << setw(13) << left << "\nCelsius: " << right << fckArray[1][c];
						}
						else cout << setw(8) << fckArray[1][c];
					}
					for (int k = 0; k < tempInstances; k++) {
						if (k == 0) {
							cout << setw(13) << left << "\nKelvin: " << right << fckArray[2][k];
						}
						else cout << setw(8) << fckArray[2][k];
					}
					cout << endl;
					showMenu();
					break;
				case 4:
					cout << "You have chosen to exit the program. Byeeee" << endl;
					return 0; //Pretty sure this is the right method to exit both the switch and the while loops.
					break;
				default:
					cout << "That isn't a valid input. Please enter 1, 2, 3, or 4." << endl;
					showMenu();
					break;
			}
	}
	
	while (tempInstances == 10) {
		cout << "\nNOTICE:" << endl << "You have reached the maximum number of temperatures this program can convert.You can select option 3 or 4." << endl;
		showMenu();
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			cout << "\nNOTICE:" << endl << "You have reached the maximum number of temperatures this program can convert.You can select option 3 or 4." << endl;
			break;
		case 2:
			cout << "\nNOTICE:" << endl << "You have reached the maximum number of temperatures this program can convert.You can select option 3 or 4." << endl;
			break;
		case 3:
			cout << "Data Entered:" << endl;
			for (int f = 0; f < tempInstances; f++) {
				if (f == 0) {
					cout << setw(12) << left << "\nFahrenheit: " << fckArray[0][f]; //Print Fahrenheit with extra space,
				}
				else cout << setw(8) << right << fckArray[0][f]; //then print the rest of this row with less space (since we don't want to reprint "Fahrenheit" every time).
			}
			for (int c = 0; c < tempInstances; c++) {
				if (c == 0) {
					cout << setw(13) << left << "\nCelsius: " << right << fckArray[1][c];
				}
				else cout << setw(8) << fckArray[1][c];
			}
			for (int k = 0; k < tempInstances; k++) {
				if (k == 0) {
					cout << setw(13) << left << "\nKelvin: " << right << fckArray[2][k];
				}
				else cout << setw(8) << fckArray[2][k];
			}
			cout << endl;
			break; //Admittedly, this display method falls apart if the user enters big numbers.
		case 4:
			cout << "You have chosen to exit the program. Byeeee" << endl;
			return 0;
		}
	}
	return 0;
}

void showMenu()
{
	cout << "\nSelect one of the following options: " << endl;
	cout << "\t1.\tConvert Fahrenheit to Celsius (Centigrade)" << endl;
	cout << "\t2.\tConvert Fahrenheit to Kelvin" << endl;
	cout << "\t3.\tDisplay data" << endl;
	cout << "\t4.\tQuit program" << endl;
	cout << "\nEnter your choice: ";
}

void showCelsius()
{
	float fTemp, cTemp, kTemp;

	cout << "\nEnter a Fahrenheit temperature: ";
	cin >> fTemp;
	if (fTemp > -459) {
		cTemp = (5.0 / 9.0) * (fTemp - 32);
		cout << fixed << setprecision(1) << "\n\t" << fTemp << " Fahrenheit = " << cTemp << " Celsius" << endl;

		kTemp = (5.0 / 9.0) * (fTemp - 32) + 273.15; //still need to calculate the Kelvin when running a Celsius conversion to store it in the array.
		fckArray[0][tempInstances] = fTemp; //Also, this should reassign each variable before it writes them to the array.
		fckArray[1][tempInstances] = cTemp;
		fckArray[2][tempInstances] = kTemp;
		tempInstances++; //should format the 2d array to put each temp in a column corresponding to the number of stored temps thus far, and then bump up that number
		// so that the program won't overwrite the previous numbers.
		//This method should also prevent out of bounds assignments, since main only runs these functions while tempInstances < 10.
	}
	else {
		cout << "That's below 0 Kelvin, which isn't technically possible. Enter a higher temperature.";
		showCelsius(); //This should restart this function without breaking anything in main or trying to store invalid temperatures...
	}
}

void showKelvin()
{
	float fTemp, kTemp, cTemp;

	cout << "\nEnter a Fahrenheit temperature: ";
	cin >> fTemp;
	if (fTemp > -459) {
		kTemp = (5.0 / 9.0) * (fTemp - 32) + 273.15;
		cout << fixed << setprecision(1) << "\n\t" << fTemp << " Fahrenheit = " << kTemp << " Kelvin" << endl;

		cTemp = (5.0 / 9.0) * (fTemp - 32);
		fckArray[0][tempInstances] = fTemp;
		fckArray[1][tempInstances] = cTemp;
		fckArray[2][tempInstances] = kTemp;
		tempInstances++; //Don't forget to increment
	}
	else {
		cout << "That's below 0 Kelvin, which isn't technically possible. Enter a higher temperature.";
		showKelvin(); //Don't increment tempInstances or write values outside the valid temperature range.
	}
}