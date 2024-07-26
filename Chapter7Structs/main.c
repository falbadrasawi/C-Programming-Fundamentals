#include <stdio.h>
#include "StoreItem.h"
#include "StoreItem.c"

int main() {
    StoreItem item1;

    StoreItemSetWeightOunces(&item1,16);
    StoreItemPrint(item1);    

    return 0;
}