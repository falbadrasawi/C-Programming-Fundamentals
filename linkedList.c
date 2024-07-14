
#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
   int dataVal;
   struct IntNode_struct* nextNodePtr;
} IntNode;

// Constructor
void IntNode_Create
(IntNode* thisNode, int dataInit, IntNode* nextLoc) {
   thisNode->dataVal = dataInit;
   thisNode->nextNodePtr = nextLoc;
}

/* Insert newNode after node.
 Before: thisNode -- next
 After:  thisNode -- newNode -- next
 */
void IntNode_InsertAfter
(IntNode* thisNode, IntNode* newNode) {
   IntNode* tmpNext = NULL;
   
   tmpNext = thisNode->nextNodePtr; // Remember next
   thisNode->nextNodePtr = newNode;// this -- new -- ?
   newNode->nextNodePtr = tmpNext; // this -- new -- next
}

// Print dataVal
void IntNode_PrintNodeData(IntNode* thisNode) {
   printf("%d\n", thisNode->dataVal);
}

// Grab location pointed by nextNodePtr
IntNode* IntNode_GetNext(IntNode* thisNode) {
   return thisNode->nextNodePtr;
}

int main(void) {
   IntNode* headObj  = NULL; // Create intNode objects
   IntNode* currObj  = NULL;
   IntNode* lastObj  = NULL;
   int i;                    // Loop index
   
   headObj = (IntNode*)malloc(sizeof(IntNode)); // Front of nodes list
   IntNode_Create(headObj, -1, NULL);
   lastObj = headObj;
   
   for (i = 0; i < 20; ++i) {                       // Append 20 rand nums
      currObj = (IntNode*)malloc(sizeof(IntNode));
      IntNode_Create(currObj, rand(), NULL);
      
      IntNode_InsertAfter(lastObj, currObj);    // Append curr
      lastObj = currObj;                        // Curr is the new last item
   }
   
   
   currObj = headObj;                           // Print the list
   
   while (currObj != NULL) {
      IntNode_PrintNodeData(currObj);
      currObj = IntNode_GetNext(currObj);
   }
   
   return 0;
}