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
#define parent (id>>1)

const int MAXN=1e5+10;
const int MAXM=1e5+10;

int heap[MAXN];
int N;

void PushDown(){
    int id=1;
    int idmax=heap[0]/2;
    while((id<=idmax)){
        int child=lson;
        if((rson<=heap[0])&&(heap[child]<heap[rson])){
            // rson may be smaller than heap[0],
            // lson will always exist
            child=rson;
        }
        if(heap[child]>heap[id]){
             swap(heap[child],heap[id]);
             id=child;
        }else{
            break;
        }
    }
}

void PushUp(int id){
    while(id>1) {
        if(heap[parent]>heap[id])break;
        swap(heap[parent],heap[id]);
        id=parent;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
