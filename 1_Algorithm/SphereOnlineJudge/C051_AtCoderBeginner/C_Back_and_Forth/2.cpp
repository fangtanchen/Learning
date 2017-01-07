#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=3000;
const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

typedef pair<int,int> pii;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int sx,sy,tx,ty;
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    for(int x=sx;x<tx;x++){
        printf("R");
    }
    for(int y=sy;y<ty;y++){
         printf("U");
    }
    for(int x=tx;x>sx;x--){
        printf("L");
    }
    for(int y=ty;y>sy;y--){
         printf("D");
    }
    printf("D");
    for(int x=sx;x<=tx;x++){
        printf("R");
    }
    for(int y=sy;y<=ty;y++)
        printf("U");
    printf("L");
    printf("U");
    for(int x=sx;x<=tx;x++){
        printf("L");
    }
    for(int y=sy;y<=ty;y++)
        printf("D");
    printf("R");



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
