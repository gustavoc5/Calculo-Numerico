#include<stdio.h>

#define MAX 10

void newton_interpolation(float x[], float fx[], int n, float value) {
    float diff[MAX][MAX];
    int i, j;
    float product, sum;

    for (i = 0; i < n; i++) {
        diff[i][0] = fx[i];
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j < n-i; j++) {
            diff[j][i] = (diff[j+1][i-1] - diff[j][i-1]) / (x[i+j] - x[j]);
        }
    }

    sum = diff[0][0];
    for (i = 1; i < n; i++) {
        product = 1;
        for (j = 0; j < i; j++) {
            product *= (value - x[j]);
        }
        product *= diff[0][i];
        sum += product;
    }

    printf("O valor interpolado de f(x) é: %.2f\n", sum);
}

void print_newton_polynomial(float x[], float fx[], int n) {
    float diff[MAX][MAX];
    int i, j;

    for (i = 0; i < n; i++) {
        diff[i][0] = fx[i];
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j < n-i; j++) {
            diff[j][i] = (diff[j+1][i-1] - diff[j][i-1]) / (x[i+j] - x[j]);
        }
    }

    printf("O polinômio interpolador de Newton é:\n");

    for (i = 0; i < n; i++) {
        printf("(%f)", diff[0][i]);
        for (j = 0; j < i; j++) {
            printf(" * (x - %f)", x[j]);
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

    print_newton_polynomial(x, fx, n);

    newton_interpolation(x, fx, n, value);

    return 0;
}
