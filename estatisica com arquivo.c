#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct registro{
	char  nome[100];
	char  sexo;
	int idade;
};



int main (void) {
	
		struct registro *registros;
	 registros = (struct registro *) malloc(100*sizeof(struct registro));
	 
	 char url[]="dados.txt";
	  
      float totalPessoas = 0.0;
	  int totalHomens = 0.0;
	  int totalMulheres = 0.0;
	  float totalIdade = 0.0;
	  float totalIdadeHomens = 0.0;
	  float totalIdadeMulheres = 0.0;

      
	  
	  FILE *arq = fopen(url, "r");
	  
//	  arq = fopen(url, "r");
  
     int total =0;
	 if(arq == NULL)
       printf("Erro, nao foi possivel abrir o arquivo\n");
     else
      while( (fscanf(arq,"%s %c %d\n",registros[total].nome, &registros[total].sexo, &registros[total].idade))!=EOF ){
      //  printf("Dentro  -- %s %c %d\n", registros[total].nome, registros[total].sexo, registros[total].idade);
      	total++;
	  }
	  
	  fclose(arq);
	  
    
	  int i=0;
	  for(i=0; i<total; i++){
	  	  	if(registros[i].sexo == 'm'){
      	totalHomens++;
      	totalIdadeHomens = 	totalIdadeHomens +registros[i].idade;
      }else if(registros[i].sexo == 'f'){
      	totalMulheres++;
      	totalIdadeMulheres = 	totalIdadeMulheres +registros[i].idade;
      }
      	
		totalPessoas++;
      	totalIdade = 	totalIdade +registros[i].idade;
     
	      	//     printf("Fora  -- %s %c %d\n", registros[i].nome, registros[i].sexo, registros[i].idade);
	  }
	  
  
     float mediaTotal = totalIdade/total;
     float mediaIdadeHomens = totalIdadeHomens/totalHomens;
     float mediaIdadeMulheres = totalIdadeMulheres/totalMulheres;

     printf("%d %d %d %.2f %.2f %.2f", total, totalHomens,totalMulheres,mediaTotal, mediaIdadeHomens,mediaIdadeMulheres);


	free(registros);
	return 0;
}

/*float media(struct registro *n, int tamanho) {
	float total = 0.00;
	int i;
	for(i = 0; i < tamanho; i++) total = total+n[i].total;
	
	float m = total/tamanho;
	
	return m;
}
*/


