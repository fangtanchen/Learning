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
    Rect(const Rect &x){
        left=x.left;
        right=x.right;
        top=x.top;
        down=x.down;
    }
};

void  Split(Rect x,Rect *rect){
    int len=x.right-x.left+1;
    if(0==len%2){
        int blen=len/2;
        rect[0]=Rect(x.left,x.top,x.left+blen-1,x.top+blen-1);
        rect[1]=Rect(x.left+blen,x.top,x.right,x.top+blen-1);
        rect[2]=Rect(x.left+blen,x.top+blen,x.right,x.down);
        rect[3]=Rect(x.left,x.top+blen,x.left+blen-1,x.down);
    }

}

int A[MAXN][MAXN],B[MAXN][MAXN];
int N;

void Init(){
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
}

void scanM(int a[MAXN][MAXN],int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
}

void Assign(int a[MAXN][MAXN],Rect aRect, int b[MAXN][MAXN],Rect bRect){
     int len=aRect.right-aRect.left+1;
     for(int i=0;i<len;i++){
         for(int j=0;j<len;j++){
             a[i+aRect.left][j+aRect.top]=
                 b[bRect.left+i][bRect.top+j];
         }
     }
}

void Rotate(int a[MAXN][MAXN],Rect aRect){
     int tmp[MAXN][MAXN];
     int tmp1[MAXN][MAXN];
     int len=aRect.right-aRect.left+1;
     Rect tmpRect(1,1,len,len);
     for(int i=1;i<=len;i++){
         for(int j=1;j<=len;j++){
             tmp[i][j]=a[aRect.left+i-1][aRect.top+j-1];
         }
     }
     for(int i=1;i<=len;i++){
         for(int j=1;j<=len;j++){
             tmp1[j][len+1-i]=tmp[i][j];
         }
     }
     Assign(a,aRect,tmp1,tmpRect);
}

int Compare(int a[MAXN][MAXN],Rect aRect,int b[MAXN][MAXN],Rect bRect){
    int len=aRect.right-aRect.left+1;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(a[aRect.left+i][aRect.top+j]>b[bRect.left+i][bRect.top+j])
                return 1;
            else if(a[aRect.left+i][aRect.top+j]<b[bRect.left+i][bRect.top+j])
                return -1;
        }
    }
    return 0;
}

void DFS(int a[MAXN][MAXN],Rect rect){
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
        Rect sub[4];
        Split(rect,sub);
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
             Assign(kktt,sub[0],tmp,sub[0]);
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
        if(0==Compare(A,Arect,B,Brect)){
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
