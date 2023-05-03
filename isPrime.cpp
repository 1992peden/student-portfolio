/* This program should accept input in the form of an integer from 1-1000, and let the user know if it's prime.
* I'll be attempting to include a check for the input stream incase of invalid input.
* If the number is not prime, the program should give back the prime numbers by which their number is divisible.
*/

#include <iostream>
#include <array>

using namespace std;


int main()
{
    int numChoice;
    int primes[11]{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };//This program will only check the first 11 prime numbers.
    bool isPrime = true;

    cout << "This program will tell you if a number between 1-1000 is prime." << endl;
    cout << "Please enter a WHOLE NUMBER between 1-1000: "; //Be specific with the user.
    cin >> numChoice;

    if (cin.good() && numChoice < 1001 && numChoice > 0) { //Do this if the input is valid.
        cout << '\n'; //Formatting
        for (int i = 0; i < 11; i++) {//Use a for loop to check the if statement using the entries of the array.
            if (numChoice == primes[i]) {//Have to check numChoice against the array, since the array holds the first 11 prime numbers.
                cout << "That's a prime number." << endl;
                isPrime = false; //Just because we don't want to repeat ourselves.
            }
            else if (numChoice % primes[i] == 0) {//Print each number from the array that the input numChoice is divisible by.
                cout << "Your number is divisible by " << primes[i] << endl;
                isPrime = false;//Set the boolean for prime number to false.
            }
        }
        if (isPrime) {//If the for loop doesn't find a number that numChoice is divisible by, isPrime stays true, meaning numChoice is a prime number.
            cout << "That's a prime number." << endl;
            return 0;
        }

    }

    else if (cin.fail()) { //Do this if the input is invalid.
        cout << "\nThat's not the right input, you broke it." << endl;
        //Side note, if the number is too big, we get a cin.fail- presumably because we exceeded the int memory capacity.
    }

    else { //Do this if input is "valid" but outside the range we want.
        cout << "\nThat's not a WHOLE NUMBER between 1 and 1000. Bye." << endl;
    }

    cout << "\nI won't ask if you had fun, but I hope this at least works." << endl; //bye

    return 0;
}