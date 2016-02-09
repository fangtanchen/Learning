#include <iostream>
#include<cstdio> 
#include<cstdlib>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct stu
{
	int l,w;
}Lode;

Lode s[5005];

int cmp(const void* a,const void *b)
{
	Lode *c,*d;
	c=(Lode*)a;
	d=(Lode*)b;
	if(c->l!=d->l)
		return d->l-c->l;
	else return d->w-c->w;
}

int main(int argc, char** argv) {
	int t,n,i,j,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&s[i].l,&s[i].w);
		qsort(s,n,sizeof(s[0]),cmp);
		ans=n;
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(s[j].l>=s[i].l&&s[j].w>=s[i].w)
				{
					ans--;
					s[j].l=s[i].l;
					s[j].w=s[i].w;
					s[i].l=0;
					s[i].w=0;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
