#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <time.h>
#include <math.h>

/*  Displays a line
    @param cOut are the outer char
    @param cIn are the char inside the line
*/
void printLine(char cOut, char cIn);

/*  This function extracts, format, and display the date from YYYYMMDD to YYYY Month DD format

    Precondition: The input date contains only 8 digits
    @param nDate is the input date in YYYYMMDD format
    @return displays the formatted date into YYYY Month DD format
*/
void displayDate(int nDate);

/*  Displays the current time

    Precondition: The year is before 2038 (int overflow)
*/
void displayTime(void);

/*  Displays the corresponding menu item from int into string.

    Precondition: The input is an integer from 1 to 3
    @param nMenu is the menu item that will be printed
*/
void displayMenu(int nMenu);

/*  Displays which tables are available or not depending on the parameter

    Precondition: The input must adhere to the table variable's format.
    @param nTable# is the table information
*/
void displayAvailableTables(int nTable1, int nTable2, int nTable3, int nTable4, int nTable5,
                            int nTable6, int nTable7, int nTable8, int isEmpty);

/*  Displays the tables' orders for the terminal display

    Precondition: The input must adhere to the table variable's format.
    @param nTable is the table information
    @param nIndex determines which item should be displayed
    @param nTableNumber is used to determine the width for display purposes
*/
void printOrders(int nTable, int nIndex, int nTableNumber);

/*  Displays the terminal / table layout of the POS system

    Precondition: The nTable# must adhere to the table's format.
    @param nDate is the date in YYYYMMDD format
    @param nTable# are the corresponding table information containing the number of 
           customers and their orders
*/
void displayTerminal(int nDate, int nTable1, int nTable2, int nTable3, int nTable4,
                     int nTable5, int nTable6, int nTable7, int nTable8);

/*  Displays the screen in updating a table's order

    Precondition: pTable# must adhere to the table variable's format.
    @param pTable stores table's information
    @param pStoreMenuItems is the storage variable for menu items and number of stocks
*/
void displayUpdateOrderScreen(int *pTable1, int *pTable2, int *pTable3, int *pTable4, int *pTable5,
                              int *pTable6, int *pTable7, int *pTable8, int *pStoreMenuItems);

/*  Displays the receipt

    Precondition: nTable must adhere to the table variable's format.
    @param fCash is the customer's payment
    @param nTable stores table's information
    @param nDate is the date in YYYYMMDD format
    @param nTableNum holds the table number
    @param pCount counts how many batches of customer has arrived
    @param pCustomers counts the total number of customers
*/
void displayReceipt(float fCash, int nTable, int nDate, int nTableNum, int *pCount, int *pCustomers,
                    int *pSushiSold, int *pMatchaSold, int *pMochiSold,
                    float fSushiPrice, float fMatchaPrice, float fMochiPrice, float *pTotalEarnings);

/*  Displays out of stock menu items
    
    Precondition: nStoreMenuItems is in the correct format
    @param nStoreMenuItems stores the menu items and its stock quantity
*/
void displayWarnings(int nStoreMenuItems);

#endif