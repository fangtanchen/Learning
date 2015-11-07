#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;


int main(void){
	char line[1010][5];
	int N;
	cin>>N;
	cin.ignore();
	N++;
	while(N--){
		int cmd_num=0;
		for(int i=0;;i++){
			cin.getline(line[i],5);
			if(strlen(line[i])==0)
			  break;
			cmd_num++;
			//else cout<<N<<"  "<<i<<"  "<<line[i]<<endl;
		}


	}


	return 0;
}

