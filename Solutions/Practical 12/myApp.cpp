#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

// return true/false if a given string is/is not a string of characters (including ')
bool is_name(const string& s)
{
	string::const_iterator i = s.begin();
	while (i != s.end() && (isupper(*i) || islower(*i) || *i == '\'')) i++;
	return !s.empty() && i == s.end();
}

// return true/false if a given string is/is not a 7-digit number
bool is_7digits(const string& s)
{
	string::const_iterator i = s.begin();
	while (i != s.end() && isdigit(*i)) i++;
	return s.size() == 7 && i == s.end();
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
	string record;				// a whole record
	string name, id, city;		// the name, id number and city fields in a record
	while (getline(fin, record)) {
		// use input string stream to extract the individual fields, one by one
		istringstream sin(record);

		// the first field must be a name
		sin >> name;	
		if (!is_name(name)) {
			cout << "Inappropriate name: " << name << endl;
			exit(1);
		}

		// the second field must a 7-digit number
		sin >> id; 
		if (!is_7digits(id)) {
			cout << "Invalid id number: " << id << endl;
			exit(1);
		}

		if (!(sin >> city)) city = " ";	// city name field is optional

		// the third field exists, it must be a name
		if (city != " " && !is_name(city)) {
			cout << "Inappropriate city name: " << city << endl;
			exit(1);
		}

		// no more field after the city field
		if (!sin.eof()) {
			cout << "Extraneous data field found: " << record << endl;
			exit(1);
		}

		// output each field in reverse order
		if (city != " ") fout << city << " ";
		fout << id << " " << name << endl;
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
		cout << "  -i input_file_name " << endl;
		cout << "  -o output_file_name" << endl;
		return 0;
	}

	// identify the arguments - the input/output file names
	int file_in = -1, file_out = -1;
	for (int i = 1; i < argc; i++) {
		if (string(argv[i]) == "-i") file_in = i + 1;
		if (string(argv[i]) == "-o") file_out = i + 1;
	}

	// call the function for file I/O
	if(file_in > 0 && file_out > 0) fileIO(argv[file_in], argv[file_out]);

	return 0;
}

int main2(int argc, char* argv[])
{
	// the user interface
	if (argc < 7) {
		cout << "Usage: " << endl;
		cout << "  -t text_file_name " << endl;
		cout << "  -b binary_file_name" << endl;
		cout << "  -n size of data" << endl;
		return 0;
	}

	// identify the arguments - the input/output file names, and the data size
	int fn_txt = -1, fn_bin = -1, num = -1;
	for (int i = 1; i < argc; i++) {
		if (string(argv[i]) == "-t") fn_txt = i + 1;
		if (string(argv[i]) == "-b") fn_bin = i + 1;
		if (string(argv[i]) == "-n") num = stoi(argv[i + 1]);
	}

	// invalid parameter(s), return doing nothing
	if (fn_txt < 0 || fn_bin < 0 || num <= 0) {
		cout << "Invalid parameter(s)." << endl;
		return 1;
	}

	// populate the array with random numbers
	int* data = new int[num];
	for (int n = 0; n < num; n++)
		data[n] = rand() % 32768 - 16384;

	// save the data in a text file
	clock_t begin = clock();

	ofstream fout_txt(argv[fn_txt]);
	for (int n = 0; n < num; n++) fout_txt << data[n] << endl;
	fout_txt.close();

	clock_t end = clock();
	double elapsed = double(end - begin);
	cout << "Time to save (in txt mode) " << num << " numbers = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl;

	// save the data in a binary file
	begin = clock();

	ofstream fout_bin(argv[fn_bin], ios::binary);
	fout_bin.write((char*)data, sizeof(int) * num);
	fout_bin.close();

	end = clock();
	elapsed = double(end - begin);
	cout << "Time to save (in bin mode) " << num << " numbers = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl;

	// read data from the text file
	begin = clock();

	ifstream fin_txt(argv[fn_txt]);
	for (int n = 0; n < num; n++) fin_txt >> data[n];
	fin_txt.close();

	end = clock();
	elapsed = double(end - begin);
	cout << "Time to read (in txt mode) " << num << " numbers = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl;

	// read data from the binary file
	begin = clock();

	ifstream fin_bin(argv[fn_bin], ios::binary);
	fin_bin.read((char*)data, sizeof(int) * num);
	fin_bin.close();

	end = clock();
	elapsed = double(end - begin);
	cout << "Time to read (in bin mode) " << num << " numbers = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl;

	delete[] data;
	return 0;
}

