#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
	long int libros_disponibles,dinero,ci ,cj,tmp,tmp1,tmp2,i,j;
	vector<long int> precios,vec;
	while(scanf("%li\n",&libros_disponibles)!= EOF){
		ci = 0;
		cj = 0;
		tmp1 = 0;
		tmp2 = 0;
		bool band = true;
		for(i = 0; i<libros_disponibles; i++){
			cin>>tmp;
			precios.push_back(tmp);
		}
		cin>>dinero;
		sort(precios.begin(),precios.end());
		i = 0;
		j = precios.size()-1;
		while(i<j){
			if(precios[i]+precios[j] > dinero)
				j--;
			else if(precios[i] + precios[j] < dinero)
				i++;
			else{
				if(ci != 0){
					tmp1 = precios[i];
					tmp2 = precios[j];
					if(tmp2-tmp1 < cj - ci){
						ci = tmp1;
						cj = tmp2;
					}

				}
				else{
					ci = precios[i];
					cj = precios[j];
				}
				i++;
				j--;
			}
		}

		cout<<"Peter should buy books whose prices are "<<ci<<" and "<<cj<<"."<<endl;
		cout<<endl;
		precios.clear();

	}
	return 0;
}

