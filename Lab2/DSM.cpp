#include "DSM.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <exception>
using namespace std;

DSM::DSM(int elementCount) {
    length=elementCount;
    cap=elementCount;
    dsm=(float**) malloc(length*sizeof (float *));
    for (int i=0;i<length;i++)
    {
        dsm[i]=(float*) malloc(length*sizeof (float));
    }

    for (int i=0;i<length;i++)
        for (int j=0;j<length;j++)
            dsm[i][j]=0;

    ifstream f;
    f.open("data.in");
    string x;
    for (int i=0;i<length;i++)
    {
        f>>x;
        elems.push_back(x);
    }
}

DSM::DSM(vector<string> element_names){
    cap=element_names.size();
    length=element_names.size();
    for (int i=0;i<length;i++)
        elems.push_back(element_names[i]);


    dsm=(float**) malloc(length*sizeof (float *));
    for (int i=0;i<length;i++)
    {
        dsm[i]=(float*) malloc(length*sizeof (float));
    }


    for (int i=0;i<length;i++)
        for (int j=0;j<length;j++)
            dsm[i][j]=0;


}

DSM::DSM(const DSM &original){
    cap=original.cap;
    length=original.length;
    dsm=original.dsm;
    for (int i=0;i<original.length;i++)
        elems.push_back(original.elems[i]);

}

int DSM::Size() {
    return length;
}

string DSM::get_name(int index) {
    if (index < length && index >= 0) return elems[index];
    throw out_of_range("Invalid index!");

}

void DSM::set_element_name(int index, string name) {
    if (index < length && index >= 0)
        elems[index] = name;
    else throw out_of_range("Invalid index!");

}

void DSM::add_link(std::string from_element, std::string to_element, float weight) {

    int fromIndex = elementIndex(from_element);
    int toIndex = elementIndex(to_element);

    // check if capacity needs to be increased
    if ((fromIndex == -1 || toIndex == -1) && cap == length) resize();

    // add the nonexistent element
    if (fromIndex == -1) {
        fromIndex = length++;
        elems.push_back(from_element);
    }
    if (toIndex == -1) {
        toIndex = length++;
        elems.push_back(to_element);
    }

    dsm[fromIndex][toIndex] = weight;

}


void DSM::deleteLink(string from_element, string to_element) {
    int fromIndex = elementIndex(from_element);
    int toIndex = elementIndex(to_element);

    if (fromIndex == -1 || toIndex == -1)
        throw invalid_argument("One or more parameters are not in the matrix!");

    dsm[fromIndex][toIndex] = 0;
}


bool DSM::hasLink(string from_element, string to_element) {
    int fromIndex = elementIndex(from_element);
    int toIndex = elementIndex(to_element);

    if (fromIndex == -1 || toIndex == -1)
        throw invalid_argument("One or more parameters are not in the matrix!");

    return dsm[fromIndex][toIndex] != 0;
}


const float DSM::linkWeight(string from_element, string to_element) {
    if (hasLink(from_element, to_element)) {
        int fromIndex = elementIndex(from_element);
        int toIndex = elementIndex(to_element);
        return dsm[fromIndex][toIndex];
    }
    throw invalid_argument("One or more parameters are not in the matrix!");
}


int DSM::countToLinks(string elementName) {
    int index = elementIndex(elementName);

    if (index != -1) {
        int count = 0;
        for (int col = 0; col < length; col++)
            if (dsm[col][index] != 0) count++;
        return count;
    }

    throw invalid_argument("Element given as parameter does not exist!");
}


int DSM::countFromLinks(string elementName) {
    int index = elementIndex(elementName);

    if (index != -1) {
        int count = 0;
        for (int row = 0; row < length; row++)
            if (dsm[index][row] != 0) count++;
        return count;
    }

    throw invalid_argument("Element given as parameter does not exist!");
}


int DSM::countAllLinks() {
    int count = 0;
    for (int row = 0; row < length; row++)
        for (int col = 0; col < length; col++)
            if (dsm[row][col] != 0) count++;
    return count;
}


int DSM::elementIndex(string name) {
    for (int index = 0; index < length; index++)
        if (elems[index] == name) return index;
    return -1;
}


void DSM::resize() {
    cap = (cap + 1) * RESIZE_FACTOR;

    float **newAdjMatrix = new float *[cap];
    for (int row = 0; row < cap; row++)
        newAdjMatrix[row] = new float[cap];

    for (int row = 0; row < cap; row++)
        for (int col = 0; col < cap; col++)
            if (row < length && col < length)
                newAdjMatrix[row][col] = dsm[row][col];
            else
            {
                newAdjMatrix[row][col] = 0;
                newAdjMatrix[col][row] = 0;
            }

    for (int row = 0; row < length; row++) delete[] dsm[row];
    delete[] dsm;
    dsm = newAdjMatrix;
}



void DSM::printMatrix() {
    cout<<"   ";
    for (int i=0;i<length;i++)
        cout<<elems[i]<<" ";
    cout<<"\n";
    for (int i=0;i<length;i++)
    {
        cout<<elems[i]<<" ";
        for (int j=0;j<length;j++)
            cout<<dsm[i][j]<<"  ";
        cout<<"\n";
    }

}

void DSM::printElems() {
    for (int i=0;i<length;i++)
        cout<<elems[i]<<" ";
}

DSM::~DSM() {
    for (int row = 0; row < cap; row++) delete[] dsm[row];
    delete[] dsm;

}