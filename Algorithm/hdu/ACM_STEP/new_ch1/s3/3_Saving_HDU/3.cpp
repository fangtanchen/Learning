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

class CItem{
	public:
		int pi;
		int mi;
};

int cmp(CItem x, CItem y){
	if(x.pi>y.pi)return true;
	else return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int v,n;
	while(cin>>v,v){
		cin>>n;
		CItem item[110];
		for(int i=0;i<n;i++){
			cin>>item[i].pi>>item[i].mi;
		}
		sort(item,item+n,cmp);
		
		#ifdef U_DEBUG
			for(int i=0;i<n;i++){
				cout<<item[i].pi<<" "<<item[i].mi<<endl;
			}
		#endif
		int res=0;
		for(int i=0;i<n;i++){
			if(v<=0)break;
			if(v>=item[i].mi){
				v-=item[i].mi;
				res=res+item[i].mi*item[i].pi;
			}else{				
				res=res+v*item[i].pi;
				v=0;
			}
		}
		cout<<res<<endl;
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
