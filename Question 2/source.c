/*program for a hotel company that uses an array of 12 structures which each should hold
a room identification number, a marker that indicates whether the room
is booked, the last name of the booking guest, and the first name of the
booking guest.*/

/*REFACTOR - program to have 2 hotels with different room type (king sized and queen sized)*/

// Date: April 7 2023

#include <stdio.h>
#include <string.h>
#include "DisplayMenu.h"
#include "Hotel.h"
#include "HotelFile.h"
#define HOTELPLUSONE     3                            //So that the loop doesn't write passed the array, initialising to 2 was giving runtime error


int main(void) {

    //modified parameter passing
    
    HOTEL hotels[HOTELPLUSONE];                       //modified Array of structure

    InitialiseArrayRooms(hotels);                     //Function to initialise array

    LoadDataFromFile(hotels);                         //loading saved data from file

    PrintWelcomeMenu();                               //Function to print the welcome message

    DisplayHotelType(hotels);                         //Function to display hotel selection and booking menu.

    SaveDataToFile(hotels);                           //saving data in file

    return 0;
}

