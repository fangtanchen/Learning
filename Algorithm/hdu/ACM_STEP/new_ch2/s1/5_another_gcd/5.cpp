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

int gcd(int x,int y){
	if(x%y==0)return y;
	else{
		return gcd(y,x%y);
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int n;
	cin>>n;
	while(n--){
		int a,b,c,p;
		scanf("%d%d",&a,&c);
		int t1=a/c;
		if(t1==1){
			printf("%d\n",2*c);
			continue;
		}
		for(int i=2;;i++){
			if(i<t1){
				if(t1%i){
					b=c*i;
					break;
				}
			}
			else{
				if(i%t1){
					b=c*i;
					break;
				}
			}
		}
		printf("%d\n",b);
		#ifdef U_DEBUG
		printf("%d %d %d\n",a,b,gcd(a,b));
		#endif
	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
