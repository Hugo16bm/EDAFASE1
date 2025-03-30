/**
 * @file funcoes.h
 * @brief Headers das funcoes 
 * @author Hugo Monteiro
 */

#ifndef FUNCOES_H
#define FUNCOES_H

#include "structs.h"

 /** @defgroup GestaoAntena Funcoes de Gestao de Antenas
  *  Funções responsaveis pela leitura, insercao, remocao e apresentacao de antenas.
  *  @{
  */

  /**
   * @brief Carrega as antenas de um ficheiro texto para uma lista ligada.
   * @param nomeFicheiro Nome do ficheiro a ler.
   * @return Lista ligada de antenas.
   */
Antenna* loadAntenna(const char* nomeFicheiro);



/**
 * @brief Insere uma nova antena na lista ligada.
 * @param lista Lista atual de antenas.
 * @param freq Frequencia da antena.
 * @param row Linha da antena.
 * @param col Coluna da antena.
 * @return Lista atualizada.
 */
Antenna* addAntenna(Antenna* lista, char freq, int row, int col);

/**
 * @brief Remove uma antena da lista pelas coordenadas.
 * @param lista Lista de antenas.
 * @param row Linha da antena a remover.
 * @param col Coluna da antena a remover.
 * @return Lista atualizada.
 */
Antenna* removeAntenna(Antenna* lista, int row, int col);

/**
 * @brief Liberta a memória ocupada pela lista de antenas.
 * @param lista Lista de antenas.
 */
void freeAntenna(Antenna* lista);

/**
 * @brief Imprime a lista de antenas na consola.
 * @param lista Lista de antenas.
 */
void showAntenna(const Antenna* lista);

/** @} */

/** @defgroup GestaoInterferencia Funcoes de Gestao de Interferencias
 *  Funcoes responsáveis por calcular, libertar e apresentar as interferencias.
 *  @{
 */

 /**
  * @brief Deduz automaticamente as interferencias a partir da lista de antenas.
  * @param lista Lista de antenas.
  * @return Lista de interferencias calculadas.
  */
Interference* calculateInterference(Antenna* lista);

/**
 * @brief Liberta a memória ocupada pela lista de interferencias.
 * @param lista Lista de interferencias.
 */
void freeInterference(Interference* lista);

/**
 * @brief Imprime a lista de interferencias na consola.
 * @param lista Lista de interferencias.
 */
void showInterference(const Interference* lista);

/**
 * @brief Verifica se uma coordenada já existe na lista de interferências.
 * @param lista Lista de interferências.
 * @param row Linha da matriz.
 * @param col Coluna da matriz.
 * @return 1 se existir, 0 caso contrário.
 */
int estaNaLista(Interference* lista, int row, int col);


/** @} */

#endif // FUNCOES_H

