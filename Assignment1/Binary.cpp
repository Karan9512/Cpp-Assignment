#include<iostream>
using namespace std;

int conversion (int a)
{
	if( a == 0)
	{
		return 0;
	}

	return (a % 2) + (10 * conversion(a / 2));																				
}
int main()
{
	int a;
	cout << "Enter a Number : ";
	cin >> a;

	cout << "Binary To Integer : "<<conversion(a) << endl;

	return 0;
	

}
