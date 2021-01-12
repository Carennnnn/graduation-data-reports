#include "defs.h"

/*
  Function: freeMemory()
  Purpose: free all dynamically allocated memory
  in: linkedlist with all data, likedlist to be stored for report 1 data,
  likedlist to be stored for report 2 data, likedlist to be stored for report 3 data,
  out: deallocate memory
*/
void freeMemory(ListType *list, R1ListType *list1, R2ListType *list2, R3ListType *list3){
  NodeType *currNode;
  NodeType *nextNode;

  currNode = list -> head;
  while(currNode != NULL){

    free(currNode -> data);
    free(currNode);
    nextNode = currNode -> next;
    currNode = nextNode;
  }
  free(list);

  R1NodeType *currNode1;
  R1NodeType *nextNode1;

  currNode1 = list1 -> head;
  while(currNode1 != NULL){
    free(currNode1 -> data);
    free(currNode1);
    nextNode1 = currNode1 -> next;
    currNode1 = nextNode1;
  }
  free(list1);

  R2NodeType *currNode2;
  R2NodeType *nextNode2;

  currNode2 = list2 -> head;
  while(currNode2 != NULL){
    free(currNode2 -> data);
    free(currNode2);
    nextNode2 = currNode2 -> next;
    currNode2 = nextNode2;
  }
  free(list2);

  R3NodeType *currNode3;
  R3NodeType *nextNode3;

  currNode3 = list3 -> head;
  while(currNode3 != NULL){
    free(currNode3 -> data);
    free(currNode3);
    nextNode3 = currNode3 -> next;
    currNode3 = nextNode3;
  }
  free(list3);


}

