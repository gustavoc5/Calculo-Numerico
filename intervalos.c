// CMAC05 – Cálculo Numérico para Computação
// Exercicio Pratico 02 – 24/08/23
// 2022006185 – Gustavo Rafael Paulino
// 2022002112 - Pedro Junho Silveira
// Título do programa – metodo localiza raizes
#include <stdio.h>
#include <math.h>

double funcao(double x) {
    return 5*(x * x * x) - 5*(x * x) + 6*x -2;
}

int main(){
    double limiteInferior, limiteSuperior, passo;
    int raizes = 0;

    printf("Digite o limite inferior: ");
    scanf("%lf", &limiteInferior);
    printf("Digite o limite superior: ");
    scanf("%lf", &limiteSuperior);
    printf("Digite o passo: ");
    scanf("%lf", &passo);

    double intervaloAtual = limiteInferior;
    while (intervaloAtual <= limiteSuperior) {
        double valorInicial = intervaloAtual;
        double valorFinal = intervaloAtual + passo;

        if (funcao(valorInicial) * funcao(valorFinal) <= 0) {
            raizes++;
            printf("Raiz encontrada no intervalo: (%lf, %lf)\n", valorInicial, valorFinal);
        }

        intervaloAtual += passo;
    }

    printf("Total de raizes encontradas: %d\n", raizes);

    return 0;
}
