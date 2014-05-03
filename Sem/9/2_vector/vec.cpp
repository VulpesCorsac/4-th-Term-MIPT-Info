#include <iostream>
#include <strstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MyMessage
{
private:
    string from;
    string to;
    string message;
    int id;
public:
    MyMessage (string from, string to, string message)
    {
        this->from = from;
        this->to = to;
        this->message = message;
    }
    int GetId ()
    {
        return this->id;
    }
    void SetId (int id)
    {
        this->id = id;
    }
    string GetMessage ()
    {
        return this->message;
    }
    string GetFrom ()
    {
        return this->from;
    }
    string GetTo ()
    {
        return this->to;
    }
};

int main (int argc, char* argv [])
{
    vector<MyMessage> common;
    // create pool of messages for 3 users:
    for (int user = 0; user < 3; user++)
    {
        for (int i = 0; i < 10; i++)
        {
            strstream messagex;
            messagex << "Message " << i;
            string smessage;
            smessage.assign (messagex.str (), messagex.pcount ());
            strstream userx;
            userx << "User " << user;
            string suser;
            suser.assign (userx.str (), userx.pcount ());
            MyMessage message ("Administrator", suser, smessage);
            message.SetId (user*10 + i);
            common.push_back (message);
        }
    }
    
    // create vector for each user:
    vector<MyMessage> user0;
    vector<MyMessage> user1;
    vector<MyMessage> user2;
    for (int x = 0; x < (int) common.size (); x++)
    {
        MyMessage message = common [x];
        if (message.GetTo () == "User 0")
        {
            user0.push_back (message);
        }
        else
            if (message.GetTo () == "User 1")
            {
                user1.push_back (message);
            }
            else
                if (message.GetTo () == "User 2")
                {
                    user2.push_back (message);
                }
    }
    
    cout << "Messages for user 2: " << endl;
    for (int i = 0; i < (int) user2.size (); i++)
    {
        MyMessage message = user2[i];
        cout << message.GetTo () << ": " << message.GetMessage() << endl;
    }
    cout << "Messages for user 1: " << endl;
    for (int i = 0; i < (int) user1.size (); i++)
    {
        MyMessage message = user1[i];
        cout << message.GetTo () << ": " << message.GetMessage() << endl;
    }
    cout << "Messages for user 0: " << endl;
    for (int i = 0; i < (int) user0.size (); i++)
    {
        MyMessage message = user0[i];
        cout << message.GetTo () << ": " << message.GetMessage() << endl;
    }
    
    cout << "Size of common vector: " << (int) common.size ()
    << endl;
    return 0;
}