#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	int A;
	while(cin>>A,A){
		int f=1;
		while(f<100){
			if(A&f)break;
			f=f<<1;
		}
		cout<<f<<endl;
	}
	return 0;
}
