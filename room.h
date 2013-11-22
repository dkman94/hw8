#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
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
    void printRoom();
    void link(Room *r, string direction);
    void printLinked();
    Room *getLinked(string direction);

};

#endif

