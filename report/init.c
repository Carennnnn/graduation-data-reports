#include "defs.h"
/*
  Function: initAllRecord()
  Purpose: initialize the linkedlist for all record in grad.dat
  in: linkedlist to be initialized
  out: read file and store data in the linkedlist
*/
void initAllRecord(ListType **list){
  FILE *f;
  DataType *d;

  char countryCode[MAX_STR];
  char countryName[MAX_STR];
  char gender[MAX_STR];
  char degree[MAX_STR];
  int year;
  int numGrads;

  (*list) = malloc(sizeof(ListType));
  (*list) -> head = NULL;


  f = fopen("grad.dat", "r");
  if(!f){
    printf("Error: could not open file\n");
    exit(1);
  }

  while(1){

    fscanf(f, "%s %s %s %s %d %d", countryCode, countryName, gender, degree, &year, &numGrads);

    if(feof(f)){
      break;
    }

    initRecord(countryCode, countryName, gender, degree, year, numGrads, &d);
    addRecordToList(list, &d);  

  }

  fclose(f);
}

/*
  Function: initRecord()
  Purpose: initialize the data type for a node
  in: country code, country name, gender, degree, year, number of graduates, datatype d
  out: initialize a record for a node
*/
void initRecord(char *code, char *name, char *gender, char *degree, int year, int numGrads, DataType **d){
  *d = (DataType *) malloc(sizeof(DataType));
  strcpy((*d)->countryCode, code);
  strcpy((*d)->countryName, name);
  strcpy((*d)->gender, gender);
  strcpy((*d)->degree, degree);
  (*d) -> year = year;
  (*d) -> numGrads = numGrads;
}

/*
  Function: initReport1Row()
  Purpose: initialize one row of data for report 1
  in: country name, number of bachelor, number of masters, number of doctors,
   number of graduates for that specific degree in that country,datatype d
  out: initialize data needed for one row of linkedlist
*/
void initReport1Row(char *name, int numBach, int numMas, int numDoc, int numGrads, R1Type **d){
  *d = (R1Type *) malloc(sizeof(R1Type));
  strcpy((*d)->countryName, name);
  (*d) -> numBach = numBach;
  (*d) -> numMas = numMas;
  (*d) -> numDoc = numDoc;
  (*d) -> numGrads = numGrads;
}

/*
  Function: initReport2Row()
  Purpose: initialize one row of data for report 2
  in: country name, number of female, number of graduates for all year and all degrees in
  a country, report 2 datatype d
  out: initialize data needed for one row of linkedlist
*/
void initReport2Row(char *name, int numFemale, int numGrads, R2Type **d){
  *d = (R2Type *) malloc(sizeof(R2Type));
  strcpy((*d)->countryName, name);
  (*d) -> numFemale = numFemale;
  (*d) -> numGrads = numGrads;
}

/*
  Function: initReport3Row()
  Purpose: initialize one row of linkedlist for report 3
  in: country name, number of all graduates in 2014, 2015, 2016, 2017 for all degrees 
  and all genders, report 3 datatype d
  out: initialize data needed for one row of linkedlist
*/
void initReport3Row(char *name, int num2014, int num2015, int num2016, int num2017, R3Type **d){
  *d = (R3Type *) malloc(sizeof(R3Type));
  strcpy((*d)->countryName, name);
  (*d) -> num2014 = num2014;
  (*d) -> num2015 = num2015;
  (*d) -> num2016 = num2016;
  (*d) -> num2017 = num2017;
}
