#include <stdio.h> //Includes the standard input/output library
#include <stdlib.h> //Includes the standard library for memory allocation

//Define the structure for an integer node
typedef struct IntNode_struct {
   int dataVal; //Integer data value of the node
   struct IntNode_struct* nextNodePtr; //Pointer to the next node in the list
} IntNode;

// Constructor (Function to create a node)
void IntNode_Create
(IntNode* thisNode, int dataInit, IntNode* nextLoc) {
   thisNode->dataVal = dataInit; //Initialize the node's data value
   thisNode->nextNodePtr = nextLoc; // Set the next node pointer
}

//Function to insert a new node after the current node
/* Insert newNode after node.
 Before: thisNode --points to  next
 After:  thisNode --points to  newNode which points to -- next
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