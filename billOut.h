#ifndef BILLOUT_H
#define BILLOUT_H

#include <stdio.h>
#include <math.h>

/*  
    Displays the screen for billing out
    
    Precondition: pTable# and pStoreMenuItems must adhere to their respective variable's format.
    @param nTable stores table's information
    @param nDate is the date in YYYYMMDD format
    @param nTableNum holds the table number
    @param pCount counts how many batches of customer has arrived
    @param pCustomers counts the total number of customers
    @param pSushiSold determines how many sushi have been sold
    @param pMatchaSold determines how many matcha have been sold
    @param pMochiSold determines how many mochi have been sold
    @param fSushiPrice is the price of sushi
    @param fMatchaPrice is the price of matcha
    @param fMochiPrice is the price of mochi
    @param pTotalEarnings counts the total earnings
    @return prints the bill
*/
void printBill(int nTable, int nDate, int nTableNum, int *pCount, int *pCustomers,
               int *pSushiSold, int *pMatchaSold, int *pMochiSold,
               float fSushiPrice, float fMatchaPrice, float fMochiPrice,
               float *pTotalEarnings);

/*  
    Displays the screen for billing out

    Precondition: pTable# and pStoreMenuItems must adhere to their respective variable's format.
    @param pTable stores table's information
    @param pStoreMenuItems is the storage variable for menu items and number of stocks
    @param pSushiSold determines how many sushi have been sold
    @param pMatchaSold determines how many matcha have been sold
    @param pMochiSold determines how many mochi have been sold
    @param pCount counts how many batches of customer has arrived
    @param pCustomers counts the total number of customers
    @param nDate is the date in YYYYMMDD format
    @param fSushiPrice is the price of sushi
    @param fMatchaPrice is the price of matcha
    @param fMochiPrice is the price of mochi
    @param pTotalEarnings counts the total earnings
    @return will either proceed to printing out the bill or go back to the terminal
*/
void billOut(int *pTable1, int *pTable2, int *pTable3, int *pTable4, int *pTable5, int *pTable6, 
             int *pTable7, int *pTable8, int *pStoreMenuItems, int *pSushiSold, int *pMatchaSold, 
             int *pMochiSold, int *pCount, int *pCustomers, int nDate, float fSushiPrice, 
             float fMatchaPrice, float fMochiPrice, float *pTotalEarnings);

#endif