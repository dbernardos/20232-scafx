#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QNT_EVT 3 // Quantidade permitida de eventos a serem criados

struct Evento
{
	char nomeEvento[50];
	int quantidadeIngressos;
	int quantidadeIngressosVendidos;
	int quantidadeMeiaEntradaVendidos;
	float quantidadeMeia;
	float valorIngresso;
};

struct Evento eventos[QNT_EVT];

int cont, continua, totalEventos;

float calculaPorcentagem(float valor,float porcentagem){
	return  valor * porcentagem;
}

void cadastraEventos() {

	do// Cadastra evento
	{
		system("cls");
		// Cadastro nome do evento
		printf("Você está cadastrando o seu evento. \n \nNome do evento: ");
		scanf("%s", eventos[cont].nomeEvento);
		
		// Cadastro de ingressos disponiveis
		printf("Número de ingressos disponíveis para o Evento '%s': ", eventos[cont].nomeEvento);
		scanf("%d", &eventos[cont].quantidadeIngressos);

		// Define a quantiadade de ingressos do tipo Meia Entrada estarao a venda
		eventos[cont].quantidadeMeia = calculaPorcentagem(eventos[cont].quantidadeIngressos, 0.40); 
		
		// Cadastro valor do ingresso
		printf("Valor da Entrada Inteira: ");
		scanf("%f", &eventos[cont].valorIngresso);
		
		system("cls");
		cont++;
		totalEventos++;
		if(cont < QNT_EVT){
			printf("Evento cadastrado com sucesso! \n \n");
			printf("Deseja cadastrar um novo evento?\n");
			printf("1 - SIM \n");
			printf("2 - NÃO \n");
			printf("\n");
			printf("Opção Escolhida: ");
			scanf("%d", &continua);
			system("cls");
		}
	
	}while(continua == 1 && cont < QNT_EVT);

}

void compraIngressos(){

	float valorPagar, valorDado, troco;
	int meiaEntrada, tipoIngresso, escolhaEvento, tipoPagamento;

	if(totalEventos == 0){
		printf("Não há eventos cadastrados. Pressione qualquer tecla para retornar ao menu principal.\n");
		getch();
		system("cls");
		return;
	}

	do{
		printf("Escolha o evento que deseja comprar o ingresso:\n");
		for(cont = 0; cont < totalEventos; cont++){
			printf("%d - %s \n", cont + 1, eventos[cont].nomeEvento);
		}
		printf("\nOpção escolhida: ");
		scanf("%d", &escolhaEvento);
		system("cls");
		// Verifica se ele selecionou um evento valido
		if(escolhaEvento > 0 && escolhaEvento <= totalEventos){
			escolhaEvento = escolhaEvento  - 1;
			printf("Você escolheu o evento: %s \n", eventos[escolhaEvento].nomeEvento);
			printf("Você gostaria de comprar um ingresso do tipo Inteira, ou do tipo Meia Entrada?\n");
			printf("1 - Inteira \n");
			printf("2 - Meia Entrada \n");
			printf("\nOpção escolhida: ");
			scanf("%d", &tipoIngresso);
			system("cls");
			switch(tipoIngresso){ // Switch Case do tipo de ingresso
				case 1: // Funcoes caso o ingresso for do tipo meia
					meiaEntrada = 0;
				    valorPagar = eventos[escolhaEvento].valorIngresso;
					break;
				case 2: // Funcoes caso o ingresso seja do tipo inteira
					valorPagar = calculaPorcentagem(eventos[escolhaEvento].valorIngresso, 0.50);
			        meiaEntrada = 1;
					break;
				default:
					printf("Opção Inválida. \n");
					break;
			}
			if(tipoIngresso == 1 || tipoIngresso == 2){
				if((meiaEntrada == 1 && eventos[escolhaEvento].quantidadeMeia >= 1) || meiaEntrada == 0) { // Verifica se existe meia entrada restante
					printf("Escolha a forma de pagamento: \n");
					printf("1 - Dinheiro \n");
					printf("2 - Cartão \n");
					printf("\nOpção escolhida: ");
					scanf("%d", &tipoPagamento);
					system("cls");
					
					if(tipoPagamento == 1){
						valorPagar = calculaPorcentagem(valorPagar, 0.90); 
						printf("Valor a pagar: R$% 2.f \n", valorPagar);
						printf("Insira o pagamento: R$ ");
						scanf(" %g", &valorDado); // Verificacao do valor inputado pelo usuario
						if(valorDado >= valorPagar){ // Verifica se o valor Â¬Âª suficiente para realizar a compra
							troco = valorDado - valorPagar;	
							if(troco > 0){ // Verifica se tem troco
								printf("Seu troco é de: R$% 2.f \n", troco);	
							}
							if(meiaEntrada == 1){ // Verifica se Â¬Âª meia entrada
								eventos[escolhaEvento].quantidadeMeia--;
								eventos[escolhaEvento].quantidadeMeiaEntradaVendidos++;
							}
							eventos[escolhaEvento].quantidadeIngressosVendidos++;
							printf("Muito obrigado pela compra! \n \n");						
						}else{
							printf("Infelizmente a quantia informada é insuficiente, devolvendo dinheiro... \n \n");
						}
					}else if(tipoPagamento == 2){
						printf("O valor de R$% 2.f foi debitado do seu cartão. \n", valorPagar);
						printf("Muito obrigado pela compra! \n \n");						
					}else{
						printf("Opção de pagamento inválida. \n");
					}
					printf("Deseja continuar comprando ingressos? \n");
					printf("1 - SIM \n");
					printf("2 - NÃO \n");
					printf("\nOpção escolhida: ");
					scanf("%d", &continua);
					system("cls");	
			
				}else{
					printf("Infelizmente os ingressos do tipo Meia entrada entrada acabaram, tente comprar novamente. \n");
				}
			}
		}else{
			printf("Esse evento não existe, tente novamente.\n");
		}
	}while(continua == 1);
}

void pucIngresso()
{
		printf(" ***************************************************************************************************************** \n");
		printf(" *    _____    _     _    ______      _   ___     _    ______    _____    ______    ______   ______   ______     * \n");
		printf(" *   |  __ \\  | |   | |  / _____|    | | |   \\   | |  / _____|  |  __ \\  |  ____|  / ____/  / ____/  /  __  \\    * \n");
		printf(" *   | |__| | | |   | | | |          | | | |\\ \\  | | | |   ___  | |__| | | |__     \\ \\___   \\ \\___  |  /  \\  |   *\n");
		printf(" *   |  ___/  | |   | | | |          | | | | \\ \\ | | | |  |   | |    _/  |  __|     \\__  \\   \\__  \\ |  |  |  |   *\n");
		printf(" *   | |      | \\___/ | | |_____     | | | |  \\ \\| | | |___| |  | |\\ \\   | |____   ____/ /  ____/ / |  \\__/  |   *\n");
		printf(" *   |_|       \\_____/   \\______|    |_| |_|   \\___|  \\______|  |_| \\_\\  |______| /_____/  /_____/   \\______/    *\n");
		printf(" *                                                                                                               *\n");
		printf(" *****************************************************************************************************************\n");
		
		printf("\n");
}

int main(void) {

	setlocale(LC_ALL, "Portuguese");
	
	int escolha;

	do{
		pucIngresso();
		printf("                           |   Seja bem vindo ao Sistema de Gerenciamento de Eventos PUCPR!   |\n");
		printf("                           |          Por favor, escolha uma das opções abaixo.               |\n");
		printf("\n");
		printf("1) Cadastrar Eventos \n");
		printf("2) Escolher Evento \n");
		printf("3) Sair \n");
		printf("\n");
		printf("Opção Escolhida: ");
		scanf("%d", &escolha);
		system("cls");

		switch(escolha){
			case 1:
				// Chama o modulo de cadastrar evento
				cadastraEventos();
				break;
			case 2:
				// Chama o modulo de comprar ingresso
				compraIngressos();
				break;
			case 3:
				// Encerra o sistema.
				printf("Voce saiu do sistema, Obrigado e volte sempre \n");
				break;
			default: 
				system("cls");
				printf("Opção inválida. Tente novamente.");
				getch();
				system("cls");
				break;
		}
	}while(escolha != 3);

	for(cont = 0; cont < totalEventos; cont++){
		printf("Confira como ficaram os resultados das vendas de ingressos. \n \n");
		printf("Evento: %s \n", eventos[cont].nomeEvento);
		printf("Total de ingressos vendidos: %d \n", eventos[cont].quantidadeIngressosVendidos);
		printf("Total de ingressos restantes: %d \n", eventos[cont].quantidadeIngressos - eventos[cont].quantidadeIngressosVendidos);
		printf("Ingressos Inteira vendidos: %d \n", eventos[cont].quantidadeIngressosVendidos - eventos[cont].quantidadeMeiaEntradaVendidos);
		printf("Ingressos Meia Entrada vendidos: %d \n", eventos[cont].quantidadeMeiaEntradaVendidos);
		printf("-----------------------------------\n");
	}
	return 0;
	
}
