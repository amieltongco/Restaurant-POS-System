#include "display.h"
#include "billOut.h"
#include "table.h"


void printBill(int nTable, int nDate, int nTableNum, int *pCount, int *pCustomers,
               int *pSushiSold, int *pMatchaSold, int *pMochiSold,
               float fSushiPrice, float fMatchaPrice, float fMochiPrice,
               float *pTotalEarnings){
    int fCash, nMenu, nQuantity, tmpTable;
    float fGrandTotal = 0;
    tmpTable = nTable;

    (*pCount)++;

    printLine(' ', '^');  
    printf("%s%40s%19s\n", "|", "Thank you for dining at", "|");
    printf("%s%45s%14s\n", "|", "Shichiha Sushi and Dessert House", "|");
    printf("%s%44s%15s\n", "|", "G/F Capernaum Mall Gen Luna Ave", "|");
    printf("%s%49s%10s\n", "|", "Orchard Fields Binondo City of Manila NCR", "|");
    printLine('+', '-');
    printf("%s%15s%20s%22s%2s\n", "|", "QTY", "ITEM", "PRICE", "|");

    while (tmpTable > 5){
        printf("|");
        nQuantity = tmpTable % 10;
        tmpTable /= 10;
        nMenu = tmpTable % 10;
		tmpTable /= 10;

        switch(nMenu){
            case 1:
                printf("%15d", nQuantity);
                printf("%20s", "Sushi");
                printf("%22.2f |\n", nQuantity * fSushiPrice);
                fGrandTotal += nQuantity * fSushiPrice;
                break;
            case 2:
                printf("%15d", nQuantity);
                printf("%20s", "Matcha");
                printf("%22.2f |\n", nQuantity * fMatchaPrice);
                fGrandTotal += nQuantity * fMatchaPrice;
                break;
            case 3:
                printf("%15d", nQuantity);
                printf("%20s", "Mochi");
                printf("%22.2f |\n", nQuantity * fMochiPrice);
                fGrandTotal += nQuantity * fMochiPrice;
                break;
        }
    }
    printf("%s%59s\n", "|", "------------ |");
    printf("%s%40s%17.2f%2s\n", "|", "GRAND TOTAL", fGrandTotal, "|");
    printLine(' ', '^'); 
    
	do {
		printf("Cash rendered: ");
		scanf("%d", &fCash);
		
		if (fCash >= fGrandTotal){
			displayReceipt(fCash, nTable, nDate, nTableNum, pCount, pCustomers,
                           pSushiSold, pMatchaSold, pMochiSold, 
                           fSushiPrice, fMatchaPrice, fMochiPrice, pTotalEarnings);
		}
		else{
			printf("Insufficient amount!\n");
		}
	} while (fCash < fGrandTotal);
}

void billOut(int *pTable1, int *pTable2, int *pTable3, int *pTable4, int *pTable5, int *pTable6, 
             int *pTable7, int *pTable8, int *pStoreMenuItems, int *pSushiSold, int *pMatchaSold, 
             int *pMochiSold, int *pCount, int *pCustomers, int nDate, float fSushiPrice, 
             float fMatchaPrice, float fMochiPrice, float *pTotalEarnings){
    int nChoice, nTableNum, nMenu, nQuantity, nPower, nIsEmpty, nAvailable, tmpTable;
    
    printLine('-', '-');
    printf("%33s\n", "BILL OUT");
    printLine('-', '-');
    
    nAvailable = generateAvailabilityBinary(*pTable1, *pTable2, *pTable3, *pTable4, 
                                            *pTable5, *pTable6, *pTable7, *pTable8);

    displayAvailableTables(*pTable1, *pTable2, *pTable3, *pTable4, *pTable5, 
                           *pTable6, *pTable7, *pTable8, 0);
    printf("Table: ");
    scanf("%d", &nTableNum);

    if (nTableNum >= 1 && nTableNum <= 8){
        nPower = pow(10, nTableNum - 1);
        nIsEmpty = nAvailable / nPower % 10;

        if (!nIsEmpty){
            switch(nTableNum){
                case 1:
                    tmpTable = *pTable1;
                    break;
                case 2:
                    tmpTable = *pTable2;
                    break;
                case 3:
                    tmpTable = *pTable3;
                    break;
                case 4:
                    tmpTable = *pTable4;
                    break;
                case 5:
                    tmpTable = *pTable5;
                    break;
                case 6:
                    tmpTable = *pTable6;
                    break;
                case 7:
                    tmpTable = *pTable7;
                    break;
                case 8:
                    tmpTable = *pTable8;
                    break;
            }
            if (tmpTable > 5){
                printf("Table's Orders:\n");
                printf("%8s%12s\n", "Item", "Qty");

                while (tmpTable > 5){
                    nQuantity = tmpTable % 10;
                    tmpTable /= 10;
                    nMenu = tmpTable % 10;
                    tmpTable /= 10;

                    switch(nMenu){
                        case 1:
                            printf("%8s", "Sushi");
                            printf("%12d\n", nQuantity);
                            break;
                        case 2:
                            printf("%8s", "Matcha");
                            printf("%12d\n", nQuantity);
                            break;
                        case 3:
                            printf("%8s", "Mochi");
                            printf("%12d\n", nQuantity);
                            break;
                    }
                }
                do {
                    printf("  [1] Print Bill\n");
                    printf("  [2] Exit\n");
                    printf("Choice: ");
                    scanf("%d", &nChoice);
                } while(nChoice < 1 || nChoice > 2);
                
                if (nChoice == 1){
                    switch(nTableNum){
                        case 1:
                            tmpTable = *pTable1;
                            *pTable1 = 0;
                            break;
                        case 2:
                            tmpTable = *pTable2;
                            *pTable2 = 0;
                            break;
                        case 3:
                            tmpTable = *pTable3;
                            *pTable3 = 0;
                            break;
                        case 4:
                            tmpTable = *pTable4;
                            *pTable4 = 0;
                            break;
                        case 5:
                            tmpTable = *pTable5;
                            *pTable5 = 0;
                            break;
                        case 6:
                            tmpTable = *pTable6;
                            *pTable6 = 0;
                            break;
                        case 7:
                            tmpTable = *pTable7;
                            *pTable7 = 0;
                            break;
                        case 8:
                            tmpTable = *pTable8;
                            *pTable8 = 0;
                            break;
                    }
                    printBill(tmpTable, nDate, nTableNum, pCount, pCustomers,
                            pSushiSold, pMatchaSold, pMochiSold, 
                            fSushiPrice, fMatchaPrice, fMochiPrice, 
                            pTotalEarnings);
                }
            }
            else{
                printf("That table does not have any orders yet!\n");
            }
        }
        else{
            printf("Choose an occupied table.\n");
        }
    }
    else{
        printf("Please enter a valid input.\n");
    }
}