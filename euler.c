// Calulo Numérico para Computação - Exercicio Prático 11
// Gustavo Rafael Paulino – 2022006185 
// Bruno Gonzalez Flores - 2022008591
// Data: 21/11/2023
// Euler simples

#include <stdio.h>

// Função para a derivada de y
double derivada(double x, double y) { return (x-y)/x; }

// Método de Euler
double euler(double x0, double y, double h, double x) {
  while (x0 < x) {
    y = y + h * derivada(x0, y);
    x0 = x0 + h;
  }
  return y;
}

int main() {
  double x0 = 2, y0 = 2, x, h, y;
  int n;

  printf("Digite o valor de b: ");
  scanf("%lf", &x);

  printf("Digite a quantidade de subintervalos n: ");
  scanf("%d", &n);
	// tamanho do passo
  h = (x - x0) / n;

  y = euler(x0, y0, h, x);

  printf("b = %.2lf, n = %d, y(b) = %.4lf\n", x, n, y);

  return 0;
}
