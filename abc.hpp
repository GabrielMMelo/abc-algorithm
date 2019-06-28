#ifndef ABC_HPP
#define ABC_HPP

#include <iostream>
#include <vector>
#include "bee.hpp"

const int COLONY_SIZE = 10;
const int HALF_COLONY = COLONY_SIZE/2;
const int MAX_ITER = 10;
const int MAX_FORAGE = 10;
const int LIMIT = 10;

class ABC {
public:
  int colony_size;
  int half_colony;
  int max_iter;                             // número de iterações (execuções do problema)
  int max_forage;                           // número de ciclos de trabalho das abelhas para busca de alimento
  int limit;                                // número de vezes que pode se tentar melhorar uma solução
  int D;                                    // dimensões do problema (i.e., número de cidades)
  int colony[HALF_COLONY][COLONY_SIZE];
  int attempts[HALF_COLONY];                // relacionado à this->limit
  int fitness[HALF_COLONY];                 // qualidade das fontes de alimento das abelhas
  double *better_solution;                  // melhor solução atual  TODO: zerar
  double better_fitness;                    // valor de fitness da melhor solução atual
  double *better_solutions;                 // melhor solução atual  TODO: zerar
  double better_fitnesses[MAX_ITER];        // melhor solução atual
  std::vector<int> food_sources;
  ABC();
  ~ABC();
  void print_colony();
  void employees_phase();
  void calc_probabilities();
  void onlookers_phase();
  void scouts_phase();
};

#endif
