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
const int MAXN=5e3+10;

int N,K;
int len,a[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

    cin>>N>>K;
    len=0;
    int ans=N;
    for(int i=1;i<=N;i++){
         int x;
         cin>>x;
         if(x>=K){
             ans--;
         }else{
             a[len++]=x;
         }
    }
    sort(a,a+len);
    int tmp=0;
    while(len>=2){
    /*    for(int i=1;i<ni;i++){
            tmp+=a[len-i];
        }*/
        tmp+=a[len-1];
        if(a[len-2]+tmp<K){
            len--;
            continue;
        }
        if(a[0]+tmp>=K){
            ans=0;
             break;
        }
        int l=0,r=len-2;
        while(l+1<r){
             int mid=(l+r)/2;
             if(tmp+a[mid]>=K){
                 r=mid;
             }else{
                 l=mid;
             }
        }

        ans=ans-(len-r);
        len=r;
    }
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
