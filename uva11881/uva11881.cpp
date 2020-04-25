#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define ms(a,b) memset(a,b,sizeof(a))

using namespace std;

int Fi[10001];
int N;

double f(double IRR){
	double ans = Fi[0];
	int i;
	for(i = 1; i < N;i++)
		ans += Fi[i]/(pow(1+IRR,i));
	return ans;
}

double solve(){
	double low = -1.0, hi = 10000.0,mid,val,ans = -1.0;
	bool ok = false;
	int it = 0;
	while (low <= hi && it < 101){
		mid = (low+hi)/2;
		val = f(mid);
		if(val > 0)
			low = mid;
		else
			hi = mid;
		it += 1;
	}
	return hi;
}

int main(){
	int T,i;
	cin>>T;
	double ans;
	while(T){
		N = T+1;
		for(i = 0; i < N; i++)
			cin>>Fi[i];
		ans = solve();
		printf("%.2f\n",ans);
		ms(Fi,-1);
		cin>>T;

	}
	return 0;
}