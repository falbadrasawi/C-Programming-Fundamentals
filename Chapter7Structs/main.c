#include <stdio.h>
#include "StoreItem.h"

int main() {
    StoreItem item1;

    StoreItemSetWeightOunces(&item1,16);
    StoreItemPrint(item1);    

    return 0;
}