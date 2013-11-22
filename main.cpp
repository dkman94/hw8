#include "room.h"
#include <iostream>

using namespace std;

int main()
{
   /* ---------- Variable Declerations ---------- */
        string exitChoice;

        /* ---------- Room Intialization ---------- */
        Room *kitchen = new room("Kitchen", "You are in the Kitchen. Pots and pans dangle above your head as you look across the room.");
        Room *diningRoom = new room("Dining Room", "You are in the Dining Room. You see a large table in the center of the room complete with a set of chairs. It seems no one has ate here in quite som time.");
        Room *garage = new room("Garage", "You are in the Garage. There are tools spread across the concerte floor complete with a Jeep Grand Cherokee on jack stands.");
        Room *masterBed = new room("Master Bed Room", "You are in the Bed Room. A large Master Bed greets you as you walk into the room. You can see a large master bath as weel in the backround");
        Room *hallway = new room("Hallway", "You are in the Hallway. A large set of stairs leads to the second floor, complete with a set to the basement. You also see a grand front door.");
        Room *familyRoom = new room("Family Room", "You are in the Family Room. You see a dark leather couch in front of you as well as a brand new LCD TV. It aappears South Park is on TV.");
        Room *bathRoom = new room("Bath Room", "You are in the Bath Room. A small room containing just a toilet is in front of you.");
        Room *frontLawn = new room("Front Lawn", "You are in the Front Lawn. You are on a pathway and observe freshly cut grass as well as several trees scattered across the yard.");
        Room *backLawn = new room("Back Lawn", "You are in the Back Lawn. You see 'Spot' running around chasing a tennis ball, as well as his dog house. A large wooden fence keeps him in the yard.");

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

        /* Bath Room */
        bathRoom->link(hallway, "North");
        bathRoom->link(masterBed, "East");

        /* ----------Gameplay---------- */
        room *currentRoom = kitchen;

        while (exitChoice != "quit")
        {
            currentRoom->printRoom();
            cout << endl;

            currentRoom->printLiked();

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
        return 0;
    }
