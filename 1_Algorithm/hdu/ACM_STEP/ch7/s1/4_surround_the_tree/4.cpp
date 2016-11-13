#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=2e5+10;

class Node{
    public:
        int x,y;
        Node(int a=0,int b=0){
            x=a;y=b;
        }
        Node(const Node &p){
            x=p.x;y=p.y;
        }
};

Node pt[MAXN];
int N;
int stack[MAXN];
int top=0;

bool IsEmpty(){
    return top==0;
}

void Push(int x){
    top++;
    stack[top]=x;
}

int NextToTop(){
    return stack[top-1];
}
int Top(){
    return stack[top];
}
void Pop(){
    top--;
}

// true: not exchange;  false: exchange
bool Cmp(const Node &p1,const Node &p2){
    int ret=(p2.x-pt[0].x)*(p1.y-pt[0].y)
        -(p2.y-pt[0].y)*(p1.x-pt[0].x);
    return ret<0;
}
int Direction(const Node &p0,const Node &p1,const Node &p2){
    return (p2.x-p0.x)*(p1.y-p0.y)
        -(p2.y-p0.y)*(p1.x-p0.x);
}


double Distance(const Node &a,const Node &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&N),N){
            int mini=0;
            for(int i=0;i<N;i++){
                scanf("%d%d",&pt[i].x,&pt[i].y);
                if(pt[i].y<pt[mini].y){
                    mini=i;
                }
            }
            if(N==1){
                printf("%.2lf\n",0.0);
                continue;
            }else if(N==2){
                printf("%.2lf\n",Distance(pt[0],pt[1]));
                continue;
            }
            swap(pt[0],pt[mini]);
            sort(pt+1,pt+N,Cmp);
/*
            for(int i=1;i<N;i++){
                for(int j=i+1;j<N;j++){
                    printf("%d\n",Direction(pt[0],pt[i],pt[j]));
                }
            }
*/
            top=0;
            Push(0);Push(1);Push(2);
            int p1,p2;
            for(int i=3;i<N;i++){
                p2=Top();
                p1=NextToTop();
                while(Direction(pt[p1],pt[p2],pt[i])>=0){
                    Pop();
                    p2=Top();
                    p1=NextToTop();
                }
                Push(i);
            }
            int tmpx=Top();
            int a,b;
            a=Top();Pop();
            double ans=0;
            while(!IsEmpty()){
                b=Top();Pop();
                ans+=Distance(pt[a],pt[b]);
                a=b;
            }
            ans+=Distance(pt[tmpx],pt[a]);
            printf("%.2lf\n",ans);

        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
