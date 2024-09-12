#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//class Plant{
//public:
//    int height{0};
//};
//
//Plant grow(Plant p, int delta)
//{
//    p.height+=delta;
//    return p;
//}
//
//Plant& growagain(Plant &p, int delta)
//{
//    p.height+=delta;
//    return p;
//}
//
//Plant* growreloaded(Plant *p, int delta)
//{
//    p->height+=delta;
//    return p;
//}


class Person{
public:
    string name;
    int age;

public:
    Person(string _name, int _age) {
        if (_name!="")
            name=_name;
        else
            throw exception();

        if (_age>=0)
            age=_age;
        else
            age=0;
    };

    virtual string getReport()
    {
        return name+" "+to_string(age);
    };
};


class Repository{
public:
    vector<Person> persons;

public:
    vector<Person> getPeople(function<bool(Person)>filterFunc){
        vector <Person> returnVec;
        for (Person pers:persons)
        {
            if (filterFunc(pers)){
                returnVec.push_back(pers);
            }
        }
        return returnVec;
    }
};

class Student : public Person
{
private:
    string fach;
public:
    Student(string _name, int _age, string _fach):Person(_name, _age){
        fach=_fach;
    }
    string getReport() override{
        return name+" "+ to_string(age)+" "+fach;
    }
};

int main() {
    int nr=15;
    int i=0;
    auto lambda = [=] (Person p)-> bool {return p.age>nr+i;} ;


    Person p1("idk",30);
    Person *ptr=new Person("plm",-2);
    int x;
    cout<<p1.getReport();
    cout<<"\n";
    Student s("bob",12,"info");
    cout<<s.getReport();

    Repository repo;
    vector<Person>vec;
    vec.push_back(p1);
    repo.persons=vec;
    cout<<"\n";
    vector<Person> result=repo.getPeople(lambda);
    cout<<result[0].name;

    //    Plant p;
//    cout<<grow(growagain(*growreloaded(&p,10),5),5).height<<"\n";
//    cout<<p.height;

    return 0;
}
