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

class CStick{
	public:
		int len;
		int wei;
		bool d;
};

int cmp(CStick x, CStick y){
	if(x.len<y.len){
		if(x.wei<=y.wei)
			return true;
		else
			return true;
	}else if(x.len==y.len){
		if(x.wei<=y.wei)
			return true;
		else 
			return false;
	}else{
		if(x.wei<=y.wei)
			return false;
		else
			return false;
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int T;
	cin>>T;
	CStick sticks[5010];
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>sticks[i].len>>sticks[i].wei;
			sticks[i].d=false;
		}
		
		sort(sticks,sticks+n,cmp);
		
		#ifdef U_DEBUG
			for(int i=0;i<n;i++){
				cout<<sticks[i].len<<" "<<sticks[i].wei<<endl;
			}
		#endif
		
		int res=0;
		for(int i=0;i<n;i++){
			int di=i;
	
			if(sticks[di].d==false){
				sticks[di].d=true;
				res++;
				#ifdef U_DEBUG
				{
					cout<<endl<<sticks[di].len<<" "<<sticks[di].wei<<endl;
				}
				#endif	
				int j;
				for(j=di+1;j<n;j++){
					if((sticks[j].d==false)
					&&(sticks[j].len>=sticks[di].len)
					&&(sticks[j].wei>=sticks[di].wei)){
						di=j;
						sticks[di].d=true;
						//j=di;
						#ifdef U_DEBUG
						{
							cout<<endl<<sticks[di].len<<" "<<sticks[di].wei<<endl;
						}
						#endif
					}
				}
				
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
