/*
 * =====================================================================================
 *
 *       Filename:  6.cpp
 *				
 *
 *        Version:  1.0
 *        Created:  02/22/2016 08:40:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;


int n, P;
#define MAX_SIZE 1010
int num[MAX_SIZE];
int path[MAX_SIZE];
int P_cnt;
int dfs_size;
bool visited[MAX_SIZE];

int DFS(int ssize){
	if(ssize>dfs_size){
		printf("%d", num[path[1]]);
		for(int ni=2;ni<=dfs_size;ni++){
			printf(" %d", num[path[ni]]);
		}
		P_cnt++;
		printf("\n");
		return 0;
	}
	
	int imax=n-dfs_size+ssize;
	for(int ni=path[ssize-1]+1;(ni<=imax)&&(P_cnt<P);ni++){
		if((num[ni]>=num[path[ssize-1]])&&(!visited[ni])){
			bool pflag=true;
			for(int i=path[ssize-1]+1;i<ni;i++){
				if(num[i]==num[ni]){
					pflag=false;
					break;
				}
			}
			if(pflag){
				path[ssize]=ni;
				visited[ni]=true;
				DFS(ssize+1);
				visited[ni]=false;
			}
		}
	}

	return 0;
}


int main(void){
	while(EOF!=scanf("%d%d", &n, &P)){
		for(int ni=1;ni<=n;ni++){
			scanf("%d", &num[ni]);
		}
		P_cnt=0;
		dfs_size=1;
		memset(visited, false, sizeof(visited));
		path[0]=0;
		num[path[0]]=-100000;
		for(dfs_size=1;(dfs_size<=n)&&(P_cnt<P);dfs_size++){
			int temp=P_cnt;
			DFS(1);
			if(temp==P_cnt)break;//prune
		}
		printf("\n");
	}

	return 0;
}

