#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include "area.h"
using namespace std;

//int area(int length, int width)
//{
    //compute & return area
//	return length * width;

//}

//Program 1
int main() {
	string name;
	cout << "Please enter your name\n";
	cin >> name;
	cout << "Hello World" << endl;
	cout << "Your name is " << name << endl;

	//cout << "The area is " << area(7, 3) << endl;

	int l, w;
	cout << ("Please enter a lenght\n");
	cin >> l;
	cout << ("Please enter a width\n");
	cin >> w;
	//cout << "The area is " << area(l, w) << endl;

	srand((unsigned)time(NULL));
	int randomNumber = rand() % 10;;
	int go = 0;	
	while (go < 3) {
		int magic;
		cout << "Enter your Guess for the Number : ";
		cin >> magic;
		if (randomNumber == magic)
		{
			cout << "Congratulation Right Guess\n";
		}
		else
		{
			cout << "Sorry Wrong Guess\n";
		}
		go++;
	}

	return 0;
}