#include "defs.h"

/*
  Function: reportOne()
  Purpose: store report 1 to the linkedlist and print it
  in: linkedlist with all data, likedlist to be stored for report 1 data
  out: initialize linkedlist and print it for report 1
*/
void reportOne(ListType *list,R1ListType **report1){
  NodeType *currNode = list->head;
  NodeType *prevNode = NULL;
  char countryName[MAX_STR];
  char degree[MAX_STR];
  R1Type *d;
  int numBach = 0;
  int numMas = 0;
  int numDoc = 0;
  int numGrads = 0;
  (*report1) = malloc(sizeof(R1ListType));
  (*report1) -> head = NULL;


  while(currNode != NULL){
    if(prevNode == NULL){
      strcpy(countryName, currNode->data->countryName);
      strcpy(degree, currNode->data->degree);
    }
    else{
 
      if(strcmp(currNode->data->countryName, countryName) == 0){
       
        if(strcmp(degree, currNode->data->degree) == 0){
        
          if(strcmp("T", currNode->data->gender) == 0){
           
            if(strcmp(degree, "L6") == 0){
              numBach += currNode->data->numGrads;
            }else if(strcmp(degree, "L7") == 0){
              numMas += currNode->data->numGrads;
            }else if(strcmp(degree, "L8") == 0){
              numDoc += currNode->data->numGrads;
            }
            numGrads += currNode->data->numGrads;
          }
        }
     
        else{
          strcpy(degree,currNode->data->degree);
          if(strcmp("T", currNode->data->gender) == 0){
           
            if(strcmp(degree, "L6") == 0){
              numBach += currNode->data->numGrads;
            }else if(strcmp(degree, "L7") == 0){
              numMas += currNode->data->numGrads;
            }else if(strcmp(degree, "L8") == 0){
              numDoc += currNode->data->numGrads;
            }
            numGrads += currNode->data->numGrads;
          }
        }
      }
      
      else{
        initReport1Row(countryName, numBach, numMas, numDoc, numGrads, &d);
        addReport1ToList(report1, &d);
        strcpy(countryName, currNode->data->countryName);
        strcpy(degree,currNode->data->degree);
        numBach = 0;
        numMas = 0;
        numDoc = 0;
        numGrads = 0;

        if(strcmp("T", currNode->data->gender) == 0){
          
          if(strcmp(degree, "L6") == 0){
            numBach += currNode->data->numGrads;
          }else if(strcmp(degree, "L7") == 0){
            numMas += currNode->data->numGrads;
          }else if(strcmp(degree, "L8") == 0){
            numDoc += currNode->data->numGrads;
          }
          numGrads += currNode->data->numGrads;
        }

      }
    }
    prevNode = currNode;
    currNode = currNode -> next;
  }
 
  initReport1Row(countryName, numBach, numMas, numDoc, numGrads, &d);
  addReport1ToList(report1, &d);

  R1NodeType *curNode = (*report1)->head;
  R1NodeType *preNode = NULL;

  int allBach = 0;
  int allMas = 0;
  int allDoc = 0;
  int allGrad = 0;

  while(curNode != NULL){
    allBach += curNode->data->numBach;
    allMas += curNode->data->numMas;
    allDoc += curNode->data->numDoc;
    allGrad += curNode->data->numGrads;
    curNode = curNode -> next;
  }

  printReport1List(*report1, allBach, allMas, allDoc, allGrad);

}


/*
  Function: reportTwo()
  Purpose: store report 2 to the linkedlist and print it
  in: linkedlist with all data, likedlist to be stored for report 2 data
  out: initialize linkedlist and print it for report 2
*/

void reportTwo(ListType *list, R2ListType **report2){
  NodeType *currNode = list->head;
  NodeType *prevNode = NULL;
  R2Type *d;
  (*report2) = malloc(sizeof(R2ListType));
  (*report2) -> head = NULL;

  char countryName[MAX_STR];
  int numFemale = 0;
  int numGrads = 0;

  while(currNode != NULL){
   
    if(prevNode == NULL){
      strcpy(countryName, currNode->data->countryName);
      
        if(strcmp("T", currNode->data->gender) == 0){
          numGrads += currNode->data->numGrads;
        }
        else if(strcmp("F", currNode->data->gender) == 0){
          numFemale += currNode->data->numGrads;
        }
    }
    
    else{
     
      if(strcmp(currNode->data->countryName, countryName) == 0){
        if(strcmp("Russia", countryName)==0 && currNode->data->year == 2010){

        }else if(strcmp("Russia", countryName)==0 && strcmp("L8", currNode->data->degree)==0){

        }
        else if(strcmp("T", currNode->data->gender) == 0){
          numGrads += currNode->data->numGrads;
        }
        else if(strcmp("F", currNode->data->gender) == 0){
          numFemale += currNode->data->numGrads;
        }
      }
      else{
        initReport2Row(countryName, numFemale, numGrads, &d);
        addReport2ToList(report2, &d);
        strcpy(countryName, currNode->data->countryName);
        numFemale = 0;
        numGrads = 0;
        if(strcmp("T", currNode->data->gender) == 0){
          numGrads += currNode->data->numGrads;
        }
        else if(strcmp("F", currNode->data->gender) == 0){
          numFemale += currNode->data->numGrads;
        }
      }

    }
    prevNode = currNode;
    currNode = currNode -> next;
  }
  
  initReport2Row(countryName, numFemale, numGrads, &d);
  addReport2ToList(report2, &d);
  printReport2List(*report2);

}



/*
  Function: reportThree()
  Purpose: store report 3 to the linkedlist and print it
  in: linkedlist with all data, likedlist to be stored for report 3 data
  out: initialize linkedlist and print it for report 3
*/

void reportThree(ListType *list,R3ListType **report3){
  NodeType *currNode = list->head;
  NodeType *prevNode = NULL;
  char countryName[MAX_STR];
  R3Type *d;
  int num2014 = 0;
  int num2015= 0;
  int num2016= 0;
  int num2017 = 0;
  int year;
  (*report3) = malloc(sizeof(R3ListType));
  (*report3) -> head = NULL;

  while(currNode != NULL){
    
    if(prevNode == NULL){
      strcpy(countryName, currNode->data->countryName);
      year = currNode->data->year;
    }
    else{
     
      if(strcmp(currNode->data->countryName, countryName) == 0){
       
        if(year == currNode->data->year){
        
          if(strcmp("T", currNode->data->gender) == 0){
           
            if(year == 2014){
              num2014 += currNode->data->numGrads;
            }else if(year == 2015){
              num2015 += currNode->data->numGrads;
            }else if(year == 2016){
              num2016 += currNode->data->numGrads;
            }else if(year == 2017){
              num2017 += currNode->data->numGrads;
            }
          }
        }else{
          year = currNode->data->year;
          if(strcmp("T", currNode->data->gender) == 0){
           
            if(year == 2014){
              num2014 += currNode->data->numGrads;
            }else if(year == 2015){
              num2015 += currNode->data->numGrads;
            }else if(year == 2016){
              num2016 += currNode->data->numGrads;
            }else if(year == 2017){
              num2017 += currNode->data->numGrads;
            }
          }
        }
      }
      else{
        initReport3Row(countryName, num2014, num2015, num2016, num2017, &d);
        addReport3ToList(report3, &d);
        strcpy(countryName, currNode->data->countryName);
        year = currNode->data->year;
        num2014 = 0;
        num2015= 0;
        num2016= 0;
        num2017 = 0;

        if(strcmp("T", currNode->data->gender) == 0){
         
          if(year == 2014){
            num2014 += currNode->data->numGrads;
          }else if(year == 2015){
            num2015 += currNode->data->numGrads;
          }else if(year == 2016){
            num2016 += currNode->data->numGrads;
          }else if(year == 2017){
            num2017 += currNode->data->numGrads;
          }
        }
      }
    }
    prevNode = currNode;
    currNode = currNode -> next;
  }
  initReport3Row(countryName, num2014, num2015, num2016, num2017, &d);
  addReport3ToList(report3, &d);

  R3NodeType *curNode = (*report3)->head;
  R3NodeType *preNode = NULL;

  int all2014 = 0;
  int all2015 = 0;
  int all2016 = 0;
  int all2017 = 0;

  while(curNode != NULL){
    all2014 += curNode->data->num2014;
    all2015 += curNode->data->num2015;
    all2016 += curNode->data->num2016;
    all2017 += curNode->data->num2017;
    curNode = curNode -> next;
  }

  printReport3List(*report3, all2014, all2015, all2016, all2017);

}
