#include <math.h>
#include <stdio.h>

// funcao a ser integrada
double funcao(double x) { 
	return 4 * pow(x, 3); 
}

// funcao que calcula a integral pelo metodo do trapezio generalizada
double integralTrapezioGeneralizada(double a, double b, int n) {
  double h = (b - a) / n;
  double soma = funcao(a) + funcao(b);
	double x_i;
	int i;

  for (i = 1; i < n; ++i) {
    x_i = a + i * h;
    soma += 2 * funcao(x_i);
  }
	
  return (h/2) * soma;
}

// funcao que calcula o erro
double calculaErro(double a, double b, int n) {
  double h = (b - a) / n;
  double M2 = 48; // valor máximo da segunda derivada da função dentro do intervalo [a, b]

  return (pow(h, 2) / 12) * (b - a) * M2;
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
  integral = integralTrapezioGeneralizada(a, b, n);

  // calculo do erro
  erro = calculaErro(a, b, n);

  // impressão dos resultados
  printf("Valor da integral (ITGEN): %lf\n", integral);
  printf("Erro cometido (ETGEN): %lf\n", erro);

  return 0;
}
