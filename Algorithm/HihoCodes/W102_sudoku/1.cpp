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
#define MAXR 730
#define MAXC 325
#define MAXN 10

struct Node{
     int x,y;
     Node *left,*right,*up,*down;
};

const int MAXNUM=MAXC*MAXR;
const int N=9;
int ans[MAXN][MAXN];
int map[MAXN][MAXN];
int cnt[MAXR];
int id[MAXR][MAXC];
int mat[MAXR][MAXC];
Node *head;
Node *pq;
Node colname[MAXR];
Node nodes[MAXNUM];



void Init(){
     memset(ans,0,sizeof(ans));
     memset(cnt,0,sizeof(cnt));
     cnt[0]=100000;
     memset(id,0,sizeof(id));
     memset(mat,0,sizeof(mat));
}

//set the constraint  matrix
// row i, col j  filled with k means id=(i-1)*9+j
// position at i row; j col; p=(i-1)/3*3+(j-1)/3+1 part
// constraints: pid=(id-1)*9+k
// 1. i-th row: (i-1)*9+k
// 2. j-th col: 81+(j-1)*9+k
// 3. part : 162+(p-1)*9+k
// 4. i,j is filled 243+id
void Set(int i,int j,int k){
     int idx=(i-1)*9+j;
     int pidx=(idx-1)*9+k;
     // rows
     mat[pidx][(i-1)*9+k]=1;
     // cols
     mat[pidx][(j-1)*9+k+81]=1;
     //parts
     mat[pidx][162+((i-1)/3*3+(j-1)/3)*9+k]=1;
     // filled?
     mat[pidx][243+idx]=1;

}

void CreateMat(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j]==0){
                for(int k=1;k<=N;k++){
                     Set(i,j,k);
                }
            }else{
                Set(i,j,map[i][j]);
            }
        }
    }
}

void BuildList(){
    //InitList
    if(head)free(head);
     head=(Node*)malloc(sizeof(Node));
     pq=head;
     pq->x=pq->y=0;
     pq->left=pq->right=pq->up=pq->down=pq;
     //InitCols
     Node *pre=head;
     for(int ci=1;ci<MAXC;ci++){
         pq=colname+ci;
         pq->x=0;pq->y=ci;
         pq->left=pq->right=pq->up=pq->down=pq;
         pq->right=pre->right;
         pq->left=pre;
         pre->right->left=pq;
         pre->right=pq;
         pre=pq;
     }

     //codes the id
     int cntx=0;
     for(int ri=1;ri<MAXR;ri++){
         for(int ci=1;ci<MAXC;ci++){
             if(1==mat[ri][ci]){
                 cntx++;
                 id[ri][ci]=cntx;
                 pq=nodes+cntx;
                 pq->x=ri;pq->y=ci;
                 pq->left=pq->right=pq->up=pq->down=pq;
             }
         }
     }

     //add cols
     for(int ci=1;ci<MAXC;ci++){
          Node *pre=colname+ci;
          for(int ri=1;ri<MAXR;ri++){
              if(mat[ri][ci]){
                  Node *p=nodes+id[ri][ci];
                  p->down=pre->down;
                  p->up=pre;
                  pre->down->up=p;
                  pre->down=p;
                  pre=p;
                  cnt[ci]++;
              }
          }
     }
     //add rows
     for(int ri=1;ri<MAXR;ri++){
         Node *pre=NULL;
         for(int ci=1;ci<MAXC;ci++){
             if(mat[ri][ci]){
                 pq=nodes+id[ri][ci];
                 if(pre!=NULL){
                     pq->right=pre->right;
                     pq->left=pre;
                     pre->right->left=pq;
                     pre->right=pq;
                 }
                 pre=pq;
             }
         }
     }
}

void Remove(int col){
    Node *pre=colname+col,*pd,*pr;
    pre->right->left=pre->left;
    pre->left->right=pre->right;

    pd=pre->down;
    while(pre!=pd){
        pr=pd->right;
        while(pr!=pd){
            pr->up->down=pr->down;
            pr->down->up=pr->up;
            cnt[pr->y]--;
            pr=pr->right;
        }
        pd=pd->down;
    }
}

void Resume(int col){
     Node *pre=colname+col,*pl,*pd;
     pre->left->right=pre;
     pre->right->left=pre;

     pd=pre->down;
     while(pd!=pre){
         pl=pd->left;
         while(pl!=pd){
             pl->up->down=pl;
             pl->down->up=pl;
             cnt[pl->y]++;
             pl=pl->left;
         }
         pd=pd->down;
     }
}

Node *FindMinCol(){
    Node *p=head->right;
    Node *res=head;
    while(p!=head){
        if(cnt[p->y]<cnt[res->y]){
             res=p;
        }
        p=p->right;
    }
    return res;
}

bool Dance(int depth){
    Node *p=head->right;
    if(p==head)return true;
    p=FindMinCol();
    Node *pd=p->down;
    if(pd==p)return false;

    Remove(p->y);
    while(pd!=p){
        ans[(pd->x-1)/81+1] [((pd->x-1)/9)%9+1]=(pd->x-1)%9+1;
        Node *pr=pd->right;
        while(pr!=pd){
            Remove(pr->y) ;
            pr=pr->right;
        }
        if(Dance(depth+1))return true;
        pr=pd->left;
        while(pr!=pd){
             Resume(pr->y);
             pr=pr->left;
        }
        pd=pd->down;
    }
    Resume(p->y);
    return false;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

    int t;
    for(scanf("%d",&t);t--;){
        Init();
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                 scanf("%d",map[i]+j);
                 ans[i][j]=map[i][j];
            }
        }
        CreateMat();
        BuildList();
        if(Dance(1)){
            for(int i=1;i<=9;i++) {
                printf("%d",ans[i][1]);
                for(int j=2;j<=9;j++){
                    printf(" %d",ans[i][j]);
                }
                printf("\n");
            }
        }

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
