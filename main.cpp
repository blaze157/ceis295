#include <iostream>
#include <string>
#include <fstream>

#include "Dictionary.h"

Dictionary dictionary;

void loadDictionary()
{
	std::ifstream in("dictionary.txt");
	std::string word = "";
	while(in >> word)
	{
		dictionary.addWord(word);
	}
}

void correct(std::string word)
{
	while(!dictionary.validWord(word))
	{
		std::cout << "You are now in an infinate loop because the software is not finished." << std::endl;
		std::cout << "Sorry about that." << std::endl;
		//alter the word somehow
	}
	std::cout << "good word" << std::endl;
}

int main()
{
	loadDictionary();
	std::string word = "";
	std::cout << "Enter a word or 0 to quit" << std::endl;

	while(word != "0")
	{
		std::cin >> word;
		correct(word);
	}

	std::cout << "Goodbye" << std::endl;

	return 0;
}