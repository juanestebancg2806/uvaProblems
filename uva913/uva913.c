#include <stdio.h>
#include <stdlib.h>

unsigned long long int oddNumbers[500000000];

void make_seq(){
	int i,lvl = 3;
	oddNumbers[0] = 1;oddNumbers[1] = 3;
	for(i = 2; i <500000000 ;i++){
		oddNumbers[i] = oddNumbers[i-1]+(2*lvl);
		lvl += 2;
	}
}

int main(){
	unsigned long long int N,i,num,ans;
	make_seq();
	while(scanf("%lli",&N) != EOF){
		i = N/2;
		num = oddNumbers[i];
		ans = num +2*(N-1);
		ans += num+(2*(N-2));
		ans += num+(2*(N-3));
		printf("%lli\n",ans);
		

	}
	return 0;


}