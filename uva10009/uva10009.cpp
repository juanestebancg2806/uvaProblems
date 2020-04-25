#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool revisar(map<string,int> indices, string nom){
	for(map<string,int>::iterator it = indices.begin(); it != indices.end(); it++){
		if(nom == it->first)
			return true;
	}
	return false;
}

void impresion(vector<int> camino, map<int,string> numeros,int raiz, int meta){
	int i = meta;
	vector<string> tmp;
	tmp.push_back(numeros[meta]);
	char hp;
	while(i != -1){
		if(i != -1)
			tmp.push_back(numeros[camino[i]]);
		i = camino[i];
	}
	for(int i = tmp.size()-2; i>=0;i--){
		cout<<tmp[i][0];
	}

}

void bfs(int raiz,int meta,vector<vector<int> > ady,map<int,string> numeros){
	vector<bool>  visitado(ady.size(),false);
	vector<int> camino(ady.size(),-1);
	int tmp;
	queue<int> cola;
	cola.push(raiz);
	visitado[raiz] = true;
	while(!cola.empty()){
		tmp = cola.front();
		cola.pop();
		if(tmp == meta){
			break;
		}
		
		for(int i = 0; i<ady[tmp].size(); i++){
			if(!visitado[ady[tmp][i]]){
				visitado[ady[tmp][i]] = true;
				camino[ady[tmp][i]] = tmp;
				cola.push(ady[tmp][i]);
			}
		}

	}
	impresion(camino,numeros,raiz,meta);

}

int main(){
	int testC,m,n,i,j,k,cont;
	cin>>testC;
	cont = testC;
	vector<string> ida,vuelta,consultas,consultas2;
	string temp;
	map<string,int> indices;
	map<int,string> numeros;
	vector<vector<int> > ady;
	vector<int> ady_temp;
	while(testC--){
		cin>>m;
		cin>>n;
		for(i = 0; i<m*2;i++){
			cin>>temp;
			if(i%2 == 0){
				ida.push_back(temp);
			}
			else{
				vuelta.push_back(temp);
			}

		}

		for(i = 0; i<n*2; i++){
			cin>>temp;
			if(i%2 == 0)
				consultas.push_back(temp);
			else
				consultas2.push_back(temp);
		}
	j = 0;
	for(i = 0; i<m; i++){
		if(!revisar(indices,ida[i])){
			indices[ida[i]] = j;
			numeros[j] = ida[i];
			j++;
		}
		if(!revisar(indices,vuelta[i])){
			indices[vuelta[i]] = j;
			numeros[j] = vuelta[i];
			j++;
		}
	}
	for(i = 0; i<j;i++){
		temp = numeros[i];
		for(k = 0; k<j;k++){
			if(temp == vuelta[k]){
				ady_temp.push_back(indices[ida[k]]);

			}
			if(temp == ida[k]){
				ady_temp.push_back(indices[vuelta[k]]);
			}
		}
		ady.push_back(ady_temp);
		ady_temp.clear();

	}

	for(i = 0; i<n;i++){
		bfs(indices[consultas[i]],indices[consultas2[i]],ady,numeros);
		cout<<endl;
	}
	cont--;
	if(cont != 0)
		cout<<endl;
	
	ady.clear();
	ida.clear();
	vuelta.clear();
	consultas.clear();
	consultas2.clear();
	indices.clear();
	numeros.clear();

	}
	return 0;

}

