// A simple string input/output using getline and one formatting tool.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string name_1, name_2, name_3;

	cout << "Please enter the first name: ";
	getline(cin, name_1);

	cout << "\nPlease enter the second name: ";
	getline(cin, name_2);

	cout << "\nPlease enter the third name: ";
	getline(cin, name_3);

	cout << setw(15);
	cout << "Customer Names" << endl;
	cout << setw(15) << name_1 << endl;
	cout << setw(15) << name_2 << endl;
	cout << setw(15) << name_3 << endl;

	return 0;
}