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
const int MAXN=1005;
const int dir[4][4]={
    0,3,1,2,
    0,1,3,2,
    2,1,3,0,
    0,1,3,2,
};


int N,X,Y;


long long DFS(int N,int di,int x,int y){
    if(N==0){
        return 1;
    }
    long long ret;
    long long len=1<<(N-1);
    int xi=x/len;
    int yi=y/len;
    int ki=2*xi+yi;
    ret=dir[di][ki]*len*len+DFS(N-1,ki,x-xi*len,y-yi*len);
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>X>>Y;
    cout<<DFS(N,3,X-1,Y-1)<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
