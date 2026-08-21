#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <math.h>

/*  Identifies the number of customer in a table.

    Precondition: The input must adhere to the table variable's format.
    @param nTable is the table information
    @return the number of customers
*/
int getCustomer(int nTable);

/*  Determines if a table is available by returning 1 or 0

    Precondition: nTable must adhere to the table variable's format.
    @param nTable stores the table's information
    @return Either 1 (table is empty) or 0 (table is occupied)
*/
int checkTableAvailability(int nTable);

/*  Shows which tables are available through 1's and 0's

    Precondition: The input must adhere to the table variable's format.
    @param nTable# is the table information
    @return returns a binary showing which tables are available
*/
int generateAvailabilityBinary(int nTable1, int nTable2, int nTable3, int nTable4, 
                               int nTable5, int nTable6, int nTable7, int nTable8);

/*  Updates a table's order

    Precondition: pTable must adhere to the table variable's format.
    @param pTable stores table's information
    @param pStoreMenuItems is the storage variable for menu items and number of stocks
*/
void updateTableOrder(int *pTable, int *pStoreMenuItems);

#endif
