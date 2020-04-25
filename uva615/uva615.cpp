#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;


int verificar_raiz(vector<vector<int> > ady,int valor){
	int i,j,cont = 0;
	for(i = 0; i<ady.size();i++){
		if(i != valor && !ady[i].empty()){
			for(j = 0; j<ady[i].size();j++){
				if(ady[i][j] == valor)
					cont++;
			}
		}
	}
	return cont;

}

bool dfs(vector<vector<int > > ady, int raiz){
	stack<int> pila;
	vector<bool> visitado(ady.size(),false);
	int i,tmp;
	visitado[raiz] = true;
	pila.push(raiz);
	while(!pila.empty()){
		tmp = pila.top();
		pila.pop();
		for(i = 0; i<ady[tmp].size(); i++){
			if(!visitado[ady[tmp][i]]){
				pila.push(ady[tmp][i]);
				visitado[ady[tmp][i]] = true;
			}
			else
				return false;
		}
	}
	for(i = 0; i<visitado.size();i++){
		if(!visitado[i])
			return false;
	}
	return true;
}

bool estado(map<int,int> indices,int valor){
	for(map<int,int>::iterator it = indices.begin(); it != indices.end() ; it++){
		if(valor == it->first)
			return true;

	}
	return false;
}


int main(){
	int valor1,valor2,i,j,k,casos = 1,tmp,raiz;
	bool band;
	vector<int> ady_tmp,ida,vuelta,chequeo;
	vector<vector<int> > ady;
	map<int,int> indices;
	map<int,int> numeros;
	while(true){
		band = true;
		cin>>valor1;
		cin>>valor2;
		if(valor1 == -1 && valor2 == -1)
			return 0;
		while(true){
			if(valor1 == 0 && valor2 == 0)
				break;
			ida.push_back(valor1);
			vuelta.push_back(valor2);
			cin>>valor1;
			cin>>valor2;

		}
		j = 0;
		for(i = 0; i<ida.size();i++){
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
		for(i = 0; i<j; i++){
			tmp = numeros[i];
			for(k = 0; k< ida.size();k++){
				if(tmp == ida[k]){
					ady_tmp.push_back(indices[vuelta[k]]);
				}
			}
			ady.push_back(ady_tmp);
			ady_tmp.clear();
			
		}
		for(i = 0; i<ady.size();i++){
			chequeo.push_back(verificar_raiz(ady,i));
		}
		tmp = 0;
		for(i = 0; i<chequeo.size();i++){
			//cout<<chequeo[i]<<" ";
			if(chequeo[i] == 0){
				raiz = i;
				tmp++;
			}
			if(chequeo[i] > 1){
				band = false;
				break;
			}

		}
		if(ida.empty()){
			cout<<"Case "<<casos<<" is a tree."<<endl;

		}
		else{
			if(tmp == 1 && band){
				if(dfs(ady,raiz))
					cout<<"Case "<<casos<<" is a tree."<<endl;
				else
					cout<<"Case "<<casos<<" is not a tree."<<endl;


			}

			else
				cout<<"Case "<<casos<<" is not a tree."<<endl;

		

		}
		

		casos++;	
		ady.clear();
		ady_tmp.clear();
		ida.clear();
		vuelta.clear();
		indices.clear();
		numeros.clear();
		chequeo.clear();

	}

	return 0;

}