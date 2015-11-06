#include <iostream>
#include<cstdio>
#include<cstring>> 

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int m,n;
char cmd[50];
char g[255][255];
//int x,y;
//int x1,x2,y1,y2;
//char c;

void I(char* s){
	sscanf(s," %d %d",&m,&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			g[i][j]='O';
		}
	}
}

void C(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			g[i][j]='O';
		}
	}
}

void L(char* s){
	int x,y;
	char c;
	sscanf(s," %d %d %c",&x,&y,&c);
	g[y][x]=c;
}

void V(char* s){
	int x,y1,y2;
	char c;
	sscanf(s," %d %d %d %c",&x,&y1,&y2,&c);
	if(y1>y2){
		int temp=y1;
		y1=y2;
		y2=temp;
	}
	for(int i=y1;i<=y2;i++)
		g[i][x]=c;
}

void H(char* s){
	int x1,x2,y;
	char c;
	sscanf(s," %d %d %d %c",&x1,&x2,&y,&c);
	if(x1>x2){
		int temp=x1;
		x1=x2;
		x2=temp;
	}
	for(int i=x1;i<=x2;i++)
		g[y][i]=c;
}

void K(char* s){
	int x1,x2,y1,y2;
	char c;
	sscanf(s," %d %d %d %d %c",&x1,&y1,&x2,&y2,&c);
	if(x1>x2){
		int temp=x1;
		x1=x2;
		x2=temp;
	}
	if(y1>y2){
		int temp=y1;
		y1=y2;
		y2=temp;
	}
	for(int i=y1;i<=y2;i++){
		for(int j=x1;j<=x2;j++){
			g[i][j]=c;
		}
	}
}



void fill_region(int x,int y,char old_color,char new_color){
	if(old_color==new_color)return;
	
	g[y][x]=new_color;
	if(x>1)
		if(old_color==g[y][x-1])
			fill_region(x-1,y,old_color,new_color);
	if(x<m)
		if(old_color==g[y][x+1])
			fill_region(x+1,y,old_color,new_color);
	if(y>1)
		if(old_color==g[y-1][x])
			fill_region(x,y-1,old_color,new_color);
	if(y<n)
		if(old_color==g[y+1][x])
			fill_region(x,y+1,old_color,new_color);
	
}

void F(char *s){
	int x,y;
	char c;
	sscanf(s," %d %d %c",&x,&y,&c);
	char old_color=g[y][x];
	fill_region(x,y,old_color,c);
}

void S(char* s){
	cout<<s<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%c",g[i][j]);
		}
		cout<<endl;
	}
}

int main(int argc, char** argv) {
	
	//char cmd[50];
	m=n=0;
	memset(g,'0',sizeof(g));
	while(cin.getline(cmd,50)&&cmd[0]!='X'){
		switch(cmd[0]){
			case 'I':{
				I(cmd+2);
				break;
			}
			case 'C':{
				C();
				break;
			}
			case 'L':{
				L(cmd+2);
				break;
			}
			case 'V':{
				V(cmd+2);
				break;
			}
			case 'H':{
				H(cmd+2);
				break;
			}
			case 'K':{
				K(cmd+2);
				break;
			}
			case 'F':{
				F(cmd+2);
				break;
			}
			case 'S':{
				S(cmd+2);
				break;
			}
			default:
				break;
		}
	}
	
	return 0;
}
