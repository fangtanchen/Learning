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
const int MAXN=2e5+10;
int id[MAXN];
int weight[MAXN];
int len;
int n;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        char op;
        cin>>op;
        switch(op){
            case 'I':{
                 cin>>id[len]>>weight[len];
                 len++;
                 break;
            };
            case 'Q':{
                         int a,b;
                         cin>>a>>b;
                         long long int sum=0;
                         for(int i=0;i<len;i++){
                             if(id[i]>=a&&(id[i]<=b)){
                                 sum+=weight[i] ;
                             }
                         }
                         printf("%lld\n",sum);
                         break;
            };
            case 'M':{
                         int a,b,d;
                         cin>>a>>b>>d;
                         for(int i=0;i<len;i++){
                             if((id[i]>=a)&&(id[i]<=b)){
                                 weight[i]+=d;
                             }
                         }
                         break;

            };
            case 'D':{
                          int a,b;
                          cin>>a>>b;
                          int len2=0;
                          for(int i=0;i<len;i++){
                              if(id[i]<a||id[i]>b){
                                  id[len2]=id[i];
                                  weight[len2]=weight[i];
                                  len2++;
                              }
                          }
                          len=len2;
                          break;
            };
        }
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
