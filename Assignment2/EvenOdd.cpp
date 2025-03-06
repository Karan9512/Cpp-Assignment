#include<iostream>
using namespace std;
int EvenOdd(int number)
{

	if(number % 2 == 0 number != 0 )
	{
		cout << "The Given Number " << number << " Is Even ";
	}
	
	cout << "The Given Number " << number << " Is odd ";
	
	return 0;
}

int main()
{
	int Number;
	cout << "Enter a Number";
	cin >> Number;
	EvenOdd(Number);

	return 0;

}
