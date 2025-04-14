#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} CartaPais;

void compararCartas(CartaPais c1, CartaPais c2, int opcao) {
    printf("\nComparando %s x %s\n", c1.nome, c2.nome);
    
    switch(opcao) {
        case 1:
            printf("Nome do país não é um atributo de comparação.\n");
            break;
        case 2:
            printf("População: %d x %d\n", c1.populacao, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Vencedor: %s\n", c1.nome);
            else if (c1.populacao < c2.populacao)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 3:
            printf("Área: %.2f x %.2f\n", c1.area, c2.area);
            if (c1.area > c2.area)
                printf("Vencedor: %s\n", c1.nome);
            else if (c1.area < c2.area)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 4:
            printf("PIB: %.2f x %.2f\n", c1.pib, c2.pib);
            if (c1.pib > c2.pib)
                printf("Vencedor: %s\n", c1.nome);
            else if (c1.pib < c2.pib)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 5:
            printf("Pontos Turísticos: %d x %d\n", c1.pontosTuristicos, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedor: %s\n", c1.nome);
            else if (c1.pontosTuristicos < c2.pontosTuristicos)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 6:
            printf("Densidade Demográfica: %.2f x %.2f\n", c1.densidadeDemografica, c2.densidadeDemografica);
            if (c1.densidadeDemografica < c2.densidadeDemografica)
                printf("Vencedor: %s\n", c1.nome);
            else if (c1.densidadeDemografica > c2.densidadeDemografica)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    CartaPais carta1 = {"Brasil", 213000000, 8515767.0, 2.05, 25, 25.0};
    CartaPais carta2 = {"Japão", 125000000, 377975.0, 5.00, 30, 330.8};

    int opcao;

    printf("Escolha o atributo para comparação:\n");
    printf("1 - Nome (não comparável)\n");
    printf("2 - População\n");
    printf("3 - Área\n");
    printf("4 - PIB\n");
    printf("5 - Pontos Turísticos\n");
    printf("6 - Densidade Demográfica (vence o menor valor)\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    compararCartas(carta1, carta2, opcao);

    return 0;
}
