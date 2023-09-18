#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nMaxEventos 3

// VARIAVEIS GLOBAIS

struct Eventos{
	char nomeEvento[50];
	int capacidadeMax;
	float valorEntradaInteira;
	float valorEntradaMeia;
	int ingressosInteiros;
	int ingressosMeios;
};

struct Eventos evento[nMaxEventos];
int contaEvento = 0;// conta a quantidade de eventos cadastrados;

//MODULOS

void cadastrarEvento(char nome[50],int capMax,float valorIngresso){
	strcpy(evento[contaEvento].nomeEvento, nome);
	evento[contaEvento].capacidadeMax = capMax;
	evento[contaEvento].valorEntradaInteira = valorIngresso;
	evento[contaEvento].valorEntradaMeia = evento[contaEvento].valorEntradaInteira / 2;
	evento[contaEvento].ingressosMeios = evento[contaEvento].capacidadeMax * 0.4;
	evento[contaEvento].ingressosInteiros = evento[contaEvento].capacidadeMax - evento[contaEvento].ingressosMeios;
	contaEvento++;
}

void calcularTroco(float valorIngresso){
	valorIngresso = valorIngresso * 0.9;
	float valorPagamento,valorPagamentoFaltante,valorPagamentoFaltPago,troco;
	printf("\nVoce optou pagar com dinheiro o preco ficou: %.2f\n", valorIngresso);
	printf("\nEntre com o valor pago\n");
	scanf("%f", &valorPagamento);
	while(valorPagamento < valorIngresso){
		valorPagamentoFaltante = valorIngresso - valorPagamento;
		printf("\nFavor pagar o total do ingresso, faltam R$%.2f\n", valorPagamentoFaltante);
		scanf("%f",&valorPagamentoFaltPago);
		valorPagamento = valorPagamentoFaltPago + valorPagamento;
		}
		if(valorPagamento > valorIngresso){
			troco = valorPagamento - valorIngresso;
			printf("\nO troco e de %.2f\n", troco);
		}
			
}

void venderIngresso(int idEvento){
	int opcao;
	int quantIngresso;
	char tipoIngresso[50];
	int formaPagamento;
	float valorIngresso;
	printf("\nDigite 1 para entrada interia e 2 para meia\n");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			quantIngresso = evento[idEvento].ingressosInteiros;
			strcpy(tipoIngresso,"inteiro");
			valorIngresso = evento[idEvento].valorEntradaInteira;
			break;
		
		case 2:
			quantIngresso = evento[idEvento].ingressosMeios;
			strcpy(tipoIngresso,"meio");
			valorIngresso = evento[idEvento].valorEntradaMeia;
			break;
	}
	if(quantIngresso == 0){
		printf("\nOs ingressos %s estao esgotados\n", tipoIngresso);
	}else{
		printf("\nVoce escolheu o ingresso %s que custa %.2f, favor indicar a forma de pagamento: \n",tipoIngresso, valorIngresso);
		printf("\nDigite 1 para cartao e 2 para dinheiro (com desconto de 10 porcento)\n");
		scanf("%d",&formaPagamento);
			
		switch(formaPagamento){
		
			case 1:
				printf("Pagamento efetuado com sucesso!\n");
				if(opcao == 1){
					evento[idEvento].ingressosInteiros --;
				}else{
					evento[idEvento].ingressosMeios --;
				}
			break;
			
			case 2:
				
				calcularTroco(valorIngresso);
				printf("Pagamento efetuado com sucesso!\n");
				if(opcao == 1){
					evento[idEvento].ingressosInteiros --;
				}else{
					evento[idEvento].ingressosMeios --;
				}
		}
	}
}

void relatorioFinal(){
	int cont = 0;
	int ingressosVendidos,totalArrecadado;
	int ingressoMeiosSobrantes;
	int ingressoInteirosSobrantes;
	while(cont < contaEvento){
		printf("O evento %s foi finalizado, dados:\n", evento[cont].nomeEvento);
		ingressosVendidos = evento[cont].capacidadeMax - (evento[cont].ingressosInteiros + evento[cont].ingressosMeios);
		ingressoMeiosSobrantes = (evento[cont].capacidadeMax * 0.4) - evento[cont].ingressosMeios;
		ingressoInteirosSobrantes = (evento[cont].capacidadeMax - (evento[cont].capacidadeMax * 0.4)) - evento[cont].ingressosInteiros;
		printf("Ingressos vendidos: %d\n", ingressosVendidos);
		printf("Ingressos meios vendidos: %d\n", ingressoMeiosSobrantes);
		printf("Ingressos meios sobrantes: %d\n", evento[cont].ingressosMeios);
		printf("Ingressos inteiros vendidos: %d\n", ingressoInteirosSobrantes);
		printf("Ingressos inteiros sobrantes: %d\n", evento[cont].ingressosInteiros);
		cont++;
	}
	
}

int main(int argc, char *argv[]){
	char nomeEvento[50];
	int capacidadeMax;
	float valorIngresso;
	int cont;
	int selectEvento,verificaEvento;
	
	int verificaCompra = 1;
	int selecionaEvento = 0;
	verificaEvento = 0;
	
	while(verificaCompra == 1){
		do{
			printf("\nBem vindo ao Ingresso++.\nPara cadastrar um evento digite 1. \nPara comprar ingressos de um evento digite 2. \nPara sair digite 3.\n");
			scanf("%d", &verificaCompra);
		}while((verificaCompra > 3) || (verificaCompra < 1));
		
		cont = 0; //verifica se os eventos estão esgotados
		while(cont < contaEvento){
			if((evento[cont].ingressosInteiros == 0) && (evento[cont].ingressosMeios == 0)){
				verificaEvento++;
			}
		cont++;
		}
		
		switch(verificaCompra){
			case 1:
				if(contaEvento == nMaxEventos){
					printf("\nNumero de Eventos ja esta no maximo.\n");
				}else{
					printf("\nInsira o nome do evento:\n");
					fflush(stdin);
					gets(nomeEvento);
					fflush(stdin);
					//scanf("%s", &nomeEvento);
					do{
						printf("\nInsira a capacidade do evento:\n");
						scanf("%d", &capacidadeMax);
					}while(capacidadeMax < 1);
					do{
						printf("\nInsira o valor do ingresso inteiro:\n");
						scanf("%f", &valorIngresso);
					}while(valorIngresso <= 0);
					cadastrarEvento(nomeEvento,capacidadeMax,valorIngresso);
				}
				break;
				
			case 2:
				if(contaEvento < 1){
					printf("\nNao ha eventos cadastrados \n");
					verificaCompra = 1;
					break;
				}else if(verificaEvento == contaEvento){
					printf("\nTodos os eventos estao esgotados\n");
					verificaCompra = 1;
					break;
				}else{
					cont = 0;
					while(cont < contaEvento){
						if((evento[cont].ingressosInteiros == 0) && (evento[cont].ingressosMeios == 0)){
							printf("\nEvento %s esgotado", evento[cont].nomeEvento);
						}else{
							printf("\nDigite %d para selecinar o evento %s, com %d ingressos inteiros e %d meios \n", cont, evento[cont].nomeEvento, evento[cont].ingressosInteiros, evento[cont].ingressosMeios);
						}
						cont++;
					}
						scanf("%d", &selectEvento);
						venderIngresso(selectEvento);
				}
				verificaCompra = 1;
				break;
			
			case 3:
				break;
		}
	}
	
	relatorioFinal();
	return 0;
}
