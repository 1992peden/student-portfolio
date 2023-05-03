//fizzbuzz
#include <iostream>

using namespace std;

int main()
{
	//Use a for loop since we know the stopping point
	for (int c = 1; c <= 100; c++) {
		if (c % 5 == 0 && c % 7 == 0) {
		cout << "FIZZBUZZ ";
		//If c is divisible (no remainder) by 5 and 7, print FIZZBUZZ
		}
		else if (c % 5 == 0) {
			cout << "fizz ";
			//If divisble by 5 but not also 7, fizz
		}
		else if (c % 7 == 0) {
			cout << "buzz ";
			//If divisible by 7 but not also 5, buzz
		}
		else {
			cout << c << ' ';
			//Otherwise, print the number.
		}
	
	}

	cout << endl;
}