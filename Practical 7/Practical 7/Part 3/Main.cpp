#include<iostream>
#include<string>
#include"LinkedList.h"
using namespace std;

void testListOfWords()
{
	// a linked list of words
	LinkedList< string> words;

	// reading and set up the list terminated by a full stop
	char ch;
	string word = "";
	while (ch = cin.get()) {
		if (ch == '.') {
			if (!word.empty()) {
				words.addAtEnd(word);
				word.clear();
			}
			break;
		}
		if (isalpha(ch)) {
			word += ch;
		}
		else {
			if (!word.empty()) {
				words.addAtEnd(word);
				word.clear();
			}
		}
	}
	words.setAtStart();
	for (int i = 0; i < words.size; i++) {
		cout << *words.getNext() << endl;
	}
}
void main() {

	testListOfWords();
	system("pause");
}