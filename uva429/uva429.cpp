#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;


int diferencia(string str1,string str2){
	int i,cont = 0;
	if(str1.size() < str2.size()){
		for(i = 0; i<str1.size();i++){
			if(str1[i] != str2[i])
				cont++;
		}
		cont = (str2.size() - i) + cont;

	}
	else{
		for(i = 0; i<str2.size();i++){
			if(str1[i] != str2[i])
				cont++;
		}
		cont = (str1.size() - i) + cont;
	}
	return cont;
}

int aux(vector<int> camino,int meta){
	int i = camino[meta],j = 0;
	while(i != -1){
		j++;
		i = camino[i];
	}
	return j;
}

int bfs(int raiz,int meta,vector<vector<int> > ady,map<int,string> numeros){
	queue<int> cola;
	vector<bool> visitados(ady.size(),false);
	vector<int> camino(ady.size(),-1);
	int i,j = 0,tmp;
	visitados[raiz] = true;
	cola.push(raiz);
	while(!cola.empty()){
		tmp = cola.front();
		cola.pop();
		if(tmp == meta){
			return aux(camino,meta);
		}
		for(i = 0; i<ady[tmp].size(); i++){
			if(!visitados[ady[tmp][i]]){
				cola.push(ady[tmp][i]);
				visitados[ady[tmp][i]] = true;
				camino[ady[tmp][i]] = tmp;

			}
		}
	}
	return 0;
}

int main(){
	int casos,i,j,cont;
	vector<string> diccionario,consultas;
	vector<vector<int > > ady;
	vector<int> ady_tmp;
	map<string,int> indices;
	map<int,string> numeros;
	string palabra,tmp;
	cin>>casos;
	while(casos--){
		j = 0;
		while(true){
			cin>>palabra;
			if(palabra == "*")
				break;
			diccionario.push_back(palabra);
			numeros[j] = palabra;
			indices[palabra] = j;
			j++;

		}
		
		for(i = 0; i<diccionario.size(); i++){
			for(j = 0 ; j < diccionario.size(); j++){
				if(diferencia(diccionario[i],diccionario[j]) == 1)
					ady_tmp.push_back(j);
			}
			ady.push_back(ady_tmp);
			ady_tmp.clear();
		}
		i = 0;
		cin.ignore();
		while(getline(cin,palabra) && palabra != ""){
			i = 0;
			while(palabra[i] != ' '){
				tmp.push_back(palabra[i]);
				i++;

			}
			consultas.push_back(tmp);
			tmp = palabra.substr(i+1,palabra.size());
			consultas.push_back(tmp);
			tmp.clear();
			

			
		}
		
		for(i = 0; i<consultas.size();i+=2){
			if(consultas[i] == consultas[i+1])
				cout<<consultas[i]<<" "<<consultas[i+1]<<" "<<0<<endl;
			else
				cout<<consultas[i]<<" "<<consultas[i+1]<<" "<<bfs(indices[consultas[i]],indices[consultas[i+1]],ady,numeros)<<endl;

		}
		if(casos != 0)
			cout<<endl;
		consultas.clear();
		ady.clear();
		ady_tmp.clear();
		indices.clear();
		numeros.clear();
		diccionario.clear();

		

	}
	return 0;
}