#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	int modoJogo = 0;
	int jogadaUm = 0;
	int jogadaDois = 0;
	int vencedor = 0;
	int vitoriasJogadorUm = 0;
	int vitoriasJogadorDois = 0;
	
	srand(time(NULL));
	
	do {
		//Menu de jogo
		do {
			printf("Escolha o modo de jogo\n1 - Singleplayer\n2 - Multiplayer\n3 - Sair\n");
			scanf("%d", &modoJogo);
			if(modoJogo == 1 || modoJogo == 2 || modoJogo == 3)
				break;
			printf("Opção inválida\n");
		} while(1);
		
		if(modoJogo != 3) {
			do { //Jogada um
				printf("\nJogador 1, escolha sua jogada\n1 - Pedra\n2 - Papel\n3 - Tesoura\n");
				scanf("%d", &jogadaUm);
				if(jogadaUm == 1 || jogadaUm == 2 || jogadaUm == 3)
					break;
				printf("Opção inválida\n");
			} while(1);
			
			if(modoJogo == 2) { //Jogada dois
				do { //Humano
					printf("\nJogador 2, escolha sua jogada\n1 - Pedra\n2 - Papel\n3 - Tesoura\n");
					scanf("%d", &jogadaDois);
					if(jogadaDois == 1 || jogadaDois == 2 || jogadaDois == 3)
						break;
					printf("Opção inválida\n");
				} while(1);
			} else { //CPU
				jogadaDois = rand() % 3 + 1;
				printf("\nO computador escolheu %d\n", jogadaDois);
			}
			
			//Decide vencedor
			if(jogadaUm == jogadaDois)
				vencedor = 3;
			else 
				switch(jogadaUm) {
					case 1:
						if(jogadaDois == 3)
							vencedor = 1;
						else
							vencedor = 2;
						break;
					case 2:
						if(jogadaDois == 1)
							vencedor = 1;
						else
							vencedor = 2;
						break;
					case 3:
						if(jogadaDois == 2)
							vencedor = 1;
						else
							vencedor = 2;
						break;
				}
			
			//Mostra vencedor
			if(vencedor != 3) {
				printf("\nO vencedor é o jogador %d\n", vencedor);
				if(vencedor == 1)
					vitoriasJogadorUm++;
				else
					vitoriasJogadorDois++;
			} else {
				printf("\nO jogo empatou\n");
			}
			
			//Reset vencedor
			vencedor = 0;
			
			//Mostra placar
			printf("\nPlacar\nJogador um: %d\nJogador dois: %d\n\n", vitoriasJogadorUm, vitoriasJogadorDois);
		}
	} while(modoJogo != 3);
	
	
	return 0;
}
