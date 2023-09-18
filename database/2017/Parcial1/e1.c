#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	float pagamento, troco, valorIngresso, valorMeia;
	int ingressos, menu, quantiaInt, quantiaMeia;
	char nomeEvento[50];
	
	printf("Cadastre o Evento\n");
	printf("Informe o nome de seu evento:");
	scanf("%s", &nomeEvento);
	printf("Informe a capacidade maxima de ingressos:");
	scanf("%d", &ingressos);
	printf("Informe o valor dos ingressos:");
	scanf("%g", &valorIngresso);
	
	valorMeia = valorIngresso / 2;
	quantiaMeia = 0;
	quantiaInt = 0;

	
	while(ingressos > 0){
		printf("Escolha o tipo de ingresso que deseja comprar para %s:\n", nomeEvento);
		printf("Pressione 1 para ingresso comum\n");
		printf("Pressione 2 para meia entrada\n");
		scanf("%d", &menu);
		switch(menu){
			case 1:{
				printf("Informe o valor do pagamento:");
				scanf("%g", &pagamento);
				while(pagamento < valorIngresso){
					printf("Informe um valor adequado.");
					scanf("%g", &pagamento);								
				}
				troco = pagamento - valorIngresso;
				printf("Seu troco:%g\n", troco);
				ingressos--;
				quantiaInt++;
				break;
			}
			case 2:{
				if(quantiaMeia < ((40 * ingressos)/100)){
					printf("Informe o valor do pagamento:");
					scanf("%g", &pagamento);
					while(pagamento < valorMeia){
						printf("Informe um valor adequado.");
						scanf("%g", &pagamento);
					}
					troco = pagamento - valorMeia;
					printf("Seu troco:%g\n", troco);
				}else{
					printf("Meia entrada esgotada");
				}
				quantiaMeia++;
				ingressos--;
				break;
			}
		}
	}
	printf("Ingressos esgotados.");	
	printf("A quantidade de entradas inteiras foi de %d\n", quantiaInt);
	printf("A quantia de meia-entradas foi de %d\n", quantiaMeia);
	
	return 0;
}
