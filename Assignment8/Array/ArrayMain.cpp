#include<iostream>
#include"Array.h"
using namespace std;
int main()
{
	int size = 0;
	int ch;
	cout << "\nEnter Array size:";
	cin >> size;

	Array arr(size);

	while(1)
	{
		cout << "\nEnter Your Choice";
		cout << "\n1.Accept the value";
		cout << "\n2.Display the Value";
		cout << "\n3.sort the Array";
		cout << "\n4.Find Max";
		cout << "\n5.Find min";
		cout << "\n6.Exit:" <<endl;
		cin >> ch;
		switch(ch)
		{
			case 1: arr.Accept();
				break;
			case 2: arr.Display();
				break;
			case 3: arr.Sort();
			        cout << "\n Sorted array :"<<endl;
				arr.Display();
				break;
			case 4: 
				cout<<arr.Findmax();
				
				break;
			case 5:	
				cout<<arr.Findmin();
				break;
			case 6: exit(0);

			default: cout <<"Please enter a valid number !!!!! ";
		}
	}
	return 0;
}
