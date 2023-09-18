#include <stdio.h>
#include <stdlib.h>


// Trabalho pratico de Programação I, codigo escrito por Alfred Louis Piper & Brendha Michels Ramos.

int main(int argc, char *argv[]) {

int jogadorA, jogadorB, jogadorH, cpu, jogadorAresult, jogadorBresult, jogadorHresult, cpuresult, menu1, menu2, escolha, numerojogadas, porcentagem1, porcentagem2, porcentagem3, vitorias, empate, jogadorArank, jogadorBrank, jogadorHrank, cpurank, contador;
int A, B, C, D; // Variaveis auxialiares utilizadas no Ranking!

jogadorArank=0;
jogadorBrank=0;
jogadorHrank=0;
cpurank=0;
A=0;
B=0;
C=0;
D=0;
menu1=50;

	while(menu1==50)
	{
	//menu1 inicial =50, Menu PvP =51, Menu PvC =52, Ranking = 53, Regras do jogo =54, Menu Creditos =55, Menu Sair =56.
	//menu2 variavel a prova de falhas! 
	
		printf("\n (I_I)=o Jokenpo o=(I_I) \n DIGITE! \n 1.Jogador contra jogador \n 2.Jogador contra CPU \n 3.Ranking Completo \n 4.Regras/Manuais do jogo \n 5.Creditos \n 6.Sair do Jogo \n Sua Escolha: "); 
		scanf("%d", &escolha);
		
		switch(escolha)
		{
			case 1:
			{
				menu1=51;
				break;
			}
			case 2:
			{
				menu1=52;
				menu2=70;
				break;
			}
			case 3: //Ranking mostra todas as colocações jogadores em ordem de numero de vitorias (Jogador A, Jogador B, Jogador, CPU) obs: Os dados só ficam armazenados se mater o programa aberto, ou seja, se reiniciar o programa se perde as estatisticas!
			{
				menu1=53; 
				break;
			}
			case 4:
			{
				menu1=54;
				break;	
			}
			case 5:
			{
				menu1=55;
				break;
			}
			case 6:
			{
				menu1=56;
				break;
			}
			default:
			{
				printf("\n\nESCOLHA UMA OPCAO VALIDA! :C \n\n");
				menu1=50;
				break;
			}
		}
		
		jogadorAresult=0;
		jogadorBresult=0;
		jogadorHresult=0;
		cpuresult=0;
		porcentagem1=0;
		porcentagem2=0;
		porcentagem3=0;
		empate=0;
		numerojogadas=0;
		cpu=0;
		vitorias=0;
		
		while(menu1==51)
		{
			printf("\n\n(I_I)=o|Jogador x Jogador|o=(I_I) \n");
			menu2=60;
			
			while(menu2==60)
			{	
				printf("\n Jogador A (I_I)=o\n 1.Pedra\n 2.Papel\n 3.Tesoura\n Sua jogada: ");
				scanf("%d", &jogadorA);
				
				if(jogadorA>3)
				{
					printf("\n\nESCOLHA UMA OPCAO VALIDA! :C \n\n");
					menu2=60;	
				}
				else
				{
					menu2=61;
				}
			}
			while(menu2==61)
			{
				printf("\n Jogador B (I_I)=o\n 1.Pedra\n 2.Papel\n 3.Tesoura\n Sua jogada: ");
				scanf("%d", &jogadorB);
				
				if(jogadorB>3)
				{
					printf("\n\nESCOLHA UMA OPCAO VALIDA! :C \n\n");
					menu2=61;	
				}
				else
				{
					menu2=0;
				}
			}
			
			if(jogadorA==1 && jogadorB==1)
			{
				printf("\n ->JOKENPO!!! \n");
				printf(" Jogador A Escolhe Pedra!\n Jogador B Escolhe Pedra!\n\n");
				printf(" Resultado!\n\n");
				printf(" Empate! \n >>Pedra x Pedra<< \n");
				empate++;
			}
			else
			{
				if(jogadorA==1 && jogadorB==2)
				{
					printf("\n ->JOKENPO!!! \n");
					printf(" Jogador A Escolhe Pedra!\n Jogador B Escolhe Papel!\n\n");
					printf(" Resultado!\n\n");
					printf(" Jogador B Vence! \n >>Papel ganha de Pedra<< \n");
					jogadorBresult++;
					vitorias++;
				}
				else
				{
					if(jogadorA==1 && jogadorB==3)
					{
						printf("\n ->JOKENPO!!! \n");
						printf(" Jogador A Escolhe Pedra!\n Jogador B Escolhe Tesoura!\n\n");
						printf(" Resultado!\n\n");
						printf(" Jogador A Vence! \n >>Pedra ganha de tesoura<< \n");
						jogadorAresult++;
						vitorias++;
					}
					else
					{
						if(jogadorA == 2 && jogadorB == 1)
						{
							printf("\n ->JOKENPO!!! \n");
							printf(" Jogador A Escolhe Papel!\n Jogador B Escolhe Pedra!\n\n");
							printf(" Resultado!\n\n");
							printf(" Jogador A Vence! \n >>Papel ganha de Pedra<< \n");
							jogadorAresult++;
							vitorias++;
						}
						else
						{
							if(jogadorA==2 && jogadorB==2)
							{
								printf("\n ->JOKENPO!!! \n");
								printf(" Jogador A Escolhe Papel!\n Jogador B Escolhe Papel!\n\n");
								printf(" Resultado!\n\n");
								printf(" Empate! \n >>Papel x Papel<< \n");
								empate++;
							}
							else
							{
								if(jogadorA==2 && jogadorB==3)
								{
									printf("\n ->JOKENPO!!! \n");
									printf(" Jogador A Escolhe Papel!\n Jogador B Escolhe Tesoura!\n\n");
									printf(" Resultado!\n\n");
									printf(" Jogador B Vence! \n >>Tesoura ganha de Papel<< \n");
									jogadorBresult++;
									vitorias++;
								}
								else
								{
									if(jogadorA==3 && jogadorB==1)
									{
										printf("\n ->JOKENPO!!! \n");
										printf(" Jogador A Escolhe Tesoura!\n Jogador B Escolhe Pedra!\n\n");
										printf(" Resultado!\n\n");
										printf(" Jogador B Vence! \n >>Pedra ganha de Tesoura<< \n");
										jogadorBresult++;
										vitorias++;
									}
									else
									{
										if(jogadorA==3 && jogadorB==2)
										{
											printf("\n ->JOKENPO!!! \n");
											printf(" Jogador A Escolhe Tesoura!\n Jogador B Escolhe Papel!\n\n");
											printf(" Resultado!\n\n");
											printf(" Jogador A Vence! \n >>Tesoura ganha de Papel<< \n");
											jogadorAresult++;
											vitorias++;
										}
										else
										{
											if(jogadorA==3 && jogadorB==3)
											{
												printf("\n ->JOKENPO!!! \n");
												printf(" Jogador A Escolhe Tesoura!\n Jogador B Escolhe Tesoura!\n\n");
												printf(" Resultado!\n\n");
												printf(" Empate!\n >>Tesoura x Tesoura<< \n");
												empate++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			printf("\n PLACAR! (I_I)=oo=(I_I) \n");
			printf(" Jogador A: %d \n", jogadorAresult);
			printf(" Jogador B: %d \n", jogadorBresult);
			numerojogadas++;
			
			if(vitorias>0)
			{
				porcentagem1=(jogadorAresult*100)/vitorias;
				porcentagem2=(jogadorBresult*100)/vitorias;
			}
			
			menu2=62;
		
			while(menu2==62)
			{
				printf("\n 1.Jogar novamente \n 2.Sair \n Sua escolha: ");
				scanf("%d", &escolha);
			
				switch(escolha)
				{
					case 1:
					{
						menu1=51;
						menu2=60;
						break;
					}
					case 2:
					{
						printf("\n\n|----------------|Estatisticas da partida|----------------|\n");
						printf(" Numero de Partidas: %d \n", numerojogadas);
						printf(" Empates: %d \n", empate);
						printf(" Vitorias: %d \n", vitorias);
						printf("\n Porcentual de vitorias! \n");
						printf(" Jogador A: %d%% \n", porcentagem1);
						printf(" Jogador B: %d%% \n", porcentagem2);
						
						porcentagem1=(jogadorAresult*100)/numerojogadas;
						porcentagem2=(jogadorBresult*100)/numerojogadas;
						porcentagem3=(empate*100)/numerojogadas;
						
						printf("\n Percentual Total! \n");
						printf(" Jogador A: %d%% \n", porcentagem1);
						printf(" Jogador B: %d%% \n", porcentagem2);
						printf(" Empates: %d%% \n", porcentagem3);
					
						if(jogadorAresult==jogadorBresult)
						{
							printf("|----|Nao houve Vencedores!|----|\n");
						}
						else
						{
							if(jogadorAresult>jogadorBresult)
							{
								printf("|----|Jogador A Vence!|----|\n");
							}
							else
							{
								printf("|----|Jogador B Vence!|----|\n");
							}
						}	
						printf("|---------------------------------------------------------|\n");
						
						jogadorArank = jogadorArank + jogadorAresult;
						jogadorBrank = jogadorBrank + jogadorBresult;
						
						menu1=50;
						menu2=0;
						break;
					}
					default:
					{
						printf("\n\nESCOLHA UMA OPCAO VALIDA! :C \n\n");
						menu2=62;
					}
				}		
			}
		}	
		
		while(menu1==52)
		{
			printf("\n\n(I_I)=o|Jogador x CPU|o=[._.] \n");
			
			while(menu2==70)
			{	
				printf("\n Jogador H (I_I)=o\n 1.Pedra\n 2.Papel\n 3.Tesoura\n Sua jogada: ");
				scanf("%d", &jogadorH);
				
				if(jogadorH>3)
				{
					printf("\n\nESCOLHA UMA OPCAO VALIDA! :C \n\n");
					menu2=70;	
				}
				else
				{
					menu2=71;
				}
			}	
						
			srand(time(NULL));
    		cpu = rand() % 3;
    		cpu++;
    		
    		if(jogadorH==1 && cpu==1)
			{
				printf("\n ->JOKENPO!!! \n");
				printf(" Jogador H Escolhe Pedra!\n CPU Escolhe Pedra!\n\n");
				printf(" Resultado!\n\n");
				printf(" Empate! \n >>Pedra x Pedra<< \n");
				empate++;
			}
			else
			{
				if(jogadorH==1 && cpu==2)
				{
					printf("\n ->JOKENPO!!! \n");
					printf(" Jogador H Escolhe Pedra!\n CPU Escolhe Papel!\n\n");
					printf(" Resultado!\n\n");
					printf(" CPU Vence! \n >>Papel ganha de Pedra<< \n");
					cpuresult++;
					vitorias++;
				}
				else
				{
					if(jogadorH==1 && cpu==3)
					{
						printf("\n ->JOKENPO!!! \n");
						printf(" Jogador H Escolhe Pedra!\n CPU Escolhe Tesoura!\n\n");
						printf(" Resultado!\n\n");
						printf(" Jogador H Vence! \n >>Pedra ganha de tesoura<< \n");
						jogadorHresult++;
						vitorias++;
					}
					else
					{
						if(jogadorH == 2 && cpu == 1)
						{
							printf("\n ->JOKENPO!!! \n");
							printf(" Jogador H Escolhe Papel!\n CPU Escolhe Pedra!\n\n");
							printf(" Resultado!\n\n");
							printf(" Jogador H Vence! \n >>Papel ganha de Pedra<< \n");
							jogadorHresult++;
							vitorias++;
						}
						else
						{
							if(jogadorH==2 && cpu==2)
							{
								printf("\n ->JOKENPO!!! \n");
								printf(" Jogador H Escolhe Papel!\n CPU Escolhe Papel!\n\n");
								printf(" Resultado!\n\n");
								printf(" Empate! \n >>Papel x Papel<< \n");
								empate++;
							}
							else
							{
								if(jogadorH==2 && cpu==3)
								{
									printf("\n ->JOKENPO!!! \n");
									printf(" Jogador H Escolhe Papel!\n CPU Escolhe Tesoura!\n\n");
									printf(" Resultado!\n\n");
									printf(" CPU Vence! \n >>Tesoura ganha de Papel<< \n");
									cpuresult++;
									vitorias++;
								}
								else
								{
									if(jogadorH==3 && cpu==1)
									{
										printf("\n ->JOKENPO!!! \n");
										printf(" Jogador H Escolhe Tesoura!\n CPU Escolhe Pedra!\n\n");
										printf(" Resultado!\n\n");
										printf(" CPU Vence! \n >>Pedra ganha de Tesoura<< \n");
										cpuresult++;
										vitorias++;
									}
									else
									{
										if(jogadorH==3 && cpu==2)
										{
											printf("\n ->JOKENPO!!! \n");
											printf(" Jogador H Escolhe Tesoura!\n CPU Escolhe Papel!\n\n");
											printf(" Resultado!\n\n");
											printf(" Jogador H Vence! \n >>Tesoura ganha de Papel<< \n");
											jogadorHresult++;
											vitorias++;
										}
										else
										{
											if(jogadorH==3 && cpu==3)
											{
												printf("\n ->JOKENPO!!! \n");
												printf(" Jogador H Escolhe Tesoura!\n CPU Escolhe Tesoura!\n\n");
												printf(" Resultado!\n\n");
												printf(" Empate!\n >>Tesoura x Tesoura<< \n");
												empate++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			printf("\n PLACAR! (I_I)=oo=[._.] \n");
			printf(" Jogador H: %d \n", jogadorHresult);
			printf(" CPU: %d \n", cpuresult);
			numerojogadas++;
			
			if(vitorias>0)
			{
				porcentagem1=(jogadorHresult*100)/vitorias;
				porcentagem2=(cpuresult*100)/vitorias;
			}
			
			
			
			while(menu2==71)
			{
				printf("\n 1.Jogar novamente \n 2.Sair \n Sua escolha: ");
				scanf("%d", &escolha);
			
				switch(escolha)
				{
					case 1:
					{
						menu1=52;
						menu2=70;
						break;
					}
					case 2:
					{
						printf("\n\n|----------------|Estatisticas da partida|----------------|\n");
						printf(" Numero de Partidas: %d \n", numerojogadas);
						printf(" Empates: %d \n", empate);
						printf(" Vitorias: %d\n\n", vitorias);
						printf(" Porcentual de vitorias! \n");
						printf(" Jogador H: %d%% \n", porcentagem1);
						printf(" CPU: %d%% \n", porcentagem2);
						
						porcentagem1=(jogadorHresult*100)/numerojogadas;
						porcentagem2=(cpuresult*100)/numerojogadas;
						porcentagem3=(empate*100)/numerojogadas;
						
						printf("\n Percentual Total! \n");
						printf(" Jogador H: %d%% \n", porcentagem1);
						printf(" CPU: %d%% \n", porcentagem2);
						printf(" Empates: %d%% \n", porcentagem3);
						
						if(jogadorHresult==cpuresult)
						{
							printf("|----|Nao houve Vencedores!|----|\n");
						}
						else
						{
							if(jogadorHresult>cpuresult)
							{
								printf("|----|Jogador H Vence!|----|\n");
							}
							else
							{
								printf("|----|CPU Vence!|----|\n");
							}
						}
						printf("|---------------------------------------------------------|\n");
						
						cpurank = cpurank + cpuresult;
						jogadorHrank = jogadorHrank + jogadorHresult;
						
						menu1=50;
						menu2=0;
						break;
					}
					default:
					{
						printf("\n\nESCOLHA UMA OPCAO VALIDA! :C \n\n");
						menu2=71;
					}
				}		
			}
		}
		
		while(menu1==53)
		{
			printf("\n Ranking completo \n");
			contador=1;
			
			A=jogadorArank + 1;
			B=jogadorBrank + 1;
			C=cpurank + 1;
			D=jogadorHrank + 1;
			
			while(contador<5)
			{
				if(A>=B && A>=C && A>=D)
				{
					printf(" %d - Jogador A = %d Pontos \n", contador, jogadorArank);
					A = 0;
					contador++;
				}
				else
				{
					if(B>=A && B>=C && B>=D)
					{
						printf(" %d - Jogador B = %d Pontos \n", contador, jogadorBrank);
						B = 0;
						contador++;
					}
					else
					{
						if(C>=A && C>=B && C>=D)
						{
							printf(" %d - CPU = %d Pontos \n", contador, cpurank);
							C = 0;
							contador++;
						}
						else
						{
							if(D>=A && D>=B && D>=C)
							{
								printf(" %d - Jogador H = %d Pontos \n", contador, jogadorHrank);
								D = 0;
								contador++;
							}
						}
					}
				}
			}
			
			menu2=80;
			
			while(menu2 == 80)
			{
				
				printf("\n Digite \n 1.Sair: ");
				scanf("%d", &escolha);
			
				switch(escolha)
				{
					case 1:
					{
						menu1=50;
						menu2=0;
						break;
					}
					default:
					{
						printf("\n\nESCOLHA UMA OPCAO VALIDA! :C \n\n");	
						menu2=80;
						break;
					}
				}
			}		
		}
		
		while(menu1==54)
		{
			printf("\n\n JOKENPO - PEDRA, PAPEL E TESOURA \n\n");
			printf(" ->  Pedra ganha da tesoura amassando-a ou quebrando-a. \n ->  Tesoura ganha do papel cortando-o. \n ->  Papel ganha da pedra embrulhando-a. \n     NO MAXIMO 2 JOGADORES \n\n");
			printf(" >|Jogador contra Jogador|<\n Nesse modo de jogo voce irar jogar contra outro jogador (Humano), sendo \n ""Jogador A"" e ""jogador B"" como voce e seu oponente. Ao sair ira aparecer as\n estaticas da partida. \n\n ");
			printf(" >|Jogador contra CPU|<\n Nesse modo de jogo voce ira jogar contra o Computador, sendo ""Jogador H"" como \n voce (Humano) e ""CPU"" como (computador). Ao sair ira aparecer as estaticas\n da partida. \n\n");
			printf(" >|Ranking Completo|<\n Esse modo mostra a posicao de todos os jogadores em ordem de pontuacao, sendo \n que tera no ranking (Jogador A, Jogador B, CPU, Jogador H). \n OBS: O RANKING SERA RESETADO TODA VEZ QUE O JOGO FOR FECHADO! \n\n");
			
			menu2=80;
			
			while(menu2 == 80)
			{
				
				printf("\n Digite \n 1.Sair: ");
				scanf("%d", &escolha);
			
				switch(escolha)
				{
					case 1:
					{
						menu1=50;
						menu2=0;
						break;
					}
					default:
					{
						printf("\n\nESCOLHA UMA OPCAO VALIDA! :C \n\n");	
						menu2=80;
						break;
					}
				}
			}
			
		}	
		while(menu1==55)
		{
			printf("\n CREDITOS:\n Alfred Louis Piper \n");
			printf(" Brendha Michels Ramos \n");
			
			menu2=80;
			
			while(menu2 == 80)
			{
				
				printf("\n Digite \n 1.Sair: ");
				scanf("%d", &escolha);
			
				switch(escolha)
				{
					case 1:
					{
						menu1=50;
						menu2=0;
						break;
					}
					default:
					{
						printf("\n\nESCOLHA UMA OPCAO VALIDA! :C \n\n");	
						menu2=80;
						break;
					}
				}
			}
			
		}
	}
	return 0;
}
