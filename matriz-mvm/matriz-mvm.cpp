#include <stdio.h>
#include <stdlib.h>
#define MatrizTam 3

void SomaLinhas(int matriz[MatrizTam][MatrizTam], int linha) {//FUNÇÃO: Somar todas as 'linhas'.
	int indice, soma = 0;
	for (indice = 0; indice < MatrizTam; indice++) {
		soma += matriz[linha][indice];
	}
	printf("%d", soma);
}

void SomaColunas(int matriz[MatrizTam][MatrizTam], int coluna) {//FUNÇÃO: Somar todas as 'colunas'.
	int indice, soma = 0;
	for (indice = 0; indice < MatrizTam; indice++) {
		soma += matriz[indice][coluna];
	}
	printf("%d", soma);
}

void Soma1Diag(int matriz[MatrizTam][MatrizTam]) {//FUNÇÃO: Somar a 'Diagonal Principal'.
	int	coluna, linha, soma = 0;
	for (linha = 0; linha < MatrizTam; linha++) {
		for (coluna = 0; coluna < MatrizTam; coluna++) {
			/* a diagonal principal é sempre o valor igual a posicao da linha e coluna, exemplo: 1,1 - 2,2*/
			if (linha == coluna) {
				soma += matriz[linha][coluna];
			}
		}
	}
	printf("%d", soma);
}

void Soma2Diag(int matriz[MatrizTam][MatrizTam]) {//FUNÇÃO: Somar a 'Diagonal Secundária'.
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

void CuboMagico(int matriz[MatrizTam][MatrizTam]) { //FUNÇÃO: Identificar se é um 'Cubo Magico' somando todas as linhas e determinando se são iguais.
	int soma, linha = 0, coluna = 0, compara = 0;
	do {
		soma = 0;
		for (coluna = 0; coluna < MatrizTam; coluna++) { //Somará as colunas através das linhas.
			soma += matriz[linha][coluna];
		}
		if (!compara) { compara = soma; } //Caso a operação seja satisfeita, será definido um valor para comparar com as outras. Se existir, ele irá comparar.
		else {
			if (soma != compara) {
				printf("\n|\n| Infelizmente o CUBO nao e magico! =(\n|");//Caso não exista, ele exi-birá a mensagem e essa função encerrará.
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
		for (linha = 0; linha < MatrizTam; linha++) {//Realizará a soma de Coluna por Coluna.
			soma += matriz[linha][coluna];
		}
		if (soma != compara) {//Caso a operação não seja satisfeita, ele exibirá a mensagem e essa função encerrará.
			printf("\n|\n| Infelizmente o CUBO nao e magico! =(\n|");
			goto final;
		}
		else {
			coluna++;
		}
	} while (coluna < MatrizTam);
	soma = 0;
	for (linha = 0; linha < MatrizTam; linha++) {//Caso a soma das colunas sejam iguais, prosseguirá a seguir (Diagonal PRINCIPAL).
		for (coluna = 0; coluna < MatrizTam; coluna++) {
			if (linha == coluna) {//Aqui será comparada a Diagonal Principal.
				soma += matriz[linha][coluna];
			}
		}
	}
	if (soma != compara) {//Caso a operação não seja satisfeita (falsa), exibirá a mensagem e essa função encer-rará. 
		printf("\n|\n| Infelizmente o CUBO nao e magico! =(\n|");
	}
	soma = 0;
	for (linha = MatrizTam; linha >= 0; linha--) {/*Caso a soma das colunas sejam iguals, prosseguirá a seguir (Diagonal SECUNDÁRIA).*/
		for (coluna = 0; coluna < MatrizTam; coluna++) {
			if ((linha + coluna) == (MatrizTam - 1)) {//Aqui será comparada a Diagonal Secundária.
				soma += matriz[linha][coluna];
			}
		}
	}
	if (soma != compara) {//Caso a operação não seja satisfeita, ele exibirá a mensagem e essa função encerrará.
		printf("\n|\n| Infelizmente o CUBO nao e magico! =(\n|");
		goto final; /*GOTO: Levará até o final para encerrar a função, evitando assim um 'Loop infinito' do programa.*/
	}
	printf("\n|\n| Parabens, o CUBO eh magico! =)\n|");/*Exibirá na tela caso identifique que todas as somas são iguais!*/
	final:;
}
int main()
{
	int matriz[MatrizTam][MatrizTam];
	MatrizTam; int coluna, linha;
	system("cls");
	for (linha = 0; linha < MatrizTam; linha++) {//FUNÇÃO: Iniciará a linha de comandos para exibição da Matriz
		for (coluna = 0; coluna < MatrizTam; coluna++) {
			printf("Insire um numero para os campos [%d][%d]: ", linha + 0, coluna + 0);
			scanf_s("%d", &matriz[linha][coluna]);/*Exibirá a mensagem na tela e requisitará os números para prosseguir.*/
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
	for (linha = 0; linha < MatrizTam; linha++) {//Exibirá na tela a soma de todas as LINHAS.
		printf("\n| A Soma da linha [%d]: ", linha + 1); SomaLinhas(matriz, linha);
	}
	printf("\n|-----------------------");
	for (coluna = 0; coluna < MatrizTam; coluna++) {//Exibirá na tela a soma de todas as COLUNAS.
		printf("\n| A Soma da coluna [%d]: ", coluna + 1); SomaColunas(matriz, coluna);
	}
	printf("\n|-----------------------");
	printf("\n| A Soma da Diagonal Principal: ");
	Soma1Diag(matriz);//Exibirá a doma da DIAGONAL Principal e Secundária. 
	printf("\n| A Soma da Diagonal Secundaria: ");
	Soma2Diag(matriz);
	CuboMagico(matriz); printf("\n*--------------------FIM--------------------*\n"); printf("\n");
	system("pause");//Encerrará o programa. 
}
