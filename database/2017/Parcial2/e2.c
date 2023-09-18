#include <stdio.h>
#include <stdlib.h>



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float pagamentoMeia(float preco){
	
	preco=preco/2;
	return preco;
	
}
int limitacaoMeia(int lotacao){
	
	int retorno;
	
	retorno=lotacao*0.4;
	
	return retorno;
	
}
int limitacaoInteira(int lotacao){
	
	int retorno;
	
	retorno=lotacao*0.6;
	
	return retorno;
	
}
float valorPagamentoCartaoInteiro(float valorPago, float precoTotal){
	
	float troco;
	int trocoInvalido;
	
	do{
		
		if(valorPago<precoTotal){
			
			printf("Voce pagou insuficientemente, pague novamente:\n\n");
			scanf("%f", &valorPago);
			
			trocoInvalido=1;
			
		}else{
			
			troco=valorPago-precoTotal;
			
			trocoInvalido=0;
		}
		
	}while(trocoInvalido==1);
	
	return troco;
	
}

float valorPagamentoCartaoMeia(float valorPago, float precoTotal){
	
	float troco;
	int trocoInvalido;
	
	do{
		
		if(valorPago<precoTotal){
			
			printf("Voce pagou insuficientemente, pague novamente:\n\n");
			scanf("%f", &valorPago);
			
			trocoInvalido=1;
			
		}else{
			
			troco=valorPago-precoTotal;
			
			trocoInvalido=0;
		}
		
	}while(trocoInvalido==1);
	
	return troco;
	
}
float valorPagamentoDinheiroInteiro(float valorPago, float precoTotal){
	
	float troco;
	int trocoInvalido;
	
	precoTotal=precoTotal*0.9;
	
	do{
		
		if(valorPago<precoTotal){
			
			printf("Voce pagou insuficientemente, pague novamente:\n\n");
			scanf("%f", &valorPago);
			
			trocoInvalido=1;
			
		}else{
			
			troco=valorPago-precoTotal;
			
			trocoInvalido=0;
		}
		
	}while(trocoInvalido==1);
	
	return troco;
	
}
float valorPagamentoDinheiroMeia(float valorPago, float precoTotal){
	
	float troco;
	int trocoInvalido;
	
	precoTotal=precoTotal*0.9;
	
	do{
		
		if(valorPago<precoTotal){
			
			printf("Voce pagou insuficientemente, pague novamente:\n\n");
			scanf("%f", &valorPago);
			
			trocoInvalido=1;
			
		}else{
			
			troco=valorPago-precoTotal;
			
			trocoInvalido=0;
		}
		
	}while(trocoInvalido==1);
	
	return troco;
	
}


int main(int argc, char *argv[]) {
	
	
	char nomeEvento[50][50];
	float precoVetor[50];
	float preco;
	float precoTotal;
	float valorPago;
	float trocoRecebido;
	float valorArrecadado[50];
	int ingressosVendidos[50];
	int lotacaoMeia[50];
	int lotacaoInteira[50];
	int escolhaErrado;
	int continuar;
	int escolhaContinuar;
	int escolhaPagamentoErrado;
	int escolhaPagamento;
	int meiaOuInteiraErrado;
	int eventoEscolhidoErrado;
	int meiaOuInteira;
	int eventoEscolhido;
	int refazerEscolha;
	int quantidadeEvento;
	int lotacao[50];
	int escolhaPrincipal;
	int evento;
	int cont;
	
	
	quantidadeEvento=-1;
	evento=0;
	
	do{		
		do{	
			printf("Digite 1 para criar um evento, 2 para comprar um ingresso e 3 para sair do programa\n");
			scanf("%i", &escolhaPrincipal);
				
			switch(escolhaPrincipal){
				
				case 1: 
				
					printf("Digite o nome do seu evento:\n");
					gets(nomeEvento[evento]);
					gets(nomeEvento[evento]);
					
					printf("\nDigite a quantidade de pessoas para o evento:\n");
					scanf("%i", &lotacao[evento]);
					
					lotacaoMeia[evento]=limitacaoMeia(lotacao[evento]);
					lotacaoInteira[evento]=limitacaoInteira(lotacao[evento]);
					
					printf("\nDigite o preço do evento:\n");
					scanf("%f", &precoVetor[evento]);
					
					ingressosVendidos[evento]=0;
					evento++;
					quantidadeEvento++;
					refazerEscolha=1;
				
					break;
				
				case 2:
				
				do{	
					if(quantidadeEvento==-1){
						
						printf("\nAinda nao foi criado um evento.\n\n");
						refazerEscolha=1;
					}
					else{
						
						for(cont=0 ; cont<=quantidadeEvento ; cont++){
						
						printf("\n\n %i- %s \n\n", cont, nomeEvento[cont]);
						
						}
						
							
							printf("Digite o evento desejado:\n");
							scanf("%i", &eventoEscolhido);
							
							switch(eventoEscolhido){
								
								default: 
									if(eventoEscolhido<0 || eventoEscolhido>quantidadeEvento){
										
										printf("\nEvento inexistente.\n\n");
										eventoEscolhidoErrado=1;
										
									}else{
										do{
											if(lotacao[eventoEscolhido]>0){
												
												printf("\nDigite 1 para pagar meia e 2 para pagar inteira.\n");
												scanf("%i", &meiaOuInteira);
												
												eventoEscolhidoErrado=0;
												
												switch(meiaOuInteira){
													
													case 1:
														if(lotacaoMeia[eventoEscolhido]>0){
															
															preco=precoVetor[eventoEscolhido];
															precoTotal=pagamentoMeia(preco);
															
															do{	
																printf("\nVoce deve pagar %f reais, Digite 1 para pagar com cartao e 2 para pagar com dinheiro.\n", precoTotal);
																scanf("%i", &escolhaPagamento);
																
																switch(escolhaPagamento){
																	
																	case 1:
																		
																		printf("\nDigite o valor pago:\n");
																		scanf("%f", &valorPago);
																		
																		trocoRecebido=valorPagamentoCartaoMeia(valorPago, precoTotal);
																		
																		printf("\nVoce recebe de troco %f reais.\n", trocoRecebido);
																		
																		lotacao[eventoEscolhido]=lotacao[eventoEscolhido]-1;
																		valorArrecadado[eventoEscolhido]=valorArrecadado[eventoEscolhido]+precoTotal;
																		ingressosVendidos[eventoEscolhido]++;
																		escolhaPagamentoErrado=0;
																		break;
																		
																	case 2:
																		
																		printf("\nDigite o valor pago:\n");
																		scanf("%f", &valorPago);
																		
																		trocoRecebido=valorPagamentoDinheiroMeia(valorPago, precoTotal);
																		
																		printf("\nVoce recebe de troco %f reais.\n", trocoRecebido);
																		
																		lotacao[eventoEscolhido]=lotacao[eventoEscolhido]-1;
																		valorArrecadado[eventoEscolhido]=valorArrecadado[eventoEscolhido]+(precoTotal*0.9);
																		ingressosVendidos[eventoEscolhido]++;
																		escolhaPagamentoErrado=0;
																		break;
																		
																	default:
																		
																		printf("\nVoce escolheu uma forma de pagamento inexistente.\n\n");
																		
																		escolhaPagamentoErrado=1;
																		break;
																}
																
															}while(escolhaPagamentoErrado==1);
																												
															meiaOuInteiraErrado=0;	
															lotacaoMeia[eventoEscolhido]--;
														}else{
															
															printf("\nAcabou os ingressos deste evento do tipo meia.\n\n");
															meiaOuInteiraErrado=1;
															
														}
														break;
														
													case 2:
														if(lotacaoInteira[eventoEscolhido]>0){
														
															preco=precoVetor[eventoEscolhido];
															precoTotal=preco;
															
															do{	
																printf("Voce deve pagar %f reais, Digite 1 para pagar com cartao e 2 para pagar com dinheiro.\n", precoTotal);
																scanf("%i", &escolhaPagamento);
																
																switch(escolhaPagamento){
																	
																	case 1:
																		
																		printf("\nDigite o valor pago:\n");
																		scanf("%f", &valorPago);
																		
																		trocoRecebido=valorPagamentoCartaoInteiro(valorPago, precoTotal);
																		
																		printf("\nVoce recebe de troco %f reais.\n", trocoRecebido);
																		
																		lotacao[eventoEscolhido]=lotacao[eventoEscolhido]-1;
																		valorArrecadado[eventoEscolhido]=valorArrecadado[eventoEscolhido]+precoTotal;
																		ingressosVendidos[eventoEscolhido]++;
																		escolhaPagamentoErrado=0;
																		break;
																		
																	case 2:
																		
																		printf("\nDigite o valor pago:\n");
																		scanf("%f", &valorPago);
																		
																		trocoRecebido=valorPagamentoDinheiroInteiro(valorPago, precoTotal);
																		
																		printf("\nVoce recebe de troco %f reais.\n", trocoRecebido);
																		
																		lotacao[eventoEscolhido]=lotacao[eventoEscolhido]-1;
																		valorArrecadado[eventoEscolhido]=valorArrecadado[eventoEscolhido]+(precoTotal*0.9);
																		ingressosVendidos[eventoEscolhido]++;
																		escolhaPagamentoErrado=0;
																		break;
																		
																	default:
																		
																		printf("\nVoce escolheu uma forma de pagamento inexistente.\n\n");
																		
																		escolhaPagamentoErrado=1;
																		break;
																}
																
															}while(escolhaPagamentoErrado==1);
															
															meiaOuInteiraErrado=0;	
															lotacaoInteira[eventoEscolhido]--;
														}else{
															
															printf("\nAcabou os ingressos deste evento do tipo inteiro.\n\n");
															meiaOuInteiraErrado=1;
														}
														
														break;
														
													default:
														
														printf("\nVoce digitou uma opcao errada para meia ou inteira.\n\n");
														meiaOuInteiraErrado=1;										
														
														break;
												}
												
																								
											}else{
												
												printf("\nAcabou os ingressos deste evento.\n\n");
												eventoEscolhidoErrado=1;
												meiaOuInteiraErrado=0;
											}
										}while(meiaOuInteiraErrado==1);
										
									}
										break;
									
							}
						
						
						refazerEscolha=0;
					}
				}while(eventoEscolhidoErrado==1);	
					
					break;
					
				case 3:
					
					exit(0);
					
					break;
					
				default:
					
					printf("\nNao eh uma opcao\n\n");
					
					refazerEscolha=1;
					
					break;
			}		
		}while(refazerEscolha==1);
		
		do{
			printf("\nDigite 1 para continuar no programa e 2 para sair.\n");
			scanf("%i", &escolhaContinuar);
			
			switch(escolhaContinuar){
				
				case 1:
					
					
					continuar=1;
					escolhaErrado=0;
					break;
					
				case 2:
					
					for(cont=0 ; cont<evento ; cont++){
						
						printf("\nForam vendidos %i do evento %i.\n", ingressosVendidos[cont], cont);
						printf("\nFoi arrecadado %f do evento %i\n\n", valorArrecadado[cont], cont);
						
					}
					
					continuar=0;
					escolhaErrado=0;
					break;
					
				default:
					
					printf("\nVoce digitou uma escolha inexistente.\n\n");
					
					escolhaErrado=1;
					break;
			}
		}while(escolhaErrado==1);
		
	}while(continuar==1);
	
	
	return 0;
}
