

#include <stdio.h>
#include "Hotel.h"
#include <ctype.h>
#include "DisplayMenu.h"
#include <stdbool.h>
#define NEW       1         //integer used when new hotel is selected
#define ORIGINAL       2    //integer used when Original hotel is selected

void PrintWelcomeMenu() {
	printf("***Welcome to the StayRite Hotel Company!***\n");
}

void DisplayMenuOptions(HOTEL h[], int hotel) {
    bool continueProgram = true;
    char select;

    while (continueProgram)
    {
        printf("\nTo choose a function, enter its letter label:\n");
        printf("a) Show number of empty (unbooked) rooms\n");
        printf("b) Show list of the empty (unbooked) rooms\n");
        printf("c) Show alphabetical listing of guests who have booked a room\n");
        printf("d) Book a room to a guest\n");
        printf("e) Delete an existing room booking\n");
        printf("f) Return to hotel selection\n");



        // DisplayMenuOptions();                          //Function to print menu options

        scanf_s(" %c", &select, 1);                      //read one character only.
        select = tolower(select);

        switch (select)
        {
        case 'a':

            DisplayNumberofUnbookedRooms(h,hotel);       // Function to display number of unbooked rooms
            break;

        case 'b':
            DisplayUnbookedRooms(h, hotel);               //function to display unbooked rooms
            break;

        case 'c':
            DisplayBookedGuestName(h, hotel);             //function to display booked guests name, with last names in alphabetical order
            break;

        case 'd':
            BookRoomForGuest(h, hotel);                   //function to book rooms
            break;

        case 'e':
            DeleteRoomBooking(h, hotel);                  //function to delete bookings
            break;

        case 'f':

            continueProgram = false;                   //assigning to false so that to exit the loop
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}


void DisplayHotelType(HOTEL h[])
{
    bool continueProg = true;
    char choice;
    while (continueProg)
    {
        printf("\nTo choose a function, enter its letter label:\n");
        printf("1) Display new hotel\n");
        printf("2) Display old hotel\n");
        printf("3) Exit\n");

        scanf_s(" %c", &choice, 1);                      //read one character only.
        choice = tolower(choice);

        switch (choice)
        {
        case '1':
            printf("\n****New hotel Selected****\n");
            DisplayMenuOptions(h,NEW);                  //function to display contents of the new hotel menu 
            break;

        case '2':
        {
            printf("\n****Original Hotel Selected****\n");
            DisplayMenuOptions(h, ORIGINAL);            //function to display contents of the original hotel menu
            break;
        }
        case '3':
            continueProg = false;                       //assigned to false so that to exit the loop 
            break;

        default:
            printf("INVALID CHOICE. PLEASE TRY AGAIN.\n");
            break;
        }
    }
}


