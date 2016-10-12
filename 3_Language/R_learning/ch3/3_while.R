z<-5
while(z>=3&&z<=10){
	print(z)
	coin<-rbinom(1,1,0.5)

	if(coin==1){
		z=z+1
	}else{
		z=z-1
	}
}
