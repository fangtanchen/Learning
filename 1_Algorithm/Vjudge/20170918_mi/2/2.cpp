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
const int MAXN=1e6+10;
const int MODU=100;
int st[MAXN];
int stlen;
int N;



int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif

    while(cin>>N){
        stlen=1;
        memset(st,0,sizeof(st));
        st[0]=1;
        for(int i=2;i<=N;i++){
            int carry=0;
            for(int j=0;j<stlen;j++){
                int tmp=st[j]*i+carry;
                st[j]=tmp%MODU;
                carry=tmp/MODU;
            }
            while(carry){
                st[stlen++]=carry%MODU;
                carry/=MODU;
            }
        }
        printf("%d",st[--stlen]);
        for(int i=stlen-1;i>=0;i--){
            printf("%02d",st[i]);
        }
        printf("\n");
    }



#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

	return 0;
}
