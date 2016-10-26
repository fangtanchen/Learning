#include<stdio.h>
#include<string.h>

#define false 0
#define true 1

int main(void){
    int g[4][4];
    int i,ri,ci,ki,cnt;
    int pi;
    int rvis[4],cvis[4];
    int rnum,cnum;
    memset(g,-1,sizeof(g));
    g[1][1]=0;
    g[3][1]=g[3][3]=0;
    for(i=0;i<3;i++){
        for(ri=1;ri<=3;ri++){
            for(ci=1;ci<=3;ci++){
                if(g[ri][ci]!=-1)continue;
                //row
                cnt=0;
                for(ki=1;ki<=3;ki++){
                    if(ki==ci)continue;
                    if(g[ri][ki]!=-1)cnt++;
                }
                if(cnt==2){
                    g[ri][ci]=0-g[ri][1]-g[ri][2]-g[ri][3];
                    if(g[ri][ci]==1){
                        for(pi=1;pi<=3;pi++){
                            g[ri][pi]=0;
                            g[pi][ci]=0;
                        }
                        g[ri][ci]=1;
                    }
                    continue;
                }
                //col
                cnt=0;
                for(ki=1;ki<=3;ki++){
                    if(ki==ri)continue;
                    if(g[ki][ci]!=-1)cnt++;
                }
                if(cnt==2){
                    g[ri][ci]=0-g[1][ci]-g[2][ci]-g[3][ci];
                    if(g[ri][ci]==1){
                        for(pi=1;pi<=3;pi++){
                            g[ri][pi]=0;
                            g[pi][ci]=0;
                        }
                        g[ri][ci]=1;
                    }
                }
            }
        }
    }
    for(ri=1;ri<=3;ri++){
        for(ci=1;ci<=3;ci++){
            printf("%d ",g[ri][ci]);
        }
        printf("\n");
    }
    return 0;
}
