#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<set>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;

int A[MAXN],T,N;
multiset<int> s;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        s.clear();
         scanf("%d",&N);
         for(int i=0;i<N;i++){
             scanf("%d",A+i);
         }
         sort(A,A+N);
         s.insert(A[0]);
         for(int i=1;i<N;i++){
              int t=*s.begin();
              if(2*t<=A[i])s.erase(s.begin());
              s.insert(A[i]);
         }
         printf("Case %d: %d\n",ti,(int)s.size());
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
