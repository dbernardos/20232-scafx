#include <stdio.h>
#include <stdlib.h>

/* LUCAS MORAES NERY - BACHARELADO EM SISTEMAS DE INFORMAÇÃO - 1º PERIODO */

int main(int argc, char *argv[]) {

int pjogador1, pjogador2, pCPU, jogador1, jogador2, cpu, menu1, menu2, jogarNovamente, voltar, nPartidas, eJogador1, eJogador2, eCPU, vPartidas, nEmpates;
	
	pjogador1=0;
	pjogador2=0;
	pCPU=0;
	nPartidas=0;
	vPartidas=0;
	cpu=1;
	nEmpates=0;
	
	printf("\n\n\n\n");
	printf("                       ____ ____ ____ ____ ____ ____ ____ \n");
	printf("                      ||J |||O |||K |||E |||N |||P |||O ||\n");
	printf("                      ||__|||__|||__|||__|||__|||__|||__||\n\n\n\n\n");
   	system("pause");
   	system("cls");
	
		do
		{
			printf("Menu\n\n");
			printf("1 - Jogar\n");
			printf("2 - Regras\n");
			printf("3 - Sair ");
			scanf("%d",&menu1);
	
			if (menu1==1) 
			{
				system("cls");
				printf("Modo de Jogo:\n");
				printf("\n1 - Jogador VS Jogador\n");
				printf("2 - Jogador VS Computador ");
				scanf("%d",&menu2);
				
					switch(menu2)
					{
						case 1:
							do
							{
								system("cls");
								printf("PARTIDAS JOGADAS: %d\n", nPartidas);
								printf("Jogador I %d x %d Jogador II\n\n", pjogador1, pjogador2);
								printf("JOGADOR 1:\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA ");
								scanf("%d", &jogador1);
								system("cls");
								printf("JOGADOR 2:\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA ");
								scanf("%d", &jogador2);
								nPartidas++;
																					
								if(jogador1 == 1 && jogador2 == 3|| jogador1 == 2 && jogador2 == 1 || jogador1 == 3 && jogador2 == 2)
								{
									pjogador1++;
									system("cls");
									printf("\n\nJOGADOR 1 VENCEU\n\n");
									vPartidas++;
										
								}else
								if(jogador2 == 1 && jogador1 == 3|| jogador2 == 2 && jogador1 == 1 || jogador2 == 3 && jogador1 == 2)
								{
									pjogador2++;
									system("cls");
									printf("\n\nJOGADOR 2 VENCEU\n\n");
									vPartidas++;
										
								}else
								if(jogador1 == jogador2)
								{
									system("cls");
									printf("\n\nEMPATOU\n\n");
									nEmpates++;
								}
							
								eJogador1 = pjogador1 * 100 / vPartidas;
								eJogador2 = pjogador2 * 100 / vPartidas;
										
								printf("\n - ESTATISTICAS - \n\n");
								printf("PARTIDAS JOGADAS: %d\n", nPartidas);
								printf("PARTIDAS COM VENCEDOR: %d\n", vPartidas);
								printf("NUMERO DE EMPATES: %d\n", nEmpates);
								printf("VITORIAS JOGADOR 1: %d %% \n", eJogador1);
								printf("VITORIAS JOGADOR 2: %d %% \n", eJogador2);
								printf("\nDeseja jogar novamente? 1 - Sim 2 - Nao ");
								scanf("%d", &jogarNovamente);
										
							}while(jogarNovamente == 1);break;
											
						case 2: 
							do
							{
								system("cls");
								printf("Jogador I %d x %d CPU\n", pjogador1, pCPU);
								printf("\nJOGADOR 1:\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA ");
								scanf("%d", &jogador1);
								nPartidas++;
									
								srand(time(NULL));
								cpu = rand() % 4; //gera um numero aleatório//
								
								system("cls");
																								
								if(jogador1 == 1 && cpu == 3 || jogador1 == 2 && cpu == 1 || jogador1 == 3 && cpu == 2) //verifica se o jogador venceu//
								{
									printf("\n\nJOGADOR 1 VENCEU\n\n");
									pjogador1++;
									vPartidas++;
								}else
								if(jogador1 == cpu) //verifica se houve empate//
								{
									printf("\n\nEMPATOU\n\n");
									nEmpates++;
								}else 
								{	
									printf("\n\nCPU VENCEU\n\n");
									pCPU++;
									vPartidas++;
								}
								
								eJogador1  = pjogador1 * 100 / vPartidas;
								eCPU = pCPU * 100 / vPartidas;
											
								printf("\n - ESTATISTICAS - \n\n");
								printf("PARTIDAS JOGADAS: %d\n", nPartidas);
								printf("NUMERO DE EMPATES: %d\n", nEmpates);
								printf("PARTIDAS COM VENCEDOR: %d\n", vPartidas);
								printf("VITORIAS JOGADOR 1: %d %% \n", eJogador1);
								printf("VITORIAS CPU: %d %% \n", eCPU);
								printf("\nDeseja jogar novamente? 1 - Sim 2 - Nao ");
								scanf("%d", &jogarNovamente);
																
							}while(jogarNovamente == 1);
					}
			}else
			if(menu1 ==2)
			{
				system("cls");
				printf("\nREGRAS:\n\nNumero de jogadores: 2\n\nPosicoes basicas:\n1: Pedra\n2: Tesoura\n3: Papel\n\nQue forma vence o que:\n- Pedra ganha da tesoura (quebra a tesoura);\n- Tesoura ganha do papel (corta o papel);\n- Papel ganha da pedra (embrulha a pedra).\n\n");
				printf("Digite 1 para voltar ao menu anterior, 2 para sair: ");
				scanf("%d", &voltar);
				system("cls");
			}else
			if(menu1 > 3)
			{
				system("cls");
				printf("\n\nOpcao invalida! Digite 1 para voltar ao menu anterior, 2 para sair: ");
				scanf("%d", &voltar);
				system("cls");
			}else
			{
				
			}
	
		}while(voltar == 1);

}
