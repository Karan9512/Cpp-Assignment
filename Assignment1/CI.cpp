#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float p , r , n, CI;
	cout << "Enter Principle Amount : "; 
	cin >> p; 
	cout << "Enter Annual Rate : ";
        cin >> r;
	cout << "Enter time (in years) : ";
        cin >> n;
	if ((p > 0) && (100 <= r > 0)  ||( n > 0))
		{
			CI = p*(pow((1+(r/100)),n));
			cout << CI << endl;	
		}
	else
		{
			cout <<" Enter Valid Numbers !!"<< endl; 
		}
	return 0;
}
