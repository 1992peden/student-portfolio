//Take three numeric arguments and pass them to a function that determines which type of triangle
// would have sides of those lengths.

#include <iostream>

using namespace std;

enum triangleType {scalene, isosceles, equilateral, noTriangle};
triangleType triangleShape(double a, double b, double c);

int main()
{
	double a, b, c;

	cout << "Please enter three numbers as lengths of sides of a triangle: ";
	cin >> a >> b >> c;

	switch (triangleShape(a, b, c)) {
		case scalene:
			cout << "This triangle is scalene." << endl;
			break;
		case isosceles:
			cout << "This triangle is isosceles." << endl;
			break;
		case equilateral:
			cout << "This triangle is equilateral." << endl;
			break;
		case noTriangle:
			cout << "This is not a triangle." << endl;
			break;
	}

	return 0;
}

triangleType triangleShape(double a, double b, double c) {
	//If a + b > c && b + c > a && a + c > b, it's a triangle
	if ((a + b > c) && (a + c > b) && (b + c > a)) {
		if (a == b && a == c) return equilateral;
		else if (a == b || a == c || b == c) return isosceles;
		else return scalene;
	}
	else return noTriangle;
}