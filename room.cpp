#include "room.h"

#include <iostream>
#include <string>
using namespace std;



Room::Room(string _name, string _description)
{
    name = _name;
    description = _description;
}

string Room::getName()
{
    return name;
}

string Room::getDescription()
{
    return description;
}

void Room::printRoom()
{
    cout<<"--"<<getName()<<"--"<<endl;
    cout<<getDescription()<<endl;
}

void Room::link(Room *r, string _direction)
{
    exits[_direction] = r;
}

Room *Room::getLinked(string direction)
{
        map<string, Room*> :: iterator it;

        it = exits.find(direction);

        if(it != exits.end())
        {
            return it->second;
        }
        else
        {
            return NULL;
        }
}

void Room::printLinked()
{
    map<string, Room*>::iterator it;

    for(it = exits.begin(); it != exits.end(); it++)
    {
        cout<<"Below are the exits available to you..."<<endl;
        cout << it->first << " (" << (it->second)->getName() <<")"<< endl;
    }
}
