#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



vector<long int> calculo(long int n, vector<long int> lady){
	vector<long int> resul;
	resul.push_back(-1);
	resul.push_back(-1);
	for(int i = 0; i <lady.size();i++){
		if(resul[0] != -1 && lady[i] < n){
			if(n-lady[i] < n-resul[0])
				resul[0] = lady[i];
		}
		if(resul[0] == -1 && lady[i]<n)
			resul[0] = lady[i];

		if(resul[1] != -1 && lady[i] > n){
			if(lady[i]-n < resul[1]-n)
				resul[1] = lady[i];
		}
		if(resul[1] == -1 && lady[i] > n)
			resul[1] = lady[i];
	}
	return resul;

}

int main(){
	long int N,tmp,Q,aux;
	vector<long int> lady;
	vector<long int> luchu;
	vector<long int> v;
	cin>>N;
	for(int i = 0; i<N; i++){
		cin>>tmp;
		lady.push_back(tmp);
	}
	cin>>Q;
	for(int i = 0; i<Q;i++){
		cin>>tmp;
		luchu.push_back(tmp);
	}

	for(int i = 0; i<Q; i++){
		aux = luchu[i];
		v = calculo(aux,lady);
		if(v[0] == -1)
			cout<<"X ";
		else
			cout<<v[0]<<" ";
		if(v[1] == -1)
			cout<<"X";
		else
			cout<<v[1];

		cout<<endl;

	}




	return 0;
}
