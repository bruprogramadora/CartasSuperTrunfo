#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de um país
typedef struct {
    char nome[30];
    int populacao;
    int area;
    int densidade;
    int pib;
    int expectativaVida;
} Carta;

// Função para exibir o menu de atributos
void exibirMenuAtributos(int atributoEscolhido) {
    printf("\nEscolha um atributo:\n");

    if (atributoEscolhido != 1) printf("1 - População\n");
    if (atributoEscolhido != 2) printf("2 - Área\n");
    if (atributoEscolhido != 3) printf("3 - Densidade Demográfica\n");
    if (atributoEscolhido != 4) printf("4 - PIB\n");
    if (atributoEscolhido != 5) printf("5 - Expectativa de Vida\n");
}

// Função para retornar o valor do atributo escolhido
int obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.densidade;
        case 4: return c.pib;
        case 5: return c.expectativaVida;
        default: return -1;
    }
}

// Função para comparar dois atributos
int compararAtributos(int valor1, int valor2, int atributo) {
    if (atributo == 3) // Densidade: menor vence
        return (valor1 < valor2) ? 1 : (valor1 > valor2 ? 2 : 0);
    else // Demais: maior vence
        return (valor1 > valor2) ? 1 : (valor1 < valor2 ? 2 : 0);
}

int main() {
    // Cartas de exemplo (substitua com seus dados reais)
    Carta carta1 = {"Brasil", 211000000, 8516000, 25, 2200, 75};
    Carta carta2 = {"Canadá", 38000000, 9985000, 4, 1700, 82};

    int atributo1, atributo2;

    // Escolha do primeiro atributo
    exibirMenuAtributos(0);
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    // Escolha do segundo atributo (menu dinâmico)
    exibirMenuAtributos(atributo1);
    printf("Escolha o segundo atributo (diferente do primeiro): ");
    scanf("%d", &atributo2);

    // Validação de atributos
    if (atributo1 == atributo2 || atributo1 < 1 || atributo1 > 5 || atributo2 < 1 || atributo2 > 5) {
        printf("Erro: Atributos inválidos ou repetidos.\n");
        return 1;
    }

    // Obter valores dos atributos
    int valor1A = obterValorAtributo(carta1, atributo1);
    int valor2A = obterValorAtributo(carta2, atributo1);
    int valor1B = obterValorAtributo(carta1, atributo2);
    int valor2B = obterValorAtributo(carta2, atributo2);

    // Comparação individual
    int resultado1 = compararAtributos(valor1A, valor2A, atributo1);
    int resultado2 = compararAtributos(valor1B, valor2B, atributo2);

    // Soma dos atributos
    int soma1 = valor1A + valor1B;
    int soma2 = valor2A + valor2B;

    // Exibição do resultado
    printf("\n--- Resultado da Rodada ---\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n", carta2.nome);
    printf("Atributo 1: %d x %d\n", valor1A, valor2A);
    printf("Atributo 2: %d x %d\n", valor1B, valor2B);
    printf("Soma: %d x %d\n", soma1, soma2);

    if (soma1 > soma2)
        printf("Vencedor: %s\n", carta1.nome);
    else if (soma2 > soma1)
        printf("Vencedor: %s\n", carta2.nome);
    else
        printf("Empate!\n");

    return 0;
}