#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

void dfs(int raiz,vector<vector<int> > ady){
	stack<int> pila;
	int tmp;
	bool band = true;
	vector<bool> visitado(ady.size(),false);
	pila.push(raiz);
	visitado[raiz] = true;
	while(!pila.empty()){
		tmp = pila.top();
		pila.pop();
		for(int i = 0; i<ady[tmp].size();i++){
			if(!visitado[ady[tmp][i]]){
				visitado[ady[tmp][i]] = true;
				pila.push(ady[tmp][i]);
			}
		}
	}
	for(int i = 0; i< visitado.size();i++){
		if(visitado[i] == false){
			band = false;
			break;
		}
	}
	if(band){
		cout<<"All stations are reachable."<<endl;
	}
	else{
		cout<<"There are stations that are unreachable."<<endl;
	}

}


int main(){
	int n,coord,i,j,k;
	double cd,cdtmp;
	vector<int> x,y;
	vector<double> adytmp;
	vector<int> indices;

	vector<vector<int> > ady;
	cin>>n;
	while(n != 0) {
		for(i = 0; i<n*2; i++){
			cin>>coord;
			if(i%2 == 0)
				x.push_back(coord);
			else
				y.push_back(coord);

		}
		for(i = 0; i<n; i++){
			k = 0;
			for(j = 0; j < n ;j++){
				if(i != j){
					if(k < 2){
						cdtmp = pow(x[j]-x[i],2.0)+pow(y[j]-y[i],2.0);
						cd = pow(cdtmp,0.5);
						adytmp.push_back(cd);
						indices.push_back(j);
						k++;
					}
					else{
						cdtmp = pow(x[j]-x[i],2.0)+pow(y[j]-y[i],2.0);
						cd = pow(cdtmp,0.5);
						if(cd < adytmp[0] && cd < adytmp[1]){
							if(adytmp[0] - cd < adytmp[1] - cd){
								adytmp[1] = cd;
								indices[1] = j;	
							}
								
							else if(adytmp[0] - cd >= adytmp[1] - cd){
								adytmp[0] = cd;
								indices[0] = j;
							}

						}
						else if(cd < adytmp[0]){
								indices[0] = j;
								adytmp[0] = cd;

						}
						else if(cd < adytmp[1]){
							indices[1] = j;
							adytmp[1] = cd;
						}	
						else if(cd == adytmp[0] || cd == adytmp[1]){
							 if(x[j]<x[indices[0]] && cd==adytmp[0]){
								adytmp[0] = cd;
								indices[0] = j;
							}
							else if(x[j] == x[indices[0]] && cd == adytmp[0]){
								if(y[j]< y[indices[0]]){
									adytmp[0] = cd;
									indices[0] = j;
								}
							}
							else if(x[j]<x[indices[1]] &&  cd == adytmp[1]){
								adytmp[1] = cd;
								indices[1] = j;
							}
							else if(x[j] == x[indices[1]] &&  cd == adytmp[1]){
								if(y[j]< y[indices[1]]){
									adytmp[1] = cd;
									indices[1] = j;
								}
							}


						}
						
				

					}
				}

			}
			ady.push_back(indices);
			indices.clear();
			adytmp.clear();
			
			
		}		
		dfs(0,ady);
	

		ady.clear();
		adytmp.clear();
		indices.clear();
		x.clear();
		y.clear();
		cin>>n;

	}
	return 0;
}