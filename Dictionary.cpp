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

template <class Word>
void Dictionary::addWord(std::string word)
{
	Word newWord;

	newWord.word = word;
	newWord.hash = hash(word);

	words.push_back(newWord);
}

template <class Word>
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

template <class Word>
bool Dictionary<Word>::IsEmpty(int KeyWord)
{
	if (key >= 0 && key < hashSize)
	{
		return head[key] == NULL;
	}
	return true;
}

template<class Word>
bool Dictionary<Word>::IsFull()
{
	try
	{
		node* location = new node;
		delete location;
		return false;
	}
	catch (std::bad_alloc&)
	{
		return true;
	}
}

template<class Word>
void Dictionary<Word>::Append(int key, Word NewWord)
{
	if (IsFull())
	{
		//std::cout<<"nAPPEND ERROR - HASH TABLE FULLn";
	}
	else
	{
		node* newNode = new node; // adds new node
		newNode->currentItem = newItem;
		newNode->next = NULL;
		if (IsEmpty(key))
		{
			head[key] = newNode;
		}
		else
		{
			node* tempPtr = head[key];

			while (tempPtr->next != NULL)
			{
				tempPtr = tempPtr->next;
			}
			tempPtr->next = newNode;
		}
		++bucketSize[key];
		++totElems;
	}

}
