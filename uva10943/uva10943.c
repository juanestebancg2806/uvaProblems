#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define li long int
#define _mod 1000000
int mem[101][101];

int solve(int N,int K){
	int ans = 0;
	int i;
	if(mem[N][K] != -1){
		ans = mem[N][K];
	}
	else if(K == 0 && N == 0)
		ans = 1;
	else if(K == 0 && N != 0)
		ans = 0;
	else{
		for(i = 0; i <= N;i++)
			ans = (ans+solve(N-i,K-1))%_mod;
	}
	return mem[N][K] = ans;
}

int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	while(!(N == 0 && K == 0)){
		ms(mem,-1);
		printf("%d\n",solve(N,K));
		scanf("%d %d",&N,&K);
	}

	return 0;
}