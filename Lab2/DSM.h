#ifndef LAB3_L3_MATEI_DIANA_DSM_H
#define LAB3_L3_MATEI_DIANA_DSM_H

#include <string>
#include <vector>
using namespace std;
class DSM {

private:
    float **dsm;

    int cap;

    int length;

    vector<string>elems;

    int RESIZE_FACTOR=2;

    void resize();

    int elementIndex(string name);

public:
    DSM (int elementCount);

    DSM (vector<string> element_names);

    DSM(const DSM &original);

    ~DSM();

    int Size();

    string get_name(int index);

    void set_element_name(int index, string name);

    void add_link(string from_element, string to_element, float weight);

    void deleteLink(string from_element, string to_element);

    bool hasLink(string from_element, string to_element);

    const float linkWeight(string from_element, string to_element);

    int countToLinks(string elementName);

    int countFromLinks(string elementName);

    int countAllLinks();

    void printMatrix();

    void printElems();


};


#endif //LAB3_L3_MATEI_DIANA_DSM_H
