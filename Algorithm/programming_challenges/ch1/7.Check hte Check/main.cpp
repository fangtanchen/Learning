#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define NO_KING 0
#define WHITE_KING 1
#define BLACK_KING 2
char g[10][10];
int nd=1;

int p(int row,int col,int krow,int kcol){
	int dcol=kcol-col;
	int drow=krow-row;
	if((drow==1)&& (abs(dcol)==1))
		return 1;
	return 0;
}

int r(int row,int col,int krow,int kcol){
	if(row==krow){
		if(col>kcol){
			int temp=col;
			col=kcol;
			kcol=temp;
		}
		for(int i=col+1;i<kcol;i++){
			if(g[row][i]!='.')return 0;
		}
		return 1;
	}
	else if(col==kcol){
		if(row>krow){
			int temp=row;
			row=krow;
			krow=temp;
		}
		for(int i=row+1;i<krow;i++){
			if(g[i][col]!='.')return 0;
		}
		return 1;
	}
	return 0;
}

int b(int row,int col,int krow,int kcol){
	int drow=krow-row;
	int dcol=kcol-col;
	if(abs(drow)!=abs(dcol))return 0;
	int direr=drow/abs(drow);
	int direc=dcol/abs(dcol);
	
	row+=direr;
	col+=direc;
	while(row!=krow){
		if(g[row][col]!='.')return 0;
		row+=direr;
		col+=direc;
	}
	return 1;
}

int q(int row,int col,int krow,int kcol){
	return r(row,col,krow,kcol)
	||b(row,col,krow,kcol);
}
int knight(int row,int col,int krow,int kcol){
	int drow=krow-row;
	int dcol=kcol-col;
	if(abs(drow)==2&&abs(dcol)==1)return 1;
	if(abs(drow)==1&&abs(dcol)==2)return 1;
	return 0;
}

int main(int argc, char** argv) {
	
	int bkingx,bkingy;
	int wkingx,wkingy;
	int casei=1;
	while(1){
		int flag=1;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++)
			{
				cin>>g[i][j];
				if(g[i][j]!='.')flag=0;
				if(g[i][j]=='k'){
					bkingx=i;
					bkingy=j;
				}
				else if(g[i][j]=='K'){
					wkingx=i;
					wkingy=j;
				}
			}
			cin.ignore();
		}
		if(flag)break;
		//for(int i=0;i<8;i++)
		//	cout<<g[i]<<endl;
		flag=0;
		for(int i=0;i<8;i++){
			if(flag)break;
			for(int j=0;j<8;j++){
				if(flag)break;
				//cout<<g[i][j];
				switch(g[i][j]){
					case 'p':{
						if(p(i,j,wkingx,wkingy))
							flag=WHITE_KING;
						break;
					}
					case 'P'	:{
						if(p(bkingx,bkingy,i,j))
							flag=BLACK_KING;
						break;
					}
					case 'r':{
						if(r(i,j,wkingx,wkingy))
							flag=WHITE_KING;
						break;
					}
					case 'R':{
						if(r(i,j,bkingx,bkingy))
							flag=BLACK_KING;
						break;
					}
					case 'b':{
						if(b(i,j,wkingx,wkingy))
							flag=WHITE_KING;
						break;
					}
					case 'B':{
						if(b(i,j,bkingx,bkingy))
							flag=BLACK_KING;
						break;
					}
					case 'q':{
						if(q(i,j,wkingx,wkingy))
							flag=WHITE_KING;
						break;
					}
					case 'Q':{
						if(q(i,j,bkingx,bkingy))
							flag=BLACK_KING;
						break;
					}
					case 'n':{
						if(knight(i,j,wkingx,wkingy))
							flag=WHITE_KING;
						break;
					}
					case 'N':{
						if(knight(i,j,bkingx,bkingy))
							flag=BLACK_KING;
						break;
					}
					default:{
						break;
					}
				}
			}
			//cout<<endl;
		} 
		//cout<<bkingx<<" "<<bkingy<<" "<<wkingx<<" "<<wkingy<<endl;
		if(flag==WHITE_KING)printf("Game #%d: white king is in check.\n",casei);
		else if(flag==BLACK_KING)printf("Game #%d: black king is in check.\n",casei);
		else printf("Game #%d: no king is in check.\n",casei);
		casei++;
	}
	return 0;
}

/*
..k.....
ppp.pppp
........
.R...B..
........
........
PPPPPPPP
K.......

rnbqk.nr
ppp..ppp
....p...
...p....
.bPP....
.....N..
PP..PPPP
RNBQKB.R

........
........
........
........
........
........
........
........

*/ 
