#include <iostream>
#include<cmath>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int diff[3100];
	int count=0;
	while(cin>>n){
		memset(diff,0,sizeof(diff));
		count=0;
		int a,b;
		cin>>a;
		for(int i=2;i<=n;i++){
			cin>>b;
			if(0==diff[(int)abs(a-b)]){
				diff[(int)abs(a-b)]=1;
			}
			a=b;
		}
		for(int i=n-1;i>0;i--)
			count+=(diff[i]);
		if(count<n-1)cout<<"Not jolly"<<endl;
		else cout<<"Jolly"<<endl;
	}
	return 0;
}
