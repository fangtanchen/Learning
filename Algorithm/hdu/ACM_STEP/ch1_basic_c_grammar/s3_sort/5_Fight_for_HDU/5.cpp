#include<iostream>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int cmp(int x,int y){
	if(x>y)return false;
	else return true;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int n;
	int hdu[100];
	int sb[100];
	while(cin>>n,n){
		for(int i=0;i<n;i++)
			cin>>hdu[i];
		for(int i=0;i<n;i++)
			cin>>sb[i];
			
		sort(hdu,hdu+n,cmp);
		sort(sb,sb+n,cmp);
		
		int s1,s2;
		s1=s2=0;
		for(int i=0;i<n;i++){
			if(hdu[i]>sb[i]){
				s1+=2;
			}
			else if(hdu[i]==sb[i]){
				s1++;
				s2++;
			}else{
				s2+=2;
			}
		}
		cout<<s1<<" vs "<<s2<<endl;
	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
