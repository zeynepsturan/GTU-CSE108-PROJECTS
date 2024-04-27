#include <stdio.h>
int check_palindrome(char array[],int size,int *index);

int main(){

	int n=0;
	char string[5]="noon";

	check_palindrome(string,5,&n);
	return 0;

}

int check_palindrome(char array[],int size,int *index){

	if(*index==size-1-*index || *index==size-2-*index){
		printf("The string \"%s\" is a palindrome\n",array);
	}

	else{

		if(array[*index]==array[size-2-*index]){
			(*index)++;

			check_palindrome(array,size,index);
		}

		else{
			printf("%d %d\n",*index,size-2-*index);
			return 0;

		}
	}

	return 0;
}
