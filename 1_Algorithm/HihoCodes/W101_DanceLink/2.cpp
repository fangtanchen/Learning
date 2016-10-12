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
#define MAXN 110
#define MAXM 110

struct Node{
    int x,y;
    Node *down,*left,*up,*right;
};

const int maxs=MAXN*MAXM;
int map[MAXN][MAXM];
int id[MAXN][MAXM];
int ans[maxs];
int n,m;

Node *head;
Node colname[MAXM];
Node nodes[maxs];

void Init(){
     memset(map,0,sizeof(map));
     memset(nodes,0,sizeof(nodes));
}

void Build(){
     if(head)free(head);
     head=(Node*)malloc(sizeof(Node));
     head->x=head->y=0;
     head->left=head->right=head->up=head->down=head;

     //add colname
     Node *pre=head,*p;
     for(int j=1;j<=m;j++){
         p=colname+j;
         p->x=0;p->y=j;
         p->left=p->right=p->up=p->down=p;
         p->right=pre->right;
         p->left=pre;
         pre->right->left=p;
         pre->right=p;
         pre=p;
     }
     //code id
     int cnt=0;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(1==map[i][j]){
                 cnt++;
                 id[i][j]=cnt;
                 Node *p=nodes+cnt;
                 p->x=i;
                 p->y=j;
                 p->left=p->right=p->up=p->down=p;
             }
         }
     }

     //add cols
     for(int j=1;j<=m;j++){
          Node *pre=colname+j,*p;
          for(int i=1;i<=n;i++){
              if(map[i][j]==1){
                  int pi=id[i][j];
                  p=nodes+pi;
                  p->down=pre->down;
                  p->up=pre;
                  pre->down->up=p;
                  pre->down=p;
                  pre=p;
              }
          }
     }

     //add rows
     for(int i=1;i<=n;i++){
         Node *pre=NULL, *p;
         for(int j=1;j<=m;j++){
             if(1==map[i][j]){
                 int pi=id[i][j];
                 p=nodes+pi;
                 if(pre==NULL)pre=p;
                 else{
                    p->right=pre->right;
                    p->left=pre;
                    pre->right->left=p;
                    pre->right=p;
                    pre=p;
                 }
             }
         }
     }

}

void Remove(int col){
    Node *p=colname+col,*pd,*pr;
    p->left->right=p->right;
    p->right->left=p->left;
    pd=p->down;
    while(pd!=p){
        pr=pd->right;
        while(pr!=pd){
            pr->up->down=pr->down;
            pr->down->up=pr->up;
            pr=pr->right;
        }
        pd=pd->down;
    }
}

void Resume(int col){
     Node *p=colname+col,*pd,*pr;
     p->left->right=p;
     p->right->left=p;
     pd=p->down;
     while(pd!=p){
         pr=pd->right;
         while(pr!=pd){
             pr->up->down=pr;
             pr->down->up=pr;
             pr=pr->right;
         }
         pd=pd->down;
     }
}

bool Dance(int depth){
    Node *p=head->right;
    if(p==head)return true;
    Node *p2=p->down;
    if(p2==p)return false;

    Remove(p->y);
    while(p2!=p){
        ans[depth]=p2->x;
        Node *pr=p2->right;
        while(pr!=p2){
            Remove(pr->y);
            pr=pr->right;
        }
        if(Dance(depth+1))return true;
        pr=p2->left;
        while(pr!=p2){
             Resume(pr->y);
             pr=pr->left;
        }

        p2=p2->down;
    }

    Resume(p->y);
    return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int t;
    for(scanf("%d",&t);t--;){
        Init();
         scanf("%d%d",&n,&m);
         for(int i=1;i<=n;i++){
             for(int j=1;j<=m;j++){
                 scanf("%d",map[i]+j);
             }
         }
         Build();
         if(Dance(0))printf("Yes\n");
         else printf("No\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
