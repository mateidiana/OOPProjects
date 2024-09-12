//
// Created by Diana on 05-Mar-2024.
//

#ifndef LAB1_L2_MATEI_DIANA_PROBLEMA_RATIONAL_H
#define LAB1_L2_MATEI_DIANA_PROBLEMA_RATIONAL_H
#include <string>
using namespace std;

class Rational {

private:

    int num=1,den=1;

public:

    //Konstruktor
    Rational(int n, int d);

    //Zugriffsmethoden
    int get_numerator();

    int get_denominator();

    //Operationen
    Rational add(Rational f);

    Rational subtract(Rational f);

    Rational multiply(Rational f);

    Rational divide(Rational f);

    void reduce();

    void inverse();

    string compare(Rational f);

    //Overload operators
    Rational operator+(Rational f);

    Rational operator-(Rational f);

    Rational operator*(Rational f);

    Rational operator/(Rational f);

};


#endif //LAB1_L2_MATEI_DIANA_PROBLEMA_RATIONAL_H
