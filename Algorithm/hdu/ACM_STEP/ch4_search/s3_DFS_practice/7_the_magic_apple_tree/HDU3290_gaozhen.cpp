#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 20010

int fa[maxn];

int pos[maxn];

int leaf[maxn];

int ans;

int main()
{
    int N,i,m,j,b,nl,pa;
    while(scanf("%d",&N)==1)
    {
	if(N==1)
	{
	    puts("1");
	    continue;
	}
	for(i=1;i<=N;i++)
	    fa[i] = -1;
	nl = 0;
	ans = -1;
        for(i=1;i<=N;i++)
	{
	    scanf("%d",&m);
            if(m==0)
                leaf[nl++]=i;
	    else
	    {
		pos[i]=(m+1)/2;
		for(j=0;j<m;j++)
                {
		    scanf("%d",&b);
		    fa[b]=i;
		}
	    }
	}
	for(i=0;i<nl;i++)
	{
	    pa = fa[leaf[i]];
	    while(pa!=-1)
            {
		if(pos[pa]==0)
		    break;
		pos[pa]--;
		if(pos[pa]!=0)
		    break;
		pa=fa[pa];
	    }
	    if(pa==-1)
            {
		ans=leaf[i];
		break;
	    }
	}
	printf("%d\n",ans);
    }
    return 0;
}
