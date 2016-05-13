//卡特蘭數的應用
//公式如下：(m+n)! * (m-n+1) / (m+1) 
#include <iostream>
#include <cstring>
#include<cstdio>
using namespace std;
int fact[205][100];
int res[100];
void multiply(int a[],int b)   //大數乘小數 
{
     int i,temp = 0;
     for(i = 99;i >= 0;i--)
     {
           temp += b * a[i];
           a[i] = temp % 10000;
           temp /= 10000;
     } 
}
void Fact()  //求階乘
{
     fact[0][99] = fact[1][99] = 1;
     for(int i = 2;i <= 200;i++)
     {
             memcpy(fact[i],fact[i-1],100*sizeof(int));
             multiply(fact[i],i);
     }
}
void divide(int a[],int b)       //大數除小數 
{
     int i,temp = 0;
     for(i = 0;i < 100;i++)
     {
           temp = temp*10000 + a[i];
           a[i] = temp / b;
           temp %= b;
     }
}
void output(int a[])       //輸出 
{
     int i = 0;
     while (i < 100 && a[i] == 0)
           i++;     //去掉前導的0 
     printf("%d",a[i++]);
     while(i < 100)
             printf("%04d",a[i++]);
     putchar('\n');
     
}
int main()
{
    int m,n,t = 1;
    Fact();
    while(cin >> m >> n , m+n)
    {
              printf("Test #%d:\n",t++);
              if(n > m)
              {
                   puts("0");
                   continue;
              }
              memcpy(res,fact[m+n],100*sizeof(int));
              multiply(res,m-n+1);
              divide(res,m+1);
              output(res);
    }
    return 0;
}
