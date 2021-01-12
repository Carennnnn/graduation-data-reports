#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 32
#define MAX_NUM 50

typedef struct {
  char countryCode[MAX_STR];
  char countryName[MAX_STR];
  char gender[MAX_STR];
  char degree[MAX_STR];
  int year;
  int numGrads;
} DataType;

typedef struct Node {
  DataType *data;
  struct Node *next;
} NodeType;

typedef struct {
  NodeType *head;
} ListType;


typedef struct {
  char countryName[MAX_STR];
  int numBach;
  int numMas;
  int numDoc;
  int numGrads;
} R1Type;

typedef struct R1Node {
  R1Type *data;
  struct R1Node *next;
} R1NodeType;

typedef struct {
  R1NodeType *head;
} R1ListType;


typedef struct {
  char countryName[MAX_STR];
  int numFemale;
  int numGrads;
} R2Type;

typedef struct R2Node {
  R2Type *data;
  struct R2Node *next;
} R2NodeType;

typedef struct {
  R2NodeType *head;
} R2ListType;

typedef struct {
  char countryName[MAX_STR];
  int num2014;
  int num2015;
  int num2016;
  int num2017;
} R3Type;

typedef struct R3Node {
  R3Type *data;
  struct R3Node *next;
} R3NodeType;

typedef struct {
  R3NodeType *head;
} R3ListType;


typedef struct {
  R2Type *dataPtr[MAX_NUM];
  int size;
} R2ArrayType;

void initAllRecord(ListType **);
void initRecord(char *, char *, char *, char *, int, int, DataType **);
void addRecordToList(ListType **, DataType **);
void initReport1Row(char *, int, int, int, int, R1Type **);
void addReport1ToList(R1ListType **, R1Type **);
void reportOne(ListType *, R1ListType **);
void printReport1List(R1ListType *, int, int, int, int);
void reportTwo(ListType *, R2ListType **);
void initReport2Row(char *, int, int, R2Type **);
void addReport2ToList(R2ListType **, R2Type **);
void printReport2List(R2ListType *);
void reportThree(ListType *,R3ListType **);
void initReport3Row(char *, int, int, int, int, R3Type **);
void addReport3ToList(R3ListType **, R3Type **);
void printReport3List(R3ListType *, int, int, int, int);
void printMenu(int *);
void freeMemory(ListType *, R1ListType *, R2ListType *, R3ListType *);
