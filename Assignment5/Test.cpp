#include<iostream>
using namespace std;

int test(int const *a, int s)
{
	for (int i = 0; i < s ; i++)
	{
		cout << a[i] << endl; 
	}

	return 0;
}
int main ()
{
	int num;
	cin >> num ;
	int array[num];
	for(int i = 0; i < num ; i++)
	{
		cin>> array[i];
	}
	
	test(array,num);

	return 0;

}
