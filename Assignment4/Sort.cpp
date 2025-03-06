#include<iostream>

using namespace std;

void Sort(int *a,int *n){

	for(int i=0;i<*n;i++){
		bool flag = false;
		for(int j=0;j<*n-i-1;j++){
		   
			if(a[j]>a[j+1]){
				int temp = a[j];
		   		a[j] = a[j+1];
		   		a[j+1] = temp;
				flag = true;
			}
		}
		if(!flag){
			break;
		}
	}
	
}

int main()
{
	int number;
	cout<<"Enter Size:"<<endl;
	cin>>number;
	int array[number];

	cout<<"Enter elements:"<<endl;

	for(int i=0; i<number; i++){
		cin>>array[i];
	}

    	Sort(array,&number);
	
	cout<<"sorted Array:->"<<endl;

	for(int i=0;i<number;i++){
		cout<<" "<<array[i];
	}
	
	return 0;
}
