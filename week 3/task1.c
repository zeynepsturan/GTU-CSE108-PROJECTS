  /*
	simple guess the number game
	written by zeynepsturan
  */
#include <stdio.h>
#include <stdlib.h> /*this libraries are needed to use random functions*/
#include <time.h>

int main(){
  /*variable declarations*/
	int target,guess,guessCount;

	srand(time(0));
	target=rand() % 1000 +1; /*creating a random number for target*/
	guessCount=0;
	printf("Welcome to the Guessing Game!\n");

	while(1){
		printf("Enter your guess (between 1 and 1000): ");
		scanf("%d",&guess);
    
		if(guess<1 || guess>1000){
			printf("Your guess must be between 1 and 1000\n\n");
		}

		else if(guess>target){
			printf("Your guess is greater than the target.\n\n");
			guessCount++;
		}

		else if(guess<target){
			printf("Your guess is less than the target.\n\n");
			guessCount++;
		}

		else{
			printf("Congratulations! You guessed the target number!\n");
			guessCount++;
			printf("Total guesses made: %d\n",guessCount);
			break;
		}
	}	
  
	return 0;
}
