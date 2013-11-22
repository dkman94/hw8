#include "room.h"

#include <iostream>
#include <string>
using namespace std;
  /* Constructor with Name and Description */
        room :: room(string _name, string _description)
        {
            name = _name;
            description = _description;
        }


        /* Contrsuctor with Name */
        room :: room(string _name)
        {
            name = _name;
        }
void Room::link(string direction, Room *r)
{
    exits[direction] = r;
}

Room *Room::getLinked(string description)
{
    Room* temproom = new Room("temp", "temp");
    return temproom;
}

void Room::printLinked()
{
    map<string, Room*>::iterator it;
    for(it = exits.begin(); it != exits.end(); it++)
    {
        cout<<it->first<<"and"<<(it->second).getName()<<endl;
    }
}

