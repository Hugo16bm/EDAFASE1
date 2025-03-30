/**
 * @file funcoes.c
 * @brief Implementação das funções que manipulam listas de antenas e interferências.
 *        Inclui inserção, remoção, leitura de ficheiro, dedução de interferências e listagens.
 * @author Hugo Monteiro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"


Antenna* addAntenna(Antenna* lista, char freq, int row, int col) {
    Antenna* nova = malloc(sizeof(Antenna));
    if (!nova) return lista;
    nova->freq = freq;
    nova->row = row;
    nova->col = col;
    nova->next = lista;
    return nova;
}

Antenna* removeAntenna(Antenna* lista, int row, int col) {
    Antenna* atual = lista, * anterior = NULL;
    while (atual) {
        if (atual->row == row && atual->col == col) {
            if (anterior) anterior->next = atual->next;
            else lista = atual->next;
            free(atual);
            return lista;
        }
        anterior = atual;
        atual = atual->next;
    }
    return lista;
}


void freeAntenna(Antenna* lista) {
    while (lista) {
        Antenna* temp = lista;
        lista = lista->next;
        free(temp);
    }
}


void freeInterference(Interference* lista) {
    while (lista) {
        Interference* temp = lista;
        lista = lista->next;
        free(temp);
    }
}


void showAntenna(const Antenna* lista) {
    printf("\nAntenas:\nFrequencia\tLinha\tColuna\n");
    while (lista) {
        printf("   %c\t\t%d\t%d\n", lista->freq, lista->row, lista->col);
        lista = lista->next;
    }
}


void showInterference(const Interference* lista) {
    printf("\nInterferencias:\nLinha\tColuna\n");
    while (lista) {
        printf("%d\t%d\n", lista->row, lista->col);
        lista = lista->next;
    }
}


Antenna* loadAntenna(const char* nomeFicheiro) {
    FILE* f = fopen(nomeFicheiro, "r");
    if (!f) return NULL;

    Antenna* lista = NULL;
    char linha[256];
    int row = 0;

    while (fgets(linha, sizeof(linha), f)) {
        for (int col = 0; linha[col] != '\0' && linha[col] != '\n'; col++) {
            if (linha[col] != '.' && linha[col] != ' ') {
                lista = addAntenna(lista, linha[col], row, col);
            }
        }
        row++;
    }
    fclose(f);
    return lista;
}


int estaNaLista(Interference* lista, int row, int col) {
    while (lista) {
        if (lista->row == row && lista->col == col) return 1;
        lista = lista->next;
    }
    return 0;
}


Interference* calculateInterference(Antenna* lista) {
    Interference* interferencias = NULL;
    for (Antenna* a = lista; a; a = a->next) {
        for (Antenna* b = lista; b; b = b->next) {
            if (a == b) continue;
            if (a->freq != b->freq) continue;

            int dx = b->row - a->row;
            int dy = b->col - a->col;

            int px1 = a->row - dx;
            int py1 = a->col - dy;
            if (px1 >= 0 && py1 >= 0 && !estaNaLista(interferencias, px1, py1)) {
                Interference* nova = malloc(sizeof(Interference));
                if (nova) {
                    nova->row = px1;
                    nova->col = py1;
                    nova->next = interferencias;
                    interferencias = nova;
                }
            }

            int px2 = b->row + dx;
            int py2 = b->col + dy;
            if (px2 >= 0 && py2 >= 0 && !estaNaLista(interferencias, px2, py2)) {
                Interference* nova = malloc(sizeof(Interference));
                if (nova) {
                    nova->row = px2;
                    nova->col = py2;
                    nova->next = interferencias;
                    interferencias = nova;
                }
            }
        }
    }
    return interferencias;
}
