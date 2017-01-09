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
int N,Q;
int parent[3][MAXN];

void Init(){
    for(int i=0;i<MAXN;i++){
         parent[2][i]=parent[1][i]=i;
    }
}

int Find(int x,int st){
    int ret=x;
    while(ret!=parent[st][ret]){
        ret=parent[st][ret];
    }
    int tmp=x;
    while(tmp!=ret){
        int a=parent[st][tmp];
        parent[st][tmp]=ret;
        tmp=a;
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&Q);
    Init();
    while(Q--){
         int op,a,b;
         scanf("%d%d%d",&op,&a,&b);
         if(a>b)swap(a,b);
         int fa,fb,ma,mb,fma,fmb;
         switch(op){
             case 1:
                 fa=Find(Find(a,1),2);
                 fb=Find(Find(b,1),2);
                 if(fa!=fb){
                     if(fa>fb)swap(fa,fb);
                     parent[2][fa]=fb;
                 }
                 break;
             case 2:{
                        int i=a;
                        int pp=Find(b,1);
                        int kk=Find(pp,2);
                        while(i<=b){
                            int ma=Find(i,1);
                            int j=ma+1;
                            parent[1][ma]=pp;
                            parent[2][Find(ma,2)]=kk;
                            i=j;
                        }
                    }
                 break;
             case 3:
                 fa=Find(Find(a,1),2);
                 fb=Find(Find(b,1),2);
                 if(fa==fb)printf("YES\n");
                 else printf("NO\n");
                 break;
             default:
                 break;
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
