#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

void simplificar(int &num,int &den){
	num = abs(num);
	int i = 2;
	while(i <= num && i <= den){
		if(num%i == 0 && den%i == 0){
			num = num / i;
			den = den / i;
			i = 1;
		}
		i++;
	}

}


int main(){
	int i,j,k,valores,casos = 1,tmp,num,den;
	double resul,tmp2;
	vector<int> datos;
	string tam,tam2,tam3;
	bool band;
	while(true){
		resul = 0.0;
		num = 0;
		band = true;
		cin>>k;
		if(k == 0)
			break;
		i = 0;
		den = k;
		while(i < k){
			cin>>valores;
			resul += valores;
			num += valores;
			i++;
		}
		cout<<"Case "<<casos<<":"<<endl;
		if(num == 0)
			cout<<0<<endl;
		else if(num % k == 0 && resul > 0)
			cout<<num/k<<endl;

		else if(num % k == 0 && resul < 0)
			cout<<"- "<<abs(num/k)<<endl;
		else if(num % k != 0){
			simplificar(num,den);
			tam = to_string(den);
			tam2 = to_string(num%den); 
			tam3 = to_string(num/den);
			i = 0;
			
			if(fabs(resul/k) > 1 && resul > 0){
				if(tam.size() > tam2.size()){	
					while(i < tam3.size() + tam.size() -1 ){
						cout<<" ";
						i++;
					}
				}
				else{
					while(i < tam3.size()){
						cout<<" ";
						i++;
					}
				}
				i = 0;
				cout<<num%den<<endl;
				cout<<num/den;
				while(i < tam.size()){
					cout<<"-";
					i++;
				}
				cout<<endl;
				i = 0;
				while(i < tam3.size()){
					cout<<" ";
					i++;
				}
				cout<<den<<endl;
			}
			else if(fabs(resul/k) > 1 && resul < 0){
				if(tam.size() > tam2.size()){
					while(i < tam.size()+tam3.size()+1){
						cout<<" ";
						i++;
					}

				}
				else{
					while(i < 2 + tam3.size()){
						cout<<" ";
						i++;
					}

				}
				
				i = 0;
				cout<<num%den<<endl;
				cout<<"- "<<num/den;
				while(i < tam.size()){
					cout<<"-";
					i++;
				}
				cout<<endl;
				i = 0;
				while(i < tam3.size()+2){
					cout<<" ";
					i++;
				}
				cout<<den<<endl;
			}
			else if(fabs(resul/k) < 1 && resul > 0){
				if(tam.size() > tam2.size()){
					while(i < tam.size()-1){
						cout<<" ";
						i++;
					}
				}
				
				i = 0;
				cout<<num<<endl;
				while(i < tam.size()){
					cout<<"-";
					i++;
				}
				cout<<endl;
				cout<<den<<endl;

			}
			else if(fabs(resul / k) < 1 && resul < 0){
				if(tam.size() > tam2.size()){
					while(i < tam.size()+1){
						cout<<" ";
						i++;
					}
				}
				else{
						cout<<"  ";
					
				}
				i = 0;
				cout<<num<<endl;
				cout<<"- ";
				while(i < tam.size()){
					cout<<"-";
					i++;
				}
				cout<<endl;
				i = 0;
				cout<<"  "<<den<<endl;
			}

		
		}
		casos++;
	}
	return 0;
}