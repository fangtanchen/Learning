#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


class CEquip{
	public:
		int A;
		int B;
		int d;
};

int cmp(CEquip x, CEquip y){
	if(x.d>y.d)return true;
	else if(x.d==y.d){
		if(x.A<y.A)return true;
		else return false;
	}else{
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
	CEquip equips[1010];
	while(T--){
		int V,N;
		cin>>V>>N;
		for(int i=0;i<N;i++){
			cin>>equips[i].A>>equips[i].B;
			equips[i].d=equips[i].B-equips[i].A;
		}
		sort(equips,equips+N,cmp);

#ifdef U_DEBUG
for(int i=0;i<N;i++){
	cout<<equips[i].A<<" "<<equips[i].B<<endl;
}
#endif

		for(int i=0;i<N;i++){

				break;
			}else{
				V=V-equips[i].A;
			}
		}
		if(V>=0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
		
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
