#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
	int n;
	while(EOF!=scanf("%d\n",&n)){
		int radix;
		char digits[15];
		char str[25];
		int ans=0;
		while(n--){
			cin.getline(digits,15,'(');
			cin>>radix;
			cin.getline(str,20);
			int len=strlen(digits);
			int num=0;
			for(int i=0;i<len;i++){
				num=num*radix+digits[i]-48;
			}
			ans+=num;
		}
		cout<<ans<<endl;
	}

	return 0;
}
