#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void mostrarCaptcha(char captcha[])
{
	int cont;
	
	printf("O captcha eh: ");
	for(cont =0; cont <6; cont++)
	{
		printf("%c", captcha[cont]);
	}
	printf("\nDigite o captcha acima: ");
}


int main(int argc, char *argv[]) 
{	
	
	char captcha[6];
	char conteudoDigitado[6];
	char valor;
	int cont;
	int captchaDiferente;
	
	while(1)
	{
		system("cls");
		
		for(cont =0; cont <6;)
		{
			valor = (rand() %74) +48;
			if(isalpha(valor) || isdigit(valor))
			{
				captcha[cont] = valor;
				cont++;
			}
		}
		
		mostrarCaptcha(captcha);
		 
		gets(conteudoDigitado);
	
		for(cont =0; cont <6; cont++)
		{
			if(captcha[cont] != conteudoDigitado[cont])
			{
				printf("\nCaptcha diferente, decifre o captcha novamente!\n\n ");
				captchaDiferente = 0;
				break;
			}
		}
		
		if(captcha[cont] == conteudoDigitado[cont])
		{
			printf("Captcha Igual! ");
			captchaDiferente = 1;
			return;	
		}
			
		system("pause");
	}
	
	
	return 0;
}
