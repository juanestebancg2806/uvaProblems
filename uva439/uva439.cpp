#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class posicion{
	public:
		int i;
		int j;

};

int bfs(posicion ini,posicion fin){
	queue<posicion> cola;
	vector<bool> visitado_tmp(8,false);
	vector<vector<bool> > visitado(8,visitado_tmp);
	vector<int> distancia_tmp(8,0);
	vector<vector<int> > distancia(8,distancia_tmp);
	int i,j;
	posicion pos,tmp;
	visitado[ini.i][ini.j] = true;
	distancia[ini.i][ini.j] = 0;
	cola.push(ini);
	while(!cola.empty()){
		tmp = cola.front();
		cola.pop();
		if(tmp.i == fin.i && tmp.j == fin.j)
			return distancia[fin.i][fin.j];

		for(i = 0; i < 8;i++){
			if(tmp.i + 2 <= 7){
				if(tmp.j + 1 <=7 ){
					pos.i = tmp.i + 2;
					pos.j = tmp.j +1;
					if(!visitado[pos.i][pos.j]){
						visitado[pos.i][pos.j] = true;
						distancia[pos.i][pos.j] = distancia[tmp.i][tmp.j] + 1;
						cola.push(pos);
						i++;
					}
				}
				if(tmp.j - 1 >= 0){
					pos.i = tmp.i + 2;
					pos.j = tmp.j - 1;
					if(!visitado[pos.i][pos.j]){
						visitado[pos.i][pos.j] = true;
						distancia[pos.i][pos.j] = distancia[tmp.i][tmp.j] + 1;
						cola.push(pos);
						i++;
					}

				}
			}
			if(tmp.i - 2 >= 0){
				if(tmp.j + 1 <= 7){
					pos.i = tmp.i -2;
					pos.j = tmp.j +1;
					if(!visitado[pos.i][pos.j]){
						visitado[pos.i][pos.j] = true;
						distancia[pos.i][pos.j] = distancia[tmp.i][tmp.j] + 1;
						cola.push(pos);
						i++;
					}
				}
				if(tmp.j -1 >= 0){
					pos.i = tmp.i - 2;
					pos.j = tmp.j - 1;
					if(!visitado[pos.i][pos.j]){
						visitado[pos.i][pos.j] = true;
						distancia[pos.i][pos.j] = distancia[tmp.i][tmp.j] + 1;
						cola.push(pos);
						i++;
					}
				}
			}
			if(tmp.j + 2 <= 7){
				if(tmp.i -1 >= 0){
					pos.i = tmp.i -1;
					pos.j = tmp.j +2;
					if(!visitado[pos.i][pos.j]){
						visitado[pos.i][pos.j] = true;
						distancia[pos.i][pos.j] = distancia[tmp.i][tmp.j] + 1;
						cola.push(pos);
						i++;
					}
				}
				if(tmp.i + 1 <= 7){
					pos.i = tmp.i +1;
					pos.j = tmp.j + 2;
					if(!visitado[pos.i][pos.j]){
						visitado[pos.i][pos.j] = true;
						distancia[pos.i][pos.j] = distancia[tmp.i][tmp.j] + 1;
						cola.push(pos);
						i++;
					}
				}
			}
			if(tmp.j -2 >= 0){
				if(tmp.i - 1 >=0){
					pos.i = tmp.i -1;
					pos.j = tmp.j -2;
					if(!visitado[pos.i][pos.j]){
						visitado[pos.i][pos.j] = true;
						distancia[pos.i][pos.j] = distancia[tmp.i][tmp.j] + 1;
						cola.push(pos);
						i++;
					}
				}
				if(tmp.i +1 <= 7){
					pos.i = tmp.i +1;
					pos.j = tmp.j -2;
					if(!visitado[pos.i][pos.j]){
						visitado[pos.i][pos.j] = true;
						distancia[pos.i][pos.j] = distancia[tmp.i][tmp.j] + 1;
						cola.push(pos);
						i++;
					}
				}
			}

		}
	}
}

int main(){
	int i,j,k;
	string linea,ini,fin;
	posicion pos1,pos2;
	char tmp;
	while(true){
		getline(cin,linea);
		if(linea == "")
			break;
		i = 0;
		while(linea[i] != ' '){
			ini.push_back(linea[i]);
			i++;
		}
		while(i < linea.size()){
			if(linea[i] != ' ')
				fin.push_back(linea[i]);
			i++; 
		}
		tmp = ini[0];
		pos1.i = ini[1] -'0';
		pos1.i -= 1;
		pos1.j = tmp - 97;
		//cout<<"ini "<<pos1.i<<" "<<pos1.j<<endl;
		tmp = fin[0];
		pos2.i = fin[1] - '0';
		pos2.i -= 1;
		pos2.j = tmp -97;
		//cout<<"fin "<<pos2.i<<" "<<pos2.j<<endl;
		cout<<"To get from "<<ini<<" to "<<fin<<" takes "<<bfs(pos1,pos2)<<" knight moves."<<endl;

		ini.clear();
		fin.clear();




	}
	return 0;
}