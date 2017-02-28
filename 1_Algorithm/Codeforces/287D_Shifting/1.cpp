#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;

deque<int> Q;
int N;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    for(int i=1;i<=N;i++){
         Q.push_back(i);
    }
    for(int i=2;i<=N;i++){
        for(int j=(N-1)/i;j>0;j--){
            swap(Q[j*i],Q[(j-1)*i]);
        }
        Q.push_back(Q.front());
        Q.pop_front();
    }
    for(int i=0;i<N;i++){
         printf("%d ",Q[i]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
