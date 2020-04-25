#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct persona{
	char nombre[15];
	int monto_total;
	int cantidad_regalos;
	char personas_regalos[11][15];
};

int calculo(struct persona *personas,char* nom,int total){
	int total_recibido = 0,total_dado = 0,i,j,tmp;
	for(i = 0; i<total; i++){
		if(strcmp(personas[i].nombre,nom) == 0){
			if(personas[i].cantidad_regalos != 0){
				if(personas[i].monto_total%personas[i].cantidad_regalos != 0){
				tmp = (personas[i].monto_total/personas[i].cantidad_regalos)*personas[i].cantidad_regalos;
				total_dado += tmp;	
				}
				else{
					total_dado += personas[i].monto_total;
				}

			}
				
		}
		for(j = 0; j<personas[i].cantidad_regalos;j++){
			if(personas[i].cantidad_regalos != 0){
				tmp = (personas[i].monto_total/personas[i].cantidad_regalos);
				if(strcmp(personas[i].personas_regalos[j],nom) == 0){
					total_recibido += tmp;

				}	
			}
			
		}
	}

	return total_recibido-total_dado;

}

int main(){
	int total_personas,i,j,tmp,cont = 0;
	char nombre_personas[11][15];
	struct persona personas[11];
	char nombretmp[15];
	while(scanf("%i",&total_personas) != EOF){
		if (cont != 0)
			printf("\n");
		for(i = 0;i<total_personas;i++){
			scanf("%s",nombretmp);
			strcpy(nombre_personas[i],nombretmp);

		}
		for(i = 0;i<total_personas;i++){
			scanf("%s",nombretmp);
			strcpy(personas[i].nombre,nombretmp);
			scanf("%i",&tmp);
			personas[i].monto_total = tmp;
			scanf("%i",&tmp);
			personas[i].cantidad_regalos = tmp;
			for(j = 0; j<tmp;j++){
				scanf("%s",nombretmp);
				strcpy(personas[i].personas_regalos[j],nombretmp);
			}

		}
		for(i = 0;i< total_personas;i++){
			printf("%s %i\n",nombre_personas[i],calculo(personas,nombre_personas[i],total_personas));
		}
		cont++;
		

	}
	return 0;
}