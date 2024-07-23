// Calulo Numérico para Computação - Exercicio Prático 11
// Gustavo Rafael Paulino – 2022006185 
// Bruno Gonzalez Flores - 2022008591
// Data: 21/11/2023
// Euler estendido

#include <stdio.h>
#include <math.h>

// Função para a derivada de y
double derivada(double x, double y) { return y; }

// Método de Euler estendido
double eulerEstendido(double x0, double y, double h, double x) {
	int count = 0;
  while (x0 < x) {
		y  = y*(1 + h + (pow(h, 2)/2));
    x0 = x0 + h;
  }
  return y;
}

int main() {
  double x0 = 0, y0 = 1, x, h, y;
  int n;

  printf("Digite o valor de b: ");
  scanf("%lf", &x);

  printf("Digite a quantidade de subintervalos n: ");
  scanf("%d", &n);
	// tamanho do passo
  h = (x - x0) / n;

  y = eulerEstendido(x0, y0, h, x);

  printf("b = %.2lf, n = %d, y(b) = %.4lf\n", x, n, y);

  return 0;
}
