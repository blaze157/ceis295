#ifndef DICTIONARY
#define DICTIONARY

#include <string>
#include <vector>

//We can ether make the hash table a const or let the user define it?
const int HASH_SIZE = 100;

template <class Word>
class Dictionary
{
	struct Word
	{
		std::string word;
		int hash;
	};
	struct Node
	{
		ItemType currentItem;
		Node* next;
	};

	std::string To_Lower_Case(std::string word);

	std::vector<Word> words;

	
public:
	void addWord(std::string word);
	bool validWord(std::string word);//is word in dictionary?


	//Constructor that initializes a hash table
	Dictionary(int hashSze = HASH_SIZE);
	~Dictionary();

	//Thinking it might work better as a function in main?
	std::string To_Lower_Case(std::string word);

	//To check if the table is empty 
	bool IsEmpty(int KeyWord);

	//To check if the table is full 
	bool IsFull();

	//Adds NewWord to the back of the list list at a given key in the hash table
	//A unique hash key is automatically generated for each NewWord
	void Insert(Word NewWord);

	//Adds new item to the end of the list at a given key in the hash table
	void Append(int key, Word NewWord);

	//Removes the first instance from the table whose value is "DeleteWord"
	//If I can figure it out, second parameter indicates the key where "DeleteWord" is located
	bool Remove(Word DeleteWord /*int key = -1*/);

	//Sort the items in the table at the given key
	void Sort(int key);

	//Return the size of the hash tabl
	int SizeOfHashTable();

	//The total number of elements contained in the hash table
	int TotalElems();

	//The number of items contained in the hash table cell at the given key
	int TableSize(int key);

	//The number of times a word appears in the table.
	int Count(Word WordSearch);

	//Initializes hash table to an empty state
	void MakeEmpty();

	//

};

#endif
