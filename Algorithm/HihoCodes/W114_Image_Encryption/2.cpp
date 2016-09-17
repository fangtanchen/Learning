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
const int MAXN=107;

struct Rect{
    int left,right,top,down;
    Rect(){
        left=right=top=down=0;
    };
    Rect(int a,int b,int c,int d){
         left=a;top=b;
         right=c;down=d;
    }
    Rect(Rect x){
        left=x.left;
        right=x.right;
        top=x.top;
        down=x.down;
    }
};

Rect* Split(Rect x){
    int len=x.right-x.left+1;
    if(0==len%2){
        int blen=len/2;
        Rect pt[4]={
             Rect(x.left,x.top,x.left+blen-1,x.top+blen-1),
             Rect(x.left+blen,x.top,x.right,x.top+blen-1),
             Rect(x.left+blen,x.top+blen,x.right,x.down),
             Rect(x.left,x.top+blen,x.left+blen-1,x.down)
        };
        return pt;
    }
    return NULL;

}

int A[MAXN][MAXN],B[MAXN][MAXN];
int N;

void Init(){
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
}

void scanM(int a[][],int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
}


void DFS(int a[][],Rect rect){
    int len=rect.right-rect.left+1;
    if(len%2){
        int min[MAXN][MAXN];
        int tmp[MAXN][MAXN];
        Rect minRect(rect),tmpRect(rect);

        Assign(tmp,tmpRect,a,rect);
        Assign(min,minRect,tmp,tmpRect);
        for(int k=0;k<3;k++){
             Rotate(tmp,tmpRect);
             if(Compare(min,minRect,tmp,tmpRect)>0){
                 Assign(min,minRect,tmp,tmpRect);
             }
        }
        Assign(a,rect,min,minRect);
        return;
    }else{
        Rect sub[4]=Split(rect);
        for(int k=0;k<4;k++){
             DFS(a,sub[k]);
        }

        int min[MAXN][MAXN];
        int tmp[MAXN][MAXN];
        Rect minRect(rect),tmpRect(rect);

        Assign(tmp,tmpRect,a,rect);
        Assign(min,minRect,tmp,tmpRect);
        for(int k=0;k<3;k++){
             int kktt[MAXN][MAXN];
             Assign(tmp,sub[0],kktt,sub[0]);
             Assign(tmp,sub[0],tmp,sub[3]);
             Assign(tmp,sub[3],tmp,sub[2]);
             Assign(tmp,sub[2],tmp,sub[1]);
             Assign(tmp,sub[1],kktt,sub[0]);
             if(Compare(min,minRect,tmp,tmpRect)>0){
                 Assign(min,minRect,tmp,tmpRect);
             }
        }
        Assign(a,rect,min,minRect);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        Init();
        cin>>N;
        scanM(A,N);
        scanM(B,N);
        Rect Arect(1,1,N,N),Brect(1,1,N,N);
        DFS(A,Arect);
        DFS(B,Brect);
        if(0==Compare(A,B)){
             printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
