#include <iostream>
#include <string>
#include <map>

#include "room.h"

using namespace std;

int main()
{
        bool foundkey = false;
    /* ---------- Variable Declerations ---------- */
        string exitChoice;

        /* ---------- Room Intialization ---------- */
        Room *kitchen = new Room("Kitchen", "You are in the Kitchen. Pots and pans dangle above your head as you look across the room.");
        Room *diningRoom = new Room("Dining Room", "You are in the Dining Room. You see a large table in the center of the room complete with a set of chairs. It seems no one has ate here in quite som time.");
        Room *garage = new Room("Garage", "You are in the Garage. There are tools spread across the concerte floor complete with a Jeep Grand Cherokee on jack stands.");
        Room *masterBed = new Room("Master Bed Room", "You are in the Bed Room. A large Master Bed greets you as you walk into the room. You can see a large master bath as weel in the backround");
        Room *hallway = new Room("Hallway", "You are in the Hallway. A large set of stairs leads to the second floor, complete with a set to the basement. You also see a grand front door.");
        Room *familyRoom = new Room("Family Room", "You are in the Family Room. You see a dark leather couch in front of you as well as a brand new LCD TV. It aappears South Park is on TV.");
        Room *bathRoom = new Room("Bath Room", "You are in the Bath Room. A small room containing just a toilet is in front of you.");
        Room *frontLawn = new Room("Front Lawn", "You are in the Front Lawn. You are on a pathway and observe freshly cut grass as well as several trees scattered across the yard.");
        Room *backLawn = new Room("Back Lawn", "You are in the Back Lawn. You see 'Spot' running around chasing a tennis ball, as well as his dog house. A large wooden fence keeps him in the yard.");
        Room *keyRoom = new Room("Room of Keys", "This room has the Key for the Room of Treasures.");
        Room *lockedRoom = new Room("Locked Room", "This room can only be accessed when you have the key.");
        /* ----------Room Links---------- */

        /* Kitchen */
        kitchen->link(diningRoom, "North");
        kitchen->link(garage, "East");
        kitchen->link(masterBed, "South");
        kitchen->link(hallway, "West");

        /* Dining Room */
        diningRoom->link(kitchen, "South");
        diningRoom->link(familyRoom, "West");

        /* Master Bed Room */
        masterBed->link(kitchen, "North");
        masterBed->link(bathRoom, "West");

        /* Garage */
        garage->link(kitchen, "West");
        garage->link(backLawn, "East");

        /* Back Lawn */
        backLawn->link(garage, "West");
        backLawn->link(keyRoom,"South");

        /* Family Room */
        familyRoom->link(diningRoom, "East");
        familyRoom->link(hallway, "South");

        /* Hallway */
        hallway->link(familyRoom, "North");
        hallway->link(kitchen, "East");
        hallway->link(bathRoom, "South");
        hallway->link(frontLawn, "West");

        /* Front Lawn */
        frontLawn->link(hallway, "East");
        frontLawn->link(lockedRoom,"South");

        /* Bath Room */
        bathRoom->link(hallway, "North");
        bathRoom->link(masterBed, "East");

        /*Locked Room*/
        lockedRoom->link(frontLawn,"North");
        keyRoom->link(backLawn,"North");

        /* ----------Gameplay---------- */
        Room *currentRoom = kitchen;

        while (exitChoice != "quit")
        {
            currentRoom->printRoom();
            cout << endl;

            currentRoom->printLinked();

            if(currentRoom == keyRoom)
                foundkey = true;

            if(currentRoom == lockedRoom && foundkey == true)
                cout<<"Success you unlocked the room and won the game!"<<endl;

            else
            {
                cout << "Which exit? (Or 'quit'):";
                cin >> exitChoice;

                if(exitChoice != "quit" && exitChoice != "North" && exitChoice != "South" && exitChoice != "East" && exitChoice != "West")
                {
                    cout << "Invalid Entry!" << endl;
                    cout << "Which exit? (Or 'quit'):";
                    cin >> exitChoice;
                }

                cout << "You move to the " << exitChoice << "..." << endl;
                currentRoom->getLinked(exitChoice);

                currentRoom = currentRoom->getLinked(exitChoice);
            }
        }

        return 0;
}
