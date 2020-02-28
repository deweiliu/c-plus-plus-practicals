#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
void system_exit(string error_message) {
	cout << error_message << endl << "The program is about to exit." << endl;
	system("pause");
	exit(1);
}
void fileIO(char* fname_in, char* fname_out)
{
	// use input file stream to open the text file for input
	ifstream fin(fname_in);
	if (!fin) {
		cout << "File not found error " << fname_in << endl;
		return;
	}
	// use output file stream to open a text file for output
	ofstream fout(fname_out);
	// read all records in the file
	string record; // a whole record
	string name, id, city; // the name, id number and city fields in a record
	while (getline(fin, record)) {
		// use input string stream to extract the individual fields, one by one
		istringstream sin(record);
		/*******************************************************************/
		if (!(sin >> name)) {
			system_exit("You need a name.");
		}
		else {
			if (name.size() < 2) {
				system_exit("The name should be a string of characters.");
			}
		}
		/*******************************************************************/

		if (!(sin >> id)) {
			system_exit("You need a id");
		}
		else {
			if (id.size() != 7) {
				string temp = "The number of digits of ID is " ;
				temp += (char)(id.size()+'0');
				temp += ", but it must be 7.";
				system_exit(temp);
			}
		}
		/*******************************************************************/

		if (!(sin >> city)) {
			city = " "; // city name field is optional
		}
		else {
			if (city.size() < 2) {
				system_exit("The city name should be a string of characters.");
			}
			else {
				string temp;
				if (sin >> temp) {
					system_exit("There are more than 3 fields in one line.");
				}
			}
		}
		/*******************************************************************/

		// output each field in reverse order
		if (city != " ") fout << city << " ";
		fout << id << " " << name << "Hello\n";
	}
	// close the input file
	fin.close();
	// close the output file
	fout.close();
}

int main(int argc, char* argv[])
{
	// the user interface
	if (argc < 5) {
		cout << "Usage: " << endl;
		cout << " -i input_file_name " << endl;
		cout << " -o output_file_name" << endl;
		system("pause");
		return 0;
	}
	cout << "Hello, we got your input." << endl;
	// identify the arguments - the input/output file names
	int file_in = -1, file_out = -1;
	for (int i = 1; i < argc; i++) {
		if (string(argv[i]) == "-i") file_in = i + 1;
		if (string(argv[i]) == "-o") file_out = i + 1;
	}

	// call the function for file I/O
	if (file_in > 0 && file_out > 0) fileIO(argv[file_in], argv[file_out]);
	system("pause");
	return 0;
}