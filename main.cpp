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

//these return true on success
bool swapChar(std::string word)
{
	
}
bool addChar(std::string word)
{

}
bool deleteChar(std::string word)
{
	
}
bool replaceChar(std::string word)//I didn't test this but it should be close
{
	std::string originalWord = word;

	int letter = 0;
	do
	{
		word[letter]++;
		if(word[letter] > 'z')
		{
			word[letter] = 'a';
		}

		if(dictionary.validWord(word))
		{
			std::cout << "Is " << word << " the correct word? y:n" << std::endl;
			std::string answer;
			std::cin >> answer;
			if(answer == "y")
			{
				return true;
			}
		}	

		if(word == originalWord &&  letter < word.length())
		{
			letter++;
		}
	}
	while(word != originalWord);

	return false;
}

void correct(std::string word)
{
	if(!swapChar(word)
	&&!addChar(word)
	&&!deleteChar(word)
	&&!replaceChar(word))
	{
		std::cout << "Could not correct word." << std::endl;
	}
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