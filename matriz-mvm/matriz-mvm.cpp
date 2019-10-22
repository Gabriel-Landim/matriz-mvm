#include <stdio.h>
#include <stdlib.h>
#define MatrizTam 3

void SomaLinhas(int matriz[MatrizTam][MatrizTam], int linha) {//FUN��O: Somar todas as 'linhas'.
	int indice, soma = 0;
	for (indice = 0; indice < MatrizTam; indice++) {
		soma += matriz[linha][indice];
	}
	printf("%d", soma);
}

void SomaColunas(int matriz[MatrizTam][MatrizTam], int coluna) {//FUN��O: Somar todas as 'colunas'.
	int indice, soma = 0;
	for (indice = 0; indice < MatrizTam; indice++) {
		soma += matriz[indice][coluna];
	}
	printf("%d", soma);
}

void Soma1Diag(int matriz[MatrizTam][MatrizTam]) {//FUN��O: Somar a 'Diagonal Principal'.
	int	coluna, linha, soma = 0;
	for (linha = 0; linha < MatrizTam; linha++) {
		for (coluna = 0; coluna < MatrizTam; coluna++) {
			/* a diagonal principal � sempre o valor igual a posicao da linha e coluna, exemplo: 1,1 - 2,2*/
			if (linha == coluna) {
				soma += matriz[linha][coluna];
			}
		}
	}
	printf("%d", soma);
}

void Soma2Diag(int matriz[MatrizTam][MatrizTam]) {//FUN��O: Somar a 'Diagonal Secund�ria'.
	int coluna, linha, soma = 0;

	for (linha = MatrizTam; linha >= 0; linha--) {

		for (coluna = 0; coluna < MatrizTam; coluna++) {
			if ((linha + coluna) == (MatrizTam - 1)) {
				soma += matriz[linha][coluna];
			}
		}
	}
	printf("%d", soma);
}

void CuboMagico(int matriz[MatrizTam][MatrizTam]) { //FUN��O: Identificar se � um 'Cubo Magico' somando todas as linhas e determinando se s�o iguais.
	int soma, linha = 0, coluna = 0, compara = 0;
	do {
		soma = 0;
		for (coluna = 0; coluna < MatrizTam; coluna++) { //Somar� as colunas atrav�s das linhas.
			soma += matriz[linha][coluna];
		}
		if (!compara) { compara = soma; } //Caso a opera��o seja satisfeita, ser� definido um valor para comparar com as outras. Se existir, ele ir� comparar.
		else {
			if (soma != compara) {
				printf("\n|\n| Infelizmente o CUBO nao e magico! =(\n|");//Caso n�o exista, ele exi-bir� a mensagem e essa fun��o encerrar�.
				goto final;
			}
			else {
				linha++;
			}
		}
	} while (linha < MatrizTam);
	coluna = 0;
	do {
		soma = 0;
		for (linha = 0; linha < MatrizTam; linha++) {//Realizar� a soma de Coluna por Coluna.
			soma += matriz[linha][coluna];
		}
		if (soma != compara) {//Caso a opera��o n�o seja satisfeita, ele exibir� a mensagem e essa fun��o encerrar�.
			printf("\n|\n| Infelizmente o CUBO nao e magico! =(\n|");
			goto final;
		}
		else {
			coluna++;
		}
	} while (coluna < MatrizTam);
	soma = 0;
	for (linha = 0; linha < MatrizTam; linha++) {//Caso a soma das colunas sejam iguais, prosseguir� a seguir (Diagonal PRINCIPAL).
		for (coluna = 0; coluna < MatrizTam; coluna++) {
			if (linha == coluna) {//Aqui ser� comparada a Diagonal Principal.
				soma += matriz[linha][coluna];
			}
		}
	}
	if (soma != compara) {//Caso a opera��o n�o seja satisfeita (falsa), exibir� a mensagem e essa fun��o encer-rar�. 
		printf("\n|\n| Infelizmente o CUBO nao e magico! =(\n|");
	}
	soma = 0;
	for (linha = MatrizTam; linha >= 0; linha--) {/*Caso a soma das colunas sejam iguals, prosseguir� a seguir (Diagonal SECUND�RIA).*/
		for (coluna = 0; coluna < MatrizTam; coluna++) {
			if ((linha + coluna) == (MatrizTam - 1)) {//Aqui ser� comparada a Diagonal Secund�ria.
				soma += matriz[linha][coluna];
			}
		}
	}
	if (soma != compara) {//Caso a opera��o n�o seja satisfeita, ele exibir� a mensagem e essa fun��o encerrar�.
		printf("\n|\n| Infelizmente o CUBO nao e magico! =(\n|");
		goto final; /*GOTO: Levar� at� o final para encerrar a fun��o, evitando assim um 'Loop infinito' do programa.*/
	}
	printf("\n|\n| Parabens, o CUBO eh magico! =)\n|");/*Exibir� na tela caso identifique que todas as somas s�o iguais!*/
	final:;
}
int main()
{
	int matriz[MatrizTam][MatrizTam];
	MatrizTam; int coluna, linha;
	system("cls");
	for (linha = 0; linha < MatrizTam; linha++) {//FUN��O: Iniciar� a linha de comandos para exibi��o da Matriz
		for (coluna = 0; coluna < MatrizTam; coluna++) {
			printf("Insire um numero para os campos [%d][%d]: ", linha + 0, coluna + 0);
			scanf_s("%d", &matriz[linha][coluna]);/*Exibir� a mensagem na tela e requisitar� os n�meros para prosseguir.*/
		}
	}
	printf("\n*** Matriz definida ***\n");
	for (linha = 0; linha < MatrizTam; linha++) {
		for (coluna = 0; coluna < MatrizTam; coluna++) {
			if (coluna == 0) {
				printf("\n|");
			}
			printf("%02d", matriz[linha][coluna]);
			if (coluna < MatrizTam - 1) {
				printf("\t");
			}
			if (coluna + 1 == MatrizTam) {
				printf("|");
			}
		}
	}
	printf("\n------------------------");
	for (linha = 0; linha < MatrizTam; linha++) {//Exibir� na tela a soma de todas as LINHAS.
		printf("\n| A Soma da linha [%d]: ", linha + 1); SomaLinhas(matriz, linha);
	}
	printf("\n|-----------------------");
	for (coluna = 0; coluna < MatrizTam; coluna++) {//Exibir� na tela a soma de todas as COLUNAS.
		printf("\n| A Soma da coluna [%d]: ", coluna + 1); SomaColunas(matriz, coluna);
	}
	printf("\n|-----------------------");
	printf("\n| A Soma da Diagonal Principal: ");
	Soma1Diag(matriz);//Exibir� a doma da DIAGONAL Principal e Secund�ria. 
	printf("\n| A Soma da Diagonal Secundaria: ");
	Soma2Diag(matriz);
	CuboMagico(matriz); printf("\n*--------------------FIM--------------------*\n"); printf("\n");
	system("pause");//Encerrar� o programa. 
}
