*This project has been created as part of the 42 curriculum by renatanu.*

# Criação do Projeto ft_printf

Porque `ft_putnbr()` e `ft_putstr()` não são suficientes.

## Descrição

O projeto **ft_printf** é um desafio fundamental no currículo da 42 que propõe ao estudante recodificar a famosa função `printf()` da biblioteca padrão do C. O objetivo principal é dominar o conceito de **funções variádicas** em C, compreendendo como gerenciar um número dinâmico e desconhecido de argumentos passados a uma única função durante a execução do programa.

Esta implementação mimetiza fielmente o comportamento original do `printf()`, suportando os principais especificadores de formato sem depender do gerenciamento interno de buffer da biblioteca padrão. O resultado final é compilado e encapsulado em uma biblioteca estática sob o nome `libftprintf.a`.

### Conversões Suportadas

A biblioteca processa com sucesso as seguintes conversões de formato:

* %c: Imprime um único caractere.
* %s: Imprime uma string (trata strings NULL exibindo a mensagem (null)).
* %p: Imprime um ponteiro do tipo void * no formato hexadecimal, precedido pelo prefixo 0x (trata ponteiros NULL exibindo a mensagem (nil)).
* %d: Imprime um número decimal (base 10).
* %i: Imprime um número inteiro em base 10.
* %u: Imprime um número decimal sem sinal (unsigned base 10).
* %x: Imprime um número no formato hexadecimal em letras minúsculas (base 16).
* %X: Imprime um número no formato hexadecimal em letras maiúsculas (base 16).
* %%: Imprime um caractere de porcentagem literal.

---

## Instruções

### Compilação

O projeto possui um arquivo Makefile estruturado e otimizado para compilar os arquivos fontes utilizando o compilador cc acompanhado das flags obrigatórias -Wall -Wextra -Werror. O arquivo foi configurado cuidadosamente para evitar o comportamento de relinking desnecessário.

Para compilar a biblioteca, execute o comando abaixo diretamente no terminal:
* make

Após a execução correta, o arquivo de biblioteca estática libftprintf.a será gerado na raiz do repositório.

### Regras do Makefile

* make all ou make: Compila os arquivos fontes e gera a biblioteca libftprintf.a.
* make clean: Apaga todos os arquivos objetos temporários (*.o).
* make fclean: Remove todos os arquivos objetos criados e também deleta a biblioteca gerada libftprintf.a.
* make re: Executa uma recompilação completa do projeto (equivalente a rodar fclean seguido de all).

### Como Utilizar

Para integrar a sua biblioteca ft_printf em outros projetos de C da 42, você deve incluir o arquivo de cabeçalho e lincar a biblioteca estática ao compilar seu programa:

1. Inclua o cabeçalho no seu arquivo.c:
#include "ft_printf.h"

2. Compile o seu programa referenciando o caminho da biblioteca:
cc main.c -L. -lftprintf -o meu_programa

---

## Abordagem Técnica e Justificativa do Algoritmo

### Estruturas de Dados

Dadas as restrições explícitas do projeto em especial a proibição do uso de gerenciamento de buffer do printf original—não houve a necessidade de empregar estruturas de dados dinâmicas ou complexas (como listas encadeadas ou arrays dinâmicos). A função opera iterando sobre a string base caractere por caractere, mantendo uma complexidade de espaço auxiliar de O(1) (desconsiderando a pilha de chamadas para funções recursivas).

### Algoritmo e Fluxo de Execução

1. Parsing da String de Formato: A função principal ft_printf varre a string format sequencialmente.

2. Detecção do Especificador: Ao encontrar o caractere %, o algoritmo analisa o caractere imediatamente seguinte (format[i + 1]) e direciona o fluxo para a função despachante interna ft_find_specifier.

3. Resgate dos Argumentos Variádicos: Dentro da função de checagem, a macro va_arg é invocada para extrair o próximo argumento do tipo va_list, baseando-se estritamente no tipo mapeado para aquele caractere (ex: int para %c, char * para %s, unsigned int para %x).

4. Conversões Recursivas:
* Para tipos numéricos (%d, %i, %u) e representações em bases hexadecimais (%x, %X, %p), utilizou-se uma lógica de redução matemática recursiva. Dividindo o número sucessivamente pela sua base (10 ou 16), as casas decimais são processadas do dígito mais significativo ao menos significativo, imprimindo os caracteres na saída padrão via write conforme a pilha de execução retorna.
* Essa escolha de design favorece o encapsulamento, a legibilidade do código e o estrito alinhamento com a Norma da 42, facilitando expansões futuras (como uma eventual adição de flags de bônus ou controle de largura de campo).

5. Controle de Contagem (Length Tracking): Todas as funções auxiliares foram projetadas para retornar a quantidade exata de caracteres exibidos com sucesso na tela. Esse valor é acumulado na variável len da função principal, garantindo que o retorno total do ft_printf reproduza perfeitamente o comportamento e as especificações exigidas na documentação da libc.

---

## Recursos

### Referências Clássicas

* Secrets of printf – Um guia aprofundado abordando toda a mecânica por trás das engrenagens do printf.
* Man va_start / va_arg – Manual oficial do Linux detalhando o tratamento de listas de argumentos variáveis.
* C Library - <stdarg.h> – Tutoriais didáticos sobre como manipular funções variádicas no padrão C.

### Uso de IA e Declaração de Transparência

Em total conformidade com as diretrizes do capítulo "AI Instructions" contidas no PDF oficial do projeto, o uso de ferramentas de Inteligência Artificial restringiu-se ao seguinte cenário:

* Geração de Documentação: A IA foi empregada unicamente para estruturar, organizar e traduzir tecnicamente este arquivo README.md, consolidando as informações da arquitetura das funções, regras do Makefile e objetivos pedagógicos da trilha. Nenhuma linha de lógica algorítmica ou código fonte do projeto foi concebida ou alterada por IA, salvaguardando o real aprendizado, o esforço cognitivo individual e o total entendimento exigido para a defesa durante a avaliação por pares (Peer-evaluation).