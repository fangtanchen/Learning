#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<stack>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;

stack<int> numS;
stack<char> opS;

char str[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
        //while(1){
	#endif
    cin>>str;
    while(!opS.empty())opS.pop();
    while(!numS.empty())numS.pop();
    int tmp=0;
    int len=strlen(str);
    for(int i=0;i<=len;i++){
        if(str[i]>='0'&&str[i]<='9'){
            tmp=tmp*10+str[i]-'0';
        }else{
            if(str[i]=='('){
                opS.push(str[i]);
                tmp=0;
                continue;
            }
            while((!opS.empty())
                    &&(opS.top()=='*'||opS.top()=='/')){
                int num=numS.top();
                char op=opS.top();
                opS.pop();
                numS.pop();
                if(op=='*')tmp*=num;
                if(op=='/')tmp=num/tmp;
            }
            if(str[i]==')'||0==str[i]){
                while(!opS.empty()
                        &&(opS.top()!='(')){
                     char op=opS.top();
                     int num=numS.top();
                     opS.pop();
                     numS.pop();
                     if(op=='+'){
                          tmp=num+tmp;
                     }else if(op=='-'){
                         tmp=num-tmp;
                     }
                }
                if(!opS.empty())opS.pop();
                continue;
            }
            numS.push(tmp);
            opS.push(str[i]);
            tmp=0;
        }
    }
    cout<<tmp<<endl;

	#ifdef L_JUDGE
//}
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
