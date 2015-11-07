#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib> 
#include<fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student
{
	char name[100];
	int age;
	int grade;
};

int main(int argc, char** argv) {
	/*FILE* fp = fopen("std.dat","wb");
	struct student stu;
	while(cin>>stu.name>>stu.age>>stu.grade ,stu.age)
	{
		fwrite(&stu,sizeof(stu),1,fp);		
	}
	fclose(fp);
	return 0;*/
	FILE* fp=fopen("std.dat","rb+");
	if(!(fp))exit(0);
	struct student stu[110] ;
	memset(stu,0,sizeof(stu));
	fseek(fp,0,SEEK_SET);
	fseek(fp,0,SEEK_END);
	int len=ftell(fp);
	
	fseek(fp,0,SEEK_SET);
	fread(stu,len,1,fp);
	
	fclose(fp);
	int count=len/sizeof(stu[0]);
	for(int i=0;i<count;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(stu[i].grade<stu[j].grade)
			{
				struct student s;
				strcpy(s.name,stu[i].name );
				s.age=stu[i].age;
				s.grade=stu[i].grade;
				strcpy(stu[i].name ,stu[j].name );
				stu[i].age=stu[j].age;
				stu[i].grade=stu[j].grade;
				strcpy(stu[j].name,s.name );
				stu[j].age=s.age;
				stu[j].grade=s.grade;				
			}
		}
	}
	fstream file;
	file.open("pass.txt",ios::out);
	for(int i=0;i<count;i++)
	{
		if(stu[i].grade<60)break;
		cout<<stu[i].name<<"  "<<stu[i].age<<"  "<<stu[i].grade<<endl;
		file<<stu[i].name<<"  "<<stu[i].age<<"  "<<stu[i].grade<<endl;
	}
	file.close();
}
