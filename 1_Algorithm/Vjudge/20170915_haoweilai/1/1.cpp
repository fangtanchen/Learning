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
const int MAXN=1005;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;

struct Node{
     int data;
     Node *left,*right;
     Node(){
         data=0;
         lchild=rchild=NULL;
     }
};

Node root;
// 递归方式实现最大值查找
// rec记录当前位置的权值和
// max_val记录历史上根到页节点的权值和
void Search_Recursion(Node *root, int rec,int &max_val){
    if(!root){
        if(max_val<rec){
            max_val=rec;
        }
        return;
    }
    rec+=root->val;
    Search_Recursion(root->left,rec,max_val);
    Search_Recursion(root->right,rec,max_val);
    return;
}


// 迭代方式实现最大值查找
//

void Search_Iteration(Node *root,int &max_val){
    max_val=0;
    if(!root)return;
    stack<pair<Node*,int> > S;
    S.push(make_pair(root,root->data));
    while(!S.empty()){
        pair<Node *,int> cur=S.top();
        S.pop();
        Node *cur_node=cur.first;
        int tmp_val=cur->second;
        if(cur!=NULL){
             S.push(cur_node->right);
             S.push(cur_node->left);
        }else{
            if(tmp->val>max_val){
                max_val=tmp_val;
            }
        }

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
