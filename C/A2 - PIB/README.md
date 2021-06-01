<!-- TABLE OF CONTENTS -->

## Tabela de Conteúdo

- [Tabela de Conteúdo](#tabela-de-conte%C3%BAdo)
- [Sobre o Projeto](#sobre-o-projeto)
  - [Feito Com](#feito-com)
- [Começando](#come%C3%A7ando)
  - [Pré-requisitos](#pr%C3%A9-requisitos)
  - [Estrutura de Arquivos](#estrutura-de-arquivos)
  - [Edição](#edi%C3%A7%C3%A3o)
- [Contato](#contato)
### Estrutura de Arquivos

<!-- ABOUT THE PROJECT -->

## Sobre o Projeto

Este projeto visa a criação de um programa que gere relatorios do PIB do brasil nos ultimos 50 anos, utilizando quick sort, vetores e entrada de arquivos com dados.
Os dados foram pegados apartir deste [link](https://infograficos.gazetadopovo.com.br/economia/pib-do-brasil/)

### Feito Com

Abaixo segue o que foi utilizado na criação deste projeto:
- Linguagem C.
- Compiler gcc para vsCode.

### Pré-requisitos

Verifique se o compilador do seu computador roda a versao C11 ou C12 da linguagem C.:

## Começando

Para conseguir rodar o projeto basta compilar o arquivo `main.c` na raiz do projeto e assim gerando um .exe.

A estrutura de arquivos está da seguinte maneira:
```bash
Root
├── assets/
│   └── economy.txt
├── core/
│   ├── shared/
│   │   ├── binary_search/
│   │   │   ├── header.h
│   │   │   └── main.c
│   │   ├── file_control/
│   │   │   ├── header.h
│   │   │   └── main.c
│   │   ├── menu/
│   │   │   ├── header.h
│   │   │   └── main.c
│   │   └── quick_sort/
│   │       ├── header.h
│   │       └── main.c
│   ├── header.h
│   └── main.c
├── main.c
└── README.md
```

### Edição

Nesta seção haverão instruções caso você queira editar o projeto, explicando para que os diretórios são utilizados e também os arquivos de configuração.

- **assets** - Diretório contendo todos os arquivos de dados para entrada e tambem os arquivos gerados pelo projeto;
- **core** - Diretório contendo todos os arquivos da aplicação, é criado um diretório `core` para que o código da aplicação possa ser isolado em um diretório e facilmente portado para o main principal, deixando a main principal mais limpa;
    - **shared** - Contem todo o codigo compartilhado e generico, ou seja, todas as funções genericas como abrir arquivos, gerar arquivos, organizar arrays, menu, vasculha array e etc.
- **header.h** - Arquivo de cabeçalho, é nele que se inicia cria as inicializações de funções, e variaveis globais.
- **main.c** - Arquivo principal, é nele que se inicia e compila todo o projeto.

## Contatos
- Daniel Henrique de Assi RA: 108878
- Lucas Bevilaqua RA: 110601
- Nicolas Gomes RA: 109181
