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
const int MAXN=2e5+10;

class Pt{
public:
    int x;
    int y;
}

Pt pts[MAXN];
int N;


int ustack[MAXN];
int top;
void Init(){
    top=-1;
}

void Push(int x){
    top++;
    ustack[top]=x;
}
int Pop(){
    int ret=ustack[top];
    top--;
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&N),N){
            Init();
            int minyi=0;
            for(int i=0;i<N;i++){
                scanf("%d%d",&pts[i].x,&pts[i].y);
                if(pts[i].y<pts[i])
            }

            if(flag){
                printf("Convex\n");
            }else{
                 printf("Concave\n");
            }
        }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
