
#include <stdio.h>
#include <stdlib.h>



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int jogadaHumano;//jogador escolher a forma de jogo
	int jogadaHumano2;
	int jogadaPC;
	int comoJogar;// pc ou multiplayer
	int empate;
	int derrota;
	int vitoria;
	int jogadasTotal;
	int jogarRealmente;
	float porcentagemVitoria;
	float porcentagemDerrota;
	empate = 0;
	derrota = 0;
	vitoria = 0;
	jogadasTotal = 0;
	porcentagemVitoria = 0;
	do{
		printf("Escolha uma maneira de jogar:\n--------------\n1 para multiplayer\n2 contra bot.\n\n");
		scanf("%d", &comoJogar);
		switch(comoJogar){
			case 1:
				printf("\nVoce escolheu jogar multiplayer!\n\n");
				do{
					printf("\nPLAYER UM\n--------\n1 para papel\n2 para tesoura\n3 para pedra\n4 para sair\n\n");
					scanf("%d", &jogadaHumano);
					if(jogadaHumano == 4){
						printf("\nJogo encerrado pelo player um\n\n");
					}
					else if(jogadaHumano > 4 || jogadaHumano < 1){
						printf("\nPor favor, escolha um valor adequado para jogar!!\n");
					}
					else{
						do{
							printf("\nPLAYER DOIS\n--------\n1 para papel\n2 para tesoura\n3 para pedra\n\n");
				  			scanf("%d", &jogadaHumano2);
			  				if(jogadaHumano2 > 3 ){
			  					printf("\nPor favor, escolha um valor adequado para jogar!!\n");
							}
						}while(jogadaHumano2 > 3 || jogadaHumano2 < 1);
						switch(jogadaHumano){
                            case 1:
                                printf("\nPapel x");
                                break;
                            case 2:
                                printf("\nTesoura x");
                                break;
                            case 3:
                                printf("\nPedra x");
						}
						switch(jogadaHumano2){
                            case 1:
                                printf(" Papel \n");
                                break;
                            case 2:
                                printf(" Tesoura \n");
                                break;
                            case 3:
                                printf(" Pedra \n");
                                break;
						}
                        if (jogadaHumano2 == jogadaHumano){
                            printf("\nVoces empataram!!\n\n");
                            empate ++;
                            jogadasTotal ++;
                        }
                        else if((jogadaHumano == 1 && jogadaHumano2 == 2) || (jogadaHumano == 2 && jogadaHumano2 == 3) || (jogadaHumano == 3 && jogadaHumano2 == 1)){
                            printf("\nPlayer dois ganhou essa rodada!!\n\n");
                            derrota ++;
                            jogadasTotal ++;
                            porcentagemDerrota ++;
                        }
                        else if((jogadaHumano == 2 && jogadaHumano2 == 1) || (jogadaHumano == 3 && jogadaHumano2 == 2) || (jogadaHumano == 1 && jogadaHumano2 == 3)){
                            printf("\nPlayer um ganhou essa rodada!!\n\n");
                            vitoria ++;
                            jogadasTotal ++;
                            porcentagemVitoria ++;
                            }
                        }

				}while(jogadaHumano != 4);
				if(jogadasTotal > 0){
					porcentagemDerrota = (porcentagemDerrota / jogadasTotal) * 100;
					porcentagemVitoria = (porcentagemVitoria / jogadasTotal) * 100;
					printf("Placar final:\n--------\nvitorias player um: %d\nvitorias player dois: %d\nempates: %d\ntotal de jogos: %d", vitoria, derrota, empate, jogadasTotal);
					printf("\nPoncentagem de vitoria do player 1 =  %f", porcentagemVitoria);
					printf("\nPoncentagem de vitoria do player 2 =  %f", porcentagemDerrota);
					if (derrota > vitoria){
						printf("\nAND THE WINNER IS......... ");
						printf("PLAYER 2!!!");
					}
					else if (derrota < vitoria){
						printf("\nAND THE WINNER IS......... ");
						printf("PLAYER 1!!!");
					}
					else{
						printf("\nDEU EMPATE!!!");
					}
				}
				else{
					printf("\nVoce nao jogou nenhuma vez :(");
				}

		break;
		case 2:
			printf("\nVoce escolheu jogar contra bot!\n--------\n\n");
				do{
					printf("1 para papel\n2 para tesoura\n3 para pedra\n4 para sair\n\n");
					scanf("%d", &jogadaHumano);
					if(jogadaHumano == 4){
						
					}
					else if(jogadaHumano > 4 || jogadaHumano < 1){
						printf("\nPor favor, escolha um valor adequado para jogar!!\n\n");
					}
					else{
						srand(time(NULL));// deve aparecer antes de ser possível gerar números aleatórios
			  			jogadaPC =1+(rand())%3;
			  			switch(jogadaHumano ){
			  				case 1:
                                printf("\nPapel x");
                                break;
                            case 2:
                                printf("\nTesoura x");
                                break;

                            case 3:
                                printf("\nPedra x");
                                break;
						}
			  			switch(jogadaPC){
			  			    case 1:
                                printf(" Papel\n\n");
                                break;
                            case 2:
                                printf(" Tesoura\n\n");
                                break;
                            case 3:
                                printf(" Pedra\n\n");
                                break;
						}

			  			if (jogadaPC == jogadaHumano){
			  				printf("\nVoce e o PC empataram!!\n\n");
			  				empate ++;
			  				jogadasTotal ++;
						}
						else if((jogadaHumano == 1 && jogadaPC == 2) || (jogadaHumano == 2 && jogadaPC == 3) || (jogadaHumano == 3 && jogadaPC == 1)){
							printf("\nVoce perdeu para o PC :(\n\n");
			  				derrota ++;
			  				jogadasTotal ++;
			  				porcentagemDerrota ++;
						}
						else if((jogadaHumano == 2 && jogadaPC == 1) || (jogadaHumano == 3 && jogadaPC == 2) || (jogadaHumano == 1 && jogadaPC == 3)){
							printf("\nVoce ganhou do PC :)\n\n");
			  				vitoria ++;
			  				jogadasTotal ++;
			  				porcentagemVitoria ++;
						}
					}
				}while(jogadaHumano != 4);

			if(jogadasTotal > 0){
				porcentagemDerrota = (porcentagemDerrota / jogadasTotal) * 100;
				porcentagemVitoria = (porcentagemVitoria / jogadasTotal) * 100;
				printf("Placar final:\n--------\nVitorias: %d\nDerrotas: %d\nEmpates: %d\nTotal de jogos: %d", vitoria, derrota, empate, jogadasTotal);
				printf("\nPoncentagem de vitoria do player =  %f", porcentagemVitoria);
				printf("\nPoncentagem de vitoria do PC=  %f", porcentagemDerrota);

				if (derrota > vitoria){
					printf("\n\n\nAND THE WINNER IS......... ");
					printf("PC!!!!");
				}
				else if (derrota < vitoria){
					printf("\nAND THE WINNER IS......... ");
					printf("VOCE!!!");
				}
				else if (derrota == vitoria){
					printf("\nDEU EMPATE!!!");
				}
			}
			else{
				printf("\nVoce nao jogou nenhuma vez :(");
			}
			break;

		default:
			printf("\nPor favor insira um modo de jogo permitido!!\n\n");
			break;

		}
	}while(comoJogar != 1 && comoJogar != 2);

	return 0;
}
