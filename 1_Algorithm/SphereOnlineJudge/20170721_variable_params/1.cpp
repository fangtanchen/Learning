#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<stdarg.h>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;


int f(int num,...){
    va_list st;
    va_start(st,num);
    int sum=0;
    for(int i=0;i<num;i++){
        int p=va_arg(st,int);
        sum+=(p) ;
    }
    va_end(st);
    return sum;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int a=1,b=2,c=3;

    cout<<f(3,a,b,c)<<endl;
    cout<<f(5,2,3,4,5,6)<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
