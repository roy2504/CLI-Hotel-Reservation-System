//prog71985 - Giteshj - w23 - Assignment 4 refactor - question 2 refactor 

#define _CRT_SECURE_NO_WARNINGS
#include "Hotel.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Utils.h"

bool SaveDataToFile(HOTEL h[])
{
    //open a file for write
    
    FILE* fp = fopen("hotel.txt", "w");

    if (!fp)                          // if there is problem
    {                      
        printf("Enabled to open file.\n");
        return false;
    }

    fwrite(h, sizeof(HOTEL), HOTELNUM, fp);       

    //close file

    fclose(fp);

    return true;
}

bool LoadDataFromFile(HOTEL h[]) {

    //open a file for read

    FILE* fp = fopen("hotel.txt", "r");

    if (!fp)                          // if there is problem
    {
        printf("Enabled to open file.\n");
        return false;
    }

    fread(h, sizeof(HOTEL), HOTELNUM, fp);        


    //close file

    fclose(fp);

    return true;
}

