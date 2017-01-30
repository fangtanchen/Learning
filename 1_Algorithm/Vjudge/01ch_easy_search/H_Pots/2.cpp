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
const int MODU=200;
const int MAXN=40005;
int A,B,C;

bool vis[MAXN];
int mp[MAXN],op[MAXN];
queue<int> Q;


int BFS(){
    while(!Q.empty())Q.pop();
    memset(vis,false,sizeof(vis));
    memset(mp,-1,sizeof(mp));
    memset(op,-1,sizeof(op));
    Q.push(0);
    vis[0]=true;
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        int a=now/MODU,b=now%MODU;
        if(a==C||b==C){
            return now;
        }
        int ta,tb,tmp;
        ta=A;tb=b;tmp=ta*MODU+tb;
        if(!vis[tmp]){
             vis[tmp]=true;
             mp[tmp]=now;
             op[tmp]=1;
             Q.push(tmp);
        }
        ta=a;tb=B;tmp=ta*MODU+tb;
        if(!vis[tmp]){
             vis[tmp]=true;
             mp[tmp]=now;
             op[tmp]=2;
             Q.push(tmp);
        }
        ta=0;tb=b;tmp=ta*MODU+tb;
        if(!vis[tmp]){
             vis[tmp]=true;
             mp[tmp]=now;
             op[tmp]=3;
             Q.push(tmp);
        }
        ta=a;tb=0;tmp=ta*MODU+tb;
        if(!vis[tmp]){
             vis[tmp]=true;
             mp[tmp]=now;
             op[tmp]=4;
             Q.push(tmp);
        }
        ta=a-min(a,B-b);tb=min(B,a+b);tmp=ta*MODU+tb;
        if(!vis[tmp]){
             vis[tmp]=true;
             mp[tmp]=now;
             op[tmp]=5;
             Q.push(tmp);
        }
        ta=min(A,a+b);tb=b-min(A-a,b);tmp=ta*MODU+tb;
        if(!vis[tmp]){
             vis[tmp]=true;
             mp[tmp]=now;
             op[tmp]=6;
             Q.push(tmp);
        }
    }
    return -1;
}

void Print(int now,int len){
    if(now==0){
        printf("%d\n",len);
        return;
    }
    Print(mp[now],len+1);
    switch(op[now]){
        case 1:
            printf("FILL(1)\n");
            break;
        case 2:
            printf("FILL(2)\n");
            break;
        case 3:
            printf("DROP(1)\n");
            break;
        case 4:
            printf("DROP(2)\n");
            break;
        case 5:
            printf("POUR(1,2)\n");
            break;
        case 6:
            printf("POUR(2,1)\n");
            break;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d%d",&A,&B,&C);
    int ans=BFS();
    if(-1==ans)printf("impossible\n");
    else{
         Print(ans,0);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
