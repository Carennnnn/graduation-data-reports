#include "defs.h"

/*
  Function: printMenu()
  Purpose: to print menu to the user for selection report
  in: choice pointer to store the choice of users'
  out: print menu to the users
*/
void printMenu(int *choice){
  printf("\nWhich record would you like to see?(Please enter a number)\n\n");
  printf("(1)The graduate percentage for each country by degree\n");
  printf("(2)The top 5 and bottom 5 countries for percentage of female graduates\n");
  printf("(3)The graduate percentage for each country by year from 2014 to 2017\n");
  printf("(0)Exit program\n\n");
  printf("Please enter your choice: ");
  scanf("%d", choice);
}

/*
  Function: printReport1List()
  Purpose: to print report 1 to the user
  in: linkedlist to be printed, number of bachelors globally, nunmber of masters globally,
  	nunmber of doctors globally, number of all graduates globally
  out: print report 1 to the user
*/
void printReport1List(R1ListType *list, int allBach, int allMas, int allDoc, int allGrad){
  printf("\n%s", "Report 1: The graduate percentage for each country\n\n");
  printf("%-15s %12s %12s %13s %17s\n","Country", "Bachelor's", "Master's", "Doctorate", "All Graduates'");
  printf("-------------------------------------------------------------------------\n");

  R1NodeType *currNode = list->head;
  R1NodeType *prevNode = NULL;

  float bachPercent = 0;
  float masPercent = 0;
  float docPercent = 0;
  float allPercent = 0;

  while(currNode != NULL){
    bachPercent = 100*((float)(currNode->data->numBach) / (float)allBach);
    masPercent = 100*((float)(currNode->data->numMas) / (float)allMas);
    docPercent = 100*((float)(currNode->data->numDoc) / (float)allDoc);
    allPercent = 100*((float)(currNode->data->numGrads) / (float)allGrad);

    printf("%-17s %-14.2f %-12.2f %-12.2f %-12.2f\n", currNode->data->countryName, bachPercent, masPercent, docPercent,allPercent);
    prevNode = currNode;
    currNode = currNode -> next;
  }

}

/*
  Function: printReport2List()
  Purpose: to print report 2 to the user
  in: linkedlist to be printed
  out: print report 2 to the user
*/
void printReport2List(R2ListType *list){
  R2NodeType *currNode = list->head;
  R2NodeType *prevNode = NULL;

  float currPercent = 0;
  int index = 0;

  while(currNode != NULL){
    if(index<5){
      if(index == 0){
        printf("\nReport 2:\n");
        printf("\nBottom 5 countries for percentage of female graduate\n\n");
        printf("%-17s %s", "Country", "Female Gradutes'\n");
        printf("----------------------------------------\n");
      }
      currPercent = 100*((float)(currNode->data->numFemale) / (float)(currNode->data->numGrads));
      printf("%-17s %-14.2f\n", currNode->data->countryName, currPercent);

    }
    else if(index > 33){
      if(index == 34){
        printf("\nTop 5 countries for percentage of female graduate\n\n");
        printf("%-17s %s", "Country", "Female Gradutes'\n");
        printf("----------------------------------------\n");

      }
      currPercent = 100*((float)(currNode->data->numFemale) / (float)(currNode->data->numGrads));
      printf("%-17s %-14.2f\n", currNode->data->countryName, currPercent);
    }
    prevNode = currNode;
    currNode = currNode -> next;
    index++;
  }


}


/*
  Function: printReport3List()
  Purpose: to print report 3 to the user
  in: linkedlist to be printed, number of all graduates in 2014, number of all graduates in 2015,
  	number of all graduates in 2016, number of all graduates in 2017
  out: print report 3 to the user
*/
 void printReport3List(R3ListType *list, int all2014, int all2015, int all2016, int all2017){
    printf("\n%s", "Report 3: The graduate percentage for each country from 2014 to 2017\n\n");
    printf("%-9s %12s %14s %12s %12s\n","Country", "2014", "2015", "2016", "2017");
    printf("---------------------------------------------------------------------\n");


    R3NodeType *currNode = list->head;
    R3NodeType *prevNode = NULL;

    float percent14 = 0;
    float percent15 = 0;
    float percent16 = 0;
    float percent17 = 0;

    while(currNode != NULL){
      percent14 = 100*((float)(currNode->data->num2014) / (float)all2014);
      percent15 = 100*((float)(currNode->data->num2015) / (float)all2015);
      percent16 = 100*((float)(currNode->data->num2016) / (float)all2016);
      percent17 = 100*((float)(currNode->data->num2017) / (float)all2017);

      printf("%-17s %-14.2f %-12.2f %-12.2f %-12.2f\n", currNode->data->countryName, percent14, percent15, percent16, percent17);
      prevNode = currNode;
      currNode = currNode -> next;
    }

  }
