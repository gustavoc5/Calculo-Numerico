#include<stdio.h>
//Resolucao de Sistemas lineares pelo metodo de interpolação de Newton

void main()
{
    double x[10], y[10], p[10], k;
    int n,i,j=1;
    double f,f1=1,f2=0;
    printf("Entre com o valor de n:\n");
    scanf("%d", &n);

    printf("Entre com os valore de x:\n");
    for (i=1;i<=n;i++)
        scanf("%lf", &x[i]);

    printf("Entre com os valores correspondentes de y:\n");
    for (i=1;i<=n;i++)
        scanf("%lf", &y[i]);

    f=y[1];
    printf("Entre com o valor de x que deseja encontrar o y:\n");
    scanf("%lf", &k);

    while(n!=1){
        for (i=1;i<=n-1;i++)
        {
            p[i] = ((y[i+1]-y[i])/(x[i+j]-x[i]));
            y[i]=p[i];
        }
        f1=1;
        for(i=1;i<=j;i++)
            {
                f1*=(k-x[i]);
            }
        f2+=(y[1]*f1);
        n--;
        j++;
    }

    f+=f2;
    printf("f(%lf) = %lf", k , f);
    getch();
}