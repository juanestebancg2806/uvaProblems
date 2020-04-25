#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool estado(vector<int> v,int valor){
	for(int i = 0; i < v.size(); i++){
		if(v[i] == valor)
			return true;
	}
	return false;

}
vector<int> crear_grafo(int valor,vector<vector<int> > &entrada,vector<int>& importantes){
	int i,j,k = 0,cont = 0;
	vector<int> ady_tmp;
	bool band;
	for(i = 0; i < entrada.size(); i++){
		band = true;
		for(j = 0; j< entrada[i].size();j++){
			if(entrada[i][j] == valor && band){
				cont++;
				k++;
			}
			if(entrada[i][j] == valor){
				if(j == 0 && !estado(ady_tmp,entrada[i][j+1]))
					ady_tmp.push_back(entrada[i][j+1]);
				else if(j == entrada[i].size()-1 && !estado(ady_tmp,entrada[i][j-1]))
					ady_tmp.push_back(entrada[i][j-1]);
				

				else if (j != entrada[i].size()-1 && j != 0){
					if(!estado(ady_tmp,entrada[i][j-1]))
						ady_tmp.push_back(entrada[i][j-1]);
					if(!estado(ady_tmp,entrada[i][j+1]))
						ady_tmp.push_back(entrada[i][j+1]);
				}
			}
		}
	}
	if(cont > 1)
		importantes.push_back(valor);
	return ady_tmp;
}
double bfs(int raiz,vector<vector<int> > ady,vector<int> importantes){
	int i,tmp;
	double resul = 0.0,j; 
	queue<int> cola;
	vector<bool> visitado(ady.size(),false);
	vector<int> distancias(ady.size(),-1);
	distancias[raiz] = 0;
	visitado[raiz] = true;
	cola.push(raiz);
	while(!cola.empty()){
		tmp = cola.front();
		cola.pop();
		for(i = 0; i < ady[tmp].size(); i++){
			if(!visitado[ady[tmp][i]]){
				cola.push(ady[tmp][i]);
				visitado[ady[tmp][i]] = true;
				distancias[ady[tmp][i]] = distancias[tmp] + 1;
			}
		}

	}
	for(i = 0; i < importantes.size(); i++){
		if(distancias[importantes[i]] != -1)
			resul += distancias[importantes[i]];
	}
	resul = resul/(importantes.size()-1);
	return resul;
}
int main(){
	int i,j,valor,casos,n,s;
	vector<vector<int> > entrada;
	vector<int> entrada_tmp,importantes;
	vector<vector<int> > ady;
	cin>>casos;
	double resul,tmp;
	while(casos--){
		cin>>n;
		cin>>s;
		i = 0;
		while(i<s){
			while(true){
				cin>>valor;
				if(valor == 0)
					break;
				entrada_tmp.push_back(valor-1);
			}
			entrada.push_back(entrada_tmp);
			entrada_tmp.clear();
			i++;
		}
		for(i = 0; i < n; i++){
			ady.push_back(crear_grafo(i,entrada,importantes));
		}
		j = 0;
		for(i = 0; i< importantes.size(); i++){
			if(i == 0){
				resul = bfs(importantes[i],ady,importantes);
				j = importantes[i]+1;
			}
			else{
				tmp = bfs(importantes[i],ady,importantes);
				if(tmp < resul){
					resul = tmp;
					j = importantes[i] + 1;
				}
			}
		}
		cout<<"Krochanska is in: "<<j<<endl;
		
		ady.clear();
		importantes.clear();
		entrada.clear();
		entrada_tmp.clear();

	}
	return 0;
}