#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define size 1001
 
int fa[size];
int vist[size];
int N, M;
 
int find(int x)
{
    if (x== fa[x])return x;
    return fa[x] = find(fa[x]);
}
void merge(int a, int b)
{
     a = find(a);
     b = find(b);
     fa[a] = fa[b];
}
 
main()
{
      int a, b, i, j;     
      while (EOF != scanf("%d",&N) && N)
      {
             scanf("%d",&M);      
             for (i=0;i<=N; ++i)
             {
                 fa[i] = i;
                 vist[i] = 0;              
             }
             while (M--)
             {
                 scanf("%d %d",&a,&b);
                 merge(a,b);
             }
             for (i=1; i <= N; ++i)
                 vist[find(i)] = 1;
              
             for (i=1,j = 0; i <= N; ++i) 
                 if (vist[i]) j++;
             printf("%d\n",j-1);
      }
}
