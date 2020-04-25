#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cfloat>
#define INF DBL_MAX
#define ms(a,b) memset(a,b,sizeof(a))
#define pb(a) push_back(a)
using namespace std;

int N;
double ans;
double G[16][16];
int Xi[16],Yi[16],visited[16];
string names[16];
vector<int> path;

double dist(int x1,int y1,int x2,int y2){
	return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
}


void solve(int n){
	int i;
	double d;
	if(n == N){
		d = 0.0;
		for(i = 1; i < N;i+=2)
			d += G[path[i]][path[i-1]];
		ans = min(ans,d);
	}
	else{
		for(i = 0; i < N;i++){
			if(!visited[i]){
				visited[i] = 1;
				path.pb(i);
				solve(n+1);
				visited[i] = 0;
				path.pop_back();
			}
		}

	}

}

int main(){
	map<string,int> id;
	int i,m,j,u,v,x1,y1,x2,y2,TC = 1;
	cin>>N;
	while(N){
		ms(G,0);id.clear();ms(visited,0);path.clear();
		N *= 2,m = 0;
		ans = INF;
		for(i = 0; i < N;i++){
			cin>>names[i]>>Xi[i]>>Yi[i];
			if(id.find(names[i]) == id.end()){
				id[names[i]] = m;
				m++;
			}
		}
		for(i = 0; i < N;i++){
			u = id[names[i]];
			x1 = Xi[i],y1 = Yi[i];
			for(j = i+1; j < N;j++){
				v = id[names[j]];
				x2 = Xi[j],y2 = Yi[j];
				G[u][v] = dist(x1,y1,x2,y2);
				G[v][u] = dist(x1,y1,x2,y2);
			}
		}
		solve(0);
		printf("Case %i: %.2f\n",TC++,ans);
		cin>>N;
	}
	return 0;
}