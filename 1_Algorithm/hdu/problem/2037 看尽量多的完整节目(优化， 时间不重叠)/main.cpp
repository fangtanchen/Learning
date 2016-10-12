#include <iostream>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct time
{
	int begin;
	int end;	
};

int main(int argc, char** argv) {
	int n;
	struct time time[100];
	while(cin>>n,n)
	{
		
		for(int i=0;i<n;i++)
		{
			cin>>time[i].begin>>time[i].end;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(time[i].end>time[j].end)
				{
					struct time temp;
					temp.begin=time[i].begin;
					temp.end=time[i].end;
					time[i].begin=time[j].begin;
					time[i].end=time[j].end;
					time[j].begin=temp.begin;
					time[j].end=temp.end;
				}
			}
		}
		
		int count=0;
		int max=0;
		for(int i=0;i<n;i++)
		{
			if(time[i].begin>=max)
			{
				max=time[i].end;
				count++;
			}
		}
		
		cout<<count<<endl;
	}
	return 0;
}
