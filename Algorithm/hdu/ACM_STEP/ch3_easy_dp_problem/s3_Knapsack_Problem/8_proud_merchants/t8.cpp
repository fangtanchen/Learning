/*
 * HDU 3466
 * 需要排序的01背包
 *
 * */
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=550;
struct Node
{
	    int p,q,v;
}node[MAXN];
int dp[5500];
bool cmp(Node a,Node b)//按照 q-p 从小到大排序
{
	    return a.q-a.p < b.q-b.p;
}
int main()
{
	    int n,m;
		    while(scanf("%d%d",&n,&m)!=EOF)
			      {
					          for(int i=0;i<n;i++)
								          scanf("%d%d%d",&node[i].p,&node[i].q,&node[i].v);
							          sort(node,node+n,cmp);
									          memset(dp,0,sizeof(dp));
											          for(int i=0;i<n;i++)
														          for(int j=m;j>=node[i].q;j--)
																	            dp[j]=max(dp[j],dp[j-node[i].p]+node[i].v);
													          printf("%d\n",dp[m]);
															      }
			    return 0;
}
