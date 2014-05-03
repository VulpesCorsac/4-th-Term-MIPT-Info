#include <iostream>
#include <strstream>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    strstream xstr;
    for (int i = 0; i < 10; i++)
    {
        xstr << "Demo " << i << endl;
    }
    cout << xstr.str () << endl;
    string str;
    str.assign (xstr.str (), xstr.pcount ());
    cout << str.c_str ();
    return 0;
}