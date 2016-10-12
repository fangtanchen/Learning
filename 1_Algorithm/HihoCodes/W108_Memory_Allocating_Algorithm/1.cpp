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
const int MAXN=2010;
const int MAXM=1e9+100;

struct Node{
    int key;
    int length;
    Node *prev;
    Node *next;

    Node(){
         key=0;
         length=0;
         prev=next=NULL;
    }
};

int N,M;
Node *head,*tail;
Node *pos[MAXN];
int res[MAXN];

void Init(int len){
     head=new Node();
     head->key=-1;
     head->length=0;
     head->prev=NULL;
     head->next=NULL;

     Node *q=new Node();
     q->key=0;
     q->length=len;
     q->prev=head;
     head->next=q;

     tail=new Node();
     tail->key=-1;
     tail->length=0;
     tail->prev=q;
     q->next=tail;
     tail->next=NULL;
}

Node *FindEmpty(int len){
    Node *tmp=head->next;
    while(tmp!=tail){
        if((tmp->key==0)&&(tmp->length>=len)){
            return tmp;
        }
        tmp=tmp->next;
    }
    return NULL;
}

int Insert(Node *block,int key,int len){
    if(block->length==len){
        block->key=key;
    }else{
        Node *tmp=new Node();
        tmp->key=0;
        tmp->length=block->length-len;
        block->key=key;
        block->length=len;
        tmp->next=block->next;
        block->next->prev=tmp;
        block->next=tmp;
        tmp->prev=block;
    }
    pos[key]=block;
}

void Delete(int key){
     Node *tmp=pos[key];
     Node *p=tmp->prev;
     if(p->key==0){
         tmp->length+=p->length;
         p->prev->next=tmp;
         tmp->prev=p->prev;
         delete p;
     }
     p=tmp->next;
     if(p->key==0){
         tmp->length+=p->length;
         p->next->prev=tmp;
         tmp->next=p->next;
         delete p;
     }
     tmp->key=0;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    Init(M);
    int k;
    int lastDeleteNum=0;
    for(int i=1;i<=N;i++){
        cin>>k;
        while(1){
            Node *tmp=FindEmpty(k);
            if(tmp){
                Insert(tmp,i,k);
                break;
            }else{
                lastDeleteNum+=1;
                Delete(lastDeleteNum);
            }
        }
    }
    Node *tmp=head->next;
    int tt=0;
    memset(res,-1,sizeof(res));
    while(tmp!=tail){
        if(tmp->key>0){
            res[tmp->key]=tt;
        }
        tt+=tmp->length;
        tmp=tmp->next;
    }
    for(int i=1;i<=N;i++){
         if(res[i]>=0)printf("%d %d\n",i,res[i]);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
