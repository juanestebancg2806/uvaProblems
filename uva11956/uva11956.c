#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void limpiar(int *arr){
	int i;
	for(i = 0; i<100; i++)
		arr[i] = 0;
}


int main(){
	int casos,cont =1,i,it;
	int display[100];
	scanf("%i",&casos);
	while(casos--){
		char comandos[100001];
		it = 0;
		limpiar(display);
		scanf("%s",comandos);
		for(i = 0; i<strlen(comandos);i++){
			if(comandos[i] == '>'){
				if(it == 99)
					it = 0;
				else
					it++;
			}
			if(comandos[i] == '<'){
				if(it == 0)
					it = 99;
				else
					it--;
			}
			if(comandos[i] == '+'){
				if(display[it] == 255 )
					display[it] = 0;
				else
					display[it] += 1;
			}
			if(comandos[i] == '-'){
				if(display[it] == 0)
					display[it] = 255;
				else
					display[it] -= 1;
			}
		}
		printf("Case %i: ",cont);
		for(i = 0; i< 100; i++){
			if(i == 99)
				printf("%02X",display[i]);
			else
				printf("%02X ",display[i]);
		}

		cont++;
		printf("\n");
	}
	return 0;
}