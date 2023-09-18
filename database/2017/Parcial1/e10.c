#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])

{
	
	int valorInt, valorMeia, valorTotal, money, troco, student, filme, subtitle, horario, ingressos, ingressosDisp, reset;
	
	valorInt = 20;
	valorMeia = 10;
	reset = 1;
	
	
	
	/* Introdução */
	
	printf ("\n   Ingresso++ \n   Seu Filme Esta Aqui! \n");
	printf ("\n   100 Cadeiras por Cinema \n   Limite de 40%% Meias \n   Valor Ingresso = R$ 20,00 \n\n\n\n");
	
	
	
	do {
		
	printf ("   INICIO \n\n");
	
	/* Estudante */
	
	printf ("   1. SIM \n   2. NAO \n");
	printf ("   Estudante: ");
	scanf ("%d", &student);
	
	while (student < 1 || student > 2)
	{
		printf ("\n   Opcao Invalida\n   Digite Novamente: ");
		scanf ("%d", &student);
	}
	
	switch (student)
	{
		case 1: student = valorMeia; printf ("\n");
		break;
		case 2: student = valorInt; printf ("\n");
		break;
	}
	
	
	
	/* Filme */
	
	printf ("   1. Logan \n   2. Deadpool \n");
	printf ("   Filme: ");
	scanf ("%d", &filme);
	
	while (filme < 1 || filme > 2)
	{
		printf ("\n   Opcao Invalida\n   Digite Novamente: ");
		scanf ("%d", &filme);
	}
	
	switch (filme)
	{
		case 1: printf ("\n");
		break;
		case 2: printf ("\n");
		break;
	}
	
	
	
	/* Subtitle */
	
	printf ("   1. Dublado \n   2. Legendado \n");
	printf ("   Subtitle: ");
	scanf ("%d", &subtitle);
	
	while (subtitle < 1 || subtitle > 2)
	{
		printf ("\n   Opcao Invalida\n   Digite Novamente: ");
		scanf ("%d", &subtitle);
	}
	
	switch (subtitle)
	{
		case 1: printf ("\n");
		break;
		case 2: printf ("\n");
		break;
	}
	
	
	
	/* Horario */
	
	if (filme == 1 && subtitle == 1)
	{
		printf ("   1. 11:00 \n   2. 12:30 \n");
		printf ("   Horario: ");
		scanf ("%d", &horario);
		
		while (horario < 1 || horario > 2)
		{
			printf ("\n   Opcao Invalida\n   Digite Novamente: ");
			scanf ("%d", &horario);
		}
		
		switch (horario)
		{
			case 1: printf ("\n");
			break;
			case 2: printf ("\n");
			break;
		}
	}
	
	if (filme == 1 && subtitle == 2)
	{
		printf ("   1. 14:00 \n   2. 15:30 \n");
		printf ("   Horario: ");
		scanf ("%d", &horario);
		
		while (horario < 1 || horario > 2)
		{
			printf ("\n   Opcao Invalida\n   Digite Novamente: ");
			scanf ("%d", &horario);
		}
		
		switch (horario)
		{
			case 1: printf ("\n");
			break;
			case 2: printf ("\n");
			break;
		}
	}
	
	if (filme == 2 && subtitle == 1)
	{
		printf ("   1. 17:00 \n   2. 18:30 \n");
		printf ("   Horario: ");
		scanf ("%d", &horario);
		
		while (horario < 1 || horario > 2)
		{
			printf ("\n   Opcao Invalida\n   Digite Novamente: ");
			scanf ("%d", &horario);
		}
		
		switch (horario)
		{
			case 1: printf ("\n");
			break;
			case 2: printf ("\n");
			break;
		}
	}
	
	if (filme == 2 && subtitle == 2)
	{
		printf ("   1. 20:00 \n   2. 21:30 \n");
		printf ("   Horario: ");
		scanf ("%d", &horario);
		
		while (horario < 1 || horario > 2)
		{
			printf ("\n   Opcao Invalida\n   Digite Novamente: ");
			scanf ("%d", &horario);
		}
		
		switch (horario)
		{
			case 1: printf ("\n");
			break;
			case 2: printf ("\n");
			break;
		}
	}
	
	
	
	/* Local */
	
	if ( filme == 1 && subtitle == 1 )
	{
		printf ("   Local: Sala A \n");
	}
	
	if ( filme == 1 && subtitle == 2 )
	{
		printf ("   Local: Sala B \n");
	}
	
	if ( filme == 2 && subtitle == 1 )
	{
		printf ("   Local: Sala C \n");
	}
	
	if ( filme == 2 && subtitle == 2 )
	{
		printf ("   Local: Sala D \n");
	}
	
	
	
	/* Ingressos */
	
	if ( (filme == 1 && subtitle == 1) && (horario == 2) )
	{
		ingressosDisp = 1;
		ingressos = 1;
		printf ("   Ingressos Disponiveis: INT-05 MEIA-08 \n");
		printf ("   Ingressos Vendidos: INT-55 MEIA-32");
		printf ("\n\n\n\n");
	}
	
	if ( (filme == 1 && subtitle == 2) && (horario == 1) )
	{
		ingressosDisp = 1;
		ingressos = 1;
		printf ("   Ingressos Disponiveis: INT- 10 MEIA-05 \n");
		printf ("   Ingressos Vendidos: INT-50 MEIA-35");
		printf ("\n\n\n\n");
	}
	
	if ( (filme == 1 && subtitle == 2) && (horario == 2) )
	{
		ingressosDisp = 1;
		ingressos = 1;
		printf ("   Ingressos Disponiveis: INT-15 MEIA-06 \n");
		printf ("   Ingressos Vendidos: INT-45 MEIA-34");
		printf ("\n\n\n\n");
	}
	
	if ( (filme == 2 && subtitle == 1) && (horario == 2) )
	{
		ingressosDisp = 1;
		ingressos = 1;
		printf ("   Ingressos Disponiveis: INT-08 MEIA-10 \n");
		printf ("   Ingressos Vendidos: INT-52 MEIA-30");
		printf ("\n\n\n\n");
	}
	
	if ( (filme == 2 && subtitle == 2) && (horario == 1) )
	{
		ingressosDisp = 1;
		ingressos = 1;
		printf ("   Ingressos Disponiveis: INT-12 MEIA-11 \n");
		printf ("   Ingressos Vendidos: INT-48 MEIA-29");
		printf ("\n\n\n\n");
	}
	
	if ( (filme == 2 && subtitle == 2) && (horario == 2) )
	{
		ingressosDisp = 1;
		ingressos = 1;
		printf ("   Ingressos Disponiveis: INT-18 MEIA-12 \n");
		printf ("   Ingressos Vendidos: INT-42 MEIA-28");
		printf ("\n\n\n\n");
	}
	
	if ( ((filme == 1 && subtitle == 1) && (horario == 1)) || ((filme == 2 && subtitle == 1) && (horario == 1)) )
	{
		ingressosDisp = 0;
		ingressos = 0;
		printf ("   Ingressos Disponiveis: INT-00 MEIA-00 \n");
		printf ("   Ingressos Vendidos: INT-60 MEIA-40");
		printf ("\n\n\n\n");
	}
	
	valorTotal = student*ingressos;
	
	
	
	/* Dados */
	
	printf ("   Ingresso (Dados): \n\n");
	
	
	
	/* Estudante */
	
	printf ("   Estudante:      ");
	
	if (student == valorMeia)
	{
		printf ("SIM (Meia) \n");
	}
	
	if (student == valorInt)
	{
		printf ("NAO (Inteira) \n");
	}

	
	
	/* Filme */
	
	printf ("   Filme:          ");
	
	if ( filme == 1 && subtitle == 1 )
	{
		printf ("Logan (Dublado) \n");
	}
	
	if ( filme == 1 && subtitle == 2 )
	{
		printf ("Logan (Legendado) \n");
	}
	
	if ( filme == 2 && subtitle == 1 )
	{
		printf ("Deadpool (Dublado) \n");
	}
	
	if ( filme == 2 && subtitle == 2 )
	{
		printf ("Deadpool (Legendado) \n");
	}
	
	
	
	/* Local */
	
	printf ("   Local:          ");
	
	if ( filme == 1 && subtitle == 1 )
	{
		printf ("Sala A \n");
	}
	
	if ( filme == 1 && subtitle == 2 )
	{
		printf ("Sala B \n");
	}
	
	if ( filme == 2 && subtitle == 1 )
	{
		printf ("Sala C \n");
	}
	
	if ( filme == 2 && subtitle == 2 )
	{
		printf ("Sala D \n");
	}
	
	
	
	/* Horario */
	
	printf ("   Horario:        ");
	
	if ( (filme == 1 && subtitle == 1) && (horario == 1) )
	{
		printf ("11:00 \n");
	}
	
	if ( (filme == 1 && subtitle == 1) && (horario == 2) )
	{
		printf ("12:30 \n");
	}
	
	if ( (filme == 1 && subtitle == 2) && (horario == 1) )
	{
		printf ("14:00 \n");
	}
	
	if ( (filme == 1 && subtitle == 2) && (horario == 2) )
	{
		printf ("15:30 \n");
	}
	
	if (  (filme == 2 && subtitle == 1) && (horario == 1) )
	{
		printf ("17:00 \n");
	}
	
	if ( (filme == 2 && subtitle == 1) && (horario == 2) )
	{
		printf ("18:30 \n");
	}
	
	if ( (filme == 2 && subtitle == 2) && (horario == 1) )
	{
		printf ("20:00 \n");
	}
	
	if ( (filme == 2 && subtitle == 2) && (horario == 2) )
	{
		printf ("21:30 \n");
	}
	
	
	
	/* Ingressos */
	
	printf ("   Ingressos:      ");
	
	if (ingressosDisp == 0)
	{
		printf ("00 \n");
	}else
	{
		printf ("01 \n");
	}
	
	
	/* Valor Total */
	
	printf ("   Valor Total:    ");
	
	if (ingressosDisp == 0)
	{
		printf ("00 \n\n\n\n\n\n");
	}else
	{
		if (student == valorMeia)
		{
			printf ("10 \n\n\n\n");
		}
		
		if (student == valorInt)
		{
			printf ("20 \n\n\n\n");
		}
	}
	
	
	
	/* Pagamento */

	if (ingressosDisp == 1)
	{
		
		printf ("   Pagamento: \n");
		printf ("   Dinheiro: ");
		scanf ("%d", &money);
	
		while (money < valorTotal)
		{
			printf ("   Opcao Invalida \n\n   Dinheiro: ");
			scanf ("%d", &money);
		}
	
		if (money >= valorTotal)
		{
			troco = money - valorTotal;
			printf ("   Troco: %d \n\n", troco);
			printf ("   TRANSACAO CONCLUIDA \n\n\n\n\n\n");
		}
		
	}
	
	} while (reset == 1);
	
	return 0;
	
}

