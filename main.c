#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runtime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	/* linked list�� ����Ű��, list�� ����Ű�� ������ ���� *list, ��带 ����Ű�� ������ �ʿ��� �̰� node ������*/ 
	int (*repFunc)(void* obj, void* arg); //function pointer for using list_repeatFunc() function �Լ�������
	void *arg; //a void pointer for passing argument to repFunc
	int cnt=0; //integer variable
	
	 
	//1. reading the movie.dat-----------------------------
	
	
	//1.1 FILE open:
	fp = fopen("movie.dat","r");
	if(fp != NULL){
		printf("������ �������ϴ�.\n");
	} 
	else{
		printf("���� ���� ����.\n");
		return 0;
	}
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while (fscanf(fp,"%s %s %d %f",name,country,&runtime,&score)!=EOF/*�о�� ������ ��� ������ ����*/ )
	{  	
		//����ü�� �ѱ� 
		mvInfo = mv_genMvInfo(name,score,runtime,country);
		list_addTail(mvInfo,list);
		
	}
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
	printf("ready done!");
	printf("%d items are read\n",(list_len(list))); 
    fclose(fp);
	//1.4 FILE close
	
	//2. program start
	while(exit_flag == 0)
	{	
		
		
		printf("-------------------- menu --------------------\n");
		printf("1. print all the movies\n");
		printf("2. search for specific score movies\n");
		printf("3. search for specific runtime movies\n");
		printf("4. search for specific country movies\n");
		printf("5. exit\n");
		printf("-------------------- menu --------------------\n");
		
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				repFunc = mv_printAll; //mv_print-All�ȿ� printmv�� ���� ��
				arg = NULL; // arg�� ����ü�� �ҷ��� �� �ִ� ���� 	
				list_repeatFunc(repFunc, arg, list);
				
				break; 
				
			case 2: //print movies of specific country
				printf("select the score : \n");
				arg = &score;
				scanf("%f",&score);
				printf("\nprinting  the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				repFunc = mv_printScore; //score�� ��� �ѱ���? 
				
				
				break;
			case 3: //print movies with long runtime
				printf("\nprinting  the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");	
				repFunc = mv_printRunTime;
				
				list_repeatFunc(repFunc, arg, list);
				arg = NULL;
				break;
			case 4: //print movies with high score
				printf("\nprinting the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				repFunc = mv_printCountry;
				
				list_repeatFunc(repFunc, arg, list);	
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				
				break;
					
			default:
				printf("wrong command! input again\n");
				break;
			
				
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
	
		} 
		
	
		
		//2.3 print number of movies
		list_repeatFunc(repFunc, arg, list);
		printf("totally %i movies are listed!\n",list_repeatFunc(repFunc, arg, list));

   }
   
   	return 0;
}


