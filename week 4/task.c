	/*
 		the program with two choices first 
   		one is creating a pascal triangle 
     		and second one is a diamond pattern
       		which uses the pascal triangle logic
   		written by: zeynepsturan
	*/
#include <stdio.h>
/*function declarations*/
void pascal_triangle(int x),diamond_pattern(int x);
int combination(int n,int r);
int factorial(int n);
int main(){
	/*variable declarations*/
	int flag=1;
	int choice;
	int size;
	while(flag!=0){
    /*menu*/
    printf("1. Pascal's Triangle Pattern\n");
    printf("2. Diamond Pattern\n");
    printf("3. Exit\n");
    printf("Make your choice: ");
    scanf("%d",&choice);
    switch(choice){
			case 1:
			printf("Enter the pattern size:");
			scanf("%d",&size);
			pascal_triangle(size);
			break;
			
			case 2:
			printf("Enter the pattern size:");
			scanf("%d",&size);
			diamond_pattern(size);
			break;
			
			case 3:
			return 0;
			break;
			
			default:
			printf("There is no such an option\n");
			break;
		}
		
		printf("Would you like to draw another pattern? (Yes:1, No:0) :");
		scanf("%d",&flag);
	}
	
	return 0;
}

/*factorial and combination is used to create the pascal triangle*/
int factorial(int n){
	int result=1;
	while(n>=1){
		result*=n;
		n--;
	}
	return result;
}

int combination(int n,int r){
	int comb;
	comb=(int)factorial(n)/(int)(factorial(r)*factorial(n-r));
	return comb;
}

void pascal_triangle(int x){
	int i,j,k,space,numberCount,comb;
	/*pascal part*/
	space=x+2;
	for(i=0;i<space-1;i++){
		printf(" ");
	}
	printf("1");
	printf("\n");
	
	numberCount=1;
	
	for(i=0;i<x-1;i++){
		space=x-i;
		/*spaces*/
		for(j=0;j<space;j++){
			printf(" ");
		}
		/*numbers*/
		for(k=0;k<=numberCount;k++){
			printf("%d ",combination(numberCount,k));
		}
		
		printf("\n");
		numberCount++;
		space--;
		
	}
	printf("\n");
	/*star part*/
	space=x+1;
	for(i=0;i<=space-1;i++){
		printf(" ");
	}
	printf("*");
	printf("\n");
	
	numberCount=1;
	
	for(i=0;i<x-1;i++){
		space=x-i;
		/*spaces*/
		for(j=0;j<space;j++){
			printf(" ");
		}
		/*numbers*/
		for(k=0;k<=numberCount;k++){
			comb=combination(numberCount,k);
			if(comb%2==1){
				printf("* ");
			}
			
			else{
				printf("  ");
			}
		}
		
		printf("\n");
		numberCount++;
		space--;
		
	}
  printf("\n");
}


void diamond_pattern(int x){
	int i,j,k,starCount,space;
	if(x%2==0){
		x++;
	}
	x-=2;
	/*first part*/
	starCount=1;
	space=x/2+1;
	for(i=0;i<(int)x/2 +1;i++){
		/*spaces*/
		for(j=0;j<space;j++){
			printf(" ");
		}
		
		/*stars*/
		for(k=0;k<starCount;k++){
			printf("*");
		}
		printf("\n");
		starCount=starCount+2;
		space--;
	}
	
	/*second part*/
	for(i=0;i<x/2+2;i++){
	
		/*spaces*/
		for(j=0;j<space;j++){
			printf(" ");
		}
		
		/*stars*/
		for(k=0;k<starCount;k++){
			printf("*");
		}
		printf("\n");
		starCount-=2;
		space++;
	}
  printf("\n");
}
