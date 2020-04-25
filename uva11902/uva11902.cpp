#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> to_zero(vector<int> v){
	for(int i = 0; i<v.size();i++)
		v[i] = 0;
	return v;
}


vector<int> dfs(vector<vector<int > > matady,int valor){
	stack<int> pila;
	int tmp,i,j,raiz;
	vector<int> resul;
	vector<bool> visitados(matady.size(),false);
	pila.push(0);
	visitados[0] = true;
	while(!pila.empty()){
		tmp = pila.top();
		pila.pop();
		for(i = 0; i<matady[tmp].size();i++){
			if(matady[tmp][i] != 0){
				if(!visitados[i] && i != valor){
					visitados[i] = true;
					pila.push(i);
				}
			}

			
		}
	}
	for(i = 0; i<visitados.size(); i++){
		if(!visitados[i])
			resul.push_back(i);
		else
			resul.push_back(-1);

	}
	return resul;

}



void operacion(vector<vector<int> > matady){
	vector<char> band;
	vector<vector<char> > resul;
	int i,j = 0,k;
	vector<int> temp,res_dfs,res2_dfs;
	res_dfs = dfs(matady,-1);
	for(i = 0; i<matady.size();i++){
		temp = matady[i];
		matady[i] = to_zero(temp);
		res2_dfs = dfs(matady,i);
		matady[i] = temp;
		k = 0;
		j = 0;
		if(i == 0){
			band.push_back('Y');
			j++;
		}
		while(j < res_dfs.size()){
			if(res_dfs[j] == res2_dfs[j]){
				band.push_back('N');
			}
			else{
				band.push_back('Y');
			}
			j++;

		}
		resul.push_back(band);
		band.clear();
	}
	for(i = 0; i<resul.size();i++){
		cout<<"+";
		k = 0;
		while(k<(2*resul.size())-1){
			cout<<"-";
			k++;
		}
		cout<<"+"<<endl;
		cout<<"|";
		for(j = 0; j<resul[i].size();j++)
			cout<<resul[i][j]<<"|";
		cout<<endl;
	}
	k = 0;
	cout<<"+";
	while(k<(2*resul.size())-1){
		cout<<"-";
		k++;
	}
	cout<<"+"<<endl;
	
}


int main(){
	int casos,valor,i,j,tam,cont = 1,imp;
	vector<int> matady_tmp;
	vector<vector<int> > matady;
	cin>>casos;
	imp = casos;
	while(casos--){
		imp--;
		cin>>tam;
		for(i = 0; i<tam;i++){
			for(j = 0; j<tam;j++){
				cin>>valor;
				matady_tmp.push_back(valor);
			}
			matady.push_back(matady_tmp);
			matady_tmp.clear();
		}
		cout<<"Case "<<cont<<":"<<endl;
		operacion(matady);
		matady_tmp.clear();
		matady.clear();	
		cont++;



	}
	return 0;
}

