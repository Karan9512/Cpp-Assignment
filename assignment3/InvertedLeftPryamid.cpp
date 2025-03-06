#include<iostream>
using namespace std;
int main()
{
 
	int N ;
	cout << "Enter a Number: ";
	cin >> N;	

	for (int i = 1; i <= N; i++)
       	{
        
       		 for (int j = 1; j <= i - 1; j++)
		 {
           		 cout << " ";
       		 }
		 for (int j = 1; j <= N - i + 1; j++)
       		 {
            		 cout << "*";
       		 }
       
        cout << "\n";
    }

    return 0;
}

