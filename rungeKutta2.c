#include <stdio.h>
#include <math.h>

// Função que representa a equação diferencial
double f(double x, double y) {
		// Substitua esta função pela sua equação diferencial
		return x - y + 2;
}

// Função que implementa o método de Runge-Kutta de 2ª ordem
double rungeKutta(double x, double x0, double y0, double h) {
		double k1, k2;

		// Cálculo do primeiro coeficiente
		k1 = h * f(x0, y0);

		// Cálculo do segundo coeficiente
		k2 = h * f(x0 + h, y0 + k1);

		// Atualização da aproximação y(x)
		double y1 = y0 + 0.5 * (k1 + k2);

		return y1;
}

int main() {
		// Valores iniciais
		double x0, y0, x, h;
		int n;
		printf("Informe o valor inicial de x e y: ");
		scanf("%lf %lf", &x0, &y0);
	
		// Aproximação desejada de x
		printf("Informe a aproximação desejada de x: ");
		scanf("%lf", &x);

		// Tamanho do passo
		// printf("Informe o valor de h: ");
		// scanf("%lf", &h);

		// Numero de subintervalos
		printf("Informe o número de subintervalos n: ");
		scanf("%d", &n);

		h = (x-x0)/n;
		// Iterações do método de Runge-Kutta até atingir a aproximação desejada
		while (x0 < x) {
				y0 = rungeKutta(x, x0, y0, h);
				x0 += h;
		}

		// Resultado final
		printf("A aproximação de y(%.2lf) é %.6lf\n", x, y0);

		return 0;
}
