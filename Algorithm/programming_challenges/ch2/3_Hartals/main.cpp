#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//#define ONLINE_JUDGE
//#define USER_DEBUG
#ifndef ONLINE_JUDGE
#pragma warning(disable:4996)
#endif

int main(int argc, char** argv) {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T,P,N;
	cin>>T;
	int h[110];
	bool flag[3700];
	while(T--){
		cin>>N;
		cin>>P;
		for(int i=1;i<=P;i++){
			cin>>h[i];
		}
		memset(flag,false,sizeof(flag));
		int hartal_day=0;
		for(int i=1;i<=P;i++){
			hartal_day=h[i];
			while(hartal_day<=N){
				int k=(hartal_day-1)%7;
				if((k!=5)&&(k!=6)){
					flag[hartal_day]=1;
				}
				hartal_day+=h[i];
			}
		}
		int sum=0;
		for(int i=1;i<=N;i++){
			sum+=flag[i];
		}
		cout<<sum<<endl;
	}
	
	#ifndef ONLINE_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif
	
	
	return 0;
}
