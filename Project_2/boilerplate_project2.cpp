// Project 2
// Summer 2022
// DSA 5005

#include <iostream>
#include <list>
#include <iterator> // for displaying list

using namespace std;

void emptyString(char* myString, int length) {
	for (int i = 0; i < length; i++) myString[i] = '\0';
}

// class prototype - since it is a recursive class
template <class DT>
class TrieDS;

template <class DT>
class TrieNode
{
public:
	TrieDS<DT>* _next; // pointing to the next address 
	list<DT>* _data; // store the data as a list	
	TrieNode();
};

// default constructor
template <class DT>
TrieNode<DT>::TrieNode()
{
	_next = NULL;
	_data = NULL;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template <class DT>
class TrieDS
{
public:
	TrieNode<DT>* myNodes; // array of length 26 to store the TrieNodes
	int depth; // given in the input

	TrieDS(); // default constructor
	int getCharPosition(DT str, int loc); // returns the index position 
											// for the loc-th position character in str
	void insert(DT str); // insert str to the structure depending on the depth
    void remove(DT str); // remove str from the structure - make sure to 
							// check if the list is empty and set it to NULL when 
							// removing the last word from the list
    int find(DT str); // find the the string str - return true or false 
	void displayMyNodes(); // display the entire myNodes array (list at each node)
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// main function
int main()
{
	char* tempWord = new char[20];
	char command;
	int mainDepth = 0;

	cin >> mainDepth; // read the depth from redirected input file

	TrieDS<char*> myTrie; // object of TrieDS

	// TODO: Read in from the redirected input file and perform the commands
        // You may use a while loop to go till eof() and a switch case inside



	return 0;
}

