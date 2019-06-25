#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
	
	int nt, i, j;
	scanf("%d", &nt);
	
	float n[nt];
	
	for(i = 0; i < nt; i++) {
		scanf("%f", &n[i]);
	}
	
	int intervalos;
	scanf("%d", &intervalos);
	
	float maior = n[0];
	float menor = n[0];
	
	for(i = 0; i < nt; i++) {
		if(n[i] > maior) maior = n[i];
		else if(n[i] < menor) menor = n[i];
	}
	
	float cadaIntervalo = (ceil(maior-menor))/intervalos;
	
	for(i = 0; i < intervalos; i++) {
		
		float vi = menor+i*cadaIntervalo;
		float vf = menor+(i+1)*cadaIntervalo;
		
		int quantidade = 0;
		for(j = 0; j < nt; j++) if(n[j] >= vi && n[j] < vf) quantidade++;
		
		printf("%.2f |-- %.2f: %d\n", vi, vf, quantidade);
		
	}
	
	
	return 0;
}



