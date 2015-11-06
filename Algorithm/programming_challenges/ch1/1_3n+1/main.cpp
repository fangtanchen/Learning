#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop 
*/

int f[1000009];


int main(int argc, char** argv) {
	f[0]=0;
	f[1]=1;
	for(int i=2;i<1000000;i++){
		long long t=i;
		//int cy_now=1;
		f[i]=0;
		while(1){
			//f[i]++;
			if(t<i){
				f[i]+=f[t];
				//f[i]++;
				break;
			}
			if(t%2)t=3*t+1;
			else t/=2;			
			f[i]++;
		}
		//f[i]++;
		
	}
//	cout<<"11"<<endl;
	int m,n;
	while(cin>>m>>n){
		cout<<m<<" "<<n<<" ";
		if(m>n){
			int temp=m;
			m=n;
			n=temp;
		}
		int cy=0;
		for(int i=m;i<=n;i++){
			if(f[i]>cy)cy=f[i];
		}
		cout<<cy<<endl;
	}
	
	return 0;
}


