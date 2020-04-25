#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int road[20001];
int N,l,r;



int solve(){
	int tl = 1,tr = 2,i,ans = road[0],phi = road[0];
	l = tl;
	r = tr;
	for(i = 1; i < N;i++){
			if(road[i] > phi+road[i]){
				phi = road[i];
				tl = i+1;
				tr = i+2;	
			}
			else if(road[i] <= phi+road[i]){
					phi += road[i];
					tr += 1;
			}
			if((phi == ans && tr-tl > r-l) || phi > ans){
				r = tr;
				l = tl;
				ans = phi;
			}
			if(phi < 0){
				phi = road[i];
				tl = i+1;
				tr = i+2;
			}
		}
		return ans;
}

int main(){
	int tc,i,s,cnt = 1,ans;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&s);
		N = s-1;
		memset(road,-1,sizeof road);
		for(i = 0; i < N;i++)
			scanf("%d",&road[i]);

		ans = solve();
		if(ans > 0)
			printf("The nicest part of route %d is between stops %d and %d\n",cnt,l,r);
		else
			printf("Route %d has no nice parts\n",cnt);
		cnt++;

	}

	return 0;
}