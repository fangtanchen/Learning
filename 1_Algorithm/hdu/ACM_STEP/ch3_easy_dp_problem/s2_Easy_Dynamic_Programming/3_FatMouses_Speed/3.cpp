#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

class CMouse{

public:
	int weight;
	int speed;
	int cnt;
	int prev;
	int label;
};

int cmp(CMouse x, CMouse y){
	if(x.weight<y.weight)return true;
	else if(x.weight==y.weight){
		if(x.speed>=y.speed)return true;
		else return false;
	}else{
		return false;
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	CMouse mice[1010];
	int mi=1;
	while(EOF!=scanf("%d%d",&mice[mi].weight, &mice[mi].speed)){
		mice[mi].label=mi;
		//mice[mi].prev=mi;
		mice[mi].cnt=1;
		mi++;
	}
	mi--;
	
	sort(mice+1,mice+mi+1,cmp);
	
	#ifdef U_DEBUG
	printf("test sort function\n");
	{
		for(int i=1;i<=mi;i++){
			printf("%d %d %d %d %d\n", mice[i].weight,
			mice[i].speed, mice[i].label, mice[i].cnt, mice[i].prev);
		}
	}
	#endif
	
	for(int i=2;i<=mi;i++){
		mice[i].prev=i;
		for(int j=i-1;j>=1;j--){
			if((mice[j].weight<mice[i].weight)
			&&(mice[j].speed>mice[i].speed)){
				int temp=mice[j].cnt+1;
				if(mice[i].cnt<temp){
					mice[i].cnt=temp;
					mice[i].prev=j;
				}
			}
		}
	}
	int max_cnt=mice[mi].cnt;
	int max_cnti=mi;
	
	for(int i=mi-1;i>=1;i--){
		if(max_cnt<mice[i].cnt){
			max_cnt=mice[i].cnt;
			max_cnti=i;
		}
	}
	int f[1010];
	int flen;
	for(flen=1;;flen++){
		f[flen]=mice[max_cnti].label;
		if(mice[max_cnti].prev==max_cnti){
			break;
		}
		max_cnti=mice[max_cnti].prev;
	}
	printf("%d\n",max_cnt);
	for(int i=flen;i>0;i--){
		printf("%d\n",f[i]);
	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
