#define _USE_MATH_DEFINES
#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Definicao da estrutura da pilha
typedef struct
{
    double dados[100];
    char infixas[100][100];
    char posfixa[100];
    int topo;
} Pilha;

// Inicializa a pilha
void initPilha(Pilha *p)
{
    p->topo = -1;         // inicializa o topo da pilha como -1
    p->posfixa[0] = '\0'; // inicializa a string pos-fixa como vazia
}

// Verifica se a pilha esta vazia
int vazia(Pilha *p)
{
    return p->topo == -1;
}

// Verifica se a pilha esta cheia
int cheia(Pilha *p)
{
    return p->topo == 99;
}

// Empilha um elemento
void empilha(Pilha *p, double valor, const char *infixa, const char *token)
{
    if (cheia(p))
    {
        printf("Erro: Pilha cheia.\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = valor; // armazena o valor no topo da pilha
    strcat(p->posfixa, token); // concatena o token na expressao pos-fixa completa
    strcat(p->posfixa, " ");
    strcpy(p->infixas[p->topo], infixa); // armazena a expressao infixa no topo da pilha
}

// Desempilha um elemento
double desempilha(Pilha *p, char *infixa)
{
    if (vazia(p))
    {
        printf("Erro: Pilha vazia.\n");
        return 0;
    }
    double valor = p->dados[p->topo];    // recupera o valor do topo da pilha
    strcpy(infixa, p->infixas[p->topo]); // recupera a expressao infixa do topo da pilha
    p->topo--;
    return valor;
}

// Avalia a expressao em notacao pos-fixada
double processarExpressao(char *expressao, char *infixaFinal, char *posfixaCompleta)
{
    Pilha p;
    initPilha(&p); // inicializa a pilha
    char *token = strtok(expressao, " ");
    while (token != NULL)
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            double valor = atof(token);
            sprintf(infixaFinal, "%.2lf", valor); // converte o valor numerico para string diretamente
            empilha(&p, valor, infixaFinal, token);
        }
        else
        {
            if (strlen(token) == 1)
            {
                char infixa2[100], infixa1[100];
                double numero2 = desempilha(&p, infixa2); // desempilha o segundo operando
                double numero1 = desempilha(&p, infixa1); // desempilha o primeiro operando
                double resultado;
                char novaInfixa[100];
                switch (token[0])
                {
                case '+':
                    resultado = numero1 + numero2;
                    sprintf(novaInfixa, "(%s + %s)", infixa1, infixa2);
                    break;
                case '-':
                    resultado = numero1 - numero2;
                    sprintf(novaInfixa, "(%s - %s)", infixa1, infixa2);
                    break;
                case '*':
                    resultado = numero1 * numero2;
                    sprintf(novaInfixa, "(%s * %s)", infixa1, infixa2);
                    break;
                case '/':
                    if (numero2 == 0)
                    {
                        printf("Erro: Divisao por zero.\n");
                        return 0;
                    }
                    resultado = numero1 / numero2;
                    sprintf(novaInfixa, "(%s / %s)", infixa1, infixa2);
                    break;
                case '^':
                    resultado = pow(numero1, numero2);
                    sprintf(novaInfixa, "(%s ^ %s)", infixa1, infixa2);
                    break;
                default:
                    printf("Erro: Operador invalido.\n");
                    return 0;
                }
                empilha(&p, resultado, novaInfixa, token); // empilha o resultado, a nova expressao infixa e o pos-fixo
            }
            else
            { // operacao unaria
                char infixa[100];
                double numero = desempilha(&p, infixa);
                double resultado;
                char novaInfixa[100];
                if (strcmp(token, "log") == 0)
                {
                    resultado = log10(numero);
                    sprintf(novaInfixa, "log(%s)", infixa);
                }
                else if (strcmp(token, "sen") == 0)
                {
                    resultado = sin(numero * M_PI / 180);
                    sprintf(novaInfixa, "sen(%s)", infixa);
                }
                else if (strcmp(token, "cos") == 0)
                {
                    resultado = cos(numero * M_PI / 180);
                    sprintf(novaInfixa, "cos(%s)", infixa);
                }
                else if (strcmp(token, "tg") == 0)
                {
                    resultado = tan(numero * M_PI / 180);
                    sprintf(novaInfixa, "tg(%s)", infixa);
                }
                else if (strcmp(token, "raiz") == 0)
                {
                    resultado = sqrt(numero);
                    sprintf(novaInfixa, "raiz(%s)", infixa);
                }
                else
                {
                    printf("Erro: Operador invalido.\n");
                    return 0;
                }
                empilha(&p, resultado, novaInfixa, token); // empilha o resultado, a nova expressao infixa e pos-fixo
            }
        }
        token = strtok(NULL, " ");
    }

    double resultadoFinal = desempilha(&p, infixaFinal); // retorna o resultado da expressao
    strcpy(posfixaCompleta, p.posfixa);                  // copia a expressao pos-fixa completa

    return resultadoFinal;
}

char *getFormaInFixa(char *Str)
{
    static char infixaFinal[512];
    char copia[512];
    strcpy(copia, Str);
    processarExpressao(copia, infixaFinal, Str);
    return infixaFinal;
}

float getValor(char *Str)
{
    char infixaFinal[512];
    char copia[512];
    strcpy(copia, Str);
    return processarExpressao(copia, infixaFinal, Str);
}