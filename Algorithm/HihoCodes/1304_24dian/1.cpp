#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<cmath>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAXT 110
char optype[10]="+-*/xy";
double numtype[10];
bool visited[10];
char opstack[10];
double numstack[10];

void Init(){
	memset(visited, false, sizeof(visited));
    memset(numtype,0,sizeof(numtype));

}

double  Calc(double x, double y,char op){
    double res=0;
    switch(op){
        case '+':
            res=x+y;
            break;
        case '-':
            res=x-y;
            break;
        case '*':
            res=x*y;
            break;
        case '/':
            res=x/y;
            break;
        case 'x':
            res=y-x;
            break;
        case 'y':
            res=y/x;
            break;
    }
    return res;
}

bool Calc1(){
    double res=numstack[0];
    for(int i=1;i<4;i++){
        res=Calc(res,numstack[i],opstack[i-1]);
    }
    if(fabs(res-24.0)<1e-5)return true;
    else return false;
}
bool Calc2(){
    double a1=Calc(numstack[0],numstack[1],opstack[0]);
    double a2=Calc(numstack[2],numstack[3],opstack[2]);
    double res=Calc(a1,a2,opstack[1]);
    if(fabs(res-24.0)<1e-5)return true;
    else return false;
}
bool MakeOp(int level){
    if(3==level){
        if(Calc1())return true;
        if(Calc2())return true;
        return false;
    }
    for(int i=0;i<6;i++){
         opstack[level]=optype[i];
         if(MakeOp(level+1))return true;
    }
    return false;

}


bool MakeNum(int level){
	if(4==level){
		return MakeOp(0);
	}
	for(int i=0;i<4;i++){
		numstack[level]=numtype[i];
		if(!visited[i]){
			visited[i]=true;
			if(MakeNum(level+1))return true;
			visited[i]=false;
		}
	}
	return false;
}



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        Init();
        for(int i=0;i<4;i++){
            scanf("%lf",numtype+i);
        }
        if(MakeNum(0))printf("Yes\n");
        else printf("No\n");
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
