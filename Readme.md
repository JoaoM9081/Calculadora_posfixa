# Calculadora Pós-fixa

Este projeto é uma calculadora pós-fixa desenvolvida para a disciplina de Estrutura de Dados. A calculadora recebe expressões em notação pós-fixa como entrada, converte-as para notação infixa e calcula seus valores. O projeto é implementado em C e demonstra o uso de estruturas de dados de pilha.

## Introdução

A calculadora pós-fixa é projetada para:

- Avaliar expressões matemáticas fornecidas em notação pós-fixa.
- Converter expressões pós-fixas para sua notação infixa equivalente.
- Lidar com várias operações, incluindo adição, subtração, multiplicação, divisão, potenciação e funções trigonométricas.

## Funcionalidades

- **Conversão de Pós-fixa para Infixa**: Converte expressões pós-fixas para notação infixa.
- **Avaliação de Expressões**: Calcula o valor de expressões pós-fixas.
- **Suporte para Operações Unárias**: Inclui suporte para funções como logaritmo, seno, cosseno, tangente e raiz quadrada.
- **Tratamento de Erros**: Lida com erros como divisão por zero e operadores inválidos.

## Visão Geral do Código

### `main.c`

Este arquivo contém a função principal que:

- Define um conjunto de expressões de teste em notação pós-fixa.
- Itera por cada expressão de teste, convertendo-a para notação infixa e avaliando seu valor.
- Imprime a expressão pós-fixa, seu equivalente infixo e o valor calculado.

### `calculadora.h`

Este arquivo de cabeçalho define a struct `Expressao` e declara as funções para conversão e avaliação de expressões:

- `getFormaInFixa`: Converte uma expressão pós-fixa para notação infixa.
- `getValor`: Avalia o valor de uma expressão pós-fixa.

### `calculadora.c`

Este arquivo contém a implementação da calculadora pós-fixa baseada em pilha:

- Define a estrutura da pilha e suas operações.
- Implementa a função `processarExpressao` para processar expressões pós-fixas.
- Fornece as funções `getFormaInFixa` e `getValor` conforme especificado no arquivo de cabeçalho.

## Pré-requisitos

Para compilar e executar este projeto, você precisa de:

- Um compilador C (por exemplo, gcc).

## Clonando o Repositório e Executando

Para clonar o repositório e executar o projeto, siga estes passos:

### 1. Clonar o Repositório

```sh
git clone https://github.com/JoaoM9081/Calculadora_posfixa.git
```

### 3. Compilar projeto

```sh
gcc main.c calculadora.c -o calculadora -lm
```

### 3. Executar o Projeto

```sh
.\'calculadora.exe'
```

## Contribuidores

Este projeto foi desenvolvido pelos seguintes membros da equipe:

- **Integrante 1**: João Marcos Azevedo Cruz
- **Integrante 2**: Marcos André Barros Meneses
- **Integrante 3**: Paulo Eduardo
- **Integrante 4**: João Victor Martins