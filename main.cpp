#include <iostream>
#include <string>

#include "Dictionary.h"

Dictionary dictionary;

void loadDictionary()
{
	//this should probably load from a file eventually
	dictionary.addWord("the");
	dictionary.addWord("cat");
	dictionary.addWord("bat");
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