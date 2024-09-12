#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include "DSM.h"
using namespace std;
int main() {

    DSM matr(4);

    vector<string> vec1;
    vec1.push_back("SB");
    vec1.push_back("BV");
    vec1.push_back("CJ");
    vec1.push_back("AB");


    DSM matr2(vec1);

    DSM matrcopy(matr2);
    assert(matrcopy.Size()==4);

    cout<<"\n";
    matr2.printMatrix();

    matr2.add_link("SB","BV",146.9);
    matr2.add_link("BV","SB",146.9);


    cout<<"\n";
    matr2.printMatrix();

    cout<<"\n";
    assert(matr2.Size()==4);
    assert(matr2.linkWeight("SB","BV")==float(146.9));
    assert(matr2.get_name(1)=="BV");

    matr2.set_element_name(2,"MS");
    matr2.printElems();
    cout<<"\n";
    assert(matr2.get_name(2)=="MS");

    matr2.set_element_name(2,"CJ");
    matr2.printElems();
    cout<<"\n";

    matr2.add_link("SB","MS",218);
    cout<<"\n";
    matr2.printMatrix();

    assert(matr2.Size()==5);
    assert(matr2.get_name(matr2.Size()-1)=="MS");

    matr2.deleteLink("SB","BV");
    assert(matr2.hasLink("SB","BV")==0);
    cout<<"\n";
    matr2.printMatrix();

    assert(matr2.countToLinks("MS")==1);
    assert(matr2.countFromLinks("BV")==1);
    assert(matr2.countAllLinks()==2);

    matr2.deleteLink("BV","SB");
    assert(matr2.countFromLinks("BV")==0);


}
