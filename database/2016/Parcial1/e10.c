#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int metodoJogo, jogadaJogador, jogadaJogador2, jogadaComputador, pontosJogador, pontosJogador2, pontosComputador, pontosEmpate, numeroJogos;
	
	pontosJogador = 0;
	pontosJogador2 = 0;
	pontosComputador = 0;
	pontosEmpate = 0;
	numeroJogos = 0;
	metodoJogo = 0;
	
	/*Iniciando o jogo e escolhendo o metodo de jogo (Computador ou Pessoa)*/
	printf("___________Jo-Ken-Po___________ \n\nPara comecar a jogar escolha o metodo de jogo:");	
	while (metodoJogo != 1 && metodoJogo !=2){
	    printf("\n\n- Pressione 1 para jogar contra o computador");
	    printf("\n- Pressione 2 para jogar contra outra pessoa\n");
	    scanf("%d", &metodoJogo);
	    if (metodoJogo != 1 && metodoJogo !=2){
		    printf("O comando digitado nao corresponde a nenhum metodo de jogo, por favor tente novamente:");
	    }
    }
	/*Jogador x Computador*/
	while (jogadaJogador != 3){
	
	    /*Início jogar contra o computador*/
		if (metodoJogo == 1){
		    printf("\n_____Voce esta jogando contra o computador_____\n\n");
		    printf("Escolha qual sera a sua jogada:\n");
		
		    printf("- Pressione 0 para jogar Pedra\n");
		    printf("- Pressione 1 para jogar Papel\n");
		    printf("- Pressione 2 para jogar Tesoura\n");
		    printf("- Pressione 3 para parar de jogar e visualizar as estatisticas de jogo\n");
		    scanf("%d", &jogadaJogador);
		
		    /*Jogada do Computador*/
		    srand(time(NULL));
		    jogadaComputador = rand() % 3;
		
		    switch (jogadaComputador){
			    case 0: 
			    printf("\nO computador jogou Pedra");
			    break;
			
			    case 1:
			    printf("\nO computador jogou Papel");
			    break;
			
			    case 2: 
			    printf("\nO computador jogou Tesoura");
			    break;
		    }  
		
		    /*Resultado da Partida*/
		    if ((jogadaComputador == 0 && jogadaJogador == 1) || (jogadaComputador == 1 && jogadaJogador == 2) || (jogadaComputador == 2 && jogadaJogador == 0))
		    {			
			    printf("\nParabens voce ganhou!\n\n");
			    pontosJogador++;
			    numeroJogos++;				
		    }
		
		    if (jogadaComputador == jogadaJogador)
		    {		
			    printf("\nHouve um empate\n\n");
			    pontosEmpate++;
			    numeroJogos++;
		    }
		
		    if ((jogadaJogador == 0 && jogadaComputador == 1) || (jogadaJogador == 1 && jogadaComputador == 2) || (jogadaJogador == 2 && jogadaComputador == 0))
		    {
			    printf("\nO computador venceu!\n\n");
			    pontosComputador++;
			    numeroJogos++;
		    }
		
		    if (jogadaJogador > 3 || jogadaJogador < 0){
			    printf("\n\n-------O comando digitado eh invalido, por favor tente novamente-------\n");
		    }  
		
	    } /*Fim jogar contra o computador*/
	    
	    /*Início jogar contra outra pessoa*/
		if (metodoJogo == 2){
			printf("\n_____Voce esta jogando contra outra pessoa_____\n\n");
		    printf("Jogador 1, por favor escolha sua jogada:\n");
		
		    printf("- Pressione 0 para jogar Pedra\n");
		    printf("- Pressione 1 para jogar Papel\n");
		    printf("- Pressione 2 para jogar Tesoura\n");
		    printf("- Pressione 3 para parar de jogar e visualizar as estatisticas de jogo\n");
		    scanf("%d", &jogadaJogador);
		    if (jogadaJogador == 3){
		    	printf("\nPara serem impressar as estatisticas do jogo sera necessario que o Jogador 2 tambem pressione '3' em sua jogada\n\n");
			}
		    
		    printf("____Agora eh a vez do jogador 2 escolher sua jogada____\n");
		    printf("- Pressione 0 para jogar Pedra\n");
		    printf("- Pressione 1 para jogar Papel\n");
		    printf("- Pressione 2 para jogar Tesoura\n");
		    printf("- Pressione 3 para parar de jogar e visualizar as estatisticas de jogo\n");
		    scanf("%d", &jogadaJogador2);
		
		    
		       /*Resultado da Partida*/
		       if ((jogadaJogador2 == 0 && jogadaJogador == 1) || (jogadaJogador2 == 1 && jogadaJogador == 2) || (jogadaJogador2 == 2 && jogadaJogador == 0))
		       {			
			       printf("\nO jogador 1 ganhou!\n\n");
			       pontosJogador++;
			       numeroJogos++;				
		       }
		
		       if (jogadaJogador2 == jogadaJogador)
		       {		
			       printf("\nHouve um empate\n\n");
			       pontosEmpate++;
			       numeroJogos++;
		       }
		
		       if ((jogadaJogador == 0 && jogadaJogador2 == 1) || (jogadaJogador == 1 && jogadaJogador2 == 2) || (jogadaJogador == 2 && jogadaJogador2 == 0))
		       {
			       printf("\nO jogador 2 ganhou!\n\n");
			       pontosJogador2++;
			       numeroJogos++;
		       }
		
		       if (jogadaJogador > 3 || jogadaJogador < 0 || jogadaJogador2 > 3 || jogadaJogador2 < 0 ){
			       printf("\n\n-------O comando digitado por um dos jogadores eh invalido, esta rodada nao sera computada-------\n");
		       }    
		}/*Fim jogar contra outra pessoa*/
	    
	}
	
	
		/*Estatísticas do Jogo para jogo contra outra Pessoa*/
	if (metodoJogo == 2){
	printf("\n\n_____Estatisticas do Jogo_____\n");
	printf("- Foram jogadas %d partidas.\n", numeroJogos);
	pontosJogador = (pontosJogador * 100) / numeroJogos;
	printf("- O jogador 1 ganhou %d%% das partidas.\n", pontosJogador);
	pontosJogador2 = (pontosJogador2 * 100) / numeroJogos;
	printf("- O jogador 2 ganhou %d%% das partidas.\n", pontosJogador2);
	pontosEmpate = (pontosEmpate * 100) / numeroJogos;
	printf("- %d%% das partidas resultaram em empate.\n", pontosEmpate);	
	}
	
	if (metodoJogo == 1){
	    /*Estatísticas do Jogo para jogo contra o Computador*/
	printf("\n\n_____Estatisticas do Jogo_____\n");
	printf("- Foram jogadas %d partidas.\n", numeroJogos);
	pontosJogador = (pontosJogador * 100) / numeroJogos;
	printf("- Voce ganhou %d%% das partidas.\n", pontosJogador);
	pontosComputador = (pontosComputador * 100) / numeroJogos;
	printf("- Voce perdeu %d%% das partidas.\n", pontosComputador);
	pontosEmpate = (pontosEmpate * 100) / numeroJogos;
	printf("- %d%% das partidas resultaram em empate.\n", pontosEmpate);
    }
	
	
	return 0;
}
