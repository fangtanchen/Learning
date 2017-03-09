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
typedef long long int LL;


char str[MAXN];
int slen;
int L[MAXN],R[MAXN];
LL dp[MAXN][10];

int stk[MAXN*5],scnt;

void DFS(int l,int r){
    if(r-l==1){
        dp[r][1]=dp[r][2]=dp[r][3]=dp[r][6]=1;
        return;
    }
    LL kk[2][10]={0};
    int si=0,di=1;
    int tl=l+1;
    while(tl<r){
        DFS(tl,R[tl]);
        tl=R[tl]+1;
    }
    for(int i=0;i<9;i++){
        kk[di][i]=dp[R[l+1]][i];
    }
    tl=R[l+1]+1;
    while(tl<r){
        swap(si,di);
        memset(kk[di],0,sizeof(kk[di]));
        for(int i=0;i<9;i++){
            int x1=i/3,y1=i%3;
            //if((x1==0&&(y1==0))
            //        ||(x1!=0&&(y1!=0)))continue;
            for(int j=0;j<9;j++){
                int x2=j/3,y2=j%3;
                //if((x2==0&&(y2==0))
                //        ||(x2!=0&&(y2!=0)))continue;
                if((y1!=0)&&(y1==x2))continue;
                int tmp=3*x1+y2;
                kk[di][tmp]=(kk[di][tmp]+kk[si][i]*dp[R[tl]][j])%MODU;
            }
        }
        tl=R[tl]+1;
    }
    for(int i=0;i<9;i++){
        int x1=i/3,y1=i%3;
        if((x1==0&&(y1==0))
                ||(x1!=0&&(y1!=0)))continue;

        for(int j=0;j<9;j++){
            int x2=j/3,y2=j%3;
            if((y1!=0)&&(y1==y2))continue;
            if((x1!=0)&&(x1==x2))continue;
            int tmp=3*x1+y2;
            dp[r][i]=(dp[r][i]+kk[di][j])%MODU;
        }
    }
}

int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    cin>>str;
    slen=strlen(str);
    scnt=-1;
    memset(L,-1,sizeof(L));
    memset(R,-1,sizeof(R));
    for(int si=0;si<slen;si++){
        if(str[si]=='('){
            stk[++scnt]=si;
        }else{
            int l=stk[scnt--];
            L[si]=l;
            R[l]=si;
        }
    }
    memset(dp,0,sizeof(dp));
    int t=0;
    while(t<slen){
        DFS(t,R[t]);
        t=R[t]+1;
    }
    LL kk[2][20]={0};
    int si=0,di=1;
    for(int i=0;i<9;i++)
        kk[di][i]=dp[R[0]][i];
    int tl=R[0]+1;
    while(tl<slen){
        swap(si,di);
        memset(kk[di],0,sizeof(kk[di]));
        for(int i=0;i<9;i++){
            int x1=i/3,y1=i%3;
            //if((x1==0&&(y1==0))
            //        ||(x1!=0&&(y1!=0)))continue;
            for(int j=0;j<9;j++){
                int x2=j/3,y2=j%3;
                //if((x2==0&&(y2==0))
                //        ||(x2!=0&&(y2!=0)))continue;
                if((y1!=0)&&(y1==x2))continue;
                int tmp=3*x1+y2;
                kk[di][tmp]=(kk[di][tmp]+kk[si][i]*dp[R[tl]][j])%MODU;
            }
        }
        tl=R[tl]+1;
    }
    LL ans=0;
    for(int i=0;i<9;i++){
        ans=(ans+kk[di][i])%MODU;
    }

    printf("%lld\n",ans);



#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
