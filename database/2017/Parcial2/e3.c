#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Evento{
	char nomeEvento[50];
	int qtdIngresso;
	int vlrIngresso;
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float comprarIngresso(float vlorIngresso, int qtdIngresso){
		int tipoCompra;
		float vlrPago, troco, vlrFalta;
		
		printf("Como deseja relizar o pagamento?\n");
		printf("	|| 1 - Dinheiro (10 por cento de desconto)\n");
		printf("	|| 2 - Cartao\n");
		printf("	|| Digite a opcao desejada: ");
		scanf("%d", &tipoCompra);
		
		
		switch(tipoCompra){
			case 1:
					vlorIngresso = vlorIngresso*0.90;
					do{
						printf("\nValor a ser pago: R$%.2f", vlorIngresso);
						printf("\nDigite o valor que voce esta pagando a maquina: R$");
						scanf("%g", &vlrPago);
						if(vlrPago == vlorIngresso){
							return 1;
						}else if(vlrPago > vlorIngresso){
							troco = vlrPago - vlorIngresso;
							return troco;
						}else if(vlrPago < vlorIngresso){
							vlrFalta = vlorIngresso - vlrPago;
							printf("Falta R$%.2f para finalizar a compra", vlrFalta);
						}						
					}while(vlrPago < vlorIngresso);
					break;
				case 2:
					do{
						printf("\nValor a ser pago: R$%.2f", vlorIngresso);
						printf("\nDigite o valor que voce esta pagando a maquina: R$");
						scanf("%g", &vlrPago);
						if(vlrPago == vlorIngresso){
							return 1;
						}else if(vlrPago > vlorIngresso){
							troco = vlrPago - vlorIngresso;
							return troco;
						}else if(vlrPago < vlorIngresso){
							vlrFalta = vlorIngresso - vlrPago;
							printf("Falta R$%.2f para finalizar a compra", vlrFalta);
						}						
					}while(vlrPago < vlorIngresso);
					break;
				}
		}

int main(int argc, char *argv[]) {
	struct Evento descricao[20];
	char nomeEventoAtual[50];
	int informacao, i, j, contInformacao, contEvento, contCompra, escolha, tipoCompra;
	int qtdMeio, qtdInteiro, qtdTotal;
	float vlrMeio, vlrInteiro, resultadoCompra, troco;
	
	for(j = 0; j < 20; j++){
		for(i = 0; i < 50; i++){
			descricao[j].nomeEvento[i] = -1;
		}
	}
	
	i = 0;
	
	printf("Seja bem-vindo ao Autoatendimento de Compra de Ingressos!\n");
	printf(" ------------------------------------------------------- \n");
	
	do{
		printf("Voce deseja registrar o evento?");
		printf("\n	|| 1 - Sim");
		printf("\n	|| 2 - Nao");
		printf("\n	|| Digite a sua opcao: ");
		scanf("%d", &informacao);
		
		system("cls");
		switch(informacao){
			case 1:
				do{
					//Registro dos eventos - quantos o usuário quiser, até 20 eventos
					printf("Seja bem-vindo ao Autoatendimento de Compra de Ingressos!\n");
					printf(" ------------------------------------------------------- \n");
					printf("Descricao do evento\n");
					printf(" ----------------- ");
					printf("\nO nome do evento: ");
					setbuf(stdin, NULL);
					gets(descricao[i].nomeEvento);
					printf("Quantidade de ingressos: ");
					scanf("%d", &descricao[i].qtdIngresso);
					printf("Valor dos ingressos: R$");
					scanf("%d", &descricao[i].vlrIngresso);
					printf("\nDeseja cadastrar mais um evento?");
					printf("\n	|| 1 - Sim");
					printf("\n	|| 2 - Nao");
					printf("\n	|| Digite a sua opcao: ");
					scanf("%d", &contInformacao);
					switch(contInformacao){
						case 1:
							i=i+1;
							break;
						case 2:
							break;
						default:
							printf("Opcao invalida! Por favor escolha novamente.");
					}
					system("cls");
				}while(contInformacao == 1);	
				break;
			case 2:
				printf("Desculpe mas ainda nao tem nenhum evento registrado.\n");
				break;
			default:
				printf("Opcao inexistente, repita o processo!\n");				
		}
	}while(informacao < 1 || informacao > 2 || informacao == 2);
	
	//loop da escolha do evento que se deseja realizar a compra
	system("cls");
	printf("Bem-vindo ao autoatendimento!!!\n");
	printf(" ----------------------------- \n");
	do{
		printf("Qual evento deseja comprar um ingresso?");
		i=1;
		//listar os eventos
		for(contEvento = 0; contEvento < 10; contEvento++){
			if(descricao[contEvento].nomeEvento[contEvento] == -1){
				break;
			}
			printf("\n	|| %d - %s", i, descricao[contEvento].nomeEvento);
			i++;
		}
		printf("\nQual opcao deseja? ");
		scanf("%d", &escolha);
		escolha = escolha - 1;
		
		//definição dos valores do evento escolhido
		strcpy(nomeEventoAtual,descricao[escolha].nomeEvento);
		qtdTotal = descricao[escolha].qtdIngresso;
		qtdMeio = descricao[escolha].qtdIngresso * 0.40;
		qtdInteiro = descricao[escolha].qtdIngresso - qtdMeio;
		vlrMeio = descricao[escolha].vlrIngresso * 0.50;
		vlrInteiro = descricao[escolha].vlrIngresso;
		
		//loop de autoatendimento da compra de ingressos
		system("cls");
		printf("Bem-vindo ao autoatendimento!!!\n");
		printf(" ----------------------------- \n");
		do{
			//loop da compra de inteiro ou meio
			do{
				printf("Deseja comprar um ingresso inteiro ou um meio ingresso?\n");
				printf("	|| 1 - Inteiro\n");
				printf("	|| 2 - Meio\n");
				printf("	|| 3 - Informacoes\n");
				printf("	|| Digite sua opcao desejada: ");
				scanf("%d", &tipoCompra);
				
				//SwitchCase da escolha do tipo da compra, inteiro ou meio
				switch(tipoCompra){
					case 1:
						resultadoCompra = comprarIngresso(vlrInteiro, qtdInteiro);
						if(resultadoCompra == 1){
							printf("Nao tem troco, muito obrigado pela sua compra!");
						}else{
							system("cls");
							printf("TROCO!!!\n");
							printf(" ------ \n");
							printf("Seu troco eh: R$%.2f\n", resultadoCompra);
							printf(" ------ \n");
						}
						qtdInteiro--;
						qtdTotal--;
						break;
					case 2:
						resultadoCompra = comprarIngresso(vlrMeio, qtdMeio);
						if(resultadoCompra == 1){
							printf("Nao tem troco, muito obrigado pela sua compra!");
						}else{
							system("cls");
							printf("Seu troco eh: R$%.2f", resultadoCompra);
						}
						qtdMeio--;
						qtdTotal--;
						break;
					case 3:
						system("cls");
						printf("informacoes:\n");
						printf(" ---------- \n");
						printf("Nome do evento: %s\n", nomeEventoAtual);
						printf("Quantidade total de ingressos: %d\n", qtdTotal);
						printf("Quantidade de ingressos inteiros: %d\n", qtdInteiro);
						printf("Quantidade de ingressos meios: %d\n", qtdMeio);
						printf("Preco do inteiro: R$%.2f\n", vlrInteiro);
						printf("Preco da meia: R$%.2f\n", vlrMeio);
						printf(" ------------------ \n");
						break;
					default:
						printf("Opcao inexistente");
				}
			}while(tipoCompra < 1 || tipoCompra > 2 || tipoCompra == 3);
			
			//Relatório, feito a cada passada do loop(for) atualizando a informação
			printf("\nRelatorio:\n");
			printf(" ---------- \n");
			printf("Total de Ingressos: %d\n", qtdTotal);
			printf("Ingressos Inteiros: %d\n", qtdInteiro);
			printf("Ingressos Meios: %d", qtdMeio);
			
			printf("\n\nDeseja realizar uma nova compra?");
			printf("\n	|| 1 - Sim");
			printf("\n	|| 2 - Nao");
			printf("\n	|| Digite a sua opcao: ");
			scanf("%d", &contCompra);
			
		}while(contCompra == 1);
	
		printf("\n\nDeseja comprar ingressos de outro evento?");
		printf("\n	|| 1 - Sim");
		printf("\n	|| 2 - Nao");
		printf("\n	|| Digite a sua opcao: ");
		scanf("%d", &contCompra);
	
	}while(contCompra == 1);
	
	
	
	return 0;
}
