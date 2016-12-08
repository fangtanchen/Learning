#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=105;
const int MAXM=10000;

char str[MAXN];
int N;
char query[MAXN];

int cseti,useti;

map<string,set<int> > mp_s2set;
map<string,int > mp_s2i;
map<set<int>,int> mp_set2i;

set<int> endpos[MAXM];


void Init(){
     cseti=useti=0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        Init();
    scanf("%s",str);
    int slen=strlen(str);
    for(int i=0;i<slen;i++){
        char tmp[MAXN];
        int tmplen=0;
        memset(tmp,0,sizeof(tmp));
        for(int j=i;j<slen;j++){
            tmp[tmplen++]=str[j];
            if(mp_s2i.find(tmp)==mp_s2i.end()){
                mp_s2i[tmp]=cseti++;
            }
            endpos[mp_s2i[tmp]].insert(j);
        }
    }
    for(int i=0;i<slen;i++){
        char tmp[MAXN];
        int tmplen=0;
        memset(tmp,0,sizeof(tmp));
        for(int j=i;j<slen;j++){
            tmp[tmplen++]=str[j];
            string ss(tmp);
            f(mp_set2i.find(endpos[mp_s2i[ss]])==mp_set2i.end()){
                 mp_set2i[endpos[mp_s2i[ss]]]=useti++;
            }
        }
    }
    scanf("%d",&N);
    for(int ni=0;ni<N;ni++){
         scanf("%s",query);

    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
