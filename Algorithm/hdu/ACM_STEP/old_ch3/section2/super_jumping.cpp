#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int n;
int a[1024];

int main()
{
	long long int sum[1024];
	long long int max;
	while(cin>>n,n){
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum[i]=a[i];
		}
		max=sum[0];


		for(int i=0;i<n;i++){

			for(int j=0;j<i;j++){
				if(a[j]<a[i]&&sum[i]<sum[j]+a[i]){
					sum[i]=sum[j]+a[i];
				}
				if(max<sum[i])max=sum[i];
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
