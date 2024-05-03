  /*
    simple 2D game
    player is in a car and tries to get
    to the finish point
    written by: zeynepsturan
  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define MAX_MOVE SIZE*SIZE

typedef struct{

	int cost; /*holds how much does it cost to go that point*/
	char type; /*holds what is in that point*/
	
}block;

int X,Y; /*player's coordinates*/
int total_cost=0;
char moves[]="";
int n=0;

void 
	init_board(block board[SIZE][SIZE]),
	print_board(block board[SIZE][SIZE]),
	print_moves(char moves[MAX_MOVE]), /*prints every move done*/
	gameplay(block board[SIZE][SIZE])
;

int main(){

	block board[SIZE][SIZE];

	srand(time(NULL));
	gameplay(board);

	return 0;
}

void gameplay(block board[SIZE][SIZE]){

	init_board(board);
	print_board(board);

	char move,c;

	do{
		printf("Enter your move(w,a,s,d or r to run): ");
		scanf("%c",&move);

		while( (c=getchar()) != '\n'){}

		switch(move){

			/*move up*/

			case 'w':

				if(X-1>0 && board[X-1][Y].type=='.'){

					board[X-1][Y].type='-'; /*marks as visited*/
					X--; /*modifies player's coordinates*/
					
					moves[n]='^'; /*saves the move*/
					moves[n+1]='\0'; /*shifts the end of array*/
					n++;

					total_cost+=board[X-1][Y].cost;
				}

				else if(X-1>0 && board[X-1][Y].type=='F'){

					X--; /*modifies player's coordinates*/

					moves[n]='^'; /*saves the move*/
					moves[n+1]='\0'; /*shifts the end of array*/
					n++;

					total_cost+=board[X-1][Y].cost;
				}

				break;

			/*move left*/

			case 'a':

				if(Y-1>0 && board[X][Y-1].type=='.'){

					board[X][Y-1].type='-'; /*marks as visited*/
					Y--; /*modifies player's coordinates*/

					moves[n]='<'; /*saves the move*/
					moves[n+1]='\0'; /*shifts the end of array*/
					n++;

					total_cost+=board[X][Y-1].cost;
				}

				else if(Y-1>0 && board[X][Y-1].type=='F'){

					Y--; /*modifies player's coordinates*/

					moves[n]='<'; /*saves the move*/
					moves[n+1]='\0'; /*shifts the end of array*/
					n++;

					total_cost+=board[X][Y-1].cost;
				}
				break;

			/*move down*/

			case 's':

				if(X+1<SIZE && board[X+1][Y].type=='.'){

					board[X+1][Y].type='-'; /*marks as visited*/
					X++; /*modifies player's coordinates*/

					moves[n]='v'; /*saves the move*/
					moves[n+1]='\0'; /*shifts the end of array*/
					n++;

					total_cost+=board[X+1][Y].cost;
				}

				else if(X+1<SIZE && board[X+1][Y].type=='F'){

					X++; /*modifies player's coordinates*/

					moves[n]='v'; /*saves the move*/
					moves[n+1]='\0'; /*shifts the end of array*/
					n++;

					total_cost+=board[X+1][Y].cost;
				}
				break;

			/*move right*/
			case 'd':

				if(Y+1<SIZE && board[X][Y+1].type=='.'){

					board[X][Y+1].type='-'; /*marks as visited*/
					Y++; /*modifies player's coordinates*/

					moves[n]='>'; /*saves the move*/
					moves[n+1]='\0'; /*shifts the end of array*/
					n++;

					total_cost+=board[X][Y+1].cost;
				}

				else if(Y+1<SIZE && board[X][Y+1].type=='F'){				

					Y++; /*modifies player's coordinates*/

					moves[n]='>'; /*saves the move*/
					moves[n+1]='\0'; /*shifts the end of array*/
					n++;

					total_cost+=board[X][Y+1].cost;
				}
				break;

			case 'r': /*ends the move input and runs the game*/

				print_board(board);
				print_moves(moves);

				if(board[X][Y].type=='F'){

					printf("You won!!!\n");
				}

				else{

					printf("Maybe next time\n");
				}

				printf("Total cost: %d\n",total_cost);
				break;

			default:

				printf("There is no such an option\n");
				break;
		}

	}while(move!='r');

}

void print_moves(char moves[MAX_MOVE]){

	int i=0;

	while(moves[i]!='\0' && i<MAX_MOVE-1){

		printf("%c",moves[i]);
		i++;

	}
	printf("\n");
}

void init_board(block board[SIZE][SIZE]){

	int i,j,costnum;

	for(i=0;i<SIZE;i++){ /*empties the array*/

		for(j=0;j<SIZE;j++){

			board[i][j].type='.';
			costnum=rand()%10;
			board[i][j].cost=costnum;

		}

	}

	/*creating F(finish) coordinates randomly*/

	i=rand()%SIZE;
	j=rand()%SIZE;
	board[i][j].type='F';

	/*creating C(car) coordinates randomly*/

	i=rand()%SIZE;
	j=rand()%SIZE;

	board[i][j].type='C';

	/*saving the car coordinates*/
	X=i;
	Y=j;	

}

void print_board(block board[SIZE][SIZE]){

	int i,j;

	for(i=0;i<SIZE;i++){

		for(j=0;j<SIZE;j++){

			printf("%c ",board[i][j].type);

		}

		printf("\n");

	}
}
