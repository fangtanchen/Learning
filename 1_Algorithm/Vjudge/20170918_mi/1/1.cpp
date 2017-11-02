#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e6+10;

char text[MAXN];
char pattern[MAXN];
int cnt[300];
vector<int> G[300];


int DFS(char *pattern,int di,vector<int> *G,int st){
    if(pattern[di]==0){
         return st;
    }
    int tmp=pattern[di];
    int l=0,r=G[tmp].size()-1;
    while(l<=r){
         int mid=(l+r)/2;
         if(G[tmp][mid]>st){
             r=mid-1;
         }else{
              l=mid+1;
         }
    }
    if(l>=G[tmp].size()){
         return -1;
    }
    return DFS(pattern, di+1,G,G[tmp][l]);
}

int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    while(EOF!=scanf("%s%s",text,pattern)){
        for(int i=0;i<300;i++)G[i].clear();
        memset(cnt,0,sizeof(cnt));
        for(int i=0;text[i];i++){
            G[text[i]].push_back(i);
        }

        for(int i=0;pattern[i];i++){
            cnt[pattern[i]]++;
        }
        bool flag=true;
        for(int i=0;i<300;i++){
            if(cnt[i]>G[i].size()){
                flag=false;
                break;
            }
        }
        if(!flag){
            printf("-1 -1\n");
            continue;
        }
        int ans_st=-1,ans_ed=-1,ans_len=0x7fffffff;
        for(int i=0;i<G[pattern[0]].size();i++){
            int ed=DFS(pattern,1,G,G[pattern[0]][i]);
            if(ed==-1)continue;
            int len=ed-G[pattern[0]][i]+1;
            if(len<ans_len){
                 ans_len=len;
                 ans_st=G[pattern[0]][i];
                 ans_ed=ed;
            }
        }

        printf("%d %d\n",ans_st,ans_ed);
    }

#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
