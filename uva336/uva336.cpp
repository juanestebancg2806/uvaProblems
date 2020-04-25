#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


bool estado(map<int,int> indices,int valor){
	for(map<int,int>::iterator it = indices.begin();it != indices.end(); it++){
		if(valor == it->first)
			return true;
	}
	return false;
}



int bfs(int raiz,int limite,vector<vector<int> > ady,map<int,int> numeros){
	queue<int> cola;
	vector<bool> visitado(ady.size(),false);
	vector<int> camino_ttl(ady.size(),0);
	camino_ttl[raiz] = limite;
	visitado[raiz] = true;
	cola.push(raiz);
	int tmp = 0,i = 0,j = 0;
	while(!cola.empty()){
		tmp = cola.front();
		cola.pop();
		if(camino_ttl[tmp] > 0){
			for(i = 0; i<ady[tmp].size();i++){
				if(!visitado[ady[tmp][i]]){
					cola.push(ady[tmp][i]);
					visitado[ady[tmp][i]] = true;
					camino_ttl[ady[tmp][i]] = camino_ttl[tmp] -1;
				}

			}

		}
		

	}
	j = 0;
	for(i = 0; i<visitado.size();i++){
		if(!visitado[i])
			j++;
	}
	return j;


}	

int main(){
	int NC,i,j,k,valor,inicio,TTL,tmp,casos = 1;
	map<int,int> indices;
	map<int,int> numeros;
	vector<int> ida,vuelta,consultas,ady_tmp;
	vector<vector<int> > ady;
	cin>>NC;
	while(NC != 0){
		for(i = 0; i<NC*2;i++){
			cin>>valor;
			if(i%2 == 0)
				ida.push_back(valor);
			
			else
				vuelta.push_back(valor);
			

		}
		
		j = 0;
		for(i = 0; i<ida.size(); i++){
			if(!estado(indices,ida[i])){
				indices[ida[i]] = j;
				numeros[j] = ida[i];
				j++;
			}
			if(!estado(indices,vuelta[i])){
				indices[vuelta[i]] = j;
				numeros[j] = vuelta[i];
				j++;
			}
		}

		for(i = 0; i<j;i++){
			tmp = numeros[i];
			for(k = 0; k<ida.size();k++){
				if(tmp == ida[k]){
					ady_tmp.push_back(indices[vuelta[k]]);

				}
				if(tmp == vuelta[k]){
					ady_tmp.push_back(indices[ida[k]]);
				}
			}
			ady.push_back(ady_tmp);
			ady_tmp.clear();
		}
		while(1){
			cin>>inicio;
			cin>>TTL;
			if(inicio == 0 && TTL == 0)
				break;
			
			if(!estado(indices,inicio))
				cout<<"Case "<<casos<<": "<<ady.size()<<" nodes not reachable from node "<<inicio<<" with TTL = "<<TTL<<"."<<endl;
			
			
			else
				cout<<"Case "<<casos<<": "<<bfs(indices[inicio],TTL,ady,numeros)<<" nodes not reachable from node "<<inicio<<" with TTL = "<<TTL<<"."<<endl;
			
			
			casos++;
		}
		
		indices.clear();
		numeros.clear();
		ida.clear();
		vuelta.clear();
		consultas.clear();
		ady.clear();
		ady_tmp.clear();
		cin>>NC;

	}
	return 0;
}
