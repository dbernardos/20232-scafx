#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {
	
	srand (time(NULL));
	
	int jogarNovamente;
	int jogarNovamente2;
	int jogarMais = 1;
	int escolhaJogo;
	int jogador1;
	int jogador2;
	int jogadaComputador;
	int linha;
	
	/* variaveis para estatisticas */
	
	int pontosJogador1 = 0;
	int pontosJogador2 = 0;
	int pontosComputador = 0;
	int empate = 0;
	int totalJogadas;
	float porcentagemJogador1;
	float porcentagemJogador2;
	float porcentagemComputador;
	
	printf("\n                              JOKENPO ULTIMATE!\n\n");
	printf("\n                    Digite >1< para jogar contra o computador.\n");
	printf("                    Digite >2< para jogar contra outro humano.\n\n");
	printf("                                     >");
	scanf(" %d", &escolhaJogo);
	
	while(jogarMais > 0){
	
		jogadaComputador = rand()%3+1;
	
		if(escolhaJogo == 1){ /* Teste para jogar contra computador */
	
		printf("\n                          Para jogar PEDRA digite    >1<\n");
		printf("                          Para jogar PAPEL digite    >2<\n");
		printf("                          Para jogar TESOURA digite  >3<\n\n");
		
		printf("\n                          HUMANO X COMPUTADOR, BOA SORTE!!");
		printf("\n                                Faca a sua jogada: \n\n");
		printf("                                     >");
		scanf(" %d", &jogador1);
		
			if(jogador1 >=1 && jogador1 <=3){ /* Teste para validar a jogada */
			
				printf("\n                                  JO");
				sleep(1);
				printf("KEN");
				sleep(1);
				printf("PO!!! \n\n");
				sleep(1);
				
				for( linha = 0; linha < 35; linha++){ /* limpar a tela */
	   				printf( "\n" );
				}
				
				switch(jogador1){ /* Transforma a jogada do jogador em palavra */
					case 1:
						printf("                                 PEDRA x ");
						break;
					case 2:
						printf("                                 PAPEL x ");
						break;
					case 3:
						printf("                                TESOURA x ");
						break;
				}
			
				switch(jogadaComputador){ /* Transforma a jogada do computador em palavra */
					case 1:
						printf("PEDRA \n\n");
						break;
					case 2:
						printf("PAPEL \n\n");
						break;
					case 3:
						printf("TESOURA \n\n");
						break;
				}
				
				if ((jogador1 == 1 && jogadaComputador == 3) || (jogador1 == 2 && jogadaComputador == 1) || (jogador1 == 3 && jogadaComputador == 2)){ /* Jogador vence */
				
					printf("                                 VOCE VENCEU!!! \n\n");
					
					pontosJogador1 = pontosJogador1 + 1;
				
				}
				
				if (jogador1 == jogadaComputador){ /* Empate */
					
					printf("                                    EMPATE! \n\n");
					
					empate++;
					
				}
				
				if ((jogadaComputador == 1 && jogador1 == 3) || (jogadaComputador == 2 && jogador1 == 1) || (jogadaComputador == 3 && jogador1 == 2)){ /* Jogador perde */
				
					printf("                                 VOCE PERDEU :( \n\n");
				
					pontosComputador = pontosComputador + 1;
				
			}
		} else { /* Jogada invalida */
			
			printf("\n                        Voce nao digitou um numero valido. \n");
			
		}
		
		}
		
		if(escolhaJogo == 2){ /* Teste humano x humano */ 
			
			printf("\n                          Para jogar PEDRA digite    >1<\n");
			printf("                          Para jogar PAPEL digite    >2<\n");
			printf("                          Para jogar TESOURA digite  >3<\n\n");
		
			printf("\n                          HUMANO X HUMANO, BOA SORTE!!");
			printf("\n\n                          JOGADOR 1 Faca a sua jogada: \n\n");
			printf("                                     >");
			scanf(" %d", &jogador1);
			
			if(jogador1 >= 1 && jogador1 <= 3){
			
				for( linha = 0; linha < 35; linha++){ /* limpar a tela */
	   				printf( "\n" );
				}
				
				printf("\n                          Para jogar PEDRA digite    >1<\n");
				printf("                          Para jogar PAPEL digite    >2<\n");
				printf("                          Para jogar TESOURA digite  >3<\n\n");
				
				printf("\n                          HUMANO X HUMANO, BOA SORTE!!");
				printf("\n\n                          JOGADOR 2 Faca a sua jogada: \n\n");
				printf("                                     >");
				scanf(" %d", &jogador2);
				
				if(jogador2 >= 1 && jogador2 <= 3) {
					
					printf("\n                                  JO");
					sleep(1);
					printf("KEN");
					sleep(1);
					printf("PO!!! \n\n");
					sleep(1);
				
					for( linha = 0; linha < 35; linha++){ /* limpar a tela */
   						printf( "\n" );
					}
					
					switch(jogador1){ /* Transforma a jogada do jogador 1 em palavra */
					case 1:
						printf("                                 PEDRA x ");
						break;
					case 2:
						printf("                                 PAPEL x ");
						break;
					case 3:
						printf("                                TESOURA x ");
						break;
					}
					
					switch(jogador2){ /* Transforma a jogada do jogador 2 em palavra */
					case 1:
						printf("PEDRA \n\n");
						break;
					case 2:
						printf("PAPEL \n\n");
						break;
					case 3:
						printf("TESOURA \n\n");
						break;
					}
					
					if ((jogador1 == 1 && jogador2 == 3) || (jogador1 == 2 && jogador2 == 1) || (jogador1 == 3 && jogador2 == 2)){ /* Jogador 1 vence */
				
						printf("                               JOGADOR 1 VENCEU! \n\n");
						
						pontosJogador1 = pontosJogador1 + 1;
				
					}
				
					if (jogador1 == jogador2){ /* Empate */
					
						printf("                                    EMPATE! \n\n");
						
						empate++;
					
					}
				
					if ((jogador2 == 1 && jogador1 == 3) || (jogador2 == 2 && jogador1 == 1) || (jogador2 == 3 && jogador1 == 2)){ /* Jogador 2 vence */
				
						printf("                               JOGADOR 2 VENCEU! \n\n");
						
						pontosJogador2 = pontosJogador2 + 1;
				
					}
			
				} else { /* Jogada invalida */
			
					printf("\n                        Voce nao digitou um numero valido. \n");
			
				}
		
			} else { /* Jogada invalida */
			
				printf("\n                        Voce nao digitou um numero valido. \n");
			
			}
	
		}
		
		if(escolhaJogo > 2){ /* Escolha do jogo invalida */ 
			
			printf("\n              Voce nao digitou um numero valido. Reinicie o jogo. \n");
			exit(0);
			
		}

		printf("\n\n\n\n\n\n\n\n                          Para jogar novamente digite >1< \n");
		printf("                          Para estatisticas digite    >2< \n");
		printf("                          Para sair digite            >3< \n\n");
		printf("                                     >");
		scanf(" %d", &jogarNovamente);
		
		if(jogarNovamente == 1){ /* Jogar novamente */
			
			for( linha = 0; linha < 35; linha++){ /* limpar a tela */
	   				printf( "\n" );
				}
			
		}

		if(jogarNovamente == 2){ /*estatisticas do jogo */
			
			for( linha = 0; linha < 35; linha++){ /* limpar a tela */
	   				printf( "\n" );
			}
			
			totalJogadas = pontosJogador1 + pontosJogador2 + pontosComputador + empate;
			
			printf("\n                                 ESTATISTICAS!\n\n");
			printf("                          Vitorias do Jogador 1:     >%d< \n", pontosJogador1);
			
			if(pontosJogador2 > 0){
				
				printf("                      Vitorias do Jogador 2:     >%d< \n\n", pontosJogador2);
				printf("                      Empates:                   >%d< \n\n", empate);
				
				porcentagemJogador1 = ((float)pontosJogador1 / (float)totalJogadas) * 100;
				porcentagemJogador2 = ((float)pontosJogador2 / (float)totalJogadas) * 100;
				
				printf("                  Porcentagem de vitorias do Jogador 1:     >%.1f< \n", porcentagemJogador1);
				printf("                  Porcentagem de vitorias do Jogador 2:     >%.1f< \n", porcentagemJogador2);
			
			}
			
			if(pontosComputador > 0){
				
				printf("                          Vitorias do Computador:    >%d< \n\n", pontosComputador);
				printf("                          Empates:                   >%d< \n\n", empate);
				
				porcentagemJogador1 = ((float)pontosJogador1 / (float)totalJogadas) * 100;
				porcentagemComputador = ((float)pontosComputador / (float)totalJogadas) * 100;
				
				printf("                  Porcentagem de vitorias do Jogador 1:     >%.1f< \n", porcentagemJogador1);
				printf("                  Porcentagem de vitorias do Computador:    >%.1f< \n", porcentagemComputador);
				
			}
			
			if(pontosJogador2 == 0 && pontosComputador == 0){
				
				if(escolhaJogo == 1){
					
					printf("                          Vitorias do Computador:    >%d< \n\n", pontosComputador);
					
				}
				
				if(escolhaJogo == 2){
					
					printf("                          Vitorias do Jogador 2:     >%d< \n\n", pontosJogador2);
					
				}
				
				if(empate > 0){
					
						printf("                          Empates:                   >%d< \n\n", empate);
						
				}
				
				porcentagemJogador1 = ((float)pontosJogador1 / (float)totalJogadas) * 100;
				printf("                  Porcentagem de vitorias do Jogador 1:     >%.1f< \n\n", porcentagemJogador1);
				
			}
			
			for( linha = 0; linha < 13; linha++){ /* pula linha */
	   				printf( "\n" );
			}
			
			printf("                          Para jogar novamente digite >1< \n");
			printf("                          Para sair digite            >2< \n\n");
			printf("                                     >");
			scanf(" %d", &jogarNovamente2);
			
			if(jogarNovamente2 == 1){ /*volta ao jogo */
				
				for( linha = 0; linha < 35; linha++){ /* limpar a tela */
				
	   				printf( "\n" );
	   				
				}
				
			}
			
			if(jogarNovamente2 == 2){ /* sair */
				
				exit(0);
				
			}
			
			if(jogarNovamente2 >= 3){
				
				printf("\n              Voce nao digitou um numero valido. Reinicie o jogo. \n");
				exit(0);
				
			}
			
		}
		
		if(jogarNovamente == 3){
		
			exit(0);
			
		}
		
		if(jogarNovamente >= 4){
			
			printf("\n              Voce nao digitou um numero valido. Reinicie o jogo. \n");
			exit(0);
			
		}
		 
	}
	
	return 0;
}
