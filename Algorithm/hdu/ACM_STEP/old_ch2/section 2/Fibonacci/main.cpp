#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int f[21];
int main(int argc, char** argv) {
	f[0]=0;
	f[1]=1;
	for(int i=2;i<21;i++)
	{
		f[i]=f[i-1]+f[i-2];
		//cout<<f[i]<<endl;
		if(f[i]>10000)f[i]/=10;
	}
	int n;
	while(cin>>n)
	{
		if(n<=20)
		{
			cout<<f[n]<<endl;
			continue;
		}
		else{
			
			double temp=-0.5 * log(5.0) / log(10.0) + ((double)n) * log((sqrt(5.0)+1.0)/2.0) / log(10.0); 
			temp -= floor(temp);
			 temp = pow(10.0, temp);  
	            while(temp < 1000)  
	                temp *= 10;  
	            printf("%d\n", (int)temp);
        }
	}
	
	return 0;
}
