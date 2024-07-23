#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcao(double x){
    return pow(x,3) - 9*x + 5;
}

int main()
{
    double x0, x1, x2, precisao1, precisao2, raiz;
    int c = 1;
    int iteracoes;
	
    printf("Entre com as aproximacoes iniciais: ");
    scanf("%lf %lf",&x0,&x1);
    printf("Entre com a primeira precisao: ");
    scanf("%lf",&precisao1);
    printf("Entre com a segunda precisao: ");
    scanf("%lf",&precisao2);
    printf("Digite a quantidade máxima de iteracoes: ");
    scanf("%d",&iteracoes);
    printf("\n\n");

		if (fabs(funcao(x0)) < precisao1){
			raiz = x0;
			printf("Raiz encontrada em: %.3lf\nQuantidade de iteracoes: %d\n",raiz,c);
			return 0;
		}
		if (fabs(funcao(x1)) < precisao1 || fabs(x1-x0) < precisao2){
			raiz = x1;
			printf("Raiz encontrada em: %.3lf\nQuantidade de iteracoes: %d\n",raiz,c);
			return 0;
		}
		x2 = x1 - (funcao(x1)/(funcao(x1)-funcao(x0))) * (x1-x0);
		while(fabs(funcao(x2)) > precisao1 && fabs(x2-x1) > precisao2 && c < iteracoes) {
			x0 = x1;
			x1 = x2;
			c++;
			x2 = x1 - (funcao(x1)/(funcao(x1)-funcao(x0))) * (x1-x0);
		}
		raiz = x2;
		
    printf("Raiz encontrada em: %.5lf\nQuantidade de iteracoes: %d\n",x2,c);
    return 0;
}