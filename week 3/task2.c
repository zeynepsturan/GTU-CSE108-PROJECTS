	/*
		the code that draws a stickman
		and allows to move right and left
		and raise or put down his arms
		written by zeynepsturan
	*/

#include <stdio.h>
/*variable declarations*/
char armStatus='d';
char move='n';
int newPosition=0;
int position=4;

/*function declarations*/
void drawStickman(int position, char armStatus);
int moveStickman(int position, char move);

int main(){
	/*beginning of the program*/
	printf("Welcome to Stickman Animation!\n");
	printf("Use 'a' to move left, 'd' to move right,\n's' to switch arms, and 'e' to exit\n");
	drawStickman(position,'d');

	while(1){
		printf("\nEnter your move: ");
		scanf(" %c",&move);
		printf("\n");

		if(move=='e'){ /*if e is entered, program ends*/
      
			return 0;
		}

		else{
			newPosition=moveStickman(position,move); /*returns the change in the position*/

			if(newPosition==0){ /*returning 0 means switching the arm position*/

				if(armStatus=='u'){

					armStatus='d';
				}

				else if(armStatus=='d'){

					armStatus='u';
				}
			}	

			if(position+newPosition>=0){

				position+=newPosition;
				drawStickman(position,armStatus);
			}

			else{ /*it prevents the stickman from overflowing to left*/

				drawStickman(position,armStatus);
			}
		}
	}
  
	return 0;
}

/*function declarations*/
int moveStickman(int position, char move){
	switch(move){
			case 'a':
			return -1;
			break;

			case 'd':
			return +1;
			break;

			case 'n':
			return position;
			break;
    
			case 's':
			return 0;
			break;

			default:
			break;
		}
}

void drawStickman(int position, char armStatus){
	int i;

	if(armStatus=='d'){

		for(i=0;i<position+1;i++){

			printf(" ");
		}
		printf("o\n");

		for(i=0;i<position+1;i++){

			printf(" ");
		}
		printf("|\n");

		for(i=0;i<position+1;i++){

			printf(" ");
		}
		printf("|\n");

		for(i=0;i<position;i++){
      
			printf(" ");
		}
		printf("/ \\ \n");
	}

	else if(armStatus=='u'){

		for(i=0;i<position+1;i++){

			printf(" ");
		}
		printf("o\n");

		for(i=0;i<position;i++){

			printf(" ");
		}
		printf("/|\\ \n");

		for(i=0;i<position+1;i++){

			printf(" ");
		}
		printf("|\n");

		for(i=0;i<position;i++){

			printf(" ");
		}
		printf("/ \\ \n");
	}
}
