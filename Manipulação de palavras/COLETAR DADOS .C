```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 5

struct Aluno {
    char nome[100];
    char cpf[15];
    char telefone[20];
    char endereco[200];
};

/* Remove o '\n' deixado pelo fgets */
void removerNovaLinha(char *str) {
    size_t len = strlen(str);

    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

/* Limpa caracteres restantes no buffer de entrada */
void limparBuffer(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

/* Lê uma string com segurança */
void lerString(char *campo, int tamanho, const char *mensagem) {
    do {
        printf("%s", mensagem);

        if (fgets(campo, tamanho, stdin) == NULL) {
            printf("\nErro ao ler a entrada.\n");
            exit(EXIT_FAILURE);
        }

        if (strchr(campo, '\n') != NULL) {
            removerNovaLinha(campo);
        } else {
            limparBuffer();
        }

        if (strlen(campo) == 0) {
            printf("Este campo nao pode ficar vazio.\n");
        }

    } while (strlen(campo) == 0);
}

/* Verifica se o CPF possui exatamente 11 dígitos */
int validarCPF(char *cpf) {
    if (strlen(cpf) != 11) {
        return 0;
    }

    for (int i = 0; i < 11; i++) {
        if (!isdigit((unsigned char)cpf[i])) {
            return 0;
        }
    }

    /* Rejeita CPFs com todos os dígitos iguais */
    int iguais = 1;

    for (int i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            iguais = 0;
            break;
        }
    }

    if (iguais) {
        return 0;
    }

    /* Calcula o primeiro dígito verificador */
    int soma = 0;

    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }

    int resto = soma % 11;
    int digito1 = (resto < 2) ? 0 : 11 - resto;

    if (digito1 != cpf[9] - '0') {
        return 0;
    }

    /* Calcula o segundo dígito verificador */
    soma = 0;

    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }

    resto = soma % 11;
    int digito2 = (resto < 2) ? 0 : 11 - resto;

    if (digito2 != cpf[10] - '0') {
        return 0;
    }

    return 1;
}

/* Formata o CPF para o padrão 000.000.000-00 */
void formatarCPF(char *cpf, char *cpfFormatado) {
    sprintf(
        cpfFormatado,
        "%c%c%c.%c%c%c.%c%c%c-%c%c",
        cpf[0], cpf[1], cpf[2],
        cpf[3], cpf[4], cpf[5],
        cpf[6], cpf[7], cpf[8],
        cpf[9], cpf[10]
    );
}

/* Captura e valida o CPF */
void capturarCPF(char *cpfFormatado) {
    char cpf[20];

    do {
        printf("CPF (11 digitos numericos): ");

        if (fgets(cpf, sizeof(cpf), stdin) == NULL) {
            printf("\nErro ao ler o CPF.\n");
            exit(EXIT_FAILURE);
        }

        if (strchr(cpf, '\n') != NULL) {
            removerNovaLinha(cpf);
        } else {
            limparBuffer();
        }

        if (!validarCPF(cpf)) {
            printf("CPF invalido. Tente novamente.\n");
        }

    } while (!validarCPF(cpf));

    formatarCPF(cpf, cpfFormatado);
}

/* Valida telefone com 10 ou 11 dígitos */
int validarTelefone(char *telefone) {
    int len = strlen(telefone);

    if (len != 10 && len != 11) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isdigit((unsigned char)telefone[i])) {
            return 0;
        }
    }

    return 1;
}

/* Formata telefone fixo ou celular */
void formatarTelefone(char *telefone, char *telefoneFormatado) {
    int len = strlen(telefone);

    if (len == 10) {
        sprintf(
            telefoneFormatado,
            "(%c%c) %c%c%c%c-%c%c%c%c",
            telefone[0], telefone[1],
            telefone[2], telefone[3],
            telefone[4], telefone[5],
            telefone[6], telefone[7],
            telefone[8], telefone[9]
        );
    } else {
        sprintf(
            telefoneFormatado,
            "(%c%c) %c%c%c%c%c-%c%c%c%c",
            telefone[0], telefone[1],
            telefone[2], telefone[3],
            telefone[4], telefone[5],
            telefone[6],
            telefone[7], telefone[8],
            telefone[9], telefone[10]
        );
    }
}

/* Captura e valida o telefone */
void capturarTelefone(char *telefoneFormatado) {
    char telefone[20];

    do {
        printf("Telefone (10 ou 11 digitos numericos): ");

        if (fgets(telefone, sizeof(telefone), stdin) == NULL) {
            printf("\nErro ao ler o telefone.\n");
            exit(EXIT_FAILURE);
        }

        if (strchr(telefone, '\n') != NULL) {
            removerNovaLinha(telefone);
        } else {
            limparBuffer();
        }

        if (!validarTelefone(telefone)) {
            printf("Telefone invalido. Digite apenas 10 ou 11 digitos.\n");
        }

    } while (!validarTelefone(telefone));

    formatarTelefone(telefone, telefoneFormatado);
}

/* Exibe os dados de todos os alunos */
void exibirAlunos(struct Aluno alunos[]) {
    printf("\n========================================\n");
    printf("          ALUNOS CADASTRADOS\n");
    printf("========================================\n");

    for (int i = 0; i < TAM; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("----------------------------------------\n");
        printf("Nome:      %s\n", alunos[i].nome);
        printf("CPF:       %s\n", alunos[i].cpf);
        printf("Telefone:  %s\n", alunos[i].telefone);
        printf("Endereco:  %s\n", alunos[i].endereco);
    }

    printf("\n========================================\n");
}

int main(void) {
    struct Aluno alunos[TAM];

    printf("========================================\n");
    printf("       SISTEMA DE CADASTRO DE ALUNOS\n");
    printf("========================================\n");

    for (int i = 0; i < TAM; i++) {
        printf("\nCadastro do aluno %d de %d\n", i + 1, TAM);
        printf("----------------------------------------\n");

        lerString(
            alunos[i].nome,
            sizeof(alunos[i].nome),
            "Nome: "
        );

        capturarCPF(alunos[i].cpf);

        capturarTelefone(alunos[i].telefone);

        lerString(
            alunos[i].endereco,
            sizeof(alunos[i].endereco),
            "Endereco: "
        );
    }

    exibirAlunos(alunos);

    return 0;
}
```
