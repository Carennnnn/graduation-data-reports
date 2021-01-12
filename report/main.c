#include "defs.h"

int main(){

  ListType *gradRecord;
  initAllRecord(&gradRecord);

  R1ListType *report1;
  R2ListType *report2;
  R3ListType *report3;

  int choice;

  int flag = -1;
  while(flag != 0){
    printMenu(&choice);

    switch (choice){
      case 1:
        reportOne(gradRecord, &report1);
        break;

      case 2:
        reportTwo(gradRecord, &report2);
        break;

      case 3:
        reportThree(gradRecord, &report3);
        break;

      case 0:
        flag = 0;
        freeMemory(gradRecord, report1, report2, report3);
        exit(0);

      default:
        printf("Please enter a valide number: ");
        scanf("%d", &choice);

    }
  }

  return 0;
}
