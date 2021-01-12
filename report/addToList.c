#include "defs.h"

/*
  Function: addRecordToList()
  Purpose: add a node to the linkedlist
  in: linkedlist with all data, node to be added
  out: node added by country name
*/
void addRecordToList(ListType **list, DataType **d){
  NodeType *currNode;
  NodeType *prevNode;
  NodeType *newNode;

  currNode = (*list)->head;
  prevNode = NULL;

  while(currNode != NULL){
    if(strcmp((*d)->countryCode, currNode->data->countryCode) < 0){
      break;
    }
    prevNode = currNode;
    currNode = currNode -> next;
  }

  newNode = malloc(sizeof(NodeType));
  newNode->data = (*d);
  newNode->next = NULL;

  if(prevNode == NULL){
    (*list)->head = newNode;
  }else{
    prevNode -> next = newNode;
  }
  newNode -> next = currNode;

}

/*
  Function: addReport1ToList()
  Purpose: add a node to report1 linkedlist
  in: linkedlist with report 1 data, node to be added
  out: node added by country name
*/
void addReport1ToList(R1ListType **list, R1Type **d){
  R1NodeType *currNode;
  R1NodeType *prevNode;
  R1NodeType *newNode;

  currNode = (*list)->head;
  prevNode = NULL;

  while(currNode != NULL){
    if(strcmp((*d)->countryName, currNode->data->countryName) < 0){
      break;
    }
    prevNode = currNode;
    currNode = currNode -> next;
  }

  newNode = malloc(sizeof(R1NodeType));
  newNode->data = (*d);
  newNode->next = NULL;

  if(prevNode == NULL){
    (*list)->head = newNode;
  }else{
    prevNode -> next = newNode;
  }
  newNode -> next = currNode;

}


/*
  Function: addReport2ToList()
  Purpose: add a node to report 2 linkedlist
  in: linkedlist with report 2 data, node to be added
  out: node added by percentage of female to all graduates
*/
void addReport2ToList(R2ListType **list, R2Type **d){
  R2NodeType *currNode;
  R2NodeType *prevNode;
  R2NodeType *newNode;

  currNode = (*list)->head;
  prevNode = NULL;

  float currPercent = 0;
  float prevPercent = 0;

  while(currNode != NULL){
    prevPercent = (float)currNode->data->numFemale / (float)currNode->data->numGrads;
    currPercent = (float)(*d)->numFemale / (float)(*d)->numGrads;
    if(currPercent < prevPercent){
      break;
    }
    prevNode = currNode;
    currNode = currNode -> next;
  }

  newNode = malloc(sizeof(R2NodeType));
  newNode->data = (*d);
  newNode->next = NULL;

  if(prevNode == NULL){
    (*list)->head = newNode;
  }else{
    prevNode -> next = newNode;
  }
  newNode -> next = currNode;

}

/*
  Function: addReport3ToList()
  Purpose: add a node to report 3 linkedlist
  in: linkedlist with report 3 data, node to be added
  out: node added by country name
*/
void addReport3ToList(R3ListType **list, R3Type **d){
  R3NodeType *currNode;
  R3NodeType *prevNode;
  R3NodeType *newNode;

  currNode = (*list)->head;
  prevNode = NULL;

  while(currNode != NULL){
    if(strcmp((*d)->countryName, currNode->data->countryName) < 0){
      break;
    }
    prevNode = currNode;
    currNode = currNode -> next;
  }

  newNode = malloc(sizeof(R3NodeType));
  newNode->data = (*d);
  newNode->next = NULL;

  if(prevNode == NULL){
    (*list)->head = newNode;
  }else{
    prevNode -> next = newNode;
  }
  newNode -> next = currNode;

}
