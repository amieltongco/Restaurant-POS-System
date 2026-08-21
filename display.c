#include <stdio.h>
#include "display.h"
#include "menu.h"
#include "table.h"

void printLine(char cOut, char cIn){
    int i;

    printf("%c", cOut);

    for (i = 0; i < 58; i++)
        printf("%c", cIn);
    
    printf("%c\n", cOut);
}

void displayDate (int nDate){
    int nYear, nMonth, nDay;
    
    nYear = nDate / 10000;
    nDay = nDate % 100;

    nMonth = nDate % 10000 / 100;

    switch (nMonth) {
        case 1:
            printf("%d Jan %02d", nYear, nDay);
            break;
        case 2:
            printf("%d Feb %02d", nYear, nDay);
            break;
        case 3:
            printf("%d Mar %02d", nYear, nDay);
            break;
        case 4:
            printf("%d Apr %02d", nYear, nDay);
            break;
        case 5:
            printf("%d May %02d", nYear, nDay);
            break;
        case 6:
            printf("%d Jun %02d", nYear, nDay);
            break;
        case 7:
            printf("%d Jul %02d", nYear, nDay);
            break;
        case 8:
            printf("%d Aug %02d", nYear, nDay);
            break;
        case 9:
            printf("%d Sep %02d", nYear, nDay);
            break;
        case 10:
            printf("%d Oct %02d", nYear, nDay);
            break;
        case 11:
            printf("%d Nov %02d", nYear, nDay);
            break;
        case 12:
            printf("%d Dec %02d", nYear, nDay);
            break;
        default:
            printf("Error");
    };
}

void displayTime(){
    int nHours, nMinutes;
    int nTotalSeconds;
    
    nTotalSeconds = (int)time(NULL);
    
    nTotalSeconds += 28800; // UTC+8

    nTotalSeconds /= 60;
    nMinutes = nTotalSeconds % 60;
    nTotalSeconds /= 60;
    
    if(nTotalSeconds % 12 == 0){
        nHours = 12;
    }
    else{
        nHours = nTotalSeconds % 12;
    }

    printf("%02d:%02d", nHours, nMinutes);

    if (nTotalSeconds % 24 >= 12){
        printf(" PM");
    }
    else{
        printf(" AM");
    }
}

void displayMenu(int nMenu){
    switch(nMenu){
        case 1:
            printf("Sushi");
            break;
        case 2:
            printf("Matcha");
            break;
        case 3: 
            printf("Mochi");
            break;
    }
}

void displayAvailableTables(int nTable1, int nTable2, int nTable3, int nTable4, int nTable5,
                            int nTable6, int nTable7, int nTable8, int isEmpty){
        
    if (checkTableAvailability(nTable1) == isEmpty){
        printf("  [1] Table 1\n");
    }
    if (checkTableAvailability(nTable2) == isEmpty){
        printf("  [2] Table 2\n");
    }
    if (checkTableAvailability(nTable3) == isEmpty){
        printf("  [3] Table 3\n");
    }
    if (checkTableAvailability(nTable4) == isEmpty){
        printf("  [4] Table 4\n");
    }
    if (checkTableAvailability(nTable5) == isEmpty){
        printf("  [5] Table 5\n");
    }
    if (checkTableAvailability(nTable6) == isEmpty){
        printf("  [6] Table 6\n");
    }
    if (checkTableAvailability(nTable7) == isEmpty){
        printf("  [7] Table 7\n");
    }
    if (checkTableAvailability(nTable8) == isEmpty){
        printf("  [8] Table 8\n");
    }
}

void printOrders(int nTable, int nIndex, int nTableNumber){
    int nPower, nMenu, nWidth;

    nPower = pow(100, nIndex + 1);
    
    nTable %= nPower;
    nTable /= (nPower / 100);
    nMenu = nTable / 10 % 10;

    switch(nTableNumber){
        case 1:
        case 2:
        case 5:
        case 6:
            nWidth = 11;
            break;
        case 3:
        case 4:
            nWidth = 20;
            break;
        case 7:
        case 8:
            nWidth = 14;
            break;
    }

    if (nMenu == 0){
        printf("%*s|", nWidth + 2, " ");
    }
    else{
        switch(nMenu){
            case 1:
                printf("%7s", "-Sushi");
                nWidth -= 7;
                break;
            case 2:
                printf("%8s", "-Matcha");
                nWidth -= 8;
                break;
            case 3:
                printf("%7s", "-Mochi");
                nWidth -= 7;
                break;
        };

        printf("%*s", nWidth, "x");

        printf("%2d|", nTable % 10);
    }
}

void displayTerminal(int nDate, int nTable1, int nTable2, int nTable3, int nTable4,
                     int nTable5, int nTable6, int nTable7, int nTable8){

    printLine('-', '-');
    printf("%29s%20s", "Shichiha", "");
    displayDate(nDate);
    printf("\n");
    printLine('-', '-');

    printf("%29s%26s\n", "+----------------------+", "+----------------------+");
    printf("%14s%12s%d%s", "| Table 4", "[", getCustomer(nTable4), "]|");
    printf("%11s%12s%d%s\n", "| Table 3", "[", getCustomer(nTable3), "]|");
    printf("%29s%26s\n", "+----------------------+", "+----------------------+");
    printf("%6s", "|");
    printOrders(nTable4, 0, 4);
    printf("%3s", "|");
    printOrders(nTable3, 0, 3);
    printf("\n");
    printf("%6s", "|");
    printOrders(nTable4, 1, 4);
    printf("%3s", "|");
    printOrders(nTable3, 1, 3);
    printf("\n");
    printf("%6s", "|");
    printOrders(nTable4, 2, 4);
    printf("%3s", "|");
    printOrders(nTable3, 2, 3);
    printf("\n");
    printf("%29s%26s\n", "+----------------------+", "+----------------------+");
    
    printf("%s%24s%21s\n", "+-------------+", "+----------------+", "+-------------+");
    printf("%s%3s%d%s", "| Table 5", "[", getCustomer(nTable5), "]|");
    printf("%15s%6s%d%s", "| Table 7", "[", getCustomer(nTable7), "]|");
    printf("%15s%3s%d%s\n", "| Table 2", "[", getCustomer(nTable2), "]|");
    printf("%s%24s%21s\n", "+-------------+", "+----------------+", "+-------------+");
    printf("%s%14s", "|", "|");
    printf("%7s", "|");
    printOrders(nTable7, 0, 7);
    printf("%7s%14s\n", "|", "|");
    printf("|");
    printOrders(nTable5, 0, 5);
    printf("%7s", "|");
    printOrders(nTable7, 1, 7);
    printf("%7s", "|");
    printOrders(nTable2, 0, 2);
    printf("\n");
    printf("|");
    printOrders(nTable5, 1, 5);
    printf("%7s", "|");
    printOrders(nTable7, 2, 7);
    printf("%7s", "|");
    printOrders(nTable2, 1, 2);
    printf("\n");
    printf("|");
    printOrders(nTable5, 2, 5);
    printf("%24s", "+----------------+");
    printf("%7s", "|");
    printOrders(nTable2, 2, 2);
    printf("\n");

    printf("%s%14s%31s%14s\n", "|", "|", "|", "|");
    printf("%s%14s%24s%7s%14s\n", "|", "|", "+----------------+", "|", "|");
    printf("%s", "+-------------+");
    printf("%15s%6s%d%s", "| Table 8", "[", getCustomer(nTable8), "]|");
    printf("%21s\n", "+-------------+");
    printf("%s", "+-------------+");
    printf("%24s", "+----------------+");
    printf("%21s\n", "+-------------+");
    printf("%s%3s%d%s", "| Table 6", "[", getCustomer(nTable6), "]|");
    printf("%7s", "|");
    printOrders(nTable8, 0, 8);
    printf("%15s%3s%d%s\n", "| Table 1", "[", getCustomer(nTable1), "]|");
    printf("%s", "+-------------+");
    printf("%7s", "|");
    printOrders(nTable8, 1, 8);
    printf("%21s\n", "+-------------+");
    printf("%s%14s", "|", "|");
    printf("%7s", "|");
    printOrders(nTable8, 2, 8);
    printf("%7s%14s\n", "|", "|");
    printf("|");
    printOrders(nTable6, 0, 6);
    printf("%24s", "+----------------+");
    printf("%7s", "|");
    printOrders(nTable1, 0, 1);
    printf("\n");
    printf("|");
    printOrders(nTable6, 1, 6);
    printf("%31s", "|");
    printOrders(nTable1, 1, 1);
    printf("\n");
    printf("|");
    printOrders(nTable6, 2, 6);
    printf("%26s", "+--------------------+");
    printf("%5s", "|");
    printOrders(nTable1, 2, 1);
    printf("\n");
    printf("%s%14s%5s%13s%8s%5s%14s\n", "|", "|", "|", "COUNTER", "|", "|", "|");
    printf("%s%26s%19s\n", "+-------------+", "+--------------------+", "+-------------+");
}

void displayUpdateOrderScreen(int *pTable1, int *pTable2, int *pTable3, int *pTable4, int *pTable5,
                              int *pTable6, int *pTable7, int *pTable8, int *pStoreMenuItems){
    
    int nPower, nTable, nAvailable, isEmpty;

    nAvailable = generateAvailabilityBinary(*pTable1, *pTable2, *pTable3, *pTable4, 
                                            *pTable5, *pTable6, *pTable7, *pTable8);                            

    printLine('-', '-');
    printf("%36s\n", "UPDATE ORDER");
    printLine('-', '-');
    printf("Choose a table:\n");

    displayAvailableTables(*pTable1, *pTable2, *pTable3, *pTable4, *pTable5, 
                           *pTable6, *pTable7, *pTable8, 0);
    printf("Table: ");
    scanf("%d", &nTable);

    if (nTable >= 1 && nTable <= 8){
        nPower = pow(10, nTable - 1);
        isEmpty = nAvailable / nPower % 10;
            
        if (!isEmpty){
            switch(nTable){
                case 1:
                    updateTableOrder(pTable1, pStoreMenuItems);
                    break;
                case 2:
                    updateTableOrder(pTable2, pStoreMenuItems);
                    break;
                case 3:
                    updateTableOrder(pTable3, pStoreMenuItems);
                    break;
                case 4:
                    updateTableOrder(pTable4, pStoreMenuItems);
                    break;
                case 5:
                    updateTableOrder(pTable5, pStoreMenuItems);
                    break;
                case 6:
                    updateTableOrder(pTable6, pStoreMenuItems);
                    break;
                case 7:
                    updateTableOrder(pTable7, pStoreMenuItems);
                    break;
                case 8:
                    updateTableOrder(pTable8, pStoreMenuItems);
                    break;
            }
        }
        else{
            printf("There are no customers seated at that table.\n");
        }
    }
    else{
        printf("Please enter a valid input.\n");
    }
}

void displayReceipt(float fCash, int nTable, int nDate, int nTableNum, int *pCount, int *pCustomers,
                    int *pSushiSold, int *pMatchaSold, int *pMochiSold,
                    float fSushiPrice, float fMatchaPrice, float fMochiPrice, float *pTotalEarnings){
    int tmpTable, nQuantity, nItems, nMenu;
    float fTotal, fChange, fNet, fVATAmount;
    const float VAT = 0.12;
    
    nItems = 0;
    fTotal = 0;
    tmpTable = nTable;

    printLine(' ', '^');    
    printf("%s%40s%19s\n", "|", "Thank you for dining at", "|");
    printf("%s%45s%14s\n", "|", "Shichiha Sushi and Dessert House", "|");
    printf("%s%44s%15s\n", "|", "G/F Capernaum Mall Gen Luna Ave", "|");
    printf("%s%49s%10s\n", "|", "Orchard Fields Binondo City of Manila NCR", "|");
    printf("%s%59s\n", "|", "|");

    printf("| ");
    displayDate(nDate);
    printf("\t");
    displayTime();
    printf("%36s\n", "|");
    printf("| Inv No.: %08d%41s\n", *pCount, "|");
    printf("| Table: %d%50s\n", nTableNum, "|");
    printLine('|', '=');
    
    printf("%s%14s%14s%12s%16s%3s\n", "|", "ITEM", "PRICE", "QTY", "AMOUNT", "|");
    
    while (tmpTable > 5){
        printf("|");
        nQuantity = tmpTable % 10;
        tmpTable /= 10;
        nMenu = tmpTable % 10;
		tmpTable /= 10;

        switch(nMenu){
            case 1:
                printf("%14s", "Sushi");
                printf("%14.2f", fSushiPrice);
                printf("%12d", nQuantity);
                printf("%16.2f  |\n", nQuantity * fSushiPrice);
                *pSushiSold += nQuantity;
                fTotal += nQuantity * fSushiPrice;
                break;
            case 2:
                printf("%14s", "Matcha");
                printf("%14.2f", fMatchaPrice);
                printf("%12d", nQuantity);
                printf("%16.2f  |\n", nQuantity * fMatchaPrice);
                *pMatchaSold += nQuantity;
                fTotal += nQuantity * fMatchaPrice;
                break;
            case 3:
                printf("%14s", "Mochi");
                printf("%14.2f", fMochiPrice);
                printf("%12d", nQuantity);
                printf("%16.2f  |\n", nQuantity * fMochiPrice);
                *pMochiSold += nQuantity;
                fTotal += nQuantity * fMochiPrice;
                break;
        }
        nItems += nQuantity;
    }
    *pTotalEarnings += fTotal;
    *pCustomers += tmpTable;

    printLine('|', '-');
    fChange = fCash - fTotal;

    printf("%s%46.2f%3s\n", "| Total Php", fTotal, "|");
    printf("%s%51.2f%3s\n", "| Cash", fCash, "|");
    printf("%s%49.2f%3s\n", "| CHANGE", fChange, "|");
    printf("%s%39d%3s\n", "| Number of Items:", nItems, "|");

    printLine('|', '-');
    fNet = fTotal / (1 + VAT);
    fVATAmount = fTotal - fNet;
   
    printf("%s%28s%12s%16s%3s\n", "|", "Net Amount", "VAT", "AMOUNT", "|");
    printf("%s%20.2f%12.2f%16.2f%3s\n", "| VATABLE", fNet, fVATAmount, fTotal, "|");
    printf("%s%21.2f%12.2f%16.2f%3s\n", "| EXEMPT", 0.00, 0.00, 0.00, "|");
    printf("%s%21.2f%12.2f%16.2f%3s\n", "| ZERO-R", 0.00, 0.00, 0.00, "|");
    printf("%s%42s%17s\n", "|", "THIS SERVES AS YOUR INVOICE", "|");
    printLine(' ', '^');

    printf("Present receipt [ENTER] ");
    getchar();
    getchar();
}

void displayWarnings(int nStoreMenuItems){
    if (!countMenuStocks(1, nStoreMenuItems) || !countMenuStocks(2, nStoreMenuItems) || !countMenuStocks(3, nStoreMenuItems)){
        printf("WARNING! We have ran out of stocks on the following:\n");
        if (!countMenuStocks(1, nStoreMenuItems)){
            printf("  - Sushi\n");
        }
        if (!countMenuStocks(2, nStoreMenuItems)){
            printf("  - Matcha\n");
        }
        if (!countMenuStocks(3, nStoreMenuItems)){
            printf("  - Mochi\n");
        }
    }
}