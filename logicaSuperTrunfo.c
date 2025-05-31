#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3]; // Ex: "SP"
    char codigo[10]; // Código da carta
    char nomeCidade[50]; // Nome da cidade
    int populacao; // População da cidade
    float area; // Área da cidade
    float pib; // PIB da cidade
    int pontosTuristicos; // Número de pontos turísticos
    float densidadePopulacional; // População / Área
    float pibPerCapita; // PIB / População
};

// Função que cadastra os dados de uma carta
void cadastrarCarta(struct Carta *carta) {
    printf("Digite o código da carta: ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade); // Leitura com espaço

    printf("Digite a sigla do estado (ex: SP): ");
    scanf("%s", carta->estado);

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculo de densidade populacional e PIB per capita
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função que compara dois valores e retorna o índice do vencedor (0 ou 1)
int compararCartas(struct Carta c1, struct Carta c2) {
    // Escolha do atributo para comparação: "populacao"
    // Para outros atributos, altere a lógica conforme necessário

    printf("\nComparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %d\n", c1.nomeCidade, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%s): %d\n", c2.nomeCidade, c2.estado, c2.populacao);

    if (c1.populacao > c2.populacao) {
        return 0; // Carta 1 vence
    } else if (c2.populacao > c1.populacao) {
        return 1; // Carta 2 vence
    } else {
        return -1; // Empate
    }
}

// Função principal
int main() {
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    int resultado = compararCartas(carta1, carta2);

    printf("\nResultado da comparação:\n");

    if (resultado == 0) {
        printf("Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (resultado == 1) {
        printf("Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Empate entre as duas cartas!\n");
    }

    return 0;
}
