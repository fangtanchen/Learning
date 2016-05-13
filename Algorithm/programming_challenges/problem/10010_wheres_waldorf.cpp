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

#define MAXR 52
#define MAXC 52

char map[MAXR][MAXC];
int n,m;
const int dir[8][2]={
    {0,1},{0,-1},{1,0},{-1,0},
    {1,1},{1,-1},{-1,1},{-1,-1}
};

bool InMap(int ri,int ci){
     return (ri>=1)&&(ri<=n)&&(ci>=1)&&(ci<=m);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int can;
    scanf("%d",&can);
    for(int cani=0;cani<can;cani++){
        if(cani>0)printf("\n");
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%s",map[i]+1);
            for(int j=1;j<=m;j++){
                if(map[i][j]>='A'&&(map[i][j]<='Z')){
                    map[i][j]+=32;
                }
            }
//            printf("%s\n",map[i]+1);
        }
        int k;
        scanf("%d",&k);
        char word[100];
        for(int ki=1;ki<=k;ki++){
             scanf("%s",word);
             int len=strlen(word);
             for(int i=0;i<len;i++){
                  if((word[i]>='A')&&(word[i]<='Z'))
                      word[i]+=32;
             }
             int ans_ri=100,ans_ci=100;
             for(int di=0;di<8;di++){
                 for(int ri=1;ri<=n;ri++){
                     for(int ci=1;ci<=m;ci++){
                         bool flag=true;
                         for(int li=0;li<len;li++){
                             int tempri=ri+li*dir[di][0];
                             int tempci=ci+li*dir[di][1];
                             if((!InMap(tempri,tempci))
                                ||(map[tempri][tempci]!=word[li])){
                                  flag=false;
                                  break;
                             }
                         }
                         if(flag){
                             if(ri<ans_ri){
                                 ans_ri=ri;
                                 ans_ci=ci;
                             }else if((ri==ans_ri)&&(ci<ans_ci)){
                                 ans_ci=ci;
                             }
                         }
                     }
                 }
             }
             printf("%d %d\n",ans_ri,ans_ci);
        }

    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
