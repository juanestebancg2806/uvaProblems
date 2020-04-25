#include <stdio.h>
#include <stdlib.h>


int walls[50];

int main(){

	int tc,N,i,highJ,lowJ,cnt = 1;
	scanf("%d",&tc);
	while(tc--){
		highJ = 0;
		lowJ = 0;
		scanf("%d",&N);
		for(i = 0; i < N; i++){
			scanf("%d",&walls[i]);
		}
		for(i = 1; i < N;i++){
			if(walls[i-1] < walls[i]){
				highJ++;
			}
			else if(walls[i-1] > walls[i]){
				lowJ++;
			}
		}

		printf("Case %d: %d %d\n",cnt,highJ,lowJ);
		cnt++;

	}	


}