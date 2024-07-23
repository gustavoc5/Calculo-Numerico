#include<stdio.h>

#define MAX 10

float lagrange_interpolation(float x[], float fx[], int n, float value) {
    float sum = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        float product = fx[i];
        for (j = 0; j < n; j++) {
            if (i != j) {
                product *= (value - x[j]) / (x[i] - x[j]);

            }
        }
                        printf("%.4f\n", product);
        sum += product;
    }

    return sum;
}

void print_lagrange_polynomial(float x[], float fx[], int n) {
    int i, j;

    printf("O polinômio interpolador de Lagrange é:\n");

    for (i = 0; i < n; i++) {
        printf("(%f)", fx[i]);
        for (j = 0; j < n; j++) {
            if (i != j) {
                printf(" * (x - %f)/(%f - %f)", x[j], x[i], x[j]);
            }
        }
        if (i != n-1) {
            printf(" +\n");
        }
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    float x[MAX], fx[MAX], value;
    int n, i;
    FILE *file;

    if (argc != 2) {
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(file, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(file, "%f %f", &x[i], &fx[i]);
    }

    fscanf(file, "%f", &value);

    fclose(file);

    print_lagrange_polynomial(x, fx, n);

    float result = lagrange_interpolation(x, fx, n, value);

    printf("O valor interpolado de g(x) é: %.2f\n", result);

    return 0;
}
