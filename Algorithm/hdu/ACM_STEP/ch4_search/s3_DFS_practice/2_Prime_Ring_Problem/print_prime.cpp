#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int g[55];
	memset(g,0,sizeof(g));
	for(int pi=2;pi<=50;pi++){
		int flag=1;
		for(int i=2;i<=pi/2;i++){
			if(pi%i==0){
				flag=0;
				break;
			}
		}
		if(flag){
			g[pi]=1;
		}
	}
	for(int i=0;i<55;i++){
		if(i%10==0)cout<<endl;
		cout<<g[i]<<",";
	}
}
