// Collection.h
// Chandler Haukap
// Homework01 COSC 2030 part 2
// 9/22/17

#ifndef COLLECTION_H
#define COLLECTION_H

#include<iostream>
using std::endl;
using std::cout;
using std::cerr;

#include<stdlib.h> //for the random number generator

// Templated class that creates an array of objects. sixe of array specified at creation
template<class T>
class Collection
{
private:
	int size;
	T* collection;
	const int MAX_INDEX;
public:
	Collection(unsigned int entries) : MAX_INDEX(entries-1)
	{
		collection = new T[entries];
		size = 0;
		cout << "Collection at " << collection << " created." << endl << endl;
	}
	~Collection()
	{
		delete[] collection;
		cout << "Collection at " << collection << " destroyed." << endl << endl;
	}

	T get(int index); // for testing purposes
	bool isEmpty();
	void makeEmpty();
	bool insert(T x);
	bool remove(T x);
	void removeRandom();
	bool notContained(T x);
};

// Returns true iff the collection contains no objects
template<class T>
bool Collection<T>::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

// Removes an element of the array if that object exists.
// Object in array MUST have == operator defined.
template<class T>
bool Collection<T>::remove(T x)
{
	bool found(false);
	int counter(0);

	while (!found && counter < size)
	{
		if (collection[counter] == x)
		{
			found = true;
		}
		else
		{
			counter++;
		}
	}

	if (found)
	{
		while (counter < size) //move the rest of the entries down one to fill in the array
		{
			collection[counter] = collection[counter + 1];
			counter++;
		}
		size--;
	}
	return found;
}

// Returns true if the object cannot be found in the array.
// Object in array MUST have the == operator defined.
template<class T>
bool Collection<T>::notContained(T x)
{
	bool found(false);
	int counter(0);

	while (!found && counter < size)
	{
		if (collection[counter] == x)
		{
			found = true;
		}
		else
		{
			counter++;
		}
	}
	return !found;
}

// deletes the array and creates a new one of the same size. 
// this does not overwrite the data, but it does change the collection pointer.
template<class T>
void Collection<T>::makeEmpty()
{
	delete[] collection;
	collection = new T[MAX_INDEX + 1];
	size = 0;
}

// inserts an element to the end of the collection
// returns true if the operation was successful.
template<class T>
bool Collection<T>::insert(T x)
{
	if (size <= MAX_INDEX)
	{
		collection[size] = x;
		size++;
		return true;
	}
	return false;
}

// Removes a random entry from the collection.
// RNG seeded by the current size of the array and the max size
template<class T>
void Collection<T>::removeRandom()
{
	srand(size * MAX_INDEX); // uses the array size to seed the random number generator
	int index = rand() % size;

	while (index < size)
	{
		collection[index] = collection[index + 1];
		index++;
	}
	size--;
}

//Used for testing. Returns the value of a specific index. No exeption handling but does make sure that the index is legal.
template<class T>
T Collection<T>::get(int index)
{
	if (index < size)
	{
		return collection[index];
	}
	return NULL;
}

#endif
