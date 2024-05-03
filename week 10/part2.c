  /*
    the program that fills an array with random intigers and 
    takes a number as an input and finds the closest number in the array
    written by: zeynepsturan
  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LIMIT 1000
#define SIZE 12

int generateRandom(int limit),
	find_closest_number(int array[], int query, int n, int *number, int *distance);

int main(){

	int keep_distance=LIMIT;
	int keep_number;
	int i, query, found_number;
	int array[SIZE];

	srand(time(NULL));

	for(i=0;i<SIZE;i++){

		array[i]=generateRandom(LIMIT);

	}

	printf("Aray= [");

	for(i=0;i<SIZE-1;i++){

		printf("%d,", array[i]);

	}

	printf("%d]\n", array[i]);

	

	printf("Please enter the number: ");

	scanf("%d",&query);

	

	found_number=find_closest_number(array, query, SIZE-1, &keep_number, &keep_distance);

	printf("Query= %d, Closest= %d\n",query,found_number);

	return 0;
}



int find_closest_number(int array[], int query, int n, int *number, int *distance){

	if(n<0){

		return *number;

	}

	else{

		if( (abs(array[n]-query)) < *distance ){

			*distance=abs(array[n]-query);
			*number=array[n];

		}

		find_closest_number(array, query ,n-1, number, distance);
	}
}

int generateRandom(int limit){

	return rand()%(limit+1);
}
