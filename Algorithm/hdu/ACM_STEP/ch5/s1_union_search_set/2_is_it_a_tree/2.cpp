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

int fa[100010];
int ha[100010];
int hai;
bool mark=true;

void init(){
	memset(ha, 0, sizeof(ha));
	hai=1;
	mark=true;

}

int find(int a){
	if(a==fa[a]){
		return a;
	}
	int root=fa[a];
	while(root!=fa[root]){
		root=fa[root];
	}
	int temp=a, pp;
	while(temp!=root){
		pp=fa[temp];
		fa[temp]=root;
		temp=pp;
	}
	return root;
}

int merge(int x, int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		fa[fy]=fx;
	return 0;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int a, b;
	int casei=1;
	init();
	while(EOF!=scanf("%d%d", &a, &b)){
		if(a<0&&b<0)break;
		if(a+b==0){
			int cnt=0;
			for(int ti=1;ti<hai;ti++){
				if(fa[ti]==ti){
					cnt++;
				}
			}
			if((cnt!=1)&&(hai!=1))mark=false;
			if(mark)printf("Case %d is a tree.\n", casei++);
			else printf("Case %d is not a tree.\n", casei++);
			
			init();
			continue;
		}
		if(!mark)continue;

		if(ha[a]==0){
			ha[a]=hai;
			fa[hai]=hai;
			hai++;
		}
		if(0==ha[b]){
			ha[b]=hai;
			fa[hai]=hai;
			hai++;
		}

		int pa=find(ha[a]);
		int pb=find(ha[b]);
		if((pa==pb)||(pb!=ha[b])){
			mark=false;
		}else{
			merge(ha[a], ha[b]);
		}
	}


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
