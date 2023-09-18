#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int pedra;
	int papel;
	int tesoura;
	
	int escolha1;
	int escolha2;
// VARIAVEL ESCOLHA1 E 2 SÃO AS ESCOLHAS DOS JOGADORES OU COMPUTADOR.
	
	int jogada;
// VARIAVEL PARA CONDIÇÃO DO WHILE, ENQUANTO FOR 1 A CONDIÇÃO SERÁ VERDADEIRA.
	
	int escolha1Ganhou;
	int escolha2Ganhou;
	int empate;
	float valorTotal;
// VARIAVEIS DE CONTAGEM PARA OS CALCULOS POSTERIORES.
	
	float escolha1Porcento;
	float escolha2Porcento;
	float empatePorcento;
// VARIAVEIS PARA CALCULO DE PORCENTAGEM.

	int desafiante;
// VARIAVEL PARA ESCOLHER QUAL DESAFIANTE SERA.
	
	pedra = 1;
	papel = 2;
	tesoura = 3;
	
	escolha1 = 0;
	escolha2 = 0;
// ESCOLHAS1 E 2 IGUAIS A ZERO PARA INICIAR A CONTAGEM.
	
	valorTotal = 100;
// PARA QUE A CONTA DEPORCENTAGEM SEJA DE 100%.
	
	escolha1Ganhou = 0;
	escolha2Ganhou = 0;
	empate = 0;
// CONTADORES INICIANDO EM 0.
	
	jogada = 1;
//
	
	srand(time(NULL));

	
	
	printf("Seja bem vindo ao Jokempo.\n");
	do{
		printf("\nSe deseja jogar contra o computador, digite 1.\nSe deseja jogar contra outra pessoa, digite 2.\n");
		printf("Creditos digite 3.\nSe deseja sair digite 4.\n");
		printf("Sua escolha: ");
		scanf("%d", &desafiante);
	}while(desafiante < 1 || desafiante > 4);
// CONDIÇÃO PARA O MENU.
	
	switch (desafiante)
	{
// CASO 1 JOGA CONTRA O COMPUTADOR.
		case 1:
			while(jogada == 1)
			{	
				while(escolha1 < 1 || escolha1 > 3){
					printf("\nEscolha\n1 para pedra\n2 para papel \n3 para tesoura\n");
					scanf("%d", &escolha1);
				}
				switch(escolha1)
				{
					case 1: escolha1 = pedra; 
						printf("\nVoce escolheu Pedra\n");
					break;
					case 2: escolha1 = papel; 
						printf("\nVoce escolheu Papel\n");
					break;
					case 3: escolha1 = tesoura;
						printf("\nVoce escolheu Tesoura\n");
					break;
				}
				escolha2 = rand() % 3 + 1;
				switch(escolha2)
				{
					case 1: escolha2 = pedra; 
						printf("O computador escolheu Pedra\n");
					break;
					case 2: escolha2 = papel; 
						printf("O computador escolheu Papel\n");
					break;
					case 3: escolha2 = tesoura; 
						printf("O computador escolheu Tesoura\n");
					break;
				}
				if(escolha1 == pedra && escolha2 == papel || escolha1 == papel && escolha2 == tesoura || escolha1 == tesoura && escolha2 == pedra)
				{
					printf("Voce perdeu\n");
					escolha2Ganhou++;
				}else	
				{	
					if(escolha1 == papel && escolha2 == papel || escolha1 == pedra && escolha2 == pedra || escolha1 == tesoura && escolha2 == tesoura)
					{
						printf("Empatou\n");
						empate++;
					}else
					{
						printf("Voce Ganhou\n");
						escolha1Ganhou++;
					}
				}
				escolha1 = 0;
				escolha2 = 0;
				printf("Quer jogar de novo?\ndigite 1 para sim e 2 para nao.\n");
				printf("Sua escolha: ");
				scanf("%d", &jogada);
				while(jogada < 1 || jogada > 2){
					printf("Esse numero nao e valido.\n");
					printf("Digite 1 para jogar de novo e 2 para encerrar: ");
					scanf("%d", &jogada);
					
				}
				if(jogada == 2)
				{
					printf("\nJogo encerrado\n");
					printf("Voce ganhou %d vezes\nO computador ganhou %d vezes\nVoces empataram %d vezes\n", escolha1Ganhou, escolha2Ganhou, empate);
					valorTotal = escolha1Ganhou + escolha2Ganhou + empate;
					escolha1Porcento = (100*escolha1Ganhou)/valorTotal;
					escolha2Porcento = (100*escolha2Ganhou)/valorTotal;
					empatePorcento = (100*empate)/valorTotal;
					printf("\nForam jogados %.1f vezes\n", valorTotal);
					printf("Jogador Ganhou %.2f porcento das vezes\n", escolha1Porcento);
					printf("Computador Ganhou %.2f porcento das vezes\n", escolha2Porcento);
					printf("Voces empataram %.2f porcento das vezes\n", empatePorcento);
					
				}
			}
			break;
		case 2:
			while(jogada == 1)
			{	
				while(escolha1 < 1 || escolha1 > 3){
					printf("\nJogador 1 \nEscolha\n1 para pedra\n2 para papel \n3 para tesoura\n");
					scanf("%d", &escolha1);
				}
				
				while(escolha2 < 1 || escolha2 > 3){
					printf("\nJogador 2 \nEscolha\n1 para pedra\n2 para papel \n3 para tesoura\n");
					scanf("%d", &escolha2);
				}
				
				switch(escolha1)
				{
					case 1: escolha1 = pedra; 
						printf("Jogado 1 escolheu Pedra\n");
					break;
					case 2: escolha1 = papel; 
						printf("jogador 1 escolheu Papel\n");
					break;
					case 3: escolha1 = tesoura;
						printf("jogador 1 escolheu Tesoura\n");
					break;
				}
				switch(escolha2)
				{
					case 1: escolha2 = pedra; 
						printf("Jogador 2 escolheu Pedra\n");
					break;
					case 2: escolha2 = papel; 
						printf("Jogador 2 escolheu Papel\n");
					break;
					case 3: escolha2 = tesoura; 
						printf("Jogador 2 escolheu Tesoura\n");
					break;
				}
				if(escolha1 == pedra && escolha2 == papel || escolha1 == papel && escolha2 == tesoura || escolha1 == tesoura && escolha2 == pedra)
				{
					printf("Jogador 1 perdeu\n");
					printf("Jogador 2 ganhou\n");
					escolha2Ganhou++;
				}else	
				{	
					if(escolha1 == papel && escolha2 == papel || escolha1 == pedra && escolha2 == pedra || escolha1 == tesoura && escolha2 == tesoura)
					{
						printf("Empatou\n");
						empate++;
					}else
					{
						printf("Jogador 1 ganhou\n");
						printf("Jogador 2 perdeu\n");
						escolha1Ganhou++;
					}
				}
				escolha1 = 0;
				escolha2 = 0;
	
				printf("Quer jogar de novo?\ndigite 1 para sim e 2 para nao.\n");
				printf("Sua escolha: ");
				scanf("%d", &jogada);
				while(jogada < 1 || jogada > 2)
				{
					printf("Esse numero nao e valido.\n");
					printf("Digite 1 para jogar de novo e 2 para encerrar: ");
					scanf("%d", &jogada);
				}
				if(jogada == 2)
				{
					printf("\nJogo encerrado\n");
					printf("Jogador 1 ganhou %d vezes\nJogador 2 ganhou %d vezes\nVoces empataram %d vezes\n", escolha1Ganhou, escolha2Ganhou, empate);
					valorTotal = escolha1Ganhou + escolha2Ganhou + empate;
					escolha1Porcento = (100*escolha1Ganhou)/valorTotal;
					escolha2Porcento = (100*escolha2Ganhou)/valorTotal;
					empatePorcento = (100*empate)/valorTotal;
					printf("Foram jogados %.1f vezes\n", valorTotal);
					printf("Jogador 1 Ganhou %.2f porcento das vezes\n", escolha1Porcento);
					printf("Jogador 2 Ganhou %.2f porcento das vezes\n", escolha2Porcento);
					printf("Voces empataram %.2f porcento das vezes\n", empatePorcento);
					
				}
			}
			
			break;
		case 3:
			printf("\nEsse jogo foi elaborado para programacao 1 com o intuito de avaliar nossos conhecimentos absorvidos ate dia 24/04/2016\n");
			printf("Professor: Dr. Emerson Cabrera Paraiso\n");
			printf("Aluno: Alan Geovani Mazeto\n");
			printf("Linguagem: C\n");
			break;
		case 4:
			printf("Jogo encerrado.");
			break;
	}
	
	
	
	return 0;
}
