#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ms(a,b) memset(a,b,sizeof(a))

long long int mem[6][30500];
int coins[5] = {1,5,10,25,50};

long long int solve(int i,int n){
	long long int ans;
	if(n < 0 || (i == 5 && n != 0))
		ans = 0;
	else{
		if(n == 0)
			ans = 1;
		else if(i < 5 && mem[i][n] != -1)
			ans = mem[i][n];
		else
			ans = solve(i,n-coins[i]) + solve(i+1,n);
		
		if(i < 5)
			mem[i][n] = ans;
	}
	return ans;
}

int main(){
	long long int n,ans;
	ms(mem,-1);
	while(scanf("%lli",&n) != EOF){
		ans = solve(0,n);
		if(ans == 1)
			printf("There is only 1 way to produce %lli cents change.\n",n);
		else
			printf("There are %lli ways to produce %lli cents change.\n",ans,n);
	}
	return 0;

}