#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAX_SIZE 55

int n;
int p[4];
char map[MAX_SIZE][MAX_SIZE];
//int step[MAX_SIZE][MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];
class CPlace{
	public:
		int a,b,c,t;
		CPlace(int a, int b, int c,int t){
			this->a=a;
			this->b=b;
			this->c=c;
			this->t=t;
		}
		CPlace(const CPlace &p){
			a=p.a;
			b=p.b;
			c=p.c;
			t=p.t;
		}
};

int BFS(CPlace st){
	
	if((st.a==st.b)&&(st.a==st.c)){
		return 0;
	}

	vector<CPlace> qe;
	qe.push_back(st);

	int qi=0;
	visited[st.a][st.b][st.c]=true;
	while(qi<(int)qe.size()){
		CPlace np(qe[qi]);

		for(int ni=1;ni<=n;ni++){
			
			if((map[np.a][ni]==map[np.b][np.c])
			&&(!visited[ni][np.b][np.c])){
				visited[ni][np.b][np.c]=true;
				qe.push_back(CPlace(ni,np.b,np.c,np.t+1));
				if((ni==np.b)&&(ni==np.c)){
					return np.t+1;
				}
			}
			if((map[np.b][ni]==map[np.a][np.c])
			&&(!visited[np.a][ni][np.c])){
				visited[np.a][ni][np.c]=true;
				qe.push_back(CPlace(np.a,ni,np.c,np.t+1));
				if((ni==np.a)&&(ni==np.c)){
					return np.t+1;
				}
			}
			if((map[np.c][ni]==map[np.a][np.b])
			&&(!visited[np.a][np.b][ni])){
				visited[np.a][np.b][ni]=true;
				qe.push_back(CPlace(np.a,np.b,ni,np.t+1));
				if((ni==np.a)&&(ni==np.b)){
					return np.t+1;
				}
			}
		}
		qi++;
	}
	return -1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%d",&n),n){
		//getchar();
		for(int ni=1;ni<=3;ni++){
			scanf("%d",&p[ni]);
			//getchar();	
		}
		getchar();
		char temps[200];
		for(int ni=1;ni<=n;ni++){
			cin.getline(temps+2,200,'\n');
			for(int nj=1;nj<=n;nj++){
				map[ni][nj]=temps[2*nj];
			}
			map[ni][n+1]=0;

		}
#ifdef U_DEBUG
printf("%d",n);
for(int ni=1;ni<4;ni++){
	printf(" %d",p[ni]);
}
printf("\n");
for(int ni=1;ni<=n;ni++){
	printf("%s\n",map[ni]+1);
}
#endif
		
		//memset(step,-1,sizeof(step));
		memset(visited,false,sizeof(visited));
		CPlace st(p[1],p[2],p[3],0);
		int res=BFS(st);
		if(res<0){
			printf("impossible\n");
		}else{
			printf("%d\n",res);
		}


	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}


