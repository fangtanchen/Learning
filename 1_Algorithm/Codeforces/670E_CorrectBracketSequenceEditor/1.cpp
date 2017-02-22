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
const int MAXN=5e5+10;

int N,M,P;
int pre[MAXN],nxt[MAXN],p[MAXN],stk[MAXN],top;
char s1[MAXN],s[MAXN];
int vis[MAXN];



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d%d",&N,&M,&P);
    scanf("%s%s",s+1,s1+1);
    top=-1;
    for(int i=1;s[i];i++){
         pre[i]=i-1;
         nxt[i]=i+1;
         if(s[i]=='('){
             stk[++top]=i;
         }else{
              int k=stk[top--];
              p[k]=i;
              p[i]=k;
         }
    }
    memset(vis,0,sizeof(vis));
    int now=P;
    for(int i=1;i<=M;i++){
        switch(s1[i]){
            case 'L':
                {
                    now=pre[now];
                }break;
            case 'R':
                {
                    now=nxt[now];
                }break;
            case 'D':
                {
                    int l,r;
                    if(now<p[now]){
                         l=now;
                         r=p[now];
                    }else{
                        l=p[now];
                        r=now;
                    }
                    vis[l]+=1;vis[r]-=1;
                    nxt[pre[l]]=nxt[r];
                    pre[nxt[r]]=pre[l];
                    now=nxt[r];
                    if(now>N)now=pre[l];
                }break;
            default:
                break;
        }
    }
    int sum=0;
    for(int i=1;i<=N;i++){
        sum+=vis[i];
        if((!sum)&&(!vis[i])) putchar(s[i]);
    }
    printf("\n");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
