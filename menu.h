#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <math.h>

/*  Allows the manager to choose the menu items for the day and its corresponding number of stocks

    Precondition: pStoreMenuItems must adhere to its format
    @param pStoreMenuItems is the storage variable for menu items and number of stocks
    @return pStoreMenuItems
*/
void chooseMenuItems(int *pStoreMenuItems);

/*  Identifies the index of a specific menu item from the storage variable

    Precondition: The storage variable must be at most 9 digits
    @param nCheck is the menu item whose index will be identified
    @param nStoreMenuItems stores the amount of stocks or quantity of each menu item
    @param nMode is either 1 (for table orders) or 2 (for stock quantity)
    @return returns the index of the specified menu item
*/
int getMenuIndex(int nCheck, int nStoreMenuItems, int nMode);

/*  Counts the number of stocks for a specific menu item

    Precondition: nStoreMenuItems is in the correct format
    @param nMenu is the menu item to be checked
    @param nStoreMenuItems stores the menu items and its stock quantity
    @return the number of stocks
*/
int countMenuStocks(int nMenu, int nStoreMenuItems);

/*  Identifies the total number of stocks

    Precondition: nStoreMenuItems is in the correct format
    @param nStoreMenuItems stores the menu items and its stock quantity
    @return the total number of stocks
*/
int countTotalStocks(int nStoreMenuItems);

#endif