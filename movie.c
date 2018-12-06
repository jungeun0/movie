#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

//structure definition
typedef struct movInfo {
	char name[100];
	float score;
	int runtime;
	char country[10];
} movInfo_t;

void* mv_genMvInfo(char name, float score, int runtime, char country)
{
	movInfo_t* mvPtr;
	
	mvPtr->name = name;
	mvPtr->country = country;
	mvPtr->runtime = runtime;
	mvPtr->score = score;
	
	//allocate memory and set the member variables
	
	return (void*)mvPtr;
}

void printMv(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->country);
	printf("running time : %i, score : %f\n", mvPtr->runtime, mvPtr->score);
	
	return;
}

int mv_printAll(void* obj, void* arg)
{
	
}

int mv_printScore(void* obj, void* arg)
{
	
}

int mv_printRunTime(void* obj, void* arg)
{
	
}

int mv_printCountry(void* obj, void* arg)
{
	
}




