#ifndef UCONVERT_H
#define UCONVERT_H

#include <iostream>
using namespace std;

// base class as interface
class uConvert {
public:
	virtual void read_unit() = 0;
	virtual void convert() = 0;
	virtual void print() = 0; 

private:
	double in_value;
	double out_value;
};

// convert litre to gallon
class l2g : public uConvert
{
	void read_unit() {
		cout << "Enter the value of litre: ";
		cin >> in_value;
	}
	void convert() { out_value = in_value / 3.7854; }
	void print() { cout << "= " << out_value << " gallons" << endl << endl; }
};

// convert Fahrenheit to Celsius
class f2c : public uConvert
{
	void read_unit() {
		cout << "Enter the degrees in Fahrenheit: ";
		cin >> in_value;
	}
	void convert() { out_value = (in_value - 32) / 1.8; }
	void print() { cout << "= " << out_value << " degrees in Celsius" << endl << endl; }
};

// convert feet to meter
class f2m : public uConvert
{
	void read_unit() {
		cout << "Enter the number of feet: ";
		cin >> in_value;
	}
	void convert() { out_value = in_value / 3.28; }
	void print() { cout << "= " << out_value << " meters" << endl << endl; }
};

#endif
