#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=210;
const int Sys=137;
const int rod=961211;
const char opr[10][4]={"","+","-","*","/","if","let","<",">","="};
const int Count[10]={0,2,2,2,2,3,2,2,2,2};

int n,top,topvar;
char s[maxn];

struct Data
{
       int num,flag;
       Data(int _num=0,int _flag=0)
       {
           num=_num; flag=_flag;
       }
};

struct Stack
{
       int k,d; Data v[4];
}stk[maxn],stkvar[maxn];

bool check(int k,int flag)
{
     return flag && ((1<=k && k<=4) || k>=7);
}

Data calc(Stack exp)
{
     Data Tas;
     for(int i=1;i<=Count[stk[top].k];i++)
         if(check(stk[top].k,stk[top].v[i].flag)) {Tas.flag=-1; return Tas;}

     switch(exp.k)
     {
         case 1: Tas.num=exp.v[1].num+exp.v[2].num; break;
         case 2: Tas.num=exp.v[1].num-exp.v[2].num; break;
         case 3: Tas.num=exp.v[1].num*exp.v[2].num; break;
         case 4: 
                 if(!exp.v[2].num) {Tas.flag=-2; return Tas;}
                 Tas.num=exp.v[1].num/exp.v[2].num;
                 break;
         case 5: Tas=(exp.v[1].num)?exp.v[2]:exp.v[3]; break;
         case 6: Tas=exp.v[2]; topvar--; break;
         case 7: Tas.num=(exp.v[1].num<exp.v[2].num); break;
         case 8: Tas.num=(exp.v[1].num>exp.v[2].num); break;
         case 9: Tas.num=(exp.v[1].num==exp.v[2].num); break;
     }
     if(exp.k<=4) Tas.flag=0;
     if(exp.k>=7) Tas.flag=1;
     return Tas;
}

bool checkif(Stack exp)
{
     return exp.k==5 && ((exp.v[1].num && exp.d==3) || (!exp.v[1].num && exp.d==2));
}

void work()
{
     n=strlen(s);
     top=topvar=0; stk[0].k=0; stk[0].d=1;
     for(int i=0,j=0;i<n;i=j+1,j=i)
     {
         if(s[i]==' ') continue;
         if(s[i]=='(')
         {
            if(checkif(stk[top]))
            {
               int top2=1; j++;
               while(top2>0)
               {
                     while(j<n && s[j]!='(' && s[j]!=')') j++;
                     if(s[j++]=='(') ++top2; else --top2;
               }
               stk[top].d++;
               continue;
            }

            top++; j=i+2;
            int flag=0,num=0;
            for(;j<n && s[j]!=' ';j++) num=(num*Sys+s[j])%rod;
            for(int k=1;k<=9;k++)
                if(strncmp(s+i+2,opr[k],j-i-2)==0)
                   stk[top].k=k,stk[top].d=1,flag=1;
            if(!flag) stk[top].k=10,stk[top].d=1,stk[top].v[0].num=num;
            continue;
         }
         if(s[i]==')')
         {
            if(stk[top].k==10)
            {
               int num=stk[top].v[0].num;
               stkvar[++topvar].k=num; stkvar[topvar].d=stk[top].v[1].num;
               --top; stk[top].v[stk[top].d].num=num; stk[top].d++;
               continue;
            }
            Data val=calc(stk[top]); --top;

            if(val.flag==-1)
            {
               printf("Type Mismatch\n");
               return;
            }
            if(val.flag==-2)
            {
               printf("Division By Zero\n");
               return;
            }

            stk[top].v[stk[top].d]=val; stk[top].d++;
            continue;
         }

         int num=0,flag;
         for(;j<n && s[j]!=' ';j++)
             if('0'<=s[j] && s[j]<='9') num=num*10+s[j]-'0',flag=0;
                else num=(num*Sys+s[j])%rod,flag=1;

         if(checkif(stk[top])) {stk[top].d++; continue;}

         if(strncmp(s+i,"false",j-i)==0) num=0,flag=2;
         if(strncmp(s+i,"true",j-i)==0) num=1,flag=2;
         if(flag==1)
         {
            for(int k=topvar;k>=1;k--)
                if(stkvar[k].k==num) {num=stkvar[k].d; flag=0; break;}
            if(flag)
            {
               printf("Unbound Identifier\n");
               return;
            }
         }
         flag=(flag>0);

         if(stk[top].k==5 && stk[top].d==1 && !flag)
         {
            printf("Type Mismatch\n");
            return;
         }

         stk[top].v[stk[top].d]=Data(num,flag);
         stk[top].d++;
     }

     if(stk[0].v[1].flag==1)
        if(stk[0].v[1].num) printf("true\n"); else printf("false\n");
     else printf("%d\n",stk[0].v[1].num);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int TT;
    scanf("%d",&TT); getchar();
    for(int i=1;i<=TT;i++)
    {
        gets(s);
        work();
    }
    return 0;
}