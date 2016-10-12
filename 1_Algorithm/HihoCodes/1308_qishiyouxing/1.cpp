#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<queue>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
int t;
char str[10];
const int dir[8][2]={{-2,-1},{-1,-2},{2,1},{1,2},
                    {-2,1},{2,-1},{1,-2},{-1,2}};
int trans[30];
bool visited[0x1<<18+5];
int step[0x1<<18+5];
const int maxp=0x3ffff;
const int minp=0x0;

queue<int> q;

bool Check(int x,int y){
    return (x>=0)&&(x<=7)&&(y>=0)&&(y<=7);
}
void BFS(int pos){
    memset(visited,false,sizeof(visited));
    memset(step,0,sizeof(step));
    while(!q.empty()){
         q.pop();
    }
    q.push(pos);
    step[pos]=0;
    while(!q.empty()){
        int tp=q.front();
        q.pop();
        if((tp&0x3f)==((tp>>6)&0x3f)
            &&((tp&0x3f)==((tp>>12)&0x3f))){
            printf("%d\n",step[tp]);
            return ;
        }
        visited[tp]=true;
        for(int i=0;i<13;i+=6){
            int tempxs=0x01<<i;
            int tempys=0x08<<i;
            int xs=(tp>>i)&0x7;
            int ys=(tp>>(i+3))&0x7;
            int ppx=tp-tempxs*xs-tempys*ys;
            for(int j=0;j<8;j++){
                int pxs=xs+dir[j][0];
                int pys=ys+dir[j][1];
                int pp=ppx+tempxs*pxs+tempys*pys;
                if(Check(pxs,pys)&&(!visited[pp])){
                     q.push(pp);
                     step[pp]=step[tp]+1;
                }
            }
        }
    }

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&t);
    while(t--){
        int npos=0;
        for(int i=0;i<3;i++){
            npos<<=6;
            scanf("%s",str);
            //printf("%s\n",str);
            npos=npos+(str[0]-'A')*8+str[1]-'1';
        }
        //printf("%o\n",npos);
        BFS(npos);

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
