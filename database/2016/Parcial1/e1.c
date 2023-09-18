#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int jogador1;
	int jogador2; 
	int cpu;
	int modoJogo;
	int jogueNovamente;
	int jogador;
	int empate = 0;
	int nroPartidas = 0;
	float auxJogador1 = 0;
	float auxJogador2 = 0;
	float auxCpu = 0;
	float auxJogador = 0;
	float resultCpu;
	float resultJogador2;
	float resultJogador1;
	float resultJogador;
	

		
			
		printf("Digite o modo em que deseja jogar: \n");
		printf("1 - vs Humano \n");
		printf("2 - vs CPU \n\n");
		scanf("%d", &modoJogo);
		
		printf("\n\n");
		
		
	do
	{
		
	
			switch(modoJogo)
			{
				case 1:
				{
					//Escolha jogador 1
					printf("VS HUMANO \n\n");
					printf("Qual a jogada do primeiro jogador?? \n");
					printf("1 - Pedra \n");
					printf("2 - Tesoura \n");
					printf("3 - Papel \n\n");
					scanf("%d", &jogador1);
					
						if(jogador1 == 1)
						{
							printf("Jogador 1 escolheu PEDRA \n\n");
						}
						else if(jogador1 == 2)
						{
							printf("Jogador 1 escolheu TESOURA \n\n");
						}
						else if(jogador1 == 3)
						{
							printf("Jogador 1 escolheu PAPEL \n\n");
						}
						else
						{
							printf("Jogada Invalida!\n\n");
							return 0;
						}
					
					
					//Escolha jogador 2
					
					printf("Qual a jogada do segundo jogador?? \n");
					printf("1 - Pedra \n");
					printf("2 - Tesoura \n");
					printf("3 - Papel \n\n");	
					scanf("%d", &jogador2);
					
						if(jogador2 == 1)
						{
							printf("Jogador 2 escolheu PEDRA \n\n");
						}
						else if(jogador2 == 2)
						{
							printf("Jogador 2 escolheu TESOURA \n\n");
						}
						else if(jogador2 == 3)
						{
							printf("Jogador 2 escolheu PAPEL \n\n");
						}
						else
						{
							printf("Jogada Invalida! \n\n");
							return 0;
						}
							
							//Verificações de ganhador
							if(jogador1 == 1 && jogador2 == 1)
								{
									printf("*******Empate******** \n\n");
									empate++;
									nroPartidas ++;
										}
										else if(jogador1 == 1 && jogador2 == 2)
										{
											printf("Pedra ganha de Tesoura, Jogador 1 ganhou! \n\n");
											auxJogador1 ++;
											nroPartidas ++;
												}		
												else if(jogador1 == 1 && jogador2 == 3)
												{
													printf("Papel ganha de Pedra. Jogador 2 ganhou! \n\n");
													auxJogador2 ++;
													nroPartidas ++;
												}
													else if(jogador1 == 2 && jogador2 == 1)
													{
														printf("Pedra ganha de Tesoura. Jogador 2 ganhou! \n\n");
														auxJogador2 ++;
														nroPartidas ++;
													}
														else if(jogador1 == 2 && jogador2 == 2)
														{
															printf("********Empate******** \n\n");
															empate ++;
															nroPartidas ++;
														}
															else if(jogador1 == 2 && jogador2 == 3)
															{
																printf("Tesoura ganha de Papel. Jogador 2 ganhou!! \n\n");
																auxJogador2 ++;
																nroPartidas ++;
															}
																else if(jogador1 == 3 && jogador2 == 1)
																{
																	printf("Papel ganha de Pedra. Jogador 1 ganhou!! \n\n");
																	auxJogador1 ++;
																	nroPartidas ++;	
																}
																	else if(jogador1 == 3 && jogador2 == 2)
																	{
																		printf("Tesoura ganha de Papel. Jogador 2 ganhou!! \n\n");	
																		auxJogador2 ++;
																		nroPartidas ++;
																	}
																		else if(jogador1 == 3 && jogador2 == 3)
																		{
																			printf("********Empate********\n\n");
																			empate ++;
																			nroPartidas ++;
																		}			
												
						break;	
				}
				case 2:
				{
					printf("VS CPU\n\n");
					printf("Qual a sua jogada?? \n");
					printf("1 - Pedra \n");
					printf("2 - Tesoura \n");
					printf("3 - Papel \n\n");	
					scanf("%d", &jogador);
					
						if(jogador == 1)
						{
							printf("Jogador 1 escolheu PEDRA \n\n");
						}
						else if(jogador == 2)
						{
							printf("Jogador 1 escolheu TESOURA \n\n");
						}
						else if(jogador == 3)
						{
							printf("Jogador 1 escolheu PAPEL \n\n");
						}
						else
						{
							printf("Jogada Invalida! \n\n");
							return 0;
						}
						
						//Escolha CPU
						
					srand(time(NULL));
			   		cpu = rand() % 3;
			   		
			   			if(cpu == 0)
						{
							printf("CPU escolheu PEDRA\n\n");
						}
						else if(cpu == 1)
						{
							printf("CPU escolheu TESOURA\n\n");
						}
						else if(cpu == 2)
						{
							printf("CPU escolheu PAPEL\n\n");
						}
					
						if(jogador == 1 && cpu == 0)
								{
									printf("Empate\n\n");
									empate ++;
									
										}
										else if(jogador == 1 && cpu == 1)
										{
											printf("Pedra ganha de Tesoura, Jogador ganhou!\n\n");
											auxJogador ++;
											nroPartidas ++;
											
												}		
												else if(jogador == 1 && cpu == 2)
												{
													printf("Papel ganha de Pedra. CPU ganhou!\n\n");
													auxCpu ++;
													nroPartidas ++;
												
												}
													else if(jogador == 2 && cpu == 0)
													{
														printf("Pedra ganha de Tesoura. CPU ganhou!\n\n");
														auxCpu ++;
														nroPartidas ++;
														
													}
														else if(jogador == 2 && cpu == 1)
														{
															printf("********Empate********\n\n");
															empate ++;
															nroPartidas ++;
															
														}
															else if(jogador == 2 && cpu == 2)
															{
																printf("Tesoura ganha de Papel. CPU ganhou!! \n\n");
																auxCpu ++;
																nroPartidas ++;
																
															}
																else if(jogador == 3 && cpu == 0)
																{
																	printf("Papel ganha de Pedra. Jogador ganhou!!\n\n");
																	auxJogador ++;
																	nroPartidas ++;
																		
																}
																	else if(jogador == 3 && cpu == 1)
																	{
																		printf("Tesoura ganha de Papel. CPU ganhou!!\n\n");
																		auxCpu ++;	
																		nroPartidas ++;
																	
																	}
																		else if(jogador == 3 && cpu == 2)
																		{
																			printf("********Empate******** \n\n");
																			empate ++;
																			nroPartidas ++;
																		}					
					break;
				}
				default:
				{
					printf("Jogada invalida, jogue novamente!\n\n");
					break;
				}
				
			}
			
			printf("Voce deseja jogar novamente? \n");
			printf("1 - Sim \n");
			printf("2 - Nao \n");
			scanf("%d", &jogueNovamente);
			
		
	}
	while(jogueNovamente == 1);

			
				if(modoJogo = 1)
				{
					
					resultJogador1 = (auxJogador1 / nroPartidas) * 100;
					resultJogador2 = (auxJogador2 / nroPartidas) * 100;	
					
				printf("Numero total de partidas: %d\n\n", nroPartidas);
				
				printf("Numero de empates: %d \n\n", empate);
				
				printf("Jogador 1 ganhou %g%% das partidas \n\n", resultJogador1);
				
				printf("Jogador 2 ganhou %g%% das partidas.\n\n", resultJogador2);
					
			}
			
			else if (modoJogo = 2)
				{
					resultCpu = (auxCpu / nroPartidas) * 100;
					resultJogador = (auxJogador / nroPartidas) * 100;
					
					printf("Numero total de partidas: %d\n\n", nroPartidas);
					
					printf("Numero de empates: %d \n\n", empate);
					
					printf("CPU ganhou %g%% das partidas \n\n", resultCpu);
					
					printf("JogadorCpu ganhou %g%% contra a CPU \n\n", resultJogador);
				}
					else 
					{
						printf("Escolha Invalida.");
					}
			
	return 0;
}
