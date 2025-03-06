#include<iostream>
#include<limits>
using namespace std;

class Employee{
	private: int EmpNo;
		 long EmpSal;
		 string EmpName;
		 string EmpDept;
	public:
		 Employee():EmpNo(0),EmpSal(0),EmpName(" "),EmpDept(" "){};
		 void Accept(){
		 	cout<<"\n Enter Employee Details: ";
			cout<<"\n Enter Employee Number: ";
			while (!((cin>>this->EmpNo)&& EmpNo > 0))
			{
        			cout << "Invalid input. Please enter an integer: ";
        			cin.clear(); 
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
    			}
				
			cout<<"\n Enter Employee Salary: ";
			while (!((cin>>this->EmpSal)&& EmpSal > 0))
			{
        			cout << "Invalid input. Please enter an integer: ";
        			cin.clear(); 
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
    			}
			cout<<"\n Enter Employee Name: ";
			cin>>this->EmpName;
			cout<<"\n Enter Employee Department: ";
			cin>>this->EmpDept;
		 }
		 void Display(){
		 	cout<<"\n Employee Details: ";
			cout<<"\n Employee Number: "<<this->EmpNo;
			cout<<"\n Enter Employee Salary: "<<this->EmpSal;
			cout<<"\n Enter Employee Name: "<<this->EmpName;
			cout<<"\n Enter Employee Department: "<<this->EmpDept<<endl;
		 }
		 long getSalary(){
			 return this->EmpSal;
		 }
		 int getEmpNo(){
		 	return this->EmpNo;
		 }
		 string getEmpName(){
		 	return this->EmpName;
		 }
};
void sortEmpSal(Employee e[],int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(e[j].getSalary()>e[j+1].getSalary())
			{
				Employee temp= e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
		       	}
		}
	}
}
void sortEmpName(Employee e[],int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(e[j].getEmpName()>e[j+1].getEmpName())
			{
				Employee temp= e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
		       	}
		}
	}
}
void sortEmpNo(Employee e[],int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(e[j].getEmpNo()>e[j+1].getEmpNo())
			{
				Employee temp= e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
		       	}
		}
	}
}
int main(){
	int n,ch;
	cout<<"\n Enter Number of Employee:  ";
	while (!((cin>>n) && n > 0))
	{
        	cout << "Invalid input. Please enter an integer: ";
        	cin.clear(); 
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	}
	Employee e[n];
	for(int i=0;i<n;i++){
		e[i].Accept();
	}
	while(1)
	{
	cout<<"\n Choose the Following: ";
	cout<<"\n 1.Sort by Employee Name";
	cout<<"\n 2.Sort by Employee Number";
	cout<<"\n 3.Sort by Employee Salary";
	cout<<"\n 4.exit";
	cout<<"\n Enter Choice:";
	cin>>ch;	
	switch(ch){
		case 1:sortEmpName(e,n);
		       for(int i=0;i<n;i++){
			       e[i].Display();
		       }
		       break;

		case 2:sortEmpNo(e,n);
		       for(int i=0;i<n;i++){
			       e[i].Display();
		       }
		       break;
	
		case 3:sortEmpSal(e,n);
		       for(int i=0;i<n;i++){
			       e[i].Display();
		       }
		       break;
		case 4:exit(0);
		default:cout<<"Enter Valid Choice";
		}

	}
	
	return 0;
}




















