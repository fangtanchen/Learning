#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MIN(a, b) ((a)<(b)?(a):(b))
#define MAX(a, b) ((a)>(b)?(a):(b))

char instr[1000010];
char str[2000010];
int f[1000010];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int N;
	scanf("%d", &N);
	while(N--){
		scanf("%s", instr);
		int len=strlen(instr);
		memset(str, ',', sizeof(str));
		for(int i=0, j=1;i<len;i++, j+=2){
			str[j]=instr[i];
		}
		len=2*len+1;
		memset(f, 0, sizeof(f));
		f[0]=1;
		int max_res=1;
		for(int mid=1;mid<len;mid++){
			int maxj=mid-1;
			int max_bo=maxj+f[maxj]/2;
			for(int j=mid-2;j>=0;j--){
				if(j+f[j]/2>max_bo){
					max_bo=j+f[j]/2;
					maxj=j;
				}
			}
			int f_min=1;
			if(2*maxj>=mid){
				MIN(f[2*maxj-mid], f[maxj]-2*(mid-maxj));
			}
			f[mid]=f_min;
			for(int st=mid-f_min/2-1, ed=mid+f_min/2+1;
					(st>=0)&&(ed<len);st--, ed++){
				if(str[st]==str[ed]){
					f[mid]+=2;
				}else{
					break;
				}
			}
			if(max_res<f[mid])max_res=f[mid];
		}
		max_res=(max_res-1)/2;
		printf("%d\n", max_res);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
