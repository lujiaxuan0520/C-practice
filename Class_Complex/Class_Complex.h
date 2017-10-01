// Class_Complex.h
// Class "Complex" declaration
#ifndef MY_CLASS_COMPLEX_H
#define MY_CLASS_COMPLEX_H
#include<cmath>
#include<iostream>
using namespace std;
class Complex
{
public:
    Complex(double r=0,double i=0);
    Complex(const Complex& c);
    double get_real() const;
    double get_imag() const;
    void SetComplex(double r,double i);
    void Show() const;
    double radius() const;
    friend Complex operator+(const Complex& a,const Complex &b );
    friend Complex operator-(const Complex& a,const Complex &b );
    friend ostream & operator<<(ostream &out,const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
    Complex operator=(const Complex &c)
    {
        this->real=c.real;this->imag=c.imag;
        return *this;
    };
    Complex operator+=(const Complex &b )
    {
        this->real+=b.real;this->imag+=b.imag;
        return *this;
    };
    Complex operator-=(const Complex &b )
    {
        this->real-=b.real;this->imag-=b.imag;
        return *this;
    };


private:
    double real;
    double imag;
} ;



#endif
