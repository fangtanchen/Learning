#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#pragma warning(disable:4996)
#endif


#include <iostream>
#include<vector>
#include<iterator>
#include<cmath>
#include<algorithm>
#include<cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;

void print_coll(const vector<int>& coll){
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout, " "));
	cout<<endl;
}

int main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int n;
	while(cin>>n){
		vector<int> coll(n);
		vector<bool> digit(n-1,false);
		for(int i=0;i<n;i++)
			cin>>coll[i];
		bool is_jolly=true;
		for(int i=1;i<n;i++){
			int d=abs(coll[i]-coll[i-1])-1;
			if(d<0||d>=n-1){
				is_jolly=false;
				break;
			}
			digit[d]=true;
		}
		if(is_jolly){
			if(find(digit.begin(),digit.end(),false)!=digit.end())
				is_jolly=false;
		}
		if(is_jolly)	cout<<"Jolly"<<endl;
		else cout<<"Not jolly"<<endl;
		
	}
#ifndef ONLINE_JUDEGE
	fclose(stdin);
	fclose(stdout);
	system("in.txt");
	system("out.txt");
#endif
	return 0;
}
