/******************************************************************
This is to certify that this project is my own work, based on my personal efforts
in studying and applying the concepts learned. I have constructed the functions
and their respective algorithms
and corresponding code by myself. The program was run, tested, and debugged by my
own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
Tongco, Amiel S., DLSU ID# 125*****
******************************************************************/

/*
 Description: This restaurant POS system allows the user to seat customer, update orders, print bill,
              and finally, close the restaurant. Additionally, it allows customization in number of
              stocks per menu item. 
 Programmed by: Tongco, Amiel S. S13B
 Last modified: August 20, 2026
 Version: 1.1.0
 [Acknowledgements: Bro Code (https://www.youtube.com/watch?v=xND0t1pr3KY)]
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "billOut.h"
#include "display.h"
#include "menu.h"
#include "restaurant.h"
#include "table.h"

int main(){
    int nChoice, nDate, nStoreMenuItems, nCount = 0, nCustomers = 0, nAvailability, nOpenMinutes = 0, nOpenHours = 0;
    int nTable1, nTable2, nTable3, nTable4, nTable5, nTable6, nTable7, nTable8;
    int nSushiSold, nMatchaSold, nMochiSold;
    float fSushiPrice, fMatchaPrice, fMochiPrice, fTotalEarnings;

    nStoreMenuItems = 1;
    nTable1 = nTable2 = nTable3 = nTable4 = nTable5 = nTable6 = nTable7 = nTable8 = 0;
    nSushiSold = nMatchaSold = nMochiSold = 0;
    fTotalEarnings = 0.0;

    // Get the time when the store was opened
    getTime(&nOpenMinutes, &nOpenHours);

    printLine('-', '-');
    printf("%49s\n", "Welcome To The Restaurant POS System!");
    printLine('-', '-');

    displayInitializeScreen(&nDate, &nStoreMenuItems, &fSushiPrice, &fMatchaPrice, &fMochiPrice);
    
    do {
        displayWarnings(nStoreMenuItems);
        Sleep(1000);

        displayTerminal(nDate, nTable1, nTable2, nTable3, nTable4,
                        nTable5, nTable6, nTable7, nTable8);
        printLine('-', '-');

        printf("  [1] Seat Customer\n");
        printf("  [2] Update Order\n");
        printf("  [3] Bill Out\n");
		printf("  [4] Close Restaurant\n");
        printf("Choice: ");
        scanf("%d", &nChoice);
        
        switch(nChoice){
            case 1:
                seatCustomer(&nTable1, &nTable2, &nTable3, 
                             &nTable4, &nTable5, &nTable6, &nTable7, &nTable8, &nStoreMenuItems);
                break;
            case 2:
                displayUpdateOrderScreen(&nTable1, &nTable2, &nTable3, &nTable4,
                                         &nTable5, &nTable6, &nTable7, &nTable8, &nStoreMenuItems);
                break;
            case 3:
                billOut(&nTable1, &nTable2, &nTable3, &nTable4, &nTable5, &nTable6,
                        &nTable7, &nTable8, &nStoreMenuItems, &nSushiSold, &nMatchaSold, 
                        &nMochiSold, &nCount, &nCustomers, nDate, fSushiPrice, fMatchaPrice, fMochiPrice, &fTotalEarnings);
                break;
            case 4:
                nAvailability = generateAvailabilityBinary(nTable1, nTable2, nTable3, nTable4,
                                                           nTable5, nTable6, nTable7, nTable8);
                if (nAvailability == 11111111){
                    // Check if restaurant is empty before closing
                    printf("Please input password to confirm closing the restaurant (123): ");
                    scanf("%d", &nChoice);

                    if (nChoice == 123){
                        closeRestaurant(nDate, nOpenMinutes, nOpenHours, fTotalEarnings, nCustomers,
                                        nSushiSold, nMatchaSold, nMochiSold, nStoreMenuItems);
                        nChoice = 4;
                    }
                    else{
                        printf("Wrong password!\n");
                        nChoice = 0;
                    }
                }
                else{
                    printf("There are still customers inside the restaurant!\n");
                    nChoice = 0;
                }
                break;
            default:
                printf("Invalid input!");
                break;
        }
    } while(nChoice != 4);
    return 0;
}