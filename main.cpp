#include <iostream>
#include <fstream>
#include <sstream>
#include "SpellChecker.h"
using namespace std;

int main()
{
	string word;
	cout << "Enter a dictionary file to use (enter dictionary.txt if unsure)" << endl;
	cin >> word;
	ifstream wordlist(word);

	cout << "Loading dictionary..." << endl;
	SpellChecker checker(wordlist);

	cout << "Enter a word to check, or enter \"quit\" to quit" << endl;
	cin >> word;
	while(word != "quit")
	{
		stringstream input(word);
		checker.spellCheck(input, cout);
		cout << "Enter a word to check, or enter \"quit\" to quit" << endl;
		cin >> word;
	}

	wordlist.close();
}