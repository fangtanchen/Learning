#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char** argv) {
	int s,n;
	char nstr[15];
	char ans[25][120];
	while(cin>>s>>n,s||n){
		memset(ans,' ',sizeof(ans));
		sprintf(nstr,"%d",n);
		//	cout<<strlen(sstr)<<" "<<sstr<<endl;
		int nlen=strlen(nstr);
		int width=s+3;
		int high=2*s+3;
		int max=0;
		for(int i=0;i<nlen;i++){
			int ywidth=i*width;
			switch(nstr[i]){
				case '0':
					max=width-1;
					for(int coli=1;coli<=s;coli++){
						ans[0][coli+ywidth]='-';
						ans[high-1][coli+ywidth]='-';
					//	ans[s+1][coli+ywidth]='-';
					}
					max=high-1;
					for(int rowi=1;rowi<=s;rowi++){
						ans[rowi][0+ywidth]='|';
						ans[rowi][s+1+ywidth]='|';
						ans[rowi+s+1][0+ywidth]='|';
						ans[rowi+s+1][s+1+ywidth]='|';
					}
					break;
				case '1':
					max=width-1;
					/*for(int coli=1;coli<=s;coli++){
						ans[0][coli+ywidth]='-';
						ans[high-1][coli+ywidth]='-';
						ans[s+1][coli+ywidth]='-';
					}*/
					max=high-1;
					for(int rowi=1;rowi<=s;rowi++){
					//	ans[rowi][0+ywidth]='|';
						ans[rowi][s+1+ywidth]='|';
					//	ans[rowi+s+1][0+ywidth]='|';
						ans[rowi+s+1][s+1+ywidth]='|';
					}
					break;
				case '2':
					max=width-1;
					for(int coli=1;coli<=s;coli++){
						ans[0][coli+ywidth]='-';
						ans[high-1][coli+ywidth]='-';
						ans[s+1][coli+ywidth]='-';
					}
					max=high-1;
					for(int rowi=1;rowi<=s;rowi++){
					//	ans[rowi][0+ywidth]='|';
						ans[rowi][s+1+ywidth]='|';
						ans[rowi+s+1][0+ywidth]='|';
					//	ans[rowi+s+1][s+1+ywidth]='|';
					}
					break;
				case '3':
					max=width-1;
					for(int coli=1;coli<=s;coli++){
						ans[0][coli+ywidth]='-';
						ans[high-1][coli+ywidth]='-';
						ans[s+1][coli+ywidth]='-';
					}
					max=high-1;
					for(int rowi=1;rowi<=s;rowi++){
					//	ans[rowi][0+ywidth]='|';
						ans[rowi][s+1+ywidth]='|';
					//	ans[rowi+s+1][0+ywidth]='|';
						ans[rowi+s+1][s+1+ywidth]='|';
					}
					break;
				case '4':
					max=width-1;
					for(int coli=1;coli<=s;coli++){
					//	ans[0][coli+ywidth]='-';
					//	ans[high-1][coli+ywidth]='-';
						ans[s+1][coli+ywidth]='-';
					}
					max=high-1;
					for(int rowi=1;rowi<=s;rowi++){
						ans[rowi][0+ywidth]='|';
						ans[rowi][s+1+ywidth]='|';
					//	ans[rowi+s+1][0+ywidth]='|';
						ans[rowi+s+1][s+1+ywidth]='|';
					}
					break;
				case '5':
					max=width-1;
					for(int coli=1;coli<=s;coli++){
						ans[0][coli+ywidth]='-';
						ans[high-1][coli+ywidth]='-';
						ans[s+1][coli+ywidth]='-';
					}
					max=high-1;
					for(int rowi=1;rowi<=s;rowi++){
						ans[rowi][0+ywidth]='|';
					//	ans[rowi][s+1+ywidth]='|';
					//	ans[rowi+s+1][0+ywidth]='|';
						ans[rowi+s+1][s+1+ywidth]='|';
					}
					break;
				case '6':
					max=width-1;
					for(int coli=1;coli<=s;coli++){
						ans[0][coli+ywidth]='-';
						ans[high-1][coli+ywidth]='-';
						ans[s+1][coli+ywidth]='-';
					}
					max=high-1;
					for(int rowi=1;rowi<=s;rowi++){
						ans[rowi][0+ywidth]='|';
					//	ans[rowi][s+1+ywidth]='|';
						ans[rowi+s+1][0+ywidth]='|';
						ans[rowi+s+1][s+1+ywidth]='|';
					}
					break;
				case '7':
					max=width-1;
					for(int coli=1;coli<=s;coli++){
						ans[0][coli+ywidth]='-';
					//	ans[high-1][coli+ywidth]='-';
					//	ans[s+1][coli+ywidth]='-';
					}
					max=high-1;
					for(int rowi=1;rowi<=s;rowi++){
					//	ans[rowi][0+ywidth]='|';
						ans[rowi][s+1+ywidth]='|';
					//	ans[rowi+s+1][0+ywidth]='|';
						ans[rowi+s+1][s+1+ywidth]='|';
					}
					break;
				case '8':
					
					for(int coli=1;coli<=s;coli++){
						ans[0][coli+ywidth]='-';
						ans[high-1][coli+ywidth]='-';
						ans[s+1][coli+ywidth]='-';
					}
					max=high-1;
					for(int rowi=1;rowi<=s;rowi++){
						ans[rowi][0+ywidth]='|';
						ans[rowi][s+1+ywidth]='|';
						ans[rowi+s+1][0+ywidth]='|';
						ans[rowi+s+1][s+1+ywidth]='|';
					}
					break;
				case '9':
					max=width-1;
					for(int coli=1;coli<=s;coli++){
						ans[0][coli+ywidth]='-';
						ans[high-1][coli+ywidth]='-';
						ans[s+1][coli+ywidth]='-';
					}
					max=high-1;
					for(int rowi=1;rowi<=s;rowi++){
						ans[rowi][0+ywidth]='|';
						ans[rowi][s+1+ywidth]='|';
					//	ans[rowi+s+1][0+ywidth]='|';
						ans[rowi+s+1][s+1+ywidth]='|';
					}
					break;
					
			}
			
		}
		max=nlen*(s+3)-1;
		for(int rowi=0;rowi<high;rowi++){			
			for(int coli=0;coli<max;coli++){
				printf("%c",ans[rowi][coli]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	
	return 0;
}
