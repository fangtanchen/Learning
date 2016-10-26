#include<stdio.h>
#include<string.h>

#define false 0
#define true 1

int g[4][4];
int rvis[4],cvis[4];
int ans[4][4];

void DFS(int ri){
    int i,j,ci;
    if(ri==4){
        for(i=1;i<=3;i++){
            for(j=1;j<=3;j++){
                ans[i][j]=g[i][j];
            }
        }
    }
    for(ci=1;ci<=3;ci++){
        if(cvis[ci]==true||g[ri][ci]!=-1)continue;
        g[ri][ci]=1;
        cvis[ci]=true;
        DFS(ri+1);
        cvis[ci]=false;
        g[ri][ci]=-1;
    }
}


int main(void){
    int i,ri,ci,ki,cnt;
    int pi;
    int rnum,cnum;
    memset(g,-1,sizeof(g));
    memset(rvis,false,sizeof(rvis));
    memset(cvis,false,sizeof(cvis));

    g[1][1]=0;
    g[3][1]=g[3][3]=0;

    DFS(1);

    for(ri=1;ri<=3;ri++){
        for(ci=1;ci<=3;ci++){
            printf("%d ",ans[ri][ci]);
        }
        printf("\n");
    }
    return 0;
}
