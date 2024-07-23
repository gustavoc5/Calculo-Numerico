#include <math.h>
#include <stdio.h>

// função a ser integrada
double funcao(double x) { 
	return x*pow(exp(1), x) + 1; 
}

// funcao que calcula a integral pelo metodo de simpson generalizada
double integralSimpsonGeneralizada(double a, double b, int n) {
  double h = (b - a) / (2 * n);
  double soma = funcao(a) + funcao(b);
	double x_i;
	int i;
	
  for (i = 1; i < 2 * n; ++i) {
    x_i = a + i * h;
    soma += (i % 2 == 0) ? 2 * funcao(x_i) : 4 * funcao(x_i);
  }

  return (h / 3) * soma;
}

// funcao que calcula o erro
double calculaErro(double a, double b, int n) {
  double h = (b - a) / (2 * n);
  double M4 = 140.5988; // valor máximo da quarta derivada da função dentro do intervalo [a, b]

  return (pow(h, 4) /180) * (b - a) * M4;
}

int main() {
  double a, b, integral, erro;
  int n;

  // leitura dos limites de integração e quantidade de subintervalos
  printf("Digite o limite inferior (a): ");
  scanf("%lf", &a);
  printf("Digite o limite superior (b): ");
  scanf("%lf", &b);
  printf("Digite a quantidade de subintervalos (n): ");
  scanf("%d", &n);

  // calculo da integral
  integral = integralSimpsonGeneralizada(a, b, n);

  // calculo do erro
  erro = calculaErro(a, b, n);

  // impressão dos resultados
  printf("Valor da integral (ISGEN): %lf\n", integral);
  printf("Erro cometido (ESGEN): %lf\n", erro);

  return 0;
}
