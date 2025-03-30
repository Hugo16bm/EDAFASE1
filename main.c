



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"

 /**
  * @brief Função principal que apresenta o menu
  * @return 0 no término do programa.
  */
int main() {
    Antenna* listaAntenas = NULL;              /**< Lista ligada de antenas */
    Interference* listaInterferencias = NULL;  /**< Lista ligada de interferências */
    int opcao, row, col;
    char freq;
    char nomeFicheiro[100];

    do {
        printf("\n--- MENU ---\n");
        printf("1. Carregar antenas de ficheiro\n");
        printf("2. Inserir antena\n");
        printf("3. Remover antena\n");
        printf("4. Listar antenas\n");
        printf("5. Listar interferencias\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            /** @brief Carrega antenas do ficheiro e recalcula interferências */
            printf("Nome do ficheiro: ");
            scanf("%s", nomeFicheiro);
            freeAntenna(listaAntenas);
            listaAntenas = loadAntenna(nomeFicheiro);
            if (!listaAntenas) printf("Erro ao carregar ficheiro.\n");
            else printf("Antenas carregadas com sucesso.\n");
            freeInterference(listaInterferencias);
            listaInterferencias = calculateInterference(listaAntenas);
            break;

        case 2:
            /** @brief Insere nova antena e recalcula interferências */
            printf("Frequencia: ");
            scanf(" %c", &freq);
            printf("Linha: ");
            scanf("%d", &row);
            printf("Coluna: ");
            scanf("%d", &col);
            listaAntenas = addAntenna(listaAntenas, freq, row, col);
            freeInterference(listaInterferencias);
            listaInterferencias = calculateInterference(listaAntenas);
            break;

        case 3:
            /** @brief Remove antena por coordenadas e recalcula interferências */
            printf("Linha da antena a remover: ");
            scanf("%d", &row);
            printf("Coluna da antena a remover: ");
            scanf("%d", &col);
            listaAntenas = removeAntenna(listaAntenas, row, col);
            freeInterference(listaInterferencias);
            listaInterferencias = calculateInterference(listaAntenas);
            break;

        case 4:
            /** @brief Lista todas as antenas existentes */
            showAntenna(listaAntenas);
            break;

        case 5:
            /** @brief Lista todas as localizações com interferência */
            showInterference(listaInterferencias);
            break;

        case 0:
            printf("A sair...\n");
            break;

        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    /** @brief Libertação final da memória antes de sair */
    freeAntenna(listaAntenas);
    freeInterference(listaInterferencias);
    return 0;
}
