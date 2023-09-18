#include <stdio.h>
#include <stdlib.h>
#define bool int
#define FALSE 0
#define TRUE 1

void criarEvento();

void comprarIngressos();

void mostrarInformacoes();

void comprarInteira();

void comprarMeia();

void mostrarRelatorio();

bool checarLotacaoMeia();

bool checarLotacaoInt();

char nomedoEvento[30];
int capacidadeMAX, restante, continuar, vendint, vendmeia, menu, ingint, ingmeia;
float ing, dinheiro, troco;

int main () {

 continuar=0;
 vendint=0;
 vendmeia=0;
 	
/*capacidadeMAX: capacidade maxima
  char: string nomeEvento
  ing : valor ingresso
  restante : quantos lugares ainda tem/sobraram
  ingint : entradas inteiras
  ingmeia : meias entradas
  vendint : entradas inteiras vendidas
  vendmeia : meias entradas vendidas 
  */
  
	
   criarEvento();
      

 do {
 	OUTRAOPCAO4:
 	mostrarInformacoes();
  
  
  if(restante!=0) {
   
  printf("=================================== TIPO DE ENTRADA ===================================\n");
  printf(" Digite 1 para entrada inteira\n");
  printf(" Digite 2 para meia entrada\n");
  printf(" Digite 3 para sair\n");
  
  scanf("%d", &menu);
  
   switch(menu) {
   	
   	case 1:{
   		
   		comprarInteira();
		break;
	   }
	case 2:{
		comprarMeia();
		break;
	}
   
    case 3:{
    	
    	continuar=1;
		break;
	}
	default:{
		printf("Opcao invalida!! Selecione uma opcao valida!\n");
		system("pause");
		system("cls");
		goto OUTRAOPCAO4;
		break;
	}
   }
  }
   else{
    
    printf(" --------------------- TODOS OS INGRESSOS SE ESGOTARAM!!---------------------/n");
    printf(" Nao ha mais ingressos a venda \n\n");
    system ("pause");
    
    continuar=1;
   }
  
 }while (continuar==0);
 
  mostrarRelatorio();
  system ("pause");
  return 0;
}

void criarEvento(){
	OUTRAOPCAO:
   printf(" ------------------------------------------ BEM VINDO AO SISTEM INGRESSO++ ---------------------------------------- \n\n");
      
   printf("Qual o tipo de evento que esta interessado \n");
   
   printf("1 - Show\n");
   printf("2- Teatro\n");
   printf("3 - Esportes\n");
   printf("4 - Cinema\n");
   printf("5 - Outro\n");
	
	scanf("%d", &menu); fflush(stdin);

	switch(menu) {
 	
 	case 1: 
 	{
 	   printf("De qual cantor ou banda e o show: (Ex: Show de Rock) \n");
 	   gets(nomedoEvento);

 	   break;
 		
	 }
 	case 2: {
 		
 		printf("Qual o nome do evento no teatro e onde: (Ex: Musical de Mamma Mia no Teatro Guaira) \n ");
 		gets(nomedoEvento);
 		
 		
		break;
	 }
	 
	 case 3: {
	 	
	 	printf("Qual o tipo de esporte e/ou de que time: (Ex: Jogo do Internacional) \n");
	 	gets(nomedoEvento);
	 	
	 	
		break;
	 }
	 
	 case 4: {
	 	
	 	printf("Qual o filme que voce esta interessado: (Ex: A Mulher Maravilha) \n");
	 	gets(nomedoEvento);
	 	
	 	
		break;
	 }
	 
	 case 5: {
	 	
	 	printf("Qual o nome do evento: \n");
 		gets(nomedoEvento);
 		
 	
 		
		break;
	 }
	 
	 default:{
	 	printf("Opcao incorreta! Selecione uma opcao valida\n");
	 	system("pause");
	 	system("cls");
	 	goto OUTRAOPCAO;
		break;
	 }
	 
}

 printf("Qual a capacidade maxima do local:  ");
 scanf("%d", &capacidadeMAX);fflush(stdin);
 
 ingmeia = capacidadeMAX*0.40;
 
 ingint = capacidadeMAX-ingmeia;

 restante = capacidadeMAX;
 
 printf("Defina o valor do ingresso:  ");
 scanf("%f", &ing);fflush(stdin);
	
}

void mostrarInformacoes(){
	
  system("cls");
  printf("=================================== COMPRA DE INGRESSOS ===================================\n");
  printf(" O nome do evento e %s\n Ingressos restantes: %d\n\n", nomedoEvento, restante);
  printf("Inteiras restantes: %d e Meias restantes %d\n\n", (ingint-vendint), (ingmeia-vendmeia));
}

void comprarInteira(){
		OUTRAOPCAO2:

 	if (checarLotacaoInt() == FALSE) {
 		printf("=================================== METODO DE PAGAMENTO =================================\n");
 		printf("Digite 1 para dinheiro (desconto de 10%c)\n",37);
 		printf("Digite 2 para cartao\n");
 		
 		scanf("%d", &menu);
 		
 		switch(menu){
 			
 			case 1: {
 				printf("O valor da entrada inteira e %.2f reais \n Favor a informar a quantia: ",(ing-(ing*0.10)));
  				scanf("%f", &dinheiro);
  				
  				if(dinheiro>=(ing-(ing*0.10))) {
  		
  				troco = dinheiro - (ing-(ing*0.10)); 
  	
  				printf("O seu troco na compra do ingresso e %.2f reais\n", troco);
  
  				vendint++;
  				restante--;
  			}
  			else{
				printf("VALOR INVALIDO!!!! Insira a quantia correta!\n");
				system("pause");
				}
  			
				  system("pause");
				break;
			 }
			 
			 case 2:{
			 	printf("O valor da entrada inteira e %.2f reais \n  ", ing);
			 	printf("Informe o numero do cartao: \n");
			 	getch();
			 	printf("Informe a data de vencimento: \n");
			 	getch();
				printf("Informe o codigo CVV: \n");
				getch();
				printf("Parabens pela compra!!\n");
				system("pause");
				
				vendint++;
  				restante--;
				break;
			 }
			 
			 default:{
			 	
			 	printf("Opcao incorreta! Selecione uma opcao valida\n");
	 			system("pause");
	 			goto OUTRAOPCAO2;
			 	
				break;
			 }
	
	}
}
	else{
		printf("========================ESGOTADO========================");
		printf("Nao ha mais entradas inteiras para serem vendidas.");
		printf("========================ESGOTADO========================");
		system("pause");
	}
    
}

void comprarMeia(){
	OUTRAOPCAO3:
	
    	if (checarLotacaoMeia() == FALSE) {
    	printf("=================================== METODO DE PAGAMENTO =================================\n");
 		printf("Digite 1 para dinheiro (desconto de 10%c)\n",37);
 		printf("Digite 2 para cartao\n");
 		
 		scanf("%d", &menu);
 		
 		switch(menu){
 			
 	
 			case 1:{
 					if(ingmeia-vendmeia!=0) {
 						
    		printf("O valor da meia entrada e %.2f reais\n Favor a informar a quantia: ",((ing*0.50)-(ing*0.50*0.10)));
    		scanf("%f", &dinheiro);
    		
    		if(dinheiro>=((ing*0.50)-(ing*0.50*0.10))) { 
	
			troco = dinheiro - ((ing*0.50)-(ing*0.50*0.10));
	
    		printf("O seu troco na compra do ingresso e %.2f reais\n", troco);
    
    		vendmeia++;
    		restante--;
    		
    		}
			else{
				printf("VALOR INVALIDO!!!! Insira a quantia correta!\n");
				system("pause");
				}
  			
				  system("pause");
				break;
			 }
			 
		}
		
		case 2:{
			 	printf("O valor da meia entrada e %.2f reais \n",(ing*0.50));
			 	printf("Informe o numero do cartao: \n");
			 	getch();
			 	printf("Informe a data de vencimento: \n");
			 	getch();
				printf("Informe o codigo CVV: \n");
				getch();
				printf("Parabens pela compra!!\n");
				system("pause");	
				vendint++;
  				restante--;
				break;
			 }
			 
		default:{
			 	
			 	printf("Opcao incorreta! Selecione uma opcao valida\n");
	 			system("pause");
	 			goto OUTRAOPCAO3;
			 	
				break;
			 }
	}
}
	
	else {
		printf("========================ESGOTADO========================\n");
		printf("Nao ha mais meias entradas para serem vendidas.\n");
		printf("========================ESGOTADO========================\n");
		system("pause");
	}

}

void mostrarRelatorio(){
	  printf("==================RELATORIO FINAL DE VENDAS==================\n");
  printf("A quantidade de entradas inteiras vendidos foi %d\n", vendint);
  printf("A quantidade de meias entradas vendidas foi %d\n", vendmeia);
  
  if (restante!=0){
  printf(" Sobraram inteiras %d \n", (ingint - vendint));
  printf(" Sobraram meias %d \n", (ingmeia - vendmeia));
  }
}

bool checarLotacaoInt() {
	
	if(ingint-vendint!=0){
		return FALSE;
	}
	else
		return TRUE;
	
}

bool checarLotacaoMeia() {
	
	if(ingmeia-vendmeia!=0){
		return FALSE;
	}
	else
		return TRUE;
	
}
