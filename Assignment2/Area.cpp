#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int num;

	while(1)
	{
		cout << "1. Area Of Circle" << endl;
		cout << "2. Area Of square" << endl;
		cout << "3. Area Of rectangle" << endl;
		cout << "4. Exit "<<endl;
		cout << "Enter Your Choice :";
		cin >> num;
		
		switch(num)
		{		
			case 1:
			{	
				double Radius;
				cout << "Enter radius of circle :";
				cin >> Radius ;
				cout << "Area Of circle Is : " << 3.14 * Radius * Radius << endl;			
			
			}
			break;	
	
			case 2:
			{	
				double length;
				cout << "Enter side of Square :";
				cin >> length ;
				cout << "Area Of Square : " << length  * length << endl;			
			
			}	
			break;
		
			case 3:
			{	
				double Length, Breadth;
				cout << "Enter length and breadth :";
				cin >> Length >> Breadth ;
				cout << "Area Of rectangle : " << Length * Breadth  << endl;			
			
			}	
			break;
			case 4:
			{	
				exit(0);
			}	
			break;

			default:
			{
				cout << "Please Enter Correct Choice !!!";   
			}
			break;
		
		}
	
	}
		
	

	return 0;
}
