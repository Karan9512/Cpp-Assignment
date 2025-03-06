#include <iostream>
using namespace std;

int Pattern1(int Number)
{
	for(int i = Number; i > 0; i--)
	{
		for(int j = 1; j <= i; j++)
		{
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}

int main()
{
	int num;

	cout << "Enter a Number :";
	cin >> num;

	Pattern1(num);

	return 0;
}
