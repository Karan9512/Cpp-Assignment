#include<iostream>
using namespace std;

int sum (int& b)
{
        int s = 0;
        while(b)
        {
                s = s + (b % 10);
                b = b /10;

        }
	cout<<"Sum of given Number : " << s << endl;

        return 0;
}

int main()
{
        int a;
        cout << "Enter a number : ";
        cin >> a;
        sum(a);
       	return 0;
}


