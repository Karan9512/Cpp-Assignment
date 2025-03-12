#include<iostream>
#include"Complex.h"
using namespace std;

Complex::Complex(): real(0), img(0){}
Complex::Complex(int real, int img): real(real), img(img){}

void Complex::Accept()
{
	cout<<"\n Please enter real and img Number"<<endl;
	cin>>real;
	cin>>img;
}

void Complex::Display() const
{
	cout<<"\n Complex["<<real<<"+"<<img<<"i"<<"]"<<endl;
}

Complex Complex::operator+(const Complex temp) const
{
	return Complex(this->real + temp.real, this->img + temp.img);		
}

Complex Complex::operator-(const Complex temp) const
{
       	return Complex(this->real - temp.real, this->img - temp.img);		
}

Complex Complex::operator*(const Complex temp) const
{
       	return Complex(this->real * temp.real, this->img * temp.img);		
}
