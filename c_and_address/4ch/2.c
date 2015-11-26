#include<stdio.h>
int isprime(int n){
	int imax=n/2;
	int i;
	for(i=2;i<=imax;i++){
		if(n%i)continue;
		return 0;
	}
	return 1;
}

int main(){
	int num;
	printf("1\n");
	for(num=2;num<=100;num++){
		if(isprime(num))
			printf("%d\n", num);
	}
	return 0;
}
