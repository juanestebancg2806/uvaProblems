#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){
	int TC,A,B,C,x,y,z,f;
	scanf("%d",&TC);
	while(TC--){
		f = 0;
		scanf("%d %d %d",&A,&B,&C);
		for(x = -100; x <= 100 && !f; x++){
			for (y = -100; y <=100 && !f; y++){
				for(z = -100; z <= 100 && !f;z++){
					f = f ||  x != y && x != z && y != z && x+y+z == A && x*y*z == B && (x*x+y*y+z*z == C);
					if (f)
						printf("%d %d %d\n",x,y,z);
				}
			}
		}
		if(!f)
			printf("No solution.\n");


	}
	return 0;
}