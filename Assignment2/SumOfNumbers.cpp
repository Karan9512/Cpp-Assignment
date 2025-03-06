#include<iostream>
using namespace std;

int SumofNumbers(int number)
{
	if (number == 0)
	{
		return 0;
	}

	return number + SumofNumbers(number - 1);
}

int main()
{
	int number;
	cout << " Enter a Number : ";
	cin >> number;
	cout << "Sum Of " << number << " is " << SumofNumbers(number) << endl;
      	return 0;	
	
}
