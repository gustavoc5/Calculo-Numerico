#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int main(int argc, char **argv) {
  double A[MAX][MAX], B[MAX][MAX + 1];
  double b[MAX], x[MAX], Laux[MAX];
  int i = 0, j = 0, k = 0, n, l;
  double m, S;

  if (argc != 2) // verifica se o nome do arquivo foi fornecido
  {
    printf("Erro: informe o nome do arquivo de dados.\n");
    return 1;
  }
  FILE *fp = fopen(argv[1], "r"); // abre o arquivo para leitura
  if (fp == NULL) // verifica se o arquivo foi aberto com sucesso
  {
    printf("Erro: não foi possível abrir o arquivo %s.\n", argv[1]);
    return 2;
  }
  // leitura dos dados do arquivo

  // leitura da ordem da matriz
  fscanf(fp, "%d", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      fscanf(fp, "%lf", &A[i][j]);
    }
  }

  // leitura do vetor
  for (i = 0; i < n; i++) {
    fscanf(fp, "%lf", &b[i]);
  }

  /* Montando a matriz expandida */

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      B[i][j] = A[i][j];
    }
  }

  for (i = 0; i < n; i++) {
    B[i][n] = b[i];
  }

  /* impressao da matriz expandida */

  for (i = 0; i < n; i++) {
    printf("\n");
    for (j = 0; j <= n; j++) {
      printf(" B=[%d][%d] = %2.2lf ", i, j, B[i][j]);
    }
  }

  fflush(stdin);
  getchar();

  /* escalonamento da matriz expandida */

  for (k = 0; k < n - 1; k++) {
    for (i = k + 1; i < n; i++) {
      m = B[i][k] / B[k][k];
      B[i][k] = 0;
      for (j = k + 1; j <= n; j++) {
        B[i][j] = (B[i][j]) - (m * B[k][j]);
      }
    }
    for (k = 0; k < n - 1; k++) {
      for (i = k + 1; i < n; i++) {
        m = B[i][k] / B[k][k];
        B[i][k] = 0;
        for (j = k + 1; j <= n; j++) {
          B[i][j] = (B[i][j]) - (m * B[k][j]);
        }
      }
      printf("\nMatriz após transformação em 0\n");
      for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j <= n; j++) {
          printf(" B=[%d][%d] = %2.2lf ", i, j, B[i][j]);
        }
      }
    }
  }

  /* Impressao Matriz escalonada */

  printf("\n Matriz escalonada.\n");
  for (i = 0; i < n; i++) {
    printf("\n");
    for (j = 0; j <= n; j++) {
      printf(" B=[%d][%d] = %2.2lf ", i, j, B[i][j]);
    }
  }

  fflush(stdin);
  getchar();

  /* Resolucao do sistema triangular */

  x[n - 1] = B[n - 1][n] / B[n - 1][n - 1];

  for (i = n - 2; i > -1; i--) {
    S = 0;
    for (k = i + 1; k < n; k++) {
      S = S + B[i][k] * x[k];
    }
    x[i] = (-S + B[i][n]) / B[i][i];
  }

  // verificação se o sistema é possível
  for (i = 0; i < n; i++) {
    if (isnan(x[i])) {
      printf("\nSistema Impossivel.\n");
      return 0;
    }
  }

  /* Impressao da solucao */

  printf("\n Solucao do sistema.\n");
  for (i = 0; i < n; i++) {
    printf(" x=[%d] = %2.2lf ", i, x[i]);
  }

  fflush(stdin);
  getchar();
}
