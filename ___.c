    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #define MAX 100

void maiorMenor(int j, int x, int k, int vNumero[MAX], int *maior, int *menor){
    if(k<x && j<x){
      if((*maior == 0 && vNumero[j] >= vNumero[k])|| (*maior != 0 && vNumero[j] <= vNumero[k] )){
    	k++;
     	maiorMenor( j, x, k, vNumero, maior, menor);
      }else{
		j++;
		k=0;
		maiorMenor( j, x, k, vNumero,maior, menor);
      }
    }else{
    	if(*maior == 0){
       *maior = vNumero[j];
       	maiorMenor(0, x, 0, vNumero,maior, menor);
       }else{
        *menor = vNumero[j];
	   }
	}
  }
    
  int menor(int j, int x, int k, int vNumero[MAX]){
    if(k<x && j<x){
      if( vNumero[j] <= vNumero[k]){
    	k++;
     	return 	menor( j, x, k, vNumero);
      }else{
		j++;
		k=0;
		return 	menor( j, x, k, vNumero);
      }
    }else{
      return vNumero[j];
	}
    }

    int main(void){

     int x;
     int *vNumero;
     int i=0;
     int maior = 0;
     int menor = 0;

     vNumero = malloc (MAX*sizeof (int));
     scanf(" %d", &x);
     
     for(i=0; i<x; i++){
      scanf(" \n%d", &vNumero[i]);
     }
  
     maiorMenor(0, x, 0, vNumero, &maior, &menor);
     free(vNumero);
     printf("%d %d", maior,menor);
    }
