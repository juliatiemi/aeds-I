#include <stdio.h>
#include <stdlib.h>

void GeracaoNova(int l, int c, int **matrix1) {
	int vizinhos;
	int i, j;
	int **matrix2;
	FILE *geracao;
	matrix2 = (int**) malloc(l * sizeof (int*));
	for(i = 0; i < l; i++) {
		matrix2[i] = (int*) malloc(c * sizeof (int));
	}
	geracao = fopen("geracao.txt", "w");
	if(geracao == NULL) {
		printf("Erro ao abrir arquivo!\n");
	}
	fprintf(geracao, "%d %d\n", l, c);
	for(j = 0; j <= c+1; j++) {
		printf("==");
	}
	printf("\n");
	for(i = 0; i < l; i++) {
		printf("||");
		for(j = 0; j < c; j++) {
			vizinhos = 0;
			if(matrix1[i][j] == 1) {
				if(i != 0) {
					if(j != 0) {
						if(matrix1[i-1][j-1] == 1 ) {
							vizinhos++;
						}
					}
					if(matrix1[i-1][j] == 1 ) {
						vizinhos++;
					}
					if(j != (c-1)) {
						if(matrix1[i-1][j+1] == 1) {
						vizinhos++;
						}
					}
				}
				if(j != 0) {
					if(matrix1[i][j-1] == 1) {
					vizinhos++;
					}
				}
				if(j != (c-1)) {
	 				if(matrix1[i][j+1] == 1) {
					vizinhos++;
					}
				}
				if(i != (l-1)) {
					if(j != 0) {
						if(matrix1[i+1][j-1] == 1) {
							vizinhos++;
						}
					}
					if(matrix1[i+1][j] == 1) {
						vizinhos++;
					}
					if(j != (c-1)) {
						if(matrix1[i+1][j+1] == 1) {
							 vizinhos++;
						}
					}
				}
				if(vizinhos > 3 || vizinhos < 2) {
					matrix2[i][j] = 0;
					fprintf(geracao, "0 ");
					printf("  ");
				}
				if(vizinhos == 2 || vizinhos == 3) {
					matrix2[i][j] = 1;
					fprintf(geracao, "1 ");
					printf("* ");
				}
			}
			else if(matrix1[i][j] == 0) {
				if(i != 0) {
					if(j != 0) {
						if(matrix1[i-1][j-1] == 1 ) {
							vizinhos++;
						}
					}
					if(matrix1[i-1][j] == 1 ) {
						vizinhos++;
					}
					if(j != (c-1)) {
						if(matrix1[i-1][j+1] == 1) {
							vizinhos++;
						}
					}
				}
				if(j != 0) {
					if(matrix1[i][j-1] == 1) {
						vizinhos++;
					}
				}
				if(j != (c - 1)) {
					if(matrix1[i][j+1] == 1) {
						vizinhos++;
					}
				}
				if(i != (l-1)) {
					if(j != 0) {
						if(matrix1[i+1][j-1] == 1) {
							vizinhos++;
						}
					}
					if(matrix1[i+1][j] == 1) {
						vizinhos++;
					}
					if(j != (c-1)) {
						if(matrix1[i+1][j+1] == 1) {
							vizinhos++;
						}
					}
				}
				if(vizinhos == 3) {
					matrix2[i][j] = 1;
					fprintf(geracao, "1 ");
					printf("* ");
				}
				if(vizinhos != 3) {
					matrix2[i][j] = 0;
					fprintf(geracao, "0 ");
					printf("  ");
				}
			}
		}
		printf("||\n");
		fprintf(geracao, "\n");
	}
	for(j = 0; j <= c+1; j++) {
		printf("==");
	}
	printf("\n");
	for(i = 0; i < l; i++) {
		for(j = 0; j < c; j++) {
			matrix1[i][j] = matrix2[i][j];
		}
	}
	fclose (geracao);
}

void PrimeiraGeracao1() {
	int lin, col, i, j;
	int **matrix;
	char resp;
	FILE *geracao;
	geracao = fopen("geracao.txt", "r");
	if(geracao == NULL) {
		printf("Erro ao abrir arquivo!\n");
	}
	fscanf(geracao, "%d %d", &lin, &col);
	matrix = (int**) malloc(lin * sizeof (int*));
	for(i = 0; i < lin; i++) {
		matrix[i] = (int*) malloc(col * sizeof (int));
	}
	for(j = 0; j <= col+1; j++) {
		printf("==");
	}
	printf("\n");
	for(i = 0; i < lin; i++) {
		printf("||");
		for(j = 0; j < col; j++) {
			fscanf(geracao, "%d", &matrix[i][j]);
			if(matrix[i][j] == 1) {
				printf("* ");
			}
			else if(matrix[i][j] == 0) {
				printf("  ");
			}
		}
		printf("||\n");
	}
	for(j = 0; j <= col+1; j++) {
		printf("==");
	}
	printf("\n");
	for(;;) {
		printf("Deseja produzir outra geracao?\n");
		scanf(" %c", &resp);
		if(resp == 's' || resp == 'S') {
			GeracaoNova(lin, col, matrix);
		}
		if(resp == 'n' || resp == 'N') {
			break;
		}
	}
	fclose (geracao);
}

void PrimeiraGeracao2() {
	int lin, col, i, j, x;
	int **matrix;
	char resp;
	FILE *geracao;
	srand((unsigned)time(NULL));
	geracao = fopen("geracao.txt", "w");
	if(geracao == NULL) {
		printf("Erro ao abrir arquivo!\n");
	}
	printf("Insira o numero o de linhas e colunas.\n");
	scanf("%d%d", &lin, &col);
	matrix = (int**) malloc(lin * sizeof (int*));
	for(i = 0; i < lin; i++) {
		matrix[i] = (int*) malloc(col * sizeof (int));
	}
	for(j = 0; j <= col+1; j++) {
		printf("==");
	}
	fprintf(geracao, "%d %d\n", lin, col);
	printf("\n");
	for(i = 0; i < lin; i++) {
		printf("||");
		for(j = 0; j < col; j++) {
			x = rand() % 2;
			if(x == 0) {
				matrix[i][j] = 0;
				fprintf(geracao, "0 ");
				printf("  ");
			}
			else {
				matrix[i][j] = 1;
				fprintf(geracao, "1 ");
				printf("* ");
			}
		}
		fprintf(geracao, "\n");
		printf("||\n");
	}
	for(j = 0; j <= col+1; j++) {
		printf("==");
	}
	printf("\n");
	for(;;) {
		printf("Deseja produzir outra geracao?\n");
		scanf(" %c", &resp);
		if(resp == 's' || resp == 'S') {
			GeracaoNova(lin, col, matrix);
		}
		if(resp == 'n' || resp == 'N') {
			break;
		}
	}
	fclose (geracao);
}

int main() {
	char resp;
	printf("Bem vindo ao Jogo da Vida. Ja possui arquivo inicial? (s/n)\n");
	scanf("%c", &resp);
	if(resp == 's' || resp == 'S') {
		PrimeiraGeracao1();
	}
	if(resp == 'n' || resp == 'N') {
		PrimeiraGeracao2();
	}
	return 0;
}
