#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<vector>
#include<string>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;
const int MAXS=26;

struct Trie{
    Trie* nxt[MAXS];
    int bleaf;// -1: nodes, >=0: leaf
    Trie(){
        memset(nxt,0,sizeof(nxt));
        bleaf=-1;
    }
};

Trie *root;
vector<string> dict;
string input;
vector<string> output;
int N;

void InsertTrie(Trie *rt,const string & str,int i,int dicti){
    if(i==str.length()){
        rt->bleaf=dicti;
        return;
    }
    if(!rt->nxt[str[i]-'a']){
        rt->nxt[str[i]-'a']=new Trie();
    }
    InsertTrie(rt->nxt[str[i]-'a'],str,i+1,dicti);
}

bool QueryTrie(Trie *rt,const string &in,int in_index,vector<string> &out){
   // printf("%d\n",in_index);
   // printf("%d\n",in_index);
    if(in_index>=in.length()){
        out.push_back(dict[rt->bleaf]);
        return true;
    }
    if(rt->bleaf!=-1){
        out.push_back(dict[rt->bleaf]);
        if(QueryTrie(root,in,in_index,out)){
             return true;
        }else{
            out.erase(out.end());
        }
    }
    if(!rt->nxt[in[in_index]-'a'])return false;
    return QueryTrie(rt->nxt[in[in_index]-'a'],in,in_index+1,out);
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>input;
    cin>>N;
    root=new Trie();
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        dict.push_back(str);
        InsertTrie(root,str,0,i);
    }
    QueryTrie(root,input,0,output);

    for(int i=0;i<output.size();i++){
         cout<<output[i]<<" ";
    }
    cout<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
