#include<iostream>
using namespace std;
int sum(int a)
{
	if (a == 0 )
	{
		return 0;
	}
	return (a % 10 + sum(a / 10));
}
int main()
{
	int a;
	cout << "Enter Number :  ";
        cin >>  a;
	cout << sum(a) <<endl;
	return 0;
}
