#include <iostream>
#include <strstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printMan (string user);

int main (int argc, char* argv [])
{
    vector<string> maleRoom;
    vector<string> femaleRoom;
    maleRoom.push_back ("Vasya");
    maleRoom.push_back ("Petya");
    maleRoom.push_back ("Sasha");
    
    femaleRoom.push_back ("Nastya");
    femaleRoom.push_back ("Alena");
    femaleRoom.push_back ("Sveta");
    
    for_each (maleRoom.begin (), maleRoom.end (), printMan);
    reverse (maleRoom.begin (), maleRoom.end ());
    cout << "Males in reverse order " << endl;
    for_each (maleRoom.begin (), maleRoom.end (), printMan);
    maleRoom.swap (femaleRoom);
    cout << "Now in male room are females: " << endl;
    for_each (maleRoom.begin (), maleRoom.end (), printMan);
    return 0;
}
void printMan (string man)
{
    cout << man << endl;
}