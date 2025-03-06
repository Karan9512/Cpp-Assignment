#include<iostream>
using namespace std;
int main()
{
 
	int N = 5;
	for (int i = 1; i < N; i++)
       	{
        	for(int j = 5; j >= i; j--)
		{
			cout << " ";
		}
		for(int k = 1; k <= i; k++)
		{
			cout << "*";
		}
		for(int k = 1; k <= i; k++)
                {
                	cout << "*";
                }
		for(int j = 5; j >= i; j--)
                {
                	cout << " ";
                }

		cout << "\n";
       	}

       	for (int i = 1; i <= N; i++)
        {
                for(int j = 1; j <= i; j++)
                {
                        cout << " ";
                }
                for(int k = 5; k >= i; k--)
                {
                        cout << "*";
                }
                for(int k = 5; k >= i; k--)
                {
                        cout << "*";
                }
                for(int j = 1; j <= i; j++)
                {
                        cout << " ";
                }

                cout << "\n";
        }
		
    return 0;
}

