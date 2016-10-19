#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=105;

int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    int res=0;
    int A;
    for(int i=1;i<=N;i++){
         cin>>A;
         res^=A;
    }
    if(res){
        printf("Alice\n");
    }else{
         printf("Bob\n");
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
