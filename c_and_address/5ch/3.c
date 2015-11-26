#include<stdio.h>

unsigned int reverse_bits(unsigned int value){
	unsigned int ret=0;
	unsigned int tt=1;
	for(tt=1;tt!=0;tt<<=1){
		ret<<=1;
		if(value&tt){
			ret|=1;
		}
	}
	return ret;
}

int main(){
	unsigned int x=0x12345678;
//	while(scanf("%u", &x)){
		unsigned y=reverse_bits(x);
		printf("%#x\n%#x\n", x, y);
//	}
	return 0;
}
