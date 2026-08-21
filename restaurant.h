#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

/*  Records the current time

    Precondition: The year is before 2038 (int overflow)
    @param pMinutes holds the minute
    @param pHours holds the hours
*/
void getTime(int *pMinutes, int *pHours);

/*  Returns a pseudorandom number using the time function.
    @return a pseudorandom number for the number of customers
*/
int randomizeNumber(void);

/*  Determines if the year is a leap year

    Precondition: nDate  must be in YYYYMMDD format and must be after the year 999 A.D.
    @param nDate is the date in YYYYMMDD format
    @return boolean value if it is a leap year or not
*/
int isLeapYear(int nYear);

/*  Determines if the date is valid

    Precondition: nDate  must be in YYYYMMDD format and must be after the year 999 A.D.
    @param nDate is the date in YYYYMMDD format
    @return boolean value if valid or not
*/
int isDateValid(int nDate);

/*  Allows the manager to do the following operations:
        (a) Initialize the POS system
        (b) Input the current date
        (c) Modify the product prices
        (d) Determine the number of stocks per item

    Precondition: pDate  must be in YYYYMMDD format
    @param pDate is the date in YYYYMMDD format
    @param pStoreMenuItems stores the number of stocks of each menu item
    @param pSushiPrice is the sushi price
    @param pMatchaPrice is the matcha price
    @param pMochiPrice is the sushi price
*/
void displayInitializeScreen(int *pDate, int *pStoreMenuItems, 
                             float *pSushiPrice, float *pMatchaPrice, float *pMochiPrice);

/*  Modifies the price for each menu item

    Precondition: pStoreMenuItems is in the correct format
    @param pStoreMenuItems stores the menu items and its stock quantity
    @param pSushiPrice is the price for sushi
    @param pMatchaPrice is the price for matcha
    @param pMochiPrice is the price for mochi
*/
void modifyMenuPrice(float *pSushiPrice, float *pMatchaPrice, float *pMochiPrice, int *pStoreMenuItems);

/*  Seats a customer

    Precondition: nTable and pStoreMenuItems must adhere to their respective variable's format.
    @param nDate is the date in YYYYMMDD format
    @param pCount counts how many batches of customer has arrived
    @param pTable# stores table's information
    @param pStoreMenuItems is the storage variable for menu items and number of stocks
*/
void seatCustomer(int *pTable1, int *pTable2, int *pTable3, int *pTable4, int *pTable5,
                  int *pTable6, int *pTable7, int *pTable8, int *pStoreMenuItems);

/*  Closes the restaurant and displays summary

    Precondition: nStoreMenuItems must adhere to its format.
    @param nDate is the date in YYYYMMDD format
    @param nOpenMinutes is the minutes when the restaurant was opened
    @param nOpenHours is the hours when the restaurant was opened
    @param fTotalEarnings counts the total earnings
    @param pCustomers counts the total number of customers
    @param pSushiSold determines how many sushi have been sold
    @param pMatchaSold determines how many matcha have been sold
    @param pMochiSold determines how many mochi have been sold
    @param pStoreMenuItems is the storage variable for menu items and number of stocks
*/
void closeRestaurant(int nDate, int nOpenMinutes, int nOpenHours, float fTotalEarnings,
                     int nCustomers, int nSushiSold, int nMatchaSold, int nMochiSold, 
                     int nStoreMenuItems);

#endif