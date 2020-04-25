#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define max(a,b)(a>b ? a: b)

int N;
int H[5000],W[5000],DPi[5000],DPd[5000];
int cnt;

void solve(){
	int i,j,maxinc = 0,maxdec = 0;
	DPi[0] = DPd[0] = W[0];
	for(i = 1; i < N;i++){
		DPd[i] = DPi[i] = W[i];
		for(j = 0; j < i;j++){
			if(H[j] < H[i]){
				DPi[i] = max(DPi[i],W[i]+DPi[j]);
			}
			if(H[j] > H[i]){
				DPd[i] = max(DPd[i],W[i]+DPd[j]);
			}
		}
	}
	for(i = 0; i < N;i++){
		maxinc = max(maxinc,DPi[i]);
		maxdec = max(maxdec,DPd[i]);
	}
	if (maxinc >= maxdec)
		printf("Case %i. Increasing (%i). Decreasing (%i).\n",cnt,maxinc,maxdec);
	else
		printf("Case %i. Decreasing (%i). Increasing (%i).\n",cnt,maxdec,maxinc);

	

}

int main(){
	int tc,i;
	cnt = 1;
	scanf("%i",&tc);
	while(tc--){
		ms(DPi,-1);
		ms(DPd,-1);
		scanf("%d",&N);
		for(i = 0; i < N; i++)
			scanf("%i",&H[i]);
		for(i = 0; i < N;i++)
			scanf("%i",&W[i]);

		solve();
		cnt++;


	}

	return 0;
}