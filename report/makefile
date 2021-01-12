OBJ = main.o report.o init.o addToList.o print.o freeMemory.o

all: main report init addToList print freeMemory
	gcc -o a5 $(OBJ)

main: main.c defs.h
	gcc -c main.c

report: report.c defs.h
	gcc -c report.c

init: init.c defs.h
	gcc -c init.c

addToList: addToList.c defs.h
	gcc -c addToList.c

print: print.c defs.h
	gcc -c print.c

freeMemory: freeMemory.c defs.h
	gcc -c freeMemory.c
