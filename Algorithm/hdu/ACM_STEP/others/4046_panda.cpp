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
#define MAXN 50010
#define MAXM 10010

int tree[MAXN];

int lowbit(int k){
	return k&-k;
}

int add(int k,  int a){
	while(k<MAXN){
		tree[k]+=a;
		k+=lowbit(k);
	}
	return 0;
}

int query(int k){
	int sum=0;
	while(k>0){
		sum+=tree[k];
		k-=lowbit(k);
	}
	return sum;
}

char le[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int T;
	scanf("%d", &T);
	for(int ti=1;ti<=T;ti++){
		printf("Case %d:\n", ti);
		int N, M;
		scanf("%d%d", &N, &M);
		scanf("%s", le+1);
		memset(tree, 0, sizeof(tree));
		for(int i=3;i<=N;i++){
			if(le[i]=='w'&&(le[i-1]=='b')
					&&(le[i-2]=='w')){
                add(i,1);
			}
		}
        int ty;
        for(int i=0;i<M;i++){
             scanf("%d",&ty);
             if(0==ty){
                 int l,r;
                 scanf("%d%d",&l,&r);
                 l++;r++;
                 if(r-l<2)printf("0\n");
                 else printf("%d\n",query(r)-query(l+1));
             }
             if(1==ty){
                 int k;
                 char ch;
                 scanf("%d %c",&k,&ch);
                 k++;
                 if(le[k]==ch)continue;
                 for(int p=k-2;p<=k;p++){
                     if(p<=0)continue;
                     if(p+2>N)break;
                     int t1=0,t2=0;
                     char sp[4]="wbw";
                     for(int h=0;h<3;h++){
                         int temp=p+h;
                         if(temp==k){
                              if(sp[h]==le[temp])t1++;
                              else t2++;
                         }else{
                             if(sp[h]==le[temp]){
                                  t1++;
                                  t2++;
                             }
                         }
                    }
                    add(p+2,(t2==3)-(t1==3));
                 }
                 le[k]=ch;
             }
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
