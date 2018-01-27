#include "Dictionary.h"

std::string Dictionary::To_Lower_Case(std::string word)
{
	//converting everyword to its lowercase
	for (unsigned c = 0; c < word.length(); ++c)
	{
		//using tolower function for lower case conversion
		word[c] = tolower(word[c]);
	}
	//returning the lowercase word
	return word;
}

int Dictionary::hash(std::string word)
{
	To_Lower_Case(word);

	//We can start out with sdbm because it's easy
	int hash = 0;
	for (int i = 0; i<word.length(); i++){
	    hash = word[i] + (hash << 6) + (hash << 16) - hash;
	}

	return hash;
}

void Dictionary::addWord(std::string word)
{
	Word newWord;

	newWord.word = word;
	newWord.hash = hash(word);

	words.push_back(newWord);
}
bool Dictionary::validWord(std::string word)
{
	int wordHash = hash(word);
	for(int i=0; i<words.size(); i++)
	{
		if(wordHash == words[i].hash)
		{
			return true;
		}
	}

	return false;
}