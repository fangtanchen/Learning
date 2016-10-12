#include<stdio.h>
#define MAX 20
int a[5][5]={{7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5}};


int f(int i,int j)
{  int b,c;
    if(i>=4) return a[i][j];
     c=f(i+1,j); 
	 b=f(i+1,j+1);

     if (c>b) return (a[i][j]+c);
     else   return (a[i][j]+b);
}

int main()
{
	int sum = f(0,0);


	printf("sum = %d\n",sum);

	return 0;
}


