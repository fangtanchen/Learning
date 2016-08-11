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
#define lson (id<<1)
#define rson ((id<<1)|1)
#define parent (id/2)

const int MAXN=1e5+10;
const int MAXW=1e5+10;

int weight[MAXN];
int N,M;
int num_weight;

void Init(){
     memset(weight,0,sizeof(weight));
     num_weight=0;
}

void Adjust(int st){
    int id=st;
    while(id>1){
        if(weight[parent]<weight[id]){
            swap(weight[parent],weight[id]);
        }else{
            break;
        }
        id=parent;
    }
}

int Delete(){
    swap(weight[1],weight[num_weight]);
    int ret=weight[num_weight];
    weight[num_weight]=0;
    num_weight--;
    int id=1;
    int idmax=num_weight/2;
    while(id<=idmax){
        int child=lson;
        if(weight[rson]>weight[child]){
            child=rson;
        }
        if(weight[id]<weight[child]){
            swap(weight[id],weight[child]);
            id=child;
        }else{
            break;
        }
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++){
         char ch;
         int w;
         cin>>ch;
         switch(ch){
             case 'A':
                 cin>>w;
                 num_weight++;
                 weight[num_weight]=w;
                 Adjust(num_weight);
                 break;
             case 'T':
                 cout<<Delete()<<endl;
                 break;
             default:
                 break;
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
