#include <iostream>
#include <vector>

using namespace std;


int main(){
	int tiempo,papas,i,j,k,tmp,resul,tmp2,ci,cj,citmp,cjtmp;
	vector<int> periodos;
	while(cin>>tiempo){
		resul = 0;
		cin>>papas;
		for(i = 0; i < papas; i++){
			cin>>tmp;
			periodos.push_back(tmp);
		}
		i = 0;
		while(i<periodos.size()){
			citmp = periodos[i];
			j = periodos[i]+tiempo-1;
			tmp2 = 0;
			k = i;
			while(periodos[k] <= j && k<periodos.size()){
				tmp2++;
				k++;
			}
			cjtmp = periodos[k-1];
			if(tmp2 > resul){
				resul = tmp2;
				ci = citmp;
				cj = cjtmp;
			}
			i++;

		}
		cout<<resul<<" "<<ci<<" "<<cj<<endl;
		periodos.clear();
	}
	return 0;
}

