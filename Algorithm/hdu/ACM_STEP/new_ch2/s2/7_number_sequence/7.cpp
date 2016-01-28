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
	int A,B,n;
	while(cin>>A>>B>>n, A||B||n){
		int f[1000];
		f[1]=f[2]=1;
		f[3]=(A+B)%7;
		f[4]=(A*f[3]+B*f[2])%7;
		int len=0;
		for(int i=5;i<200;i++){
			f[i]=(A*f[i-1]+B*f[i-2])%7;
			if((f[i]==f[4])
			&&(f[i-1]==f[3])){
				len=i-4;
				break;
			}
		}
		#ifdef U_DEBUG
		for(int i=1;i<=len+1;i++){
			cout<<f[i]<<" ";
		}
		cout<<endl<<endl<<endl;
		#endif
		if(n==1||len==0||n==2){
			printf("1\n");
		}
		else{
			printf("%d\n",f[(n-3)%(len)+3]);
		}
		
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
