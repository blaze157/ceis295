#include "Dictionary.h"

int Dictionary::hash(std::string word)
{
	//make sure strings are converted to lower case to
	//avoid missing correct words due to case difference

	return 0;//obviously not finished yet
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