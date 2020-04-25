#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


void inicializar(map<string,string> &codigo){
	string hack = """";
	codigo[".-"] = "A";codigo["-..."] = "B";codigo["-.-."] = "C";codigo["-.."] = "D";codigo["."] = "E";	codigo["..-."] = "F";codigo["--."] = "G";codigo["...."] = "H";
	codigo[".."] = "I"; codigo[".---"] = "J"; codigo["-.-"] = "K"; codigo[".-.."] = "L"; codigo["--"] = "M"; codigo["-."] = "N"; codigo["---"] = "O";codigo[".--."] = "P";
	codigo["--.-"] = "Q";codigo[".-."] = "R";codigo["..."] = "S";codigo["-"] = "T";codigo["..-"] = "U";codigo["...-"] = "V";codigo[".--"] = "W";codigo["-..-"] = "X";codigo["-.--"] = "Y";
	codigo["--.."] = "Z"; codigo["-----"] = "0"; codigo[".----"] = "1"; codigo["..---"] = "2"; codigo["...--"] = "3"; codigo["....-"] = "4"; codigo["....."] = "5"; codigo["-...."] = "6"; codigo["--..."] = "7";
	codigo["---.."] = "8"; codigo["----."] = "9"; codigo[".-.-.-"] = "."; codigo["--..--"] = ","; codigo["..--.."] = "?"; codigo[".----."] = "'"; codigo["-.-.--"] = "!"; codigo["-..-."] = "/"; codigo["-.--."] = "(";
	codigo["-.--.-"] = ")"; codigo[".-..."] = "&"; codigo["---..."] = ":"; codigo["-.-.-."] = ";"; codigo["-...-"] = "="; codigo[".-.-."] = "+"; codigo["-....-"] = "-"; codigo["..--.-"] = "_"; codigo[".-..-."] = hack[0]; 
	codigo[".--.-."] = "@";
}


int main(){
	map<string,string> codigo;
	char d = '"';
	int casos,cont = 1,espacio,conteo;
	string linea,tmp;
	inicializar(codigo);
	cin>>casos;
	cin.ignore();
	conteo = casos;
	while(casos--){
		espacio = 0;
		getline(cin,linea);
		cout<<"Message #"<<cont<<endl;
		for(int i = 0; i<linea.size();i++){
			if(linea[i] != ' '){
				while(linea[i] != ' ' && i<linea.size()){
					tmp.push_back(linea[i]);
					i++;
				}
				if(tmp == ".-..-.")
					cout<<d;
				
				else
					cout<<codigo[tmp];
			}
			if(linea[i] == ' '){
				while(linea[i] == ' ' && i<linea.size()){
					espacio++;
					i++;
				}
				if(espacio == 2){
					cout<<" ";
				}

				espacio = 0;
				i--;
			}
			tmp.clear();
		}
		cout<<endl;
		if(conteo != cont)
			cout<<endl;

		
		cont++;
	}

	return 0;
}