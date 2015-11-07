#include<stdio.h>

int main(){
	int n;
	while(EOF!=scanf("%d",&n)&&n){
		int ans=5*n;
		int st=0;
		int ar=0;
		for(int i=0;i<n;i++){
			scanf("%d",&ar);
			int temp=ar-st;
			if(temp>0)ans+=(6*temp);
			else ans-=(4*temp);
			st=ar;
		}
		printf("%d\n",ans);
	}
	return 0;
}
