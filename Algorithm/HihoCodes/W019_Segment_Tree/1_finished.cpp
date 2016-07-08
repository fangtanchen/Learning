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
const int MAXN=1000010;
const int MAXP=2000020;

struct Node{
     int l,r;
     int val;
     int lch,rch,fa;

     Node(){
         l=r=val=lch=rch=fa=0;
     }
};

Node nodes[MAXP];
int weights[MAXN];
int numnodes;
int numleaf;
int N,Q;
int root;


void Init(){
    numnodes=N+1;
    root=N+1;
    numleaf=1;
}
int GenerateTree(int ni){
    int len=nodes[ni].r-nodes[ni].l+1;
    if(len==1){
        return 0;
    }
    int len1=len/2;
    int len2=len-len1;
    if(len1>1){
        numnodes++;
        nodes[ni].lch=numnodes;
        nodes[numnodes].fa=ni;
        nodes[numnodes].l=nodes[ni].l;
        nodes[numnodes].r=nodes[ni].l+len1-1;
        GenerateTree(numnodes);
    }else{
        int k=nodes[ni].l;
        nodes[ni].lch=k;
        nodes[k].fa=ni;
    }
    if(len2>1){
        numnodes++;
        nodes[ni].rch=numnodes;
        nodes[numnodes].fa=ni;
        nodes[numnodes].r=nodes[ni].r;
        nodes[numnodes].l=nodes[ni].l+len1;
        GenerateTree(numnodes);
    }else{
        int k=nodes[ni].r;
        nodes[ni].rch=k;
        nodes[k].fa=ni;
    }
    int lch=nodes[ni].lch;
    int rch=nodes[ni].rch;
    nodes[ni].val=min(nodes[lch].val,nodes[rch].val);
}

int PostOrder(int id){
    if(nodes[id].l==nodes[id].r){
        return nodes[id].val;
    }
    int lch=nodes[id].lch;
    int rch=nodes[id].rch;
    PostOrder(nodes[id].lch);
    PostOrder(nodes[id].rch);
    nodes[id].val=min(nodes[lch].val,nodes[rch].val);
}

int Modify(int id){
    if(id==0)return 0;
    int fa=nodes[id].fa;
    int lch=nodes[fa].lch;
    int rch=nodes[fa].rch;
    nodes[fa].val=min(nodes[lch].val,nodes[rch].val);
    Modify(fa);
    return 0;
}

int Query(int id,int A,int B){
    if(nodes[id].l==A && nodes[id].r==B)
        return nodes[id].val;
    int len=nodes[id].r-nodes[id].l+1;
//    if(len==1)return nodes[id].val;

    int mid=nodes[id].l+len/2;
    if(B<mid)return  Query(nodes[id].lch,A,B);
    else if(A>=mid)return Query(nodes[id].rch,A,B);
    else {
        int k1=Query(nodes[id].lch,A,mid-1);
        int k2=Query(nodes[id].rch,mid,B);
        return min(k1,k2);
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    Init();
    for(int i=1;i<=N;i++){
        scanf("%d",&nodes[i].val);
        nodes[i].l=nodes[i].r=i;
    }

    nodes[root].l=1;
    nodes[root].r=N;
    GenerateTree(root);
    scanf("%d",&Q);
    while(Q--){
         int op,a,b;
         scanf("%d%d%d",&op,&a,&b);
         switch(op){
             case 0:
                 printf("%d\n",Query(root,a,b));
                 break;
             case 1:
                 nodes[a].val=b;
                 Modify(a);
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
