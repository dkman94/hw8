#include <iostream>
#include <string>
#include <map>
#include <fstream>

#include "room.h"

using namespace std;

int main()
{
        bool foundkey = false;
        bool unlockRoom = false;
    /* ---------- Variable Declerations ---------- */
        string exitChoice;

        /* ---------- Room Intialization ---------- */
        Room *kitchen = new Room("Kitchen", "You are in the Kitchen. There are Yams everywhere.");
        Room *diningRoom = new Room("Dining Room", "Tastefully created dishes are spread across the table on the finest Versace linens.");
        Room *garage = new Room("Garage", "Interestingly 2 Chainz drives a 1997 Toyota Corolla. Who would have guessed. And of course it does not have a ceiling.");
        Room *masterBed = new Room("Master Bed Room", "2 Chainz's bed is a jacuzzi...not quite sure who that works but to each is own.");
        Room *hallway = new Room("Hallway", "You are in the Hallway. It's a pretty standard Gucci accesorized hallway.");
        Room *trophyRoom = new Room("Trophy Room", "You are in the Trophy Room. Framed weaves as far as the eye can see...");
        Room *bathRoom = new Room("Bath Room", "You are in the Bath Room. 2 Words: GOLDEN TOILET.");
        Room *frontLawn = new Room("Front Lawn", "You are in the Front Lawn. You see the grass is freshly cut and a white picket fence is visible in the distance. A Rhinestone path leads you to the Locked Room.");
        Room *backLawn = new Room("Back Lawn", "You are in the Back Lawn. There's another Jacuzzi and a large charcoal girll. That's about it.");
        Room *keyRoom = new Room("Room of Keys", "This room has the Key for the Room of Treasures. But for real it's an entire room for 1 key.");
        Room *lockedRoom = new Room("Locked Room", "This room can only be accessed when you have the key.");
        /* ----------Room Links---------- */

        /* Kitchen */
        kitchen->link(diningRoom, "North");
        kitchen->link(garage, "East");
        kitchen->link(masterBed, "South");
        kitchen->link(hallway, "West");

        /* Dining Room */
        diningRoom->link(kitchen, "South");
        diningRoom->link(trophyRoom, "West");

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
        trophyRoom->link(diningRoom, "East");
        trophyRoom->link(hallway, "South");

        /* Hallway */
        hallway->link(trophyRoom, "North");
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
        int kitchenCount = 0;
        cout<<"Welcome to the 2 Chainz Mansion!"<<endl;

        while (exitChoice != "quit")
        {
            currentRoom->printRoom();
            cout << endl;

            currentRoom->printLinked();

            if(currentRoom == keyRoom)
                foundkey = true;

            if(currentRoom == lockedRoom && foundkey == true)
                unlockRoom = true;

            if(unlockRoom)
            {
                cout<<"Congratulations! You have unlocked the room and won the game!"<<endl;
                cout<<"Want to know what's in 2 Chain's room of treasures?!?! You guessed it! More weaves..."<<endl;
            }

            if(currentRoom == kitchen)
                kitchenCount++;
            if(kitchenCount > 1)
            {
                string cook;
                int cCount = 0;
                cout<<"Uh oh! Its #MEALTIME! Better show them how to cook!"<<endl;
                cout<<"Hit c to keep cookin!"<<endl;
                while(cCount < 10)
                {
                     cin>>cook;
                     cCount++;
                }
                cout<<"Killed it!!! Let's keep on going..."<<endl;

            }

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
