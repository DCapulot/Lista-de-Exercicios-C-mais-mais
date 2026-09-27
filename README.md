# 📚 Sistema de Cadastro de Alunos em C

Projeto desenvolvido em linguagem **C** com o objetivo de praticar conceitos fundamentais de programação, como estruturas (`struct`), funções, vetores, strings, validação de dados e entrada de informações pelo usuário.

## 📌 Sobre o projeto

O programa permite cadastrar **5 alunos**, armazenando as seguintes informações:

* Nome
* CPF
* Telefone
* Endereço

Após realizar todos os cadastros, o programa exibe os dados dos alunos cadastrados.

O projeto também possui validação e formatação de CPF e telefone.

---

## 🚀 Funcionalidades

### 👤 Cadastro de alunos

Para cada aluno são solicitados:

```text
Nome
CPF
Telefone
Endereço
```

### 🪪 Validação de CPF

O programa verifica:

* Se o CPF possui 11 dígitos;
* Se todos os caracteres são numéricos;
* Se o CPF não possui todos os números iguais;
* Se os dois dígitos verificadores estão corretos.

O CPF é exibido no formato:

```text
123.456.789-09
```

### 📱 Validação de telefone

O programa aceita telefones com:

* 10 dígitos — telefone fixo;
* 11 dígitos — telefone celular.

Exemplos:

```text
(21) 1234-5678
(21) 99999-9999
```

### 📋 Exibição dos dados

Depois dos cadastros, todos os alunos são exibidos no terminal.

---

## 🛠️ Tecnologias utilizadas

* **C**
* `stdio.h`
* `stdlib.h`
* `string.h`
* `ctype.h`

---

## 📂 Estrutura do projeto

```text
cadastro-alunos/
│
├── main.c
└── README.md
```

---

## 💻 Como executar

### 1. Clone o repositório

```bash
git clone https://github.com/SEU-USUARIO/cadastro-alunos.git
```

Entre na pasta:

```bash
cd cadastro-alunos
```

### 2. Compile o programa

Caso esteja utilizando o GCC:

```bash
gcc main.c -o cadastro
```

### 3. Execute

No Linux ou macOS:

```bash
./cadastro
```

No Windows:

```bash
cadastro.exe
```

---

## 🖥️ Exemplo de execução

```text
========================================
       SISTEMA DE CADASTRO DE ALUNOS
========================================

Cadastro do aluno 1 de 5
----------------------------------------
Nome: João da Silva
CPF (11 digitos numericos): 12345678909
Telefone (10 ou 11 digitos numericos): 21999999999
Endereco: Rua das Flores, 100

...

========================================
          ALUNOS CADASTRADOS
========================================

Aluno 1
----------------------------------------
Nome:      João da Silva
CPF:       123.456.789-09
Telefone:  (21) 99999-9999
Endereco:  Rua das Flores, 100
```

---

## 🧠 Conceitos praticados

Este projeto foi desenvolvido para praticar:

* Variáveis;
* Tipos de dados;
* Estruturas `struct`;
* Vetores;
* Strings;
* Funções;
* `fgets`;
* `strlen`;
* `strchr`;
* `isdigit`;
* Estruturas de repetição;
* Estruturas condicionais;
* Validação de dados;
* Formatação de strings;
* Manipulação do buffer de entrada.

---

## 🔒 Validação dos dados

O programa não aceita:

* Nome vazio;
* Endereço vazio;
* CPF com quantidade incorreta de dígitos;
* CPF com caracteres não numéricos;
* CPF inválido de acordo com os dígitos verificadores;
* CPF formado pelo mesmo dígito repetido;
* Telefone com quantidade diferente de 10 ou 11 dígitos;
* Telefone contendo caracteres não numéricos.

---

## 🎯 Objetivo

O objetivo principal deste projeto é desenvolver familiaridade com a linguagem C e com a organização de pequenos sistemas utilizando funções e estruturas de dados.

Este projeto pode servir como base para futuras implementações, como:

* Cadastro de quantidade variável de alunos;
* Busca de alunos;
* Alteração de dados;
* Exclusão de alunos;
* Menu interativo;
* Persistência dos dados em arquivos;
* Sistema de login;
* Utilização de banco de dados.

---

## 👨‍💻 Autor

Desenvolvido por **SEU NOME**.

📌 GitHub: `https://github.com/SEU-USUARIO`

---

## 📄 Licença

Este projeto foi desenvolvido para fins educacionais.
