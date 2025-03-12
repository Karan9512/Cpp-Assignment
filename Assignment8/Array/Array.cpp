#include<iostream>
#include"Array.h"
using namespace std;

Array::Array(): size(5){};

Array::Array(int size): size(size)
{
	this->arr =  new int[this->size];
};

void Array::Accept()
{
	for (int i = 0;i < this->size ; i++)
	{
		cin >>this->arr[i];
	
	}
}

void Array::Display()
{

	for (int i = 0;i < this->size ; i++)
	{
		cout << this->arr[i]<<endl;
	
	}

}

void Array::Sort()
{
	for(int i=0;i<this->size;i++)
		{
			for(int j=0;j<this->size-1;j++)
			{
				if(this->arr[j] >= this->arr[j+1])
					{
						int temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					
					}


			}
		}
}

int Array::Findmax()
{
	return arr[this->size - 1];
}

int Array::Findmin()
{

	return arr[0];
}

Array::~Array()
{
	delete arr;
}
