#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char linea[256];
	int casos,contM,contF,i,j;
	scanf("%i\n",&casos);
	while(casos--){
		contM = 0;
		contF = 0;
		linea[strlen(linea)-1] = '\0';
		fgets(linea,256,stdin);
		for(i = 0; i<strlen(linea); i++){
			if(linea[i] == 'M')
				contM++;
			if(linea[i] == 'F')
				contF++;
		}

		if(contM == contF){
			if(contM == 1 && contF ==1)
				printf("NO LOOP");
			else
				printf("LOOP");
		}
		else{
			printf("NO LOOP");
		}
		printf("\n");


	}
	return 0;
}




