#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<conio.h>
using namespace std;

void main(int argc, char * argv[]);

string get_argument(string identifier, int argc, char * argv[]);

void save_in_text(const string & file_name, const int * data, int sum);

void save_in_binary(const string & file_name, const int * data, int sum);

void print_data(const int * data, int sum);

int get_file_size(const string & file_name);

void read_in_binary(const string & file_name, int * data, int sum);

off_t file_size(const string & filename);

void read_in_text(const string & file_name, int * data, int sum);

void time_info(const string & message, time_t time);
