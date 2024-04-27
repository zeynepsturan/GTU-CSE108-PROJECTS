#include <stdio.h>
#define MAXIT 100

void hs(int array[],int *cn, int maxit);

int main(){
	int i, n=1;
	int a[MAXIT]={2};

	hs(a,&n,MAXIT);

  for(i=0;a[i]!=1 && i<MAXIT;i++){
			printf("%d ",a[i]);
		}
	printf("%d\n",a[i]);
	return 0;
}

void hs(int array[],int *cn, int maxit){

	/*printf("%d",*cn);*/
	int a=*cn-1;

	if(array[*cn]==1 || *cn==maxit){
	}

	else{

		if(array[a]%2==0){
			array[a+1]=array[a]/2;
		}

		else{
			array[a+1]=(array[a]*3)+1;
		}

		(*cn)++;
		hs(array,cn,maxit);

	}
}
