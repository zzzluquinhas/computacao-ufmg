#include <stdio.h>
#include <stdlib.h>

void percorre(){
	int vector[3][3] = {1,2,3,4,5,6,7,8,9};

	for(int i=0; i<3; i++){

		if(i%2==0){
			for(int j=0; j<3; j++){
				printf("%d ",vector[i][j]);
			}
		}
		
		else{
			for(int j=2; j>=0; j--){
				printf("%d ",vector[i][j]);
			}
		}
		
		printf("\n");
	}

}
