#include "room.h"

#inlcude <iostream>
#include <string>
using namespace std;

Room(string name_, string description_)
{
    name = name_;
    description = description_;
}

string getName()
{
    return name;
}

string getDescription()
{
    return description;
}

void link(string direction, Room *r)
{

}
