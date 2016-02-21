#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


struct Node{
	int val;
	int cnt;
};


vector<struct Node> num_stack;
vector<char> op_stack;
char cmd[1010];

void solve(){
	while (!num_stack.empty()){
		num_stack.pop_back();
	}
	while (!op_stack.empty()){
		op_stack.pop_back();
	}

	int cmd_len = strlen(cmd);
	char temp_op;
	struct Node temp_num;
	for (int si = 0; si<cmd_len; si++){
		if ('(' == cmd[si] || '+' == cmd[si]){
			op_stack.push_back(cmd[si]);
		}
		else if ((cmd[si] >= '0') && (cmd[si] <= '9')){
			temp_num.val = cmd[si] - '0';
			temp_num.cnt = 0;
			si++;
			while ((cmd[si] >= '0') && (cmd[si] <= '9')){
				temp_num.val = temp_num.val * 10 + cmd[si] - '0';
				si++;
			}
			si--;
			num_stack.push_back(temp_num);
		}
		else if (',' == cmd[si]){
			while ((!op_stack.empty()) && (op_stack.back() == '+')){
				temp_num = num_stack.back();
				num_stack.pop_back();
				op_stack.pop_back();
				struct Node temp = num_stack.back();
				num_stack.pop_back();
				temp_num.val = temp_num.val + temp.val;
				temp_num.cnt = temp_num.cnt + temp.cnt + 1;
				num_stack.push_back(temp_num);
			}
		}
		else if (')' == cmd[si]){
			while ((!op_stack.empty()) && (op_stack.back() == '+')){
				temp_num = num_stack.back();
				num_stack.pop_back();
				op_stack.pop_back();
				struct Node temp = num_stack.back();
				num_stack.pop_back();
				temp_num.val = temp_num.val + temp.val;
				temp_num.cnt = temp_num.cnt + temp.cnt + 1;
				num_stack.push_back(temp_num);
			}
			//pop '('
			op_stack.pop_back();

			temp_num = num_stack.back();
			num_stack.pop_back();
			{
				struct Node temp = num_stack.back();
				num_stack.pop_back();
				if (temp_num.val >= temp.val){
					temp_num.cnt = temp_num.cnt * 2 + temp.cnt;
				}
				else{
					temp_num.cnt = temp_num.cnt + temp.cnt * 2;
					temp_num.val = temp.val;
				}
				num_stack.push_back(temp_num);
			}
		}

	}//end for
	while ((!op_stack.empty()) && (op_stack.back() == '+')){
		temp_num = num_stack.back();
		num_stack.pop_back();
		op_stack.pop_back();
		struct Node temp = num_stack.back();
		num_stack.pop_back();
		temp_num.val = temp_num.val + temp.val;
		temp_num.cnt = temp_num.cnt + temp.cnt + 1;
		num_stack.push_back(temp_num);
	}
}


int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%s", cmd);
		solve();
		printf("%d %d\n", num_stack.back().val, num_stack.back().cnt);
	}

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
