#include <stdio.h>
#include <string.h>
int print_special_substrings(const char *str);

int main(){
	char array[]="abcab";
	print_special_substrings(array);
	return 0;
}

int print_special_substrings(const char *str){
	int size=strlen(str);
	char sub_array[size+1];
	int i=0,j=0;

	if(size==1){
		return 0;
	}

	else{

		if(str[0]==str[size-1]){
			printf("%s\n",str);
		}

		for(j=0;j<size;j++){

			for(i=0;i<size-1;i++){
				sub_array[i]=str[j+i];
			}

			sub_array[i]='\0';
			print_special_substrings(sub_array);
		}
	}

	return 0;
}
