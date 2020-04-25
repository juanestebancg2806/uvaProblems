#include <iostream>
#include <vector>
#include <string.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define lli long long int
using namespace std;

int isPrime[1300];
vector<int> primes;
lli mem[1125][17][214];

void make_seq(){
	int i,j;
	for(i = 2; i < 1300;i++){
		for(j = i+i;j < 1300;j+=i)
			isPrime[j] = 0;
	}
	for(i = 2; i < 1300;i++){
		if(isPrime[i])
			primes.push_back(i);
	}
}

lli solve(int n,int k,int i){
	lli ans;
	int j;
	if (mem[n][k][i] != -1){
		ans = mem[n][k][i];
	}
	else if(n == 0 && k == 0)
		ans = 1;
	else if(n == 0 || i >= primes.size() || (n != 0 && k == 0))
		ans = 0;
	else{
		ans = 0;
		for(j = i; j < primes.size() && primes[j] <= n;j++){
			if(primes[j] <= n)
				ans += solve(n-primes[j],k-1,j+1);

		}

	}
	return mem[n][k][i] = ans;
}
int main(){
	int n,k;
	ms(isPrime,1);
	ms(mem,-1);
	make_seq();
	cin>>n>>k;
	while(!(n == 0 & k == 0)){
		
		cout<<solve(n,k,0)<<endl;

		cin>>n>>k;
	}
	return 0;
}