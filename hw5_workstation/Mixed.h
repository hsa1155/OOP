#ifndef MIXED_H
#define MIXED_H


#include<iostream>
#include<iomanip>
using namespace std;
int gcd(int,int);
class Mixed
{
    private:
    int integer;
    int numerator;
    int denominator;
    public:
    Mixed(int = 0); // set object to the value of parameter, and has no fraction part
    Mixed(int, int, int);// set object follow the integer, numerator, and denominator order
    double Evaluate(); // return the decimal equivalent of the Mixed number
    void Simplify();// simplify the Mixed number representation to lowest terms. (This means that the fraction part should be reduced to lowest terms, and the fraction part should not be an improper fraction)
    void ToFraction();// convert the mixed number to into fraction form. (This means integer part is 0, and the fraction portion may be an improper fraction)
    void print();
    bool operator<(const Mixed &);
    bool operator>(const Mixed &);
    bool operator<=(const Mixed &);
    bool operator>=(const Mixed &);
    bool operator==(const Mixed &);
    bool operator!=(const Mixed &);
    Mixed operator+(const Mixed &);
    Mixed operator-(const Mixed &);
    Mixed operator*(const Mixed &);
    Mixed operator/(const Mixed &);
    Mixed operator+(const int);
    Mixed operator-(const int);
    Mixed operator*(const int);
    Mixed operator/(const int);
    void operator=(const Mixed&);
    Mixed &operator++();//++x
    const Mixed operator++(int);//x++
    Mixed &operator--();
    const Mixed operator--(int);
    friend istream & operator>>(istream &, Mixed &);
    friend ostream & operator<<(ostream &, const Mixed &);
};


#endif