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
const int MAXN=1e5+10;

int N;
double T,C;
double t[MAXN],c[MAXN];

double k[MAXN],b[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    cin>>T>>C;
    for(int i=1;i<=N;i++){
         cin>>t[i]>>c[i];
    }
    int cnta=0,cntb=0,cntc=0;;
    for(int i=1;i<=N;i++){
        if(t[i]==T){
            cntc++;
        }else if(t[i]>T)cnta++;
        else cntb++;
    }
    if(cntc>0&&cntc<N){
        cout<<"Impossible"<<endl;
        return 0;
    }else if(cntc==N){
        cout<<"Possible"<<endl;
        cout<<T<<endl;
        return 0;
    }
    if(cnta&&cntb){
        cout<<"Impossible"<<endl;
        return 0;
    }

    if(cnta>0){
        int mini=1;
        for(int i=2;i<=N;i++) {
            if(t[i]<t[mini])mini=i;
        }
        swap(t[mini],t[1]);
        swap(c[mini],c[1]);
    }else{
        int maxi=1;
        for(int i=2;i<=N;i++) {
            if(t[i]>t[maxi])maxi=i;
        }
        swap(t[maxi],t[1]);
        swap(c[maxi],c[1]);
    }

    k[1]=1;b[1]=0;
    double left=C;
    double kpp=1;
    for(int i=2;i<=N;i++){
         k[i]=(t[i]-T)*c[i]/((t[1]-T))/c[1];
         b[i]=(t[i]-t[1])/(t[1]-T)*c[i];
         left-=b[i];
         kpp+=k[i];
    }
    double hlow=0;
    double hhigh=left/kpp;
    if(hhigh<0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    cout<<"Possible"<<endl;
    if(cnta>0){
        printf("%.4lf\n",t[1]);
    }else{
         printf("%.4lf\n",(T*hhigh+t[1]*c[1])/(hhigh+c[1]));
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
