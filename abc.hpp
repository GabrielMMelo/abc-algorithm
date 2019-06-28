#ifndef ABC_HPP
#define ABC_HPP

#include <iostream>
#include <vector>
#include "bee.hpp"
#include "tsplib.hpp"

const int COLONY_SIZE = 10;
const int HALF_COLONY = COLONY_SIZE/2;
const int MAX_ITER = 10;
const int MAX_FORAGE = 10;
const int LIMIT = 10;

class ABC {
public:
  /* ATTRIBUTES */
  int colony_size;
  int half_colony;
  int max_iter;                                          // número de iterações (execuções do problema)
  int max_forage;                                        // número de ciclos de trabalho das abelhas para busca de alimento
  int limit;                                             // número de vezes que pode se tentar melhorar uma solução
  int D;                                                 // dimensões do problema (i.e., número de cidades)
  std::vector<std::vector<double>> colony;               // matriz que armazena a quantidade de alimento retirado por cada abelha em cada fonte de alimento;
  std::vector<int> attempts;                             // relacionado à this->limit
  std::vector<int> fitness;                              // qualidade das fontes de alimento das abelhas
  std::vector<double> better_solution;                   // melhor solução atual
  double better_fitness;                                 // valor de fitness da melhor solução atual
  std::vector<std::vector<double>> better_solutions;     // melhores soluções de cada execução do algoritmo
  std::vector<double> better_fitnesses;                  // valores das melhores soluções de cada execução
  std::vector<int> food_sources;
  Tsplib *tsp;

  /* METHODS */
  ABC(Tsplib*);
  ~ABC();
  void print_colony();
  void generate_population();
  void employees_phase();
  void calc_probabilities();
  void onlookers_phase();
  void scouts_phase();
  void fill_vectors();
};

#endif
