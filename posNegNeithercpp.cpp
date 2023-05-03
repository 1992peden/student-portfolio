/*This program will prompt the user to enter a number. Then, the program will evaluate and determine whether said number
is positive, negative, or 0.*/

#include <iostream>//Basic input/output
#include <string>//String inclusion and manipulation

using namespace std;//Remove some clutter

int main() {
	double numIn; //We'll use a double to include a wide range of numbers.
	bool goAgain = true;//Practicing a loop.
	string keepGoing;//Use string incase user mashes the keyboard when entering their choice.

	while (goAgain) {//Do all this while goAgain is true. We declared it as true, so this runs at least once.

		cout << "\nGive me a number, I'll tell you if it's positive, negative, or zero." << endl;
		cout << "Alright, I'm ready: ";
		cin >> numIn;

		if (cin.fail()) {
			cout << "\nI don't know what that is, let's go again." << endl;
		}//Just incase the input fails, including numbers outside the scope of double.

		else if (numIn > 0) {
			cout << "\nEasy, that's a positive number." << endl;//Positive means >0, so here we go.
			cout << "Wanna go again? y for yes or anything else for no: ";
			cin >> keepGoing;
			if (keepGoing != "y") goAgain = false;//So anything but 'y' will set goAgain to false.
		}

		else if (numIn < 0) {
			cout << "\nEasy, that's a negative number." << endl;//Negative means <0, so here we go.
			cout << "Wanna go again? y for yes or anything else for no: ";
			cin >> keepGoing;
			if (keepGoing != "y") goAgain = false;
		}
		else {
			cout << "\nToo easy, that's 0." << endl;//else should work, input can only be a fail, >0, <0, or ==0.
			cout << "Wanna go again? y for yes or anything else for no: ";
			cin >> keepGoing;
			if (keepGoing != "y") goAgain = false;
		}
	}

	cout << "\nLater, skater." << endl;

	return 0;
}
