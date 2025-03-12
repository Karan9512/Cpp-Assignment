/* Implement constructor, parameterized constructor, Accept, Display functions in Student class. Try to create Student objects using new operator. Try creating student array and check if constructors are getting multiple times. Write constructor with initialization list for const D.M initialization. Print this pointer inside function to check if it points to invoking object.
*/


#include<iostream>
using namespace std;

class Student
{
	private:
		int Roll_number;
		string name;
		string course;
		static int k;
	public:
		Student():Roll_number(0), name(" "), course(" "){};

		void Accept()
		{
			cout << "Enter Student Details" <<endl;
			cout << "Enter Student Roll Number " <<endl;
			cin >> this ->Roll_number;	
			cout << "Enter Student Name" <<endl;
			cin >> this ->name;
			cout << "Enter Student course" <<endl;
			cin >> this ->course;
		
		}
		
		void Display() const
		{
			cout << "Student Details :"<<endl;
			cout << "Roll Number: "<< this -> Roll_number<<endl; 
			cout << "Student Name :"<< this -> name<<endl;
			cout << "Student course :"<<this -> course<<endl;
			cout << k ;		
		}

};
int Student::k(100);  
int main()
{
	int num;
	cout << "Enter The Number Of Students" << endl;
	cin >> num;
	Student *S = new Student[num];
	for(int i = 0; i < num; i++)
	{
		S[i].Accept();
	}
		
	for(int i = 0; i < num; i++)
	{
		S[i].Display();
	}
	
	return 0;
}
