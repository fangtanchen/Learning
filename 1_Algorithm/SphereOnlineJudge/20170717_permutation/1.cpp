#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;

class Solution {
    public:
        void DFS(string str,int di,set<string> &ret){
            if(di<0){
                ret.insert(str);
            }
            for(int i=di;i<str.size();i++){
                string tmp=str;
                swap(tmp[i],tmp[di]);
                if(i==di||tmp[i]!=tmp[di])DFS(tmp,di-1,ret);
            }
        }
        vector<string> Permutation(string str) {
            vector<string> ret;
            set<string>  kk;
            DFS(str,str.size()-1,kk);
            for(set<string>::iterator it=kk.begin();it!=kk.end();it++){
                ret.push_back(*it);
                 cout<<*it<<endl;
            }
            return ret;
        }
};


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Solution ans;
    ans.Permutation("aabbc");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
