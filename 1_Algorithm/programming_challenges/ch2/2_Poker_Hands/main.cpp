
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define ONLINE_JUDGE
#define DEBUG_M
#define XXY
#ifndef ONLINE_JUDGE
#pragma warning(disable:4996)
#endif



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class card{
public:
	char suit;
	char c;
	int val;
	card(){
		suit=val=0;
	}
public:	
	void ctoval(){
		switch(c){
			case 'T':
				val=10;
				break;
			case 'J':{
				val=11;
				break;
			}
			case 'Q':{
				val=12;
				break;
			}
			case 'K':{
				val=13;
				break;
			}
			case 'A':{
				val=14;
				break;
			}
			default:{
				val=c-'0';
				break;
			}
		}
	}
};

#define HIGH_CARD 0
#define PAIR 1
#define TWO_PAIR 2
#define THREE_OF_A_KIND 3
#define STRAIGHT 4
#define FLUSH 5
#define FULL_HOUSE 6
#define FOUR_OF_A_KIND 7
#define STRAIGHT_FLUSH 8
#define BLACK_WIN 1
#define WHITE_WIN 2
#define TIE 0
class cardType{
	public:
		int same_cnt;
		int is_straight;
		int is_flush;
		int pairs_cnt;
		char suit;
		int val;
		int type;
		int pair_val1;
		int pair_val2;
		cardType(){
			same_cnt=0;
			is_straight=0;
			is_flush=0;
			pairs_cnt=0;
			suit=0;
			val=0;
			type=0;
			pair_val1=pair_val2=0;
		}
		
		int judgeCardType(vector<card> cr){
			
			this->straight(cr);
			int x=this->val;
			this->flush(cr);
			int y=this->val;
			if(this->is_flush&&this->is_straight){
				this->type=STRAIGHT_FLUSH;
				this->val=x;
				return 0;
			}
			this->count_same(cr);
			if(4==this->same_cnt){
				this->type=FOUR_OF_A_KIND;
				return 0;
			}
			
			if(3==this->same_cnt){
				if(((cr[0].val==cr[1].val)&&(cr[0].val!=this->val))||
				((cr[3].val==cr[4].val)&&(cr[3].val!=this->val))){
					this->type=FULL_HOUSE ;
					return 0;
				}
			}
			this->flush(cr);
			if(this->is_flush){
				this->type=FLUSH;
				return 0;
			}
			
			this->straight(cr);
			if(this->is_straight){
				this->type=STRAIGHT;
				return 0;
			}
			this->count_same(cr);
			if(3==this->same_cnt){
				this->type=THREE_OF_A_KIND ;
				return 0;
			}
			
			int istwopair=this->twoPairs(cr);
			if(istwopair){
				this->type=TWO_PAIR ;
				int temp=0;
				for(int i=0;i<5;i++){
					if(cr[i].val!=this->pair_val1
					&&cr[i].val!=this->pair_val2){
						temp=cr[i].val;
						break;
					}
				}
				cr[0].val=cr[1].val=this->pair_val1;
				cr[2].val=cr[3].val=this->pair_val2;
				cr[4].val=temp;
				return 0;
			}
			if(this->pairss(cr)){
				this->type=PAIR;
				int pairi=0;
				for(pairi=4;pairi>=0;pairi--){
					if(cr[pairi].val==this->pair_val1)break;
				}
				for(;pairi>1;pairi--){
					cr[pairi].val=cr[pairi-2].val;
				}
				cr[0].val=cr[1].val=this->pair_val1;
				return 0;
			}
			this->type=HIGH_CARD;
			
			
			return 0;
		}
		
		int pairss(vector<card> cr){
			for(int i=0;i<=3;i++){
				if(cr[i].val==cr[i+1].val){
					this->pair_val1=cr[i].val;
					this->val=cr[i].val;
					return 1;
				}
			}
			return 0;
		}
		
		int twoPairs(vector<card> cr){
			for(int i=0;i<2;i++){
				if(cr[i].val==cr[i+1].val){
					for(int j=i+2;j<4;j++){
						if(cr[j].val==cr[j+1].val){
							this->pair_val1=cr[i].val;
							this->pair_val2=cr[j].val;
							this->val=cr[i].val;
							return 1;
						}
					}
				}
			}
			return 0;
		}
		
		int straight(vector<card> cr){
			int flag=1;
			for(int i=0;i<4;i++){
				if(cr[i].val-cr[i+1].val!=flag){
					flag=0;
					break;
				}
			}
			is_straight=flag;
			this->val=cr[0].val;
			#ifndef ONLINE_JUDGE
		//	cout<<"is_straight: "<<this->is_straight<<"  val:  "<<this->val<<endl;
			#endif
			
			return 0;
		}
		
		int flush(vector<card> cr){
			char s=cr[0].suit;
			int flag=1;
			for(int i=1;i<5;i++){
				if(s!=cr[i].suit){
					flag=0;
					break;
				}
			}
			this->is_flush=flag;
			this->val=cr[0].val;
			#ifndef ONLINE_JUDGE
			//cout<<"is_flush:  "<<this->is_flush<<"  val: "<<this->val<<endl;
			#endif
			
			return 0;
		}
		
		int count_same(vector<card> crd){
			int max=0;
			int max_v=0;
			for(int i=0;i<4;i++){
				int temp=1;
				for(int j=i+1;j<5;j++){
					if(crd[i].val==crd[j].val)temp++;
					else break;
				}
				if(max<temp){
					max=temp;
					this->suit=crd[i].suit;
					this->val=crd[i].val;
				}
			}
			this->same_cnt=max;
			#ifndef ONLINE_JUDGE
			//cout<<this->same_cnt<<"  "<<this->suit<<" "<<this->val<<endl;
			#endif
			return 0;
		}
};

int cmp(card x, card y) {
	if(x.val<y.val)return 0;
	return 1;
}



int main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif

	vector<card> black(5);
	vector<card> white(5);
	
	cardType blackty; 
	cardType whitety;
	
	char s[100];
	while(cin.getline(s,100,'\n')){
		#ifndef DEBUG_M
		cout<<endl<<endl<<endl<<"311:  "<<s<<endl;
		#endif
		for(int i=0;i<5;i++){
			sscanf(s+3*i,"%c%c",&(black[i].c),&(black[i].suit));
			sscanf(s+3*i+15,"%c%c",&(white[i].c),&(white[i].suit));
			black[i].ctoval();
			white[i].ctoval();
		}
		
		sort(black.begin(),black.end(),cmp); 
		sort(white.begin(),white.end(),cmp);
		
		
		blackty.judgeCardType(black);
		whitety.judgeCardType(white);
		//////////测试输入开始 /////////// 
		#ifndef DEBUG_M
		
		
		printf("BLACK:\n");
		for(int i=0;i<5;i++){
			printf("%c%c  %d\n",black[i].c,black[i].suit,black[i].val);
		}
		
		printf("WHITE:\n");
		for(int i=0;i<5;i++){
			printf("%c%c  %d\n",white[i].c,white[i].suit,white[i].val);
		}
		printf("\n\n\n");
		
		cardType blackty; 
		cardType whitety;
		cout<<"BLACK:"<<endl;
		blackty.judgeCardType(black);
		
		//#ifndef ONLINE_JUDGE
		//	cout<<"type:  "<<blackty.type<<"  "<<"value:  "<<blackty.val<<endl;
		//#endif
		
		cout<<endl<<"WHITE:"<<endl;
		whitety.judgeCardType(white);
		
		//#ifndef ONLINE_JUDGE
		//	cout<<"type:  "<<whitety.type<<"  "<<"value:  "<<whitety.val<<endl;
		//#endif
		
		cout<<endl;
		
		#endif
		///////////测试输入结束 /////// 
		int sres=TIE;
		if(blackty.type==whitety.type){
			if(blackty.val>whitety.val)
			{
				sres=BLACK_WIN;
			}
			else if(blackty.val<whitety.val){
				sres=WHITE_WIN;
			}
			else{	
				if(blackty.type==FLUSH
				||blackty.type==TWO_PAIR
				||blackty.type==PAIR
				||blackty.type==HIGH_CARD){
					for(int i=0;i<5;i++){
						if(black[i].val==white[i].val)continue;
						else{
							if(black[i].val>white[i].val){
								sres=BLACK_WIN;
							}
							else{
								sres=WHITE_WIN;
							}
							break;
						}
					}
				}
			}
		}
		else if(blackty.type>whitety.type){
				sres=BLACK_WIN;
		}
		else {
			sres = WHITE_WIN;
		}
		
		
		#ifndef XXY
		
		//printf("BLACK:\n");
		for(int i=0;i<5;i++){
			printf("%c%c ",black[i].c,black[i].suit,black[i].val);
		}
		
		//printf("WHITE:\n");
		for(int i=0;i<5;i++){
			printf("%c%c ",white[i].c,white[i].suit,white[i].val);
		}
		//printf("\n");
		#endif
		
		if(sres==BLACK_WIN)cout<<"Black wins." <<endl;
		else if(sres==WHITE_WIN)cout<<"White wins."<<endl;
		else cout<<"Tie."<<endl;
	}

#ifndef ONLINE_JUDGE
fclose(stdin);
fclose(stdout);
system("out.txt");
#endif
	return 0;
}
