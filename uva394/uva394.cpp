#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class array{
	public:
		string nombre;
		int base;
		int tamano;
		int dimensiones;
		vector<int> lowers;
		vector<int> uppers;

};

int busqueda_dimension(vector<array> principal,string nombre){
	for(int i = 0; i<principal.size();i++){
		if(nombre == principal[i].nombre){
			return principal[i].dimensiones;
		}
	}
}

int calculo(string nombre,vector<array> principal,vector<int> intervalos){
	vector<int> vec,lowers_tmp,uppers_tmp;
	bool band = true;
	int tmp,pos,i,j,k,l,resul;
	for(i = 0; i <principal.size() && band; i++){
		if(nombre == principal[i].nombre){
			vec.push_back(principal[i].tamano);
			lowers_tmp = principal[i].lowers;
			uppers_tmp = principal[i].uppers;
			pos = 0;
			k = lowers_tmp.size()-1;
			for(j = 0; j < intervalos.size();j++,k--){
				if(j == intervalos.size()-1){		
					l = 0;
					reverse(vec.begin(),vec.end());
					tmp = principal[i].base;
					while(l<vec.size()){
						tmp -= lowers_tmp[l]*vec[l];
						l++;

					}
					vec.insert(vec.begin(),tmp);
					band = false;
					break;

				}
				else{
					tmp = vec[pos]*(uppers_tmp[k]-lowers_tmp[k]+1);
					vec.push_back(tmp);
					pos++;
				}
				
			}
		}
	}
	resul = vec[0];
	for(i = 1,j = 0; i<vec.size();i++,j++){
		resul += vec[i]*intervalos[j];
	}
	return resul;

}

int main(){

	int N,R,valores;
	string nom_tmp;
	vector<array> principal;
	vector<string> nom_consultas;
	vector<vector<int> > num_consultas;
	vector<int> v;	
	cin>>N;
	cin>>R;
	for(int i = 0; i<N; i++){
		array array_tmp;
		cin>>nom_tmp;
		array_tmp.nombre = nom_tmp;
		cin>>valores;
		array_tmp.base = valores;
		cin>>valores;
		array_tmp.tamano = valores;
		cin>>valores;
		array_tmp.dimensiones = valores;
		for(int j = 0; j<array_tmp.dimensiones*2;j++){
			cin>>valores;
			if(j%2 == 0)
				array_tmp.lowers.push_back(valores);
			
			else
				array_tmp.uppers.push_back(valores);
	}

		principal.push_back(array_tmp);
	}
	
	for(int i = 0; i<R; i++){
		cin>>nom_tmp;
		nom_consultas.push_back(nom_tmp);
		int dim = busqueda_dimension(principal,nom_tmp);
		for(int j = 0; j< dim;j++){
			cin>>valores;
			v.push_back(valores);
		}
		num_consultas.push_back(v);
		v.clear();
	}

	for(int i = 0; i<nom_consultas.size();i++){
		cout<<nom_consultas[i]<<"[";
		for(int j = 0;j<num_consultas[i].size();j++){
			if(j == num_consultas[i].size()-1){
				cout<<num_consultas[i][j]<<"]"<<" = ";
			}
			else{
				cout<<num_consultas[i][j]<<", ";

			}
			
		}
		cout<<calculo(nom_consultas[i],principal,num_consultas[i])<<endl;
	}

	return 0;
}