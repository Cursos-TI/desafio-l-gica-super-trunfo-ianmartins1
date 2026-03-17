#include <stdio.h>
#include <string.h>

int main() {
    // Declaração das variáveis para armazenar os dados das cartas
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;
    float densidade1, densidade2, pib_per_capita1, pib_per_capita2;

    // Entrada de dados para a carta 1
    printf("Cadastro da Carta 1\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o Nome da Cidade: ");
    getchar(); // para consumir o '\n' deixado pelo scanf anterior
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = 0; // remove o \n

    printf("Digite a População: ");
    scanf("%lu", &populacao1);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontos1);

    densidade1 = populacao1 / area1;
    pib_per_capita1 = (pib1 * 1e9) / populacao1;

    // Entrada de dados para a carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo2);
    printf("Digite o Nome da Cidade: ");
    getchar();
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("Digite a População: ");
    scanf("%lu", &populacao2);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontos2);

    densidade2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1e9) / populacao2;

    // Menu interativo
    int opcao;
    printf("\nEscolha o atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    // Lógica de comparação com base na opção escolhida
    switch(opcao) {
        case 1: // Comparar População
            printf("\nComparação de Cartas (Atributo: População):\n");
            printf("Carta 1 - %s: %lu\n", cidade1, populacao1);
            printf("Carta 2 - %s: %lu\n", cidade2, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 2: // Comparar Área
            printf("\nComparação de Cartas (Atributo: Área):\n");
            printf("Carta 1 - %s: %.2f km²\n", cidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);
            if (area1 > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (area2 > area1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 3: // Comparar PIB
            printf("\nComparação de Cartas (Atributo: PIB):\n");
            printf("Carta 1 - %s: %.2f bi\n", cidade1, pib1);
            printf("Carta 2 - %s: %.2f bi\n", cidade2, pib2);
            if (pib1 > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (pib2 > pib1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 4: // Comparar Pontos Turísticos
            printf("\nComparação de Cartas (Atributo: Pontos Turísticos):\n");
            printf("Carta 1 - %s: %d\n", cidade1, pontos1);
            printf("Carta 2 - %s: %d\n", cidade2, pontos2);
            if (pontos1 > pontos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (pontos2 > pontos1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 5: // Comparar Densidade Demográfica
            printf("\nComparação de Cartas (Atributo: Densidade Demográfica):\n");
            printf("Carta 1 - %s: %.2f habitantes por km²\n", cidade1, densidade1);
            printf("Carta 2 - %s: %.2f habitantes por km²\n", cidade2, densidade2);
            if (densidade1 < densidade2) { // Menor densidade vence
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (densidade2 < densidade1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default:
            printf("Opção inválida! Escolha um número de 1 a 5.\n");
            break;
    }

    return 0;
}
