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
							//데이터에서 받은 값을 mvInfo에 넣어줌 
	
	//allocate memory and set the member variables
	
	return (void*)mvPtr;
}
 
void printMv(void* obj)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj; 	 //obj는 조건을 통해 선택된 영화 구조체
									
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
	
		//obj는 movInfo 구조체 하나, arg는 조건	
	if ((mvPtr->score) >= (*(float*)arg)){
									 //score가 입력받은 score값보다 같거나 큰 경우 
		printMv(mvPtr);
		return 1;
	}
	else if (mvPtr == NULL){
		
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
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
	
	int comparison = strcmp((char*)mvPtr->country,(char*)arg);  //country와 입력받은 country값을 비교
	
	if(comparison == 0){
			 //country와 입력받은 country값을 비교했을 때, comparison이 0을 반환함. 즉, 0일 경우 두 변수가 같음.
		printMv(mvPtr);
		return 1;
		
	}
	else if (mvPtr == NULL){
		
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	
	return 0;
}




