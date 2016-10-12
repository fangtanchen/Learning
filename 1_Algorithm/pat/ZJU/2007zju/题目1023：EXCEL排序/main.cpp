#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct student
{
	char sno[7]	;
	char name[9];
	int grade;
}Student;
Student stu[100000];

int cmp1(const void* x,const void* y)
{
	Student* px=(Student*)x;
	Student* py=(Student*)y;
	return strcmp(px->sno,py->sno);
}
int cmp2(const void* x,const void* y)
{
	Student* px=(Student*)x;
	Student* py=(Student*)y;
	int res=strcmp(px->name ,py->name  );
	
	if(res)return res;
	else return strcmp(px->sno ,py->sno);	
}

int cmp3(const void* x,const void* y)
{
	Student* px=(Student*)x;
	Student* py=(Student*)y;
	int res=px->grade-py->grade;
	
	if(res)return res;
	else return strcmp(px->sno ,py->sno);	
}

int main(int argc, char** argv) {
	int casei=1;
	int n,c;
	while(cin>>n>>c,c||n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>stu[i].sno>>stu[i].name>>stu[i].grade;
		}
		switch(c)
		{
			case 1:
				qsort(stu,n,sizeof(stu[0]),&cmp1);
				break;
			case 2:
				qsort(stu,n,sizeof(stu[0]),&cmp2);
				break;
			case 3:
				qsort(stu,n,sizeof(stu[0]),&cmp3);
				break;
			default:
				break;
		}
		//Êä³ö 
		printf("Case %d:\n",casei++);
		for(int i=0;i<n;i++)
			cout<<stu[i].sno<<" "<<stu[i].name<<" "<<stu[i].grade<<endl;
	}
	return 0;
}
