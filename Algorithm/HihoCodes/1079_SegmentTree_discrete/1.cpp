#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;
const int MAXL=1e9+10;

struct Node{
    int l,r;
    int lazy;
    Node *lch,*rch;
    Node(int x,int y){
        l=x;r=y;
        lazy=0;
        lch=rch=NULL;
    }
}*root;


int a[2*MAXN];
int b[2*MAXN];
map<int,int> c;
int N,M;

void Build(int l,int r){
    root=new Node(l,r);
    queue<Node> qe;
    qe.push(root);
    while(!qe.empty()){
         Node *tmp=qe.front();
         qe.pop();
         if(tmp->r==tmp->l+1)continue;
         int mid=(tmp->l+tmp->r)/2;
         tmp->lch=new Node(tmp->l,mid);
         tmp->rch=new Node(mid,tmp->r);
         qe.push(tmp->lch);
         qe.push(tmp->rch);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    int imax=2*N;
    for(int i=0;i<imax;i+=2){
         cin>>a[i]>>a[i+1];
         b[i]=a[i];b[i+1]=a[i+1];
    }
    sort(b,b+imax);
    int ci=1;
    map<int,int>::iterator it;
    for(int i=0;i<imax;i++){
        if(c.find(b[i])==c.end()){
             c[b[i]]=ci++;
        }
    }
    int tmax=ci-1;
    int tmin=1;
    Build(tmin,tmax);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
