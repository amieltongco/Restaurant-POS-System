#include <time.h>

#include "display.h"
#include "menu.h"
#include "restaurant.h"
#include "table.h"

void getTime(int *pMinutes, int *pHours){
    int nTotalSeconds;

    nTotalSeconds = (int)time(NULL);

    nTotalSeconds += 28800;

    nTotalSeconds /= 60;
    *pMinutes = nTotalSeconds % 60;
    nTotalSeconds /= 60;
    *pHours = nTotalSeconds % 24;
}

int randomizeNumber(){
    int nRandom;

    srand(time(NULL));

    nRandom = (rand() % 5) + 1;

    return nRandom;
}

int isLeapYear (int nYear){
    int isLeap = 0;

    if (nYear % 4 == 0){
        isLeap = 1;
        if (nYear % 100 == 0){
            if (nYear % 400 == 0){
                isLeap = 1;
            }
            else{
                isLeap = 0;
            }
        }
    }

    return isLeap;
}

int isDateValid (int nDate){
    int nYear, nMonth, nDay;
    int bIsValid = 0;

    nYear = nDate / 10000;
    nMonth = nDate / 100 % 100;
    nDay = nDate % 100;

    switch(nMonth){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (nDay <= 31){
            bIsValid = 1;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (nDay <= 30){
            bIsValid = 1;
        }
        break;
    case 2:
        if (isLeapYear(nYear)){
            if (nDay <= 29){
                bIsValid = 1;
            }
        }
        else{
            if (nDay <= 28){
                bIsValid = 1;
            }
        }
    }

    return bIsValid;
}

void displayInitializeScreen(int *pDate, int *pStoreMenuItems, float *pSushiPrice, float *pMatchaPrice, float *pMochiPrice){
    int nChoice;

    do {
        printf("Please input password (Password is 123): ");
        scanf("%d", &nChoice);

        if (nChoice != 123){
            printf("Wrong password!\n");
        }
    } while(nChoice != 123);

    printLine('-', '-');
    printf("%38s", "Initialize Screen\n");
    printLine('-', '-');

    do {
        printf("Enter the date today: ");
        scanf("%d", pDate);
        if (!isDateValid(*pDate)){
            printf("Enter a valid date!\n");
        }
    } while (!isDateValid(*pDate));

    chooseMenuItems(pStoreMenuItems);

    modifyMenuPrice(pSushiPrice, pMatchaPrice, pMochiPrice, pStoreMenuItems);
}

void modifyMenuPrice(float *pSushiPrice, float *pMatchaPrice, float *pMochiPrice, int *pStoreMenuItems){
    int nChoice;
    float fPrice;
    *pSushiPrice = 159;
    *pMatchaPrice = 170;
    *pMochiPrice = 99;

    printLine('-', '-');
    do {
        printf("You may change the price of each menu:\n");
        printf("%9s%10s\n", "Menu", "Price");
        if (getMenuIndex(1, *pStoreMenuItems, 2) != -1){
            printf("[1] Sushi%10.2f\n", *pSushiPrice);
        }
        if (getMenuIndex(2, *pStoreMenuItems, 2) != -1){
            printf("[2] Matcha%9.2f\n", *pMatchaPrice);
        }
        if (getMenuIndex(3, *pStoreMenuItems, 2) != -1){
            printf("[3] Mochi%10.2f\n", *pMochiPrice);
        }
        printf("[0] Confirm\n");
        printf("Choice: ");
        scanf("%d", &nChoice);

        if (nChoice < 0 || nChoice > 3){
            printf("Enter a valid input!\n");
        }
        else if (getMenuIndex(nChoice, *pStoreMenuItems, 2) == -1){
            if (nChoice != 0){
                printf("That is not an available menu item for today\n");
            }
        }
        else{
            switch(nChoice){
            case 1:
                printf("Overwriting the price of Sushi:\n");
                printf("Price: ");
                scanf("%f", &fPrice);
                *pSushiPrice = fPrice;
                break;
            case 2:
                printf("Overwriting the price of Matcha:\n");
                printf("Price: ");
                scanf("%f", &fPrice);
                *pMatchaPrice = fPrice;
                break;
            case 3:
                printf("Overwriting the price of Mochi:\n");
                printf("Price: ");
                scanf("%f", &fPrice);
                *pMochiPrice = fPrice;
                break;
            }
        }
    } while (nChoice != 0);
}

void seatCustomer(int *pTable1, int *pTable2, int *pTable3, int *pTable4, int *pTable5,
                  int *pTable6, int *pTable7, int *pTable8, int *pStoreMenuItems){
    int nCustomers, nChoice, nPower, nIsEmpty, nAvailable;

    nCustomers = randomizeNumber();
    
    nAvailable = generateAvailabilityBinary(*pTable1, *pTable2, *pTable3, *pTable4, 
                                            *pTable5, *pTable6, *pTable7, *pTable8);

    if (nAvailable != 0 && countTotalStocks(*pStoreMenuItems) > 0){
        printf("There are %d customers waiting. Here are the available tables:\n", nCustomers);

        displayAvailableTables(*pTable1, *pTable2, *pTable3, *pTable4, *pTable5, 
                               *pTable6, *pTable7, *pTable8, 1);
        printf("Table: ");
        scanf("%d", &nChoice);

        if (nChoice >= 1 && nChoice <= 8){
            nPower = pow(10, nChoice - 1);
            nIsEmpty = nAvailable / nPower % 10;
            
            if (nIsEmpty){
                switch(nChoice){
                    case 1:
                        *pTable1 = nCustomers;
                        break;
                    case 2:
                        *pTable2 = nCustomers;
                        break;
                    case 3:
                        *pTable3 = nCustomers;
                        break;
                    case 4:
                        *pTable4 = nCustomers;
                        break;
                    case 5:
                        *pTable5 = nCustomers;
                        break;
                    case 6:
                        *pTable6 = nCustomers;
                        break;
                    case 7:
                        *pTable7 = nCustomers;
                        break;
                    case 8:
                        *pTable8 = nCustomers;
                        break;
                }
            }
            else{
            printf("Sorry, that table is already taken.\n");
            }
        }
        else{
            printf("Please enter a valid input.\n");
        }
    }    
    else if (countTotalStocks(*pStoreMenuItems) == 0){
        printf("Sorry, all our menu items are sold out\n");
    }
    else{
        printf("There are no tables available today. Please wait for the customers to finish.\n");
    }
}

void closeRestaurant(int nDate, int nOpenMinutes, int nOpenHours, float fTotalEarnings,
                     int nCustomers, int nSushiSold, int nMatchaSold, int nMochiSold, 
                     int nStoreMenuItems){
    int nCloseMinutes, nCloseHours, nTotalMinutes, nTotalHours; 
    nCloseMinutes = 0, nCloseHours = 0;
    getTime(&nCloseMinutes, &nCloseHours);

    printLine('-', '-');
    printf("%25s", "E");
    Sleep(250);
    printf("n");
    Sleep(250);
    printf("d");
    Sleep(250);
    printf(" ");
    Sleep(250);
    printf("o");
    Sleep(250);
    printf("f");
    Sleep(250);
    printf(" ");
    Sleep(250);
    printf("D");
    Sleep(250);
    printf("a");
    Sleep(250);
    printf("y\n");
    Sleep(250);
    printLine('-', '-');

    displayDate(nDate);
    printf(" Summary\n");

    printf("%-30s%02d:%02d\n", "Opening time", nOpenHours, nOpenMinutes);
    printf("%-30s%02d:%02d\n", "Closing time", nCloseHours, nCloseMinutes);
    nTotalHours = nCloseHours - nOpenHours;
    nTotalMinutes = nCloseMinutes - nOpenMinutes;
    if (nTotalMinutes < 0){
        nTotalHours--;
        nTotalMinutes += 60;
    }
    printf("%-30s%02d hour(s) and %02d minute(s)\n\n", "Total time opened", nTotalHours, nTotalMinutes);

    printf("%-30s%.2f\n", "Total Earnings", fTotalEarnings);
    printf("%-30s%d\n", "Total Number of Customers", nCustomers);
    if (nCustomers > 0){
        printf("%-30s%.2f\n\n", "Avg Earning/Customer", fTotalEarnings / nCustomers);
    }
    else{
        printf("%-30s%.2f\n\n", "Avg Earning/Transaction", 0.00);
    }

    printf("%-30s%d\n", "Total Items Sold", nSushiSold + nMatchaSold + nMochiSold);
    printf("    %-26s%d\n", "Sushi Sold", nSushiSold);
    printf("    %-26s%d\n", "Matcha Sold", nMatchaSold);
    printf("    %-26s%d\n\n", "Mochi Sold", nMochiSold);

    printf("%-30s%d\n", "Unsold Sushi Stocks", countMenuStocks(1, nStoreMenuItems));
    printf("%-30s%d\n", "Unsold Matcha Stocks", countMenuStocks(2, nStoreMenuItems));
    printf("%-30s%d\n", "Unsold Mochi Stocks", countMenuStocks(3, nStoreMenuItems));

    printLine('-', '-');
    printf("%35s", "THANK YOU!");
}