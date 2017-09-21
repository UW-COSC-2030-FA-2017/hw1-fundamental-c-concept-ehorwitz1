// HW1Part3.cpp : Defines the entry point for the console application.
//

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <iostream>
#include <string>
using namespace std;


template <class T> class Collection
{
public:
	Collection(int x)
	{
		size = x;
		myarray = new T[size];
	}

	~Collection()
	{
		delete[] myarray;
	}
	bool isEmpty();
	void makeEmpty();
	void insert(T x);
	void remove(T x);
	void removeRandom();
	bool notContained(T x);

	void printCollection();
private:
	int size;
	T *myarray;
	int numberOfObjects=0;
};


template <class T>
bool Collection<T>::isEmpty()
{
	if (numberOfObjects == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


template <class T>
void Collection<T>::makeEmpty()
{
	T * temp = new T[size];

	for (int i = 0; i < size; i++)
	{
		temp[i] = NULL;
	}

	delete[] myarray;
	myarray = temp;
	numberOfObjects = 0;
}


template<class T>
void Collection<T>::remove(T x)
{

	for (int i = 0; i < size; i++)
	{
		if (myarray[i] == x)
		{
			for (int index = i+1; index < size; index++)
			{
				myarray[index - 1] = myarray[index];
			}
			size = size - 1;
		}
		
	}
	numberOfObjects--;
}

template<class T>
void Collection<T>::removeRandom()
{
	srand(time(NULL));
	int randNum = rand() % numberOfObjects + 0;
	for (int i = 0; i < size; i++)
	{
		if (i == randNum)
		{
			for (int index = i+1 ; index < size; index++)
			{
				myarray[index - 1] = myarray[index];
			}
			size = size - 1;
			
		}
	}

	numberOfObjects--;
}



template <class T>
void Collection<T>::insert(T x)
{
	
	T * temp = new T[size+1];

	for (int i = 0; i < size; i++)
	{
		temp[i] = myarray[i];
	}

   size=size+1;

	delete[] myarray;
	myarray = temp;
	myarray[size-1] = x;
	numberOfObjects++;
}


template<class T>
void Collection<T>::printCollection()
{
	cout<< "Array values: ";
	for (int i = 0; i < size; i++)
	{
		cout << myarray[i] <<' ';
	}
	cout << endl;
}


template <class T>
bool Collection<T>::notContained(T x)
{
	int index;
	bool search = false;
	index = 0;
	while (index < size && !search)
	{
		if (myarray[index] == x)
		{
			search = true;
			return false;
			break;
		}
		else
		{
			index++;
			
		}
		
	}
	return true;
}




int main()
{
	Collection<int> new_array(0);
	cout << "Int Array Created"<<endl;
	
	cout<<"Is the array empty? (1=true, 0=false): " <<new_array.isEmpty()<<endl;
	new_array.insert(3);
	new_array.insert(10);
	new_array.insert(2);
	new_array.insert(4);
	new_array.insert(654);
	new_array.insert(545);
	new_array.insert(42);
	cout << "Inserted values 3, 10, 2, 4, 654, 545, 42 into array"<<endl;
	cout << "Does the array contain 242323? (0=contains, 1=does not) " << new_array.notContained(242323)<<endl;
	cout << "Does the array contain 2? (0=contains, 1=does not) " << new_array.notContained(2) << endl;
	cout << "Does the array contain 545? (0=contains, 1=does not) " << new_array.notContained(545) << endl;

	cout << "Is the array empty? (1=true,0=false): " << new_array.isEmpty()<<endl;
	new_array.printCollection();

	cout << "adding 54\n";
	new_array.insert(54);
	new_array.printCollection();

	cout << endl << "remove 10 and 4" << endl;
	new_array.remove(10);
	new_array.remove(4);
	new_array.printCollection();

	cout <<endl<< "removing random"<<endl;
	new_array.removeRandom();

	new_array.printCollection();

	new_array.makeEmpty();
	cout << "Emptied array" << endl;;
	new_array.printCollection();

	Collection<string> newChar_array(0);
	cout <<endl<< "String Array Created" << endl;

	cout << "Is the array empty? (1=true, 0=false): " << new_array.isEmpty() << endl;

	newChar_array.insert("h");
	newChar_array.insert("asdsad");
	newChar_array.insert("gdfg");
	newChar_array.insert("fred");
	newChar_array.insert("foo");

	cout << "added strings"<<endl;
	newChar_array.printCollection();

	cout << "removed string" << endl;
	newChar_array.remove("foo");
	newChar_array.printCollection();

	cout << "Does the array contain gdfg? (0=contains, 1=does not) " << newChar_array.notContained("gdfg") << endl;

	return 0;
}





//stackoverflow.com/questions/33059706/adding-to-dynamic-array
//cplusplus.com/forum/general/53238/