#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	char str[300];
	while(cin.getline(str,300,'\n'),str[0]!='#'){
		int sum=0;
		int len=strlen(str);
		for(int i=0;i<len;i++){			
			if(str[i]==' ') continue;
			sum=sum+(i+1)*(str[i]-'A'+1);
		}
		cout<<sum<<endl;
	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
