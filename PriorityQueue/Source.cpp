#include "LinkedQueue.h"
#include "priQueue.h"

#include <iostream>
using namespace std;

int main()
{
	//First try the regular queue of strings named "Q"
	LinkedQueue<string> Q;
	string x;
	cout << "Testing Q:" << endl;
	cout << "inserting 5 names into Q:" << endl;
	cout << "Please Enter 5 names to enqueue:";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		Q.enqueue(x);
	}
	cout << "\nDequeue from regural queue ==> FIFO:";
	while (Q.dequeue(x))
		cout << x << " ";

	cout << endl;

	//Now try the pri queue and notice the difference
	priQueue<string> pQ;
	int pri;
	cout << "Testing pQ:" << endl;
	cout << "inserting 5 names into pQ:" << endl;
	cout << "Please Enter 5 names with priorities to enqueue:";
	for (int i = 0; i < 5; i++)
	{
		cin >> x >> pri;
		pQ.enqueue(x,pri);
	}
	cout << "\nDequeue from Pri Queue (items sorted by pri):\n";
	while (pQ.dequeue(x, pri))
		cout << "(" << x << ", " << pri << ")";

	cout << endl;
	return 0;

}