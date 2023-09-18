#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) 
{	
	setlocale(LC_ALL,""); // utiliza o arquivo de cabeçalho locale.h para implementar a localização, garante que caracteres como “ç” e acentuação sejam exibidos normalmente.
	
	int jogadorUm;	
	int jogadorDois;
	int jogadorCpu;
							
	int modoJogo;
	int menu;
	
	int contEmpateXcpu = 0;	
	int contEmpate = 0; 
							
	int totalPartidasXcpu; 
	int totalPartidasXjogador;
	
	float percentualVitoriaJogadorUm;
	float percentualVitoriaJogadorDois;
	
	float percentualVitoriaJogadorXcpu; 
	float percentualVitoriaCpu;
	
	float contVitoriaJogador = 0;
	float contVitoriaJogadorDois = 0; 
	float contVitoriaDerrota = 0; 
	
	float contVitoriaJogadorXcpu = 0;
	float contVitoriaCpu = 0;
	float contVitoriaDerrotaXcpu = 0;


	do // teste no fim para voltar ao inicio ou sair do programa.
	{	
		system("CLS"); 
		printf("----------------------------------------\n");	
		printf("----_-------_---------------------//\\---\n");
		printf("---(_)-----|-|-------------------|/-\\|--\n");
		printf("----_--___-|-|-_____-_-__--_-__---___---\n");
		printf("---|-|/-_-\\|-|/-/-_-\\-'_-\\|-'_-\\-/-_-\\--\n");
		printf("---|-|-(_)-|---<--__/-|-|-|-|_)-|-(_)-|-\n");
		printf("---|-|\\___/|_|\\_\\___|_|-|_|-.__/-\\___/--\n");
		printf("--_/-|--------------------|-|-----------\n");
		printf("-|__/---------------------|_|-----------\n");
		printf("----------------------------------------\n");
		printf("------- 1 - Jogador X Jogador ----------\n"); 
		printf("------- 2 - Jogador X Computador -------\n");
		printf("------- 3 - Estatísticas ---------------\n");
		printf("------- 4 - Sair -----------------------\n");
		printf("----------------------------------------\n");
		scanf("%i", &modoJogo); 
		
		while(modoJogo < 1 || modoJogo > 4) // verifica se a opção digitada é valida , se nao for, é pedido que o jogador digite novamente.
		{									
			printf("\tOpção inválida\n"); 
			printf("\tEscolha novamente\n");
			scanf("%i", &modoJogo); 
		}
								
		switch(modoJogo) // opções do menu, sem default pois a verificação está sendo feita acima.
		{
			case 1: // opção jogador x jogador 
					
				do // teste no fim para a repetição do case1 / sair do programa / voltar para o menu.
				{
					system("CLS"); 
					printf("\tJogador X Jogador\n\n"); 
					printf("Jogador 1\n\n");
					printf("1 - Pedra \n2 - Papel \n3 - Tesoura\n\n");
					printf("Qual é a sua jogada ?\n");
					scanf("%i", &jogadorUm);
					
					while(jogadorUm < 1 || jogadorUm > 3) // verifica se a opção digitada é valida , se nao for, é pedido que o jogador digite novamente.
					{									
						printf("Opção inválida	\n");
						printf("Escolha novamente\n");
						scanf("%i", &jogadorUm); 
					}
						
					system("CLS"); 
					
					printf("\tJogador X Jogador\n\n");
					printf("Jogador 2\n\n");
					printf("1 - Pedra \n2 - Papel \n3 - Tesoura\n\n");
					printf("Qual é a sua jogada ?\n");
					scanf("%i", &jogadorDois);
					
					while(jogadorDois < 1 || jogadorDois > 3) // verifica se a opção digitada é valida , se nao for, é pedido que o jogador digite novamente.
					{									
						printf("Opção inválida\n");
						printf("Escolha novamente\n");
						scanf("%i", &jogadorDois);
					}
					
					system("CLS");
					
					if(jogadorUm == 1)
					{						
						printf("\n(Jogador 1) - Pedra\n");
					}
					else
					{
						if(jogadorUm == 2)
						{
							printf("\n(Jogador 1) - Papel\n");
						}
						else
						{
							printf("\n(Jogador 1) - Tesoura\n");
						}
					}
						
					printf("\n\tX\n");		
						
					if(jogadorDois == 1)
					{
						printf("\n(Jogador 2) - Pedra\n");
					}
					else
					{
						if(jogadorDois == 2)
						{
							printf("\n(Jogador 2) - Papel\n");
						}
						else
						{
							printf("\n(Jogador 2) - Tesoura\n");
						}
					}
						
					if((jogadorUm == 1 && jogadorDois == 3) || (jogadorUm == 2 && jogadorDois == 1) || (jogadorUm == 3 && jogadorDois == 2)) // compara o resultados entre jogador um e dois e imprime na tela quem venceu ou se houve empate.
					{
						printf("\n\tVitória Jogador 1\n\n");
						contVitoriaJogador++; // quando jogador um vence é somado +1 ao seu contador de vitorias.
						contVitoriaDerrota++; // quando o resultado dos jogadores é diferente de empate então é somado +1 ao seu contador de vitorias e derrotas.
					}				
					else
					{
						if(jogadorUm == jogadorDois) 
						{
							printf("\n\tEmpate\n\n");
							contEmpate++; // quando jogador um e jogador dois empatam é somado +1 ao contador de empates.
						}
						else
						{
							printf("\n\tVitória Jogador 2\n\n");
							contVitoriaJogadorDois++; // quando jogador dois vence é somado +1 ao seu contador de vitorias.
							contVitoriaDerrota++; //quando o resultado dos jogadores é diferente de empate então é somado +1 ao seu contador de vitorias e derrotas.	
						}
					}
									
					printf("1 - Jogar Novamente\n2 - Voltar ao menu\n3 - Sair\n");
					scanf("%i", &menu);
					
					while(menu < 1 || menu > 3) // verifica se a opção digitada é valida , se nao for, é pedido que o jogador digite novamente.
					{
						printf("Opção inválida\n"); 	
						printf("Escolha novamente\n");	
						scanf("%i", &menu);					
					}	
				}
				while (menu != 3 && menu != 2); //	1(jogar novamente) - é diferente de 3 e diferente de 2 == ( V ) continua.
												//	2(menu) - é diferente de 3 e igual a 2 == ( F ), continua, menu é decrescido em 1, passa a ser 1, abandona, continua, encontra condição(menu != 2 && modoJogo != 4), 1(menu) é diferente de 2 e modoJogo é sempre != 4 == (V) continua.
				menu--;							//	3(sair) - é diferente de 2 e é igual a 3 == ( F ), continua, menu é decrescido	em 1, passa a ser 2, abandona, continua, encontra condição(menu != 2 && modoJogo != 4), 2(sair) é igual a 2 e modoJogo é sempre !=4 ==	(F)	fim.																																							
			break;																				
																	
			case 2:  // teste no fim para a repetição do case2 / sair do programa / voltar para o menu.
															
				do
				{	
					system("CLS");	
					printf("\tJogador X Computador\n\n");
					printf("Jogador 1\n\n");
					printf("1 - Pedra \n2 - Papel \n3 - Tesoura\n\n");
					printf("Qual é a sua jogada ?\n");
					scanf("%i", &jogadorUm);
					
					while(jogadorUm < 1 || jogadorUm > 3) // verifica se a opção digitada é valida , se nao for, é pedido que o jogador digite novamente.
					{
						printf("Opção inválida\n");
						printf("Escolha novamente\n");
						scanf("%i", &jogadorUm);
					}
					
					srand(time(NULL));
	    			jogadorCpu = rand() % 3; // gera um numero de 0 a 2 aleatorio.
					jogadorCpu += 1; // resultado sempre é acrescido em +1, 0 == 1, 1 == 2, 2 == 3.
					
					system("CLS");
					
					if(jogadorUm == 1) // faz um teste após jogadorUm e jogadorDois terem feito sua jogada , então é exibido na tela o jogador e a opção correspondente.
					{						
						printf("\n(Jogador 1) - Pedra\n");
					}
					else
					{
						if(jogadorUm == 2)
						{
							printf("\n(Jogador 1) - Papel\n");
						}
						else
						{
							printf("\n(Jogador 1) - Tesoura\n");
						}
					}
							
					printf("\n\tX\n"); 
							
					if(jogadorCpu == 1) // faz um teste após jogadorUm e jogadorDois terem feito sua jogada , então é exibido na tela o jogador e a opção correspondente.
					{
						printf("\n(Computador) - Pedra\n");
					}
					else
					{
						if(jogadorCpu == 2)
						{
							printf("\n(Computador) - Papel\n");
						}
						else
						{
							printf("\n(Computador) - Tesoura\n");
						}
					}
					
	    			if((jogadorUm == 1 && jogadorCpu == 3) || (jogadorUm == 2 && jogadorCpu == 1) || (jogadorUm == 3 && jogadorCpu == 2))
					{
						printf("\n\tVitória Jogador 1\n\n");
						contVitoriaJogadorXcpu++;
						contVitoriaDerrotaXcpu++; 
	    			}
					else
					{
						if(jogadorUm == jogadorCpu)
						{
							printf("\n\tEmpate\n\n");
							contEmpateXcpu++;	
						}
						else
						{
							printf("\n\tVitória Computador\n\n");
							contVitoriaCpu++;
							contVitoriaDerrotaXcpu++; 
						}
					}
					printf("1 - Jogar Novamente\n2 - Voltar ao menu\n3 - Sair\n");
					scanf("%i", &menu);		
					while(menu < 1 || menu > 3)
					{
						printf("Opção inválida\n");
						printf("Escolha novamente\n");
						scanf("%i", &menu);
					}
				}	
				while (menu != 3 && menu != 2); //	1(jogar novamente) - é diferente de 3 e diferente de 2 == ( V ) continua.
				menu--;							//	2(menu) - é diferente de 3 e igual a 2 == ( F ), continua, menu é decrescido em 1, passa a ser 1, abandona, continua, encontra condição(menu != 2 && modoJogo != 4), 1(menu) é diferente de 2 e modoJogo é sempre != 4 == (V) continua.
			break;								//	3(sair) - é diferente de 2 e é igual a 3 == ( F ), continua, menu é decrescido	em 1, passa a ser 2, abandona, continua, encontra condição(menu != 2 && modoJogo != 4), 2(sair) é igual a 2 e modoJogo é sempre !=4 ==	(F)	fim.					
			
			case 3: // menu Estatísticas 
				
				system("CLS");
				percentualVitoriaJogadorUm  = ((contVitoriaJogador / contVitoriaDerrota) * 100); // calcula percentual de vitoria do jogador 1 no modo " Jogador X Jogador "
				percentualVitoriaJogadorDois  = ((contVitoriaJogadorDois / contVitoriaDerrota) * 100); // calcula o percentual de vitoria do jogador 2 no modo " Jogador X Jogador "
				percentualVitoriaJogadorXcpu = ((contVitoriaJogadorXcpu / contVitoriaDerrotaXcpu) * 100); // calcula o percentual de vitoria do Jogador 1 no modo " Jogador X Computador "
				percentualVitoriaCpu = ((contVitoriaCpu / contVitoriaDerrotaXcpu) * 100); // calcula o percentual de vitoria do Computador no modo " Jogador X Computador "
				
				totalPartidasXjogador = contEmpate + contVitoriaDerrota; // calcula o total de partidas ( empates, vitorias, derrotas ) do modo " Jogador X Jogador "
				totalPartidasXcpu = contEmpateXcpu + contVitoriaDerrotaXcpu; // calcula o total de partidas ( empates, vitorias, derrotas) do modo " Jogador X Computador "
	
				if(contVitoriaJogador >= 1 || contVitoriaJogadorDois >= 1 && contEmpate >= 1) // faz testes para a exxibição das Estatísticas de " Jogador X Jogador " , exibe somento se houver informação para exibir.
				{
					printf("\tJogador X Jogador\n\n");	
					printf("Percentual Vitórias Jogador 1 :%.0f%%\n", percentualVitoriaJogadorUm);
					printf("Percentual Vitórias Jogador 2 :%.0f%%\n", percentualVitoriaJogadorDois);
					printf("Total de partidas :%i\n", totalPartidasXjogador);
					printf("Total de empate: %i\n\n", contEmpate);	
				}
				else
				{
					if(contVitoriaJogador >= 1 || contVitoriaJogadorDois >= 1) 
					{
						printf("\tJogador X Jogador\n\n");	
						printf("Percentual Vitórias Jogador 1 :%.0f%%\n", percentualVitoriaJogadorUm);
						printf("Percentual Vitórias Jogador 2 :%.0f%%\n", percentualVitoriaJogadorDois);
						printf("Total de partidas :%i\n\n", totalPartidasXjogador);	
					}
					else
					{
						if(contEmpate >= 1)
						{
							printf("\tJogador X Jogador\n\n");	
							printf("Total de partidas :%i\n", totalPartidasXjogador);
							printf("Total de empate :%i\n\n", contEmpate);	
						}
						else
						{
							printf("\tJogador X Jogador\n\n");
							printf("Não há Estatísticas para exibir\n\n");	
						}
					}
				}

				if(contVitoriaJogadorXcpu >= 1 || contVitoriaCpu >= 1 && contEmpateXcpu >= 1) // faz testes para exibição das Estatísticas de " Jogador X Computador " , exibe somente se houver informação para exibir.
				{
					printf("\tJogador X Computador\n\n");
					printf("Percentual Vitórias Jogador :%.0f%%\n", percentualVitoriaJogadorXcpu);
					printf("Percentual Vitórias Computador :%.0f%%\n", percentualVitoriaCpu);
					printf("Total de partidas :%i\n", totalPartidasXcpu);
					printf("Total de empate :%i\n\n", contEmpateXcpu);	
				}
				else
				{
					if(contVitoriaJogadorXcpu >= 1 || contVitoriaCpu >= 1)
					{
						printf("\tJogador X Computador\n\n");
						printf("Percentual Vitórias Jogador :%.0f%%\n", percentualVitoriaJogadorXcpu);
						printf("Percentual Vitórias Computador :%.0f%%\n", percentualVitoriaCpu);
						printf("Total de partidas :%i\n\n", totalPartidasXcpu);	
					}
					else
					{
						if(contEmpateXcpu >= 1)
						{
							printf("\tJogador X Computador\n\n");
							printf("Total de partidas :%i\n", totalPartidasXcpu);
							printf("Total de empates :%i\n", contEmpateXcpu);
						}
						else
						{
							printf("\tJogador X Computador\n\n");
							printf("Não há Estatísticas para exibir\n\n");
						}
					}		
				}
				
				printf("\n1 - Voltar ao Menu\n2 - Sair\n\n");
				scanf("%i", &menu); 
				
				while(menu < 1 || menu > 2) // verifica se a opção digitada é valida , se nao for, é pedido que o jogador digite novamente.
				{
					printf("Opção inválida\n");
					printf("Escolha novamente\n");
					scanf("%i", &menu);	
				}	
			break;		
		}													
	}
	while(menu != 2 && modoJogo != 4);	
	return 0;							
}											

