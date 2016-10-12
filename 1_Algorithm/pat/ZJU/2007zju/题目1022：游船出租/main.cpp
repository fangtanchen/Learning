#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	char s[110][6];
	char e[110][6];
	int flag[110];
	int num;
	char keyw;
	char time[6];
	
	memset(flag,0,sizeof(flag));
	int total=0;
	int numcnt=0;
	while(cin>>num,num!=-1)
	{		
		if(!num)
		{
			if(numcnt==0)cout<<"0 0"<<endl;
			else
			{			
				cout<<numcnt<<" "<<(total+numcnt/2)/numcnt<<endl;
				memset(flag,0,sizeof(flag));
				total=0;
				numcnt=0;
			}			
		}
		cin>>keyw>>time;
		
		if(keyw=='S'&&flag[num]==0)
		{
			strcpy(s[num],time);
			flag[num]++;
		}
		else if(keyw=='E'&&flag[num]==1)
		{
			int t1=0,t2=0;
			for(int i=0;i<2;i++)
			{
				t1=((s[num][i]-'0')*60+s[num][i+3]-'0')+t1*10;
				t2=((time[i]-'0')*60+time[i+3]-'0')+t2*10;
			}
			total+=(t2-t1);			
			flag[num]=0;
			numcnt++;
		}
	}
	return 0;
}
