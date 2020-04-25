#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

void bfs(int raiz,int meta,vector<vector<int> > ady){
	queue<int> cola;
	vector<bool> visitado(301,false);
	vector<int> camino(301,-1);
	int i,j,tmp;
	visitado[raiz] = true;
	cola.push(raiz);
	vector<int> resul;
	bool band = false;
	while(!cola.empty()){
		tmp = cola.front();
		cola.pop();
		if(tmp == meta){
			band = true;
			break;
		}
		sort(ady[tmp].begin(),ady[tmp].end());
		for(i = 0; i < ady[tmp].size(); i++){
			if(!visitado[ady[tmp][i]]){
				cola.push(ady[tmp][i]);
				visitado[ady[tmp][i]] = true;
				camino[ady[tmp][i]] = tmp;

			}
		}
	}
	if(band){
		resul.push_back(meta);
		i = meta;
		while(i != -1){
			if(camino[i] != -1)
				resul.push_back(camino[i]);
			i = camino[i];
		}
		for(i = resul.size()-1 ; i>=0 ;i--){
			if(i == 0)
				cout<<resul[i]+1;
			
			else
				cout<<resul[i]+1<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"connection impossible"<<endl;
	}
	
}

int main(){
	int i,j,k,pos,valor,dato;
	string linea,tmp;
	vector<string> entrada;
	vector<int> ady_tmp,consultas;
	while(true){
		vector<vector<int> > ady(301,ady_tmp);
		getline(cin,tmp);
		if(tmp == "")
			break;
		valor = stoi(tmp);
		for(i = 0; i < valor; i++){
			cin>>linea;
			entrada.push_back(linea);
		}
		cin.ignore();
		getline(cin,tmp);
		if(tmp == "")
			break;
		valor = stoi(tmp);
		for(i = 0; i < valor*2; i++){
			cin>>dato;
			consultas.push_back(dato-1);
		}
		cin.ignore();
		for(i = 0; i < entrada.size(); i++){
			tmp.clear();
			for(j = 0; j < entrada[i].size(); j++){
				if(j == 0){
					while(entrada[i][j] != '-'){
						tmp.push_back(entrada[i][j]);
						j++;
					}
					pos = stoi(tmp)-1;
				}
				if(entrada[i][j] != ' ' && entrada[i][j] != ','){
					tmp.clear();
					while(j < entrada[i].size()){
						if(j == entrada[i].size()-1 && entrada[i][j] != '-'){
							tmp.push_back(entrada[i][j]);
							ady_tmp.push_back(stoi(tmp)-1);

						}
						else if(entrada[i][j] != ',' && entrada[i][j] != '-'){
							tmp.push_back(entrada[i][j]);
						}

						else if(entrada[i][j] == ',' && entrada[i][j] != '-'){
							ady_tmp.push_back(stoi(tmp)-1);
							tmp.clear();

						}
						j++;
					}
				}
			}
			ady[pos] = ady_tmp;
			ady_tmp.clear();
		}
		i = 0;
		while(i < 5){
			cout<<"-";
			i++;
		}
		cout<<endl;

		for(i = 0; i < consultas.size(); i+=2){
			bfs(consultas[i],consultas[i+1],ady);

		}
		ady_tmp.clear();
		consultas.clear();

	}
	return 0;

}