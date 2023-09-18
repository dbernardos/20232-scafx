#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	float pontosH1, pontosH2, pontosMaquina, pontosEmpate;
	int h1, h2, modoDeJogo, maquina, escolha, partidas;
	float statisticasH1, statisticasM, statisticasH2, statisticasE;
	
	
	pontosMaquina = 0;
	pontosH1 = 0;
	pontosH2 = 0;
	pontosEmpate = 0;
	partidas = 0;
	
	printf ("         BEM VINDO AO JOKENPO EM C !! \n\n");
	printf (" Digite 1 para modo de jogo Humano x Maquina \n Digite 2 para modo de jogo Humano x Humano \n ");
	scanf ("%d", &modoDeJogo);
	if (modoDeJogo > 0 && modoDeJogo < 2){
		
		while (modoDeJogo == 1){
		partidas ++;
		
		
		printf (" \n Modo de jogo Humano x maquina selecionado! \n\n");
		printf("\n Humano, escolha sua jogada: \n\n Digite 1 para Pedra \n Digite 2 para Papel \n Digite 3 para Tesoura \n\n ");
		scanf ("%d", &h1);
				
	switch(h1)
		{
			case 1 :
				printf ("\nVoce jogou Pedra. \n\n");
				break;
			case 2 :
				printf ("\nVoce jogou Papel. \n\n");
				break;
			case 3 :
				printf ("\nVoce jogou Tesoura. \n\n");
				break;
			default:
				printf("\nNao existe essa jogada. \n\n");
				exit(0);
		}
	
	
	
	srand (time(NULL));
	maquina = rand() %3 + 1 ;
	
	
	switch (maquina)
		{
			case 1 :
				printf ("Maquina jogou Pedra. \n\n");
				break;
			case 2 :
				printf("Maquina jogou Papel. \n\n");
				break;
			case 3 :
				printf("Maquina jogou Tesoura. \n\n");
				break;
		}	
		
		
	if ((h1 == 1 && maquina == 3) || (h1 == 2 && maquina == 1) || (h1 == 3 && maquina == 2))
	{
		printf("Voce VENCEU ! \n\n Digite 1 para jogar novamente: \n Digite 2 para ter acesso as estatiscas e sair: \n Digite 3 para sair: ");
		pontosH1 ++;
		scanf ("%d", &escolha);
		
		
		switch(escolha)
		{
			case 1 :
				printf ("\n Computando pontos !\n\n");
				break;
			case 2 :
				statisticasH1 = (pontosH1/partidas)*100;
				statisticasM = (pontosMaquina/partidas)*100;
				statisticasE = (pontosEmpate/partidas)*100;
				printf ("\nNumero de partidas jogadas: %d \n", partidas);
				printf ("Porcentagem de vitorias humano: %f \n", statisticasH1);
				printf ("Porcentagem de vitorias Maquina: %f \n", statisticasM);
				printf ("Porcentagem de empates: %f \n", statisticasE);
				exit(0);
			case 3 :
				exit (0);
			default:
				printf("\nOpcao inexistente. \n\n");
				exit(0);
		}

	}else{
		if (h1 == maquina)
		{
			printf ("Empate! \n\n Digite 1 para jogar novamente: \n Digite 2 para ter acesso as estatiscas e sair: \n Digite 3 para sair: \n");
			pontosEmpate ++;	
			scanf ("%d", &escolha);
		
		
		switch(escolha)
		{
			case 1 :
				printf ("\n Computando pontos !\n\n");
				break;
			case 2 :
				statisticasH1 = (pontosH1/partidas)*100;
				statisticasM = (pontosMaquina/partidas)*100;
				statisticasE = (pontosEmpate/partidas)*100;
				printf ("\nNumero de partidas jogadas: %d \n", partidas);
				printf ("Porcentagem de vitorias humano: %f \n", statisticasH1);
				printf ("Porcentagem de vitorias Maquina: %f \n", statisticasM);
				printf ("Porcentagem de empates: %f \n", statisticasE);
				exit (0);
			case 3 :
				exit (0);
			default:
				printf("\nOpcao inexistente. \n\n");
				exit(0);
		}	
	}else
	{
		printf("Maquina VENCEU! \n\n Digite 1 para jogar novamente: \n Digite 2 para ter acesso as estatiscas e sair: \n Digite 3 para sair: \n");
		pontosMaquina ++;
		scanf ("%d", &escolha);
		
		
		switch(escolha)
		{
			case 1 :
				printf ("\n Computando pontos !\n\n");
				break;
			case 2 :
				statisticasH1 = (pontosH1/partidas)*100;
				statisticasM = (pontosMaquina/partidas)*100;
				statisticasE = (pontosEmpate/partidas)*100;
				printf ("\nNumero de partidas jogadas: %d \n", partidas);
				printf ("Porcentagem de vitorias humano: %f \n", statisticasH1);
				printf ("Porcentagem de vitorias Maquina: %f \n", statisticasM);
				printf ("Porcentagem de empates: %f \n", statisticasE);
				exit(0);
			case 3 :
				exit (0);
			default:
				printf("\nOpcao inexistente. \n\n");
				exit(0);
		}
	}}}}else{
		if (modoDeJogo == 2)
		{
		while (modoDeJogo == 2){
		partidas ++;
		
		
		printf(" \n Modo de jogo Humano x Humano selecionado ! \n\n ");
		printf("\n Humano 1, escolha sua jogada: \n\n Digite 1 para Pedra \n Digite 2 para Papel \n Digite 3 para Tesoura \n");
			scanf ("%d", &h1);
		if ((h1 != 1 && h1 != 2 && h1 !=3))
		{
			printf("Nao existe essa jogada");
			exit(0);
		}
		printf("\n Humano 2, escolha sua jogada: \n\n Digite 1 para Pedra \n Digite 2 para Papel \n Digite 3 para Tesoura \n");
			scanf ("%d", &h2);
		if ((h2 != 1 && h2 != 2 && h2 !=3))
		{
			printf("Nao existe essa jogada");
			exit(0);
		}
		
		if ((h1 == 1 && h2 == 3) || (h1 == 2 && h2 == 1) || (h1 == 3 && h2 == 2))
		{
			printf("\n Humano 1 VENCEU ! \n\n Digite 1 para jogar novamente: \n Digite 2 para ter acesso as estatiscas e sair: \n Digite 3 para sair: \n");
			pontosH1 ++;
			scanf ("%d", &escolha);
		
		
		switch(escolha)
		{
			case 1 :
				printf ("Computando pontos! \n\n");
				break;
			case 2 :
				statisticasH1 = pontosH1/partidas*100;
				statisticasH2 = pontosH2/partidas*100;
				statisticasE = pontosEmpate/partidas*100;
				printf ("\nNumero de partidas jogadas: %d \n", partidas);
				printf ("Porcentagem de vitorias Humano 1: %f \n", statisticasH1);
				printf ("Porcentagem de vitorias Humano 2: %f \n", statisticasH2);
				printf ("Porcentagem de empates: %f \n", statisticasE);
				exit(0);
			case 3 :
				exit (0);
			default:
				printf("\nOpcao inexistente. \n\n");
				exit(0);
		}
			
		}else {
			if (h1 == h2)
			{
				printf ("\n Empate ! \n\n Digite 1 para jogar novamente: \n Digite 2 para ter acesso as estatiscas e sair: \n Digite 3 para sair: ");
				pontosEmpate++;
				scanf ("%d", &escolha);
		
		
		switch(escolha)
		{
			case 1 :
				printf ("Computando pontos! \n\n");
				break;
			case 2 :
				statisticasH1 = pontosH1/partidas*100;
				statisticasH2 = pontosH2/partidas*100;
				statisticasE = pontosEmpate/partidas*100;
				printf ("\nNumero de partidas jogadas: %d \n", partidas);
				printf ("Porcentagem de vitorias Humano 1: %f \n", statisticasH1);
				printf ("Porcentagem de vitorias Humano 2: %f \n", statisticasH2);
				printf ("Porcentagem de empates: %f \n", statisticasE);
				exit(0);
			case 3 :
				exit (0);
			default:
				printf("\nOpcao inexistente. \n\n");
				exit(0);
		}
			}else{
			if ((h1 == 3 && h2 == 1) || (h1 == 1 && h2 == 2) || (h1 == 2 && h2 == 3))
			{
				printf("\n Humano 2 Venceu ! \n\n Digite 1 para jogar novamente: \n Digite 2 para ter acesso as estatiscas e sair: \n Digite 3 para sair: ");
				pontosH2 ++;
				scanf ("%d", &escolha);
		
		
		switch(escolha)
		{
			case 1 :
				printf ("Computando pontos! \n\n");
				break;
			case 2 :
				statisticasH1 = pontosH1/partidas*100;
				statisticasH2 = pontosH2/partidas*100;
				statisticasE = pontosEmpate/partidas*100;
				printf ("\nNumero de partidas jogadas: %d \n", partidas);
				printf ("Porcentagem de vitorias Humano 1: %f \n", statisticasH1);
				printf ("Porcentagem de vitorias Humano 2: %f \n", statisticasH2);
				printf ("Porcentagem de empates: %f \n", statisticasE);
				exit(0);
			case 3 :
				exit (0);
			default:
				printf("\nOpcao inexistente. \n\n");
				exit(0);
		}
			}else{
		printf (" Não existe essa jogada !");
		exit(0);
	}
		}
		} 
		}
		}else{
		printf (" Nao existe esse modo de Jogo !");
		
	}}
	return 0;
}
