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

int n;
int a[55];
int cnt;
bool map[8192][8192];
int len[8192];

void DFS(int root, int xorsum, int andsum){
    if(xorsum==andsum){
        cnt++;
    }
    if((root>n)||(!len[xorsum])||(!len[andsum])){
        return ;
    }
    for(int i=root;i<=n;i++){
        int temp1=xorsum^a[i];
        int temp2=andsum&a[i];
        DFS(i+1,temp1,temp2);
    }
    return ;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

        memset(map,false,sizeof(map));
        memset(len,0,sizeof(len));
        for(int i=0;i<8192;i++){
            if((i^i)==(i&i)){
                map[i][i]=true;
                len[i]++;
            }
            for(int j=i+1;j<8192;j++){
                if((i^j)==(i&j)){
                    map[i][j]=map[j][i]=true;
                    len[i]++;len[j]++;
                }
            }
        }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
         scanf("%d",a+i);
    }

    cnt=0;
    DFS(1,0,0x1fff);
    printf("%d\n",cnt);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
