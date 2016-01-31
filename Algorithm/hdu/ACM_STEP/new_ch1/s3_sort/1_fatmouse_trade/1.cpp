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

#define MAX_JPF 1000000

using namespace std;

class Rooms{
public:
	int j;
	int f;
	double jpf;
};

int cmp(Rooms r1, Rooms r2){
	if(r1.jpf>r2.jpf)
	  return true;
	else if(r1.jpf==r2.jpf)
	{
		if(r1.j<r2.j)
		  return false;
	}
	else{
		return false;
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int M,N;
	while(cin>>M>>N,M!=-1 && N!=-1){
		Rooms rooms[1010];
		for(int i=0;i<N;i++){
			cin>>rooms[i].j>>rooms[i].f;
			if(rooms[i].f==0){
				rooms[i].jpf=MAX_JPF;
			}
			else{
				rooms[i].jpf=rooms[i].j*1.0/rooms[i].f;
			}
		}
		sort(rooms,rooms+N,cmp);

#ifdef U_DEBUG
for(int i=0;i<N;i++){
	cout<<rooms[i].jpf<<" "<<rooms[i].j<<" "<<rooms[i].f<<endl;
}
#endif
		double sum=0;
		for(int i=0;i<N;i++){
			if(M<=0)break;
			if(M>=rooms[i].f){
				sum+=rooms[i].j;
				M-=rooms[i].f;
			}else{
				sum+=(M*1.0/rooms[i].f*rooms[i].j);
				M=0;
			}
			
		}
		printf("%.3f\n",sum);
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
