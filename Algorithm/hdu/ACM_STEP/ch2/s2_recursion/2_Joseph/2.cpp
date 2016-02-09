#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int k=1;
	int at[15];
	for(k=1;k<14;k++){
		int m=k+1;
		int cnt=0;
		int pos=1;
		int size=2*k;
		
		while(1){
			while(cnt<k){
				pos=(pos+(m-1)%size-1)%size+1;
				if(pos<=k)break;
				else{
					cnt++;
					size--;
				}
			}
			if(cnt==k)break;
			else{
				m++;
				size=2*k;
				pos=1;
				cnt=0;
			}
		}
		at[k]=m;
		
		#ifdef U_DEBUG
		
		cnt=0;
		pos=1;
		size=2*k;
		while(cnt<k){
			pos=(pos+(m-1)%size-1)%size+1;
			if(pos<=k)break;
			else{
				cnt++;
				size--;
				cout<<pos<<" "<<endl;
			}
		}
		
		#endif
	}
	
	while((EOF!=scanf("%d",&k))&&k){
		printf("%d\n",at[k]);
	}
	

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
