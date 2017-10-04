#include<iostream>
#include<vector>

using namespace std;


// input two dim arr arr
// output : used for print res
// di:  the number sets used
// length:  total length of arr
void PrintProduct(vector<vector<int> > &arr,vector<int> output,int di,int length){
	if(di==length){
		for(int i=0;i<output.size();i++){
			cout<<output[i]<<",";
		}
		cout<<endl;
		return ;
	}
	for(int i=0;i<arr[di].size();i++){
		output.push_back(arr[di][i]);
		PrintProduct(arr,output,di+1,length);
		output.pop_back();
	} 
}


int main(){
	vector<vector<int> > G;
	vector<int> A(2,3);
	G.push_back(A);
	vector<int> B;
	B.push_back(3);
	B.push_back(4);
	B.push_back(5);
	G.push_back(B);
	vector<int> C;
	C.push_back(6);
	C.push_back(7);
	C.push_back(8);
	G.push_back(C);
	vector<int> ans;
	PrintProduct(G,ans,0,G.size());
	return 0;
}
