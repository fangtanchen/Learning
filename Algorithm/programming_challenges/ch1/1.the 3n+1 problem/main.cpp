#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop 
*/

//i,jҪ���Ǵ�С,���������ʱ���������i,j������� 
int main(int argc, char** argv) {

	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		cout<<m<<" "<<n<<" ";
		if(m>n){
			int temp=m;
			m=n;
			n=temp;
		}
		int cy=0;
		for(int i=m;i<=n;i++){
			long long t=i;
			int cy_now=1;
			while(t>1){
				if(t%2)t=3*t+1;
				else t/=2;			
				cy_now++;
			}
			if(cy_now>cy)cy=cy_now;
		}
		cout<<cy<<endl;
	}
	
	return 0;
}

