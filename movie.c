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


void* mv_genMvInfo(char *name, float score, int runtime, char *country)
{	
	movInfo_t* mvPtr;
	
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	strcpy(mvPtr->country,country);
	strcpy(mvPtr->name,name);
	mvPtr->runtime = runtime;
	mvPtr->score = score;
	//printf("%s %s %d %f\n",mvPtr->name, mvPtr->country, mvPtr->runtime, mvPtr->score);
	
	//allocate memory and set the member variables
	
	return (void*)mvPtr;
}

void printMv(void* obj)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));  //obj�� ������ ���� ���õ� ��ȭ ����ü
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
	printMv(obj);
	
}

int mv_printScore(void* obj, void* arg)
{
		//���ǿ� �´� ����ü�� �ҷ��;� ��.. 
	//obj�� movInfo ����ü �ϳ�, arg�� ����
}

int mv_printRunTime(void* obj, void* arg)
{
	
}

int mv_printCountry(void* obj, void* arg)
{
	
}




