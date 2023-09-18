#include <stdio.h>//Biblioteca de Entrada e Saida
#include <stdlib.h>//Biblioteca auxiliar
#include <locale.h>//biblioteca de idioma


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	char nomeEvento[10];	
	int opcaoEntrada, qtdInteira=0, qtdMedia=0, ingressosVendidos, limiteIng, opcao, contador=0;
	float pagamento, troco, meia, inteira;
	
	do{
		printf("\n");		
		printf("[1] Criar Evento\n");
		printf("[2] Comprar Ingressos\n");
		printf("[0] Sair\n");
		printf("\n");		
		
		printf("Escolha a uma das opções acima: ");
		scanf("%d", &opcao);
		printf("\n");
	
		switch (opcao){
			case 1:
				printf("Nome do Evento: ");
				scanf("%s", &nomeEvento);
				printf("Limite máximo de ingressos: ");
				scanf("%d", &limiteIng);
				printf("Valor da entrada inteira: ");
				scanf("%f", &inteira);
				contador=limiteIng;
			break;
			
			case 2:
				if(contador <= 0){
					printf("Não há mais ingressos disponíveis!\n");
					printf("Entradas inteiras vendidas %d\n", qtdInteira);
					printf("Meia-entradas vendidas: %d\n", qtdMedia);
					printf("Ingressos Disponíveis: %d \n", contador);
				  	printf("Total de ingressos vendidos: %d \n", limiteIng);
				  	printf("-------------------------------------\n");
				}
				else{				
					printf("Evento: %s\n", nomeEvento);
					printf("Valor Inteira: R$%.2f\n", inteira);
					meia = inteira * 0.5;	
					printf("Valor Meia: R$%.2f\n", meia);
					printf("\n");
					printf("[1] Inteira\n");
					printf("[2] Meia-Entrada\n");
					printf("Opção de Ingresso: ");	
					scanf("%d", &opcaoEntrada);		
					printf("Insira o dinheiro: ");
					scanf("%f", &pagamento);
					switch (opcaoEntrada)		
				{
					case 1: 	
						if (pagamento < inteira)
						{
							printf("Valor Insuficiente! Devolvendo dinheiro e retornando ao menu principal.\n");
							printf("-----------------------------------------------------------------------\n");					
						}
					    else{
							if (pagamento > inteira)	
								{
									printf("\n");
									troco = pagamento - inteira;								
									printf("Troco: R$%2.f\n", troco);							
								}
								printf("Compra efetuada com sucesso!\n");
								qtdInteira++;	
								contador--;
								printf("Ingressos restantes:  %d\n", contador);			
							}
					break;
					 
					case 2:		
						meia = inteira * 0.5;	
						if (pagamento < meia)
						{
							printf("Valor Insuficiente! Devolvendo dinheiro e retornando ao menu principal.\n");
							printf("-----------------------------------------------------------------------\n");					
						}
						else
							{
								if (pagamento > meia)
									{
										printf("\n");
										troco = pagamento - meia;									
										printf("Troco: R$%2.f\n", troco);							
									}
								printf("Compra efetuada com sucesso!\n");
								qtdMedia++;
								contador--;
								printf("Ingresos Restantes:  %d\n", contador);
							}											
						break;											
				}

				
				break;
				}
		} 
		}while(opcao!=0);		
		
		return 0;	
	} 
