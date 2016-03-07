#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int map[5][5];
	int k=10;
	scanf("%d", &k);
	while(k--){
	for(int ri=0;ri<3;ri++){
		for(int ci=0;ci<3;ci++){
			scanf("%d", &map[ri][ci]);
		}
	}
	map[1][1]=5;
	for(int ri=0;ri<3;ri++){
		for(int ci=0;ci<3;ci++){
			if(0!=map[ri][ci]){
				map[2-ri][2-ci]=10-map[ri][ci];
			}
		}
	}
	int cnt=0;
	for(int ri=0;ri<3;ri++){
		for(int ci=0;ci<3;ci++){
			if(0!=map[ri][ci]){
				cnt++;
			}
		}
	}	
	if(cnt<5){
		printf("Too Many\n");
	}else{

		int pp=3;
	while(pp--){
	for(int ri=0;ri<3;ri++){
		for(int ci=0;ci<3;ci++){
			if((map[ri][ci]==0)
					&&(map[ri][(ci+1)%3]!=0)
					&&(map[ri][(ci+2)%3]!=0)){
				map[ri][ci]=15-(map[ri][(ci+1)%3])-(map[ri][(ci+2)%3]);
			}
			
			if((map[ri][ci]==0)
					&&(map[(ri+1)%3][ci]!=0)
					&&(map[(ri+2)%3][ci]!=0)){
				map[ri][ci]=15-(map[(ri+1)%3][(ci)])-(map[(ri+2)%3][ci]);
			}
		}
	}
	}
	for(int ri=0;ri<3;ri++){
		printf("%d", map[ri][0]);
		for(int ci=1;ci<3;ci++){
			printf(" %d", map[ri][ci]);
		}
		printf("\n");
	}
	}
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
