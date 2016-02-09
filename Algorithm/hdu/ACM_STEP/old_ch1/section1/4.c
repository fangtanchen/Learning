#include<stdio.h>

int main(){
	int n;
	while(scanf("%d",&n)&&n){
		int sum=0;
		int a=0;
		while(n--){
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
	}
	return 0;
}
