#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char g[255][255];
int m,n;
char par[20];
int x[2];
int y[2];
char c;
char tem;


void F(int x,int y,char old_color, char new_color)
{	
	if(old_color==new_color)
		return ;
		
	g[y][x]=new_color;
	if(x>1){
		if(g[y][x-1]==old_color){
			F(x-1,y,old_color,new_color);
		}
	}
	if(x<m){
		if(g[y][x+1]==old_color){
			F(x+1,y,old_color,new_color);
		}
	}
	if(y>1){
		if(g[y-1][x]==old_color){
			F(x,y-1,old_color,new_color);
		}
	}
	if(y<n){
		if(g[y+1][x]==old_color){
			F(x,y+1,old_color,new_color);
		}
	}
}

int cmd_deal(char cmd){
	switch(cmd){
			case 'I':
				cin>>m;
				cin.ignore();			
				cin>>n;
				cin.ignore();			
				for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++){
						g[i][j]='0';
					}
				}
				break;
			case 'C':
				for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++){
						g[i][j]='0';
					}
				}
				break;
			case 'L':
				cin>>x[0];
				cin.ignore();
				cin>>y[0];
				cin.ignore();
				cin>>c;
				cin.ignore();
				g[y[0]][x[0]]=c;
				break;
			case 'V':
				cin>>x[0];
				cin.ignore();
				cin>>y[0];
				cin.ignore();
				cin>>y[1];
				cin.ignore();
				cin>>c;
				cin.ignore();
				if(y[0]>y[1]){
					int temp=y[0];
					y[0]=y[1];
					y[1]=temp;
				}
				for(int i=y[0];i<=y[1];i++)
					g[i][x[0]]=c;
				break;
			case 'H':
				cin>>x[0];
				cin.ignore();
				cin>>x[1];
				cin.ignore();
				cin>>y[0];
				cin.ignore();
				cin>>c;
				cin.ignore();
				if(x[0]>x[1]){
					int temp=x[0];
					x[0]=x[1];
					x[1]=temp;
				}
				for(int i=x[0];i<=x[1];i++)
					g[y[0]][i]=c;
				break;
			case 'K':
				cin>>x[0];
				cin.ignore();
				cin>>y[0];
				cin.ignore();
				cin>>x[1];
				cin.ignore();
				cin>>y[1];
				cin.ignore();
				cin>>c;
				cin.ignore();
				for(int i=x[0];i<=x[1];i++){
					for(int j=y[0];j<=y[1];j++){
						g[j][i]=c;
					}
				}
				break;
			case 'F':
				cin>>x[0];
				cin.ignore();
				cin>>y[0];
				cin.ignore();
				cin>>c;
				cin.ignore();
				F(x[0],y[0],g[y[0]][x[0]],c);
				break;
			case 'S':
				cin.getline(par,20);
				//cin.ignore();
				cout<<par<<endl;
								
				for(int j=1;j<=n;j++){
					for(int i=1;i<=m;i++){
						cout<<g[j][i];
					}
					cout<<endl;
				}
				break;
			case 'X':
				
				break;
			default:
				break;
	}
}

int main(int argc, char** argv) {
	char cmd;
	n=m=0;
	memset(g,'0',sizeof(g));
	while(cin>>cmd&&cmd!='X'){
		cin.ignore();
		cmd_deal(cmd);				
	}
	return 0;
}
