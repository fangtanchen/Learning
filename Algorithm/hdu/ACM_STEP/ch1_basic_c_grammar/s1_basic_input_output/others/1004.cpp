/*
 * =====================================================================================
 *
 *       Filename:  1004.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/23/2016 07:57:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
//#include <stdlib.h>

#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

char color[1010][20];
int colori;
int cnt[1010];

int main(void){
	int N;
	while(EOF!=scanf("%d", &N), N){
		colori=0;
		char temp[20];
		memset(cnt, 0, sizeof(cnt));
		for(int i=0;i<N;i++){
			scanf("%s", temp);
			int flag=1;
			for(int j=0;j<colori;j++){
				if(!strcmp(color[j], temp)){
					flag=0;
					cnt[j]++;
					break;
				}
			}
			if(flag){
				strcpy(color[colori], temp);
				cnt[colori]=1;
				colori++;
			}
		}
		int maxi=0;
		for(int i=1;i<colori;i++){
			if(cnt[i]>cnt[maxi])maxi=i;
		}
		printf("%s\n", color[maxi]);
	}
	

	return 0;
}

