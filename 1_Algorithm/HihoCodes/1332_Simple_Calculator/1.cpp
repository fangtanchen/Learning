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

char table[7][7]={
     '>','>','<','<','<','>','>',//+;
     '>','>','<','<','<','>','>',//-;
     '>','>','>','>','<','>','>',//*
     '>','>','>','>','<','>','>',///
     '<','<','<','<','<','=',0,//(
     '>','>','>','>',0,'>','>',//)
     '<','<','<','<','<',0,'='//(
};

int Op2Int(char ch){
    switch(ch){
        case '+':
            return 0;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 3;
            break;
        case '(':
            return 4;
            break;
        case ')':
            return 5;
            break;
        case '\0':
            return 6;
            break;
        default:
            return -1;
    }
}

stack<int> numS;
stack<char> opS;

int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif

    char str[200];
    cin>>str;
    int len=strlen(str);
    opS.push('\0');
    bool flag=true;

    for(int i=0;i<=len;){
        if(str[i]>='0'&&str[i]<='9'){
            if(flag){
                numS.push(0);
                flag=false;
            }
            int tmp=numS.top();
            numS.pop();
            tmp=tmp*10+str[i]-'0';
            numS.push(tmp);
            i++;
        }else{
            flag=true;
            char op=opS.top();
            char prior=table[Op2Int(op)][Op2Int(str[i])];
            int num1,num2;
            switch(prior){
                case '<':
                    opS.push(str[i]);
                    i++;
                    break;
                case '=':
                    opS.pop();
                    i++;
                    break;
                case '>':
                    num1=numS.top();numS.pop();
                    num2=numS.top();numS.pop();
                    op=opS.top();opS.pop();
                    switch(op){
                        case '+':
                            num2+=num1;
                            break;
                        case '-':
                            num2-=num1;
                            break;
                        case '*':
                            num2*=num1;
                            break;
                        case '/':
                            num2/=num1;
                            break;
                    }
                    numS.push(num2);
                    break;
                default:
                    break;
            }
        }
    }
    cout<<numS.top()<<endl;



#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

	return 0;
}
