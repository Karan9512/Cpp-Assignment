#include<iostream>
#include"Complex.h"
using namespace std;
int main()
{
	
        int ch;
	Complex C1(10,10),C2(5,6);
	Complex C3;
        while(1)
        {
                cout << "\nEnter Your Choice";
                cout << "\n1.ADD";
                cout << "\n2.Substract";
                cout << "\n3.Multiplication";
                cout << "\n4.Exit:" <<endl;
                cin >> ch;
                switch(ch)
                {
                        case 1:
				C3 = C1 + C2;
				C3.Display();
				break;
                        case 2:
				C3 = C1 - C2;
			       	C3.Display();	
                                break;
			case 3:
			        C3 = C1 * C2;
				C3.Display();	       
                                break;
                        case 4: exit(0);
                        default: cout <<"Please enter a valid number !!!!! ";
                }
        }

	return 0;
}
