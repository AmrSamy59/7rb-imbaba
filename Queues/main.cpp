
#include "LinkedQueue.h"
#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.

using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"
//This is the program starting point.
int main()
{


	//Declare a queue of integers named "Q"
	LinkedQueue<int> Q;
	int x;
	cout << "Testing Q:" << endl;
	cout << "inserting 5 values into Q:" << endl;

	cout<<"Please Enter the 5 values to enqueue :";
	for(int i = 0; i < 5; i++)
	{
		cin>>x;
		Q.enqueue(x); //enqueue x to Q
	}

	cout << "Testing dequeue operation:\n ";

	while(Q.dequeue(x))
		cout << x << " ";

	cout<<endl;

	//Write code to test empty case and to test peek function
	return 0;
}
  
