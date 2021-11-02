// Emerson Racca
// 10/27/2021
// Lab 9c - Pentagon Structure Constructor

/*
Code a constructor for your Pentagon class.

In the main, code an array (or vector) of 50 pentagons and populate the array (or vector) with random data.

In a separate for loop, print the properties of each pentagon in the array.

NO USER INTERFACE on this lab.
*/

#include<iostream>
#include<cstdlib> // srand(), rand()
#include<ctime> // time()
#include<iomanip> // setprecision()
#include<cmath>
#include<vector>

using namespace std;

struct Pentagon {
	double side;
	string color;

	Pentagon(double s = 1.0, string c = "black");

	double r(void); //for inscribed circle
	double R(void); //for circumscribed circle
	void print(void); //print
	double area();
	double perimeter();
};


int main(void) {
	srand((unsigned int)time(0));
	cout << fixed << setprecision(2);

	int size = 50;
	vector<Pentagon> pent; //Specifying size here does not work since those objects are created.

	cout << "Pentagon Structure Constructor\n\n";

	//To choose from random colors.
	string c[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white" };


	for (int i = 0; i < size; i++) {
		// Using the technique in the class lecture to populate the vector.
		pent.push_back(Pentagon(1.0 + rand() % 100 + 1.0 * rand() / RAND_MAX, c[rand() % 10]));
	}

		
	for (unsigned int i = 0; i < pent.size(); i++) {
		cout << "Element with index " << i << " --" << endl;
		pent[i].print();
	}

	return 0;
}

//Constructor.
Pentagon::Pentagon(double s, string c) {
	side = s;
	color = c;
}

// Print pentagon object.
void Pentagon::print(void) {
	cout << "Side length : " << side << endl;
	cout << "Inner Radius: " << r() << endl;
	cout << "Outer Radius: " << R() << endl;
	cout << "Color       : " << color << endl;
	cout << "Area        : " << area() << endl;
	cout << "Perimeter   : " << perimeter() << endl;
	cout << endl;
}

// Compute r, where r is the radius of the inscribed circle. Also known as the apothem.
double Pentagon::r(void) {
	return (1.0 * side / (2.0 * tan(36.0 * 3.1415926 / 180))); // radian conversion
}

// Compute R, where R is the radius of the circumscribed circle.
double Pentagon::R(void) {
	return ((1.0 * side) / (2.0 * sin(36.0 * 3.1415926 / 180)));
}

// Compute area.
double Pentagon::area() {
	return ((5.0 * pow(side, 2.0)) / (4.0 * tan(36.0 * 3.1415926 / 180)));
}

// Compute perimeter.
double Pentagon::perimeter() {
	return 5.0 * side;
}