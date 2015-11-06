#include <iostream>
#include<string>
#include<sstream>
#include<vector>
#include<iterator>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define SWAP(x, y, type) \
	{\
		if(x>y)\
		{\
			type tmp=x;\
			x=y;\
			y=tmp\
		}\
	}

//输出图形矩阵的内容
ostream& operator<<(ostream &out, const vector <vector<char>> &matrix) {
	for(vector<vector<char>>::const_iterator p=matrix.begin();
	p!=matrix.end();p++){
		copy((*p).begin(),(*p).end(),ostream_iterator<char>(out,""));
		out<<endl;
	}
	return out;
}

void reset(vector<vector<char>> &matrix){
	for(vector<vector<char>>::iterator p=matrix.begin();
		p!=matrix.end();p++){
			fill((*p).begin,(*p).end(),'0');
		}
}

void set_pixel(vector<vector<char>> &matrix, int x,int y,char c){
	matrix[y][x]=c;
}

void fill_rect(vector<vector<char>> &matrix, int x1,int y1,int x2,
int y2,char c){
	for(int i=y1;i<=y2;i++)
		for(int j=x1;j<=x2;j++)
			matrix[i][j]=c;
}


void fill_region(vector<vector<char>> &matrix,int x,int y,
	char old_color, char new_color){
		if(old_color==new_color) 
			return;
		matrix[y][x]=new_color;
		if(x>0)
			if(matrix[y][x-1]==old_color)
				fill_region(matrix,x-1,y,old_color,new_color);
				
		if(x<matrix[y].size()-1)
			if(matrix[y][x+1]==old_color)
				fill_region(matrix,x+1,y,old_color,new_color);
		if(y>0)
			if(matrix[y-1][x]==old_color)
				fill_region(matrix,x,y-1,old_color,new_color);
		if(y<matrix.size()-1)
			if(matrix[y+1][x]==old_color)
				fill_region(matrix,x,y+1,old_color,new_color);			
	}


int main(int argc, char** argv) {
	vector<vector<char>> matrix;
	string line;
	int width,height,x,y,x1,x2,y1,y2;
	char command,color;
	
	while(getline(cin,line),line[0]!='X'){
		istringstream iss(line);
		iss>>command;
		switch(command) {
			case 'I':
				iss>>width>>height;
				matrix.clear();
				matrix.resize(height);
				for(vector<vector<char>>::iterator p=matrix.begin();
					p!=matrix.end();p++)
						(*p).resize(width);
						
				reset(matrix);
				break;
		}
		
	}
	return 0;
}
