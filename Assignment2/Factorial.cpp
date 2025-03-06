#include<iostream>
using namespace std;

int Factorial(int number)
{
	if(number == 0 || number == 1)
	{
		return 1;
	}

	return (number * (Factorial(number -1))); 	

}

int main()
{
	int number;
	cout << "Enter The Number " << endl;
	cin >> number;
	for(int i = 1 ; i <= number; i++)
	{
		cout << Factorial(i) <<",  " ;	
	}
	return 0;	
	
}
