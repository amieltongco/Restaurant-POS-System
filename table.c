#include "display.h"
#include "menu.h"
#include "table.h"

int getCustomer(int nTable){

    if (nTable >= 1000000){
        nTable /= 1000000;
    }
    else if (nTable >= 1000){
        nTable /= 10000;
    }
    else if (nTable >= 100){
        nTable /= 100;
    }
    else if (nTable < 10){
        ;
    }
    else {
        nTable = -1;
    }
    return nTable;
}

int checkTableAvailability(int nTable){
    return !nTable;
}

int generateAvailabilityBinary(int nTable1, int nTable2, int nTable3, int nTable4, 
                               int nTable5, int nTable6, int nTable7, int nTable8){
    int nAvailable = 0;

    nAvailable += checkTableAvailability(nTable1);
    nAvailable += checkTableAvailability(nTable2) * 10;
    nAvailable += checkTableAvailability(nTable3) * 100;
    nAvailable += checkTableAvailability(nTable4) * 1000;
    nAvailable += checkTableAvailability(nTable5) * 10000;
    nAvailable += checkTableAvailability(nTable6) * 100000;
    nAvailable += checkTableAvailability(nTable7) * 1000000;
    nAvailable += checkTableAvailability(nTable8) * 10000000;

    return nAvailable;
}

void updateTableOrder(int *pTable, int *pStoreMenuItems){
    int nChoice = 0, nProceed = 0, nIndex, nRightMenu, nQuantity, nPower, nMenu = 0, nStocks;   

    printLine('-', '-');

    do {
        printf("Select customer's order:\n");
        printf("Number of customers: %d\n", getCustomer(*pTable));
        printf("%29s\n", "In stock");
        printf("%11s%17d\n", "[1] Sushi", countMenuStocks(1, *pStoreMenuItems));
        printf("%12s%16d\n", "[2] Matcha", countMenuStocks(2, *pStoreMenuItems));
        printf("%11s%17d\n", "[3] Mochi", countMenuStocks(3, *pStoreMenuItems));
        printf("  [0] Confirm\n");
        printf("Choice: ");
        scanf("%d", &nMenu);
        
        nIndex = getMenuIndex(nMenu, *pTable, 1);

        switch(nMenu){
            case 0:
                    nProceed = 1;
                    break;
            case 1:
            case 2:
            case 3:
                if (nIndex == -1){
                    do{
                        
                        printf("Select order quantity (0-9): ");
                        scanf("%d", &nChoice);
                        if (nChoice >= 0 && nChoice <= 9){
                            if (nChoice <= countMenuStocks(nMenu, *pStoreMenuItems)){
                                if (nChoice != 0){
                                    // Updates order
                                    *pTable *= 100;
                                    *pTable += nMenu * 10;
                                    *pTable += nChoice;

                                    nIndex = getMenuIndex(nMenu, *pStoreMenuItems, 2);
                                    nPower = pow(1000, nIndex);

                                    // Update the number of stocks
                                    nRightMenu = *pStoreMenuItems % nPower;
                                    *pStoreMenuItems = *pStoreMenuItems / nPower;
                                    *pStoreMenuItems = *pStoreMenuItems - nChoice;
                                    *pStoreMenuItems = *pStoreMenuItems * nPower + nRightMenu;
                                }
                            }
                            else{
                                printf("Insufficient stocks!\n");
                            }
                        }
                        else{
                            printf("Choose an integer from 0 to 9!\n");
                        }
                    } while (nChoice < 0 || nChoice > 9);
                }
                else {
                    nPower = pow(100, nIndex);

                    printf("Overwriting the number of orders for ");
                    displayMenu(nMenu);
                    printf("\n");
                    printf("Select order quantity of ");
                    displayMenu(nMenu);
                    printf(": ");
                    scanf("%d", &nChoice);

                    if (nChoice >= 0 && nChoice <= 9){
                        // Add the current order quantity to the total number of stocks
                        nRightMenu = *pTable % nPower;
                        *pTable = *pTable / nPower;
                        nQuantity = *pTable % 10;
                        nStocks = nQuantity + countMenuStocks(nMenu, *pStoreMenuItems);

                        if (nChoice <= nStocks){
                            //printf("Overwriting...\n");
                            // Update the number of orders
                            *pTable = *pTable - nQuantity + nChoice;

                            // Remove menu from list if 0 zero orders
                            if (nChoice == 0){
                                *pTable /= 100;
                            }
							
                            *pTable = *pTable * nPower + nRightMenu;
                            
                            // Update the number of stocks
                            nIndex = getMenuIndex(nMenu, *pStoreMenuItems, 2);
                            nPower = pow(1000, nIndex);

                            nRightMenu = *pStoreMenuItems % nPower;
                            *pStoreMenuItems = *pStoreMenuItems / nPower;
                            *pStoreMenuItems = *pStoreMenuItems - nChoice + nQuantity;
                            *pStoreMenuItems = *pStoreMenuItems * nPower + nRightMenu;
                        }
                        else{
                            printf("Insufficient stocks!\n");
                            *pTable = *pTable * nPower + nRightMenu;
                        }
                    }
                    else{
                        printf("Choose an integer from 0 to 9!\n");
                    }                   
                }
                break;
            default:
                printf("Invalid input!\n");
                break;   
        }
    } while(nProceed == 0);
}