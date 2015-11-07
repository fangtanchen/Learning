#include<iostream>
#include<cstdio>

using namespace std;

int main(void){
	cout<<2992<<endl;
	for(int i=2993;i<10000;i++){
		//decimal nums
		int decsum=0;
		int hexsum=0;
		int duosum=0;
		int hexnum=i;
		int duonum=i;
		int decnum=i;

		for(int j=1;j<=4;j++){
			decsum+=(decnum%10);
			hexsum+=(hexnum%16);
			duosum+=(duonum%12);
			decnum /= (10);
			hexnum /= (16);
			duonum /=(12);
		}
		if(decsum==hexsum&&decsum==duosum)cout<<i<<endl;
	}
	return 0;
}

