queue<int> q;

int topo(){
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	int temp;
	while(!q.empty()){
		temp=q.front();
		for(int i=1;i<=n;i++){
			if(map[temp][i]){
				indegree[i]--;
				if(0==indegree[i]){
					q.push(i);
				}
			}
		}
	}
}
