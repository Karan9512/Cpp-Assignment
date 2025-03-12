#include<iostream>
#include"Factorial.h"
using namespace std;

int Factorial(int number)
{
	number = 20;// Modificationn is not possible
	if(number == 0 || number == 1)
	{
		return 1;
	}

	return (number * (Factorial(number -1)));
}	
