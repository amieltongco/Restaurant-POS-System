#include "display.h"
#include "menu.h"

void chooseMenuItems (int *pStoreMenuItems){
    int nMenu, nChoice, nProceed = 0, nIndex, nRightMenu, nStocks, nPower;

    printLine('-', '-');

    do {
        printf("Select which menu items are available today:\n");
        printf("%29s\n", "In stock");
        printf("%11s%17d\n", "[1] Sushi", countMenuStocks(1, *pStoreMenuItems));
        printf("%12s%16d\n", "[2] Matcha", countMenuStocks(2, *pStoreMenuItems));
        printf("%11s%17d\n", "[3] Mochi", countMenuStocks(3, *pStoreMenuItems));
        printf("  [0] Confirm\n");
        printf("Choice: ");
        scanf("%d", &nMenu);
        
        nIndex = getMenuIndex(nMenu, *pStoreMenuItems, 2);

        switch(nMenu){
            case 0:
                if (*pStoreMenuItems / 1000000 == 0) {
                    printf("You must select at least two menu items today!\n");
                }
                else{
                    nProceed = 1;
                }
                break;
            case 1:
            case 2:
            case 3:
                if (nIndex == -1){
                    printf("Select how many are in stock today (0-99): ");
                    scanf("%d", &nChoice);

                    if (nChoice >= 0 && nChoice <= 99){
                        if (nChoice != 0){
                        *pStoreMenuItems *= 1000;
                        *pStoreMenuItems += nMenu*100;
                        *pStoreMenuItems += nChoice;
                        }
                    }
                    else{
                        printf("Invalid input!\n");
                    }                    
                }
                else {
                    nPower = pow(1000, nIndex);

                    printf("Overwriting the stock for ");
                    displayMenu(nMenu);
                    printf("\n");
                    printf("Select how many stocks of ");
                    displayMenu(nMenu);
                    printf(": ");
                    scanf("%d", &nChoice);

                    if (nChoice >= 0 && nChoice <= 99){
                        nRightMenu = *pStoreMenuItems % nPower;
                        *pStoreMenuItems = *pStoreMenuItems / nPower;
                        nStocks = *pStoreMenuItems % 100;
                        *pStoreMenuItems = *pStoreMenuItems - nStocks + nChoice;

                        if (nChoice == 0){
                            *pStoreMenuItems /= 1000;
                        }

                        *pStoreMenuItems = *pStoreMenuItems * nPower + nRightMenu;
                    }
                    else{
                        printf("Invalid input!\n");
                    }
                }
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
    } while(nProceed == 0);
}

int getMenuIndex (int nCheck, int nStoreMenuItems, int nMode){
    int nItem = -1, nIndex;

    nMode = pow(10, nMode);

    nStoreMenuItems /= nMode;

    for (nIndex = 0; nStoreMenuItems >=1 && nItem != nCheck; nIndex++){
        nItem = nStoreMenuItems % 10;
        nStoreMenuItems = nStoreMenuItems / (nMode * 10);
    }

    if (nItem == nCheck){
        nIndex -= 1;
    }
    else {
        nIndex = -1;
    }

    return nIndex;
}

int countMenuStocks(int nMenu, int nStoreMenuItems){
    int nIndex, nPower, nStocks;

    nIndex = getMenuIndex(nMenu, nStoreMenuItems, 2);

    if (nIndex != -1){
        nPower = 100 * pow(1000, nIndex);

        nStoreMenuItems %= nPower;

        nStocks = nStoreMenuItems / (nPower / 100);
    }
    else {
        nStocks = 0;
    }

    return nStocks;
}

int countTotalStocks(int nStoreMenuItems){
    return countMenuStocks(1, nStoreMenuItems) + countMenuStocks(2, nStoreMenuItems) + countMenuStocks(3, nStoreMenuItems);
}