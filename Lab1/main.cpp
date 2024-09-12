#include "Rational.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int main() {

    Rational r(1,2);
    Rational f(1,2);
    assert(r.get_numerator()==1);
    assert(r.get_denominator()==2);

    assert(r.add(f).get_numerator()==4);
    assert(r.add(f).get_denominator()==4);

    assert(r.subtract(f).get_numerator()==0);
    assert(r.subtract(f).get_denominator()==4);

    assert(r.multiply(f).get_numerator()==1);
    assert(r.multiply(f).get_denominator()==4);

    assert(r.divide(f).get_numerator()==2);
    assert(r.divide(f).get_denominator()==2);

//    cout<<r.add(f).get_numerator()<<"/"<<r.add(f).get_denominator()<<endl;
//    cout<<r.subtract(f).get_numerator()<<"/"<<r.subtract(f).get_denominator()<<endl;
//    cout<<r.multiply(f).get_numerator()<<"/"<<r.multiply(f).get_denominator()<<endl;
//    cout<<r.divide(f).get_numerator()<<"/"<<r.divide(f).get_denominator()<<endl;

    Rational g(2,4);
    g.reduce();

    assert(g.get_numerator()==1);
    assert(g.get_denominator()==2);
//    cout<<endl<<g.get_numerator()<<"/"<<g.get_denominator()<<endl;

    Rational q(2,3);
    q.inverse();

    assert(q.get_numerator()==3);
    assert(q.get_denominator()==2);
//    cout<<endl<<q.get_numerator()<<"/"<<q.get_denominator()<<endl;

    Rational q1(2,4);
    assert(f.compare(q1)=="1/2 is equal to 2/4");
    Rational q2(3,4);
    assert(q1.compare(q2)=="2/4 is less than 3/4");

    Rational r1(1,2);
    Rational r2(1,2);
    Rational r3(1,2);

    vector<Rational>v;
    v.push_back(r1);
    v.push_back(r2);
    v.push_back(r3);

    for (int i=1;i<3;i++)
        v[0]=v[0].add(v[i]);
    v[0].reduce();

    assert(v[0].get_numerator()==3);
    assert(v[0].get_denominator()==2);
//    cout<<endl<<v[0].get_numerator()<<"/"<<v[0].get_denominator();

    Rational x(1,2),y(1,2);
    Rational z=x+y;
    Rational z1=x-y;
    Rational z2=x*y;
    Rational z3=x/y;

    assert(z.get_numerator()==4);
    assert(z.get_denominator()==4);

    assert(z1.get_numerator()==0);
    assert(z1.get_denominator()==4);

    assert(z2.get_numerator()==1);
    assert(z2.get_denominator()==4);

    assert(z3.get_numerator()==2);
    assert(z3.get_denominator()==2);
//    cout<<endl<<z.get_numerator()<<"/"<<z.get_denominator();

    return 0;
}
