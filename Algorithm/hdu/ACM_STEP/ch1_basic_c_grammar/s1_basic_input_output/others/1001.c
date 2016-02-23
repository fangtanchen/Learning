/*
 * =====================================================================================
 *
 *       Filename:  1001.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/23/2016 07:52:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include<stdio.h>

int main(void){
	int n;
	while(EOF!=scanf("%d", &n)){
		int sum=0;
		int i;
		for(i=1;i<=n;i++){
			sum=sum+i;
		}
		printf("%d\n\n", sum);
	}
	return 0;
}


