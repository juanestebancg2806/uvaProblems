#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ms(a,b) memset(a,b,sizeof(a))

int path[16],visited[17],n;

int isPrime(int n){
	int ans = 1,i;
	if(n > 2){
		for(i = 2; i*i <= n && ans;i++)
			ans = ans && n%i != 0;
	}
	return ans;
}

void solve(int i){
	int j;
	if(i == n && isPrime(path[n-1]+1)){
		for(j = 0; j < n;j++){
			if(j+1 == n)
				printf("%d\n",path[j]);
			else
				printf("%d ", path[j]);
		}
	}
	else if(i < n){
		for(j = 0; j < n;j++){
			if(!visited[j+1] && isPrime(path[i-1]+(j+1))){
				visited[j+1] = 1;
				path[i] = j+1;
				solve(i+1);
				path[i] = 0;
				visited[j+1] = 0;
			}
		}
	}
}

int main(){
	int TC = 0;
	ms(visited,0); path[0] = 1; visited[1] = visited[0] = 1;
	while(scanf("%d",&n) != EOF){
		TC++;
		if(TC>1) printf("\n");
		printf("Case %d:\n",TC);
		solve(1);
	}

	return 0;
}