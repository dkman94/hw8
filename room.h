
#ifndef Room_h
#define Room_h
#include <iostream>
#include <map>

using namespace std;
class Room
{
    string name, description;
    map<string, Room*> exits;

public:
    Room(string name, string description);
    string getName();
    string getDescription();
    void link(Room *r, string direction);
    Room *getLinked(string direction);
    void printLinked();
};


#endif // Room_h
