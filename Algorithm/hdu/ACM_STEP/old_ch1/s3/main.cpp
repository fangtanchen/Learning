#include <iostream>
#include <cstdio>
#include<algorithm>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class TVShow{
public:
	int s;
	int e;
	int period;
};


int cmp(TVShow x,TVShow y){
	if(x.s>y.s)return false;
	else if(x.s==y.s&&x.period>y.period)return false;
	return true;
}

int cmp1(TVShow x, TVShow y){
	if(x.e<y.e)return true;
	else if(x.e==y.e&&x.s<y.s)return true;
	return false;
}


int main(int argc, char** argv) {
	int n;
	TVShow show[110];
	while(cin>>n,n){
		for(int i=0;i<n;i++){
			cin>>show[i].s>>show[i].e;
			show[i].period=show[i].e-show[i].s;
		}
		sort(show,show+n,cmp1);
		/**/
		for(int i=0;i<n;i++){
			cout<<show[i].s<<"  "<<show[i].period<<"  "<<show[i].e<<endl;
		}
		
		
	}
	return 0;
}
