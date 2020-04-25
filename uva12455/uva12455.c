#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ms(a,b) memset(a,b,sizeof(a))

int mem[22][1100];
int bars[22];

int solve(int N,int W){
	int ans;
	if(mem[N][W] != -1)
		ans = mem[N][W];
	else if(N == 0 && W == 0)
		ans = 1;
	else if(N == 0)
		ans = 0;
	else{
		ans = solve(N-1,W);
		if(W >= bars[N-1])
			ans = ans || solve(N-1,W-bars[N-1]);
	}
	return mem[N][W] = ans;
}

int main(){
	int t,n,p,i;
	scanf("%d",&t);
	while(t--){
		ms(mem,-1);
		scanf("%d",&n);
		scanf("%d",&p);
		for(i = 0; i < p;i++)
			scanf("%d",&bars[i]);
		if(solve(p,n))
			printf("YES\n");
		else
			printf("NO\n");

	}
	

	return 0;
}