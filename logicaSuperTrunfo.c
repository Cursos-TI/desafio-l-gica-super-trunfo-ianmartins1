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

    // Menu interativo para a escolha dos dois atributos
    int opcao1, opcao2;
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao1);

    // Garantir que o segundo atributo não seja o mesmo que o primeiro
    do {
        printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Número de Pontos Turísticos\n");
        printf("5. Densidade Demográfica\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao2);
    } while (opcao2 == opcao1);

    // Comparação e soma dos atributos escolhidos
    float soma1 = 0, soma2 = 0;
    printf("\nComparação entre %s e %s:\n", cidade1, cidade2);

    // Comparar o primeiro atributo
    switch(opcao1) {
        case 1: // Comparar População
            printf("Atributo 1 - População:\n");
            printf("Carta 1 - %s: %lu\n", cidade1, populacao1);
            printf("Carta 2 - %s: %lu\n", cidade2, populacao2);
            soma1 += populacao1;
            soma2 += populacao2;
            break;
        case 2: // Comparar Área
            printf("Atributo 1 - Área:\n");
            printf("Carta 1 - %s: %.2f km²\n", cidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);
            soma1 += area1;
            soma2 += area2;
            break;
        case 3: // Comparar PIB
            printf("Atributo 1 - PIB:\n");
            printf("Carta 1 - %s: %.2f bi\n", cidade1, pib1);
            printf("Carta 2 - %s: %.2f bi\n", cidade2, pib2);
            soma1 += pib1;
            soma2 += pib2;
            break;
        case 4: // Comparar Pontos Turísticos
            printf("Atributo 1 - Pontos Turísticos:\n");
            printf("Carta 1 - %s: %d\n", cidade1, pontos1);
            printf("Carta 2 - %s: %d\n", cidade2, pontos2);
            soma1 += pontos1;
            soma2 += pontos2;
            break;
        case 5: // Comparar Densidade Demográfica
            printf("Atributo 1 - Densidade Demográfica:\n");
            printf("Carta 1 - %s: %.2f habitantes por km²\n", cidade1, densidade1);
            printf("Carta 2 - %s: %.2f habitantes por km²\n", cidade2, densidade2);
            soma1 += densidade1;
            soma2 += densidade2;
            break;
        default:
            printf("Opção inválida! \n");
            break;
    }

    // Comparar o segundo atributo
    switch(opcao2) {
        case 1: // Comparar População
            printf("Atributo 2 - População:\n");
            printf("Carta 1 - %s: %lu\n", cidade1, populacao1);
            printf("Carta 2 - %s: %lu\n", cidade2, populacao2);
            soma1 += populacao1;
            soma2 += populacao2;
            break;
        case 2: // Comparar Área
            printf("Atributo 2 - Área:\n");
            printf("Carta 1 - %s: %.2f km²\n", cidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);
            soma1 += area1;
            soma2 += area2;
            break;
        case 3: // Comparar PIB
            printf("Atributo 2 - PIB:\n");
            printf("Carta 1 - %s: %.2f bi\n", cidade1, pib1);
            printf("Carta 2 - %s: %.2f bi\n", cidade2, pib2);
            soma1 += pib1;
            soma2 += pib2;
            break;
        case 4: // Comparar Pontos Turísticos
            printf("Atributo 2 - Pontos Turísticos:\n");
            printf("Carta 1 - %s: %d\n", cidade1, pontos1);
            printf("Carta 2 - %s: %d\n", cidade2, pontos2);
            soma1 += pontos1;
            soma2 += pontos2;
            break;
        case 5: // Comparar Densidade Demográfica
            printf("Atributo 2 - Densidade Demográfica:\n");
            printf("Carta 1 - %s: %.2f habitantes por km²\n", cidade1, densidade1);
            printf("Carta 2 - %s: %.2f habitantes por km²\n", cidade2, densidade2);
            soma1 += densidade1;
            soma2 += densidade2;
            break;
        default:
            printf("Opção inválida! \n");
            break;
    }

    // Exibir o resultado final
    printf("\nSoma dos Atributos:\n");
    printf("Carta 1 (%s) - Soma: %.2f\n", cidade1, soma1);
    printf("Carta 2 (%s) - Soma: %.2f\n", cidade2, soma2);

    if (soma1 > soma2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (soma2 > soma1) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
