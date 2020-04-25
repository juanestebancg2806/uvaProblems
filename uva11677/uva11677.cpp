#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;



int main(){
	int H1,M1,H2,M2,resul,tmp;
	while(true){
		resul = 0;
		cin>>H1;
		cin>>M1;
		cin>>H2;
		cin>>M2;
		if(H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0)
			return 0;
		if(H1 == 0)
			H1 = 24;
		if(H2 == 0)
			H2 = 24;
		if(H1 == H2 && M2 > M1)
			resul = (M2-M1);
		
		else if(H1 >= H2)
			resul = (H2+24-H1)*60 + (M2-M1);
		else
			resul = abs(H1 - H2)*60 +(M2-M1);
		
		cout<<resul<<endl;
	}
	return 0;

}