// Chandler Haukap
// Homework01 COSC 2030 part 2
// Test code for Collection templated class
// 9/22/17

#include "Collection.h"

int main()
{
	Collection<int> cows(10);
	cout << cows.isEmpty() << endl << endl;
	cows.insert(6);
	cows.insert(34);
	cows.insert(4);
	cout << cows.isEmpty() << endl << endl;
	cows.remove(4);
	cows.remove(34);
	cows.remove(6);
	cout << cows.isEmpty() << endl << endl;
	cows.insert(6);
	cows.insert(34);
	cows.insert(4);
	//Ensure that the remove function moves all of the entries back one
	cout << "cows[1] = " << cows.get(1) << endl << endl; 
	cows.remove(34);
	cout << "After removing 34, cows[1] = " << cows.get(1) << endl << endl;

	Collection<double> chickens(2);
	chickens.insert(5.5);
	chickens.insert(3.1);
	if (chickens.insert(57.5)) //array is already full
	{
		cout << 57.5 << " Was writen to memory unallocated memory" << endl << endl; //ensure it is not overwriting other memory
	}
	chickens.remove(5.5); //make room
	if (chickens.insert(57.5)) //try again
	{
		cout << 57.5 << " Was writen to memory" << endl << endl; 
	}
	cout << chickens.get(43) << endl << endl; //make sure it does not try to read outside of its memory

	//Test notContained(x) function
	Collection<float> ducks(10);
	if (ducks.notContained(0)) //test notContained function
	{
		cout << "Could not find 0" << endl << endl; //this should be displayed
	}
	else
	{
		cout << "Found a 0 that does not exist" << endl << endl;
	}
	ducks.insert(0);
	if (ducks.notContained(0)) //test notContained function
	{
		cout << "Could not find 0" << endl << endl;
	}
	else
	{
		cout << "Found 0" << endl << endl; //this should be displayed
	}

	//Test makeEmpty() function
	Collection<unsigned int> turkeys(10);
	turkeys.insert(32);
	turkeys.insert(22);
	turkeys.insert(76);
	turkeys.insert(92);
	turkeys.insert(45);
	turkeys.insert(23);
	turkeys.insert(99);
	turkeys.insert(123);
	cout << "Before makeEmpty(): " << turkeys.get(0) << endl << endl;
	turkeys.makeEmpty(); //test makeEmpty function.
	cout << "After makeEmpty(): " << turkeys.get(0) << endl << endl;

	//Test the removeRandom() function
	Collection<double> pigs(6);
	pigs.insert(1);
	pigs.insert(2);
	pigs.insert(3);
	pigs.insert(4);
	pigs.insert(5);
	pigs.insert(6);
	cout << "pigs before removal:" << endl;
	cout << pigs.get(0) << " , " << pigs.get(1) << " , " << pigs.get(2) << " , " << pigs.get(3) << " , " << pigs.get(4) << " , " << pigs.get(5) << endl << endl;
	pigs.removeRandom(); 
	cout << "After 1 removal:" << endl;
	cout << pigs.get(0) << " , " << pigs.get(1) << " , " << pigs.get(2) << " , " << pigs.get(3) << " , " << pigs.get(4) << " , " << pigs.get(5) << endl << endl;
	pigs.removeRandom(); 
	cout << "After 2 removals:" << endl;
	cout << pigs.get(0) << " , " << pigs.get(1) << " , " << pigs.get(2) << " , " << pigs.get(3) << " , " << pigs.get(4) << " , " << pigs.get(5) << endl << endl;
	pigs.removeRandom(); 
	cout << "After 3 removals:" << endl;
	cout << pigs.get(0) << " , " << pigs.get(1) << " , " << pigs.get(2) << " , " << pigs.get(3) << " , " << pigs.get(4) << " , " << pigs.get(5) << endl << endl;	

	return 0;
}