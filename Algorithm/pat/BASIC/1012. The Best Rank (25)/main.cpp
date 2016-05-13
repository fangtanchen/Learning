#include <iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Student
{
	char id[7];
	int g[4];	
	char c;
	int rank1;
}Student;

std::vector< Student > stu;
std::vector< int> rank1;

char s[5]="ACME";
int main(int argc, char** argv) {
	int m,n;
	while(cin>>n>>m)
	{
		stu.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>stu[i].id>>stu[i].g[1]
				>>stu[i].g[2]>>stu[i].g[3];
			stu[i].g[0]=(stu[i].g[1]+stu[i].g[2]+stu[i].g[3])/3;
			stu[i].rank1=n+5;
		}
		rank1.resize(n);
		rank1.assign(n,0);
		for(int ci=0;ci<4;ci++)
		{
			for(int i=0;i<n;i++)
			{
				rank1[i]=1;
				for(int j=0;j<n;j++)	
				{
					if(stu[j].g[ci]>stu[i].g[ci])rank1[i]++;
					if(rank1[i]>stu[i].rank1)break;
				}
				if(rank1[i]<stu[i].rank1)
				{
					stu[i].c=s[ci];
					stu[i].rank1=rank1[i];
				}
			}
		}
		for(int i=0;i<m;i++)
		{
			char p[7];
			cin>>p;
			int flag=1;
			for(int j=0;j<n;j++)
			{
				if(!strcmp(stu[j].id,p))
				{
					flag=0;
					cout<<stu[j].rank1<<" "<<stu[j].c<<endl;
				}
			}
			if(flag)cout<<"N/A"<<endl;
		}
	}
	return 0;
}
