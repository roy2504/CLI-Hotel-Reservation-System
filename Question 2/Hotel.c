//prog71985 - Giteshj - w23 - Assignment 4 refactor - question 2 refactor 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Hotel.h"
#include <stdbool.h>
#include <string.h>
#include "HotelFile.h"

#define ROOMAMOUNT        6     //6 rooms to be King Sized and six rooms to be Queen sized 



void InitialiseArrayRooms(HOTEL h[]) {

	//initialising array of struct
	
	for (int j = 1; j <= HOTELNUM; j++)
	{
		for (int i = 1; i <= MAXROOM; i++)
		{
			h[j].rooms[i].roomID = i;
			h[j].rooms[i].roomStatus = EMPTY;
			strcpy(h[j].rooms[i].guestLastName, "");
			strcpy(h[j].rooms[i].guestFirstName, "");

			if (i <= ROOMAMOUNT)
				strcpy(h[j].rooms[i].roomType, "Single Kings");                         //added room type
			else
				strcpy(h[j].rooms[i].roomType, "Queen Plus Two Singles");
		}
	}
}

//*******************************************************************************************
//REFACTOR - modified all functions to only perform a particular action in the selected hotel
//*******************************************************************************************


// Function to display number of unbooked rooms

	void DisplayNumberofUnbookedRooms(HOTEL h[], int hotel) {           
    
	int empty = 0;                                 

	//iteration to search and display the number of unbooked rooms
	
		for (int i = 1; i <= MAXROOM; i++)
		{
			if (h[hotel].rooms[i].roomStatus == EMPTY)
			{
				empty++;
			}
		}
	printf("\nThere are %d empty rooms.\n", empty);
}


	//function to display unbooked rooms
	void DisplayUnbookedRooms(HOTEL h[], int hotel) {                 

		printf("\nList of empty rooms:\n");

		//iteration to search and display the unbooked rooms and the room type

		{
			for (int i = 1; i <= MAXROOM; i++) {
				if (h[hotel].rooms[i].roomStatus == EMPTY) {
					printf("\nRoomNo:%d\n", h[hotel].rooms[i].roomID);
					printf("Suitetype:%s\n", h[hotel].rooms[i].roomType);
				}
			}
		}
	}


	//function to display booked guests name, with last names in alphabetical order
	void DisplayBookedGuestName(HOTEL h[], int hotel){

	//Loop for Sorting names in alphabetical order

		for (int i = 1; i < MAXROOM; i++) 
	{
		for (int j = i + 1; j <= MAXROOM; j++) 
		{

			if (strcmp(h[hotel].rooms[i].guestLastName, h[hotel].rooms[j].guestLastName) > 0)     //comparing if last name at index i comes later in alphabetical order than last name at index j. 
			{
			  //switching positions in array
	
				ROOM temp = h[hotel].rooms[i];                             
				h[hotel].rooms[i] = h[hotel].rooms[j];
				h[hotel].rooms[j] = temp;
			}
		}
	}

	printf("\nGuest list sorted based on their last names\n");
	for (int count = 1; count <= MAXROOM; count++)
	{
		//Displaying last name, in alphabetical order, and first name of guests who have booked rooms

		if (h[hotel].rooms[count].roomStatus == BOOKED) {
			printf("%s %s\n", h[hotel].rooms[count].guestLastName, h[hotel].rooms[count].guestFirstName);
		}
	}
};


	//function to book rooms
int BookRoomForGuest(HOTEL h[], int hotel) {
	 
	int room_number = 0;
	
	printf("Here is a list of the rooms available\n");
	DisplayUnbookedRooms(h,hotel);                                                                           //displaying the unbooked rooms 

	printf("\nPlease enter the room number you want to book:\n");
	scanf_s("%d", &room_number);

	if (room_number <= 0 || room_number > MAXROOM || h[hotel].rooms[room_number].roomStatus == BOOKED) {               //verifying if number entered is valid or if room is already booked
		printf("INVALID NUMBER OR ROOM IS ALREADY BOOKED\n");
	}
	else {

		//Abort Functionality
		int answer = 0;
		printf("Are you sure you want to book this room?\n");
		printf("Enter any number if you want to continue\n");
		printf("Enter 0 if you want to quit\n");
		scanf_s("%d", &answer);

		if (answer == 0)
			return 0;


	    //Booking Room

		h[hotel].rooms[room_number].roomStatus = BOOKED;                                                                           

		printf("\nPlease enter your last name:\n");
		scanf_s("%s", h[hotel].rooms[room_number].guestLastName, MAXNAME);


		printf("\nPlease enter your first name:\n");
		scanf_s("%s", h[hotel].rooms[room_number].guestFirstName, MAXNAME);

		printf("Room %d has been booked by %s %s\n", h[hotel].rooms[room_number].roomID, h[hotel].rooms[room_number].guestLastName, h[hotel].rooms[room_number].guestFirstName);
	}
	return 0;                                                //fixed 
}

//Function to display the rooms that have been booked

bool DisplayBookedRooms(HOTEL h[], int hotel) {

	bool found = false;
	printf("\nList of booked rooms:\n");

	for (int i = 1; i <= MAXROOM; i++)           //iteration to search and display booked rooms 
	{
		if (h[hotel].rooms[i].roomStatus == BOOKED)
		{

			printf("RoomId:%d\n", h[hotel].rooms[i].roomID);
			printf("Suitetype:%s\n\n", h[hotel].rooms[i].roomType);
			found = true;
		}
	}
	if (found == false)
	{
		printf("There are no booked rooms\n");
		return false;
	}
	else
		return true;
}


int DeleteRoomBooking(HOTEL h[], int hotel) {                         //function to delete bookings

	int Rnumber = 0;

	printf("\nBooking cancellation Platform\n");

	bool result = DisplayBookedRooms(h, hotel);                                     //displaying booked rooms

	if (result == false)
		return 0;
	
	printf("Please enter the room number you want to cancel\n");

	scanf_s("%d", &Rnumber);

	//Abort Functionality
	int answer = 0;
	printf("Are you sure you want to delete the booking?\n");
	printf("Enter any number if you want to continue\n");
	printf("Enter 0 if you want to quit\n");
	scanf_s("%d", &answer);

	if (answer == 1)
		return 0;

	
	//searching for room number and initialising
	bool found = false;

	for (int i = 0; i <= MAXROOM && found==false; i++)
	{
		

		if (h[hotel].rooms[i].roomID == Rnumber) {
			h[hotel].rooms[i].roomStatus = EMPTY;
			strcpy(h[hotel].rooms[i].guestLastName, "");
			strcpy(h[hotel].rooms[i].guestFirstName, "");
			found = true;
			printf("Booking for room %d has been sucessfully deleted\n", h[hotel].rooms[Rnumber].roomID);
		}
	}

	//if room number was not found
	if (found == false)
		printf("Room number not found\n");

	return 0;
}
