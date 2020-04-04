//============================================================================
// Name        : TheCppProj.cpp
// Author      : Alto Legato
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "myarray.h"
#include <iostream>
using namespace std;
using namespace Array;

int main()
{
      MyIntLinkedList arr = *(new MyIntLinkedList());
//    arr.Append(1);
//    arr.Append(2);
//    arr.Append(3);
//    arr += 4;
//    cout << arr;

    cout << "Cool so far, let's test out the memory management part. " << endl;

    for(int Trials = 0; Trials < 10000; Trials++)
    {
		for(int I = 1; I <= 10000; I++)
		{
			arr+= I;
			//cout << arr << endl;
		}

		while(arr.Size() != 0)
		{
			//cout << arr << endl;
			arr.Pop();
		}

		cout << ".";
    }
    cout << endl;
    cout << "Ok, it's paused and check the memory to see if heap is still good" << endl;

    string s;
    cin >> s;
}
