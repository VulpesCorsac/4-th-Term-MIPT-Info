#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printInt (int number);

int main (int argc, char* argv [])
{
    vector<int> myVec;
    vector<int>::iterator first, last;
    for (long i=0; i<10; i++)
    {
        myVec.push_back (i);
    }
    first = myVec.begin () + 2;
    last = myVec.begin () + 5;
    if (last >= myVec.end ())
    {
        return - 1;
    }
    myVec.erase (first, last);
    for_each (myVec.begin (), myVec.end (), printInt);
    return 0;
}

void printInt (int number)
{
    cout << number << endl;
}