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
const int MAXN=5e4+10;
const int MAXM=5e4+10;
const int MAXS=10;




struct Node{
    int left,right,top,down;
    int numpt;
    int x[MAXS],y[MAXS];
    Node *child[4];
    bool bchild;

    Node(int a=0,int b=0,int c=0,int d=0){
         left=a;
         top=b;
         right=c;
         down=d;
         numpt=0;
         memset(child,0,sizeof(child));
         bchild=false;
    }
};

bool InNeibor(int x,int y,int cx,int cy,int r){
    return (x-cx)*(x-cx)+(y-cy)*(y-cy)<=r*r;
}

bool InMap(Node *p,int x,int y){
    return (x>=p->left)&&(x<=p->right)&&(y>=p->top)&&(y<=p->down);
}

int N,M;
Node *root;

void Init(){
     root=new Node(0,0,30000,30000);
}

void Insert(Node *rt,int x,int y){
    if(!InMap(rt,x,y))return;
    if(rt->numpt<MAXS){
        rt->x[rt->numpt]=x;
        rt->y[rt->numpt]=y;
        rt->numpt++;
        return;
    }
    if(!rt->bchild){
        int midx=(rt->left+rt->right)>>1;
        int midy=(rt->top+rt->down)>>1;
        rt->child[0]=new Node(rt->left,rt->top,midx,midy);
        rt->child[1]=new Node(midx+1,rt->top,rt->right,midy);
        rt->child[2]=new Node(rt->left,midy+1,midx,rt->down);
        rt->child[3]=new Node(midx+1,midy+1,rt->right,rt->down);
        rt->bchild=true;
    }
    for(int i=0;i<4;i++){
         Insert(rt->child[i],x,y);
    }
}


int Query(Node *rt,int a,int b,int r){
    int ret=0;
    if(max(rt->left,a-r)<=min(rt->right,a+r)
            &&(max(rt->top,b-r)<=min(rt->down,b+r))){
        for(int i=0;i<rt->numpt;i++){
            ret+=InNeibor(rt->x[i],rt->y[i],a,b,r);
        }
        if(rt->bchild){
            for(int ci=0;ci<4;ci++){
                ret+=Query(rt->child[ci],a,b,r);
            }
        }
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);
    for(int ni=0;ni<N;ni++){
         int a,b;
         scanf("%d%d",&a,&b);
         Insert(root,a,b);
    }
    for(int mi=0;mi<M;mi++){
        int a,b,r;
        scanf("%d%d%d",&a,&b,&r);
        int ans=Query(root,a,b,r);
        printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
