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
int A[MAXN][MAXN],B[MAXN][MAXN];
int tmpM[MAXN][MAXN];
int minM[MAXN][MAXN];
int N;

void Init(){


}

void Assign(int a[][],int b[][],int ri,int ci,int len){
    for(int i=ri+len-1;i>=ri;i--){
        for(int j=ci+len-1;j>=ci;j--){
            a[i][j]=b[i][j];
        }
    }
}

void Rotate(int a[][],int ri,int ci,int len){
     int tmp1[MAXN][MAXN];
     int tmp2[MAXN][MAXN];
     for(int i=1;i<=len;i++){
         for(int j=1;j<=len;j++){
             tmp1[i][j]=a[i+ri][j+ci];
         }
     }
     for(int i=1;i<=len;i++){
         for(int j=1;j<=len;j++){
             tmp2[i][j]=a[len+1-j][i];
         }
     }
     for(int i=1;i<=len;i++){
         for(int j=1;j<=len;j++){
             a[i+ri][j+ci]=tmp2[i][j];
         }
     }
}

int Compare(int a[][],int b[][],int ri,int ci,int len){
    int imax=i+len,jmax=j+len;
    for(int i=ri;i<imax;i++){
        for(int j=ci;j<jmax;j++){
            if(a[i][j]<b[i][j])return -1;
            else if(a[i][j]>b[i][j])return 1;
        }
    }
    return 0;
}
void RotateBlock(int a[][],int ri,int ci,int len){
    int blen=len/2;
    int tmp[MAXN][MAXN];
    for(int i=ri+len-1;i>=ri;i--){
        for(int j=ci+len-1;j>=ci;j--){

        }
    }
}


void DFS(int A[][],int ri,int ci,int len){
    if(len%2==1){
        Assign(tmpM,A,ri,ci,len);
        Assign(minM,tmpM,ri,ci,len);
        for(int k=0;k<3;k++){
            Rotate(tmpM,ri,ci,len);
            if(Compare(minM,tmpM,ri,ci,len)>0){
                 Assign(minM,tmpM,ri,ci,len);
            }
        }
        Assign(A,minM,ri,ci,len);
    }else{
        int ss=len/2;
        DFS(A,ri,ci,ss);
        DFS(A,ri+ss,ci,ss);
        DFS(A,ri,ci+ss,ss);
        DFS(A,ri+ss,ci+ss,ss);
        Assign(tmpM,A,ri,ci,len);
        Assign(minM,tmpM,ri,ci,len);
        for(int k=0;k<3;k++){
             RotateBlock(tmpM,ri,ci,len);
             if(Compare(minM,tmpM,ri,ci,len)>0){
                 Assign(minM,tmpM,ri,ci,len);
             }
        }
        Assign(A,minM,ri,ci,len);
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
         for(int i=1;i<=N;i++){
             for(int j=1;j<=N;j++){
                 cin>>A[i][j];
             }
         }
         for(int i=1;i<=N;i++){
             for(int j=1;j<=N;j++){
                 cin>>B[i][j];
             }
         }
         DFS(1,1,N);
         bool flag=true;
         for(int i=1;i<=N;i++){
             for(int j=1;j<=N;j++){
                 if(A[i][j]!=B[i][j]){
                     flag=false;
                     break;
                 }
             }
             if(!flag)break;
         }
         if(flag)cout<<"Yes"<<endl;
         else cout<<"No"<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
