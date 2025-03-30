/**
 * @file structs.h
 * @brief Definicoes das estruturas de dados utilizadas no projeto: Antenna e Interference.
 *        Cada estrutura representa respetivamente uma antena e um ponto com interferencia.
 * @author Hugo Monteiro
 */

#ifndef STRUCTS_H
#define STRUCTS_H

 /**
  * @brief Representa uma antena com frequencia, linha, coluna e ligacao para proxima antena.
  */
typedef struct Antenna {
    char freq;          /**< Frequencia da antena */
    int row;            /**< Linha da antena na grelha */
    int col;            /**< Coluna da antena na grelha */
    struct Antenna* next; /**< Ponteiro para a proxima antena */
} Antenna;

/**
 * @brief Representa um ponto de interferência com coordenadas e ligação para o próximo.
 */
typedef struct Interference {
    int row;            /**< Linha da interferência */
    int col;            /**< Coluna da interferência */
    struct Interference* next; /**< Ponteiro para próxima interferência */
} Interference;

#endif // STRUCTS_H