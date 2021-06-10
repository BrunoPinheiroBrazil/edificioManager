#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* Fa�a um programa em C onde para um edif�cio de n andares, para cada andar do pr�dio, leia o n�mero de pessoas que entraram e sa�ram do elevador. 
Considere que o elevador est� vazio e est� subindo. Os dados se referem a apenas uma �subida� do elevador e que o n�mero de pessoas dentro do elevador sempre ser� maior ou igual a zero.
Se o n�mero de pessoas, ap�s a entrada e sa�da for maior que 15, deve ser mostrada a mensagem �EXCESSO DE PASSAGEIROS . DEVEM SAIR " em seguida, o n�mero de pessoas que devem sair do elevador, 
de modo que seja obedecido o limite de 15 passageiros. Ap�s a entrada e sa�da de pessoas no �ltimo andar o algoritmo deve mostrar quantas pessoas ir�o descer.
*/

typedef enum 
{
	F,
	T
} boolean;

int main(int argc, char *argv[]) {
	
	int andaresPredio=0;
	int quantidadeTripulantes=0;
	
	printf("Bem vindo ao programa Controle de Elevador do Edificio\n");
	printf("Pressione alguma tecla para continuar...\n");
	getchar();
	while(andaresPredio <= 0)
	{
		andaresPredio = 0;
		
		printf("Insira a quantidade de andares do Predio:\n");
		scanf("%d", &andaresPredio);
		
		if(andaresPredio <= 0)
		{
			printf("Insira pelo menos um numero maior que 0 para a quantidade de andares para o Predio\n");
		}
		
	}
	
	SobeElevador(andaresPredio);
	
	return 0;
}


SobeElevador(int andaresPredio)
{
	int andarAtual=0;
	int quantidadeDePessoasASair;
	int quantidadeDePessoasAEntrar;
	int qtPessoasRestantes=0;
	boolean validou;
	
	while(andarAtual < andaresPredio)
	{
		validou = F;
		if(andarAtual == 0)
		{
			printf("O Elevador esta no terreo, insira a quantidade de pessoas a entrar:\n");
		}
		else
		{
			printf("O Elevador esta no %d o andar, insira a quantidade de pessoas a entrar:\n", andarAtual);
		}
		
		scanf("%d", &quantidadeDePessoasAEntrar);
		
		int qtPessoasPrecisamSair = quantidadeDePessoasAEntrar - (15 - qtPessoasRestantes);
		
		if(qtPessoasPrecisamSair > 0)
		{
			printf("O Elevador atingiu capacidade maxima de 15 pessoas!! %d pessoas precisam sair!!\n", qtPessoasPrecisamSair);
		}
		
		printf("Agora insira a quantidade de pessoas a sair do Elevador:\n");
		scanf("%d", &quantidadeDePessoasASair);
		
		if(quantidadeDePessoasASair < qtPessoasPrecisamSair)
		{
			printf("Voce inseriu o valor de pessoas a sair menor que o minimo, devem sair %d pessoas\n", qtPessoasPrecisamSair);
		}
		else
		{
			int qtPessoasQueVaoRestar = (quantidadeDePessoasAEntrar + qtPessoasRestantes) - quantidadeDePessoasASair;
		
			if(qtPessoasQueVaoRestar >= 0)
			{
				qtPessoasRestantes = qtPessoasRestantes + (quantidadeDePessoasAEntrar - quantidadeDePessoasASair);
				validou = T;
			}
			
			printf("-------------------------------------\n");
			if(andarAtual>0)
			{
				printf("O elevador tem %d pessoas e esta no %d andar no momento\n", qtPessoasRestantes, andarAtual);
			}
			else
			{
				printf("O elevador tem %d pessoas e esta no terreo no momento\n", qtPessoasRestantes);
			}
			
			printf("-------------------------------------\n");
			printf("%d pessoas sairam\n", quantidadeDePessoasASair);
			printf("-------------------------------------\n");
			printf("%d pessoas entraram\n", quantidadeDePessoasAEntrar);
			printf("-------------------------------------\n");
		}
		
		
		if(validou == T)
		{
			printf("O elevador esta subindo");
			int a=0;
			for(a=0;a<3;a++)
			{
				sleep(1);
				printf(".");
			}
			printf("\n\n\n");
			andarAtual++;
		}
		else
		{
			printf("Voce inseriu dados errados, o Elevador nao fechou, insira novamente os dados.\n\n\n");
		}
	}
	
	printf("O elevador chegou ao ultimo andar.\n");
	
	if(qtPessoasRestantes > 0)
	{
		printf("%d pessoas restantes desceram\n", qtPessoasRestantes);
	}
	else
	{
		printf("Todas as %d pessoas que restaram desceram no %d o andar\n", andarAtual);
	}
}



