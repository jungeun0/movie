#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"
//structure definition
typedef struct movInfo {
	char name[100];
	float score;
	int runtime;
	char country[10];
} movInfo_t;


void* mv_genMvInfo(char *name, float score, int runtime, char *country)
{	
	movInfo_t* mvPtr;
	
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	strcpy(mvPtr->country,country);
	strcpy(mvPtr->name,name);
	mvPtr->runtime = runtime;
	mvPtr->score = score;
	printf("%s %s %d %f\n",mvPtr->name, mvPtr->country, mvPtr->runtime, mvPtr->score);
	
	//allocate memory and set the member variables
	
	return (void*)mvPtr;
}

void printMv(void* obj)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;
										 //obj는 조건을 통해 선택된 영화 구조체
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->country);
	printf("running time : %i, score : %f\n", mvPtr->runtime, mvPtr->score);
	printf("----------------------------------------\n");
	return;
}
int mv_printAll(void* obj, void* arg)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;
		
	printMv(mvPtr);
	
	return 1;
}

int mv_printScore(void* obj, void* arg)
{		
	movInfo_t* mvPtr = (movInfo_t*)obj;
		
	if ((mvPtr->score) >= (*(float*)arg)){
			
		printMv(mvPtr);
		return 1;
	}
	else if (mvPtr == NULL){
		
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}

		//조건에 맞는 구조체를 불러와야 함.. 
		//obj는 movInfo 구조체 하나, arg는 조건
	return 0;
}

int mv_printRunTime(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if ((mvPtr->runtime) >= (*(int*)arg)){
			
		printMv(mvPtr);
		return 1;
	}
	else if (mvPtr == NULL){
		
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}

	
	return 0;
	
}

int mv_printCountry(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	char argument = *(char*)arg;
	
	int comparison = strcmp(mvPtr->country,argument);
	
	if(comparison == 0){
			
		printMv(mvPtr);
		return 1;
	
	}
	else if (mvPtr == NULL){
		
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}

	
	return 0;
}




