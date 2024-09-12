//
// Created by Diana on 05-Mar-2024.
//

#include "Rational.h"
#include <iostream>
#include <string>

using namespace std;

//Konstruktor
Rational::Rational(int n, int d) {

    num=n; //set numerator and denominator
    den=d;

}

//Get private attributes
int Rational::get_numerator() {

    return num;
}

int Rational::get_denominator() {

    return den;
}

//Add class fraction to another fraction, return new fraction
Rational Rational::add(Rational f){
    int x=num*f.den+den*f.num;
    int y=den*f.den;
    return Rational(x,y);
}

//Subtract class fraction from another fraction, return new fraction
Rational Rational::subtract(Rational f) {
    int x=num*f.den-den*f.num;
    int y=den*f.den;
    return Rational(x,y);
}

//Multiply class fraction with another fraction, return new fraction
Rational Rational::multiply(Rational f) {
    int x=num*f.num;
    int y=den*f.den;
    return Rational(x,y);
}

//Divide class fraction by another fraction, return new fraction
Rational Rational::divide(Rational f) {
    int x=num*f.den;
    int y=den*f.num;
    return Rational(x,y);
}

//Euclidian algorithm for gcd, numerator and denominator of fraction are modified
void Rational::reduce() {
    int gcd=1;
    int x,y;
    x=num;
    y=den;
    if (x!=0 && y!=0)
    {
        while (x!=y)
            if (x>y)
                x=x-y;
            else
                y=y-x;
        gcd=x;
    }
    num=num/gcd;
    den=den/gcd;
}

//Swap numerator and denominator
void Rational::inverse(){
    int x,y;
    x=num;
    y=den;
    num=y;
    den=x;
}

//If denominator is equal, compare numerators. Else make denominators the same
string Rational::compare(Rational f){
    if (den==f.den)
        if (num>f.num)
            return std::to_string(get_numerator())+"/"+std::to_string(get_denominator())+" is greater than "+std::to_string(f.get_numerator())+"/"+std::to_string(f.get_denominator());
        else
        if (num<f.num)
            return std::to_string(get_numerator())+"/"+std::to_string(get_denominator())+" is less than "+std::to_string(f.get_numerator())+"/"+std::to_string(f.get_denominator());
        else
            return std::to_string(get_numerator())+"/"+std::to_string(get_denominator())+" is equal to "+std::to_string(f.get_numerator())+"/"+std::to_string(f.get_denominator());
    else
    {
        int a=num;
        int b=den;
        int c=f.num;
        int d=f.den;
        num=a*d;
        den=b*d;
        f.num=c*b;
        f.den=b*d;
        if (num>f.num)
            return std::to_string(get_numerator()/d)+"/"+std::to_string(get_denominator()/d)+" is greater than "+std::to_string(f.get_numerator()/b)+"/"+std::to_string(f.get_denominator()/b);

        else
        if (num<f.num)
            return std::to_string(get_numerator()/d)+"/"+std::to_string(get_denominator()/d)+" is less than "+std::to_string(f.get_numerator()/b)+"/"+std::to_string(f.get_denominator()/b);
        else
            return std::to_string(get_numerator()/d)+"/"+std::to_string(get_denominator()/d)+" is equal to "+std::to_string(f.get_numerator()/b)+"/"+std::to_string(f.get_denominator()/b);

    }

}

//Overload operators. Return new fraction
Rational Rational::operator+(Rational f) {
    Rational g(1,1);
    g.num=num*f.den+den*f.num;
    g.den=den*f.den;
    return g;
}

Rational Rational::operator-(Rational f){
//    Rational g(1,1);
//    g.num=num*f.den-den*f.num;
//    g.den=den*f.den;
//    return g;
    return this->subtract(f);

}

Rational Rational::operator*(Rational f){
    Rational g(1,1);
    g.num=num*f.num;
    g.den=den*f.den;
    return g;
}


Rational Rational::operator/(Rational f){
    Rational g(1,1);
    g.num=num*f.den;
    g.den=den*f.num;
    return g;
}









