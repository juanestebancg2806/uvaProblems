#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cars[1001],positions[1001],grid[1001];

int solve(int N){
	int i,ans = 1;
	for(i = 0; i < N && ans; i++){
		ans = i+positions[i] >= 0 && i+positions[i] < N && grid[i+positions[i]] == -1;
		if(ans)
			grid[positions[i]+i] = cars[i];
	}
	return ans;

}

int main(){
	int i,N,C,P,ans;
	scanf("%d",&N);
	while(N != 0){
		memset(cars,-1,sizeof(cars));
		memset(positions,-1,sizeof(positions));
		memset(grid,-1,sizeof(grid));
		for(i = 0 ; i < N; i++)
			scanf("%d %d",&cars[i],&positions[i]);
		
		ans = solve(N);
		if(!ans)
			printf("-1\n");
		else{
			for(i = 0; i < N ;i++)
				if(i+1 == N)
					printf("%d\n",grid[i]);
				else
					printf("%d ",grid[i]);

		}
		scanf("%d",&N);	
	}
	return 0;
}