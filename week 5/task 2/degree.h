void Celcius_to_Kelvin_Fahrenheit(double celcius,double *fahrenheit, double *kelvin){
	*fahrenheit=(celcius*9/5)+32;
	*kelvin=celcius+273.15;
}

void Kelvin_to_Celcius_Fahrenheit(double kelvin, double *fahrenheit, double *celcius){
	*fahrenheit=((kelvin-273.15)*9/5)+32;
	*celcius=kelvin-273.15;
}

void Fahrenheit_to_Celcius_Kelvin(double fahrenheit, double *celcius, double *kelvin){
	*celcius=(fahrenheit-32)*5/9;
	*kelvin=((fahrenheit-32)*5/9)+273.15;
}

void print_temperatures(double celcius, double fahrenheit, double kelvin){
	printf("The degree in Fahrenheit: %.2lf\n",fahrenheit);
	printf("The degree in Celcius: %.2lf\n",celcius);
	printf("The degree in Kelvin: %.2lf\n",kelvin);
}
