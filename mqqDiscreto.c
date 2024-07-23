// CMAC05 – Cálculo Numérico para Computação
// Exercicio Pratico 08 – 31/10/2023
// 2022000314 - Alejandro Macha Paiva
// 2022006185 - Gustavo Rafael Paulino
// Método dos Mínimos quadrados (caso discreto)

#include <stdio.h>

// aqui definimos os valores arbitrários
//
#define g1(x) (x)             // Referente a ax em (a.x + b)
#define g2(x) (3)             // Referente a b  em (a.x + b)

int main() {
    FILE *txt;
    char nomearquivo[10];
    double fx[10], x[10], matriz[2][3], coef[2], pivo;
    int n, i;


    // Recebemos o arquivo
    //
    scanf("%s", nomearquivo);
    txt = fopen( nomearquivo, "r");

    // Recebemos o número de elementos
    //
    fscanf(txt, "%d", &n);

    for(i = 0; i < n; i++){
        fscanf(txt, "%lf %lf", &x[i], &fx[i]);
    }

    // Aqui iremos adicionar em todos os elementos da matriz o somatório
    // a cada iteração, para não ter que fazer um loop para cada indice.
    //
    for(i = 0; i < n; i++){
        matriz[0][0] += g1(x[i]) * g1(x[i]);      // para a11
        matriz[0][1] += g1(x[i]) * g2(x[i]);      // para a12 = a21
        matriz[0][2] += fx[i] * g1(x[i]);         // para a13 (termo independente)
        matriz[1][1] += g2(x[i]) * g2(x[i]);      // para a22
        matriz[1][2] += fx[i] * g2(x[i]);         // para a23 (termo independente)
    }

    // Como a12 = a21, omitimos suas somas anteriormente para que agora que finalizada
    // possâmos só repassar seu valor.
    //
    matriz[1][0] = matriz[0][1];

    // Já temos o sistema montado, devemos solucioná-lo para encontrar a e b.
    // Usaremos Eliminação Gaussiana.
    //
    pivo = matriz[1][0] / matriz[0][0];
    for(i = 0; i < 3; i++) {
        matriz[1][i] -= pivo * matriz[0][i];
    }

    // Resolvemos o sistema triangularizado
    //
    coef[1] = matriz[1][2] / matriz[1][1];
    coef[0] = (matriz[0][2] - matriz[0][1] * coef[1]) / matriz[0][0];

    // Podemos printar o valor de a e b.
    //
    printf("\nEquacao: p(x) = %lf + %lf.x\n",coef[1], coef[0]);
    return 0;
}

