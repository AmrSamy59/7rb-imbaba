
#include "ArrayStack.h"	
#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.
using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"

// This caod has 1 checkpoint [CheckPoint 1]
//Follow the provided instructions at each check point

//This is the program starting point.
int main()
{
	//Declare a Stack of integers named "S"
	ArrayStack<int> S;
	int i,x,n;
	cout<<"\nEnter no. of values to push into stack:";
	cin>>n;

	//Test the 1st stack by pushing n values then popping
	cout << "Testing stack S......" << endl;
	cout << "Pushing "<<n<<" values into S:" << endl;

	cout<<"Please Enter the "<<n<<" values to push in S :";
	for(i = 0; i < n; i++)
	{	 
		cin>>x;
		S.push(x); //pushing x to S
	}

	cout << endl<<"Popping: ";
	while(S.pop(x))		//As long as pop returns true, x contains a valid value		
		cout << x << " ";

	/// ==> [CheckPoint 1]
	//After 1st run, comment the above while loop and uncomment the while loop below

	//while(S.peek(x))		//as long as peek returns true, so x contains a valid value		
		//cout << x << " ";
		
	cout<<endl;
	cout<<"Testing isEmpty()?? ==>"<<boolalpha<<S.isEmpty();

	cout<<endl;
	return 0;
}
  
