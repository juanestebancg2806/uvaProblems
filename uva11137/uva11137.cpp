#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define lli long long int
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;


lli mem[22][10001];
int coins[21];

void make_seq(){
	int i;
	for(i = 1; i <=21; i++)
		coins[i-1] = pow(i,3.0);
}

lli solve(int N, int a){
	lli ans;
	if(mem[N][a] != -1)
		ans = mem[N][a];
	else if(a == 0)
		ans = 1;
	else if(N == 0 && a != 0)
		ans = 0;
	else{
		ans = solve(N-1,a);
		if(a-coins[N-1] >= 0)
			ans += solve(N,a-coins[N-1]);
	}
	return mem[N][a] = ans;
}

int main(){
	int n;
	make_seq();
	ms(mem,-1);
	while(cin>>n){
		printf("%lli\n",solve(21,n));
	}
	return 0;
}

