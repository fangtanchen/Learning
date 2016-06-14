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
#define MAXN 105
#define MAXM 105

struct Node{
    int x,y;
    Node*up,*dn,*lf,*rt;
};

int n,m;
int map[MAXN][MAXM];
int id[MAXN][MAXM];
Node nodes[MAXN*MAXM];
Node head;
Node colname[MAXM];

void Init(){
    memset(map,0,sizeof(map));
    memset(id,-1,sizeof(id));
    memset(nodes,0,sizeof(nodes));
}

void Build(){
    head.x=head.y=0;
    head.up=head.dn=head.lf=head.rt=&head;

    Node* pre=&head,*p;
    for(int mi=1;mi<=m;mi++){
        p=&colname[mi];
        p->x=0;p->y=mi;
        p->up=p->dn=p;
        p->rt=pre->rt;
        p->lf=pre;
        pre->rt->lf=p;
        pre->rt=p;
        pre=p;
    }
    int cnt=0;
    for(int ni=1;ni<=n;ni++){
        for(int mi=1;mi<=m;mi++){
            if(map[ni][mi]==1){
                cnt++;
                id[ni][mi]=cnt;
                nodes[cnt].x=ni;
                nodes[cnt].y=mi;
                nodes[cnt].lf=nodes[cnt].rt
                    =nodes[cnt].up=nodes[cnt].dn=&nodes[cnt];
            }
        }
    }

    for(int j=1;j<=m;j++){
        Node *pre=&colname[j],*p;
        for(int i=1;i<=n;i++){
            if(map[i][j]==1){
                int pi=id[i][j];
                p=&nodes[pi];
                p->dn=pre->dn;
                p->up=pre;
                pre->dn->up=p;
                pre->dn=p;
                pre=p;
            }
        }
    }
    for(int i=1;i<=n;i++){
        Node *pre=NULL,*p;
        for(int j=1;j<=m;j++){
            if(map[i][j]==1){
                int pi=id[i][j];
                p=&nodes[pi];
                if(pre==NULL)pre=p;
                else{
                    p->rt=pre->rt;
                    p->lf=pre;
                    pre->rt->lf=p;
                    pre->rt=p;
                    pre=p;
                }
            }
        }
    }
}

void Remove(int col){
     Node *p=colname+col;
     p->lf>rt=p->rt;
     p->rt->lf=p->lf;
     Node *p2=p->dn;
     while(p2!=p){
         Node *pr=p2->rt;
         while(pr!=p2){
             pr->up->dn=pr->dn;
             pr->dn->up=pr->up;
              pr=pr->rt;
         }
         p2=p2->dn;
     }
}

void Resume(int col){
     Node *p=colname+col;
     p->lf->rt=p;
     p->rt->lf=p;
     Node *p2=p->dn;
     while(p2!=p){
         Node *pr=p2->rt;
         while(pr!=p2){
             pr->up->dn=pr;
             pr->dn->up=pr;
             pr=pr->rt;
         }
         p2=p2->dn;
     }
}

bool Dance(int depth){
    Node *p=head.rt;
    if(p==&head)return true;
    Node *p2=p.dn;
    if(p2==p)return false;

    Remove(p2.y);

}



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int t;
    scanf("%d",&t);
    while(t--){
        Init();
         scanf("%d%d",&n,&m);
         for(int i=1;i<=n;i++){
             for(int j=1;j<=m;j++){
                 scanf("%d",map[i]+j);
             }
         }
         Build();
         Dance(1);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
