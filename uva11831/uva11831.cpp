#include <iostream>
#include <vector>
#include <string>

using namespace std;



void operacion(int filas,int columnas,vector<string> camino,string pasos){
	int i,j,direc = 0,stickers = 0,posi,posj;
	bool band = true;
	for(i = 0; i<camino.size() && band; i++){
		for(j = 0; j<camino[i].size(); j++){
			if(camino[i][j] == 'N'){
				direc = 90;
				posi = i;
				posj = j;
				band = false;
				break;
			}
			if(camino[i][j] == 'S'){
		
				direc = 270;
				posi = i;
				posj = j;
				band = false;
				break;
			}
			if(camino[i][j] == 'L'){
				direc = 0;
				posi = i;
				posj = j;
				band = false;
				break;
			}
			if(camino[i][j] == 'O'){
				direc = 180;
				posi = i;
				posj = j;
				band = false;
				break;
			}
		}
	}
	for(i = 0; i<pasos.size();i++){
		if(pasos[i] == 'D'){
			if(direc == 0)
				direc = 270;
			else
				direc -= 90;

		}
		else if(pasos[i] == 'E'){
			if(direc == 270)
				direc = 0;
			else
				direc += 90;
		}
		else{
			if(direc == 0){
				if(posj < columnas-1){
					posj++;
					if(camino[posi][posj] == '#')
						posj--;
					else if(camino[posi][posj] == '*'){
						camino[posi][posj] = '.';
						stickers++;
						
						}
					}

			}
			else if(direc == 90){
				if(posi > 0){
					posi--;
					if(camino[posi][posj] == '#')
						posi++;
					else if(camino[posi][posj] == '*'){
						camino[posi][posj] = '.';
						stickers++;

					}
						
				}

			}
			else if(direc == 180){
				if(posj > 0){
					posj--;
					if(camino[posi][posj] == '#')
						posj++;
					else if(camino[posi][posj] == '*'){
						camino[posi][posj] = '.';
						stickers++;
					}
				}
			}
			else if(direc == 270){
				if(posi < filas-1){
					posi++;
					if(camino[posi][posj] == '#')
						posi--;
					else if(camino[posi][posj] == '*'){
						camino[posi][posj] = '.';
						stickers++;
					}
				}
			}
		}
	}
	cout<<stickers<<endl;
}



int main(){

	int filas,columnas,instr,i,j;
	string linea,pasos;
	vector<string> camino;
	while(1){
		cin>>filas;
		cin>>columnas;
		cin>>instr;
		if(filas == 0 && columnas == 0 && instr == 0)
			return 0;
		for(i = 0; i<filas; i++){
			cin>>linea;
			camino.push_back(linea);
		}
		cin>>pasos;
		operacion(filas,columnas,camino,pasos);
		camino.clear();
	}
	return 0;
}



