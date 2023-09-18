#include <stdio.h>
#include <stdlib.h>

struct cadastroEventos		// **VARIAVEL REGISTRO**
{
	char nomeEvento[50];
	int quantidadeIngressosEventos;
	float valorIngressosEventos;	
		
};

							//** VARIAVEIS GLOBAIS

struct cadastroEventos Eventos[100];	
int contEvento=1, contIngressosVendidosInteiros [50],contIngressosVendidosMeias[50],contLimiteMeia[50];




void cadastroEventos () 		// **FUNCAO PARA CADASTRO DE EVENTOS
{
	
printf("Qual sera o nome do evento:");
gets(Eventos[contEvento].nomeEvento);

printf("Qual sera a quantidade de ingressos para o %s:",Eventos[contEvento].nomeEvento);
scanf("%d",&Eventos[contEvento].quantidadeIngressosEventos);

	while (Eventos[contEvento].quantidadeIngressosEventos < 1.00)
	{
		printf("Valor invalido. Digite Novamente:");
		scanf("%d",&Eventos[contEvento].quantidadeIngressosEventos);
	}
fflush(stdin);
	
	printf("Qual sera o valor do ingresso do %s:",Eventos[contEvento].nomeEvento);	
	scanf("%f",&Eventos[contEvento].valorIngressosEventos);
	
	while (Eventos[contEvento].valorIngressosEventos < 0.01)
	{
		printf("Valor Invalido. Digite Novamente:");
		scanf("%f",&Eventos[contEvento].valorIngressosEventos);
	}
	
contEvento++;	
	
};


int mostrarEventosCadastrados() //                           **MOSTRAR E ESCOLOHE EVENTOS**
{
	int opcaoEventoEscolhido,contMostrarEventos=0;
	
	printf("EVENTOS DISPONIVEIS\n\n");
	
		for(contMostrarEventos=1;contMostrarEventos<contEvento;contMostrarEventos++)
		{
			printf("[%d] %s\n\n",contMostrarEventos,Eventos[contMostrarEventos].nomeEvento);
		}
	printf("Qual o evento gostaria de comprar ingressos:");
	scanf("%d",&opcaoEventoEscolhido);	
	

	return opcaoEventoEscolhido;

};

void mostrarEventos() //                                    **APENAS MOSTRA EVENTOS**
{
	int contMostrarEventos=0;
	
	printf("EVENTOS DISPONIVEIS\n\n");
	
		for(contMostrarEventos=1;contMostrarEventos<contEvento;contMostrarEventos++)
		{
			printf("[%d] %s\n\n",contMostrarEventos,Eventos[contMostrarEventos].nomeEvento);
		}
	
};

int menuEscolhaIngresso(int valor1) // 							**MENU COM OPCOES DE INGRESSO*
{
	int opcaoIngressoevento;
	
	printf("Bem vindo ao %s\n\n",Eventos[valor1].nomeEvento);
	printf("[1] Ingresso Inteiro \n");
	printf("[2] Meia Entrada \n");
	printf("Informe a opcao desejada: ");
	scanf("%d",&opcaoIngressoevento);
		while (opcaoIngressoevento!=1 && opcaoIngressoevento!=2  )
		{
			printf("Opcao Invalida. Digite Novamente:");
			scanf("%d",&opcaoIngressoevento);
		}
	
	return opcaoIngressoevento;
};

int comprarIngresso(int valor1)//                              ** OPCOES PARA ENTRADA INTEIRA **
{
	int opcaoPagamentoIngresso;
	system("cls");
	printf("Voce optou pelo Ingresso Inteiro\n");
	printf("O ingresso custa %.2f\n",Eventos[valor1].valorIngressosEventos);
	printf("[1] Dinheiro (10%% de Desconto)\n");
	printf("[2] Cartao de Debito\n");
	printf("[3] Credito Parcelado (5%% de juros por Parcela)\n");
	printf("Como deseja pagar:");
	scanf("%d",&opcaoPagamentoIngresso);
		while(opcaoPagamentoIngresso!=1 && opcaoPagamentoIngresso!=2&& opcaoPagamentoIngresso!=3)
		{
			printf("Opcao Invalida. Digite Novamente: ");
			scanf("%d",&opcaoPagamentoIngresso);
		}
		
	return opcaoPagamentoIngresso;
};

void comprarIngressoDinheiro (float valor1, int valor2) //                                       **OPCAO=INTEIRO** PAGAMENTO COM DINHEIRO 
{
	float pagamento,troco,valorComDesconto;
	
	valorComDesconto= valor1*0.90;
		
	system("cls");
	printf("PAGAMENTO EM DINHEIRO\n");
	printf("O valor com 10%% de desconto fica %.2f\n",valorComDesconto);
	printf("Informe o valor do pagamento:");
	scanf("%f",&pagamento);
	
		if(valorComDesconto>pagamento)
		{
		
			printf("O valor eh insuficiente. repita a compra\n");	
			system("pause");
		}	
		else
		{
			
			troco=pagamento-valorComDesconto;
			
			printf("Seu troco eh %.2f Reais\n",troco);
			printf("Obrigado por Comprar !!!\n\n");
			contIngressosVendidosInteiros[valor2]++;
			system("pause");
		}
};

void comprarIngressoCartaoDebito(float valor1, int valor2) //                            	**OPCAO=INTEIRO** PAGAMENTO COM O CARTAO DE DEBITO
{
	float saldo,troco;
	system("cls");
	printf("PAGAMENTO-CARTAO DE DEBITO\n");
	printf("O valor do ingresso eh:%.2f\n",valor1);
	printf("Informe o saldo do cartao:");
	scanf("%f",&saldo);
	
		system("cls");
		if (saldo<valor1)
		{
			
			printf("Saldo do Cartao insuficiente\n");
			printf("Repita a compra. Obrigado !\n\n");
			system("pause");;
		}
		else
		{
			
			printf("Obrigado pela compra!!!\n\n");
			contIngressosVendidosInteiros[valor2]++;			
			system("pause");
		}
};

void comprarIngressoCartaoCredito (int valor2)//                                             **OPCAO=INTEIRO**PAGAMENTO COM CARTAO DE CREDITO
{
	
	int opcaoPagamentoCredito;
	float valorParcelado,saldo;
	
system("cls");	
printf("PAGAMENTO-CARTAO DE CREDITO\n");
printf("Se optar por parcelar o pagamento, ira pagar 5%% de juros por parcela\n\n");
printf("[1] Pagamento em 1X %.2f\n",Eventos[valor2].valorIngressosEventos*1.05);
printf("[2] Pagamento em 2X %.2f Totalizando:%.2f\n",(Eventos[valor2].valorIngressosEventos*1.10)/2,Eventos[valor2].valorIngressosEventos*1.10);
printf("[3] Pagamento em 3X %.2f Totalizando:%.2f\n",(Eventos[valor2].valorIngressosEventos*1.15)/2,Eventos[valor2].valorIngressosEventos*1.15);
printf("[4] Pagamento em 4X %.2f Totalizando:%.2f \n\n",(Eventos[valor2].valorIngressosEventos*1.20)/2,Eventos[valor2].valorIngressosEventos*1.20);
printf("Informe a opcao desejada:");
scanf("%d",&opcaoPagamentoCredito);
contIngressosVendidosInteiros[valor2]++;
system("cls");
printf("Obrigado por comprar !!\n\n");
system("pause");
};

int opcaoCompraMeiaEntrada (int valor1) //                                                  **OPCOES PARA MEIA ENTRADA**
{
	
	int opcaoPagamentoIngresso;
	system("cls");
	printf("Voce optou pelo Ingresso Meia Entrada\n");
	printf("O ingresso custa %.2f\n",Eventos[valor1].valorIngressosEventos/2);
	printf("[1] Dinheiro (10%% de Desconto)\n");
	printf("[2] Cartao de Debito\n");
	printf("[3] Credito Parcelado (5%% de juros por Parcela)\n");
	printf("Como deseja pagar:");
	scanf("%d",&opcaoPagamentoIngresso);
		while(opcaoPagamentoIngresso!=1 && opcaoPagamentoIngresso!=2&& opcaoPagamentoIngresso!=3)
		{
			printf("Opcao Invalida. Digite Novamente: ");
			scanf("%d",&opcaoPagamentoIngresso);
		}
	return opcaoPagamentoIngresso;	
};

void comprarIngressoDinheiroMeia (float valor1, int valor2) //                             **OPCAO=MEIAENTRADA** PAGAMENTO COM DINHEIRO 
{
	float pagamento,troco,valorComDesconto;
	valorComDesconto= (valor1*0.90)/2;
	
	system("cls");
	printf("PAGAMENTO-DINHEIRO\n");
	printf("O valor com 10%% de desconto fica %.2f\n",valorComDesconto);
	printf("Informe o valor do pagamento:");
	scanf("%f",&pagamento);
	
		if(pagamento<valorComDesconto)
		{
		
			printf("O valor é insuficiente. repita a compra\n\n");	
			system("pause");			
		}	
		else
		{			
			troco=pagamento-valorComDesconto;
			
			printf("Seu troco eh %.2f Reais\n\n",troco);
			contIngressosVendidosMeias[valor2]++;
			printf("Obrigado por comprar !!!\n\n");
			system("pause");
		}
};

void comprarIngressoCartaoDebitoMeia(float valor1, int valor2) // 							**OPCAO=MEIAENTRADA**PAGAMENTO COM CARTAO DE DEBITO 
{
	float saldo,troco;
	system("cls");
	printf("PAGAMENTO-CARTAO DE DEBITO\n");
	printf("O valor do ingresso eh:%.2f\n",valor1/2);
	printf("Informe o saldo do cartao");
	scanf("%f",&saldo);
	
		if (saldo<valor1/2)
		{			
			printf("Saldo do Cartao insuficiente\n\n");
			system("pause");
		}
		else
		{			
			printf("Obrigado pela compra!!!\n\n");
			contIngressosVendidosMeias[valor2]++;	
			system("pause");		
		}
};

void comprarIngressoCartaoCreditoMeia (int valor2)//										**OPCAO=MEIAENTRADA**PAGAMENTO COM CARTAO DE CREDITO 
{
	
	int opcaoPagamentoCredito;
	float valorParcelado,saldo;
system("cls");	
printf("Voce optou por pagar com cartão de credito\n");
printf("Se optar por parcelar o pagamento, pagar 5%% de juros por parcela\n\n");
printf("[1] Pagamento em 1X valor:%.2f\n",(Eventos[valor2].valorIngressosEventos/2)*1.05);
printf("[2] Pagamento em 2X valor:%.2f Totalizando:%.2f\n",((Eventos[valor2].valorIngressosEventos/2)*1.10)/2,(Eventos[valor2].valorIngressosEventos/2)*1.10);
printf("[3] Pagamento em 3X valor:%.2f Totalizando:%.2f\n",((Eventos[valor2].valorIngressosEventos/2)*1.15)/2,(Eventos[valor2].valorIngressosEventos/2)*1.15);
printf("[4] Pagamento em 4X valor:%.2f Totalizando:%.2f \n\n",((Eventos[valor2].valorIngressosEventos/2)*1.20)/2,(Eventos[valor2].valorIngressosEventos/2)*1.20);
printf("Informe a opcao desejada:"); 
scanf("%d",&opcaoPagamentoCredito);
contIngressosVendidosMeias[valor2]++;
system("cls");

printf("Obrigado por comprar !!\n\n");
system("pause");	
};

int menuAcaoPosCadastro()  //													        	  **MENU PRINCIPAL**
{
	int opcaoMenuPrincipal;
	system("cls");
	printf("MENU PRINCIPAL\n\n");
	printf("[1] Comprar Ingressos\n");
	printf("[2] Eventos cadastrados\n");
	printf("[3] ingressos Vendidos\n");
	printf("[4] Sair\n");
	printf("o que deseja fazer:");
	scanf("%d",&opcaoMenuPrincipal);
		while (opcaoMenuPrincipal!=1 && opcaoMenuPrincipal!=2 && opcaoMenuPrincipal!=3 && opcaoMenuPrincipal!=4)
		{
			printf("Opcao Invalida. Digite Novamente:");
			scanf("%d",&opcaoMenuPrincipal);
		}
		 
	return opcaoMenuPrincipal;	
};

void mostrarIngressosVendidos()//                                     	                     **MOSTRAR INGRESSOS VENDIDOS POR EVENTO**
{
	int inteirasRestantes,meiasRestantes;
	int opcaoEventoEscolhido,contMostrarEventos=0;
	
	system ("cls");
	printf("EVENTOS DISPONIVEIS\n\n");
	
		for(contMostrarEventos=1;contMostrarEventos<contEvento;contMostrarEventos++)
		{
			printf("[%d] %s\n\n",contMostrarEventos,Eventos[contMostrarEventos].nomeEvento);
		}
	printf("Qual o evento gostaria de comprar ingressos:");
	scanf("%d",&opcaoEventoEscolhido);	
		
		system("cls");
		
		meiasRestantes=(Eventos[opcaoEventoEscolhido].quantidadeIngressosEventos*0.4)-contIngressosVendidosMeias[opcaoEventoEscolhido];
		inteirasRestantes=(Eventos[opcaoEventoEscolhido].quantidadeIngressosEventos-(contIngressosVendidosInteiros[opcaoEventoEscolhido]+contIngressosVendidosMeias[opcaoEventoEscolhido]));
		printf("INGRESSOS VENDIDOS\n\n");
		printf("INTEIRAS: %d\n",contIngressosVendidosInteiros[opcaoEventoEscolhido]);
		printf("MEIAS: %d\n",contIngressosVendidosMeias[opcaoEventoEscolhido]);
		printf("TOTAL VENDIDO: %d\n\n",contIngressosVendidosInteiros[opcaoEventoEscolhido]+contIngressosVendidosMeias[opcaoEventoEscolhido]);
		printf("INGRESSOS RESTANTES\n\n");
		printf("TOTAL RESTANTE: %d\n\n",inteirasRestantes);
		system("pause");
};

//																		*****INICIO MODULO MAIN*****

int main() {
	
int ingressosVendidos,limitadormeia,opcaoMenuPrincipal,motrarIngressosDisponives,contIngresosComprados=0,opcaoCadastroNovoEvento,opcaoIngressoevento,opcaoEventoEscolhido,opcaoPagamentoIngresso;
		
printf("+++++++Bem Vindo ao Ingressos +++++++\n\n"); 
printf("Vamos cadastrar o primeiro evento\n");
	while (opcaoCadastroNovoEvento!=2) //                   **REPETICAO PARA CADASTRO DE EVENTOS**
	{
	cadastroEventos(); // 									**CHAMADA PARA CADASTRO DOS EVENTOS**
	system("cls");	
	printf("Voce gostaria de cadastrar um novo evento ?\n");
	printf("[1] SIM\n");
	printf("[2] NAO\n");
	printf("O que deseja fazer:");
	scanf("%d",&opcaoCadastroNovoEvento);
		while (opcaoCadastroNovoEvento!=1 && opcaoCadastroNovoEvento!=2)  // **RESTRICAO PARA CADASTRO DE EVENTOS**
		{
			printf("Valor Invalido. Digite Novamente:");
			scanf("%d",&opcaoCadastroNovoEvento);
		}
	system("cls");
	fflush(stdin);
	}
		
opcaoMenuPrincipal=menuAcaoPosCadastro(); // 								  ** CHAMADA DE MENU PRINCIPAL**
		
while(opcaoMenuPrincipal !=4)//													** REPETICAO PARA SAIR DO PROGRAMA**
{
		
	if (opcaoMenuPrincipal==1 ) //                                              ** OPCAO 1 DO MENU PRINCIPAL**
	{
		system("cls");
		opcaoEventoEscolhido=mostrarEventosCadastrados(); // 					    												**MOTRAR EVENTOS E ESCOLHER UM**
		ingressosVendidos=contIngressosVendidosInteiros[opcaoEventoEscolhido]+contIngressosVendidosMeias[opcaoEventoEscolhido];//   **INICIALIZACAO DA VARIAVEL INGRESSOS VENDIDOS**
				
		if (ingressosVendidos < Eventos[opcaoEventoEscolhido].quantidadeIngressosEventos )// 										**CONDICIONAL PARA LIMITAR INGRESSOS VENDIDOS**
		{
			limitadormeia= Eventos[opcaoEventoEscolhido].quantidadeIngressosEventos*0.4;//											**INICIALIZACAO DA VARIAVEL LIMITADOR DE MEIA ENTRADA**						
			system("cls");	
			opcaoIngressoevento=menuEscolhaIngresso(opcaoEventoEscolhido); // 							  **CHAMADA DA FUNCAO TIPO INGRESSO**
			if(opcaoIngressoevento==1)// 						                                           **INGRESSO INTEIRO**
			{
				opcaoPagamentoIngresso=comprarIngresso(opcaoEventoEscolhido); // OPCOES DE PAGAMENTO         **OPCAO DE PAGAMENTO**
				if (opcaoPagamentoIngresso==1)//                                                             **PAGAMENTO DINHEIRO**		
				{
					comprarIngressoDinheiro (Eventos[opcaoEventoEscolhido].valorIngressosEventos,opcaoEventoEscolhido); // 		**CHAMADA DO MODULO PAGAMENTO EM DINHEIRO**
				}
				else if (opcaoPagamentoIngresso==2)	//                                                    **PAGAMENTO DEBITO**
				{
					comprarIngressoCartaoDebito(Eventos[opcaoEventoEscolhido].valorIngressosEventos,opcaoEventoEscolhido);// **CHAMADA DO MODULO PAGAMENTO DEBITO**
				}
				else if (opcaoPagamentoIngresso==3)//                                                     ** PAGAMENTO CREDITO** 
				{
					comprarIngressoCartaoCredito(opcaoEventoEscolhido);// 													**CHAMADA DO MODULO PAGAMENTO CREDITO**
				}
			}	// 																						**FIM DA OPCAO INGRESSO INTREIRO**			
				
			else if (opcaoIngressoevento==2 &&  limitadormeia > contIngressosVendidosMeias[opcaoEventoEscolhido] )//  			**OPCAO MEIA ENTRADA**
			{
				opcaoPagamentoIngresso=opcaoCompraMeiaEntrada (opcaoEventoEscolhido);//                                       **CHAMADA DA FUNCAO MEIA ENTRADA MENU**
					if (opcaoPagamentoIngresso==1)//																		  **PAGAMENTO EM DINHEIRO**	
					{
						comprarIngressoDinheiroMeia (Eventos[opcaoEventoEscolhido].valorIngressosEventos,opcaoEventoEscolhido);// **CHAMADA DA FUNCAO PAGAMENTO DINHEIRO**
					}
					else if (opcaoPagamentoIngresso==2)//																	**PAGAMENTO COM DEBITO**
					{
						comprarIngressoCartaoDebitoMeia(Eventos[opcaoEventoEscolhido].valorIngressosEventos,opcaoEventoEscolhido);// **CHAMADA DA FUNCAO PAGAMENTO COM DEBITO**
					}
					else if (opcaoPagamentoIngresso==3)//																	**PAGAMENTO COM CREDITO**
					{
						comprarIngressoCartaoCreditoMeia(opcaoEventoEscolhido);//											**CHAMADA DA FUNCAO PAGAMENTO COM CREDITO**
					}
									
			}
			else
			{
				system("cls");
				printf("Todas as Meias Entradas ja Foram Vendidas !\n\n");
				system("pause");
			}								
		}//																													**FIM DO CONDICIONAL PARA LIMITAR INGRESSOS VENDIDOS**
			
		else if(ingressosVendidos >= Eventos[opcaoEventoEscolhido].quantidadeIngressosEventos)//							**CONDICIONAL PARA INFORMAR QUE NAO HA MAIS INGRESSOS**
		{
			system("cls");
			printf("Todos os ingressos para esse eventos ja foram vendidos\n\n");
			system("pause");
		}
	}//																													**FIM DA OPCAO 1 COMPRA DE INGRESSOS**
	else if (opcaoMenuPrincipal==2) // 																					 **OPCAO PARA EVENTOS CADASTRADOS**
	{
		system("cls");
		mostrarEventos();//																								**CHAMADA DA FUNCAO EVENTOS CADASTRADOS**
		system("pause");
		system("cls");
	}
	else if (opcaoMenuPrincipal==3)// 																						**OPCAO PARA MOSTRAR INGRESSOS VENDIDOS**
	{
		mostrarIngressosVendidos();//																						**CHAMADA DA FUNCAO PARA MOSTRAR INGRESSOS VENDIDOS**
	}
	opcaoMenuPrincipal=menuAcaoPosCadastro();//  																			** APRESENTACAO DO MENU PRINCIPAL**
}//																							** FIM DA REPETICAO DO PROGRAMA**
	
	
	
	
	return 0;
}
