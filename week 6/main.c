	/*
 		a 4 part program
   		1- filling an array with user inputs
     		2- counting the prime numbers in that array
       		3- comparing two arrays index by index
	 	4- searching a word in the given array
 	*/
#include <stdio.h>
/*function declarations*/
int countPrimes(double array[],int size),isPrime(int x);
void fillArray(double array[],int size);
void compareArrays(double array1[],double array2[],int result_array[],int size);
int searchQuery(char text[],char word[]);

int main(){
	/*variable declarations*/
	int i,size,prime_count,search_result;

  	//part 1
	printf("Please enter the size of the arrays: ");
	scanf("%d",&size);

	double my_array[size];
	fillArray(my_array,size);
	prime_count=countPrimes(my_array,size);
	printf("\nNumber of the primes in the array is %d.\n",prime_count);

  //part 2
	printf("Please enter the size of the arrays: ");
	scanf("%d",&size);
	double arr1[size];
	double arr2[size];
	int result[size];
  
	fillArray(arr1,size);
	printf("\n");
	fillArray(arr2,size);

	compareArrays(arr1,arr2,result,size);
	printf("\n\n");

  //part 3
	char target[100]="Many that live deserve death. And some that die deserve life. Can you give it to them?";
	char query[10]="cherry";

	printf("Target:");
	for(i=0;target[i]!='\0';i++){
		printf("%c",target[i]);
	}
	printf("\n");

	printf("Query:");
	for(i=0;query[i]!='\0';i++){
		printf("%c",query[i]);
	}
	printf("\n");

	search_result=searchQuery(target,query);
	if(search_result==-1){
		printf("Result:The word does not exist in the text\n\n");
	}

	else{
		printf("Result:\"%s\" is contained in target at position %d.\n\n",query,search_result);
	}

	return 0;
}

int searchQuery(char text[],char word[]){
	int i,j,flag;
	flag=0;
	for(i=0;(text[i]!='\0');i++){
		if(text[i]==word[0]){
			flag=1;
			for(j=1;(text[i+j]!='\0') && (word[j]!='\0');j++){
				if(text[i+j]!=word[j]){
					flag=0;
					break;
				}
			}
      
			if(flag==1){
				return i;
			}
		}
	}

	if(flag==0){
		return -1;
	}
}

void compareArrays(double array1[],double array2[],int result_array[],int size){
	int i;

	for(i=0;i<size;i++){
		if(array1[i]>array2[i]){
			result_array[i]=1;
		}

		else{
			result_array[i]=0;
		}
		printf("%d ",result_array[i]);
	}
}

void fillArray(double array[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("Enter the %d. index of the array: ",i);
		scanf("%lf",&array[i]);
	}
}

int isPrime(int x){
	int i;
  if(x<=1){
      return 0;
  }

  else if(x==2 || x==3){
      return 1;
  }
  else{
      for(i=2;i<=x/2;i++){
          if((x%i)==0){
              return 0;
          }
    }
  }
return 1;
}

int countPrimes(double array[],int size){
	int i,count=0,value;
	for(i=0;i<size;i++){
		value=isPrime(array[i]);
		if(value==1){
			count++;
		}
	}
	return count;
}
