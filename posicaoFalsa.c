// CMAC05 – Cálculo Numérico para Computação
// Exercicio Pratico 02 – 24/08/23
// 2022006185 – Gustavo Rafael Paulino
// 2022002112 - Pedro Junho Silveira
// Título do programa – metodo ponto falso

#include <stdio.h>
#include <math.h>

double funcao(double x) {
    return (9.81*x*(1-exp(-(15/x)*9))/15)-35;
}

int main() {
    double a, b, x, raiz, erro = 50;
    int count = 0;

    printf("Digite o valor para A e B: ");
    scanf("%lf %lf", &a, &b);
		printf("Digite o valor da raiz: ");
	  scanf("%lf", &raiz);

    while (erro > 0.0001*(b-a)) {
        x = (a * funcao(b) - b * funcao(a)) / (funcao(b) - funcao(a));
				erro = fabs(raiz - x);
        if (funcao(a) * funcao(x) > 0) {
            a = x;
        } else {
            b = x;
        }

        count++;
    }
    printf("Raiz encontrada em: %lf\n", x);
    return 0;
}
