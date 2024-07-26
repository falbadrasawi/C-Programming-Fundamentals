#ifndef STOREITEM_H
#define STOREITEM_H

typedef struct StoreItem_struct {
    int weightOunces;
    //Other fields omitted fro brevity
} StoreItem;

void StoreItemSetWeightOunces(StoreItem* storeItem, int weightOunces);
void StoreItemPrint(StoreItem storeItem);

#endif
