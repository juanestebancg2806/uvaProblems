#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int numbers[5];



int solve(int N,int v){
	int ans;
	if(N == 5 && v != 23)
		ans = 0;
	else if(N == 5 && v == 23)
		ans = 1;
	else{
		ans = solve(N+1,v+numbers[N]) || solve(N+1,v-numbers[N]) || solve(N+1,v*numbers[N]);
	}

	return ans;
}

int main(){
	int i,ans;
	for(i = 0; i < 5;i++)
		scanf("%d",&numbers[i]);
	while(!(numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0 && numbers[3] == 0 && numbers[4] == 0)){
		sort(numbers,numbers+5);
		ans = 0;
		do{
			ans = ans || solve(1,numbers[0]);
		}while(next_permutation(numbers,numbers+5) && !ans);
		if(ans)
			printf("Possible\n");
		else
			printf("Impossible\n");


		for(i = 0; i < 5;i++)
			scanf("%d",&numbers[i]);


	}
	return 0;
}