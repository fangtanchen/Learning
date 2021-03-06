/*
 * mouse.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: fangtanchen
 */


#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>

using namespace std;

class Mouse{
public:
	int w;
	int s;
	int label;

	void set(int x,int y,int z){
		w=x;
		s=y;
		label=z;
	}
	void print(){
		cout<<w<<"  "<<s<<"  "<<label<<endl;	
	}
};
int cmp(Mouse x,Mouse y){
if(x.w<y.w)return true;
 else if(x.w==y.w&&x.s>y.s)return true;
 else return false;
}
int main(){
	Mouse mice[1005];
	int mi=0;

	while(EOF != scanf("%d",&mice[mi].w))
	{
		scanf("%d",&mice[mi].s);
		mice[mi].label=mi;
		mi++;
	}

	sort(mice,mice+mi,cmp);
	/*for(int i=0;i<mi;i++){
		mice[i].print();
	}*/
	int dp[1005][2];
	memset(dp,-1,sizeof(dp));
	dp[0][1]=-1;
	dp[0][0]=1;
	for(int i=1;i<mi;i++){
		int max=0;
		int forward_l=-1;
		for(int j=i-1;j>=0;j--){
			if(mice[i].w>mice[j].w
			&&mice[i].s<mice[j].s){
				if(max<dp[j][0]){
					max=dp[j][0];
					forward_l=j;				
				}
			}
		}
		dp[i][0]=max+1;
		dp[i][1]=forward_l;
	}
	int maxi=0;
	for(int i=1;i<mi;i++){
		if(dp[i][0]>dp[maxi][0])
			maxi=i;	
	}
	int f[1005];
	int flen=-1;
	for(int i=maxi;dp[i][1]==-1;i=dp[i][1]){
		flen++;
		f[flen]=mice[i].label;
	}
	cout<<flen+1<<endl;
	for(int i=flen;i>=0;i--){
		cout<<f[i]<<endl;
	}
//	cout<<mice[0].w<<" "<<mice[0].s<<endl;

	return 0;
}



