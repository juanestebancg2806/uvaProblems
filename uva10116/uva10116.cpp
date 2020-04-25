#include <iostream>
#include <vector>
#include <string>

using namespace std;

class posicion{
	public:
		int i;
		int j;

};


void calculo(vector<string> camino,int filas,int columnas,int inicio){
	vector<posicion> vec;
	posicion pos;
	bool ciclo = false;
	vector<bool> visitados_tmp(columnas,false);
	vector<vector<bool > > visitados;
	int i = 0,j = inicio-1, pasos = 0;
	for(i = 0; i<filas;i++){
		visitados.push_back(visitados_tmp);
	}
	i = 0;
	visitados[0][inicio-1] = true;
	pos.i = i;
	pos.j = j;
	vec.push_back(pos);
	while(true){
		if(camino[i][j] == 'W'){
			if(j > 0 ){
				j--;
				pos.i = i;
				pos.j = j;
				if(!visitados[i][j]){
					visitados[i][j] = true;
					vec.push_back(pos);

				}
				else{
					ciclo = true;
					vec.push_back(pos);
					break;
				}
			}
			else{
				break;
			}
		}
		else if(camino[i][j] == 'S'){
			if(i < filas-1 ){
				i++;
				pos.i = i;
				pos.j = j;
				if(!visitados[i][j]){
					visitados[i][j] = true;
					vec.push_back(pos);

				}
				else{
					ciclo = true;
					vec.push_back(pos);
					break;
				}
				
			}
			else{
				break;
			}
		}
		else if(camino[i][j] == 'E'){
			if(j < columnas-1){
				j++;
				pos.i = i;
				pos.j = j;
				if(!visitados[i][j]){
					visitados[i][j] = true;
					vec.push_back(pos);
				}
				else{
					ciclo = true;	
					vec.push_back(pos);
					break;
				}
			}
			else{
				break;
			}
		}
		else if(camino[i][j] == 'N'){
			if(i > 0 ){
				i--;
				pos.i = i;
				pos.j = j;
				if(!visitados[i][j]){
					visitados[i][j] = true;
					vec.push_back(pos);
				}
				else{
					ciclo = true;
					vec.push_back(pos);
					break;
				}
			}
			else{
				break;
			}
		}

	}
	if(!ciclo){
		cout<<vec.size()<<" step(s) to exit"<<endl;

	}
	else{
		pos = vec[vec.size()-1];
		j = 1;
		for(i = vec.size()-2; i >= 0;i--){
			if(vec[i].i == pos.i && vec[i].j == pos.j){
				break;
			}
			else{
				j++;
			}
		}
		cout<<(vec.size()-1)-j<<" step(s) before a loop of "<<j<<" step(s)"<<endl;

	}

}

int main(){
	int i,j,filas,columnas,inicio;
	vector<string>camino;
	string linea;
	while(true){
		cin>>filas;
		cin>>columnas;
		cin>>inicio;
		if(filas == 0 && columnas == 0 && inicio == 0)
			return 0;
		for(i = 0; i<filas;i++){
			cin>>linea;
			camino.push_back(linea);
		}
		calculo(camino,filas,columnas,inicio);
		camino.clear();

	}

	return 0;
}