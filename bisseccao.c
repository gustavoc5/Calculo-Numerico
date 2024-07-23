// CMAC05 – Cálculo Numérico para Computação
// Exercicio Pratico 02 – 24/08/23
// 2022006185 – Gustavo Rafael Paulino
// 2022002112 - Pedro Junho Silveira
// Título do programa – metodo bissecção

#include <stdio.h>
#include <math.h>

double funcao(double x) {
    return 5*(x * x * x) - 5*(x * x) + 6*x -2;
}

int main() {
    double a, b, x, raiz, erro = 50;
    int count = 0;

    printf("Digite o valor para A e B: ");
    scanf("%lf %lf", &a, &b);
	printf("Digite o valor da raiz: ");
	scanf("%lf", &raiz);
	
    while (count < 50 && erro > 0.1*(b-a)) {
        double func = funcao(a);
        x = (a + b) / 2;
		erro = fabs(raiz - x);
        if (func * funcao(x) > 0) {
            a = x;
        } else {
            b = x;
        }
        count++;
    }

    x = (a + b) / 2; 
    printf("Raiz encontrada em: %lf\n", x);
    return 0;
}


