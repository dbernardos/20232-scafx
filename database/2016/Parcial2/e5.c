#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * geraCaptcha(char captcha[5]) {
	int maiusculas, minusculas, numeros;
	int maiusculas2, minusculas2, numeros2;
	
	numeros = 48 + rand() % (57 - 48);   // geração de letras/números aleatórios
	numeros2 = 48 + rand() % (57 - 48);
	maiusculas = 65 + rand() % (90 - 65);
	maiusculas2 = 65 + rand() % (90 - 65);
	minusculas = 97 + rand() % (122 - 97);
	minusculas2 = 97 + rand() % (122 - 97);	

	captcha[0] = numeros;                // atribuição dos aleatórios ao captcha
	captcha[1] = maiusculas;
	captcha[2] = minusculas;
	captcha[3] = minusculas2;
	captcha[4] = maiusculas2;
	captcha[5] = numeros2;
	
	return captcha;
}

int comparaCaptcha(char captcha[5], char captchaUsuario[5]) {
	int comparador;

	comparador = strcmp(captcha, captchaUsuario); // compara os vetores com os números gerados e
	return comparador;		                      // o vetor digitado pelo usuário
}

int main(int argc, char *argv[]) {
	char captcha[5], captchaUsuario[5];
	int retorno;
	
	do {
	geraCaptcha(captcha);
	printf("%s \nDigite o captcha acima: ", captcha);
	gets(captchaUsuario);
	retorno = comparaCaptcha(captchaUsuario, captcha);
	if (retorno == 0) {
		printf("O captcha foi digitado corretamente.");
	}
	else {
			printf("O captcha nao foi digitado corretamente. Tente novamente. \n"); 
		}
		
	}
	while (retorno != 0);  //loop até que o usuário digite o código corretamente
	return 0;
}
