#include <iostream>
#include <strstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MyFunctor
{
    string comment;
public:
    MyFunctor ()
    {
        comment = "My comment";
    };
    MyFunctor (string comment)
    {
        this->comment = comment;
    }
    void operator ()(int test)
    {
        cout << test << comment << endl;
    };
};

int main (int argc, char* argv [])
{
    vector<int> test;
    // fill vector:
    for (int i = 0; i < 5; i++)
    {
        test.push_back (i);
    }
    // now use our functor:
    MyFunctor functor (" Test comment");
    for_each (test.begin (), test.end (), functor);
    return 0;
}