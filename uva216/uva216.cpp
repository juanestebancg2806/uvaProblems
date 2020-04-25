#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define INF 999999999.0
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
int N;
vector<int> path;
vector<int> pathtmp;
vector<int> x;
vector<int> y;
double G[9][9];
double ans;
int visited[9];
string line =  "**********************************************************";

double f(int x1,int y1,int x2,int y2){
	return sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
}

void solve(int n){
	if(n == N){
		double cost = 0.0;
		int i;
		for(i = 1; i <N;i++)
			cost += G[pathtmp[i-1]][pathtmp[i]]+16.0;
		if(cost < ans){
			ans = cost;
			path = pathtmp;
		}
	}
	else{
		int i = 0;
		while(i < N){
			if(visited[i] == 0){
				visited[i] = 1;
				pathtmp.push_back(i);
				solve(n+1);
				visited[i] = 0;
				pathtmp.pop_back();
			}
			i += 1;
		}
	}
}
int main(){
	int i,j,xi,yi,xj,yj,tc = 1;
	double d;
	cin>>N;
	while(N){
		ms(G,0);
		ms(visited,0);
		ans = INF;
		for(i = 0; i < N;i++){
			cin>>xi>>yi;
			x.push_back(xi);
			y.push_back(yi);
		}
		for(i = 0; i < N;i++){
			xi = x[i];
			yi = y[i];
			for(j = i+1; j< N;j++){
				xj = x[j];
				yj = y[j];
				d = f(xi,yi,xj,yj);
				G[i][j] = G[j][i] = d;
			}
		}
		solve(0);
		cout<<line<<endl;
		cout<<"Network #"<<tc<<endl;
		for(i = 1; i < N;i++){
			xi = x[path[i-1]];
			yi = y[path[i-1]];
			xj = x[path[i]];
			yj = y[path[i]];
			printf("Cable requirement to connect (%i,%i) to (%i,%i) is %.2f feet.\n",xi,yi,xj,yj,f(xi,yi,xj,yj)+16.0);
		}
		printf("Number of feet of cable required is %.2f.\n",ans);
		tc++;
		pathtmp.clear();path.clear();		
		x.clear();y.clear();
		cin>>N;

	}

	return 0;
}