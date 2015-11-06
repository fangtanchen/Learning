#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int pc=0;
int reg[12];
int pc_num=0;

char cmdline[1010][5];

int interpreter(char* line){
	int cmd,cx,cy;
	sscanf(line,"%1d%1d%1d",&cmd,&cx,&cy);
	
	switch(cmd){
		case 0:
			if(reg[cy])pc=reg[cx];
			else pc++;
			break;
		case 1:
			return 0;
			break;
		case 2:
			reg[cx]=cy;
			pc++;
			break;
		case 3:
			reg[cx]+=cy;
			reg[cx]%=1000;
			pc++;
			break;
		case 4:
			reg[cx]*=cy;
			reg[cx]%=1000;
			pc++;
			break;
		case 5:
			reg[cx]=reg[cy];
			reg[cx]%=1000;
			pc++;
			break;
		case 6:
			reg[cx]+=reg[cy];
			reg[cx]%=1000;
			pc++;
			break;
		case 7:
			reg[cx]*=reg[cy];
			reg[cx]%=1000;
			pc++;
			break;
		case 8:
		{
			int temp;
			sscanf(cmdline[reg[cy]],"%3d",&temp);
			reg[cx]=temp;
			pc++;
			break;
		}
		case 9:
			sprintf(cmdline[reg[cy]],"%3d",reg[cx]);
			pc++;
			break;
		default:
			break;
	}
	return 1;
}


int main(int argc, char** argv) {
	int ca;
	
	cin>>ca;
	cin.ignore();
	//ca++;
	cin.get();
	for(int cai=0;cai<ca;cai++)
	{
		pc=0;
		memset(cmdline,'0',sizeof(cmdline));
		memset(reg,0,sizeof(reg));
		
		int line_count=0;
		for(int i=0;;i++){
			cin.getline(cmdline[i],5);
			if(strlen(cmdline[i])==0)break;
			line_count++;
			//cout<<ca<<" "<<i<<" "<<line[i]<<endl;
		}
		//if(0==cai)continue;
		//cout<<i<<" "<<cmd<<" "<<cx<<" "<<cy<<" "<<endl;
		pc=0;
		pc_num=1;
		if(line_count>0){
			while(interpreter(cmdline[pc]))
				pc_num++;	
		}
		if(cai>0)cout<<endl;
		cout<<pc_num<<endl;
		
	}
	return 0;
}
