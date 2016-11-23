#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=5e4+10;
const int MAXM=5010;
const int NODE_CAPACITY=10;


class Point{
public:
    int x,y;
    Point(int a=0,int b=0){
         x=a;y=b;
    }

    Point(const Point& p){
        x=p.x;
        y=p.y;
    }
};

class QuadtreeNode{
    public:
        int left,top,right,down;
        Point pts[NODE_CAPACITY];
        int num_pts;
        QuadtreeNode* childNode[4];
        bool isDivided;
        QuadtreeNode(int l,int t,int r,int d){
             left=l;top=t;right=r;down=d;
             num_pts=0;
             isDivided=false;
             memset(childNode,0,sizeof(childNode));
        }
};

QuadtreeNode *root;
int N,M;


bool InRange(QuadtreeNode* root,int x,int y){
    return (x>=root->left)&&(x<=root->right)&&(y<=root->down)&&(y>=root->top);
}

void Insert(QuadtreeNode* root,int x,int y){
    if(!InRange(root,x,y))return;
    if(root->num_pts<NODE_CAPACITY){
        root->pts[root->num_pts].x=x;
        root->pts[root->num_pts].y=y;
        root->num_pts++;
        return;
    }
    if(!root->isDivided){
        root->isDivided=true;
        int midx=(root->left+root->right)/2;
        int midy=(root->top+root->down)/2;

        root->childNode[0]=new QuadtreeNode(
                root->left,root->top,midx,midy);
        root->childNode[1]=new QuadtreeNode(
                midx+1,root->top,root->right,midy);
        root->childNode[2]=new QuadtreeNode(
                root->left,midy+1,midx,root->down);
        root->childNode[3]=new QuadtreeNode(
                midx+1,midy+1,root->right,root->down);
    }
    for(int i=0;i<4;i++){
         Insert(root->childNode[i],x,y);
    }
}

int a,b,r;
int Query(QuadtreeNode* root,int left,int top,int right,int down){
    int ret=0;
    //int midx=(left+right)/2;
    //int midy=(top+down)/2;
    if(!((max(left,root->left)<min(right,root->right))
                &&(min(down,root->down)>max(top,root->top)))){
        return ret;
    }
    for(int i=0;i<root->num_pts;i++){
        Point p=root->pts[i];
        if((p.x-a)*(p.x-a)+(p.y-b)*(p.y-b)<=r*r){
            ret++;
        }
    }
    if(root->isDivided){
        for(int i=0;i<4;i++){
            ret+=Query(root->childNode[i],left,top,right,down);
        }
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    root=new QuadtreeNode(0,0,30000,30000);
    for(int i=0;i<N;i++){
         int x,y;
         scanf("%d%d",&x,&y);
         Insert(root,x,y);
    }
    for(int mi=0;mi<M;mi++){
         //int a,b,r;
         scanf("%d%d%d",&a,&b,&r);
         int ans=Query(root,a-r,b-r,a+r,b+r);
         printf("%d\n",ans);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
