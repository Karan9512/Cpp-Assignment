#include<iostream>
#include<cmath>
using namespace std;

int root(int a ,int b, int c)
{
	int x = 0;
        int y = 0;

	x = (-b + sqrt(pow(b,2)-(4 * a * c )))/(2*a);	
	y = (-b - sqrt(pow(b,2)-(4 * a * c )))/(2*a);

	cout << x << "\n "<< y<< endl;	
	
	return 0;
}

int main()
{
	int  a , b , c ;
	cout << "Enter value of a , b , c(assuming ax^2+bx+c=0) :  ";
	cin >> a >>b >> c;
	root(a,b,c);
	return 0;

}
