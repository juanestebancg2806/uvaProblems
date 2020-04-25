#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

string encontrar_nombres(vector<string> nombres,string cuenta){
	string nombre,tmp;
	for(int i = 0; i<nombres.size(); i++){
		tmp = nombres[i].substr(0,3);
		if(tmp == cuenta){
			nombre = nombres[i].substr(3,nombres[i].size());
			return nombre;
		}
	}

}

void operacion(vector<string> nombres,vector<string> transacciones,vector<long int> montos,string tmp,string espacios){
	int i,j;
	double resul,total = 0.0;
	string cuenta,secuencia,subtr,nom;
	i = 0;
	while(i < transacciones.size()){
		subtr = transacciones[i].substr(0,3);
		if(subtr == tmp){
			cuenta = transacciones[i].substr(3,6);
			resul = montos[i]/100.0;
			total += resul;
			nom = encontrar_nombres(nombres,cuenta);
			//cout<<cuenta<<" "<<nom;
			printf("%s %-30s %10.2lf\n",cuenta.c_str(),nom.c_str(),resul);
			//printf("%.2f\n", resul);

		}
		i++;
	}
	if(total < 0.0)
		total = fabs(total);
	else
		total = -total;
	printf("999 Out of Balance                 %10.2lf\n",total);
}

int main(){
	int i,j;
	long int monto;
	string linea,tmp,tmp2;
	vector<string> nombres,transacciones;
	vector<long int> montos;
	vector<string> resul;
	while(true){
		getline(cin,linea);
		tmp = linea.substr(0,3);
		if(tmp == "000")
			break;
		nombres.push_back(linea);
		
	}
	while(true){
		cin>>linea;
		cin>>monto;
		tmp = linea.substr(0,3);
		if(tmp == "000")
			break;
		transacciones.push_back(linea);
		montos.push_back(monto);
		

	}
	
	i = 0;
	while(i<transacciones.size() && i+1<transacciones.size()){
		j = i+1;
		monto = montos[i];
		tmp = transacciones[i].substr(0,3);
		tmp2 = transacciones[j].substr(0,3);
		while(i < transacciones.size() && tmp == tmp2 && j<transacciones.size()){
			monto += montos[j];
			j++;
			if(j<transacciones.size())
				tmp2 = transacciones[j].substr(0,3);
		}
		if(monto != 0 ){
			j--;
			tmp = transacciones[j].substr(0,3);
			linea = "*** Transaction " + tmp + " is out of balance ***";
			cout<<linea<<endl;
			operacion(nombres,transacciones,montos,tmp,linea);
			cout<<endl;
			j++;
		}

		i = j;
		if(i == transacciones.size()-1){
			tmp = transacciones[i].substr(0,3);
			linea = "*** Transaction " + tmp + " is out of balance ***";
			cout<<linea<<endl;
			operacion(nombres,transacciones,montos,tmp,linea);
			cout<<endl;
		}
		
	}
	




	return 0;
}