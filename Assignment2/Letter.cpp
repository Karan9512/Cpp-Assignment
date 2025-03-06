#include<iostream>
using namespace std;
int Check(char a)
{
	if(a <= 90  && a >= 65 )
	{
		cout << "Given character Is a Capital Letter " << endl;	
	}
	else if(a <= 122 && a >= 97 )
	{
		cout << "Given character Is a Small  Letter " << endl;		
	}
	else
	{
		cout << "Wrong Input" << endl;	
		
	}

	return 0;

}

int main()
{
	char a;
	cout << "Enter a character : ";
	cin >> a ;
	Check (a);
	return 0;

}
