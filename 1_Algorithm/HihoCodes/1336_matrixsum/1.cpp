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
const int MODU=1e9+7;

int A[MAXN][MAXN];
int N,M;

int Lowbit(int x){
    return x&-x;
}

void Add(int i,int j,int add){
    int tj=j;
    while(tj<MAXN){
        A[i][tj]+=add;
        A[i][tj]%=MODU;
        tj+=Lowbit(tj);
    }
}

int Sum(int ri,int ci){
    int ret=0;
    while(ci>0){
        ret+=A[ri][ci];
        ret%=MODU;
        ci-=Lowbit(ci);
    }
    return ret;
}

int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    scanf("%d%d",&N,&M);
    memset(A,0,sizeof(A));
    char op[10];
    for(int mi=0;mi<M;mi++){
        scanf("%s",op);
        if(0==strcmp(op,"Add")){
            int x,y,add;
            scanf("%d%d%d",&x,&y,&add);
            Add(x+1,y+1,add);
        }else{
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x1++;x2++;y1++;y2++;
            int sum=0;
            for(int ri=x1;ri<=x2;ri++){
                sum=sum+Sum(ri,y2)-Sum(ri,y1-1);
                if(sum>=MODU)sum-=MODU;
            }
            if(sum<0)sum+=MODU;
            printf("%d\n",sum);
        }
    }



#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
