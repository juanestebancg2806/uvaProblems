#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <stdio.h>
#include <stack>
#include <stdlib.h>
using namespace std;



bool sin_salida(vector<int> &v,int &ant,vector<bool> &visitado){
	for(int i = 0; i<v.size();i++){
		if(v[i] != ant && !visitado[v[i]])
			return true;
	}
	return false;
}

void dfs(int raiz,vector<vector<int> > ady,long int k,int ant){
	stack<int> pila;
	char letra;
	vector<bool> visitado(26,false);
	int tmp,i,ante = ant;
	long int j = 1;
	pila.push(raiz);
	while(!pila.empty()){
		tmp = pila.top();
		pila.pop();
		if(ady[tmp].empty()){
			letra = tmp +65;
			cout<<"/"<<letra<<endl;
		}
		for(i = 0; i<ady[tmp].size();i++){
			if(!sin_salida(ady[tmp],ante,visitado) || ady[tmp].empty()){
				letra = tmp +65;
				cout<<"/"<<letra<<endl;
				return;
			}
			if(j == k && sin_salida(ady[tmp],tmp,visitado)){
				letra = tmp+65;
				cout<<letra<<" ";
				visitado[tmp] = true;
				j = 0;
			}
			if(!visitado[ady[tmp][i]] && ady[tmp][i] != ante){
				j += 1;
				ante = tmp;
				pila.push(ady[tmp][i]);
				break;
			}
		}
	}


}


int main(){
	vector<int> adytmp;
	vector<long int> consulta;
	char tmp1,tmp2;
	int i,j;
	char temp;
	string linea,num;
	getline(cin,linea);
	while(linea != "#"){
		vector<vector<int> > ady(26,adytmp);
		vector<bool> visitado(26,false);
		for(i = 0; i<linea.size();i++){
			if(linea[i] == '.'){
				j = 0;
				while(i<linea.size()){
					if(j >= 2 && linea[i] != ' '){
						num.push_back(linea[i]);

					}
					if(linea[i] != '.' && linea[i] != ' ' && j<2){
						consulta.push_back(linea[i]-65);
						j++;

					}
					i++;
				}
				break;

			}
				
			 else if(i<linea.size() && linea[i] != ';' && linea[i] != '.'){
				temp = linea[i];
				i++;
				while(linea[i] != ';' && linea[i] != '.' && i<linea.size()){
					if(linea[i] != ':')
						ady[temp-65].push_back(linea[i]-65);
					i++;
				}
				i--;
			}
		}
		consulta.push_back(stoi(num));
		dfs(consulta[0],ady,consulta[2],consulta[1]);
		consulta.clear();
		num.clear();
		getline(cin,linea);
	}
	return 0;
}