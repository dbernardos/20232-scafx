#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* VARIAVEIS */

int menu, contEventos, maxEventos, desejaCpf;
float precoInt[20], precoMeia[20];
char nome[20][160];

struct grupoIngresso
{
	int Total[20];
	int Meia[20];
	int Int[20];
};

struct grupoIngresso ingressoDisp, ingressoVend;


/* MODULOS */

void operacao()
{
	setlocale(LC_ALL, "Portuguese");
	printf ("\n   MENU \n\n");
	printf ("   [1] Cadastrar Eventos \n");
	printf ("   [2] Vender Ingressos \n");
	printf ("   [3] Relatório Geral \n");
	printf ("   Opção: ");
	scanf ("%d", &menu);
	
	while (menu > 3 || menu < 1)
	{
		printf ("\n   Opção Inválida \n   Digite Novamente: ");
		scanf ("%d", &menu);
	}
}

void cadastroEvento(int maxEventos, int contEventos)
{	
	for (contEventos == 0; contEventos < maxEventos; contEventos++)
	{
		printf ("\n   Evento [%d]: ", (contEventos + 1));
		scanf ("%s", &nome[contEventos]);
		printf ("   Total Ingressos: ");
		scanf ("%d", &ingressoDisp.Total[contEventos]);
		printf ("   Preço Inteira: ");
		scanf ("%f", &precoInt[contEventos]);
		
		ingressoDisp.Int[contEventos] = ingressoDisp.Total[contEventos] - ingressoDisp.Meia[contEventos];
		ingressoDisp.Meia[contEventos] = ingressoDisp.Total[contEventos] * 0.4;
		precoMeia[contEventos] = precoInt[contEventos]/2;
		
		ingressoVend.Total[contEventos] = 0;
		ingressoVend.Meia[contEventos] = 0;
		ingressoVend.Int[contEventos] = 0;
	}
}

void validarCPF(char cpf[11])
{
	int contcpf, contMult, soma, numb1, numb2, intcpf[11];
	
	for(contcpf == 0; contcpf <= 10; contcpf++)  
	{  
		intcpf[contcpf] = cpf[contcpf] - 48;
	}  
	
	contMult = 10;
	soma = 0;
	
	for (contcpf = 0; contcpf < 9; contcpf++)
	{
		soma = soma + (intcpf[contcpf]*contMult);
		contMult--;
	}
	
	numb1 = soma % 11;
	numb1 = 11 - numb1;
	
	if(numb1 > 9)
	{
		numb1 = 0;
	}
	
	contMult = 11;
	soma = 0;
	
	for (contcpf = 0; contcpf < 10; contcpf++)
	{
		soma = soma + (intcpf[contcpf]*contMult);
		contMult--;
	}
	
	numb2 = soma % 11;
	numb2 = 11 - numb2;
	
	if(numb2 > 9)
	{
		numb2 = 0;
	}
	
	if (numb1 == intcpf[9] && numb2 == intcpf[10])
	{
		printf ("   CPF Válido \n");
		desejaCpf++;
	}else
	{
		printf ("   CPF Inválido \n");
	}
}

void venderIngressos(int contEventos)
{
	int student, metPag, senha;
	float money, troco, precoFinal, precoFinalDesc;
	char cpf[11];
	
	printf ("   Evento: %s \n", nome[contEventos]);
	printf ("   Ingressos Disponíveis: %d \n", ingressoDisp.Total[contEventos]);
	printf ("   Meias Permitidas: %d (40%% Total)\n", ingressoDisp.Meia[contEventos]);
	printf ("   Preço Inteira: R$ %.2f \n\n", precoInt[contEventos]);
	
	
	/* Estudante */
	printf ("   Você é estudante ? \n");
	printf ("   [1] SIM \n");
	printf ("   [2] NAO \n");
	printf ("   Opção: ");
	scanf ("%d", &student);
	
	while (student > 2 || student < 1)
	{
		printf ("\n   Opção Inválida \n   Digite Novamente: ");
		scanf ("%d", &student);
	}

	while (student == 1 && ingressoDisp.Meia[contEventos] == 0)
	{
		printf("\n   Ingressos Meias Esgotados \n   Escolha Outra Opção: ");
		scanf ("%d", &student);
	}

	switch (student)
	{
		case 1:
			precoFinal = precoMeia[contEventos];
		break;
	
		case 2:
			precoFinal = precoInt[contEventos];
		break; 
	}
	
	
	/* CPF */
	printf ("\n   Deseja CPF Na Nota ? \n");
	printf ("   [1] SIM \n");
	printf ("   [2] NAO \n");
	printf ("   Opção: ");
	scanf ("%d", &desejaCpf);
	
	while (desejaCpf < 1 && desejaCpf > 2)
	{
		printf ("\n   Opção Inválida \n   Digite Novamente: ");
		scanf ("%d", &desejaCpf);
	}
	
	while (desejaCpf == 1)
	{
		printf ("\n   Digite seu CPF: ");
		scanf ("%s", &cpf);
		validarCPF(cpf);
	}
	
	
	/* Metodo Pagamento */
	printf ("\n   Escolha Método de Pagamento: \n");
	printf ("   [1] Dinheiro \n");
	printf ("   [2] Cartão \n");
	printf ("   Opção: ");
	scanf ("%d", &metPag);
	
	while (metPag > 2 || metPag < 1)
	{
		printf ("\n   Opção Inválida \n   Digite Novamente: ");
		scanf ("%d", &metPag);
	}
	
	switch (metPag)
	{
		case 1:
			precoFinalDesc = precoFinal*0.9;
			printf ("\n   Preço: R$ %.2f (10%% Desconto) \n   Pagamento: ", precoFinalDesc);
			scanf ("%f", &money);
			
			while (money < precoFinalDesc)
			{
				printf ("\n   Valor Inválido \n   Digite Novamente: ");
				scanf ("%f", &money);
				printf ("\n");
			}

			troco = money - precoFinalDesc;
			printf ("   Troco: R$ %.2f \n\n", troco);
		break;
	
		case 2:
			printf ("\n   Preço: R$ %.2f \n   Digite Sua Senha: ", precoFinal);
			scanf ("%d", &senha);
			printf ("\n");
		break; 
	}
	
	printf ("   TRANSAÇÃO CONCLUÍDA \n\n\n\n");
	
	
	/* Dados Ingressos */
	if (precoFinal == precoInt[contEventos])
	{
		ingressoDisp.Int[contEventos]--;
		ingressoVend.Int[contEventos]++;
	}

	if (precoFinal == precoMeia[contEventos])
	{
		ingressoDisp.Meia[contEventos]--;
		ingressoVend.Meia[contEventos]++;
	}
	
	ingressoDisp.Total[contEventos]--;
	ingressoVend.Total[contEventos]++;
	
}

void ingressosEsgotados(int contEventos)
{
	printf ("\n   Ingressos %s Esgotados \n   Relatório: \n\n", nome[contEventos]);
	printf ("   Ingressos Disponíveis: %d \n", ingressoDisp.Total[contEventos]);
	printf ("   Meias Permitidas: %d (40%% Total)\n\n", ingressoDisp.Meia[contEventos]);
	printf ("   Ingressos Vendidos: \n");
	printf ("   Total = %d \n", ingressoVend.Total[contEventos]);
	printf ("   Inteiras = %d \n", ingressoVend.Int[contEventos]);
	printf ("   Meias = %d \n\n\n\n", ingressoVend.Meia[contEventos]);
}

void relatorioFinal(int contEventos)
{
	for (contEventos == 0; contEventos < maxEventos; contEventos++)
	{
		printf ("   Evento [%d]: %s \n", (contEventos + 1), nome[contEventos]);
		printf ("   Ingressos Disponíveis: %d \n", ingressoDisp.Total[contEventos]);
		printf ("   Meias Permitidas: %d (40%% Total)\n\n", ingressoDisp.Meia[contEventos]);
		printf ("   Ingressos Vendidos: \n");
		printf ("   Total = %d \n", ingressoVend.Total[contEventos]);
		printf ("   Inteiras = %d \n", ingressoVend.Int[contEventos]);
		printf ("   Meias = %d \n\n\n", ingressoVend.Meia[contEventos]);
	}
}


/* INICIO */

int main(int argc, char *argv[])
{
	
	printf ("\n   Ingresso++ 5.0");
	printf ("\n   Seu Ingresso Esta Aqui! \n\n\n\n");
	
	do {
		
		operacao();
		
		switch (menu)
		{
			case 1:
				
				printf ("\n\n\n\n   CADASTRAR EVENTOS \n\n");
				printf ("   Digite Número Total de Eventos: ");
				scanf ("%d", &maxEventos);
				contEventos = 0;
				
				cadastroEvento(maxEventos, contEventos);
				
				printf ("\n\n\n");
			
			break;
			
			case 2:
				
				contEventos = 0;
				
				printf ("\n\n\n\n   VENDER INGRESSOS \n\n");
				
				printf ("   Digite Evento Desejado: \n");
				
				for (contEventos == 0; contEventos < maxEventos; contEventos++)
				{
					printf ("   [%d] %s \n", (contEventos + 1), nome[contEventos]);
				}
				
				printf ("   Opção: ");
				scanf ("%d", &contEventos);
				
				while (contEventos > maxEventos || contEventos < 1)
				{
					printf ("\n   Opção Inválida \n   Digite Novamente: ");
					scanf ("%d", &contEventos);
				}
				
				contEventos = contEventos - 1;
				
				printf ("\n\n");
				
				if (ingressoDisp.Total[contEventos] > 0)
				{
					venderIngressos(contEventos);
				}else
				{
					ingressosEsgotados(contEventos);
				}
				
			break;
		
		}
	
	} while (menu != 3);
	
	printf ("\n\n\n\n   RELATÓRIO GERAL \n\n");
	
	contEventos = 0;
	
	relatorioFinal(contEventos);
	
	printf ("\n\n   Ingresso++ 5.0 \n   Finalizado \n");
	
	return 0;
}
