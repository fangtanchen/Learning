/*
 * =====================================================================================
 *
 *       Filename:  5_2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/27/2016 05:03:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include<cstdio>

int main(){
	int ch, q=1;
	while(EOF!=(ch=getchar())){
		if(ch=='"'){
			printf("%s", q?"``":"''");
			q=!q;
		}else{
			putchar(ch);
		}
	}
	return 0;
}
