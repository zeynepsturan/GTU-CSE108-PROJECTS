#include <stdio.h>
typedef enum Operation {ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION} optype;

void get_parameters(double *a, optype *op, double *b);
void print_result(double a, optype op, double b);

int main(){
	double num1,num2;
	optype operation;
	get_parameters(&num1,&operation,&num2);
	print_result(num1,operation,num2);
	return 0;
}

void get_parameters(double *a, optype *op, double *b){
	char operation_char;
	printf("Type an arithmetic question (e.g., 1+2):");
	scanf("%lf %c %lf",a,&operation_char,b);
	switch(operation_char){

		case '+':
		*op=ADDITION;
		break;

		case '-':
		*op=SUBTRACTION;
		break;
    
		case '*':
		*op=MULTIPLICATION;
		break;

		case '/':
		*op=DIVISION;
		break;
	}
}

void print_result(double a, optype op, double b){
	double result;
	switch(op){
    
		case 0:
		result=a+b;
		printf("Result = %.2lf\n",result);
		break;

		case 1:
		result=a-b;
		printf("Result = %.2lf\n",result);
		break;

		case 2:
		result=a*b;
		printf("Result = %.2lf\n",result);
		break;
    
		case 3:
		if(b==0){
			printf("Syntax Error\n");
		}

		else{

			result=a/b;
			printf("Result = %.2lf\n",result);
		}
		break;
	}
}
