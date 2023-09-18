#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 6

int * GeraCaptcha(int Captcha[TAMANHO])
{
	int contador, escolha, captcha;
	
	for(contador=0; contador<TAMANHO; contador++)
	{
		escolha=rand();
		escolha=(escolha % 3);
		if(escolha == 0) //Gera Numero
		{
			captcha=rand();
			captcha=(captcha % 10)+48;
			Captcha[contador]=captcha;
		}
		if(escolha == 1) //Gera Letra Minuscula
		{
			captcha=rand();
			captcha=(captcha % 25)+97;
			Captcha[contador]=captcha;
		}
		if(escolha == 2) //Gera Letra Maiuscula
		{
			captcha=rand();
			captcha=(captcha % 25)+65;
			Captcha[contador]=captcha;
		}
	}
	return Captcha;
}

int ValidaCaptcha(int CaptchaCompleto[TAMANHO], char CaptchaUsuario[TAMANHO])
{
	int contador;
	
	for(contador=0; contador<TAMANHO; contador++)
	{
		if(CaptchaCompleto[contador] != CaptchaUsuario[contador]) //Compara ponto a ponto
		{
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	int teste=-1, contador, CaptchaVazio[TAMANHO], * CaptchaCompleto;
	char CaptchaUsuario[TAMANHO];
	float tempo;
	clock_t c2, c1;
	
	srand(time(NULL)); //Gera Captcha
	while(teste!=0)
	{
		CaptchaCompleto=GeraCaptcha(CaptchaVazio);
		printf("Prove que voce nao eh um Robo!\n\n");
		printf("      ");
		for(contador=0; contador<TAMANHO; contador++)
		{
			printf("%c", CaptchaCompleto[contador]); //Impressao do Captcha
		}
		printf("\n\nInsira os 6 caracteres acima seguindo a ordem apresentada em 15 segundos.\n\n");
		printf("Captcha:");
		c1 = clock(); //Conta tempo inicio.
		gets(CaptchaUsuario); //Leitura do Usuario
		c2 = clock(); //Conta tempo final.
		tempo = (c2 - c1)*1000/CLOCKS_PER_SEC;
		if(tempo > 15000)
		{
			system("cls");
			printf("\nTompo maximo excedido!\n\n"); //Valida o tempo maximo de 15 segundos para que o usuario insira o captcha.
		}
		else
		{
			if(strlen(CaptchaUsuario) != TAMANHO)
				teste = 1;
			else
				teste=ValidaCaptcha(CaptchaCompleto, CaptchaUsuario); //Compara o Captcha
			if(teste == 1)
			{
				system("cls");
				printf("\nCaptcha invalido!!\n\n");
			}
		}
	}
	printf("\nCaptcha valido!!\n");
}
