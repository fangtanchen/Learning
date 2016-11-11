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
const int MAXN=2e5+10;
int x[MAXN],y[MAXN];
int N;

int Judge(int id1,int id2,int id3){
    return (x[id2]-x[id1])*(y[id3]-y[id1])-(x[id3]
            -x[id1])*(y[id2]-y[id1]);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&N),N){
            for(int i=0;i<N;i++){
                scanf("%d%d",x+i,y+i);
            }
            bool flag=true;
            for(int i=0;i<N;i++){
                int id0=i;
                int id1=(i+1)%N;
                int id2=(i+2)%N;
                if(Judge(id0,id1,id2)<=0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                printf("convex\n");
            }else{
                 printf("concave\n");
            }
        }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
