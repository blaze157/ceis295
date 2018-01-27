//hash table of words
#ifndef DICTIONARY
#define DICTIONARY

#include <string>
#include <vector>

class Dictionary
{
	struct Word
	{
		std::string word;
		int hash;
	};

	std::string To_Lower_Case(std::string word);

	std::vector<Word> words;

	int hash(std::string word);//some hashing algorythm
public:
	void addWord(std::string word);
	bool validWord(std::string word);//is word in dictionary?
};

#endif