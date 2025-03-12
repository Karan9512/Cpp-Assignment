#include<iostream>
using namespace std;

int Swap(int &a , int &b)
{
	a = a + b;
       	b = a - b;
	a = a - b;	

	return 0;
}

int main()
{
	int num1 , num2;
	cin >> num1 >> num2;
	cout << num1 <<" " <<num2 << endl; 
	Swap(num1 , num2);
	cout << num1 <<" " <<num2 << endl;  
	return 0;
}
