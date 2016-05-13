#include<stdio.h>

int main(){
	int m=0;
	scanf("%d",&m);

	while(m--){
		int sum=0;
		int a=0;
		int n=0;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
	}
	return 0;
}
