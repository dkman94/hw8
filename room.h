
#ifndef Room_h
#define Room_h
#include <iostream>

using namespace std;
class Room
{
public:
    Room(string name, string description);
    string getName();
    string getDescription();
    void link(string direction, Room *r);
    Room *getLinked(string direction);
    void printLinked();
};


#endif // Room_h
