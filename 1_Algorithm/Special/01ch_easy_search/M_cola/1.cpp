#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

class Node{
    public:
        int a[3];
        int cnt;
        Node(int t=0,int b=0,int c=0,int d=0){
             a[0]=t;a[1]=b;a[2]=c;cnt=d;
        }
};



int S,N,M;
bool vis[101][101][101];
queue<Node> qe;
int top[3];


int BFS(Node st){
    int goal=S/2;
    memset(vis,false,sizeof(vis));
    while(!qe.empty()){
        qe.pop();
    }
    qe.push(st);
    vis[st.a[0]][st.a[1]][st.a[2]]=true;
    while(!qe.empty()){
         Node now=qe.front();
         qe.pop();
         int num=0;
         for(int i=0;i<3;i++){
             if(now.a[i]==goal){
                 num++;
             }
         }
         if(num==2)return now.cnt;

         Node nex;
         for(int i=0;i<3;i++){
             if(now.a[i]==0)continue;
             for(int j=0;j<3;j++){
                 if(j==i)continue;
                 int tmp=now.a[i]+now.a[j];
                 int tt[3];
                 for(int k=0;k<3;k++){
                     tt[k]=now.a[k];
                 }
                 if(tmp>top[j]){
                     tt[i]-=top[j]-tt[j];
                     tt[j]=top[j];
                     if(!vis[tt[0]][tt[1]][tt[2]]){
                        nex=Node(tt[0],tt[1],tt[2],now.cnt+1);
                        vis[tt[0]][tt[1]][tt[2]]=true;
                        qe.push(nex);
                     };
                 }else{
                     tt[j]+=tt[i];
                     tt[i]=0;
                     if(!vis[tt[0]][tt[1]][tt[2]]){
                        nex=Node(tt[0],tt[1],tt[2],now.cnt+1);
                        vis[tt[0]][tt[1]][tt[2]]=true;
                        qe.push(nex);
                     }
                 }
             }
         }
    }
    return -1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d%d%d",&S,&N,&M),S||N||M){
            if(S%2){
                printf("NO\n");
                continue;
            }
            top[0]=S;top[1]=N;top[2]=M;
            int ans=BFS(Node(S,0,0));
            if(ans<0)printf("NO\n");
            else printf("%d\n",ans);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
