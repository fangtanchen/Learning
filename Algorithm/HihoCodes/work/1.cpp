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

void exchange(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int N;
    int digit[10];
    while(cin>>N){
        int tmp=N;
        int di=0;
        if(N<0)tmp=-tmp;
        while(tmp){
             digit[di]=tmp%10;
            tmp/=10;
             di++;
        }
        if(N>0) {
            for(int i=0;i<di;i++){
                for(int j=i+1;j<di;j++){
                    if(digit[i]>digit[j]){
                        exchange(digit[i],digit[j]);
                    }
                }
            }
            for(int i=0;i<di;i++){
                if(digit[i]!=0){
                    exchange(digit[i],digit[0]);
                    break;
                }
            }
        }else if(N<0){
            for(int i=0;i<di;i++){
                for(int j=i+1;j<di;j++){
                    if(digit[i]<digit[j]){
                        exchange(digit[i],digit[j]);
                    }
                }
            }
        }
        int ret=0;
        for(int i=0;i<di;i++){
            ret=ret*10+digit[i] ;
        }
        if(N<0)ret=-ret;
        cout<<ret<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
