#include <iostream>
#include <fstream>
#include <sstream>
#include "SpellChecker.h"
using namespace std;

void spellCheck(istream& inf, istream& wordlistfile, ostream& outf)
{
	SpellChecker checker = SpellChecker(wordlistfile);
	checker.spellCheck(inf, outf);
}

int main()
{
	string word;
	cout << "Enter a dictionary file to use (enter dictionary.txt if unsure)" << endl;
	cin >> word;
	ifstream wordlist(word);

	cout << "Enter a word to check, or enter \"quit\" to quit" << endl;
	cin >> word;
	while(word != "quit")
	{
		istringstream input(word);
		spellCheck(input, wordlist, cout);
		cout << "Enter a word to check, or enter \"quit\" to quit" << endl;
		cin >> word;
	}
}