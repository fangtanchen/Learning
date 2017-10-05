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

char a[MAXN],b[MAXN];
char c[MAXN];
char tmp[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        cin>>a>>b;
    int alen=strlen(a);
    int blen=strlen(b);
    for(int i=0,j=alen-1;i<=j;i++,j--)
        swap(a[i],a[j]);
    for(int i=0,j=blen-1;i<=j;i++,j--)
        swap(b[i],b[j]);
    for(int i=0;i<alen;i++)a[i]-='0';
    for(int i=0;i<blen;i++)b[i]-='0';
    int clen=0;
    for(int ai=0;ai<alen;ai++){
        if(a[ai]==0)continue;
        memset(tmp,0,sizeof(tmp));
        int carry=0;
        int tmpi=ai;
        for(int bi=0;bi<blen;bi++){
            int kk=b[bi]*a[ai]+carry;
            tmp[tmpi]=kk%10;
            carry=kk/10;
            tmpi++;
        }
        if(carry)tmp[tmpi++]=carry;
        carry=0;
        for(int ti=0;ti<tmpi;ti++){
            int kk=c[ti]+tmp[ti]+carry;
            c[ti]=kk%10;
            carry=kk/10;
        }
        if(carry)c[tmpi++]=carry;
        clen=max(clen,tmpi);
    }
    for(int i=0,j=clen-1;i<=j;i++,j--){
         swap(c[i],c[j]);
    }
    for(int i=0;i<clen;i++)c[i]+='0';
    cout<<c<<endl;





	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
