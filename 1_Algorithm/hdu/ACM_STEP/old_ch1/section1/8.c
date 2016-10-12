#include<stdio.h>

int main(){
	int m=0;
	scanf("%d",&m);
	int flag=0;
	while(m--){
		int sum=0;
		int a=0;
		int n=0;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&a);
			sum+=a;
		}

		if(flag)printf("\n");
		else flag=1;
		printf("%d\n",sum);
	}
	return 0;
}
