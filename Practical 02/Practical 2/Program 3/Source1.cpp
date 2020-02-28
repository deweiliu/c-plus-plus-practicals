#include<string>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include "Call-by-reference.h"
#include "Source1.h"
using namespace std;
void insert_function(int *&array, int &array_len) {
	int val, pos;
	cout << "Enter the value you want to insert : ";
	cin >> val;
	cout << "Enter the position you want to insert : ";
	cin >> pos;
	insert(array, array_len, pos-1, val);

}
void remove_function(int *&array, int &array_len) {
	int  pos;
	cout << "Enter the position of value you want to remove : ";
	cin >> pos;
	remove(array, array_len, pos-1);

}
void exit_function(int *&array) {
	free(array);
	cout << "Thank you! This program is going to exit.";
	Sleep(3000);
	exit(0);
}
bool function(int *&array, int &array_len) {
	print_menu();
	int option = _getch();
	option -= 48;
	switch (option) {
	case 1: insert_function(array, array_len); break;
	case 2: remove_function(array, array_len); break;
	case 3: exit_function(array); return 0;
	}
	return 1;
}
void print_menu() {
	cout << endl << "Press 1 if you want to insert a value" << endl;
	cout << "Press 2 if you want to remove a value" << endl;
	cout << "Press 3 if you want to delete the array and exit." << endl;
}