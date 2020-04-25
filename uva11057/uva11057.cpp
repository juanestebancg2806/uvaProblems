#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



int main(){
	long int libros_disponibles,dinero,ci ,cj,tmp;
	vector<long int> precios;
	while(scanf("%li\n",&libros_disponibles)!= EOF){
		ci = 0;
		cj = 0;
		for(int i = 0; i<libros_disponibles; i++){
			cin>>tmp;
			precios.push_back(tmp);
		}
		cin>>dinero;
		sort(precios.begin(),precios.end());
		for(int i = 0; i<precios.size();i++){
			for(int j = i+1; j<precios.size();j++){
				if(ci != 0){
					if(precios[j] + precios[i] == dinero && precios[j]-precios[i]<cj-ci){
						cj = precios[j];
						ci = precios[i];
					}
				}
				if(ci == 0 && precios[j] + precios[i] == dinero){
					ci = precios[i];
					cj = precios[j];
				}
			}
		}

		cout<<"Peter should buy books whose prices are "<<ci<<" and "<<cj<<"."<<endl;
		cout<<endl;
		precios.clear();

	}
	return 0;
}

