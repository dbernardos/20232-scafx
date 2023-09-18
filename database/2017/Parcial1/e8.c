#include<stdio.h>
#include<stdlib.h>



int main(void) {


	
char evento[100];
int  numeroIngressos=-1,ingresso,opcao=0,contadorInteiro=0,contadorMeia=0,contadorRestantes=0,restantes=0, limiteMeia=0,ingressosVendidos=0;
float valorIngresso=-1,pagamento,troco,meiaEntrada ;




printf("Ola, seja Bem Vindo ao Ingresso++ \n");
printf("Meu Sistema de gestao de Venda de Ingressos \n\n");
printf("Digite o nome do evento que deseja criar: ");
scanf("%[^\n]s",&evento); // Comando para ler uma string com duas palavras separadas por espaço.



/*FIM CADASTRO DO EVENTO,INGRESSOS E VALORES*/	


		
	printf("Qual o numero de ingressos que o %s ira ter: ",evento);
	scanf("%d",&numeroIngressos);

	while(numeroIngressos < 1  )
	{	
			if (numeroIngressos< 1){
				printf("Valor Invalido. Digite novamente: ");	
				scanf("%d",&numeroIngressos);
			}
	}


	printf("Digite o valor do ingresso: ");
	scanf("%f",&valorIngresso);

	while (valorIngresso < 0.01)
	{
				if (valorIngresso < 0.01)
				{
					printf("Valor Invalido. Digite Novamente: ");
					scanf("%f",&valorIngresso);
				}
			
		
	}
	
	
system("cls");

/*FIM CADASTRO DO EVENTO,INGRESSOS E VALORES*/	



// Declaração da meia entrada e do limente de meia entrada vendido 

meiaEntrada=valorIngresso/2; //Meia Entrada recebe seu valor
limiteMeia = numeroIngressos*0.4; // Variavel para delimitar a meia entrada.
	
// Fim da declaração


while(opcao !=4) // inicio do laço para repetir o meu enquanto o usaurio não opta por sair
{
		
	
	// MENU PARA A COMPRA DE INGRESSOS
	
		
		
		system("cls");	
		printf("Seja Bem Vindo ao %s \n\n",evento);
			printf("1-Ingresso Inteiro \n");
			printf("2-Meia Entrada \n");
			printf("3-Ingressos Ja Vendidos \n");	
			printf("4- Sair \n");
			printf("Informe a opcao desejada: ");
			scanf("%d",&opcao);
			
	
			
		// FIM DO MENU PARA A COMPRA DE INGRESSOS
	
	system("cls");
	
	
	// OPÇÃO SELECIONADA PELO USUARIO NA SELEÇÃO ACIMA
	
	
			
		if ( numeroIngressos > ingressosVendidos) // TESTE PARA DEFINIR SE AINDA HÁ INGRESSOS PARA VENDA
		{
			
	
			// INICIO OPÇÃO 1
			
				if(opcao==1)
				{				
					printf("Voce selecionou a opcao de ingressos Inteiro \n");
					printf("O valor do ingresso e %.2f \n",valorIngresso);
					printf("Informe o pagamento: ");
					scanf("%f",&pagamento);
					system("cls");
						if(pagamento > valorIngresso)
							{
							troco=pagamento-valorIngresso;
							
							printf("Seu troco e %.2f \n",troco);
							printf("Obrigado por sua compra !! \n");
									contadorInteiro++;
									contadorRestantes--;
									ingressosVendidos++;
							
							}
								else if(pagamento == valorIngresso)
									{
										printf("Obrigado por sua compra ! \n");
											contadorInteiro++;
											contadorRestantes--;
											ingressosVendidos++;
									}
									else
										{
											printf("Pagamento Insuficiente ! \n");
										}
										
				}  // FIM DA OPÇÃO 1
							
									
									
			// INICIO  OPÇÃO 2
					
			else if ( opcao==2 && contadorMeia <limiteMeia )  // MEIA ENTRADA AINA DISPONIVEL
			
			{	
					printf("Voce seleciouno a opcao  Meia Entrada \n");
					printf("O valor da Meia Entrada e: %.2f \n",meiaEntrada);
					printf("Informe o pagamento: ");
					scanf("%f",&pagamento);
					system("cls");
						if(pagamento > meiaEntrada)
						{
							troco=pagamento-meiaEntrada;
							
							printf("Seu troco e %.2f \n",troco);
							printf("Obrigado por sua compra !! \n");
									contadorMeia++;
									contadorRestantes--;
									ingressosVendidos++;
							
						}
							else if(pagamento == meiaEntrada)
							{
								printf("Obrigado por sua compra ! \n");
								contadorMeia++;
								contadorRestantes--;
								ingressosVendidos++;
									
							}
								else
								{
									printf("Pagamento Insuficiente ! \n");
								}
										
					
			} // FIM DA OPÇÃO 2 COM MEIA ENTRDA DISPONIVEL
			
				else if (opcao==2 && contadorMeia >= limiteMeia)  // MEIA ENTRADA INDISPONIVEL
			
				{
					printf("Todas as Meias Entradas ja foram vendidas \n\n");				
				} 
			// FIM DA OPÇÃO 2 PARA INGRESSOS INDISPONIVEIS
						                            
				
		} 	// FIM DA CONDIÇÃO DOS INGRESSOS 
		
			
			
		
		else 
		{
			printf("Todos os Ingressos ja foram vendidos \n");  // MENSAGEM EXIBIDA QUANDO TODOS OS INGRESSOS FORAM VENDIDOS			
	   	
		}	
					
			// INICIO OPÇÃO 3
					
				if (opcao==3)
				{									
					printf("Os Ingressos Vendidos Sao:\n\n");
					printf("Ingressos Inteiros: %d \n",contadorInteiro);
					printf("Meia Entrada: %d \n",contadorMeia);
					restantes=numeroIngressos+contadorRestantes;
					printf("Total de Ingressos Vendidos: %d \n",ingressosVendidos);
					printf("Ingressos Restantes: %d \n",restantes);					
				}
				
			// FIM DA OPÇÃO 3
			
			system("pause");
			system("cls");
		
			// INICIO OPÇÃO 4
			
				if(opcao==4)		
				{
					printf("Obrigado por utilizar o Ingresso ++");
				}
		
			// FIM OPÇÃO 4
		
	}	// FIM DO LAÇO DE REPETIÇÃO




return 0;	
}
