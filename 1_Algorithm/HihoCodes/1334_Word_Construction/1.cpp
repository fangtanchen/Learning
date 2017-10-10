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
const int MAXN=105;

int id[MAXN],id_cnt;
char str[MAXN];
int N;


void DFS(int *arr,int length,int max_level,int li,int di,int mask,int &ans){
    if(li==length){
        ans=max(ans,di);
        return;
    }
    if(di==max_level){
        ans=max(ans,di);
        return;
    }
    for(int i=li;i<length;i++){
        if(mask&arr[i])continue;
        DFS(arr,length,max_level,i+1,di+1,mask|arr[i],ans);
    }
    ans=max(ans,di);
}

int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    id_cnt=0;
    cin>>N;
    for(int i=0;i<N;i++){
         cin>>str;
         id[id_cnt]=0;
         for(int j=0;str[j];j++){
             id[id_cnt]|=(1<<(str[j]-'a'));
         }
         id_cnt++;
    }
    int ans=0;
    DFS(id,id_cnt,6,0,0,0,ans);
    cout<<ans<<endl;

#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
