#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	cin>>N;
	cin.ignore();
	char name[21][81];
	bool fail[21];
	int votes[1000][21];
	int cand[21];
	char temp[100];
	while(N--){
		
		int n;
		cin>>n;
		cin.ignore();
		
		memset(fail,0,sizeof(fail));
		memset(cand,0,sizeof(cand));
		
		for(int i=1;i<=n;i++){
			cin.getline(name[i],81);
		}
		int vote_num=0;
		while(1){
			cin.getline(temp,100);
			if(0==strlen(temp))break;
			vote_num++;
			votes[vote_num][0]=1;
			int p=0;
			for(int i=1;i<=n;i++){
				votes[vote_num][i]=0;
				while(temp[p]>='0'&&temp[p]<='9') {
					votes[vote_num][i]=votes[vote_num][i]*10+temp[p]-'0';
					p++;
				}
				p++;
			}
			cand[votes[vote_num][1]]++;
		}
		
		int win_votes=vote_num/2;
		int flag=1;
		int pnum=n;
		while(flag){
			int min_votes=vote_num;
			//判断是否有人胜出，确认最少的票数 
			for(int i=1;i<=n;i++){
				if(fail[i])continue;
				if(cand[i]>win_votes){
					flag=0;
					cout<<name[i]<<endl;
					break;
				}
				if(min_votes>cand[i])
					min_votes=cand[i];
			}
			//胜出则结束 
			if(!flag)break;
			//否则取缔失败的 
			for(int i=1;i<=n;i++){
				if(min_votes==cand[i]){
					fail[i]=1;
					//cand[i]=-1;
					pnum--;
				}
			}
			//所有人票数一样，平局 
			if(!pnum){
				for(int i=1;i<=n;i++){
					if(min_votes==cand[i]){
						cout<<name[i]<<endl;
					}
				}
				break;
			}
			
			//有人票数不一样，把 
			for(int i=1;i<=vote_num;i++){
				int k=votes[i][0];
				while(fail[votes[i][k]]){
					k++;
				}
				
				if(k!=votes[i][0]){
					cand[votes[i][k]]++;
					votes[i][0]=k;
				}
			}
			
		}
	/*	for(int i=1;i<=n;i++){
			cout<<i<<" "<<name[i]<<endl;
		}
		for(int i=1;i<=vote_num;i++){
			for(int j=0;j<=n;j++){
				cout<<votes[i][j]<<" ";
			}
			cout<<endl;
		}*/
		if(N)cout<<endl;
	}
	return 0;
}
