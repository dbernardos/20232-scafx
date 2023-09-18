/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>


void imprimirCaptcha(char captcha[]){
	
	int i;
	
	for(i = 0; i < 6; i++)
	{
		
		printf("%c",captcha[i]);
		
	}
	printf("\n\n");
}

void gerarCaptcha(char captcha[]){	
		
	int i;
	srand((unsigned)time(NULL));
	for(i = 0; i < 6; i++)
	{
			captcha[i] = '0' + (char)(rand()%42);
	}
}

void validarCaptcha(char captcha[], char resposta[]){
	
	if(strcmp(captcha, resposta) == 0)
	{
		
		printf("Captcha correto, pode prosseguir...\n");
		
	}
	else
	{
		printf("\n\nCaptcha incorreto...\n");
		printf("Por favor tente novamente.\n");
	}
}

int menuContinuacao(int opcao){
	
	while(opcao != 1 || opcao != 0){
		
	printf("\n\nDeseja gerar um novo Captcha?\n");
	printf("Selecione a opção: \n");
	printf("1 - Para Continuar\n");
	printf("0 - Para Sair\n");
	scanf("%d", &opcao);
	printf("\n\n");
	
		
	switch(opcao){
		case 1:
			return opcao;
			
		break; 
		case 0: 
			return opcao;	
					
		break; 
		 default: 
		 
	 		printf("Não existe essa opcao! \n\n");
	 		
		}
	}
}

int main(int argc, char** argv){
	
	setlocale(LC_ALL, "Portuguese");

	char captcha[5]; 
	int opcao, i; 
	char resposta[5]; 
	
	opcao = 1;

	while(opcao != 0)
	{
		
	printf("-----Prove que você não é um robo----\n");
	printf("Digite os numeros que estão abaixo: \n");
	
	gerarCaptcha(captcha);
	imprimirCaptcha(captcha);
	
	printf("Digite os caracteres: \n");
	fflush(stdin);
	gets(resposta);

	validarCaptcha(captcha, resposta);

	opcao = menuContinuacao(opcao);

	}

	printf("Tchau!");
	
}

