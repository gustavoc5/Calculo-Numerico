/*
Instituto de Matemática e Computação
CMAC05 – Cálculo Numérico para Computação
Exercício Prático 05 – EP05 – 19/09/2023
Gustavo Rafael Paulino - 2022006185
Patricky Alexandre da Costa Silva - 2020028352
Método de Gauss Jacobi
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

void trocaLinha(double A[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], int l1,
                int l2, int n) {
  double temp;
  int i;
  for (i = 0; i < n; i++) {
    temp = A[l1][i];
    A[l1][i] = A[l2][i];
    A[l2][i] = temp;
  }
  temp = b[l1];
  b[l1] = b[l2];
  b[l2] = temp;
}

int main(int argc, char **argv) {
  int n, i, j, k, maiorColuna, kIter, converge;
  double epsilon;               // Tolerância para o critério de parada
  double A[MAX_SIZE][MAX_SIZE]; // Matriz dos coeficientes
  double b[MAX_SIZE];           // Vetor de termos independentes
  double x[MAX_SIZE];           // Vetor de soluções
  double novoX[MAX_SIZE];       // Vetor de soluções atualizado
  double diag, maxValor;
  FILE *file;

  if (argc != 2) {
    printf("Uso: %s <arquivo_de_dados>\n", argv[0]);
    return 0;
  }

  file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
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

  // Lê o vetor de estimativa inicial
  for (i = 0; i < n; i++) {
    fscanf(file, "%lf", &x[i]);
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

  // Realiza o método de Gauss-Jacobi com pivotamento parcial
  for (kIter = 0; kIter < k; kIter++) {
    for (i = 0; i < n; i++) {
      // Encontra a linha com o maior elemento na coluna atual (pivotamento
      // parcial)
      maiorColuna = i;
      maxValor = fabs(A[i][i]);
      for (j = i + 1; j < n; j++) {
        if (fabs(A[j][i]) > maxValor) {
          maxValor = fabs(A[j][i]);
          maiorColuna = j;
        }
      }

      // Troca as linhas na matriz A e no vetor b
      if (maiorColuna != i) {
        trocaLinha(A, b, i, maiorColuna, n);
      }

      novoX[i] = b[i];
      for (j = 0; j < n; j++) {
        if (i != j) {
          novoX[i] -= A[i][j] * x[j];
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

    printf("Iteração %d:\n", kIter + 1);
    for (i = 0; i < n; i++) {
      printf("x[%d] = %2.6lf\n", i, novoX[i]);
    }

    if (converge) {
      printf("Precisão atingida após %d iterações.\n", kIter + 1);
      return 0;
    }

    // Atualiza o vetor de soluções para a próxima iteração
    for (i = 0; i < n; i++) {
      x[i] = novoX[i];
    }
  }

  printf("A solução não foi atingida com %d iterações e o erro relativo foi de "
         "%2.6lf\n",
         k, fabs(novoX[0] - x[0]));
  printf("Valores calculados:\n");
  for (i = 0; i < n; i++) {
    printf("%2.6lf\n", novoX[i]);
  }

  return 0;
}
