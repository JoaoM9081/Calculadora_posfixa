#include "calculadora.h"
#include <stdio.h>
#include <string.h>

int main()
{
    // Expressoes fornecidas
    char *Testes[] = {
        "3 4 + 5 *",
        "7 2 * 4 +",
        "8 5 2 4 + * +",
        "6 2 / 3 + 4 *",
        "9 5 2 8 * 4 + * +",
        "2 3 + log 5 /",
        "10 log 3 ^ 2 +",
        "45 60 + 30 cos *",
        "0.5 45 sen 2 ^ +"};

    int numExpressoes = sizeof(Testes) / sizeof(Testes[0]);

    for (int i = 0; i < numExpressoes; i++)
    {
        Expressao expr;
        strcpy(expr.posFixa, Testes[i]);
        expr.valor = getValor(expr.posFixa);
        strcpy(expr.inFixa, getFormaInFixa(expr.posFixa));

        printf("Teste: %d\n", i + 1);
        printf("Expressao pos-fixa: %s\n", expr.posFixa);
        printf("Expressao infixa: %s\n", expr.inFixa);
        printf("Valor: %.2f\n\n", expr.valor);
    }

    return 0;
}