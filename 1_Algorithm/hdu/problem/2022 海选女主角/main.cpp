#include <iostream>
#include<cmath>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m,n;
	while(cin>>m>>n)
	{
		int x=0,y=0,sco=0;
		int score;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>score;
				if(abs(score)>abs(sco))
				{
					x=i;
					y=j;
					sco=score;
				}	
			}
		}
		cout<<x<<" "<<y<<" "<<sco<<endl;
	}
	return 0;
}
