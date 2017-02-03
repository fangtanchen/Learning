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
const int MAXN=500;

char op[MAXN];
double num[MAXN];
int optop,numtop;
char str[MAXN];

int priority[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    priority['+']=priority['-']=1;
    priority['*']=priority['/']=2;
    while(1){
        char ch;
        int x=0;
        int cnt=0;
        optop=numtop=-1;
        while(1){
            x=0;
            while(ch=getchar(),ch>='0'&&ch<='9'){
                x=x*10+ch-'0';
            }
            cnt++;
            num[++numtop]=x;
            if(ch=='\n')break;
            ch=getchar();
            if(priority[ch]<=priority[op[optop]]){
                while(priority[op[optop]]>=priority[ch]){
                    double x2=num[numtop--],x1=num[numtop--];
                    char p=op[optop--];
                    double ret;
                    switch(p){
                        case '+':
                            ret=x1+x2;
                            break;
                        case '-':
                            ret=x1-x2;
                            break;
                        case '*':
                            ret=x1*x2;
                            break;
                        case '/':
                            ret=x1/x2;
                            break;
                    }
                    num[++numtop]=ret;
                }
            }
            op[++optop]=ch;
            getchar();
        }
        if(cnt==1&&(x==0))break;
        while(numtop>0){
            double x2=num[numtop--],x1=num[numtop--];
            char p=op[optop--];
            double ret;
            switch(p){
                case '+':
                    ret=x1+x2;
                    break;
                case '-':
                    ret=x1-x2;
                    break;
                case '*':
                    ret=x1*x2;
                    break;
                case '/':
                    ret=x1/x2;
                    break;
            }
            num[++numtop]=ret;
        }
        printf("%.2lf\n",num[0]);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
