#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char a;
int xjogou = 0;
char matriz[5][6];
JOGADA j;

void inicio() {
	printf("*********************\n");
	printf("**  JOGO DA VELHA  **\n");
	printf("*********************\n\n");
}

void lemapa() {
	FILE* f;

	f = fopen("mapa.txt", "r");
	if(f == 0) {
		printf("Erro na leitura do mapa\n");
		exit(1);
	}

	for(int i = 0; i < 5; i++) {
		fscanf(f, "%s", matriz[i]);
		}

	fclose(f);
}

void imprimemapa() {
	int i;
	for(i = 0; i < 5; i++)
		printf("%s\n", matriz[i]);
}

void jogadores(char j1[10], char j2[10]) {
	printf("Jogador(a) 1: ");
	scanf("%s", j1);
	printf("Jogador(a) 2: ");
	scanf("%s", j2);

	printf("\n\n%s sera o X!\n\n", j1);

}

int valida(int x, int y) {
	if(j.linha > 4 && j.coluna > 4)
		return 0;
	else
		return 1;
}

JOGADA jogada(char j1[10], char j2[10]) {
	if (xjogou) {
		printf("Vez do(a) %s!\n", j1);
		a = 'X';

		xjogou = 0;
	}
	else {
		printf("Vez do(a) %s!\n", j2);
		a = 'O';

		xjogou = 1; 
	}

	scanf("%d %d", &(j.linha), &(j.coluna));

	j = adapta(j.linha, j.coluna);

	while(!valida(j.linha, j.coluna) || !vazia(j.linha, j.coluna)) {
		system("cls");
		inicio();
		imprimemapa();

		j = adapta(invalida(j.linha, j.coluna, j1, j2));
	}

	return j;
}

JOGADA invalida(int x, int y, char jogador1[10], char jogador2[10]){
	printf("Posicao invalida, %s. Tente novamente!\n", xjogou ? jogador2 : jogador1);
	scanf("%d %d", &(j.linha), &(j.coluna));

	return j;
} 

JOGADA adapta() {
	if(j.linha == 1) j.linha--;
	else if(j.linha == 3) j.linha++;
	else if(j.linha >= 4) j.linha = j.linha + 3;

	if(j.coluna == 1) j.coluna--;
	else if(j.coluna == 3) j.coluna++;
	else if(j.coluna >= 4) j.coluna = j.coluna + 3;

	return j;
}

void atualiza(int x, int y) {
	matriz[x][y] = a;

	imprimemapa();
 }

int vazia(int x, int y) {
	if (matriz[x][y] != '*') 
		return 0;	
	else 
		return 1;
}

 int acabou() {
 	for(int i = 0; i < 5; i++)
 		for(int j = 0; j < 6; i++) 
 			if(matriz[i][j] == '*');
 				return 0;
 		

 	return 1;
 }

int fechoulinha() {
	int i;
	for(i = 0; i < 5; i = i + 2)
		if((matriz[i][0] == a) && (matriz[i][2] == a) && (matriz[i][4] == a))
			return 1;
	return 0;
}

int fechoucoluna() {
	int i;
	for(i = 0; i < 5; i = i + 2)
		if((matriz[0][i] == a) && (matriz[2][i] == a) && (matriz[4][i] == a))
			return 1;

	return 0;
}

int fechoudiagonal() {
	if(((matriz[0][0] == a) && (matriz[2][2] == a) && (matriz[4][4] == a)) || ((matriz[0][4] == a) && (matriz[2][2] == a) && (matriz[4][0] == a)))
		return 1;

	return 0;
}

int querjogardenovo() {
	char denovo;
	printf("Quer jogar de novo?(S/N) ");
	scanf(" %c", &denovo);

	if(denovo == 'S' || denovo == 's') {
		lemapa();
		system("cls");

		return 1;
	}
	else return 0;
}

int main() {
	char jogador1[10], jogador2[10];	
	inicio();
	lemapa();	
		
	jogadores(jogador1, jogador2);
		
	do {
		imprimemapa();
		
		int i;
		for(i = 1; i <= 9; i++){
			JOGADA jj = jogada(jogador1, jogador2);
		
			system("cls");
			inicio();
		
			atualiza(jj.linha, jj.coluna);
		
			if(fechoulinha() || fechoucoluna() || fechoudiagonal()) {
				printf("%s venceu!\n", a == 'X' ? jogador1 : jogador2);
					
				break;
			}
		
		}
		
		if(i == 10)
			printf("Deu velha!\n");
	} while(querjogardenovo());
		// placar
	return 0;
}