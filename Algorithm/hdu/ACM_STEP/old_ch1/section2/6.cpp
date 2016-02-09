#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	int t[7]={1,2,4,8,16,32,64};
	int A;
	while(cin>>A,A){
		int ans=1;
		for(int i=6;i>=0;i--){
			if(A-t[i]>0)A-=t[i];
			else if(A-t[i]==0)break;
		}
		cout<<A<<endl;
	}
	return 0;
}
