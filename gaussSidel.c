/*
Instituto de Matemática e Computação
CMAC05 – Cálculo Numérico para Computação
Exercício Prático 05 – EP05 – 19/09/2023
Gustavo Rafael Paulino - 2022006185
Patricky Alexandre da Costa Silva - 2020028352
Método de Gauss Sidel
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void printMatriz(double A[MAX_SIZE][MAX_SIZE], int n) {
  int i, j;
  printf("Matriz A:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%2.6lf\t", A[i][j]);
    }
    printf("\n");
  }
}

void printMatrizAjustada(double A[MAX_SIZE][MAX_SIZE], int n) {
  int i, j;
  printf("Matriz A após os ajustes da diagonal:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        printf("%2.6lf\t", A[i][j]);
      } else {
        printf("0.00\t");
      }
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  int n, i, j, k, count, converge; // Número de equações/incógnitas
  double epsilon;                  // Tolerância para o critério de parada
  double A[MAX_SIZE][MAX_SIZE];    // Matriz dos coeficientes
  double b[MAX_SIZE];              // Vetor de termos independentes
  double x[MAX_SIZE];              // Vetor de soluções
  double novoX[MAX_SIZE];          // Vetor de soluções atualizado
  double diag;
  FILE *file;

  if (argc != 2) {
    printf("Uso: %s <arquivo_de_dados>\n", argv[0]);
    return 1;
  }

  file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  fscanf(file, "%d", &n);
  fscanf(file, "%lf", &epsilon);
  fscanf(file, "%d", &k);

  // Lê os elementos da matriz e os termos independentes
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      fscanf(file, "%lf", &A[i][j]);
    }
    fscanf(file, "%lf", &b[i]);
  }

  fclose(file);

  printMatriz(A, n);

  // Verifica se o sistema é impossível ou sem solução
  for (i = 0; i < n; i++) {
    diag = A[i][i];
    if (fabs(diag) < epsilon) {
      printf("\nSistema Impossivel\n");
      return 1;
    }
  }

  // Chute inicial para as soluções (pode ser 0 para começar)
  for (i = 0; i < n; i++) {
    x[i] = 1;
  }

  count = 0; // Contador de iterações

  // Realiza o método de Gauss-Seidel
  for (count = 0; count < k; count++) {
    for (i = 0; i < n; i++) {
      novoX[i] = b[i];
      for (j = 0; j < n; j++) {
        if (i != j) {
          novoX[i] -= A[i][j] * novoX[j];
        }
      }
      novoX[i] /= A[i][i];
    }

    converge = 1;
    for (i = 0; i < n; i++) {
      if (fabs(novoX[i] - x[i]) > epsilon) {
        converge = 0;
        break;
      }
    }

    printf("Iteração %d:\n", count + 1);
    for (i = 0; i < n; i++) {
      printf("x[%d] = %lf\n", i, novoX[i]);
    }

    if (converge) {
      break;
    }

    // Atualiza o vetor de soluções para a próxima iteração
    for (i = 0; i < n; i++) {
      x[i] = novoX[i];
    }
  }

  if (count == k) {
    printf("A solução não foi atingida com %d iterações e o erro relativo foi "
           "de %2.6lf\n",
           k, fabs(novoX[0] - x[0]));
  } else {
    printf("Precisão atingida após %d iterações.\n", count + 1);
  }

  return 0;
}
