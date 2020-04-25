#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>
using namespace std;




int main(){

	int K,N,M,X,Y,i;
	string ans;
	cin>>K;
	while(K != 0){
		cin>>N>>M;
		for(i = 0; i < K;i++){
			cin>>X>>Y;
			ans = "";
			if(X==N || Y == M)
				ans = "divisa";
			else if( X < N && Y > M )
				ans = "NO";
			else if(X > N && Y > M)
				ans = "NE";
			else if(X > N && Y < M)
				ans = "SE";
			else if(X < N && Y < M)
				ans = "SO";
			assert(ans != "");
			cout<<ans<<endl;
		}
		cin>>K;

	}
	return 0;
}