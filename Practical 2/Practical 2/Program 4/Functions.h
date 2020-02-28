#pragma once


void get_array_value(int * a, int length, int position);

void init_array_value(int * a, int length);

bool compare_array(int * a, int * b, int length);

int find_value(int value, int * array, int length);

void remove_value(int *& array, int array_len, int pos);


void print_array(int * array, int length);

int get_array_size();
