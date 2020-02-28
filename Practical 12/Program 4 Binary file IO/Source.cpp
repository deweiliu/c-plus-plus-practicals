
#include "Source.h"

//The string inputed to the main() is as follow
//- r 1000000 - t text.txt - b binary.txt

#define RANGE 16383
//#define RANGE 10

void main(int argc, char* argv[]) {
	string dir(argv[0]);
	dir = dir.substr(0, dir.find_last_of("\\") + 1);

	//Create data
	int sum = atoi(get_argument("-r", argc, argv).c_str());
	cout << "We are writting " << sum << " intergers to " << dir << endl << "Please wait..." << endl;
	int *data = new int[sum];
	for (int i = 0; i < sum; i++) {
		data[i] = (rand() % RANGE) - (RANGE / 2);
	}

	/*************************************************************************/
	//string dir = "I:\\QUB\\Level 2\\CSC2040 Data Structures, Algorithms and Programming Languages\\Praticals\\Practical 12\\Practical 12\\Program 4 Binary file IO\\";
	string text_file_dir = dir + get_argument("-t", argc, argv);
	string binary_file_dir = dir + get_argument("-b", argc, argv);
	time_t start, end;
	/*************************************************************************/
	//Write in text
	start = clock();
	save_in_text(text_file_dir, data, sum);
	end = clock();
	cout << "The size of the text file is " << file_size(text_file_dir) / (double)1024 << " KB." << endl;
	time_info("save data in text", end - start);
	/*************************************************************************/
	//Write in binary
	start = clock();
	save_in_binary(binary_file_dir, data, sum);
	end = clock();
	cout << "The size of the binary file is " << file_size(binary_file_dir) / (double)1024 << " KB." << endl;
	time_info("save data in binary", end - start);
	/*************************************************************************/
	delete[] data;
	data = new int[sum];


	/*************************************************************************/
	//read in binary
	read_in_binary(binary_file_dir, data, sum);
	cout << "The data from the binary file.";
	print_data(data, sum);

	/*************************************************************************/
	//read in text
	read_in_text(text_file_dir, data, sum);
	cout << "\n\nThe data from the text file.";
	print_data(data, sum);


	delete[]data;
	cout << "\n\nDONE\n";
	system("pause");
}
string get_argument(string identifier, int argc, char* argv[]) {
	if (identifier == "") {
		return argv[0];
	}
	for (int i = 1; i < argc; i++) {
		if (string(argv[i]) == identifier) {
			return string(argv[i + 1]);
		}
	}
	return nullptr;
}
void save_in_text(const string&  file_name, const int* data, int sum) {
	ofstream fout(file_name);
	for (int i = 0; i < sum; i++) {
		fout << data[i] << " ";
	}
	fout.close();
}
void save_in_binary(const string& file_name,const int* data, int sum) {
	ofstream fout(file_name, ios::binary);
	fout.write((char*)data, sizeof(*data)*sum);
	fout.close();
}
void print_data(const int*data, int sum) {
	cout << "\nPress Y if you want to print the array, or press other key if not.";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		cout << endl << "The array is as follow:";
		for (int i = 0; i < sum; i++) {
			if (i % 10 == 0) {
				cout << endl;
			}
			cout << data[i] << "\t";
		}
		cout << endl;
	}
	cout << "Please wait...\n";
}
int get_file_size(const string& file_name) {
	struct stat filestatus;
	stat(file_name.c_str(), &filestatus);
	return filestatus.st_size;
}



void read_in_binary(const string& file_name, int* data, int sum) {
	ifstream fin(file_name, ios::binary);

	if (!fin) {
		cerr << "Sorry, we cannot find that file.\n";
		system("pause");
		exit(0);
	}

	fin.read((char*)data, sizeof(*data)*sum);
	fin.close();
}

off_t file_size(const string& filename) {
	struct stat s;
	stat(filename.c_str(), &s);
	return s.st_size;
}
void read_in_text(const string& file_name, int* data, int sum) {
	ifstream fin(file_name);
	if (!fin) {
		cerr << "Sorry, we cannot find that file.\n";
		system("pause");
		exit(0);
	}
	for (int i = 0; i < sum; i++) {
		fin >> data[i];
	}
	fin.close();
}
void time_info(const string& message, time_t time) {
	cout << "The time for " << message << " is " << time << " milliseconds." << endl;
}