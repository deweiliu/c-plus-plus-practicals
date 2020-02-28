#include<iostream>
#include<string>
#include<random>
#include<fstream>
#include<math.h>
#include "Graph.h"

using namespace std;

double average_2d(int N, int M, int maxV);
int count_3d(int N, int M, int L, char c);

void rectangleArea_txt(int length, int width, char * fname);

void rectangleArea_bin(int length, int width, char * fname);

int calculateArea(int length, int width);

size_t hash_index(const string & street, const string & city, const string & postcode, int length, size_t tableSize);

size_t get_index(const string & word, int length, int& startPower);

void testGraph(char * fname);

void main() {
	/****************************************************************************/
	//Part 1

	//1
	cout << endl << "Part 1 - 1" << endl;
	cout << average_2d(10, 20, 10) << endl;

	//2
	cout << endl << "Part 1 - 2" << endl;
	cout << count_3d(10, 20, 30, 'a') << endl;

	//3
	cout << endl << "Part 1 - 3" << endl;
	char* txt = "text.txt";
	char* bin = "binary.txt";
	const int LENGTH = 10;
	const int WIDTH = 20;
	rectangleArea_txt(LENGTH, WIDTH, txt);
	rectangleArea_bin(LENGTH, WIDTH, bin);

	//Part 1
	/****************************************************************************/
	//Part 2	
	cout << endl << "Part 2" << endl;

	const string street = "HelloStreet";
	const string  city = "HelloCity";
	const string postcode = "HEL LOO";
	int length = 7;
	size_t tableSize = 23;

	cout << "Result for the function : size_t hash_index(const string& street, const string & city, const string& postcode, int length, size_t tableSize);\n";
	cout << hash_index(street, city, postcode, length, tableSize) << endl;


	//Part 2
	/****************************************************************************/
	//Part 3
	cout << endl << "Part 3" << endl;
	char* FILE_NAME = "graph.txt";
	testGraph(FILE_NAME);

	//Part 3
	/****************************************************************************/

	system("pause");
}



/****************************************************************************/
//Part 1 functions

double average_2d(int N, int M, int maxV) {
	if (N <= 0 || M <= 0 || maxV <= 0) {
		cout << "Inappropriate arguments" << endl;
		return 0.;
	}


	double** array = new double*[N];

	//1 & 2 creating a 2d array and assign with random numbers
	for (int i = 0; i < N; i++) {
		array[i] = new double[M];
		for (int j = 0; j < M; j++) {
			array[i][j] = rand() % (maxV + 1);
		}
	}

	//3 calculating the average
	double sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum += array[i][j];
		}
	}
	double average = sum / (M*N);

	//4. delete array
	for (int i = 0; i < N; i++) {
		delete[] array[i];
	}
	delete[]array;

	//5 return the average
	return average;
}

int count_3d(int N, int M, int L, char c) {
	char*** array = new char**[N];


	//1 & 2 creating a 3d array and assign with random chars

	//1d
	for (int i = 0; i < N; i++) {
		array[i] = new char*[M];

		//2d
		for (int j = 0; j < M; j++) {
			array[i][j] = new char[L];

			//3d
			for (int k = 0; k < L; k++) {
				array[i][j][k] = 'a' + rand() % 26;
			}
		}
	}


	//3 count the number of occurrences of c
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < L; k++) {
				if (array[i][j][k] == c) {
					count += 1;
				}
			}
		}
	}

	//delete array
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			//delete 3d
			delete[] array[i][j];
		}

		//delete 2d
		delete[] array[i];
	}

	//delete 1d
	delete[] array;


	return count;
}

void rectangleArea_txt(int length, int width, char*fname) {
	//write the values
	ofstream fout(fname);
	fout << length << endl;
	fout << width << endl;
	fout << calculateArea(length, width);
	fout.close();


	//read the values
	ifstream fin(fname);
	int getLength, getWidth, getArea;
	fin >> getLength;
	fin >> getWidth;
	fin >> getArea;
	fin.close();

	//output
	cout << "\nResult for the function : void rectangleArea_txt(int length, int width, char*fname);" << endl;
	cout << "Length = " << getLength << "\t";
	cout << "Width = " << getWidth << "\t";
	cout << "Area = " << getArea << "\n";

}


void rectangleArea_bin(int length, int width, char*fname) {
	//write the values
	ofstream fout(fname, ios::binary);
	fout.write((char*)&length, sizeof(int));
	fout.write((char*)&width, sizeof(int));
	int area = calculateArea(length, width);
	fout.write((char*)&(area), sizeof(int));
	fout.close();


	//read the values
	ifstream fin(fname, ios::binary);
	int getLength, getWidth, getArea;
	fin.read((char*)&getLength, sizeof(int));
	fin.read((char*)&getWidth, sizeof(int));
	fin.read((char*)&getArea, sizeof(int));
	fin.close();

	//output
	cout << "\nResult for the function : void rectangleArea_bin(int length, int width, char*fname);\n";
	cout << "Length = " << getLength << "\t";
	cout << "Width = " << getWidth << "\t";
	cout << "Area = " << getArea << "\n";
}

int calculateArea(int length, int width) {
	return length*width;
}

//Part 1 functions
/****************************************************************************/
//Part 2 functions
size_t hash_index(const string& street, const string & city, const string& postcode, int length, size_t tableSize) {
	size_t index = 0;

	int power = 0;
	index += get_index(street, length, power);

	index += get_index(city, length, power);

	index += get_index(postcode, length, power);

	index = index%tableSize;
	return index;
}
size_t get_index(const string& word, int length, int& power) {
	int index = 0;
	int primeNumber = 37;
	for (int i = 0; i < word.size() && i < length; i++) {
		index += ((int)word[i])*pow(primeNumber, power);
		power++;
	}

	return index;
}

//Part 2 functions
/****************************************************************************/
//Part 3 functions
void testGraph(char* fname) {
	//Task 1
	Graph graph(fname);
	//Task 2
	int source = -1, destination = -1;
	double weight = INT_MAX;

	//Undirected
	if (graph.directed == false) {
		for (int i = 0; i < graph.num_v; i++) {
			for (int j = 0; j <= i; j++) {
				if ((graph.edges)[i][j] == 0) {
					//No edge
				}
				else {
					if ((graph.edges)[i][j] < weight) {
						weight = (graph.edges)[i][j];
						source = i;
						destination = j;
					}
				}
			}
		}
	}

	//Directed
	else {
		for (int i = 0; i < graph.num_v; i++) {
			for (int j = 0; j <= graph.num_v; j++) {
				if ((graph.edges)[i][j] == 0) {
					//No edge
				}
				else {
					if ((graph.edges)[i][j] < weight) {
						weight = (graph.edges)[i][j];
						source = j;
						destination = i;
					}
				}
			}
		}
	}

	//Task 3
	cout << "The edge with the lowest weight : \n";
	cout << source << "\t";
	cout << destination << "\t";
	cout << weight << "\n";
}

//Part 3 functions
/****************************************************************************/
