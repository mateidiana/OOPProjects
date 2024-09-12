#include <iostream>
#include <vector>
using namespace std;

class Square{
private:
    int x;

public:
    Square(int _x):x(_x){}
    virtual ~Square() {}
    void setX(int _x) {x=_x;}
    int getX() const {return x;}
    virtual void print() {cout<<"Square\n";}
};

class Rectangle:public Square{
private:
    int y;

public:
    Rectangle(int _x, int _y): Square(_x) { y=_y;}
    virtual ~Rectangle() {}
    void setY(int _y) { y=_y;}
    int getY() const {return y;}
    void print() override {cout<<"Rectangle\n";}
};

class Foo:public Square{
public:
    using Square::Square;
    void print() override {cout<<"Foo\n";}
    virtual ~Foo() {}
};

void foo(Square &s)
{
    s.print();
}

int main() {
    Square s(8);
    s.print();
    foo(s);
    Rectangle r(2,8);
    r.print();
    foo(r);
    Foo f(3);
    f.print();
    foo(f);

    Square *sqPtr=&r;
    sqPtr->print();

    Square *squares[]={new Square(3),new Rectangle(1,2),new Foo(1)};

    for (Square *sq:squares)
        sq->print();

    return 0;
}
