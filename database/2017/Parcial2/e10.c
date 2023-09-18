#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct event
{
	char nameEvent[50];
	int nmbrTicks;
	int nmbrFull;
	int nmbrHalf;
	float priceFull;
	float priceHalf;
};
	
int main(int argc, char *argv[])
{	
	int option, nmbrEvents, totalEvents;
	int posiEvent, i, order, buyMenu;
	char enter;
	float money, price, priceDisc;
	struct event eventRegis[10];
	char soldAll[] = "(esgotado)";
	order = 0;
	nmbrEvents = 0;

	system("cls");
	printf("-------------------------------------------------------------\n");
	printf("----------------   Vendedor de Ingressos++   ----------------\n");
	printf("------------------   Cadastro do Evento    ------------------\n");
	printf("-------------------------------------------------------------\n\n\n");

	/* cadastro eventos */
	printf("Digite a quantidade de Eventos (max 10): ");
	do{
		scanf("%d", &totalEvents);
		printf("\n");
		if(totalEvents > 10 || totalEvents < 1)
		{
			printf("Valor nao disponivel! \nDigite uma opcao valida.\n");
		}
	}while(totalEvents > 10 || totalEvents < 1);
	
	for (nmbrEvents = 0; nmbrEvents < totalEvents; nmbrEvents++){
		setbuf(stdin, NULL);
		printf("Digite o nome do evento %d: ", (nmbrEvents+1));
		gets(eventRegis[nmbrEvents].nameEvent);
		setbuf(stdin, NULL);
	
		printf("Digite a quantidade total de ingressos: ");
		scanf("%d", &eventRegis[nmbrEvents].nmbrTicks);
	
		eventRegis[nmbrEvents].nmbrHalf = (eventRegis[nmbrEvents].nmbrTicks * 0.4);
		eventRegis[nmbrEvents].nmbrFull = (eventRegis[nmbrEvents].nmbrTicks - eventRegis[nmbrEvents].nmbrHalf);
	
		printf("Digite o valor da entrada inteira: R$");
		scanf("%g", &eventRegis[nmbrEvents].priceFull);
		printf("\n");
	
		eventRegis[nmbrEvents].priceHalf = (eventRegis[nmbrEvents].priceFull / 2);
		
		printf("	| Nome do evento: %s\n", eventRegis[nmbrEvents].nameEvent);
		printf("	| Quantidade total de ingressos: %d\n", eventRegis[nmbrEvents].nmbrTicks);
		printf("	| Inteiras: %d\n", eventRegis[nmbrEvents].nmbrFull);
		printf("	| Meias: %d\n", eventRegis[nmbrEvents].nmbrHalf);
		printf("	| Valor inteira: R$%g\n", eventRegis[nmbrEvents].priceFull);
		printf("	| Valor meia: R$%g\n", eventRegis[nmbrEvents].priceHalf);
		printf("\n");
	}
	printf("\n\nCadastros finalizados.\nPressione ENTRER para iniciar o auto-atendimento.\n");
	setbuf(stdin, NULL);
	scanf("%c", &enter);
	
//Inicio
	do{
		system("cls");
		printf("-------------------------------------------------------------\n");
		printf("----------------   Vendedor de Ingressos++   ----------------\n");
		printf("------------------          Venda          ------------------\n");
		printf("-------------------------------------------------------------\n");
		printf("\nTotal de eventos: %d\n\n", totalEvents);
		printf("\nEscolha um dos eventos disponiveis: \n");
		
		for(i = 0; i < totalEvents; i++){
			if(eventRegis[i].nmbrHalf == 0 && eventRegis[i].nmbrFull == 0){
				printf("	[%d] %s %s\n", (i+1), eventRegis[i].nameEvent, soldAll);
			}else{
				printf("	[%d] %s\n", (i+1), eventRegis[i].nameEvent);
			}	       
	    }
	    do{
	    	printf("\n	Digite a opcao desejada: ");
	    	scanf("%d", &option);
	    	if(option > totalEvents || option < 0){
		    	printf("Opcao nao disponivel!\nDigite uma opcao valida: ");
		    	scanf("%d", &option);
		    }
		    posiEvent = option-1;
		    if(eventRegis[posiEvent].nmbrHalf == 0 && eventRegis[posiEvent].nmbrFull == 0){
		    	printf("Evento esgotado, escolha outra opcao");
				option = 0;	    	
		    }
	    }while(option > totalEvents || option < 1);
	    
	
	    posiEvent = option-1;
	    printf("\n\n------------   Vendas  %s   ------------\n", eventRegis[posiEvent].nameEvent);
	    printf("\nDeseja comprar ingresso inteiro ou meio?");
	    printf("\n	[1] Inteiro\n	[2] Meio");
	    do{
	    	printf("\n	Digite a opcao desejada: ");
	    	scanf("%d", &option);
	    	if(option == 1 && (eventRegis[posiEvent].nmbrFull) == 0){
	    		printf("Ingresso nao disponivel!\nEscolha outra opcao.\n");
	    		option = 0;
	    	}else{
		    	if(option == 2 && (eventRegis[posiEvent].nmbrHalf) == 0){
		    		printf("Ingresso nao disponivel!\nEscolha outra opcao.\n");
		    		option = 0;
		    	}else{
	    			if(option != 2 && option != 1){
					printf("Valor nao disponivel!\n	Digite uma opcao valida.\n");
	    			}
	    		}
	    	}
	    }while(option != 2 && option != 1);
	    
	    switch(option){
	    	case 1: price = eventRegis[posiEvent].priceFull;
	    			eventRegis[posiEvent].nmbrFull--;	    	
					break;
			case 2: price = eventRegis[posiEvent].priceHalf;
	    			eventRegis[posiEvent].nmbrHalf--;	    
					break;
		}
		printf("\nModo de pagamento:\n	[1] Dinherio (10%% desc.)\n	[2] Cartao");
		printf("\n	Digite a opcao: ");
		scanf("%d", &option);
		do{
			switch(option){
				case 1: priceDisc = price*0.9;
						printf("\nO valor do ingresso eh: R$%.2f", priceDisc);
						printf("\nDigite o valor que sera pago: R$");
						scanf("%f", &money);
						if(money > priceDisc){
							printf("	Seu troco eh R$ %.2f", (money-priceDisc));
						}else{
							if(money < priceDisc){
								printf("\n	O valor nao paga o total do ingresso.\n	Falta R$%.2f\n", (price-priceDisc));
								money = 0;
							}else{
							printf("\nIngresso pago.");
							}
						}
						break;
				case 2: printf("\nO valor do ingresso eh: R$%.2f", price);
						printf("\n\n	Insira o cartao na maquininha, digite a senha e, \n	apos a confirmacao do pagamento, tecle ENTER.");
							setbuf(stdin, NULL);
							scanf("%c", &enter);
						printf("\nIngresso pago.");
						break;
				default: printf("Opcao invalida");
			}
		}while(money == 0);
		printf("\n\n	Obrigado pela compra!");
		printf("\n\n\n\n------------   MENU   ------------\n\n");
		printf("	[1] Realizar uma nova compra\n	[2] Visualizar relatorios de todos os eventos\n	[3] Sair");
		do{
			printf("\n\n		Digite a opcao desejada: ");
			scanf("%d", &buyMenu);
			if(buyMenu < 1 && buyMenu < 3){
				printf("Opcao nao disponivel!\nDigite uma opcao valida: ");
			}
		}while(buyMenu < 1 && buyMenu < 3);
		if(buyMenu == 2){
			do{
				
				system("cls");
				printf("-------------------------------------------------------------\n");
				printf("----------------   Vendedor de Ingressos++   ----------------\n");
				printf("------------------      Relatorio          ------------------\n");
				printf("-------------------------------------------------------------\n\n\n");
				
				printf("\nEscolha um dos eventos disponiveis: \n\n");		
				for(i = 0; i < totalEvents; i++){
			          printf("	[%d] %s\n", (i+1), eventRegis[i].nameEvent);
			    }
			    do{
			    	printf("\n	Digite a opcao desejada: ");
			    	scanf("%d", &option);
			    	if(option > totalEvents || option < 0){
				    	printf("Opcao nao disponivel!\nDigite uma opcao valida: ");
				    	scanf("%d", &option);
				    }
				posiEvent = option-1;
			    }while(option > totalEvents || option < 0);
			    printf("\n\n------------   Vendas  %s   ------------\n", eventRegis[posiEvent].nameEvent);
				printf("\n\n	Ingressos disponiveis (inicial): %d\n", eventRegis[posiEvent].nmbrTicks);
				printf("	Ingressos disponiveis (atual): %d\n", (eventRegis[posiEvent].nmbrFull+eventRegis[posiEvent].nmbrHalf));
				printf("		Inteiras disponiveis: %d\n", eventRegis[posiEvent].nmbrFull);
				printf("		Meias disponiveis: %d\n", eventRegis[posiEvent].nmbrHalf);
				printf("\n\n\n\n------------   MENU   ------------\n\n");
				printf("	[1] Realizar uma nova compra\n	[2] Visualizar relatorios de todos os eventos\n	[3] Sair");
				do{
					printf("\n\n		Digite a opcao desejada: ");
					scanf("%d", &buyMenu);
					if(buyMenu < 1 && buyMenu < 3){
					printf("Opcao nao disponivel!\n	Digite uma opcao valida: ");
					}
				}while(buyMenu < 1 && buyMenu < 3);
			}while(buyMenu == 2);
		}
	}while(buyMenu == 1);	
	

	
   return 0;
}

