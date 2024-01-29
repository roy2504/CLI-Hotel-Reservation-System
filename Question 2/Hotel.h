#pragma once
//prog71985 - Giteshj - w23 - Assignment 4 refactor - question 2 refactor 

#include <stdbool.h>
#define MAXROOM   12        //maximum number of room
#define MAXNAME   40        //maximum characters for name 
#define HOTELNUM   2        //number of hotels
#define MAXROOMPLUSONE  13  //So that the loop doesn't write passed the array, initialising to 12 was giving runtime error


typedef enum status { EMPTY, BOOKED } STATUS;     //enum to know if room is booked or not 

typedef struct room
{
	int roomID;
	STATUS roomStatus;
	char guestLastName[MAXNAME];
	char guestFirstName[MAXNAME];
	char roomType[MAXNAME];
} ROOM;

typedef struct hotel
{
	ROOM rooms[MAXROOMPLUSONE];           // added a new structure
}HOTEL;

//modified all functions
void InitialiseArrayRooms(HOTEL[] );

void DisplayNumberofUnbookedRooms(HOTEL[],int);

void DisplayUnbookedRooms(HOTEL[],int);

void DisplayBookedGuestName(HOTEL[],int);

int BookRoomForGuest(HOTEL[], int);

int DeleteRoomBooking(HOTEL[], int);

bool DisplayBookedRooms(HOTEL[], int);
