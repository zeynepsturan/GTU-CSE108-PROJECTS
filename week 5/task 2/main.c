	/*
 		simple program for converting
   		celcius,kelvin and fahrenheit values
     		user enters
       		written by zeynepsturan
 	*/
#include <stdio.h>
#include "degree.h" /*the library for converting functions*/

int main(){
	/*variable declarations*/
	double celcius,kelvin,fahrenheit;
	char option;

	do{
		printf("1. Convert to Fahrenheit(Enter Celcius Degree)\n");
		printf("2. Convert to Celcius (Enter Fahrenheit Degree)\n");
		printf("3. Convert to Kelvin(Enter Celcius Degree)\n");
		printf("0. Choose if you want to exit\n");
		printf("Choose an option (1,2,3 or 0 to exit): ");
		scanf(" %c",&option);

		switch(option){
      
			case '1':
			printf("Enter Celcius degree: ");
			scanf("%lf",&celcius);
			Celcius_to_Kelvin_Fahrenheit(celcius,&fahrenheit,&kelvin);
			break;

			case '2':
			printf("Enter Fahrenheit degree: ");
			scanf("%lf",&fahrenheit);
			Fahrenheit_to_Celcius_Kelvin(fahrenheit,&celcius,&kelvin);
			break;

			case '3':
			printf("Enter Kelvin degree: ");
			scanf("%lf",&kelvin);
			Kelvin_to_Celcius_Fahrenheit(kelvin,&fahrenheit,&celcius);
			break;

			case '0':
			break;
      
			default:
			printf("There is no such an option\n");
			break;
		}

		print_temperatures(celcius,fahrenheit,kelvin);
		printf("\n\n");
	}while(option!='0');

	return 0;
}
