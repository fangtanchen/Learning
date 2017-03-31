#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;


char input[100];
int state[10],s_num,e10[10],fac_n[10];
char hash_T[400000],step[10000],hash_T2[400000];

struct inf{
     int pos;
     char mode;
};

queue<int> SQ;
queue<inf> SQ2;

int num_pos(int num,int x,int y){
     int tmp=(x-1)*3+y;
     if(tmp==num%10)return 9;
     if(tmp>num%10)return num/e10[10-tmp]%10;
     else return (num/e10[9-tmp])%10;
}

int state_pos(int num,int x,int y){
     int tmp=(x-1)*3+y;
     if(tmp==state[9])return 9;
     if(tmp>state[9])return state[tmp-1];
     else return state[tmp];
}

inline int move(int num,char op){
     int t0,t1,t2;
     switch(op){
         case 'r':if(num%10%3==0)
                      return 0;
                  else
                      return num+1;
                      break;
        case 'l':if((num-1)%10%3==0)
                     return 0;
                 else
                     return num-1;
        case 'u':
                 if(num%10-3<=0)return 0;
                 t0=9-num%10+1;
                 t1=num/e10[t0];
                 t2=t1%1000;
                 t1=t1-t2+(t2%100)*10+t2/100;
                 t1*=e10[t0];
                 return (t1+((num%e10[t0])-3));
        case 'd':
                 if(num%10+3>9)return 0;
                 t0=9-num%10+1-3;
                 t1=num/e10[t0];
                 t2=t1%1000;
                 t1=t1-t2+(t2%10)*100+t2/10;
                 t1*=e10[t0];
                 return (t1+((num%e10[t0])+3));
     }
}

bool be_solved(){
     int i,j,anti=0;
     for(i=1;i<=8;i++){
         for(j=1;j<=8;j++){
             if(state[i]<state[j])anti++;
         }
     }
     if(anti%2)return false;
     else return true;
}

inline int hash(int num){
     int dig[10],i=9,j,sum,anti;
     if(0==num)return -1;
     while(num) dig[i]=num%10,num/=10,i--;
     sum=(9-dig[9])*fac_n[8];
     for(i=1;i<9;i++){
         for(anti=0,j=1;j<i;j++){
             if(dig[i]<dig[j])anti++;
         }
         sum+=anti*fac_n[i-1];
     }
     return sum;
}



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    for(e10[0]=1,i=1;i<=9;i++)e10[i]=e10[i-1]*10;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
