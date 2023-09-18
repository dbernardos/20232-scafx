#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

// Escrito por Alfred Louis Piper -Trabalho 2° Parcial de Programação I- "Gerador de Captcha"

char captcha[6];

void gerarCaptcha()
{
	int gerador, contador;
	
	srand(time(NULL));
    
    for(contador=0; contador<6; contador++)
    {
		gerador=rand() % 3;
		
		if(gerador==0)
    	{
    		captcha[contador]= '0' + (rand() % 10);
		}
		else
		{
			if(gerador==1)
			{
				captcha[contador]='a' + (rand() % 26);
			}
			else
			{
				if(gerador==2)
				{
					captcha[contador]='A' + (rand() % 26);
				}
			}
		}
	}
}

int testarCaptcha(char entrada[])
{
    if (strcmp(entrada, captcha) == 0)
    {
        return TRUE;
    }
    return FALSE;
}

int main()
{
    char lerCaptcha[16];
    int tentativa;

	do
	{
		gerarCaptcha();
		tentativa=0;
		do
    	{
			printf("Tentativa %d MAXIMO: 3", tentativa+1);
			printf("\n%s\nDigite o captcha acima: ", captcha);		 
			gets(lerCaptcha);
			
    		if (testarCaptcha(lerCaptcha))
    		{
				printf("\nACERTO!\n\n");
				break;
	    	}
    		else
    		{	  
        		printf("\nERRRRROU!\n\n");
        		tentativa++;
			}
		} while(tentativa<3);
	}while(tentativa<4);
}
