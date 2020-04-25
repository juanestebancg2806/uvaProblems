#include <iostream>
#include <string>
#include <vector>

using namespace std;


class posicion{
	public:
		int i;
		int j;

};

int main(){
	int i,j,testC,filas,columnas,posi,posj,rot;
	string linea,tmp;
	vector<string> mapa;
	posicion pos;
	cin>>testC;
	bool band;
	while(testC--){
		cin>>filas>>columnas;
		band = true;
		cin.ignore();
		for(i = 0; i < filas; i++){
			getline(cin,linea);
			mapa.push_back(linea);
		}
		cin>>posi>>posj;

		pos.i = posi -1;
		pos.j = posj -1;
		rot = 90;
		cin.ignore();
		while(getline(cin,linea) && linea != "" && band){
			for(i = 0; i < linea.size() && band; i++){
				if(linea[i] == 'R'){
					if(rot == 0)
						rot = 270;
					else
						rot -= 90;
				}
				else if(linea[i] == 'L'){
					if(rot == 270)
						rot = 0;
					else
						rot += 90;
				}
				else if(linea[i] == 'F'){
					if(rot == 0){
						if(pos.j + 1 < columnas - 1){
							if(mapa[pos.i][pos.j + 1] != '*'){
								pos.j += 1;
							}
						}

					}
					else if(rot == 90){
						if(pos.i - 1 > 0){
							if(mapa[pos.i - 1 ][pos.j] != '*'){
								pos.i -= 1;
							}
						}
					}
					else if(rot == 180){
						if(pos.j - 1 > 0){
							if(mapa[pos.i][pos.j -1] != '*'){
								pos.j -= 1;
							}
						}
					}
					else if(rot == 270){
						if(pos.i + 1 < filas -1){
							if(mapa[pos.i + 1 ][pos.j] != '*'){
								pos.i += 1;
							}
						}
					}
				}
				else if(linea[i] == 'Q'){
					band = false;
					cout<<pos.i+1<<" "<<pos.j+1<<" ";
					if(rot == 0)
						cout<<"E"<<endl;
					else if(rot == 90)
						cout<<"N"<<endl;
					else if(rot == 180)
						cout<<"W"<<endl;
					else if(rot == 270)
						cout<<"S"<<endl;
					break;
				}
			}
		}


		if(testC)
			cout<<endl;
		mapa.clear();	

	}
	return 0;
}