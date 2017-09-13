//Chandler Haukap
//Homework01 part1
//This program uses a Templated Class to create a Fibonacci sequence.
//traditionally Fibonacci sequences use integers but this can handle any real number.

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

template<class T> //My concept was templated classes.
class Fibo //My templated class
{
private:
	T firstNumber, secondNumber; //stores first two numbers of series
	int seqNum; //and the series index.

public:
	Fibo(T first, T second, int iterate) //constructor
	{
		firstNumber = first;
		secondNumber = second;
		seqNum = iterate;
	}
	T go(); //performs the Fibonacci calculation.
};

template<class T>
T Fibo<T>::go() //Templated function to go along with the Templated class
{
	T thisNumber = firstNumber;
	if (seqNum == 2)
	{
		thisNumber = secondNumber;
		return thisNumber;
	}
	for (int i = 2; i < seqNum; i++)
	{
		thisNumber = firstNumber + secondNumber;
		firstNumber = secondNumber;
		secondNumber = thisNumber;
	}
	return thisNumber; //changes thisNumber to the number in the series.
}

int main()
{
    //Main block demonstrates three data types working.
	Fibo<int> a1(1, 1, 1);
	Fibo<int> a2(1, 1, 2);
	Fibo<int> a3(1, 1, 3);
	cout << a1.go() << "\t" << a2.go() << "\t" << a3.go() << "\n";

	Fibo<float> b1(1.5, 1.7, 5);
	Fibo<float> b2(1, 2.7, 6);
	Fibo<float> b3(1.0, 1.000, 7);
	cout << b1.go() << "\t" << b2.go() << "\t" << b3.go() << "\n";

	double num1, num2; //now user inputs
	int iterations;
	cout << "Enter two numbers to start a series." << endl;
	cin >> num1 >> num2; //no handling here, its just an example
	cout << endl << "Enter the sequence number." << endl;
	cin >> iterations;

	Fibo<double> d1(num1,num2,iterations);
	cout << d1.go();

    return 0;
}

